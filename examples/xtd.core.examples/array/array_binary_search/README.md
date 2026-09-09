# array_binary_search

Shows how to use [xtd::array<>::binary_search](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1array_3_4.html#af7d6d835b28dd7be7f1c68d852b502ce) method.

## Sources

* [src/array_binary_search.cpp](src/array_binary_search.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```

Pachycephalosaurus
Amargasaurus
Tyrannosaurus
Mamenchisaurus
Deinonychus
Edmontosaurus

sort

Amargasaurus
Deinonychus
Edmontosaurus
Mamenchisaurus
Pachycephalosaurus
Tyrannosaurus

binary_search for "Coelophysis":
Not found. Sorts between: Amargasaurus and Deinonychus.

binary_search for "Tyrannosaurus":
Found at index 5.
```
