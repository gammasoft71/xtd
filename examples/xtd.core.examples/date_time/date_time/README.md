# date_time

Shows how to use [xtd::date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) class.

## Sources

[src/date_time.cpp](src/date_time.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
d1 (2025-02-04 21:51:19) ~= d1 (2025-02-04 21:51:19): true
d1 (2025-02-04 21:51:19) ~= d2 (2025-02-04 21:51:39): false
d1 (2025-02-04 21:51:19) ~= d3 (2025-02-04 21:50:59): false
d1 (2025-02-04 21:51:19) ~= d4 (2025-02-04 21:51:24): true
d1 (2025-02-04 21:51:19) ~= d5 (2025-02-04 21:51:14): true
d1 (2025-02-04 21:51:19) ~= d6 (2025-02-04 23:51:39): false
d1 (2025-02-04 21:51:19) ~= d7 (2025-02-04 23:50:59): false
d1 (2025-02-04 21:51:19) ~= d8 (2025-02-04 23:51:24): true
d1 (2025-02-04 21:51:19) ~= d9 (2025-02-04 23:51:14): true
```
