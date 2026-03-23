# as

Shows how to use [xtd::unsafe::as](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga19379a1158ccd320e208b362f11295b7) operator.

## Sources

* [src/unsafe_as.cpp](src/unsafe_as.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
C++ cast :
  i => 1144201745
  s => "@\317r"
  s => (null)

Unsafe cast :
  i => 1144201745
  s => "@\317r"

Safe cast :
  366216421905 is greater than 2147483647
  "value" is not a std::string

Convert :
  366216421905 is greater than 2147483647
  "value" is not a std::string

```
