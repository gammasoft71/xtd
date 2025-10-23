# date_time

Shows how to use [xtd::date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) class.

## Sources

* [src/date_time.cpp](src/date_time.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
d1 (10/23/2025 1:04:56 AM) ~= d1 (10/23/2025 1:04:56 AM): true
d1 (10/23/2025 1:04:56 AM) ~= d2 (10/23/2025 1:05:16 AM): false
d1 (10/23/2025 1:04:56 AM) ~= d3 (10/23/2025 1:04:36 AM): false
d1 (10/23/2025 1:04:56 AM) ~= d4 (10/23/2025 1:05:01 AM): true
d1 (10/23/2025 1:04:56 AM) ~= d5 (10/23/2025 1:04:51 AM): true
d1 (10/23/2025 1:04:56 AM) ~= d6 (10/23/2025 3:05:16 AM): false
d1 (10/23/2025 1:04:56 AM) ~= d7 (10/23/2025 3:04:36 AM): false
d1 (10/23/2025 1:04:56 AM) ~= d8 (10/23/2025 3:05:01 AM): true
d1 (10/23/2025 1:04:56 AM) ~= d9 (10/23/2025 3:04:51 AM): true
```
