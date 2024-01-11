# format_date_time

Show how to use format [xtd::format](https://gammasoft71.github.io/xtd/reference_guides/latest/_format_page.html) class with [std::chrono](https://en.cppreference.com/w/cpp/chrono) utilities.

## Sources

[src/format_date_time.cpp](src/format_date_time.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output (with colors)

```
Sat Jan  2 03:04:05 2021
01/02/2021
1/02/2021
03:04:05
3:04:05
Sat Jan  2 03:04:05 2021
Sat Jan  2 03:04:05 2021
Sat Jan  2 03:04:05 2021
Sat Jan  2 03:04:05 2021
Sat
Saturday
02
2
Jan
January
01
1
21
2021
January 2
January 2
Saturday, 2 January 2021
Saturday, 2 January 2021
2 January 2021
2021-01-02T03:04:05
03:04:05
3:04:05
2021-01-02 03:04:05
Saturday, 2 January 2021 3:04:05
03:04
3:04
January 21
January 2021
CET
CET
```

