# format_character

Show how to use format [xtd::format](https://gammasoft71.github.io/xtd/reference_guides/latest/_format_page.html) class with characters.

## Sources

* [src/format_character.cpp](src/format_character.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output (with colors)

```
┌───────────┬────────────┬──────────────────────────────────┐
│  char     │   format   │      representation              │
├───────────┼────────────┼──────────────────────────────────┤
│ a         │ {}         │ a                                │
│ a         │ {:g}       │ a                                │
│ a         │ {:G}       │ a                                │
│ a         │ {:d}       │ a                                │
│ a         │ {:D}       │ a                                │
│ a         │ {:x}       │ a                                │
│ a         │ {:X}       │ a                                │
│ a         │ {:ANY_FMT} │ a                                │
├───────────┼────────────┼──────────────────────────────────┤
│ 1         │ {}         │ 1                                │
│ 1         │ {:g}       │ 1                                │
│ 1         │ {:G}       │ 1                                │
│ 1         │ {:d}       │ 1                                │
│ 1         │ {:D}       │ 1                                │
│ 1         │ {:x}       │ 1                                │
│ 1         │ {:X}       │ 1                                │
│ 1         │ {:ANY_FMT} │ 1                                │
├───────────┼────────────┼──────────────────────────────────┤
│ 😃         │ {}         │ 😃                                │
│ 😃         │ {:g}       │ 😃                                │
│ 😃         │ {:G}       │ 😃                                │
│ 😃         │ {:d}       │ 😃                                │
│ 😃         │ {:D}       │ 😃                                │
│ 😃         │ {:x}       │ 😃                                │
│ 😃         │ {:X}       │ 😃                                │
│ 😃         │ {:ANY_FMT} │ 😃                                │
├───────────┼────────────┼──────────────────────────────────┤
│ 亰         │ {}         │ 亰                                │
│ 亰         │ {:g}       │ 亰                                │
│ 亰         │ {:G}       │ 亰                                │
│ 亰         │ {:d}       │ 亰                                │
│ 亰         │ {:D}       │ 亰                                │
│ 亰         │ {:x}       │ 亰                                │
│ 亰         │ {:X}       │ 亰                                │
│ 亰         │ {:ANY_FMT} │ 亰                                │
├───────────┼────────────┼──────────────────────────────────┤
│ 🐨         │ {}         │ 🐨                                │
│ 🐨         │ {:g}       │ 🐨                                │
│ 🐨         │ {:G}       │ 🐨                                │
│ 🐨         │ {:d}       │ 🐨                                │
│ 🐨         │ {:D}       │ 🐨                                │
│ 🐨         │ {:x}       │ 🐨                                │
│ 🐨         │ {:X}       │ 🐨                                │
│ 🐨         │ {:ANY_FMT} │ 🐨                                │
└───────────┴────────────┴──────────────────────────────────┘
```

