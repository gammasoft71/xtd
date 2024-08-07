# generic_list_as_read_only

Shows how to use [xtd::collections::generic::list](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1list.html) class.

## Sources

[src/generic_list_as_read_only.cpp](src/generic_list_as_read_only.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```

capacity: 0

Tyrannosaurus
Amargasaurus
Deinonychus
Compsognathus

auto ro_dinosaurs = dinosaurs.as_read_only()

Elements in the read-only ilist:
Tyrannosaurus
Amargasaurus
Deinonychus
Compsognathus

dinosaurs[2] = "Coelophysis"

Elements in the read-only ilist:
Tyrannosaurus
Amargasaurus
Coelophysis
Compsognathus
```
