# semaphore

Shows how to use [xtd::threading::semaphore](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1semaphore.html) class.

## Sources

[src/semaphore.cpp](src/semaphore.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
thread 2 begins and waits for the semaphore.
thread 5 begins and waits for the semaphore.
thread 4 begins and waits for the semaphore.
thread 1 begins and waits for the semaphore.
thread 3 begins and waits for the semaphore.
Main thread calls Release(3).
thread 5 enters the semaphore.
thread 2 enters the semaphore.
thread 1 enters the semaphore.
thread 5 releases the semaphore.
thread 5 previous semaphore count: 0
thread 4 enters the semaphore.
thread 2 releases the semaphore.
thread 2 previous semaphore count: 0
thread 3 enters the semaphore.
thread 1 releases the semaphore.
thread 1 previous semaphore count: 0
thread 4 releases the semaphore.
thread 4 previous semaphore count: 1
thread 3 releases the semaphore.
thread 3 previous semaphore count: 2
Main thread exits.
```
