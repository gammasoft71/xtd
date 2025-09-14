# xtd_collection_indexer

Shows how to use indexing operators with [xtd::bpos](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gae5b63301b69ce281ee7db98e2e61941f) (bpos, bpos + 1, bpos + 2), [xtd::epos](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gaa99759e66edbafa9f3ed0b523c924b5c) (epos, epos - 1, epos - 2, ...) and bitwise operators (~1_z, ~2_z, ...) with xtd collections like [xtd::collections::generic::list](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1list.html).

## Sources

* [src/xtd_collection_indexer.cpp](src/xtd_collection_indexer.cpp)

* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
10
20
30
30
20
10
10
20
30
30
20
10
```
