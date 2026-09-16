# array_rank_2_and_mdspan

Shows how to use [xtd::array\[\]](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1array_3_01type__t_00_012_00_01allocator__t_01_4.html) class.

## Sources

* [src/array_rank_2_and_mdspan.cpp](src/array_rank_2_and_mdspan.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Read with std::mdspan:
  view1[0, 0] = 11
  view1[0, 1] = 12
  view1[0, 2] = 13
  view1[0, 3] = 14
  view1[0, 4] = 15
  view1[1, 0] = 21
  view1[1, 1] = 22
  view1[1, 2] = 23
  view1[1, 3] = 24
  view1[1, 4] = 25
```
