# as

Shows how to use [xtd::as](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga19379a1158ccd320e208b362f11295b7) operator.

## Sources

* [src/as.cpp](src/as.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
d = 41.6, convert::to_int32(d) = 42, as<int>(d) = 42
i = 42, convert::to_string(i) = 42, as<string>(i) = 42
a = string, convert::to_string(a) = string, as<string>(a) = string
p = a, convert_pointer::to_ptr<string>(p) = a, as<string>(p) = a
Bad cast : Specified cast is not valid. !
Bad cast : Specified cast is not valid. !
```
