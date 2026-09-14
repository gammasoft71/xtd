# bit_converter_to_string4

Shows how to use [xtd::bit_converter::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1bit__converter.html#a6baa470168d21a5668ff105ade7d482f) and [xtd::bit_converter::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1bit__converter.html#aa38d54dbc0c793f7ad3d8f536c1a27a6) methods.

## Sources

* [src/bit_converter_to_string4.cpp](src/bit_converter_to_string4.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
This example of the
  xtd::bit_converter::to_string(const xtd::read_only_span<byte>&, xtd::usize) and
  xtd::bit_converter::to_string(const xtd::read_only_span<byte>&, xtd::usize, xtd::usize)
methods generates the following output.

array_one
---------
00-00-00-00-80-3F-00-00-70-41-00-FF-7F-47-00-00-80-3B-00-00-
80-2F-49-46-83-05-4B-06-9E-3F-4D-06-9E-3F-50-06-9E-3F-1E-37-
BE-79-FF-FF-7F-FF-FF-7F-7F-01-00-00-00-C0-FF-00-00-80-FF-00-
00-80-7F

array_two
---------
FF-FF-FF-00-00-14-00-21-00-00-00-01-00-00-00-64-A7-B3-B6-E0-
0D-00-CA-9A-3B-00-8F-5B-00-AA-AA-AA-AA-AA-AA-00-00-E8-89-04-
23-C7-8A-FF-E8-F4-FF-FC-CD-FF-FF-81

array_three
-----------
00-DE-00-00-00-E0-6F-40-00-00-E0-FF-FF-FF-EF-41-00-00-83-00-
00-00-70-3F-00-8F-00-64-00-00-F0-3D-DF-88-1E-1C-FE-74-AA-01-
FA-59-8C-42-CA-C0-F3-3F-FB-59-8C-42-CA-C0-F3-3F-FC-59-8C-42-
CA-C0-F3-3F-52-D3-BB-BC-E8-7E-FF-FF-FF-F4-FF-EF-7F-01-00-00-
00-0A-11-00-00-F8-FF-00-58-00-5B-00-00-F0-FF-00-00-F0-9D

```
