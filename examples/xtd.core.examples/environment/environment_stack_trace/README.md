# environment_stack_trace

Shows how to use [xtd::environment](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1environment.html) class.

## Sources

[src/environment_stack_trace.cpp](src/environment_stack_trace.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
environment::stack_trace:
   at xtd::environment::stack_trace() [0x00002C20] in !---OMITTED---!/environment.cpp:line 255
   at test3() [0x00002B40] in !---OMITTED---!/environment_stack_trace.cpp:line 7
   at test2() [0x00002CA0] in !---OMITTED---!/environment_stack_trace.cpp:line 11
   at test1() [0x00002CB0] in !---OMITTED---!/environment_stack_trace.cpp:line 15
   at main [0x00002CC0] in !---OMITTED---!/environment_stack_trace.cpp:line 20
```
