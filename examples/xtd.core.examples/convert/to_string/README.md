# to_string

Shows how to use [xtd::convert::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert.html#a1de05be36bc70b03e74ec7d9586b0199) method and [xtd::convert_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert__string.html) class.

## Sources

* [src/to_string.cpp](src/to_string.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Convert int to string :
-----------------------
to_string(value)            = 42
as<string>(value)           = 42
convert::to_string(value)   = 42
string::format("{}", value) = 42

Convert float to string :
-------------------------
to_string(float_value)            = 42.5
as<string>(float_value)           = 42.5
convert::to_string(float_value)   = 42.5
string::format("{}", float_value) = 42.5

Convert any to string :
-----------------------
to_string(any_value)            = 42
as<string>(any_value)           = 42
convert::to_string(any_value)   = 42
string::format("{}", any_value) = 42

Convert any_object to string :
------------------------------
to_string(any_object_value)            = 42
as<string>(any_object_value)           = 42
convert::to_string(any_object_value)   = 42
string::format("{}", any_object_value) = 42

Convert const char16 to string :
--------------------------------
to_string(wstring_value)                      = A string value
as<string>(const_char16_value)                = A string value
convert::to_string(const_char16_value)        = A string value
convert_string::to_string(const_char16_value) = A string value
string::format("{}", const_char16_value)      = A string value

Convert wstring to string :
---------------------------
to_string(wstring_value)                 = A string value
as<string>(wstring_value)                = A string value
convert::to_string(wstring_value)        = A string value
convert_string::to_string(wstring_value) = A string value
string::format("{}", wstring_value)      = A string value
Program ended with exit code: 0
```
