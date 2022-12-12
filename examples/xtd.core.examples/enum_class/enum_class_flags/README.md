# enum_class_flags

* Shows how to use [xtd::enum_object](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1enum__object.html) class, [enum_class_](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1enum__object.html) and [add_enum_flag_operators_](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1enum__object.html) helpers.

## Sources

[src/enum_class.cpp](src/enum_class_flags.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
name = bold, italic
value = 3
as<int> = 3
values = [0, 1, 2, 4, 8]
names = [normal, bold, italic, underline, strikeout]
entries = [(0, normal), (1, bold), (2, italic), (4, underline), (8, strikeout)]
```
