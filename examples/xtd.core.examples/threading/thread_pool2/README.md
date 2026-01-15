# thread_pool2

Shows how to use [xtd::threading::thread_pool](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1thread__pool.html) class.

## Sources

* [src/thread_pool2.cpp](src/thread_pool2.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
(Thread Main 1) -> start
(Thread Main 1) -> sleep(200)
  (Thread Pool 5) -> count 1
  (Thread Pool 5) -> count 2
(Thread Main 1) -> join all threads of thread_pool
  (Thread Pool 5) -> count 3
  (Thread Pool 5) -> count 4
  (Thread Pool 5) -> count 5
  (Thread Pool 5) -> count 6
  (Thread Pool 5) -> count 7
  (Thread Pool 5) -> count 8
  (Thread Pool 5) -> count 9
  (Thread Pool 5) -> count 10
(Thread Main 1) -> stop
```
