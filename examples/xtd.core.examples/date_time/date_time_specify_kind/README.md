# date_time_specify_kind

Shows how to use [xtd::date_time::specify_kind](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#adcb67f5e68f1830781c7d2b4e90f757c) method.

## Sources

[src/date_time_specify_kind.cpp](src/date_time_specify_kind.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
utc_now: ........... 2021-12-31 17:08:41, Kind = utc
now: ............... 2021-12-31 18:08:41, Kind = local

utc: ............... 2021-12-31 17:08:41, Kind = utc
  to_local_time:     2021-12-31 18:08:41, Kind = local
  to_universal_time: 2021-12-31 17:08:41, Kind = utc

local: ............. 2021-12-31 18:08:41, Kind = local
  to_local_time:     2021-12-31 18:08:41, Kind = local
  to_universal_time: 2021-12-31 17:08:41, Kind = utc

unspecified: ....... 2021-12-31 18:08:41, Kind = unspecified
  to_local_time:     2021-12-31 19:08:41, Kind = local
  to_universal_time: 2021-12-31 17:08:41, Kind = utc
```
