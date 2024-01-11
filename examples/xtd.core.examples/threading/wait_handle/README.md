# wait_handle

Shows how to use [xtd::threading::wait_handle](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1wait_handle.html) class.

## Sources

[src/wait_handle.cpp](src/wait_handle.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
MMain thread is waiting for BOTH tasks to complete.
Performing a task for 4000 milliseconds.
Performing a task for 9000 milliseconds.
Both tasks are completed (time waited=00:00:09:011011000)

The main thread is waiting for either task to complete.
Performing a task for 7000 milliseconds.
Performing a task for 4000 milliseconds.
Task 2 finished first (time waited=00:00:04:011925000).
```
