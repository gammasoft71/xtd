# debug_cassert

Shows how to use [debug::cassert](../../../../src/xtd.core/include/xtd/diagnostics/debug.h) method.

## Sources

[src/stack_trace.cpp](src/debug_cassert.cpp)

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
