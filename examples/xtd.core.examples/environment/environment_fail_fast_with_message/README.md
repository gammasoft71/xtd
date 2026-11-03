# environment_fail_fast_with_message

Demonstrates how to use [xtd::environment::fail_fast](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1environment.html#a6a69ebbe559d36bc470bb217fcfae609) method.

## Sources

* [src/environment_fail_fast_with_message.cpp](src/environment_fail_fast_with_message.cpp)
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
   at xtd::environment::fail_fast(xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&)
   at main
```
