# args_echo

This code example shows how to use [xtd::diagnostics::process_start_info](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1diagnostics_1_1process__start__info.html) class.

## Sources

[src/args_echo.cpp](src/args_echo.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run one two "three four" five
```

## Output

```
Received the following arguments:

[0] = oone
[1] = two
[2] = three four
[3] = five

```
