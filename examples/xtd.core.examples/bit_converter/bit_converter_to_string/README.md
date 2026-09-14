# bit_converter_to_string

Shows how to use [xtd::bit_converter::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1bit__converter.html#a40a3bfbf49e3e964a052e8ccf99e9927) method.

## Sources

* [src/bit_converter_to_string.cpp](src/bit_converter_to_string.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
This example of the xtd::bit_converter::to_string(const xtd::array<xtd::byte>&) 
method generates the following output.

array_one
---------
00-01-02-04-08-10-20-40-80-FF

array_two
---------
20-00-00-2A-00-41-00-7D-00-C5-00-A8-03-29-04-AC-20

array_three
-----------
0F-00-00-80-10-27-F0-D8-F1-FF-7F

array_four
----------
0F-00-00-00-00-10-00-FF-03-00-00-CA-9A-3B-FF-FF-FF-FF-7F

```
