# parse_floating_point

Shows how to use format [xtd::parse](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#gaf38b51b1a3c788f678bb6e89f7694ee4) method with floating point values (float, double and decimal).

## Sources

[src/parse_floating_point.cpp](src/parse_floating_point.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output (with colors)

```
12.345
12.345
12.345
inf
-inf
nan
Exception : invalid character found
```

