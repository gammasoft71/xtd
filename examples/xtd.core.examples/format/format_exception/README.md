# format_exception

Show how to use format [xtd::format](https://gammasoft71.github.io/xtd/reference_guides/latest/_format_page.html) class with exceptions.

## Sources

[src/format_exception.cpp](src/format_exception.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output (with colors)

```
1 : Jean-Luc Picard (Captain)
2 : Jean-Luc Picard
xtd::format_exception : The "B" value is not valid format.
   at character::to_string(xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::locale const&) const in /Users/gammasoft/Projects/xtd/examples/xtd.core.examples/format/format_exception/src/format_exception.cpp:line 22
   at xtd::iformatable::__opague_internal_formatable__(long, long, long, long) const in iformatable.cpp:line 7
   at void __basic_string_extract_format_arg<character&>(std::basic_string<char, std::char_traits<char>, std::allocator<char>>&, unsigned long&, std::vector<__format_information<char>, std::allocator<__format_information<char>>>&, character&) in basic_string_.hpp:line 365
   at void __basic_string_extract_format_arg<character&>(xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>&, std::vector<__format_information<char>, std::allocator<__format_information<char>>>&, character&) in basic_string_.hpp:line 387
   at xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>::format<character&>(xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, character&) in basic_string_.hpp:line 328
   at void xtd::println<character&>(char const*, character&) in println.hpp:line 34
   at main in format_exception.cpp:line 34
```

