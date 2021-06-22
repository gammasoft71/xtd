# trace_cassert_message

Shows how to use [trace::cassert_](../../../../src/xtd.core/include/xtd/diagnostics/trace.h) method.

## Sources

[src/stack_trace.cpp](src/trace_cassert.cpp)

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
