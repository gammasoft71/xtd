# boxed_info

Shows how to use how to use [xtd::boxing](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gac451ec4dea542f67e4fa51551fd2cef9) methods.

## Sources

[src/boxed_info.cpp](src/boxed_info.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
[type = int, boxed type = xtd::box_integer<int>, value = 42]
[type = double, boxed type = xtd::box_floating_point<double>, value = 42.84]
[type = bool, boxed type = xtd::box<bool>, value = true]
[type = xtd::day_of_week, boxed type = xtd::enum_object<xtd::day_of_week>, value = saturday]
[type = char [9], boxed type = xtd::ustring, value = A string]
[type = char32_t [13], boxed type = xtd::ustring, value = A u32 string]
[type = xtd::date_time, boxed type = xtd::date_time, value = Thu Dec  1 20:03:07 2022]
[type = foo, boxed type = xtd::box<foo>, value = (unregistered)]
```
