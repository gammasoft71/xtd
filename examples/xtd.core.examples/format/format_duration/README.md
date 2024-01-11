# format_duration

Show how to use format [xtd::format](https://gammasoft71.github.io/xtd/reference_guides/latest/_format_page.html) class with [std::chrono](https://en.cppreference.com/w/cpp/chrono) duration.

## Sources

[src/format_duration.cpp](src/format_duration.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output (with colors)

```
1.02:03:32:024000500
1.02:03:32:024000500
1
01
1:2:03:32:024000500
1:02:03:32:024000500
1.2:03:32:024000500
1.02:03:32:024000500
2
02
3
03
24000500
024000500
32
32
```

