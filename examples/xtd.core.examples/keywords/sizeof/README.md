# sizeof

Shows how to use [sizeof_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gafa2ffd9b4a6568b57ab2731bec095d99) keyword.

## Sources

[src/sizeof.cpp](src/sizeof.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
sizeof :
┌───────────────────┬─────────────────────┬─────────────────────────┐
│  xtd              │  std                │ native                  │
├───────────────────┼─────────────────────┼─────────────────────────┤
│ xtd::boolean =  1 │ ------------------- │ bool               =  1 │
│ xtd::char_   =  1 │ ------------------- │ char               =  1 │
│ xtd::char8   =  1 │ ------------------- │ char8_t            =  1 │
│ xtd::char16  =  2 │ ------------------- │ char16_t           =  2 │
│ xtd::char32  =  4 │ ------------------- │ char32_t           =  4 │
│ xtd::wchar   =  4 │ ------------------- │ wchar_t            =  4 │
│ xtd::single  =  4 │ std::float_t   =  4 │ float              =  4 │
│ xtd::double_ =  8 │ std::double_t  =  8 │ double             =  8 │
│ xtd::decimal =  8 │ ------------------- │ long double        =  8 │
│ xtd::sbyte   =  1 │ std::int8_t    =  1 │ char               =  1 │
│ xtd::int16   =  2 │ std::int16_t   =  2 │ short              =  2 │
│ xtd::int32   =  4 │ std::int32_t   =  4 │ int                =  4 │
│ xtd::int64   =  8 │ std::int64_t   =  8 │ long               =  8 │
│ xtd::intptr  =  8 │ std::intptr_t  =  8 │ long long          =  8 │
│ xtd::byte    =  1 │ std::int8_t    =  1 │ unsigned char      =  1 │
│ xtd::uint16  =  2 │ std::uint16_t  =  2 │ unsigned short     =  2 │
│ xtd::uint32  =  4 │ std::uint32_t  =  4 │ unsigned int       =  4 │
│ xtd::uint64  =  8 │ std::uint64_t  =  8 │ unsigned long      =  8 │
│ xtd::uintptr =  8 │ std::uintptr_t =  8 │ unsigned long long =  8 │
│ xtd::size    =  8 │ ------------------- │ size_t             =  8 │
│ xtd::ptrdiff =  8 │ ------------------- │ ptrdiff_t          =  8 │
└───────────────────┴─────────────────────┴─────────────────────────┘
```
