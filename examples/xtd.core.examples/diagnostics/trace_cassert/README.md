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
```
> If user clicks assert dialog 'Abort' button:
Start application

> If user clicks assert dialog 'Retry' button:
Start application
> Break the debugger on file xtd_assert.cpp line 9.
> If user choose continue running after break.
End application

> If user clicks assert dialog 'Ignore' button:
Start application
End application
```
