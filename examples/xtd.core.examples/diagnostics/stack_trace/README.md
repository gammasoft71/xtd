# stack_trace

Shows how to use [xtd::diagnostics::stack_trace](../../../../src/xtd.core/include/xtd/diagnostics/stack_trace.h) class.

## Sources

[src/stack_trace.cpp](src/stack_trace.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
stack_trace:
   at method3()
   at method2()
   at method1()
   at main
```
