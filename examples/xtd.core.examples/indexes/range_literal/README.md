# range_literal

Shows how to use [xtd::range](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1range.html) struct.

## Sources

* [src/range_literal.cpp](src/range_literal.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
items["0..10"_r] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
items["2..6"_r] = [3, 4, 5, 6]
items["0..~0"_r] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
items["2..~4"_r] = [3, 4, 5, 6]
items["~10..~0"_r] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
items["~8..~4"_r] = [3, 4, 5, 6]
```
