# bit_converter

Shows how to use [xtd::bit_converter](../../../../src/xtd.core/include/xtd/bit_converter.h) class.

## Sources

[src/bit_converter.cpp](src/bit_converter.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
This example of methods of the BitConverter class
generates the following output.

                 argument                    byte array
                 --------                    ----------
        0.111111111111111       1C-C7-71-1C-C7-71-BC-3F
                0.1111111                   39-8E-E3-3D
      1111111111111111111       C7-71-C4-2B-AB-75-6B-0F
               1111111111                   C7-35-3A-42
                    11111                         67-2B
                        *                   2A-00-00-00
                     True                            01
```