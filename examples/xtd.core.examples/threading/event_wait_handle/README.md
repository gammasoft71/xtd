# event_wait_handle

Shows how to use [xtd::threading::event_wait_handle](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1event__wait__handle.html) class.

## Sources

[src/event_wait_handle.cpp](src/event_wait_handle.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Thread 2 blocks.
Thread 4 blocks.
Thread 0 blocks.
Thread 1 blocks.
Thread 3 blocks.
Press ENTER to release a waiting thread.

Thread 4 exits.
Press ENTER to release a waiting thread.

Thread 2 exits.
Press ENTER to release a waiting thread.

Thread 0 exits.
Press ENTER to release a waiting thread.

Thread 1 exits.
Press ENTER to release a waiting thread.

Thread 3 exits.

Thread 0 blocks.
Thread 1 blocks.
Thread 3 blocks.
Thread 2 blocks.
Thread 4 blocks.
Press ENTER to release the waiting threads.

Thread 2 exits.
Thread 1 exits.
Thread 4 exits.
Thread 3 exits.
Thread 0 exits.
```
