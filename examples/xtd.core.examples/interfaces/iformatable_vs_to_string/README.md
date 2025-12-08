# iformatable_vs_to_string

Shows how to use [xtd::iformatable](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1iformatable.html) interface and [xtd::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#gaceb0e0a25d04cce9beebad549c27c167) method.

## Sources

* [src/iformatable_vs_to_string.cpp](src/iformatable_vs_to_string.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
foo1 standard output :
  (unregistered)
  42
  (unregistered)
  0b(unregistered)
  0b00101010

foo1 write_line :
  (unregistered)
  42
  (unregistered)
  0b(unregistered)
  0b00101010

foo2 standard output :
  (unregistered)
  42
  42
  0b00101010
  0b00101010

foo2 write_line :
  42
  42
  42
  0b00101010
  0b00101010

foo3 standard output :
  (unregistered)
  42
  42
  0b00101010
  0b00101010

foo3 write_line :
  42
  42
  42
  0b00101010
  0b00101010

foo4 standard output :
  42
  42
  42
  0b42
  0b00101010

foo4 write_line :
  42
  42
  42
  0b42
  0b00101010

foo5 standard output :
  42
  42
  42
  0b00101010
  0b00101010

foo5 write_line :
  42
  42
  42
  0b00101010
  0b00101010

foo6 standard output :
  42
  42
  42
  0b00101010
  0b00101010

foo6 write_line :
  42
  42
  42
  0b00101010
  0b00101010

foo7 standard output :
  42
  42
  42
  0b00101010
  0b00101010

foo7 write_line :
  42
  42
  42
  0b00101010
  0b00101010
```
