# default_trace_listener

Shows how to use [xtd::diagnostics::default_trace_listener](../../../../src/xtd.core/include/xtd/diagnostics/default_trace_listener.h) class.

## Sources

[src/default_trace_listener.cpp](src/default_trace_listener.cpp)

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
