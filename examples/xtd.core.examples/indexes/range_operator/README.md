# range_operator

Shows how to use [xtd::range](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1range.html) struct as operator.

## Sources

* [src/range_operator.cpp](src/range_operator.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
items = [persona {Oliver Queen, 24}, persona {Laurel Lance, 23}, persona {John "Dig" Diggle, 27}, persona {Thea Queen, 20}, persona {Felicity Smoak, 22}]

items[range::all()] = [persona {Oliver Queen, 24}, persona {Laurel Lance, 23}, persona {John "Dig" Diggle, 27}, persona {Thea Queen, 20}, persona {Felicity Smoak, 22}]
items[range {2_i, ~0_i}] = [persona {John "Dig" Diggle, 27}, persona {Thea Queen, 20}, persona {Felicity Smoak, 22}]
items[range {0, 4}] = [persona {Oliver Queen, 24}, persona {Laurel Lance, 23}, persona {John "Dig" Diggle, 27}, persona {Thea Queen, 20}]
items["1..3"_r] = [persona {Laurel Lance, 23}, persona {John "Dig" Diggle, 27}]
```
