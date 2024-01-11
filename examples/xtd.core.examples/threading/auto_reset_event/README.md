# auto_reset_event

Shows how to use [xtd::threading::auto_reset_event](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1auto_reset_event.html) class.

## Sources

[src/auto_reset_event.cpp](src/auto_reset_event.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Press Enter to create three threads and start them.
The threads wait on auto_reset_event #1, which was created
in the signaled state, so the first thread is released.
This puts auto_reset_event #1 into the unsignaled state.

Thread_1 waits on auto_reset_event #1.
Thread_1 is released from auto_reset_event #1.
Thread_1 waits on auto_reset_event #2.
Thread_2 waits on auto_reset_event #1.
Thread_3 waits on auto_reset_event #1.
Press Enter to release another thread.

Thread_3 is released from auto_reset_event #1.
Thread_3 waits on auto_reset_event #2.
Press Enter to release another thread.

Thread_2 is released from auto_reset_event #1.
Thread_2 waits on auto_reset_event #2.

All threads are now waiting on auto_reset_event #2.
Press Enter to release a thread.

Thread_1 is released from auto_reset_event #2.
Thread_1 ends.
Press Enter to release a thread.

Thread_3 is released from auto_reset_event #2.
Thread_3 ends.
Press Enter to release a thread.

Thread_2 is released from auto_reset_event #2.
Thread_2 ends.
```
