# console_read_key

Shows how to use [xtd::console::read_key](../../../../src/xtd.core/include/xtd/basic_console.h) and  [xtd::console::key_available](../../../../src/xtd.core/include/xtd/basic_console.h) methods.

# Sources

[src/console_color.cpp](src/console_read_key.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output if user stroke 'q', 'w', 'e', 'r', 't', 'y', Ctrl+C and Escape keys

```
Key = q (81), Char = 'q' (113), Modifiers = 0
Key = w (87), Char = 'w' (119), Modifiers = 0
Key = e (69), Char = 'e' (101), Modifiers = 0
Key = r (82), Char = 'r' (114), Modifiers = 0
Key = t (84), Char = 't' (116), Modifiers = 0
Key = y (89), Char = 'y' (121), Modifiers = 0
Signal control_c intercepted !
Key = escape (27), Char = ' (27), Modifiers = 0
```
