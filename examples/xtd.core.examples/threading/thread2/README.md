# thread2

Shows how to use [xtd::threading::thread](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1thread.html) class.

## Sources

* [src/thread2.cpp](src/thread2.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
(thread 1) main -> start
(thread 1) main -> sleep(200_ms)
  (thread 2) -> count 1
  (thread 2) -> count 2
(thread 1) main -> join thread 2
  (thread 2) -> count 3
  (thread 2) -> count 4
  (thread 2) -> count 5
  (thread 2) -> count 6
  (thread 2) -> count 7
  (thread 2) -> count 8
  (thread 2) -> count 9
  (thread 2) -> count 10
(thread 1) main -> stop
```
