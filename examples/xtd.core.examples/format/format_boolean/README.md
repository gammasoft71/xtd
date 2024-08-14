# format_boolean

Show how to use format [xtd::format](https://gammasoft71.github.io/xtd/reference_guides/latest/_format_page.html) class with booleans.

## Sources

[src/format_boolean.cpp](src/format_boolean.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output (with colors)

```
┌───────────┬────────────┬──────────────────────────────────┐
│  boolean  │   format   │      representation              │
├───────────┼────────────┼──────────────────────────────────┤
│ true      │ {}         │ true                             |
│ true      │ {:b}       │ 1                                |
│ true      │ {:b4}      │ 0001                             |
│ true      │ {:b8}      │ 00000001                         |
│ true      │ {:B}       │ 1                                |
│ true      │ {:B4}      │ 0001                             |
│ true      │ {:B8}      │ 00000001                         |
│ true      │ {:d}       │ 1                                |
│ true      │ {:d2}      │ 01                               |
│ true      │ {:D}       │ 1                                |
│ true      │ {:D2}      │ 01                               |
│ true      │ {:g}       │ true                             |
│ true      │ {:G}       │ true                             |
│ true      │ {:o}       │ 1                                |
│ true      │ {:o3}      │ 001                              |
│ true      │ {:O}       │ 1                                |
│ true      │ {:O3}      │ 001                              |
│ true      │ {:x}       │ 1                                |
│ true      │ {:x5}      │ 00001                            |
│ true      │ {:X}       │ 1                                |
│ true      │ {:X5}      │ 00001                            |
├───────────┼────────────┼──────────────────────────────────┤
│ false     │ {}         │ false                            |
│ false     │ {:b}       │ 0                                |
│ false     │ {:b4}      │ 0000                             |
│ false     │ {:b8}      │ 00000000                         |
│ false     │ {:B}       │ 0                                |
│ false     │ {:B4}      │ 0000                             |
│ false     │ {:B8}      │ 00000000                         |
│ false     │ {:d}       │ 0                                |
│ false     │ {:d2}      │ 00                               |
│ false     │ {:D}       │ 0                                |
│ false     │ {:D2}      │ 00                               |
│ false     │ {:g}       │ false                            |
│ false     │ {:G}       │ false                            |
│ false     │ {:o}       │ 0                                |
│ false     │ {:o3}      │ 000                              |
│ false     │ {:O}       │ 0                                |
│ false     │ {:O3}      │ 000                              |
│ false     │ {:x}       │ 0                                |
│ false     │ {:x5}      │ 00000                            |
│ false     │ {:X}       │ 0                                |
│ false     │ {:X5}      │ 00000                            |
└───────────┴────────────┴──────────────────────────────────┘
```

