# read_only_collection

Shows how to use [xtd::collections::object_model::read_only_collection](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1object__model_1_1read__only__collection.html) class.

## Sources

* [src/read_only_collection.cpp](src/read_only_collection.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Tyrannosaurus
Amargasaurus
Deinonychus
Compsognathus

count: 4

contains("Deinonychus"): true

read_only_dinosaurs[3]: Compsognathus

index_of("Compsognathus"): 3

Insert into the wrapped List:
insert(2, "Oviraptor")

Tyrannosaurus
Amargasaurus
Oviraptor
Deinonychus
Compsognathus

Copied array has 7 elements:
""
"Tyrannosaurus"
"Amargasaurus"
"Oviraptor"
"Deinonychus"
"Compsognathus"
""
```
