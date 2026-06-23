# trace_assert_message

Shows how to use [trace::assert_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__debug.html#gab8e6aea91a39c5e05d514044aa2b2ddf) method.

## Sources

* [src/trace_assert.cpp](src/trace_assert.cpp)
* [CMakeLists.txt](CMakeLists.txt)

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
> Break the debugger on file trace_assert.cpp line 13.
> If user choose continue running after break.
End application

> If user clicks assert dialog 'Ignore' button:
Start application
End application
```
