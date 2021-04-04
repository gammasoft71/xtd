# console_trace_listener

Shows how to use [xtd::diagnostics::stack_trace](../../../../src/xtd.core/include/xtd/diagnostics/console_trace_listener.h) class.

## Sources

[src/stack_trace.cpp](src/console_trace_listener.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
stack_trace:
   at test3()
   at test2()
   at test1()
   at main
```
