# format_associative_containers

Show how to use format [xtd::format](https://gammasoft71.github.io/xtd/reference_guides/latest/_format_page.html) class with [associative containers](https://en.cppreference.com/w/cpp/container).

## Sources

[src/format_associative_containers.cpp](src/format_associative_containers.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output (with colors)

```
{1, 2, 3, 4}
{1, 2, 3, 4}
{(1, one), (2, two), (3, three), (4, four)}
{(1, one), (2, two), (3, three), (4, four)}
```

