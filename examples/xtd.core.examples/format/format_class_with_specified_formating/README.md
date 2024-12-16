# format_class_with_specified_formating

Show how to use format [xtd::format](https://gammasoft71.github.io/xtd/reference_guides/latest/_format_page.html) class with specified formatting.

## Sources

[src/format_class_with_specified_formating.cpp](src/format_class_with_specified_formating.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output (with colors)

```
┌───────────────────────────────────────────────┬────────────┬──────────────────────────────────────────┐
│  character                                    │   format   │      representation                      │
├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
│ {}                                            │ {}         │  ()                                      │
│ {}                                            │ {:F}       │  ()                                      │
│ {}                                            │ {:N}       │                                          │
│ {}                                            │ {:R}       │                                          │
├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
│ {"Jean-Luc Picard", "Captain"}                │ {}         │ Jean-Luc Picard (Captain)                │
│ {"Jean-Luc Picard", "Captain"}                │ {:F}       │ Jean-Luc Picard (Captain)                │
│ {"Jean-Luc Picard", "Captain"}                │ {:N}       │ Jean-Luc Picard                          │
│ {"Jean-Luc Picard", "Captain"}                │ {:R}       │ Captain                                  │
├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
│ {"William Riker", "Commander"}                │ {}         │ William Riker (Commander)                │
│ {"William Riker", "Commander"}                │ {:F}       │ William Riker (Commander)                │
│ {"William Riker", "Commander"}                │ {:N}       │ William Riker                            │
│ {"William Riker", "Commander"}                │ {:R}       │ Commander                                │
├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
│ {"Data", "Commander"}                         │ {}         │ Data (Commander)                         │
│ {"Data", "Commander"}                         │ {:F}       │ Data (Commander)                         │
│ {"Data", "Commander"}                         │ {:N}       │ Data                                     │
│ {"Data", "Commander"}                         │ {:R}       │ Commander                                │
├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
│ {"Beverly Crusher", "Commander"}              │ {}         │ Beverly Crusher (Commander)              │
│ {"Beverly Crusher", "Commander"}              │ {:F}       │ Beverly Crusher (Commander)              │
│ {"Beverly Crusher", "Commander"}              │ {:N}       │ Beverly Crusher                          │
│ {"Beverly Crusher", "Commander"}              │ {:R}       │ Commander                                │
├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
│ {"Geordi La Forge", "Lieutenant Commander"}   │ {}         │ Geordi La Forge (Lieutenant Commander)   │
│ {"Geordi La Forge", "Lieutenant Commander"}   │ {:F}       │ Geordi La Forge (Lieutenant Commander)   │
│ {"Geordi La Forge", "Lieutenant Commander"}   │ {:N}       │ Geordi La Forge                          │
│ {"Geordi La Forge", "Lieutenant Commander"}   │ {:R}       │ Lieutenant Commander                     │
├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
│ {"Worf", "Lieutenant Commander"}              │ {}         │ Worf (Lieutenant Commander)              │
│ {"Worf", "Lieutenant Commander"}              │ {:F}       │ Worf (Lieutenant Commander)              │
│ {"Worf", "Lieutenant Commander"}              │ {:N}       │ Worf                                     │
│ {"Worf", "Lieutenant Commander"}              │ {:R}       │ Lieutenant Commander                     │
├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
│ {"Tasha Yar", "Lieutenant"}                   │ {}         │ Tasha Yar (Lieutenant)                   │
│ {"Tasha Yar", "Lieutenant"}                   │ {:F}       │ Tasha Yar (Lieutenant)                   │
│ {"Tasha Yar", "Lieutenant"}                   │ {:N}       │ Tasha Yar                                │
│ {"Tasha Yar", "Lieutenant"}                   │ {:R}       │ Lieutenant                               │
└───────────────────────────────────────────────┴────────────┴──────────────────────────────────────────┘
```

