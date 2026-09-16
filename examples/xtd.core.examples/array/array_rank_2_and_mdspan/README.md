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
items = [[11, 12, 13, 14, 15], [21, 22, 23, 24, 25]]

Read with xtd::array:
  items[0, 0] = 11
  items[0, 1] = 12
  items[0, 2] = 13
  items[0, 3] = 14
  items[0, 4] = 15
  items[1, 0] = 21
  items[1, 1] = 22
  items[1, 2] = 23
  items[1, 3] = 24
  items[1, 4] = 25

view = [[11, 12, 13, 14, 15], [21, 22, 23, 24, 25]]

Read with std::mdspan:
  view[0, 0] = 11
  view[0, 1] = 12
  view[0, 2] = 13
  view[0, 3] = 14
  view[0, 4] = 15
  view[1, 0] = 21
  view[1, 1] = 22
  view[1, 2] = 23
  view[1, 3] = 24
  view[1, 4] = 25
```
