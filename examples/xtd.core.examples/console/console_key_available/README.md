# console_key_available

Shows how to use [xtd::console::key_available](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html#ade7353994e38d4645a831a12caab9427) and [xtd::console::read_key](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html#ac0ebb643e4d3b01faa8380bd90d22aa0) methods.

## Sources

[src/console_key_available.cpp](src/console_key_available.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output if user stroke 'h', 'e', pagge_up, down_arrow, and 'x' keys

```
Press a key to display; press the 'x' key to quit.
You pressed the 'h' key.

Press a key to display; press the 'x' key to quit.
You pressed the 'e' key.

Press a key to display; press the 'x' key to quit.
You pressed the 'page_up' key.

Press a key to display; press the 'x' key to quit.
You pressed the 'down_arrow' key.

Press a key to display; press the 'x' key to quit.
You pressed the 'x' key.
```
