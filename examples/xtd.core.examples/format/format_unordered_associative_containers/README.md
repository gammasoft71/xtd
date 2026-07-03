# format_unordered_associative_containers

Show how to use format [xtd::format](https://gammasoft71.github.io/xtd/reference_guides/latest/_format_page.html) class with [unordered associative containers](https://en.cppreference.com/w/cpp/named_req/UnorderedAssociativeContainer).

## Sources

* [src/format_unordered_associative_containers.cpp](src/format_unordered_associative_containers.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output (with colors)

```
{4, 3, 2, 1}
{(4, four), (3, three), (2, two), (1, one)}

{4, 3, 2, 1}
{4, 3, 2, 1}
{(4, four), (3, three), (2, two), (1, one)}
{(4, four), (3, three), (2, two), (1, one)}
```

