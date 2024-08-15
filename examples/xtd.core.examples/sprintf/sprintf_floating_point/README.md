# sprintf_floating_point

Shows how to use [xtd::string::sprintf](https://gammasoft71.github.io/xtd/reference_guides/latest/group__format__parse.html#ga0c65606fb81f84e4d9ea43002114d8de) method.

## Sources

[src/sprintf_floating_point.cpp](src/sprintf_floating_point.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output (with colors)

```
12.345000
12.345000
1.234500e+01
1.234500E+01
12.345
12.345
0x0x1.8b0a3d70a3d71p+3
0x0X1.8B0A3D70A3D71P+3
4.94066E-324
nan
inf
-inf
```

