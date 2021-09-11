# to_byte

Shows how to use [xtd::convert](../../../../src/xtd.core/include/xtd/convert.h) class.

# Sources

[src/to_byte.cpp](src/to_byte.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Convert int to byte :
---------------------
static_cast<byte_t>(value) = 42
as<byte_t>(value)          = 42
convert::to_byte(value)    = 42

Convert string to byte :
------------------------
parse<byte_t>(string_value))   = 42
as<byte_t>(string_value)       = 42
convert::to_byte(string_value) = 42

Convert hexa string to byte :
-----------------------------
parse<byte_t>(string_hex_value, number_styles::hex_number) = 42
as<byte_t>(string_hex_value, 16)                           = 42
convert::to_byte(string_hex_value, 16))                    = 42

Convert int to byte with overflow :
-----------------------------------
static_cast<byte_t>(overflow_value) = 1
(ERROR) as : Overflow exception
(ERROR) convert::to_byte : Overflow exception
```
