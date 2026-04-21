# as_string

Shows how to use [xtd::as](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga19379a1158ccd320e208b362f11295b7) operator.

## Sources

* [src/as_string.cpp](src/as_string.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
s1 (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) -> "💾 My string 😎 🐨" has 24 chars
s2 (xtd::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t>>) -> "💾 My string 😎 🐨" has 15 chars
s3 (xtd::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t>>) -> "💾 My string 😎 🐨" has 18 chars
s4 (xtd::basic_string<char8_t, std::char_traits<char8_t>, std::allocator<char8_t>>) -> "💾 My string 😎 🐨" has 24 chars
s5 (xtd::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>) -> "💾 My string 😎 🐨" has 15 chars

s6 (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) -> "💾 My string 😎 🐨" has 24 chars
s7 (xtd::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t>>) -> "💾 My string 😎 🐨" has 15 chars
s8 (xtd::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t>>) -> "💾 My string 😎 🐨" has 18 chars
s9 (xtd::basic_string<char8_t, std::char_traits<char8_t>, std::allocator<char8_t>>) -> "💾 My string 😎 🐨" has 24 chars
s10 (xtd::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>) -> "💾 My string 😎 🐨" has 15 chars

s11 (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) -> "💾 My string 😎 🐨" has 24 chars
s12 (xtd::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t>>) -> "💾 My string 😎 🐨" has 15 chars
s13 (xtd::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t>>) -> "💾 My string 😎 🐨" has 18 chars
s14 (xtd::basic_string<char8_t, std::char_traits<char8_t>, std::allocator<char8_t>>) -> "💾 My string 😎 🐨" has 24 chars
s15 (xtd::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>) -> "💾 My string 😎 🐨" has 15 chars

s16 (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) -> "💾 My string 😎 🐨" has 24 chars
s17 (xtd::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t>>) -> "💾 My string 😎 🐨" has 15 chars
s18 (xtd::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t>>) -> "💾 My string 😎 🐨" has 18 chars
s19 (xtd::basic_string<char8_t, std::char_traits<char8_t>, std::allocator<char8_t>>) -> "💾 My string 😎 🐨" has 24 chars
s20 (xtd::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>) -> "💾 My string 😎 🐨" has 15 chars

s21 (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) -> "💾 My string 😎 🐨" has 24 chars
s22 (xtd::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t>>) -> "💾 My string 😎 🐨" has 15 chars
s23 (xtd::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t>>) -> "💾 My string 😎 🐨" has 18 chars
s24 (xtd::basic_string<char8_t, std::char_traits<char8_t>, std::allocator<char8_t>>) -> "💾 My string 😎 🐨" has 24 chars
s25 (xtd::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>) -> "💾 My string 😎 🐨" has 15 chars
```
