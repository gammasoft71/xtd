# any_info

Shows how to use [xtd::any_object](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1any__object.html) class.

## Sources

[src/any_info.cpp](src/any_info.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
[value = one (char [4]), any = one (xtd::ustring)]
[value = Tue Jan  5 00:00:00 1971 (xtd::date_time), any = Tue Jan  5 00:00:00 1971 (xtd::date_time)]
[value = 42 (int), any = 42 (xtd::box_integer<int>)]
[value = 0.42 (double), any = 0.42 (xtd::box_floating_point<double>)]
[value = 42 (foo1), any = 42 (foo1)]
[value = 42 (foo2), any = 42 (xtd::box<foo2>)]
[value = wednesday (xtd::day_of_week), any = wednesday (xtd::enum_object<xtd::day_of_week>)]
```
