# format_any

Show how to use format [xtd::format](https://gammasoft71.github.io/xtd/reference_guides/latest/_format_page.html) class with [std::any](https://en.cppreference.com/w/cpp/utility/any).

## Sources

[src/format_any.cpp](src/format_any.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
42
Star Trek: The Next Generation
Before register_any_stringer : (unregistered)
After register_any_stringer : Jean-Luc Picard (Captain)
After unregister_any_stringer : (unregistered)
```

