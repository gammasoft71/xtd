# enum_class_flags_without_helpers

* Shows how to use [xtd::enum_object](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1enum__object.html) an [xtd::enum_register](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1enum__register.html) classes.

## Sources

[src/enum_class_flags_without_helpers.cpp](src/enum_class_flags_without_helpers.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
name = bold, italic
value = 3
as<int> = 3
values = [0, 1, 2, 4, 8]
names = [normal, bold, italic, underline, strikeout]
entries = [(0, normal), (1, bold), (2, italic), (4, underline), (8, strikeout)]
```
