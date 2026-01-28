# task

Shows how to use [xtd::threadin::tasks:task](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1tasks_1_1task_3_01void_01_4.html) class.

## Sources

* [src/task.cpp](src/task.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
counter = 1
counter = 2
counter = 3
counter = 4
counter = 5
This is a string result
[taskId (3)] Run this action in parallel!
[taskId (4)] Run this action in parallel!
[taskId (5)] Run this action in parallel!
[taskId (6)] Run this action in parallel!
[taskId (7)] Run this action in parallel!
[taskId (8)] Run this action in parallel!
```
