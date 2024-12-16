# format_enum

Show how to use format [xtd::format](https://gammasoft71.github.io/xtd/reference_guides/latest/_format_page.html) class with enums.

## Sources

[src/format_enum.cpp](src/format_enum.cpp)

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
│ monday               │ {}         │ monday                           │
│ monday               │ {:b}       │ 0                                │
│ monday               │ {:b4}      │ 0000                             │
│ monday               │ {:B}       │ 0                                │
│ monday               │ {:B4}      │ 0000                             │
│ monday               │ {:d}       │ 0                                │
│ monday               │ {:d1}      │ 0                                │
│ monday               │ {:D}       │ 0                                │
│ monday               │ {:D1}      │ 0                                │
│ monday               │ {:g}       │ monday                           │
│ monday               │ {:G}       │ monday                           │
│ monday               │ {:o}       │ 0                                │
│ monday               │ {:o2}      │ 00                               │
│ monday               │ {:O}       │ 0                                │
│ monday               │ {:O2}      │ 00                               │
│ monday               │ {:x}       │ 0                                │
│ monday               │ {:x2}      │ 00                               │
│ monday               │ {:X}       │ 0                                │
│ monday               │ {:X2}      │ 00                               │
├──────────────────────┼────────────┼──────────────────────────────────┤
│ thursday             │ {}         │ thursday                         │
│ thursday             │ {:b}       │ 11                               │
│ thursday             │ {:b4}      │ 0011                             │
│ thursday             │ {:B}       │ 11                               │
│ thursday             │ {:B4}      │ 0011                             │
│ thursday             │ {:d}       │ 3                                │
│ thursday             │ {:d1}      │ 3                                │
│ thursday             │ {:D}       │ 3                                │
│ thursday             │ {:D1}      │ 3                                │
│ thursday             │ {:g}       │ thursday                         │
│ thursday             │ {:G}       │ thursday                         │
│ thursday             │ {:o}       │ 3                                │
│ thursday             │ {:o2}      │ 03                               │
│ thursday             │ {:O}       │ 3                                │
│ thursday             │ {:O2}      │ 03                               │
│ thursday             │ {:x}       │ 3                                │
│ thursday             │ {:x2}      │ 03                               │
│ thursday             │ {:X}       │ 3                                │
│ thursday             │ {:X2}      │ 03                               │
├──────────────────────┼────────────┼──────────────────────────────────┤
│ sunday               │ {}         │ sunday                           │
│ sunday               │ {:b}       │ 110                              │
│ sunday               │ {:b4}      │ 0110                             │
│ sunday               │ {:B}       │ 110                              │
│ sunday               │ {:B4}      │ 0110                             │
│ sunday               │ {:d}       │ 6                                │
│ sunday               │ {:d1}      │ 6                                │
│ sunday               │ {:D}       │ 6                                │
│ sunday               │ {:D1}      │ 6                                │
│ sunday               │ {:g}       │ sunday                           │
│ sunday               │ {:G}       │ sunday                           │
│ sunday               │ {:o}       │ 6                                │
│ sunday               │ {:o2}      │ 06                               │
│ sunday               │ {:O}       │ 6                                │
│ sunday               │ {:O2}      │ 06                               │
│ sunday               │ {:x}       │ 6                                │
│ sunday               │ {:x2}      │ 06                               │
│ sunday               │ {:X}       │ 6                                │
│ sunday               │ {:X2}      │ 06                               │
└──────────────────────┴────────────┴──────────────────────────────────┘
```

