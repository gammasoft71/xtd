# variant

Shows how to use [xtd::as](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga19379a1158ccd320e208b362f11295b7) operator with std::variant.

## Sources

* [src/variant.cpp](src/variant.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
int -> 0x2A
double -> 21.00 %
string -> "value"
bool -> true
foo -> 84
date_time -> 05/01/1971 23:32:44

int -> 0x2A
double -> 21.00 %
string -> "value"
bool -> true
foo -> 84
date_time -> 05/01/1971 23:32:44
```
