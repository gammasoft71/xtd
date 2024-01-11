# to_ustring

Shows how to use [xtd::convert::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert.html#a1de05be36bc70b03e74ec7d9586b0199) method and [xtd::convert_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert__string.html) class.

## Sources

[src/to_ustring.cpp](src/to_ustring.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Convert int to ustring :
------------------------
to_ustring(value)            = 42
as<ustring>(value)           = 42
convert::to_ustring(value)   = 42
ustring::format("{}", value) = 42

Convert float to ustring :
--------------------------
to_ustring(float_value)            = 42.5
as<ustring>(float_value)           = 42.5
convert::to_ustring(float_value)   = 42.5
ustring::format("{}", float_value) = 42.5

Convert any to ustring :
------------------------
to_ustring(any_value)            = 42
as<ustring>(any_value)           = 42
convert::to_ustring(any_value)   = 42
ustring::format("{}", any_value) = 42

Convert const char16 to ustring :
-----------------------------------
to_ustring(wstring_value)                      = A string value
as<ustring>(const_char16_value)                = A string value
convert::to_ustring(const_char16_value)        = A string value
convert_string::to_ustring(const_char16_value) = A string value
ustring::format("{}", const_char16_value)      = A string value

Convert wstring to ustring :
----------------------------
to_ustring(wstring_value)                 = A string value
as<ustring>(wstring_value)                = A string value
convert::to_ustring(wstring_value)        = A string value
convert_string::to_ustring(wstring_value) = A string value
ustring::format("{}", wstring_value)      = A string value
Program ended with exit code: 0
```
