# thread

Shows how to use [xtd::threading::thread](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1thread.html) class.

## Sources

[src/thread.cpp](src/thread.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Main thread: Start a second thread.
Main thread: Do some work.
Main thread: Do some work.
thread_proc: 0
Main thread: Do some work.
thread_proc: 1
Main thread: Do some work.
thread_proc: 2
Main thread: Call Join(), to wait until thread_proc ends.
thread_proc: 3
thread_proc: 4
thread_proc: 5
thread_proc: 6
thread_proc: 7
thread_proc: 8
thread_proc: 9
Main thread: thread_proc.Join has returned.  Press Enter to end program.
```
