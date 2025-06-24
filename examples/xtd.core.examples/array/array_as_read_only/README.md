# array_as_read_only

Shows how to use [xtd::array::as_read_only](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1object__model_1_1read__only__collection.html) method.

## Sources

[src/array.cpp](src/array_as_read_only.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
The string array initially contains the following values:
   [0] : The
   [1] : quick
   [2] : brown
   [3] : fox

The read-only ilist contains the following values:
   [0] : The
   [1] : quick
   [2] : brown
   [3] : fox

xtd::not_supported_exception - Collection is read-only.

After changing the third element, the string array contains the following values:
   [0] : The
   [1] : quick
   [2] : RED
   [3] : fox

After changing the third element, the read-only ilist contains the following values:
   [0] : The
   [1] : quick
   [2] : RED
   [3] : fox

```
