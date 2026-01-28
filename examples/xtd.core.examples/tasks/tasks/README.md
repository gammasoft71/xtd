# tasks

Shows how to use [xtd::threading::tasks:task](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1tasks_1_1task_3_01void_01_4.html) class.

## Sources

* [src/tasks.cpp](src/tasks.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
main 0, thread 1 -> start
  task 2, thread 5 -> running
  task 3, thread 2 -> running
  task 4, thread 3 -> running
  task 5, thread 1 -> running
  parallel (6) running
  parallel (7) running
  parallel (8) running
  parallel (9) running
  parallel (10) running
  parallel (12) running
  parallel (13) running
  parallel (14) running
  parallel (11) running
  parallel (15) running
main 0, thread 1 -> task5.result = task<string> 16, thread 7 -> running
main 0, thread 1 -> result co_await = task<string> 17, thread 7 -> running
main 0, thread 7 -> end
```
