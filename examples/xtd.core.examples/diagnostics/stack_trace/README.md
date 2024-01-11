# stack_trace

Shows how to use [xtd::diagnostics::stack_trace](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1diagnostics_1_1stack__trace.html) class.

## Sources

[src/stack_trace.cpp](src/stack_trace.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
stack_trace:
   at method3()
   at method2()
   at method1()
   at main
```
