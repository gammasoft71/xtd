# environment_stack_trace

Shows how to use [xtd::diagnostics::process_start_info](../../../../src/xtd.core/include/xtd/diagnostics/process_start_info.h) class.

## Sources

[src/process_start_info.cpp](src/process_start_info.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
environment::stack_trace:
   at xtd::environment::stack_trace() [0x00002C20] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/environment/environment_stack_trace/Debug/environment_stack_trace:line 0
   at test3() [0x00002B40] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/environment/environment_stack_trace/Debug/environment_stack_trace:line 0
   at test2() [0x00002CA0] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/environment/environment_stack_trace/Debug/environment_stack_trace:line 0
   at test1() [0x00002CB0] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/environment/environment_stack_trace/Debug/environment_stack_trace:line 0
   at main [0x00002CC0] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/environment/environment_stack_trace/Debug/environment_stack_trace:line 0
```
