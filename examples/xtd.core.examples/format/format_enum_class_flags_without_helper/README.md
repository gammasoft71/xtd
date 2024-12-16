# format_enum_class_flags_without_helper

Show how to use format [xtd::format](https://gammasoft71.github.io/xtd/reference_guides/latest/_format_page.html) class with enum classes flags without helper.

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
┌───────────────────────────────────────────────┬────────────┬──────────────────────────────────┐
│  text_styles                                  │   format   │      representation              │
├───────────────────────────────────────────────┼────────────┼──────────────────────────────────┤
│ text_styles::normal                           │ {}         │ normal                           │
│ text_styles::normal                           │ {:b}       │ 0                                │
│ text_styles::normal                           │ {:b4}      │ 0000                             │
│ text_styles::normal                           │ {:B}       │ 0                                │
│ text_styles::normal                           │ {:B4}      │ 0000                             │
│ text_styles::normal                           │ {:d}       │ 0                                │
│ text_styles::normal                           │ {:d1}      │ 0                                │
│ text_styles::normal                           │ {:D}       │ 0                                │
│ text_styles::normal                           │ {:D1}      │ 0                                │
│ text_styles::normal                           │ {:g}       │ normal                           │
│ text_styles::normal                           │ {:G}       │ normal                           │
│ text_styles::normal                           │ {:o}       │ 0                                │
│ text_styles::normal                           │ {:o2}      │ 00                               │
│ text_styles::normal                           │ {:O}       │ 0                                │
│ text_styles::normal                           │ {:O2}      │ 00                               │
│ text_styles::normal                           │ {:x}       │ 0                                │
│ text_styles::normal                           │ {:x2}      │ 00                               │
│ text_styles::normal                           │ {:X}       │ 0                                │
│ text_styles::normal                           │ {:X2}      │ 00                               │
├───────────────────────────────────────────────┼────────────┼──────────────────────────────────┤
│ text_styles::bold|text_styles::italic         │ {}         │ bold, italic                     │
│ text_styles::bold|text_styles::italic         │ {:b}       │ 11                               │
│ text_styles::bold|text_styles::italic         │ {:b4}      │ 0011                             │
│ text_styles::bold|text_styles::italic         │ {:B}       │ 11                               │
│ text_styles::bold|text_styles::italic         │ {:B4}      │ 0011                             │
│ text_styles::bold|text_styles::italic         │ {:d}       │ 3                                │
│ text_styles::bold|text_styles::italic         │ {:d1}      │ 3                                │
│ text_styles::bold|text_styles::italic         │ {:D}       │ 3                                │
│ text_styles::bold|text_styles::italic         │ {:D1}      │ 3                                │
│ text_styles::bold|text_styles::italic         │ {:g}       │ bold, italic                     │
│ text_styles::bold|text_styles::italic         │ {:G}       │ bold, italic                     │
│ text_styles::bold|text_styles::italic         │ {:o}       │ 3                                │
│ text_styles::bold|text_styles::italic         │ {:o2}      │ 03                               │
│ text_styles::bold|text_styles::italic         │ {:O}       │ 3                                │
│ text_styles::bold|text_styles::italic         │ {:O2}      │ 03                               │
│ text_styles::bold|text_styles::italic         │ {:x}       │ 3                                │
│ text_styles::bold|text_styles::italic         │ {:x2}      │ 03                               │
│ text_styles::bold|text_styles::italic         │ {:X}       │ 3                                │
│ text_styles::bold|text_styles::italic         │ {:X2}      │ 03                               │
├───────────────────────────────────────────────┼────────────┼──────────────────────────────────┤
│ text_styles::strikeout                        │ {}         │ strikeout                        │
│ text_styles::strikeout                        │ {:b}       │ 1000                             │
│ text_styles::strikeout                        │ {:b4}      │ 1000                             │
│ text_styles::strikeout                        │ {:B}       │ 1000                             │
│ text_styles::strikeout                        │ {:B4}      │ 1000                             │
│ text_styles::strikeout                        │ {:d}       │ 8                                │
│ text_styles::strikeout                        │ {:d1}      │ 8                                │
│ text_styles::strikeout                        │ {:D}       │ 8                                │
│ text_styles::strikeout                        │ {:D1}      │ 8                                │
│ text_styles::strikeout                        │ {:g}       │ strikeout                        │
│ text_styles::strikeout                        │ {:G}       │ strikeout                        │
│ text_styles::strikeout                        │ {:o}       │ 10                               │
│ text_styles::strikeout                        │ {:o2}      │ 10                               │
│ text_styles::strikeout                        │ {:O}       │ 10                               │
│ text_styles::strikeout                        │ {:O2}      │ 10                               │
│ text_styles::strikeout                        │ {:x}       │ 8                                │
│ text_styles::strikeout                        │ {:x2}      │ 08                               │
│ text_styles::strikeout                        │ {:X}       │ 8                                │
│ text_styles::strikeout                        │ {:X2}      │ 08                               │
└───────────────────────────────────────────────┴────────────┴──────────────────────────────────┘
```

