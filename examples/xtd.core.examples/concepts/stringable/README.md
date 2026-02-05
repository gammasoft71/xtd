# stringable

Shows how to use [xtd::stringable](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1stringable.html) concept.

## Sources

* [src/stringable.cpp](src/stringable.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
my_formatable_string
my_stringable_string
my_streamable_string
my_object_string
1/11/2026 6:33:25 PM
0.2.0
saturday
42
[1, 2, 3, 4, 5]
[1, 4, 9, 16, 25]
[1, 8, 27, 64, 125]
xtd::argument_out_of_range_exception : Specified argument is out of range of valid values.
   at xtd::argument_out_of_range_exception::argument_out_of_range_exception(xtd::diagnostics::stack_frame const&) in argument_out_of_range_exception.hpp:line 30
   at main in stringable.cpp:line 62
```
