# generic_list

Shows how to use [xtd::collections::generic::list](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1list.html) class.

## Sources

[src/generic_list.cpp](src/generic_list.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
capacity: 0

ID: 1234   Name: crank arm
ID: 1334   Name: chain ring
ID: 1434   Name: seat
ID: 1534   Name: cassette
ID: 1634   Name: shift lever

capacity: 8
count: 5

trim_excess()
capacity: 5
count: 5

clear()
capacity: 5
count: 0
```
