# object_and_iequatable

Shows hows how to use [xtd::object](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1object.html) and [xtd::iequatable](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1iequatable.html).

## Sources

[src/object_and_iequatable.cpp](src/object_and_iequatable.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
foo1 equals foo2: true
foo1 equals foo3: false
foo1 equals foo2 (object): true
foo1 equals foo3 (object): false
foo1 hash code: 9105846386475545849
foo2 hash code: 9105846386475545849
foo3 hash code: 4537660354082115200
foo1 == foo2: true
foo1 != foo3: true
foo: id = 1, name = Example
foo: id = 1, name = Example
foo: id = 2, name = Different
```
