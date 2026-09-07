# array_as_read_only

Shows how to use [xtd::array::as_read_only](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1array_3_4.html#a7edca610710ffecef0f2f2fa1db6f2b3) method.

## Sources

* [src/array.cpp](src/array_as_read_only.cpp)
* [CMakeLists.txt](CMakeLists.txt)

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
