# any

Shows how to use [xtd::any_object](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1any__object.html) class.

## Sources

* [src/any.cpp](src/any.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
a = gammasoft => Gammasoft (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>)
a = 1/5/1971 0:00:00 AM => 1/5/1971 (xtd::date_time)
a = 42 => 42 (int)
a = 0.42 => 0.42 (double)
a = 42 => 42 (foo1)
a = 42 => 42 (foo2)
a = 42 => 42 (foo3)
a = wednesday => wednesday (xtd::day_of_week)
```
