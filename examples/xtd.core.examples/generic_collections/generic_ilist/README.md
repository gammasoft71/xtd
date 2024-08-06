# generic_ilist

Shows how to use [xtd::collections::generic::ilist](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1ilist.html) interface.

## Sources

[src/generic_ilist.cpp](src/generic_ilist.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
A box with 10x4x6 dimensions was already added to the collection.

height  length  width   hash code
10      4       6       204188593481
4       6       10      204188593481
6       10      4       204188593481
12      8       10      204188593481

Removing 6x10x4

height  length  width   hash code
10      4       6       204188593481
4       6       10      204188593481
12      8       10      204188593481

Contains 8x12x10 by dimensions: false
Contains 8x12x10 by volume: true
```
