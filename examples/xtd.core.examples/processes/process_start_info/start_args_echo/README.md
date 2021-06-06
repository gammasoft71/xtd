# start_args_echo

This code example shows how to use ProcessStartInfo class.

# Sources

[CMakeLists.txt](CMakeLists.txt)

[src/start_args_echo.cpp](src/start_args_echo.cpp)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run
```

# Output

```
Received the following arguments:

[0] = /a

Received the following arguments:

[0] = /a
[1] = /b
[2] = c:\temp

Received the following arguments:

[0] = /a
[1] = literal string arg

Received the following arguments:

[0] = /a
[1] = /b:string
[2] = in
[3] = double
[4] = quotes

Received the following arguments:

[0] = /a
[1] = /b:"quoted string"

```
