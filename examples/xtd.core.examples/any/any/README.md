# any

Shows how to use how to use [xtd::any_object](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1any__object.html) class.

## Sources

[src/any.cpp](src/any.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
a = one => one (xtd::ustring)
a = Tue Jan  5 00:00:00 1971 => Tue Jan  5 00:00:00 1971 (xtd::date_time)
a = 42 => 42 (int)
a = 0.42 => 0.42 (double)
a = 42 => 42 (foo1)
a = foo2 => NA (foo2)
a = wednesday => wednesday (xtd::day_of_week)
```
