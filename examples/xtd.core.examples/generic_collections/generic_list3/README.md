# generic_list3

Shows how to use [xtd::collections::generic::list](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1 list.html) class.

## Sources

[src/generic_list3.cpp](src/generic_list3.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```

capacity: 3

Brachiosaurus
Amargasaurus
Mamenchisaurus

add_range(dinosaurs)

Brachiosaurus
Amargasaurus
Mamenchisaurus
Brachiosaurus
Amargasaurus
Mamenchisaurus

remove_range(2, 2)

Brachiosaurus
Amargasaurus
Amargasaurus
Mamenchisaurus

insert_range(3, input)

Brachiosaurus
Amargasaurus
Amargasaurus
Tyrannosaurus
Deinonychus
Velociraptor
Mamenchisaurus

output = dinosaurs.get_range(2, 3).to_array()

Amargasaurus
Tyrannosaurus
Deinonychus
```
