"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.Emitter = void 0;
var _assert = require("assert");
var leap = require("./leap.js");
var meta = require("./meta.js");
var util = require("./util.js");
var _core = require("@babel/core");
const PENDING_LOCATION = Number.MAX_VALUE;
function getDeclError(node) {
  return new Error("all declarations should have been transformed into " + "assignments before the Exploder began its work: " + JSON.stringify(node));
}
const catchParamVisitor = {
  Identifier: function (path, state) {
    if (path.node.name === state.catchParamName && util.isReference(path)) {
      util.replaceWithOrRemove(path, state.getSafeParam());
    }
  },
  Scope: function (path, state) {
    if (path.scope.hasOwnBinding(state.catchParamName)) {
      path.skip();
    }
  }
};
class Emitter {
  constructor(contextId) {
    this.nextTempId = void 0;
    this.contextId = void 0;
    this.listing = void 0;
    this.marked = void 0;
    this.insertedLocs = void 0;
    this.finalLoc = void 0;
    this.tryEntries = void 0;
    this.leapManager = void 0;
    this.nextTempId = 0;
    this.contextId = contextId;
    this.listing = [];
    this.marked = [true];
    this.insertedLocs = new Set();
    this.finalLoc = this.loc();
    this.tryEntries = [];
    this.leapManager = new leap.LeapManager(this);
  }
  loc() {
    const l = _core.types.numericLiteral(PENDING_LOCATION);
    this.insertedLocs.add(l);
    return l;
  }
  getInsertedLocs() {
    return this.insertedLocs;
  }
  getContextId() {
    return _core.types.cloneNode(this.contextId);
  }
  mark(loc) {
    const index = this.listing.length;
    if (loc.value === PENDING_LOCATION) {
      loc.value = index;
    } else {
      _assert.strictEqual(loc.value, index);
    }
    this.marked[index] = true;
    return loc;
  }
  emit(node) {
    if (_core.types.isExpression(node)) {
      node = _core.types.expressionStatement(node);
    }
    _core.types.assertStatement(node);
    this.listing.push(node);
  }
  emitAssign(lhs, rhs) {
    this.emit(this.assign(lhs, rhs));
    return lhs;
  }
  assign(lhs, rhs) {
    return _core.types.expressionStatement(_core.types.assignmentExpression("=", _core.types.cloneNode(lhs), rhs));
  }
  contextProperty(name, computed) {
    return _core.types.memberExpression(this.getContextId(), computed ? _core.types.stringLiteral(name) : _core.types.identifier(name), !!computed);
  }
  clearPendingException(tryLoc, assignee) {
    const catchCall = _core.types.callExpression(this.contextProperty("catch", true), [_core.types.cloneNode(tryLoc)]);
    if (assignee) {
      this.emitAssign(assignee, catchCall);
    } else {
      this.emit(catchCall);
    }
  }
  jump(toLoc) {
    this.emitAssign(this.contextProperty("next"), toLoc);
    this.emit(_core.types.breakStatement());
  }
  jumpIf(test, toLoc) {
    this.emit(_core.types.ifStatement(test, _core.types.blockStatement([this.assign(this.contextProperty("next"), toLoc), _core.types.breakStatement()])));
  }
  jumpIfNot(test, toLoc) {
    let negatedTest;
    if (_core.types.isUnaryExpression(test) && test.operator === "!") {
      negatedTest = test.argument;
    } else {
      negatedTest = _core.types.unaryExpression("!", test);
    }
    this.emit(_core.types.ifStatement(negatedTest, _core.types.blockStatement([this.assign(this.contextProperty("next"), toLoc), _core.types.breakStatement()])));
  }
  makeTempVar() {
    return this.contextProperty("t" + this.nextTempId++);
  }
  getContextFunction(id) {
    return _core.types.functionExpression(id || null, [this.getContextId()], _core.types.blockStatement([this.getDispatchLoop()]), false, false);
  }
  getDispatchLoop() {
    const self = this;
    const cases = [];
    let current;
    let alreadyEnded = false;
    self.listing.forEach(function (stmt, i) {
      if (self.marked.hasOwnProperty(i)) {
        cases.push(_core.types.switchCase(_core.types.numericLiteral(i), current = []));
        alreadyEnded = false;
      }
      if (!alreadyEnded) {
        current.push(stmt);
        if (_core.types.isCompletionStatement(stmt)) alreadyEnded = true;
      }
    });
    this.finalLoc.value = this.listing.length;
    cases.push(_core.types.switchCase(this.finalLoc, []), _core.types.switchCase(_core.types.stringLiteral("end"), [_core.types.returnStatement(_core.types.callExpression(this.contextProperty("stop"), []))]));
    return _core.types.whileStatement(_core.types.numericLiteral(1), _core.types.switchStatement(_core.types.assignmentExpression("=", this.contextProperty("prev"), this.contextProperty("next")), cases));
  }
  getTryLocsList() {
    if (this.tryEntries.length === 0) {
      return null;
    }
    let lastLocValue = 0;
    return _core.types.arrayExpression(this.tryEntries.map(function (tryEntry) {
      const thisLocValue = tryEntry.firstLoc.value;
      _assert.ok(thisLocValue >= lastLocValue, "try entries out of order");
      lastLocValue = thisLocValue;
      const ce = tryEntry.catchEntry;
      const fe = tryEntry.finallyEntry;
      const locs = [tryEntry.firstLoc, ce ? ce.firstLoc : null];
      if (fe) {
        locs[2] = fe.firstLoc;
        locs[3] = fe.afterLoc;
      }
      return _core.types.arrayExpression(locs.map(loc => loc && _core.types.cloneNode(loc)));
    }));
  }
  explode(path, ignoreResult) {
    const node = path.node;
    const self = this;
    if (_core.types.isDeclaration(node)) throw getDeclError(node);
    if (path.isStatement()) return self.explodeStatement(path);
    if (path.isExpression()) return self.explodeExpression(path, ignoreResult);
    switch (node.type) {
      case "VariableDeclarator":
        throw getDeclError(node);
      case "ObjectProperty":
      case "SwitchCase":
      case "CatchClause":
        throw new Error(node.type + " nodes should be handled by their parents");
      default:
        throw new Error("unknown Node of type " + JSON.stringify(node.type));
    }
  }
  explodeStatement(path, labelId = null) {
    const stmt = path.node;
    const self = this;
    let before, after, head;
    if (path.isBlockStatement()) {
      path.get("body").forEach(function (path) {
        self.explodeStatement(path);
      });
      return;
    }
    if (!meta.containsLeap(stmt)) {
      self.emit(stmt);
      return;
    }
    switch (path.type) {
      case "ExpressionStatement":
        self.explodeExpression(path.get("expression"), true);
        break;
      case "LabeledStatement":
        after = this.loc();
        self.leapManager.withEntry(new leap.LabeledEntry(after, path.node.label), function () {
          self.explodeStatement(path.get("body"), path.node.label);
        });
        self.mark(after);
        break;
      case "WhileStatement":
        before = this.loc();
        after = this.loc();
        self.mark(before);
        self.jumpIfNot(self.explodeExpression(path.get("test")), after);
        self.leapManager.withEntry(new leap.LoopEntry(after, before, labelId), function () {
          self.explodeStatement(path.get("body"));
        });
        self.jump(before);
        self.mark(after);
        break;
      case "DoWhileStatement":
        const first = this.loc();
        const test = this.loc();
        after = this.loc();
        self.mark(first);
        self.leapManager.withEntry(new leap.LoopEntry(after, test, labelId), function () {
          self.explode(path.get("body"));
        });
        self.mark(test);
        self.jumpIf(self.explodeExpression(path.get("test")), first);
        self.mark(after);
        break;
      case "ForStatement":
        head = this.loc();
        const update = this.loc();
        after = this.loc();
        if (path.node.init) {
          self.explode(path.get("init"), true);
        }
        self.mark(head);
        if (path.node.test) {
          self.jumpIfNot(self.explodeExpression(path.get("test")), after);
        } else {}
        self.leapManager.withEntry(new leap.LoopEntry(after, update, labelId), function () {
          self.explodeStatement(path.get("body"));
        });
        self.mark(update);
        if (path.node.update) {
          self.explode(path.get("update"), true);
        }
        self.jump(head);
        self.mark(after);
        break;
      case "TypeCastExpression":
        return self.explodeExpression(path.get("expression"));
      case "ForInStatement":
        head = this.loc();
        after = this.loc();
        const keyIterNextFn = self.makeTempVar();
        self.emitAssign(keyIterNextFn, _core.types.callExpression(util.runtimeProperty("keys"), [self.explodeExpression(path.get("right"))]));
        self.mark(head);
        const keyInfoTmpVar = self.makeTempVar();
        self.jumpIf(_core.types.memberExpression(_core.types.assignmentExpression("=", keyInfoTmpVar, _core.types.callExpression(_core.types.cloneNode(keyIterNextFn), [])), _core.types.identifier("done"), false), after);
        self.emitAssign(path.node.left, _core.types.memberExpression(_core.types.cloneNode(keyInfoTmpVar), _core.types.identifier("value"), false));
        self.leapManager.withEntry(new leap.LoopEntry(after, head, labelId), function () {
          self.explodeStatement(path.get("body"));
        });
        self.jump(head);
        self.mark(after);
        break;
      case "BreakStatement":
        self.emitAbruptCompletion({
          type: "break",
          target: self.leapManager.getBreakLoc(path.node.label)
        });
        break;
      case "ContinueStatement":
        self.emitAbruptCompletion({
          type: "continue",
          target: self.leapManager.getContinueLoc(path.node.label)
        });
        break;
      case "SwitchStatement":
        const disc = self.emitAssign(self.makeTempVar(), self.explodeExpression(path.get("discriminant")));
        after = this.loc();
        const defaultLoc = this.loc();
        let condition = defaultLoc;
        const caseLocs = [];
        const cases = path.node.cases || [];
        for (let i = cases.length - 1; i >= 0; --i) {
          const c = cases[i];
          if (c.test) {
            condition = _core.types.conditionalExpression(_core.types.binaryExpression("===", _core.types.cloneNode(disc), c.test), caseLocs[i] = this.loc(), condition);
          } else {
            caseLocs[i] = defaultLoc;
          }
        }
        const discriminant = path.get("discriminant");
        util.replaceWithOrRemove(discriminant, condition);
        self.jump(self.explodeExpression(discriminant));
        self.leapManager.withEntry(new leap.SwitchEntry(after), function () {
          path.get("cases").forEach(function (casePath) {
            const i = casePath.key;
            self.mark(caseLocs[i]);
            casePath.get("consequent").forEach(function (path) {
              self.explodeStatement(path);
            });
          });
        });
        self.mark(after);
        if (defaultLoc.value === PENDING_LOCATION) {
          self.mark(defaultLoc);
          _assert.strictEqual(after.value, defaultLoc.value);
        }
        break;
      case "IfStatement":
        const elseLoc = path.node.alternate && this.loc();
        after = this.loc();
        self.jumpIfNot(self.explodeExpression(path.get("test")), elseLoc || after);
        self.explodeStatement(path.get("consequent"));
        if (elseLoc) {
          self.jump(after);
          self.mark(elseLoc);
          self.explodeStatement(path.get("alternate"));
        }
        self.mark(after);
        break;
      case "ReturnStatement":
        self.emitAbruptCompletion({
          type: "return",
          value: self.explodeExpression(path.get("argument"))
        });
        break;
      case "WithStatement":
        throw new Error("WithStatement not supported in generator functions.");
      case "TryStatement":
        after = this.loc();
        const handler = path.node.handler;
        const catchLoc = handler && this.loc();
        const catchEntry = catchLoc && new leap.CatchEntry(catchLoc, handler.param);
        const finallyLoc = path.node.finalizer && this.loc();
        const finallyEntry = finallyLoc && new leap.FinallyEntry(finallyLoc, after);
        const tryEntry = new leap.TryEntry(self.getUnmarkedCurrentLoc(), catchEntry, finallyEntry);
        self.tryEntries.push(tryEntry);
        self.updateContextPrevLoc(tryEntry.firstLoc);
        self.leapManager.withEntry(tryEntry, function () {
          self.explodeStatement(path.get("block"));
          if (catchLoc) {
            if (finallyLoc) {
              self.jump(finallyLoc);
            } else {
              self.jump(after);
            }
            self.updateContextPrevLoc(self.mark(catchLoc));
            const bodyPath = path.get("handler.body");
            const safeParam = self.makeTempVar();
            self.clearPendingException(tryEntry.firstLoc, safeParam);
            bodyPath.traverse(catchParamVisitor, {
              getSafeParam: () => _core.types.cloneNode(safeParam),
              catchParamName: handler.param.name
            });
            self.leapManager.withEntry(catchEntry, function () {
              self.explodeStatement(bodyPath);
            });
          }
          if (finallyLoc) {
            self.updateContextPrevLoc(self.mark(finallyLoc));
            self.leapManager.withEntry(finallyEntry, function () {
              self.explodeStatement(path.get("finalizer"));
            });
            self.emit(_core.types.returnStatement(_core.types.callExpression(self.contextProperty("finish"), [finallyEntry.firstLoc])));
          }
        });
        self.mark(after);
        break;
      case "ThrowStatement":
        self.emit(_core.types.throwStatement(self.explodeExpression(path.get("argument"))));
        break;
      case "ClassDeclaration":
        self.emit(self.explodeClass(path));
        break;
      default:
        throw new Error("unknown Statement of type " + JSON.stringify(stmt.type));
    }
  }
  emitAbruptCompletion(record) {
    _assert.notStrictEqual(record.type, "normal", "normal completions are not abrupt");
    const abruptArgs = [_core.types.stringLiteral(record.type)];
    if (record.type === "break" || record.type === "continue") {
      abruptArgs[1] = this.insertedLocs.has(record.target) ? record.target : _core.types.cloneNode(record.target);
    } else if (record.type === "return" || record.type === "throw") {
      if (record.value) {
        abruptArgs[1] = _core.types.cloneNode(record.value);
      }
    }
    this.emit(_core.types.returnStatement(_core.types.callExpression(this.contextProperty("abrupt"), abruptArgs)));
  }
  getUnmarkedCurrentLoc() {
    return _core.types.numericLiteral(this.listing.length);
  }
  updateContextPrevLoc(loc) {
    if (loc) {
      if (loc.value === PENDING_LOCATION) {
        loc.value = this.listing.length;
      } else {
        _assert.strictEqual(loc.value, this.listing.length);
      }
    } else {
      loc = this.getUnmarkedCurrentLoc();
    }
    this.emitAssign(this.contextProperty("prev"), loc);
  }
  explodeViaTempVar(tempVar, childPath, hasLeapingChildren, ignoreChildResult) {
    _assert.ok(!ignoreChildResult || !tempVar, "Ignoring the result of a child expression but forcing it to " + "be assigned to a temporary variable?");
    let result = this.explodeExpression(childPath, ignoreChildResult);
    if (ignoreChildResult) {} else if (tempVar || hasLeapingChildren && !_core.types.isLiteral(result)) {
      result = this.emitAssign(tempVar || this.makeTempVar(), result);
    }
    return result;
  }
  explodeExpression(path, ignoreResult) {
    const expr = path.node;
    if (!expr) {
      return expr;
    }
    const self = this;
    let result;
    let after;
    function finish(expr) {
      if (ignoreResult) {
        self.emit(expr);
      }
      return expr;
    }
    if (!meta.containsLeap(expr)) {
      return finish(expr);
    }
    const hasLeapingChildren = meta.containsLeap.onlyChildren(expr);
    switch (path.type) {
      case "MemberExpression":
        return finish(_core.types.memberExpression(self.explodeExpression(path.get("object")), path.node.computed ? self.explodeViaTempVar(null, path.get("property"), hasLeapingChildren) : path.node.property, path.node.computed));
      case "CallExpression":
        const calleePath = path.get("callee");
        const argsPath = path.get("arguments");
        let newCallee;
        let newArgs;
        const hasLeapingArgs = argsPath.some(argPath => meta.containsLeap(argPath.node));
        let injectFirstArg = null;
        if (_core.types.isMemberExpression(calleePath.node)) {
          if (hasLeapingArgs) {
            const newObject = self.explodeViaTempVar(self.makeTempVar(), calleePath.get("object"), hasLeapingChildren);
            const newProperty = calleePath.node.computed ? self.explodeViaTempVar(null, calleePath.get("property"), hasLeapingChildren) : calleePath.node.property;
            injectFirstArg = newObject;
            newCallee = _core.types.memberExpression(_core.types.memberExpression(_core.types.cloneNode(newObject), newProperty, calleePath.node.computed), _core.types.identifier("call"), false);
          } else {
            newCallee = self.explodeExpression(calleePath);
          }
        } else {
          newCallee = self.explodeViaTempVar(null, calleePath, hasLeapingChildren);
          if (_core.types.isMemberExpression(newCallee)) {
            newCallee = _core.types.sequenceExpression([_core.types.numericLiteral(0), _core.types.cloneNode(newCallee)]);
          }
        }
        if (hasLeapingArgs) {
          newArgs = argsPath.map(argPath => self.explodeViaTempVar(null, argPath, hasLeapingChildren));
          if (injectFirstArg) newArgs.unshift(injectFirstArg);
          newArgs = newArgs.map(arg => _core.types.cloneNode(arg));
        } else {
          newArgs = path.node.arguments;
        }
        return finish(_core.types.callExpression(newCallee, newArgs));
      case "NewExpression":
        return finish(_core.types.newExpression(self.explodeViaTempVar(null, path.get("callee"), hasLeapingChildren), path.get("arguments").map(function (argPath) {
          return self.explodeViaTempVar(null, argPath, hasLeapingChildren);
        })));
      case "ObjectExpression":
        return finish(_core.types.objectExpression(path.get("properties").map(function (propPath) {
          if (propPath.isObjectProperty()) {
            return _core.types.objectProperty(propPath.node.key, self.explodeViaTempVar(null, propPath.get("value"), hasLeapingChildren), propPath.node.computed);
          } else {
            return propPath.node;
          }
        })));
      case "ArrayExpression":
        return finish(_core.types.arrayExpression(path.get("elements").map(function (elemPath) {
          if (!elemPath.node) {
            return null;
          }
          if (elemPath.isSpreadElement()) {
            return _core.types.spreadElement(self.explodeViaTempVar(null, elemPath.get("argument"), hasLeapingChildren));
          } else {
            return self.explodeViaTempVar(null, elemPath, hasLeapingChildren);
          }
        })));
      case "SequenceExpression":
        const lastIndex = path.node.expressions.length - 1;
        path.get("expressions").forEach(function (exprPath) {
          if (exprPath.key === lastIndex) {
            result = self.explodeExpression(exprPath, ignoreResult);
          } else {
            self.explodeExpression(exprPath, true);
          }
        });
        return result;
      case "LogicalExpression":
        after = this.loc();
        if (!ignoreResult) {
          result = self.makeTempVar();
        }
        const left = self.explodeViaTempVar(result, path.get("left"), hasLeapingChildren);
        if (path.node.operator === "&&") {
          self.jumpIfNot(left, after);
        } else {
          _assert.strictEqual(path.node.operator, "||");
          self.jumpIf(left, after);
        }
        self.explodeViaTempVar(result, path.get("right"), hasLeapingChildren, ignoreResult);
        self.mark(after);
        return result;
      case "ConditionalExpression":
        const elseLoc = this.loc();
        after = this.loc();
        const test = self.explodeExpression(path.get("test"));
        self.jumpIfNot(test, elseLoc);
        if (!ignoreResult) {
          result = self.makeTempVar();
        }
        self.explodeViaTempVar(result, path.get("consequent"), hasLeapingChildren, ignoreResult);
        self.jump(after);
        self.mark(elseLoc);
        self.explodeViaTempVar(result, path.get("alternate"), hasLeapingChildren, ignoreResult);
        self.mark(after);
        return result;
      case "UnaryExpression":
        return finish(_core.types.unaryExpression(path.node.operator, self.explodeExpression(path.get("argument")), !!path.node.prefix));
      case "BinaryExpression":
        return finish(_core.types.binaryExpression(path.node.operator, self.explodeViaTempVar(null, path.get("left"), hasLeapingChildren), self.explodeViaTempVar(null, path.get("right"), hasLeapingChildren)));
      case "AssignmentExpression":
        if (path.node.operator === "=") {
          return finish(_core.types.assignmentExpression(path.node.operator, self.explodeExpression(path.get("left")), self.explodeExpression(path.get("right"))));
        }
        const lhs = self.explodeExpression(path.get("left"));
        const temp = self.emitAssign(self.makeTempVar(), lhs);
        return finish(_core.types.assignmentExpression("=", _core.types.cloneNode(lhs), _core.types.assignmentExpression(path.node.operator, _core.types.cloneNode(temp), self.explodeExpression(path.get("right")))));
      case "UpdateExpression":
        return finish(_core.types.updateExpression(path.node.operator, self.explodeExpression(path.get("argument")), path.node.prefix));
      case "YieldExpression":
        after = this.loc();
        const arg = path.node.argument && self.explodeExpression(path.get("argument"));
        if (arg && path.node.delegate) {
          const result = self.makeTempVar();
          const ret = _core.types.returnStatement(_core.types.callExpression(self.contextProperty("delegateYield"), [arg, _core.types.stringLiteral(result.property.name), after]));
          ret.loc = expr.loc;
          self.emit(ret);
          self.mark(after);
          return result;
        }
        self.emitAssign(self.contextProperty("next"), after);
        const ret = _core.types.returnStatement(_core.types.cloneNode(arg) || null);
        ret.loc = expr.loc;
        self.emit(ret);
        self.mark(after);
        return self.contextProperty("sent");
      case "ClassExpression":
        return finish(self.explodeClass(path));
      default:
        throw new Error("unknown Expression of type " + JSON.stringify(expr.type));
    }
  }
  explodeClass(path) {
    const explodingChildren = [];
    if (path.node.superClass) {
      explodingChildren.push(path.get("superClass"));
    }
    path.get("body.body").forEach(member => {
      if (member.node.computed) {
        explodingChildren.push(member.get("key"));
      }
    });
    const hasLeapingChildren = explodingChildren.some(child => meta.containsLeap(child));
    for (let i = 0; i < explodingChildren.length; i++) {
      const child = explodingChildren[i];
      const isLast = i === explodingChildren.length - 1;
      if (isLast) {
        child.replaceWith(this.explodeExpression(child));
      } else {
        child.replaceWith(this.explodeViaTempVar(null, child, hasLeapingChildren));
      }
    }
    return path.node;
  }
}
exports.Emitter = Emitter;

//# sourceMappingURL=emit.js.map
