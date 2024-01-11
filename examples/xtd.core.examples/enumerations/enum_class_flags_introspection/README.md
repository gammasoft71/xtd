# enum_class_flags_introspection

* Shows how the introspection works with [enum_class_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gade4794e2743558ee1eb5bbad10c7f6d4) helper.

## Sources

[src/enum_class_flags_introspection.cpp](src/enum_class_flags_introspection.cpp)

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
