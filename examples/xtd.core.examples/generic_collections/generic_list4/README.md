# generic_list4

Shows how to use [xtd::collections::generic::list](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1list.html) class.

## Sources

[src/generic_list4.cpp](src/generic_list4.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```

ID: 1234   Name: crank arm
ID: 1334   Name: chain ring
ID: 1434   Name: regular seat
ID: 1444   Name: banana seat
ID: 1534   Name: cassette
ID: 1634   Name: shift lever

contains("1734"): false

Insert(2, "1834")
ID: 1234   Name: crank arm
ID: 1334   Name: chain ring
ID: 1834   Name: brake lever
ID: 1434   Name: regular seat
ID: 1444   Name: banana seat
ID: 1534   Name: cassette
ID: 1634   Name: shift lever

parts[3]: ID: 1434   Name: regular seat

remove("1534")

ID: 1234   Name: crank arm
ID: 1334   Name: chain ring
ID: 1834   Name: brake lever
ID: 1434   Name: regular seat
ID: 1444   Name: banana seat
ID: 1634   Name: shift lever

remove_at(3)

ID: 1234   Name: crank arm
ID: 1334   Name: chain ring
ID: 1834   Name: brake lever
ID: 1444   Name: banana seat
ID: 1634   Name: shift lever
```
