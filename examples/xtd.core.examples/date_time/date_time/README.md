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
d1 (Thu Dec 30 16:18:10 2021) ~= d1 (Thu Dec 30 16:18:10 2021): true
d1 (Thu Dec 30 16:18:10 2021) ~= d2 (Thu Dec 30 16:18:30 2021): false
d1 (Thu Dec 30 16:18:10 2021) ~= d3 (Thu Dec 30 16:17:50 2021): false
d1 (Thu Dec 30 16:18:10 2021) ~= d4 (Thu Dec 30 16:18:15 2021): true
d1 (Thu Dec 30 16:18:10 2021) ~= d5 (Thu Dec 30 16:18:05 2021): true
d1 (Thu Dec 30 16:18:10 2021) ~= d6 (Thu Dec 30 18:18:30 2021): false
d1 (Thu Dec 30 16:18:10 2021) ~= d7 (Thu Dec 30 18:17:50 2021): false
d1 (Thu Dec 30 16:18:10 2021) ~= d8 (Thu Dec 30 18:18:15 2021): true
d1 (Thu Dec 30 16:18:10 2021) ~= d9 (Thu Dec 30 18:18:05 2021): true
```
