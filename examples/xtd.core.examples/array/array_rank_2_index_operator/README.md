# array

Shows how to use [xtd::array\[\]](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1array_3_01type__t_00_012_00_01allocator__t_01_4.html#afe859dabc4cd807a6269f58a60fb2d19) and [xtd::array()](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1array_3_01type__t_00_011_00_01allocator__t_01_4.html#ac17607656c7da9d5c4079f94199a3b77) operators.

## Sources

* [src/array_rank_1_index_operator.cpp](src/array_rank_1_index_operator.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Read with [] operator:
  items[0] = 1
  items[1] = 2
  items[2] = 3
  items[3] = 4
  items[4] = 5
  items[5] = 6
  items[6] = 7
  items[7] = 8
  items[8] = 9
  items[9] = 10

Read with () operator:
  items(0) = 1
  items(1) = 2
  items(2) = 3
  items(3) = 4
  items(4) = 5
  items(5) = 6
  items(6) = 7
  items(7) = 8
  items(8) = 9
  items(9) = 10

Write with [] operator:
  items = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]

Write with () operator:
  items = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]
