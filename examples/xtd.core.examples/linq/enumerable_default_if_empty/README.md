# enumerable_default_if_empty

Shows how to use [xtd::linq::enumerable::default_if_empty](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1linq_1_1enumerable.html#a89cb4c7f69e1af47e2d24c5e4e963925) method.

## Sources

[src/enumerable_default_if_empty.cpp](src/enumerable_default_if_empty.cpp)

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

pet {name=, age=0}

```
