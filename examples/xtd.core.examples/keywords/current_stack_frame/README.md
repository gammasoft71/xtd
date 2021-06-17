# current_stack_frame

Shows how to use [xtd::diagnostics::stack_frame](../../../../src/xtd.core/include/xtd/diagnostics/stack_frame.h) class.

## Sources

[src/current_stack_frame.cpp](src/current_stack_frame.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
stack_frame: /!---OMITTED---!/current_stack_frame.cpp:15:0

Message: Something happened.
Method name: main
File name: /!---OMITTED---!/current_stack_trace.cpp
File line number: 15
```
