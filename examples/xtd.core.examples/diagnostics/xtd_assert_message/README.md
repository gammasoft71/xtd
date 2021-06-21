# xtd_assert_message

Shows how to use [xtd_assert_message](../../../../src/xtd.core/include/xtd/diagnostics/xtd_assert.h) macro.

## Sources

[src/stack_trace.cpp](src/xtd_assert.cpp)

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
