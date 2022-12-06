# date_time_add_milliseconds

Shows how to use [xtd::date_time::add_milliseconds](../../../../src/xtd.core/include/xtd/date_time.h) method.

# Sources

[src/date_time_add_milliseconds.cpp](src/date_time_add_milliseconds.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Original date: 09/08/2010/16:00:00.0000000 (634195584000000000 ticks)

Second date:   09/08/2010/16:00:00.0000000 (634195584000010000 ticks)
Difference between dates: Mon Jan  1 00:00:00 0001 (10000 ticks)

Third date:    09/08/2010/16:00:00.0005000 (634195584000015000 ticks)
Difference between dates: Mon Jan  1 00:00:00 0001 (15000 ticks)
```
