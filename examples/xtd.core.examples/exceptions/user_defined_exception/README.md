# user_defined_exception

Shows how to use [xtd::exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html) exception.

## Sources

[src/user_defined_exception.cpp](src/user_defined_exception.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
type              = user_defined_exception::employee_list_not_found_exception
help_link         = 
h_result          = 0x80131500 (2148734208)
inner_exception   = (null)
message           = The employee list does not exist.
source            = user_defined_exception
stack_trace       =    at main [0x0000665C] in /Users/yves/Projects/xtd/examples/xtd.core.examples/exceptions/user_defined_exception/src/user_defined_exception.cpp:line 24
```
