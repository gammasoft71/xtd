# date_time_specify_kind

Shows how to use [xtd::date_time::specify_kind](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#adcb67f5e68f1830781c7d2b4e90f757c) method.

## Sources

* [src/date_time_specify_kind.cpp](src/date_time_specify_kind.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
utc_now: ........... 10/24/2025 08:59:24 PM, kind = utc
now: ............... 10/24/2025 10:59:24 PM, kind = local

utc: ............... 10/24/2025 8:59:24 PM, kind = utc
  to_local_time:     10/24/2025 10:59:24 PM, kind = local
  to_universal_time: 10/24/2025 08:59:24 PM, kind = utc

local: ............. 10/24/2025 10:59:24 PM, kind = local
  to_local_time:     10/24/2025 10:59:24 PM, kind = local
  to_universal_time: 10/24/2025 08:59:24 PM, kind = utc

unspecified: ....... 10/24/2025 10:59:24 PM, kind = unspecified
  to_local_time:     10/25/2025 00:59:24 AM, kind = local
  to_universal_time: 10/24/2025 08:59:24 PM, kind = utc
```
