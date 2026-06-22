# console_info

Shows how to use [xtd::console](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html) class.

## Sources

* [src/console_info.cpp](src/console_info.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Streams:
  Is error redirected = false
  Is input redirected = false
  Is output redirected = false

Input:
  Key available = false
  Caps lock = false
  Number lock = true
  Treat control-c as input = false
  Input code page = 65001

Output:
  Background color = default_color
  Foreground color = default_color
  Cursor left = 0
  Cursor top = 18
  Cursor size = 100%
  Cursor visible = true
  Auto flush out = true
  Autput code page = 65001

Window:
  Title = 
  Window left = 0
  Window top = 0
  Window width = 120
  Window height = 30
  Largest window width = 1000
  Largest window height = 1000
  Buffer width = 120
  Buffer height = 30
```
