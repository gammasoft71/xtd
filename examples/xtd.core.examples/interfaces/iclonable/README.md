# iclonable

Shows how to use [xtd::iequatable](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1iclonable.html) interface.

## Sources

[src/iclonable.cpp](src/iclonable.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
f1 {type = foo, value = 42}
f2 {type = std::unique_ptr<xtd::object, std::default_delete<xtd::object>>, value = 42}
f3 {type = std::unique_ptr<foo, std::default_delete<foo>>, value = 42}
```
