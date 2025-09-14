# sizeof

Shows how to use [sizeof_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gacff264255bb80f00c1447fda6524b0ec) keyword.

## Sources

* [src/sizeof.cpp](src/sizeof.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
sizeof :
┌───────────────────────────────┬───────────────────────────────┬─────────────────────────────────────────────────────────┬─────────────────────────┐
│  xtd (unboxed)                │  xtd (boxed)                  │ std                                                     │  natif                  │
├───────────────────────────────┼───────────────────────────────┼─────────────────────────────────────────────────────────┼─────────────────────────┤
│ xtd::boolean             =  1 │ xtd::boolean_object      = 40 │ n/a                                                     │ bool               =  1 │
│ xtd::byte                =  1 │ xtd::byte_object         = 40 │ std::int8_t                                        =  1 │ unsigned char      =  1 │
│ xtd::char_               =  1 │ xtd::char_object         = 40 │ n/a                                                     │ char               =  1 │
│ xtd::char16              =  2 │ xtd::char16_object       = 40 │ n/a                                                     │ char16_t           =  2 │
│ xtd::char32              =  4 │ xtd::char32_object       = 40 │ n/a                                                     │ char32_t           =  4 │
│ xtd::char8               =  1 │ xtd::char8_object        = 40 │ n/a                                                     │ char8_t            =  1 │
│ xtd::date_time           = 48 │ xtd::date_time           = 48 │ std::chrono::system_clock                          =  1 │ struct tm          = 56 │
│ xtd::decimal             =  8 │ xtd::decimal_object      = 40 │ n/a                                                     │ long double        =  8 │
│ xtd::double_             =  8 │ xtd::double_object       = 40 │ std::double_t                                      =  8 │ double             =  8 │
│ n/a                           │ xtd::enum_object         = 40 │ n/a                                                     │ enum               =  4 │
│ xtd::guid                = 56 │ xtd::guid                = 56 │ n/a                                                     │ n/a                     │
│ xtd::int16               =  2 │ xtd::int16_object        = 40 │ std::int16_t                                       =  2 │ short              =  2 │
│ xtd::int32               =  4 │ xtd::int32_object        = 40 │ std::int32_t                                       =  4 │ int                =  4 │
│ xtd::int64               =  8 │ xtd::int64_object        = 40 │ std::int64_t                                       =  8 │ long               =  8 │
│ xtd::intptr              =  8 │ xtd::intptr_object       = 40 │ std::intptr_t                                      =  8 │ long long          =  8 │
│ xtd::object              =  8 │ xtd::object              =  8 │ n/a                                                     │ n/a                     │
│ xtd::ptrdiff             =  8 │ xtd::ptrdiff_object      = 40 │ n/a                                                     │ ptrdiff_t          =  8 │
│ xtd::sbyte               =  1 │ xtd::sbyte_object        = 40 │ std::int8_t                                        =  1 │ char               =  1 │
│ xtd::single              =  4 │ xtd::single_object       = 40 │ std::float_t                                       =  4 │ float              =  4 │
│ xtd::size                =  8 │ xtd::size_object         = 40 │ n/a                                                     │ size_t             =  8 │
│ xtd::string              = 64 │ xtd::string              = 64 │ std::string                                        = 24 │ n/a                     │
│ xtd::time_span           = 40 │ xtd::time_span           = 40 │ std::chrono::time_point<std::chrono::system_clock> =  8 │ n/a                     │
│ xtd::uint16              =  2 │ xtd::uint16_object       = 40 │ std::uint16_t                                      =  2 │ unsigned short     =  2 │
│ xtd::uint32              =  4 │ xtd::uint32_object       = 40 │ std::uint32_t                                      =  4 │ unsigned int       =  4 │
│ xtd::uint64              =  8 │ xtd::uint64_object       = 40 │ std::uint64_t                                      =  8 │ unsigned long      =  8 │
│ xtd::uintptr             =  8 │ xtd::uintptr_object      = 40 │ std::uintptr_t                                     =  8 │ unsigned long long =  8 │
│ xtd::uri                 = 56 │ xtd::uri                 = 56 │ n/a                                                     │ n/a                     │
│ xtd::version             = 40 │ xtd::version             = 40 │ n/a                                                     │ n/a                     │
│ xtd::wchar               =  4 │ xtd::wchar_object        = 40 │ n/a                                                     │ wchar_t            =  4 │
│ xtd::drawing::point      = 24 │ xtd::drawing::point      = 24 │ n/a                                                     │ n/a                     │
│ xtd::drawing::rectangle  = 32 │ xtd::drawing::rectangle  = 32 │ n/a                                                     │ n/a                     │
│ xtd::drawing::size       = 24 │ xtd::drawing::size       = 24 │ n/a                                                     │ n/a                     │
└───────────────────────────────┴───────────────────────────────┴─────────────────────────────────────────────────────────┴─────────────────────────┘
```
