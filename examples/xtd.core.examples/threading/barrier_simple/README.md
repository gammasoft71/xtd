# barrier_simple

Shows how to use [xtd::threading::barrier](https:gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1barrier.html) class.

## Sources

[src/barrier_simple.cpp](src/thread_pool.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Thread 9 is performing its work
Thread 11 is performing its work
Thread 8 is performing its work
Thread 11 compelted the phase
Thread 8 compelted the phase
Thread 9 compelted the phase
```
