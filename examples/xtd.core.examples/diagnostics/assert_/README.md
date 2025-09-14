# assert

Shows how to use [assert_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__debug.html#gad1e9d87aeb065b1eec47e92a49fd01e9) macro.

## Sources

* [src/assert_.cpp](src/assert_.cpp)
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
> Break the debugger on file assert_.cpp line 11.
> If user choose continue running after break.
End application

> If user clicks assert dialog 'Ignore' button:
Start application
End application
```
