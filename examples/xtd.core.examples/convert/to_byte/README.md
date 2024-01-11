# to_byte

Shows how to use [xtd::convert::to_byte](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert.html#a31ae0aaad2259a0d02bce9c06a5df2c1) method.

## Sources

[src/to_byte.cpp](src/to_byte.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Convert int to byte :
---------------------
static_cast<unsigned char>(value) = 42
as<unsigned char>(value)          = 42
convert::to_byte(value)           = 42

Convert float to byte :
-----------------------
static_cast<unsigned char>(float_value) = 42
as<unsigned char>(float_value)          = 43
convert::to_byte(float_value)           = 43

Convert any to byte :
---------------------
any_cast<unsigned char>(any_value) = 42
as<unsigned char>(any_value)       = 42
convert::to_byte(any_value)        = 42

Convert string to byte :
------------------------
parse<unsigned char>(string_value))   = 42
as<unsigned char>(string_value)       = 42
convert::to_byte(string_value)        = 42

Convert hexa string to byte :
-----------------------------
parse<unsigned char>(string_hex_value, number_styles::hex_number) = 42
as<unsigned char>(string_hex_value, 16)                           = 42
convert::to_byte(string_hex_value, 16))                           = 42

Convert int to byte with overflow :
-----------------------------------
static_cast<unsigned char>(overflow_value) = 1
(ERROR) as : Overflow exception
(ERROR) convert::to_byte : Overflow exception
```
