# countdown_event

Shows how to use [xtd::threading::countdown_event](https:gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1countdown__event.html) class.

## Sources

[src/countdown_event.cpp](src/countdown_event.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Thread 2 signals countdown_event
Thread 3 signals countdown_event
Thread 4 signals countdown_event
Thread 6 signals countdown_event
Thread 5 signals countdown_event
All threads have signaled countdown_event
```
