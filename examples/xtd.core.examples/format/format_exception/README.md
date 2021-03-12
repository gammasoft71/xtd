# format_exception

Show how to use format [xtd::format](../../../../src/xtd.core/include/xtd/format.h) class.

## Sources

[src/format_exception.cpp](src/format_exception.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output (with colors)

```
exception: std::exception
exception: Invvalid argument
xtd::system_exception : System exception
   at main [0x00005620] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/format/format_exception/Debug/format_exception:line 0
xtd::argument_out_of_range_exception : Argument out of range exception
   at main [0x00005620] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/format/format_exception/Debug/format_exception:line 0
```

