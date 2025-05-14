"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.getTypes = getTypes;
exports.isReference = isReference;
exports.replaceWithOrRemove = replaceWithOrRemove;
exports.runtimeProperty = runtimeProperty;
exports.wrapWithTypes = wrapWithTypes;
let currentTypes = null;
function wrapWithTypes(types, fn) {
  return function (...args) {
    const oldTypes = currentTypes;
    currentTypes = types;
    try {
      return fn.apply(this, args);
    } finally {
      currentTypes = oldTypes;
    }
  };
}
function getTypes() {
  return currentTypes;
}
function runtimeProperty(name) {
  const t = getTypes();
  return t.memberExpression(t.identifier("regeneratorRuntime"), t.identifier(name), false);
}
function isReference(path) {
  return path.isReferenced() || path.parentPath.isAssignmentExpression({
    left: path.node
  });
}
function replaceWithOrRemove(path, replacement) {
  if (replacement) {
    path.replaceWith(replacement);
  } else {
    path.remove();
  }
}

//# sourceMappingURL=util.js.map
