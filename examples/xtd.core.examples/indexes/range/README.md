# range

Shows how to use [xtd::range](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1range.html) struct.

## Sources

* [src/range.cpp](src/range.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
items[range::all()] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
items(range::start_at(2)) = [3, 4, 5, 6, 7, 8, 9, 10]
items[range::start_at(index::from_end(8))] = [3, 4, 5, 6, 7, 8, 9, 10]
items(range::start_at(~8_i)) = [3, 4, 5, 6, 7, 8, 9, 10]
items[range::end_at(6)] = [1, 2, 3, 4, 5, 6]
items(range::end_at(index::from_start(6))) = [1, 2, 3, 4, 5, 6]
items(range::end_at(~4_i)) = [1, 2, 3, 4, 5, 6]
items(range {2, 6}) = [3, 4, 5, 6]
items[range {3_i, ~2_i}) = [4, 5, 6, 7, 8]
items[{0, 8}] = [1, 2, 3, 4, 5, 6, 7, 8]
items[{1_i, ~4_i}][{1_i, ~1_i}] = [3, 4, 5]
```
