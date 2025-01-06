# enumerable_default_if_empty2

Shows how to use [xtd::linq::enumerable::default_if_empty](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1linq_1_1enumerable.html#a77cd5c4f6280710bd7422cb5bb6ca0d1) method.

## Sources

[src/enumerable_default_if_empty2.cpp](src/enumerable_default_if_empty2.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
pet {name=Barley, age=8}
pet {name=Boots, age=4}
pet {name=Whiskers, age=1}

pet {name=Default pet, age=0}

```
