# monitor_pulse

Shows how to use [xtd::threading::monitor::pulse](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1monitor.html#a02075512c6dc3fb73840910466cca815) pulse.

## Sources

[src/monitor_pulse.cpp](src/monitor_pulse.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
    Thread 2 wait...
    Thread 3 wait...
    Thread 3 ...continue.
    Thread 2 ...continue.
```
