# system_exception

Shows how to use [system_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1system__exception.html) exception.

## Sources

[src/system_exception.cpp](src/system_exception.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Exception occured :
-------------------
xtd::system_exception : The handle is null
   at destroy_handle(long) [0x00004B20] in /|---OMITTED---|/system_exception/src/system_exception.cpp:line 10
   at main [0x00004DD0] in /|---OMITTED---|/system_exception/Debug/system_exception:line 0
```
