# enum_class_flags_without_helpers

* Shows how to use [xtd::enum_object](../../../../src/xtd.core/include/xtd/xtd::enum_object.h) an [xtd::enum_register](../../../../src/xtd.core/include/xtd/xtd::enum_object.h) classes.

## Sources

[src/enum_class_flags_without_helper.cpp](src/enum_class_flags_without_helpers.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
ame = bold, italic
value = 3
as<int> = 3
values = [0, 1, 2, 4, 8]
names = [normal, bold, italic, underline, strikeout]
entries = [(0, normal), (1, bold), (2, italic), (4, underline), (8, strikeout)]
```
