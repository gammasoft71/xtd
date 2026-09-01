# index_literal

Shows how to use [xtd::index](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1index.html) struct.

## Sources

* [src/index_literal.cpp](src/index_literal.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
items["0"_i] = 1
items(1_i) = 2
items[u8"2"_i] = 3
items(3_i) = 4
items[4_i] = 5
items(5_i) = 6
items[6_i] = 7
items(7_i) = 8
items[8_i] = 9
items(u"9"_i) = 10

items["~1"_i] = 10
items(~2_i) = 9
items[U"~3"_i] = 8
items(~4_i) = 7
items[~5_i] = 6
items(~6_i) = 5
items[~7_i] = 4
items(~8_i) = 3
items[~9_i] = 2
items(L"~10"_i) = 1
```
