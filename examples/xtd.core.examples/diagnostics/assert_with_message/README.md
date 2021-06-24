# assert_with_message

Shows how to use [assert_](../../../../src/xtd.core/include/xtd/diagnostics::debug.h) macro.

## Sources

[src/assert_with_message.cpp](src/assert_with_message.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
> If user clicks assert dialog 'Abort' button:
Start application

> If user clicks assert dialog 'Retry' button:
Start application
> Break the debugger on file assert_wuth_message.cpp line 11.
> If user choose continue running after break.
End application

> If user clicks assert dialog 'Ignore' button:
Start application
End application
```
