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
│ true      │ {}         │ true                             │
│ true      │ {:b}       │ 1                                │
│ true      │ {:b4}      │ 0001                             │
│ true      │ {:b8}      │ 00000001                         │
│ true      │ {:B}       │ 1                                │
│ true      │ {:B4}      │ 0001                             │
│ true      │ {:B8}      │ 00000001                         │
│ true      │ {:d}       │ 1                                │
│ true      │ {:d2}      │ 01                               │
│ true      │ {:D}       │ 1                                │
│ true      │ {:D2}      │ 01                               │
│ true      │ {:g}       │ true                             │
│ true      │ {:G}       │ true                             │
│ true      │ {:o}       │ 1                                │
│ true      │ {:o3}      │ 001                              │
│ true      │ {:O}       │ 1                                │
│ true      │ {:O3}      │ 001                              │
│ true      │ {:x}       │ 1                                │
│ true      │ {:x5}      │ 00001                            │
│ true      │ {:X}       │ 1                                │
│ true      │ {:X5}      │ 00001                            │
├───────────┼────────────┼──────────────────────────────────┤
│ false     │ {}         │ false                            │
│ false     │ {:b}       │ 0                                │
│ false     │ {:b4}      │ 0000                             │
│ false     │ {:b8}      │ 00000000                         │
│ false     │ {:B}       │ 0                                │
│ false     │ {:B4}      │ 0000                             │
│ false     │ {:B8}      │ 00000000                         │
│ false     │ {:d}       │ 0                                │
│ false     │ {:d2}      │ 00                               │
│ false     │ {:D}       │ 0                                │
│ false     │ {:D2}      │ 00                               │
│ false     │ {:g}       │ false                            │
│ false     │ {:G}       │ false                            │
│ false     │ {:o}       │ 0                                │
│ false     │ {:o3}      │ 000                              │
│ false     │ {:O}       │ 0                                │
│ false     │ {:O3}      │ 000                              │
│ false     │ {:x}       │ 0                                │
│ false     │ {:x5}      │ 00000                            │
│ false     │ {:X}       │ 0                                │
│ false     │ {:X5}      │ 00000                            │
├───────────┼────────────┼──────────────────────────────────┤
│ 1         │ {}         │ true                             │
│ 1         │ {:b}       │ 1                                │
│ 1         │ {:b4}      │ 0001                             │
│ 1         │ {:b8}      │ 00000001                         │
│ 1         │ {:B}       │ 1                                │
│ 1         │ {:B4}      │ 0001                             │
│ 1         │ {:B8}      │ 00000001                         │
│ 1         │ {:d}       │ 1                                │
│ 1         │ {:d2}      │ 01                               │
│ 1         │ {:D}       │ 1                                │
│ 1         │ {:D2}      │ 01                               │
│ 1         │ {:g}       │ true                             │
│ 1         │ {:G}       │ true                             │
│ 1         │ {:o}       │ 1                                │
│ 1         │ {:o3}      │ 001                              │
│ 1         │ {:O}       │ 1                                │
│ 1         │ {:O3}      │ 001                              │
│ 1         │ {:x}       │ 1                                │
│ 1         │ {:x5}      │ 00001                            │
│ 1         │ {:X}       │ 1                                │
│ 1         │ {:X5}      │ 00001                            │
├───────────┼────────────┼──────────────────────────────────┤
│ 0         │ {}         │ false                            │
│ 0         │ {:b}       │ 0                                │
│ 0         │ {:b4}      │ 0000                             │
│ 0         │ {:b8}      │ 00000000                         │
│ 0         │ {:B}       │ 0                                │
│ 0         │ {:B4}      │ 0000                             │
│ 0         │ {:B8}      │ 00000000                         │
│ 0         │ {:d}       │ 0                                │
│ 0         │ {:d2}      │ 00                               │
│ 0         │ {:D}       │ 0                                │
│ 0         │ {:D2}      │ 00                               │
│ 0         │ {:g}       │ false                            │
│ 0         │ {:G}       │ false                            │
│ 0         │ {:o}       │ 0                                │
│ 0         │ {:o3}      │ 000                              │
│ 0         │ {:O}       │ 0                                │
│ 0         │ {:O3}      │ 000                              │
│ 0         │ {:x}       │ 0                                │
│ 0         │ {:x5}      │ 00000                            │
│ 0         │ {:X}       │ 0                                │
│ 0         │ {:X5}      │ 00000                            │
└───────────┴────────────┴──────────────────────────────────┘
```

