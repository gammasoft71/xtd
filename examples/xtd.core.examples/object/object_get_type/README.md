# object_get_type

Shows hows how to use [xtd::object::get_type](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1object.html#a322144840e8ad539c039538997b0fe40) method.

## Sources

[src/object_get_type.cpp](src/object_get_type.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
my_base: type is my_base_class
my_derived: type is my_derived_class
object o = my_derived: type is my_derived_class
my_base_class b = my_derived: type is my_derived_class

my_base: type is my_base_class
my_derived: type is my_derived_class
object o = my_derived: type is my_derived_class
my_base_class b = my_derived: type is my_derived_class
```
