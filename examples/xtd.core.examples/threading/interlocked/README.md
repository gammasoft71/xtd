# interlocked

Shows how to use [xtd::threading::interlocked](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1interlocked.html) class.

## Sources

[src/interlocked.cpp](src/interlocked.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Thread1 acquired the lock
Thread1 exiting lock
Thread2 acquired the lock
   Thread3 was denied the lock
Thread2 exiting lock
Thread1 acquired the lock
   Thread4 was denied the lock
   Thread5 was denied the lock
Thread1 exiting lock
Thread6 acquired the lock
   Thread3 was denied the lock
   Thread2 was denied the lock
   Thread7 was denied the lock
Thread6 exiting lock
Thread4 acquired the lock
   Thread5 was denied the lock
   Thread1 was denied the lock
Thread4 exiting lock
Thread8 acquired the lock
   Thread3 was denied the lock
   Thread2 was denied the lock
   Thread7 was denied the lock
   Thread6 was denied the lock
   Thread9 was denied the lock
Thread8 exiting lock
Thread5 acquired the lock
   Thread1 was denied the lock
   Thread4 was denied the lock
   Thread3 was denied the lock
   Thread10 was denied the lock
   Thread2 was denied the lock
   Thread7 was denied the lock
Thread5 exiting lock
Thread6 acquired the lock
   Thread9 was denied the lock
   Thread8 was denied the lock
   Thread1 was denied the lock
Thread6 exiting lock
Thread4 acquired the lock
   Thread3 was denied the lock
   Thread10 was denied the lock
   Thread2 was denied the lock
   Thread7 was denied the lock
   Thread5 was denied the lock
Thread4 exiting lock
Thread9 acquired the lock
   Thread8 was denied the lock
   Thread6 was denied the lock
Thread9 exiting lock
Thread10 acquired the lock
   Thread7 was denied the lock
   Thread5 was denied the lock
   Thread4 was denied the lock
   Thread8 was denied the lock
Thread10 exiting lock
Thread6 acquired the lock
   Thread9 was denied the lock
Thread6 exiting lock
Thread8 acquired the lock
   Thread10 was denied the lock
   Thread9 was denied the lock
Thread8 exiting lock
Thread10 acquired the lock
Thread10 exiting lock
```
