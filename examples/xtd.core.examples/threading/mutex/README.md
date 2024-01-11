# mutex

Shows how to use [xtd::threading::mutex](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1mutex.html) class.

## Sources

[src/mutex.cpp](src/mutex.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
thread_1 is requesting the mutex
thread_1 has entered the protected area
thread_2 is requesting the mutex
thread_3 is requesting the mutex
thread_1 is leaving the protected area
thread_1 has released the mutex
thread_2 has entered the protected area
thread_2 is leaving the protected area
thread_2 has released the mutex
thread_3 has entered the protected area
thread_3 is leaving the protected area
thread_3 has released the mutex
```
