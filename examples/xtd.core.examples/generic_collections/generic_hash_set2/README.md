# generic_hash_set2

Shows how to use [xtd::collections::generic::hash_set](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1hash__set.html) class.

## Sources

* [src/generic_hash_set2.cpp](src/generic_hash_set2.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
The current hash_set contains:

Automobiles
Trains
Planes

The updated hash_set contains:

Rockets
Motorcycles
Ships
Automobiles
Trains
Submarines
Helicopters
Planes

The 'All' vehicles set contains everything in 'Some' vechicles list.

The 'All' vehicles set contains 'roCKeTs'

The excepted hash_set contains:

Rockets
Motorcycles
Ships
Submarines
Helicopters

The super cool vehicles are:

Motorcycles
Helicopters
```
