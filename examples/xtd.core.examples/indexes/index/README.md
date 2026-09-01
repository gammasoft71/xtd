# index

Shows how to use [xtd::index](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1index.html) struct.

## Sources

* [src/index.cpp](src/index.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
items[xtd::index::from_start(0)] = 1
items(xtd::index {1, false}) = 2
items[xtd::index {2}] = 3
items(xtd::index {~3, true}) = 4
items[xtd::index {4}] = 5
items(xtd::index {5}) = 6
items[xtd::index {6}] = 7
items(xtd::index {7}) = 8
items[xtd::index {8}] = 9
items(xtd::index::from_start(9)) = 10

items[xtd::index::from_end(1)] = 10
items(xtd::index {2}, true)) = 9
items[xtd::index {~3}] = 8
items(xtd::index {~4, false}) = 7
items[xtd::index {~5}] = 6
items(xtd::index {~6}) = 5
items[xtd::index {~7}] = 4
items(xtd::index {~8}) = 3
items[xtd::index {~9}] = 2
items(xtd::index::from_end(10)) = 1
```
