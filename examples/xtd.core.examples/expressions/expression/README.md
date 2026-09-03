# expression

Shows how to use [xtd::expressions::expression](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1expressions_1_1expression.html) class.

## Sources

* [src/expression.cpp](src/expression.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
expr1 = 900
expr1 => (_1 + _2) * 30
type_of(expr1) => xtd::expressions::multiply<xtd::expressions::add<xtd::expressions::placeholder<1ul>, xtd::expressions::placeholder<2ul>>, xtd::expressions::value<int>>

expr2 = 900
expr2 => (_1 + _2) * 30
type_of(expr2) => xtd::expressions::multiply<xtd::expressions::add<xtd::expressions::placeholder<1ul>, xtd::expressions::placeholder<2ul>>, xtd::expressions::value<int>>
```
