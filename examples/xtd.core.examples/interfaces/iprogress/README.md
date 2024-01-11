# iprogress

Shows how to use how to use [xtd::iprogress](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1iprogress.html) interface.

## Sources

[src/iprogress.cpp](src/iprogress.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Started
completion=  0%, message="Initialized"
completion= 20%, message="Device opened"
completion= 40%, message="Device updated 1"
completion= 60%, message="Device updated 2"
completion= 80%, message="Device updated 3"
completion=100%, message="Device closed"
Ended
```
