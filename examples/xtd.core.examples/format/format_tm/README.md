# format_tm

Show how to use format [xtd::format](https://gammasoft71.github.io/xtd/reference_guides/latest/_format_page.html) class with [std::tm](https://en.cppreference.com/w/cpp/chrono/c/tm) struct.

## Sources

[src/format_tm.cpp](src/format_tm.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output (with colors)

```
┌──────────────────────────────────┬────────────┬──────────────────────────────────────────┐
│  date_time                       │   format   │      representation                      │
├──────────────────────────────────┼────────────┼──────────────────────────────────────────┤
│ 0                                │ {}         │ Sun Jan  0 00:00:00 1900                 │
│ 0                                │ {:a}       │ AM                                       │
│ 0                                │ {:b}       │ 000                                      │
│ 0                                │ {:B}       │ 0                                        │
│ 0                                │ {:d}       │ 01/00/1900                               │
│ 0                                │ {:D}       │ 1/00/1900                                │
│ 0                                │ {:f}       │ Sun Jan  0 00:00:00 1900                 │
│ 0                                │ {:F}       │ Sun Jan  0 00:00:00 1900                 │
│ 0                                │ {:g}       │ Sun Jan  0 00:00:00 1900                 │
│ 0                                │ {:G}       │ Sun Jan  0 00:00:00 1900                 │
│ 0                                │ {:h}       │ Sun                                      │
│ 0                                │ {:H}       │ Sunday                                   │
│ 0                                │ {:i}       │ 00                                       │
│ 0                                │ {:I}       │ 0                                        │
│ 0                                │ {:j}       │ Jan                                      │
│ 0                                │ {:J}       │ January                                  │
│ 0                                │ {:k}       │ 01                                       │
│ 0                                │ {:K}       │ 1                                        │
│ 0                                │ {:l}       │ 00                                       │
│ 0                                │ {:L}       │ 1900                                     │
│ 0                                │ {:m}       │ January 0                                │
│ 0                                │ {:M}       │ January 0                                │
│ 0                                │ {:n}       │ Sunday, 0 January 1900                   │
│ 0                                │ {:n}       │ Sunday, 0 January 1900 0:00:00           │
│ 0                                │ {:o}       │ 0 January 1900                           │
│ 0                                │ {:O}       │ 0 January 1900                           │
│ 0                                │ {:s}       │ 1900-01-00T00:00:00.0000000              │
│ 0                                │ {:t}       │ 00:00:00                                 │
│ 0                                │ {:T}       │ 0:00:00                                  │
│ 0                                │ {:u}       │ 1900-01-00 00:00:00                      │
│ 0                                │ {:U}       │ Sunday, 0 January 1900 0:00:00           │
│ 0                                │ {:v}       │ 00:00                                    │
│ 0                                │ {:V}       │ 0:00                                     │
│ 0                                │ {:w}       │ 00}                                      │
│ 0                                │ {:W}       │ 0                                        │
│ 0                                │ {:x}       │ 00                                       │
│ 0                                │ {:X}       │ 0                                        │
│ 0                                │ {:y}       │ January 0                                │
│ 0                                │ {:Y}       │ January 1900                             │
│ 0                                │ {:z}       │ CET                                      │
│ 0                                │ {:Z}       │ CET                                      │
├──────────────────────────────────┼────────────┼──────────────────────────────────────────┤
│ make_time(1971, 1, 5)            │ {}         │ Tue Jan  5 00:00:00 1971                 │
│ make_time(1971, 1, 5)            │ {:a}       │ AM                                       │
│ make_time(1971, 1, 5)            │ {:b}       │ 000                                      │
│ make_time(1971, 1, 5)            │ {:B}       │ 0                                        │
│ make_time(1971, 1, 5)            │ {:d}       │ 01/05/1971                               │
│ make_time(1971, 1, 5)            │ {:D}       │ 1/05/1971                                │
│ make_time(1971, 1, 5)            │ {:f}       │ Tue Jan  5 00:00:00 1971                 │
│ make_time(1971, 1, 5)            │ {:F}       │ Tue Jan  5 00:00:00 1971                 │
│ make_time(1971, 1, 5)            │ {:g}       │ Tue Jan  5 00:00:00 1971                 │
│ make_time(1971, 1, 5)            │ {:G}       │ Tue Jan  5 00:00:00 1971                 │
│ make_time(1971, 1, 5)            │ {:h}       │ Tue                                      │
│ make_time(1971, 1, 5)            │ {:H}       │ Tuesday                                  │
│ make_time(1971, 1, 5)            │ {:i}       │ 05                                       │
│ make_time(1971, 1, 5)            │ {:I}       │ 5                                        │
│ make_time(1971, 1, 5)            │ {:j}       │ Jan                                      │
│ make_time(1971, 1, 5)            │ {:J}       │ January                                  │
│ make_time(1971, 1, 5)            │ {:k}       │ 01                                       │
│ make_time(1971, 1, 5)            │ {:K}       │ 1                                        │
│ make_time(1971, 1, 5)            │ {:l}       │ 71                                       │
│ make_time(1971, 1, 5)            │ {:L}       │ 1971                                     │
│ make_time(1971, 1, 5)            │ {:m}       │ January 5                                │
│ make_time(1971, 1, 5)            │ {:M}       │ January 5                                │
│ make_time(1971, 1, 5)            │ {:n}       │ Tuesday, 5 January 1971                  │
│ make_time(1971, 1, 5)            │ {:n}       │ Tuesday, 5 January 1971 0:00:00          │
│ make_time(1971, 1, 5)            │ {:o}       │ 5 January 1971                           │
│ make_time(1971, 1, 5)            │ {:O}       │ 5 January 1971                           │
│ make_time(1971, 1, 5)            │ {:s}       │ 1971-01-05T00:00:00.0000000              │
│ make_time(1971, 1, 5)            │ {:t}       │ 00:00:00                                 │
│ make_time(1971, 1, 5)            │ {:T}       │ 0:00:00                                  │
│ make_time(1971, 1, 5)            │ {:u}       │ 1971-01-05 00:00:00                      │
│ make_time(1971, 1, 5)            │ {:U}       │ Tuesday, 5 January 1971 0:00:00          │
│ make_time(1971, 1, 5)            │ {:v}       │ 00:00                                    │
│ make_time(1971, 1, 5)            │ {:V}       │ 0:00                                     │
│ make_time(1971, 1, 5)            │ {:w}       │ 00}                                      │
│ make_time(1971, 1, 5)            │ {:W}       │ 0                                        │
│ make_time(1971, 1, 5)            │ {:x}       │ 00                                       │
│ make_time(1971, 1, 5)            │ {:X}       │ 0                                        │
│ make_time(1971, 1, 5)            │ {:y}       │ January 71                               │
│ make_time(1971, 1, 5)            │ {:Y}       │ January 1971                             │
│ make_time(1971, 1, 5)            │ {:z}       │ CET                                      │
│ make_time(1971, 1, 5)            │ {:Z}       │ CET                                      │
├──────────────────────────────────┼────────────┼──────────────────────────────────────────┤
│ make_time(1971, 1, 5, 21, 30, 3) │ {}         │ Tue Jan  5 21:30:03 1971                 │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:a}       │ PM                                       │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:b}       │ 000                                      │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:B}       │ 0                                        │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:d}       │ 01/05/1971                               │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:D}       │ 1/05/1971                                │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:f}       │ Tue Jan  5 21:30:03 1971                 │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:F}       │ Tue Jan  5 21:30:03 1971                 │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:g}       │ Tue Jan  5 21:30:03 1971                 │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:G}       │ Tue Jan  5 21:30:03 1971                 │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:h}       │ Tue                                      │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:H}       │ Tuesday                                  │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:i}       │ 05                                       │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:I}       │ 5                                        │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:j}       │ Jan                                      │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:J}       │ January                                  │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:k}       │ 01                                       │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:K}       │ 1                                        │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:l}       │ 71                                       │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:L}       │ 1971                                     │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:m}       │ January 5                                │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:M}       │ January 5                                │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:n}       │ Tuesday, 5 January 1971                  │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:n}       │ Tuesday, 5 January 1971 21:30:03         │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:o}       │ 5 January 1971                           │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:O}       │ 5 January 1971                           │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:s}       │ 1971-01-05T21:30:03.0000000              │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:t}       │ 21:30:03                                 │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:T}       │ 21:30:03                                 │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:u}       │ 1971-01-05 21:30:03                      │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:U}       │ Tuesday, 5 January 1971 21:30:03         │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:v}       │ 21:30                                    │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:V}       │ 21:30                                    │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:w}       │ 21}                                      │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:W}       │ 21                                       │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:x}       │ 09                                       │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:X}       │ 9                                        │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:y}       │ January 71                               │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:Y}       │ January 1971                             │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:z}       │ CET                                      │
│ make_time(1971, 1, 5, 21, 30, 3) │ {:Z}       │ CET                                      │
├──────────────────────────────────┼────────────┼──────────────────────────────────────────┤
│ now                              │ {}         │ Sun Dec 15 13:41:38 2024                 │
│ now                              │ {:a}       │ PM                                       │
│ now                              │ {:b}       │ 163                                      │
│ now                              │ {:B}       │ 163                                      │
│ now                              │ {:d}       │ 12/15/2024                               │
│ now                              │ {:D}       │ 12/15/2024                               │
│ now                              │ {:f}       │ Sun Dec 15 13:41:38 2024                 │
│ now                              │ {:F}       │ Sun Dec 15 13:41:38 2024                 │
│ now                              │ {:g}       │ Sun Dec 15 13:41:38 2024                 │
│ now                              │ {:G}       │ Sun Dec 15 13:41:38 2024                 │
│ now                              │ {:h}       │ Sun                                      │
│ now                              │ {:H}       │ Sunday                                   │
│ now                              │ {:i}       │ 15                                       │
│ now                              │ {:I}       │ 15                                       │
│ now                              │ {:j}       │ Dec                                      │
│ now                              │ {:J}       │ December                                 │
│ now                              │ {:k}       │ 12                                       │
│ now                              │ {:K}       │ 12                                       │
│ now                              │ {:l}       │ 24                                       │
│ now                              │ {:L}       │ 2024                                     │
│ now                              │ {:m}       │ December 15                              │
│ now                              │ {:M}       │ December 15                              │
│ now                              │ {:n}       │ Sunday, 15 December 2024                 │
│ now                              │ {:n}       │ Sunday, 15 December 2024 13:41:38        │
│ now                              │ {:o}       │ 15 December 2024                         │
│ now                              │ {:O}       │ 15 December 2024                         │
│ now                              │ {:s}       │ 2024-12-15T13:41:38.163216000            │
│ now                              │ {:t}       │ 13:41:38                                 │
│ now                              │ {:T}       │ 13:41:38                                 │
│ now                              │ {:u}       │ 2024-12-15 13:41:38                      │
│ now                              │ {:U}       │ Sunday, 15 December 2024 13:41:38        │
│ now                              │ {:v}       │ 13:41                                    │
│ now                              │ {:V}       │ 13:41                                    │
│ now                              │ {:w}       │ 13}                                      │
│ now                              │ {:W}       │ 13                                       │
│ now                              │ {:x}       │ 01                                       │
│ now                              │ {:X}       │ 1                                        │
│ now                              │ {:y}       │ December 24                              │
│ now                              │ {:Y}       │ December 2024                            │
│ now                              │ {:z}       │ CET                                      │
│ now                              │ {:Z}       │ CET                                      │
└──────────────────────────────────┴────────────┴──────────────────────────────────────────┘
```

