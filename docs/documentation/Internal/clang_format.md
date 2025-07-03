# clang-format Evaluation for xtd (internal)

## Purpose

This document summarizes the evaluation of [`clang-format`](https://clang.llvm.org/docs/ClangFormat.html) as a potential alternative to `astyle` for formatting the [xtd](https://github.com/gammasoft71/xtd) codebase.

The goal was to determine whether `clang-format` could match the strict and elegant formatting style currently used in xtd, and whether it would be a viable replacement in terms of configuration flexibility and output.

---

## Configuration Used

```yaml
BasedOnStyle: Google
IndentWidth: 2
UseTab: Never
ColumnLimit: 0
AlignConsecutiveAssignments: false
AlignConsecutiveDeclarations: false
AllowShortEnumsOnASingleLine: true
AllowShortFunctionsOnASingleLine: All
BreakBeforeBraces: Custom
BraceWrapping:
  AfterEnum: false
  AfterStruct: false
  AfterClass: false
  AfterControlStatement: false
  SplitEmptyFunction: false
  SplitEmptyRecord: false
  SplitEmptyNamespace: false
SpacesInParentheses: false
SpaceBeforeParens: ControlStatements
SpaceInEmptyParentheses: false
SpaceBeforeCpp11BracedList: true
```

This configuration aimed to match xtd’s current formatting as closely as possible.

---

## Incompatibilities Found

Despite a close attempt, several stylistic mismatches were observed:

### 1. **Enums on a Single Line**
#### Source:
```cpp
enum Color { red, green, blue };
```
#### Formatted as:
```cpp
enum Color { red,
             green,
             blue };
```
✅ Expected to stay compact if originally written in one line.

---

### 2. **Enums Multiline Style**
#### Source:
```cpp
enum Color {
    red,
    green,
    blue};
```
#### Desired formatting:
```cpp
enum Color {
  red,
  green,
  blue};
```
❌ `clang-format` either indents closing brace incorrectly or applies inconsistent spacing.

---

### 3. **Spacing in Braced Constructors**
#### Source:
```cpp
xtd::forms::application::run(xtd::forms::form {});
```
#### Formatted as:
```cpp
xtd::forms::application::run(xtd::forms::form{});
```
❌ The space between type and `{}` is removed, breaking xtd style.

---

### 4. **Declaration Alignment**
#### Source:
```cpp
auto main_form = form::create("Gui application");
auto info_label = label::create(main_form, "...", {10, 10});
```
#### Formatted as:
```cpp
auto main_form         = form::create("Gui application");
auto info_label        = label::create(main_form, "...", {10, 10});
```
❌ Unwanted alignment of assignment operators — xtd prefers natural spacing, not column-based alignment.

---

### 5. **Access Specifier Formatting**
#### Source:
```cpp
class test_class_(test_application) {
public:
  // ...
};
```
#### Formatted as:
```cpp
class test_class_(test_application) {
 public:
  // ...
};
```
❌ Space before `public:` is not allowed in xtd style.

---

## Conclusion

Although `clang-format` is powerful and widely adopted, it lacks the fine-grained control and stylistic nuance required by the xtd codebase. Many of xtd's formatting rules are **contextual**, **minimalist**, and **intentionally designed**, which `clang-format` cannot currently express — even with extensive configuration.

Given these limitations:

> ❌ **clang-format is not suitable for xtd at this time.**  
> ✅ **xtd will continue using `astyle`** as it better respects the project's formatting philosophy.

---

## Future Possibilities

- Revisit `clang-format` if more granular options are added in future versions.
- Explore writing a custom formatter or wrapper if needed.
- Consider using `clang-format` only for CI linting or limited to trivial files (unlikely in xtd's case).

---
