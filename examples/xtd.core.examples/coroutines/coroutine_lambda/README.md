# coroutine_lambda

Shows how to use coroutine with lambda expression and [task](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1tasks_1_1task_3_01void_01_4.html).

## Sources

* [src/coroutine_lambda.cpp](src/coroutine_lambda.cpp)
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
[main, thread 11] -> end
```
