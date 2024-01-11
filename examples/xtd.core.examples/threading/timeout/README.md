# timeout

Shows how to use [xtd::threading::timeout](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1timeout.html) class.

## Sources

[src/timeout.cpp](src/timeout.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
new_thread is executing thread_method.
main thread calls interrupt on new_thread.
new_thread going to sleep.
new_thread cannot go to sleep - interrupted by main thread.
```
