# iequatable

Shows how to use how to use [xtd::iequatable](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1iequatable.html) interface.

## Sources

[src/iequatable.cpp](src/iequatable.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
foo {42}.equals(foo {42}) = true
foo {42}.equals(foo {84}) = false

!foo {42}.equals(foo {42}) = false
!foo {42}.equals(foo {84}) = true

foo {42} == foo {42} = true
foo {42} == foo {84} = false

foo {42} != foo {42} = false
foo {42} != foo {84} = true
```
