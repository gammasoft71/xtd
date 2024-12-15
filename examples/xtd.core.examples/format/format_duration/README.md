# format_duration

Show how to use format [xtd::format](https://gammasoft71.github.io/xtd/reference_guides/latest/_format_page.html) class with [std::chrono](https://en.cppreference.com/w/cpp/chrono) duration.

## Sources

[src/format_duration.cpp](src/format_duration.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output (with colors)

```
┌────────────────────────────────────────────────────┬────────────┬────────────────────────────┐
│  time_span                                         │   format   │      representation        │
├────────────────────────────────────────────────────┼────────────┼────────────────────────────┤
│ std::chrono::nanoseconds {}                        │ {}         │ 00:00:00                   |
│ std::chrono::nanoseconds {}                        │ {:c}       │ 00:00:00                   |
│ std::chrono::nanoseconds {}                        │ {:d}       │ 0                          |
│ std::chrono::nanoseconds {}                        │ {:D}       │ 00                         |
│ std::chrono::nanoseconds {}                        │ {:f}       │ 0.0:00:00:000000000        |
│ std::chrono::nanoseconds {}                        │ {:F}       │ 0.00:00:00:000000000       |
│ std::chrono::nanoseconds {}                        │ {:g}       │ 0:00:00                    |
│ std::chrono::nanoseconds {}                        │ {:G}       │ 00:00:00                   |
│ std::chrono::nanoseconds {}                        │ {:h}       │ 0                          |
│ std::chrono::nanoseconds {}                        │ {:H}       │ 00                         |
│ std::chrono::nanoseconds {}                        │ {:m}       │ 0                          |
│ std::chrono::nanoseconds {}                        │ {:M}       │ 00                         |
│ std::chrono::nanoseconds {}                        │ {:n}       │ 0                          |
│ std::chrono::nanoseconds {}                        │ {:N}       │ 000000000                  |
│ std::chrono::nanoseconds {}                        │ {:s}       │ 0                          |
│ std::chrono::nanoseconds {}                        │ {:S}       │ 00                         |
│ std::chrono::nanoseconds {}                        │ {:t}       │ 0                          |
│ std::chrono::nanoseconds {}                        │ {:T}       │ 0000000                    |
├────────────────────────────────────────────────────┼────────────┼────────────────────────────┤
│ 6h + 3min + 8s                                     │ {}         │ 06:03:08                   |
│ 6h + 3min + 8s                                     │ {:c}       │ 06:03:08                   |
│ 6h + 3min + 8s                                     │ {:d}       │ 0                          |
│ 6h + 3min + 8s                                     │ {:D}       │ 00                         |
│ 6h + 3min + 8s                                     │ {:f}       │ 0.6:03:08:000000000        |
│ 6h + 3min + 8s                                     │ {:F}       │ 0.06:03:08:000000000       |
│ 6h + 3min + 8s                                     │ {:g}       │ 6:03:08                    |
│ 6h + 3min + 8s                                     │ {:G}       │ 06:03:08                   |
│ 6h + 3min + 8s                                     │ {:h}       │ 6                          |
│ 6h + 3min + 8s                                     │ {:H}       │ 06                         |
│ 6h + 3min + 8s                                     │ {:m}       │ 3                          |
│ 6h + 3min + 8s                                     │ {:M}       │ 03                         |
│ 6h + 3min + 8s                                     │ {:n}       │ 0                          |
│ 6h + 3min + 8s                                     │ {:N}       │ 000000000                  |
│ 6h + 3min + 8s                                     │ {:s}       │ 8                          |
│ 6h + 3min + 8s                                     │ {:S}       │ 08                         |
│ 6h + 3min + 8s                                     │ {:t}       │ 0                          |
│ 6h + 3min + 8s                                     │ {:T}       │ 0000000                    |
├────────────────────────────────────────────────────┼────────────┼────────────────────────────┤
│ 52h + 3min + 32s                                   │ {}         │ 2.04:03:02                 |
│ 52h + 3min + 32s                                   │ {:c}       │ 2.04:03:02                 |
│ 52h + 3min + 32s                                   │ {:d}       │ 2                          |
│ 52h + 3min + 32s                                   │ {:D}       │ 02                         |
│ 52h + 3min + 32s                                   │ {:f}       │ 2.4:03:02:000000000        |
│ 52h + 3min + 32s                                   │ {:F}       │ 2.04:03:02:000000000       |
│ 52h + 3min + 32s                                   │ {:g}       │ 2.4:03:02                  |
│ 52h + 3min + 32s                                   │ {:G}       │ 2.04:03:02                 |
│ 52h + 3min + 32s                                   │ {:h}       │ 4                          |
│ 52h + 3min + 32s                                   │ {:H}       │ 04                         |
│ 52h + 3min + 32s                                   │ {:m}       │ 3                          |
│ 52h + 3min + 32s                                   │ {:M}       │ 03                         |
│ 52h + 3min + 32s                                   │ {:n}       │ 0                          |
│ 52h + 3min + 32s                                   │ {:N}       │ 000000000                  |
│ 52h + 3min + 32s                                   │ {:s}       │ 2                          |
│ 52h + 3min + 32s                                   │ {:S}       │ 02                         |
│ 52h + 3min + 32s                                   │ {:t}       │ 0                          |
│ 52h + 3min + 32s                                   │ {:T}       │ 0000000                    |
├────────────────────────────────────────────────────┼────────────┼────────────────────────────┤
│ 24ms + 543ns                                       │ {}         │ 00:00:00:024000543         |
│ 24ms + 543ns                                       │ {:c}       │ 00:00:00:024000543         |
│ 24ms + 543ns                                       │ {:d}       │ 0                          |
│ 24ms + 543ns                                       │ {:D}       │ 00                         |
│ 24ms + 543ns                                       │ {:f}       │ 0.0:00:00:024000543        |
│ 24ms + 543ns                                       │ {:F}       │ 0.00:00:00:024000543       |
│ 24ms + 543ns                                       │ {:g}       │ 0:00:00:024000543          |
│ 24ms + 543ns                                       │ {:G}       │ 00:00:00:024000543         |
│ 24ms + 543ns                                       │ {:h}       │ 0                          |
│ 24ms + 543ns                                       │ {:H}       │ 00                         |
│ 24ms + 543ns                                       │ {:m}       │ 0                          |
│ 24ms + 543ns                                       │ {:M}       │ 00                         |
│ 24ms + 543ns                                       │ {:n}       │ 24000543                   |
│ 24ms + 543ns                                       │ {:N}       │ 024000543                  |
│ 24ms + 543ns                                       │ {:s}       │ 0                          |
│ 24ms + 543ns                                       │ {:S}       │ 00                         |
│ 24ms + 543ns                                       │ {:t}       │ 240005                     |
│ 24ms + 543ns                                       │ {:T}       │ 0240005                    |
├────────────────────────────────────────────────────┼────────────┼────────────────────────────┤
│ 52h + 3min + 2s + 24ms + 543ns                     │ {}         │ 2.04:03:02:024000543       |
│ 52h + 3min + 2s + 24ms + 543ns                     │ {:c}       │ 2.04:03:02:024000543       |
│ 52h + 3min + 2s + 24ms + 543ns                     │ {:d}       │ 2                          |
│ 52h + 3min + 2s + 24ms + 543ns                     │ {:D}       │ 02                         |
│ 52h + 3min + 2s + 24ms + 543ns                     │ {:f}       │ 2.4:03:02:024000543        |
│ 52h + 3min + 2s + 24ms + 543ns                     │ {:F}       │ 2.04:03:02:024000543       |
│ 52h + 3min + 2s + 24ms + 543ns                     │ {:g}       │ 2.4:03:02:024000543        |
│ 52h + 3min + 2s + 24ms + 543ns                     │ {:G}       │ 2.04:03:02:024000543       |
│ 52h + 3min + 2s + 24ms + 543ns                     │ {:h}       │ 4                          |
│ 52h + 3min + 2s + 24ms + 543ns                     │ {:H}       │ 04                         |
│ 52h + 3min + 2s + 24ms + 543ns                     │ {:m}       │ 3                          |
│ 52h + 3min + 2s + 24ms + 543ns                     │ {:M}       │ 03                         |
│ 52h + 3min + 2s + 24ms + 543ns                     │ {:n}       │ 24000543                   |
│ 52h + 3min + 2s + 24ms + 543ns                     │ {:N}       │ 024000543                  |
│ 52h + 3min + 2s + 24ms + 543ns                     │ {:s}       │ 2                          |
│ 52h + 3min + 2s + 24ms + 543ns                     │ {:S}       │ 02                         |
│ 52h + 3min + 2s + 24ms + 543ns                     │ {:t}       │ 240005                     |
│ 52h + 3min + 2s + 24ms + 543ns                     │ {:T}       │ 0240005                    |
├────────────────────────────────────────────────────┼────────────┼────────────────────────────┤
│ std::chrono::nanoseconds {int64_object::min_value} │ {}         │ -106751.23:47:16:854775808 |
│ std::chrono::nanoseconds {int64_object::min_value} │ {:c}       │ -106751.23:47:16:854775808 |
│ std::chrono::nanoseconds {int64_object::min_value} │ {:d}       │ 106751                     |
│ std::chrono::nanoseconds {int64_object::min_value} │ {:D}       │ 106751                     |
│ std::chrono::nanoseconds {int64_object::min_value} │ {:f}       │ -106751.23:47:16:854775808 |
│ std::chrono::nanoseconds {int64_object::min_value} │ {:F}       │ -106751.23:47:16:854775808 |
│ std::chrono::nanoseconds {int64_object::min_value} │ {:g}       │ -106751.23:47:16:854775808 |
│ std::chrono::nanoseconds {int64_object::min_value} │ {:G}       │ -106751.23:47:16:854775808 |
│ std::chrono::nanoseconds {int64_object::min_value} │ {:h}       │ 23                         |
│ std::chrono::nanoseconds {int64_object::min_value} │ {:H}       │ 23                         |
│ std::chrono::nanoseconds {int64_object::min_value} │ {:m}       │ 47                         |
│ std::chrono::nanoseconds {int64_object::min_value} │ {:M}       │ 47                         |
│ std::chrono::nanoseconds {int64_object::min_value} │ {:n}       │ 854775808                  |
│ std::chrono::nanoseconds {int64_object::min_value} │ {:N}       │ 854775808                  |
│ std::chrono::nanoseconds {int64_object::min_value} │ {:s}       │ 16                         |
│ std::chrono::nanoseconds {int64_object::min_value} │ {:S}       │ 16                         |
│ std::chrono::nanoseconds {int64_object::min_value} │ {:t}       │ 8547758                    |
│ std::chrono::nanoseconds {int64_object::min_value} │ {:T}       │ 8547758                    |
├────────────────────────────────────────────────────┼────────────┼────────────────────────────┤
│ std::chrono::nanoseconds {int64_object::max_value} │ {}         │ 106751.23:47:16:854775807  |
│ std::chrono::nanoseconds {int64_object::max_value} │ {:c}       │ 106751.23:47:16:854775807  |
│ std::chrono::nanoseconds {int64_object::max_value} │ {:d}       │ 106751                     |
│ std::chrono::nanoseconds {int64_object::max_value} │ {:D}       │ 106751                     |
│ std::chrono::nanoseconds {int64_object::max_value} │ {:f}       │ 106751.23:47:16:854775807  |
│ std::chrono::nanoseconds {int64_object::max_value} │ {:F}       │ 106751.23:47:16:854775807  |
│ std::chrono::nanoseconds {int64_object::max_value} │ {:g}       │ 106751.23:47:16:854775807  |
│ std::chrono::nanoseconds {int64_object::max_value} │ {:G}       │ 106751.23:47:16:854775807  |
│ std::chrono::nanoseconds {int64_object::max_value} │ {:h}       │ 23                         |
│ std::chrono::nanoseconds {int64_object::max_value} │ {:H}       │ 23                         |
│ std::chrono::nanoseconds {int64_object::max_value} │ {:m}       │ 47                         |
│ std::chrono::nanoseconds {int64_object::max_value} │ {:M}       │ 47                         |
│ std::chrono::nanoseconds {int64_object::max_value} │ {:n}       │ 854775807                  |
│ std::chrono::nanoseconds {int64_object::max_value} │ {:N}       │ 854775807                  |
│ std::chrono::nanoseconds {int64_object::max_value} │ {:s}       │ 16                         |
│ std::chrono::nanoseconds {int64_object::max_value} │ {:S}       │ 16                         |
│ std::chrono::nanoseconds {int64_object::max_value} │ {:t}       │ 8547758                    |
│ std::chrono::nanoseconds {int64_object::max_value} │ {:T}       │ 8547758                    |
└────────────────────────────────────────────────────┴────────────┴────────────────────────────┘
```

