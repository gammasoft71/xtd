# file_settings

Shows how to use [xtd::consiguration::file_settings](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1configuration_1_1file__settings.html) object.

## Sources

[src/file_settings.cpp](src/file_settings.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
----------------------------------------
"exemple.ini" file content :
# Settings file used by file_settings example.
# Copyright (c) 2024 Gammasoft. All rights reserved.

auto_close = true
caption = file_settings example

[Thread "Process"]
timeout = 00:00:00.1000000

----------------------------------------
read keys :
auto_close = true
caption = file_settings example
Thread "Process"
----------------------------------------
```
