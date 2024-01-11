# monitor_pulse_all

Shows how to use [xtd::threading::monitor::pulse_all](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1monitor.html#a362df17ae1c2d6e99ae2d272805c2dcb) method.

## Sources

[src/monitor_pulse_all.cpp](src/monitor_pulse_all.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
    Thread 2 wait...
    Thread 3 wait...
    Thread 3 ...continue.
    Thread 2 ...continue.
```
