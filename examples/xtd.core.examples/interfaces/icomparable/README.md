# icomparable

Shows how to use how to use [xtd::iequatable](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1icomparable.html) interface.

## Sources

[src/icomparable.cpp](src/icomparable.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
foo {42}.compare_to(foo {42}) = 0
foo {42}.compare_to(foo {41}) = 1
foo {42}.compare_to(foo {43}) = -1

foo {42} <=> foo {42} = equivalent
foo {42} <=> foo {41} = greater
foo {42} <=> foo {43} = less

foo {42} <= foo {42} = true
foo {42} <= foo {41} = false
foo {42} <= foo {43} = true

foo {42} < foo {42} = false
foo {42} < foo {41} = false
foo {42} < foo {43} = true

foo {42} >= foo {42} = true
foo {42} >= foo {41} = true
foo {42} >= foo {43} = false

foo {42} > foo {42} = false
foo {42} > foo {41} = true
foo {42} > foo {43} = false
```
