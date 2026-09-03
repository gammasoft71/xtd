# add_expression_with_own_struct

Shows how to use [xtd::expressions::operator +](https://gammasoft71.github.io/xtd/reference_guides/latest/group__expressions.html#ga2595c35e5a97bfe1a900ce48f63a755b) expression.

## Sources

* [src/add_expression_with_own_struct.cpp](src/add_expression_with_own_struct.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
add(40, 20)) => 60
add("Hello, "_s, "world!"_s) = Hello, world!
add(date_time , 7_min + 24_s) = 4/20/2026 9:20:00 PM
add(foo {50}, foo {30}) = 80
```
