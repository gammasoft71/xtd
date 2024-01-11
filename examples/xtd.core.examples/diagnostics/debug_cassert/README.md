# debug_cassert

Shows how to use [debug::cassert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1diagnostics_1_1debug.html#acdb0d00e4b12fccc037cf3f965110d72) method.

## Sources

[src/debug_cassert.cpp](src/debug_cassert.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
> If user clicks assert dialog 'Abort' button:
Start application

> If user clicks assert dialog 'Retry' button:
Start application
> Break the debugger on file debug_cassert.cpp line 12.
> If user choose continue running after break.
End application

> If user clicks assert dialog 'Ignore' button:
Start application
End application
```
