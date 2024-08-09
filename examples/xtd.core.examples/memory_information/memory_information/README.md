# memory_information

Shows how to use [xtd::memory_information](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1memory_information.html) class.

## Sources

[src/memory_information.cpp](src/memory_information.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Physical memory
  total =  34359738368 ( 32 GB)
  used  =  18914050048 ( 17 GB)
  free  =  15445688320 ( 14 GB)

Virtual memory
  total = 600992124928 (559 GB)
  used  = 420945264640 (392 GB)
  free  = 180046860288 (167 GB)

Process memory
  total = 180046860288 (167 GB)
  used  =     40550400 ( 38 MB)
  free  = 180006309888 (167 GB)
```
