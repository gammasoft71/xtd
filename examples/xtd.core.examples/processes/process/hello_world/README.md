# args_echo

This code example shows how to use [xtd::diagnostics::process_start_info](../../../../../src/xtd.core/include/xtd/diagnostics/process_start_info.h) class.

# Sources

[CMakeLists.txt](CMakeLists.txt)

[src/args_echo.cpp](src/args_echo.cpp)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run one two "three four" five
```

# Output

```
Received the following arguments:

[0] = oone
[1] = two
[2] = three four
[3] = five

```
