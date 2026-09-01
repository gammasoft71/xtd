# index_operator

Shows how to use [xtd::index](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1index.html) struct as operator.

## Sources

* [src/index_operator.cpp](src/index_operator.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
items = [persona {Oliver Queen, 24}, persona {Laurel Lance, 23}, persona {John "Dig" Diggle, 27}, persona {Thea Queen, 20}, persona {Felicity Smoak, 22}]

items[0_i] = persona {Oliver Queen, 24}
items[2] = persona {John "Dig" Diggle, 27}
items[~1_i] = persona {Felicity Smoak, 22}

items[1_i] = persona {Laurel Lance, 23}
items[1_i] (updated) = persona {Laurel Lance, 24}
```
