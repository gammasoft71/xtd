# generic_list_binary_search

Shows how to use [xtd::collections::generic::list::binary_search](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1list.html) class.

## Sources

[src/generic_list_binary_search.cpp](src/generic_list_binary_search.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```

Pachycephalosaurus
Amargasaurus
Mamenchisaurus
Deinonychus

sort

Amargasaurus
Deinonychus
Mamenchisaurus
Pachycephalosaurus

binary_search and insert "Coelophysis":

Amargasaurus
Coelophysis
Deinonychus
Mamenchisaurus
Pachycephalosaurus

binary_search and insert "Tyrannosaurus":

Amargasaurus
Coelophysis
Deinonychus
Mamenchisaurus
Pachycephalosaurus
Tyrannosaurus
```
