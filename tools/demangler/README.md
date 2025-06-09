# demangler

demangler is use to demangling a stack trace command line tool.

# Usage

```
guidgen stack_file
```

The options are:

```
-o, --output  : Write result in output_demangled_file.
-q, --quiet   : Do not write result on stdout.
-v, --version : Shows version information.
-h, --help    : Shows this help page.
```

# Example

## Demangle stack trace in stack_trace.txt file

Open "Command Prompt" or "Terminal", and type the following:

```bash
demangler stack_trace.txt
```

Example output

```cpp
std::char_traits<char>::assign(char&, char const&)
std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_S_copy(char*, char const*, unsigned long)
void std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_construct<true>(char const*, unsigned long)
std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const&)
xtd::ustring::ustring(xtd::ustring const&)
xtd::version::to_string(unsigned long) const
xtd::version::to_string() const
xtd::version::to_string() const
__object_to_string[abi:cxx11](xtd::object const&)
__enum_or_polymorphic_ostream__<char, xtd::version, std::integral_constant<bool, true>>::to_stream(std::ostream&, xtd::version const&)
std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> __format_stringer_to_std_string<xtd::version>(xtd::version const&)
std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> __format_stringer<char, xtd::version&>(xtd::version&)
void __ustring_extract_format_arg<xtd::version&>(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>&, unsigned long&, std::vector<__format_information<char>, std::allocator<__format_information<char>>>&, xtd::version&)
void __ustring_extract_format_arg<xtd::ustring, xtd::version>(xtd::ustring&, std::vector<__format_information<char>, std::allocator<__format_information<char>>>&, xtd::ustring&&, xtd::version&&)
xtd::ustring xtd::ustring::format<xtd::ustring, xtd::version>(xtd::ustring const&, xtd::ustring&&, xtd::version&&)
xtd::forms::native::toolkit::description()
__init_toolkit__::__init_toolkit__()
__static_initialization_and_destruction_0
_GLOBAL__sub_I___init_process_message_box_message_value__
__libc_start_main@@GLIBC_2.34
_start
```

# For more info about guidgen

Open "Command Prompt" or "Terminal", and type the following:

```bash
demangler --help
```

______________________________________________________________________________________________

© 2025 Gammasoft.
