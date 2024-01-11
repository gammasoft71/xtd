# default_trace_listener

Shows how to use [xtd::diagnostics::default_trace_listener](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1diagnostics_1_1default__trace__listener.html) class.

## Sources

[src/default_trace_listener.cpp](src/default_trace_listener.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
stack_trace:
   at test3()
   at test2()
   at test1()
   at main
```
