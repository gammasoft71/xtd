# enum_struct

* Shows how to use [xtd::enum_object](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1enum__object.html) class and [enum_struct_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#ga85a4f5366ae461ca1e20872d39a0b440) helper.


## Sources

[src/enum_struct.cpp](src/enum_struct.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
name = value_four
value = 3
as<int> = 3
values = [0, 1, 2, 3]
names = [value_one, value_two, value_three, value_four]
entries = [(0, value_one), (1, value_two), (2, value_three), (3, value_four)]
```
