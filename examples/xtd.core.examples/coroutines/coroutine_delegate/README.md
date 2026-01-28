# coroutine_delegate

Shows how to use coroutine with [delegate](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1tasks_1_1task_3_01void_01_4.html) and [task](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1tasks_1_1task_3_01void_01_4.html).

## Sources

* [src/tasks.cpp](src/coroutine_delegate.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
[main], thread 1] -> start
message : Hello, World!
length  : 13
[main, thread 4] -> end
```
