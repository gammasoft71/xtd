# stopwatch

Shows how to use [xtd::diagnostics::stopwatch](../../../../src/xtd.core/include/xtd/diagnostics/stopwatch.h) class.

## Sources

[src/stopwatch.cpp](src/stopwatch.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Operations timed using the system's high-resolution performance counter.
  Timer frequency in ticks per second = 1000000000
  Timer is accurate within 1 nanoseconds

Press the Enter key to begin:


Operation: parse<int>("0") Summary:
  Slowest time:  #7232/10000 = 505 ticks
  Fastest time:  #1278/10000 = 20 ticks
  Average time:  26 ticks = 26 nanoseconds
  Total time looping through 10000 operations: 28 milliseconds

Operation: try_parse<int>("0") Summary:
  Slowest time:  #2910/10000 = 312 ticks
  Fastest time:  #5105/10000 = 19 ticks
  Average time:  20 ticks = 20 nanoseconds
  Total time looping through 10000 operations: 22 milliseconds

Operation: parse<int>("a") Summary:
  Slowest time:  #7001/10000 = 19279 ticks
  Fastest time:  #3392/10000 = 4881 ticks
  Average time:  5878 ticks = 5878 nanoseconds
  Total time looping through 10000 operations: 5882 milliseconds

Operation: try_parse<int>("a") Summary:
  Slowest time:  #3157/10000 = 14341 ticks
  Fastest time:  #20/10000 = 5809 ticks
  Average time:  6532 ticks = 6532 nanoseconds
  Total time looping through 10000 operations: 6536 milliseconds
```
