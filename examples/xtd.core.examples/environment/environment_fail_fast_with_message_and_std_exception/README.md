# environment_fail_fast_with_message_and_std_exception

Demonstrates how to use [xtd::environment::fail_fast](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1environment.html#a949b2af9a19a371e6aff4c6ddad3f8a3) method.

## Sources

* [src/environment_fail_fast_with_message_and_std_exception.cpp](src/environment_fail_fast_with_message_and_std_exception.cpp)
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
   at void xtd::environment::fail_fast<std::invalid_argument>(xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::invalid_argument const&)
   at main
std::invalid_argument (Parameter 'This is a test exception for fail_fast.')
```
