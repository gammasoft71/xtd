# date_time_add_milliseconds

Shows how to use [xtd::date_time::add_milliseconds](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#a0c0b9b22d495ed1096b74dd9c72df2e4) method.

## Sources

* [src/date_time_add_milliseconds.cpp](src/date_time_add_milliseconds.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Original date: 09/08/2010 04:00:00.0000000 (634195584000000000 ticks)

Second date:   09/08/2010 04:00:00.0010000 (634195584000009984 ticks)
Difference between dates: 00:00:00.0010000 (10000 ticks)

Third date:    09/08/2010 04:00:00.0015000 (634195584000014976 ticks)
Difference between dates: 00:00:00.0015000 (15000 ticks)
```
