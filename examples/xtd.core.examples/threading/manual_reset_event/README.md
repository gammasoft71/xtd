# manual_reset_event

Shows how to use [xtd::threading::manual_reset_event](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1manual_reset_event.html) class.

## Sources

[src/manual_reset_event.cpp](src/manual_reset_event.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 3 named threads that block on a ManualresetEvent:

Thread_0 starts and calls mre.WaitOne()
Thread_2 starts and calls mre.WaitOne()
Thread_1 starts and calls mre.WaitOne()

When all three threads have started, press Enter to call set()
to release all the threads.


Thread_2 ends.
Thread_0 ends.
Thread_1 ends.

When a ManualresetEvent is signaled, threads that call WaitOne()
do not block. Press Enter to show this.


Thread_3 starts and calls mre.WaitOne()
Thread_4 starts and calls mre.WaitOne()
Thread_3 ends.
Thread_4 ends.

Press Enter to call reset(), so that threads once again block
when they call WaitOne().


Thread_5 starts and calls mre.WaitOne()

Press Enter to call set() and conclude the demo.

Thread_5 ends.
```
