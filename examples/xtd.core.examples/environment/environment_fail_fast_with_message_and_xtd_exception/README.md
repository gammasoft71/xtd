# environment_fail_fast_with_message_and_xtd_exception

Demonstrates how to use [xtd::environment::fail_fast](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1environment.html#a949b2af9a19a371e6aff4c6ddad3f8a3) method.

## Sources

* [src/environment_fail_fast_with_message_and_xtd_exception.cpp](src/environment_fail_fast_with_message_and_xtd_exception.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run
```

## Output

```
Start application

Process terminated.
User message.
   at void xtd::environment::fail_fast<xtd::argument_out_of_range_exception>(xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::argument_out_of_range_exception const&)
   at main
xtd::argument_out_of_range_exception: Specified argument is out of range of valid values. (Parameter 'This is a test exception for FailFast.')
```
