# generic_ordered_dictionary

Shows how to use [xtd::collections::generic::ordered_dictionary](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1ordered__dictionary.html) class.

## Sources

* [src/generic_ordered_dictionary.cpp](src/generic_ordered_dictionary.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
   INDEX KEY                       VALUE
   0     test_key1                 test_value1
   1     test_key2                 test_value2
   2     key_to_delete             value_to_delete
   3     test_key3                 test_value3


Displaying the entries of a modified ordered_dictionary.
   INDEX KEY                       VALUE
   0     inserted_key              inserted_value1
   1     test_key1                 test_value1
   2     test_key2                 modified_value


Displaying the entries of a "new" ordered_dictionary.
   KEY                       VALUE
   new_key1                  new_value1
   new_key2                  new_value2
   new_key3                  new_value3
```
