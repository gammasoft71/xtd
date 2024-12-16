# format_enum_class

Show how to use format [xtd::format](https://gammasoft71.github.io/xtd/reference_guides/latest/_format_page.html) class with enum classes.

## Sources

[src/format_enum_class.cpp](src/format_enum_class.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output (with colors)

```
┌──────────────────────┬────────────┬──────────────────────────────────┐
│  week_day            │   format   │      representation              │
├──────────────────────┼────────────┼──────────────────────────────────┤
│ week_day::monday     │ {}         │ monday                           │
│ week_day::monday     │ {:b}       │ 0                                │
│ week_day::monday     │ {:b4}      │ 0000                             │
│ week_day::monday     │ {:B}       │ 0                                │
│ week_day::monday     │ {:B4}      │ 0000                             │
│ week_day::monday     │ {:d}       │ 0                                │
│ week_day::monday     │ {:d1}      │ 0                                │
│ week_day::monday     │ {:D}       │ 0                                │
│ week_day::monday     │ {:D1}      │ 0                                │
│ week_day::monday     │ {:g}       │ monday                           │
│ week_day::monday     │ {:G}       │ monday                           │
│ week_day::monday     │ {:o}       │ 0                                │
│ week_day::monday     │ {:o2}      │ 00                               │
│ week_day::monday     │ {:O}       │ 0                                │
│ week_day::monday     │ {:O2}      │ 00                               │
│ week_day::monday     │ {:x}       │ 0                                │
│ week_day::monday     │ {:x2}      │ 00                               │
│ week_day::monday     │ {:X}       │ 0                                │
│ week_day::monday     │ {:X2}      │ 00                               │
├──────────────────────┼────────────┼──────────────────────────────────┤
│ week_day::thursday   │ {}         │ thursday                         │
│ week_day::thursday   │ {:b}       │ 11                               │
│ week_day::thursday   │ {:b4}      │ 0011                             │
│ week_day::thursday   │ {:B}       │ 11                               │
│ week_day::thursday   │ {:B4}      │ 0011                             │
│ week_day::thursday   │ {:d}       │ 3                                │
│ week_day::thursday   │ {:d1}      │ 3                                │
│ week_day::thursday   │ {:D}       │ 3                                │
│ week_day::thursday   │ {:D1}      │ 3                                │
│ week_day::thursday   │ {:g}       │ thursday                         │
│ week_day::thursday   │ {:G}       │ thursday                         │
│ week_day::thursday   │ {:o}       │ 3                                │
│ week_day::thursday   │ {:o2}      │ 03                               │
│ week_day::thursday   │ {:O}       │ 3                                │
│ week_day::thursday   │ {:O2}      │ 03                               │
│ week_day::thursday   │ {:x}       │ 3                                │
│ week_day::thursday   │ {:x2}      │ 03                               │
│ week_day::thursday   │ {:X}       │ 3                                │
│ week_day::thursday   │ {:X2}      │ 03                               │
├──────────────────────┼────────────┼──────────────────────────────────┤
│ week_day::sunday     │ {}         │ sunday                           │
│ week_day::sunday     │ {:b}       │ 110                              │
│ week_day::sunday     │ {:b4}      │ 0110                             │
│ week_day::sunday     │ {:B}       │ 110                              │
│ week_day::sunday     │ {:B4}      │ 0110                             │
│ week_day::sunday     │ {:d}       │ 6                                │
│ week_day::sunday     │ {:d1}      │ 6                                │
│ week_day::sunday     │ {:D}       │ 6                                │
│ week_day::sunday     │ {:D1}      │ 6                                │
│ week_day::sunday     │ {:g}       │ sunday                           │
│ week_day::sunday     │ {:G}       │ sunday                           │
│ week_day::sunday     │ {:o}       │ 6                                │
│ week_day::sunday     │ {:o2}      │ 06                               │
│ week_day::sunday     │ {:O}       │ 6                                │
│ week_day::sunday     │ {:O2}      │ 06                               │
│ week_day::sunday     │ {:x}       │ 6                                │
│ week_day::sunday     │ {:x2}      │ 06                               │
│ week_day::sunday     │ {:X}       │ 6                                │
│ week_day::sunday     │ {:X2}      │ 06                               │
└──────────────────────┴────────────┴──────────────────────────────────┘
```

