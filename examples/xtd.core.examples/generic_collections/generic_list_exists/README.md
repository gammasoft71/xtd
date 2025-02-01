# generic_list_convert_all

Shows how to use [xtd::collections::generic::list::convert_all](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1list.html) method.

## Sources

[src/generic_list_convert_all.cpp](src/generic_list_convert_all.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```

Compsognathus
Amargasaurus
Oviraptor
Velociraptor
Deinonychus
Dilophosaurus
Gallimimus
Triceratops

true_for_all(ends_with_saurus): false

find(ends_with_saurus): Amargasaurus

findLast(ends_with_saurus): Dilophosaurus

find_all(ends_with_saurus):
Amargasaurus
Dilophosaurus

2 elements removed by remove_all(ends_with_saurus).

list now contains:
Compsognathus
Oviraptor
Velociraptor
Deinonychus
Gallimimus
Triceratops

exists(ends_with_saurus): false
```
