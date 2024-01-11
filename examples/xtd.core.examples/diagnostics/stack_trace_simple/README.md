# stack_trace_simple

Demonstrates how to create a simple [xtd::diagnostics::stack_trace](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1diagnostics_1_1stack__trace.html) class and iterate through its frames to obtain debugging and diagnostic information.

## Sources

[src/stack_trace_simple.cpp](src/stack_trace_simple.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
 File: /!---OMITTED---!/stack_trace_simple
 Line Number: 24

   Method: stack_trace_sample::my_protected_method()
   File: /!---OMITTED---!/stack_trace_simple
   Line Number: 14

     Method: stack_trace_sample::my_public_method()
     File: /!---OMITTED---!/stack_trace_simple
     Line Number: 9

       Method: main
       File: /!---OMITTED---!/stack_trace_simple
       Line Number: 44

High up the call stack, Method: main
High up the call stack, Line Number: 0
```
