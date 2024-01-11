# enum_class_without_helper

* Shows how to use [xtd::enum_object](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1enum__object.html) and [enum_register](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1enum__register.html) classes.


## Sources

[src/enum_class_without_helper.cpp](src/enum_class_without_helper.cpp)

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
