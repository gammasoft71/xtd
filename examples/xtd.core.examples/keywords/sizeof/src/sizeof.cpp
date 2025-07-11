#include <xtd/xtd>

using namespace xtd;

auto main()->int {
  console::write_line("sizeof :");
  console::write_line("┌───────────────────────────────┬───────────────────────────────┬─────────────────────────────────────────────────────────┬─────────────────────────┐");
  console::write_line("│  xtd (unboxed)                │  xtd (boxed)                  │ std                                                     │  natif                  │");
  console::write_line("├───────────────────────────────┼───────────────────────────────┼─────────────────────────────────────────────────────────┼─────────────────────────┤");
  console::write_line("│ xtd::boolean             = {,2} │ xtd::boolean_object      = {,2} │ n/a                                                     │ bool               = {,2} │", sizeof_<xtd::boolean>(), sizeof_<xtd::boolean_object>(), sizeof_<bool>());
  console::write_line("│ xtd::byte                = {,2} │ xtd::byte_object         = {,2} │ std::int8_t                                        = {,2} │ unsigned char      = {,2} │", sizeof_<xtd::byte>(), sizeof_<xtd::byte_object>(), sizeof_<std::uint8_t>(), sizeof_<unsigned char>());
  console::write_line("│ xtd::char_               = {,2} │ xtd::char_object         = {,2} │ n/a                                                     │ char               = {,2} │", sizeof_<xtd::char_>(), sizeof_<xtd::char_object>(), sizeof_<char>());
  console::write_line("│ xtd::char16              = {,2} │ xtd::char16_object       = {,2} │ n/a                                                     │ char16_t           = {,2} │", sizeof_<xtd::char16>(), sizeof_<xtd::char16_object>(), sizeof_<char16_t>());
  console::write_line("│ xtd::char32              = {,2} │ xtd::char32_object       = {,2} │ n/a                                                     │ char32_t           = {,2} │", sizeof_<xtd::char32>(), sizeof_<xtd::char32_object>(), sizeof_<char32_t>());
  console::write_line("│ xtd::char8               = {,2} │ xtd::char8_object        = {,2} │ n/a                                                     │ char8_t            = {,2} │", sizeof_<xtd::char8>(), sizeof_<xtd::char8_object>(), sizeof_<char8_t>());
  console::write_line("│ xtd::date_time           = {,2} │ xtd::date_time           = {,2} │ std::chrono::system_clock                          = {,2} │ struct tm          = {,2} │", sizeof_<xtd::date_time>(), sizeof_<xtd::date_time>(), sizeof_<std::chrono::system_clock>(), sizeof_<struct tm>());
  console::write_line("│ xtd::decimal             = {,2} │ xtd::decimal_object      = {,2} │ n/a                                                     │ long double        = {,2} │", sizeof_<xtd::decimal>(), sizeof_<xtd::decimal_object>(), sizeof_<long double>());
  console::write_line("│ xtd::double_             = {,2} │ xtd::double_object       = {,2} │ std::double_t                                      = {,2} │ double             = {,2} │", sizeof_<xtd::double_>(), sizeof_<xtd::double_object>(), sizeof_<std::double_t>(), sizeof_<double>());
  console::write_line("│ n/a                           │ xtd::enum_object         = {,2} │ n/a                                                     │ enum               = {,2} │", sizeof_<xtd::enum_object<day_of_week>>(), sizeof_<day_of_week>());
  console::write_line("│ xtd::guid                = {,2} │ xtd::guid                = {,2} │ n/a                                                     │ n/a                     │", sizeof_<xtd::guid>(), sizeof_<xtd::guid>());
  console::write_line("│ xtd::int16               = {,2} │ xtd::int16_object        = {,2} │ std::int16_t                                       = {,2} │ short              = {,2} │", sizeof_<xtd::int16>(), sizeof_<xtd::int16_object>(), sizeof_<std::int16_t>(), sizeof_<short>());
  console::write_line("│ xtd::int32               = {,2} │ xtd::int32_object        = {,2} │ std::int32_t                                       = {,2} │ int                = {,2} │", sizeof_<xtd::int32>(), sizeof_<xtd::int32_object>(), sizeof_<std::int32_t>(), sizeof_<int>());
  console::write_line("│ xtd::int64               = {,2} │ xtd::int64_object        = {,2} │ std::int64_t                                       = {,2} │ long               = {,2} │", sizeof_<xtd::int64>(), sizeof_<xtd::int64_object>(), sizeof_<std::int64_t>(), sizeof_<long>());
  console::write_line("│ xtd::intptr              = {,2} │ xtd::intptr_object       = {,2} │ std::intptr_t                                      = {,2} │ long long          = {,2} │", sizeof_<xtd::intptr>(), sizeof_<xtd::intptr_object>(), sizeof_<std::intptr_t>(), sizeof_<long long>());
  console::write_line("│ xtd::object              = {,2} │ xtd::object              = {,2} │ n/a                                                     │ n/a                     │", sizeof_<xtd::object>(), sizeof_<xtd::object>());
  console::write_line("│ xtd::ptrdiff             = {,2} │ xtd::ptrdiff_object      = {,2} │ n/a                                                     │ ptrdiff_t          = {,2} │", sizeof_<xtd::ptrdiff>(), sizeof_<xtd::ptrdiff_object>(), sizeof_<ptrdiff_t>());
  console::write_line("│ xtd::sbyte               = {,2} │ xtd::sbyte_object        = {,2} │ std::int8_t                                        = {,2} │ char               = {,2} │", sizeof_<xtd::sbyte>(), sizeof_<xtd::sbyte_object>(), sizeof_<std::int8_t>(), sizeof_<char>());
  console::write_line("│ xtd::single              = {,2} │ xtd::single_object       = {,2} │ std::float_t                                       = {,2} │ float              = {,2} │", sizeof_<xtd::single>(), sizeof_<xtd::single_object>(), sizeof_<std::float_t>(), sizeof_<float>());
  console::write_line("│ xtd::size                = {,2} │ xtd::size_object         = {,2} │ n/a                                                     │ size_t             = {,2} │", sizeof_<xtd::size>(), sizeof_<xtd::size_object>(), sizeof_<size_t>());
  console::write_line("│ xtd::string              = {,2} │ xtd::string              = {,2} │ std::string                                        = {,2} │ n/a                     │", sizeof_<xtd::string>(), sizeof_<xtd::string>(), sizeof_<std::string>());
  console::write_line("│ xtd::time_span           = {,2} │ xtd::time_span           = {,2} │ std::chrono::time_point<std::chrono::system_clock> = {,2} │ n/a                     │", sizeof_<xtd::time_span>(), sizeof_<xtd::time_span>(), sizeof_<std::chrono::time_point<std::chrono::system_clock>>());
  console::write_line("│ xtd::uint16              = {,2} │ xtd::uint16_object       = {,2} │ std::uint16_t                                      = {,2} │ unsigned short     = {,2} │", sizeof_<xtd::uint16>(), sizeof_<xtd::uint16_object>(), sizeof_<std::uint16_t>(), sizeof_<unsigned short>());
  console::write_line("│ xtd::uint32              = {,2} │ xtd::uint32_object       = {,2} │ std::uint32_t                                      = {,2} │ unsigned int       = {,2} │", sizeof_<xtd::uint32>(), sizeof_<xtd::uint32_object>(), sizeof_<std::uint32_t>(), sizeof_<unsigned int>());
  console::write_line("│ xtd::uint64              = {,2} │ xtd::uint64_object       = {,2} │ std::uint64_t                                      = {,2} │ unsigned long      = {,2} │", sizeof_<xtd::uint64>(), sizeof_<xtd::uint64_object>(), sizeof_<std::uint64_t>(), sizeof_<unsigned long>());
  console::write_line("│ xtd::uintptr             = {,2} │ xtd::uintptr_object      = {,2} │ std::uintptr_t                                     = {,2} │ unsigned long long = {,2} │", sizeof_<xtd::uintptr>(), sizeof_<xtd::uintptr_object>(), sizeof_<std::uintptr_t>(), sizeof_<unsigned long long>());
  console::write_line("│ xtd::uri                 = {,2} │ xtd::uri                 = {,2} │ n/a                                                     │ n/a                     │", sizeof_<xtd::uri>(), sizeof_<xtd::uri>());
  console::write_line("│ xtd::version             = {,2} │ xtd::version             = {,2} │ n/a                                                     │ n/a                     │", sizeof_<xtd::version>(), sizeof_<xtd::version>());
  console::write_line("│ xtd::wchar               = {,2} │ xtd::wchar_object        = {,2} │ n/a                                                     │ wchar_t            = {,2} │", sizeof_<xtd::wchar>(), sizeof_<xtd::wchar_object>(), sizeof_<wchar_t>());
  console::write_line("│ xtd::drawing::point      = {,2} │ xtd::drawing::point      = {,2} │ n/a                                                     │ n/a                     │", sizeof_<xtd::drawing::point>(), sizeof_<xtd::drawing::point>());
  console::write_line("│ xtd::drawing::rectangle  = {,2} │ xtd::drawing::rectangle  = {,2} │ n/a                                                     │ n/a                     │", sizeof_<xtd::drawing::rectangle>(), sizeof_<xtd::drawing::rectangle>());
  console::write_line("│ xtd::drawing::size       = {,2} │ xtd::drawing::size       = {,2} │ n/a                                                     │ n/a                     │", sizeof_<xtd::drawing::size>(), sizeof_<xtd::drawing::size>());
  console::write_line("└───────────────────────────────┴───────────────────────────────┴─────────────────────────────────────────────────────────┴─────────────────────────┘");
}

// This code can produce the following output :
//
// sizeof :
// ┌───────────────────────────────┬───────────────────────────────┬─────────────────────────────────────────────────────────┬─────────────────────────┐
// │  xtd (unboxed)                │  xtd (boxed)                  │ std                                                     │  natif                  │
// ├───────────────────────────────┼───────────────────────────────┼─────────────────────────────────────────────────────────┼─────────────────────────┤
// │ xtd::boolean             =  1 │ xtd::boolean_object      = 40 │ n/a                                                     │ bool               =  1 │
// │ xtd::byte                =  1 │ xtd::byte_object         = 40 │ std::int8_t                                        =  1 │ unsigned char      =  1 │
// │ xtd::char_               =  1 │ xtd::char_object         = 40 │ n/a                                                     │ char               =  1 │
// │ xtd::char16              =  2 │ xtd::char16_object       = 40 │ n/a                                                     │ char16_t           =  2 │
// │ xtd::char32              =  4 │ xtd::char32_object       = 40 │ n/a                                                     │ char32_t           =  4 │
// │ xtd::char8               =  1 │ xtd::char8_object        = 40 │ n/a                                                     │ char8_t            =  1 │
// │ xtd::date_time           = 48 │ xtd::date_time           = 48 │ std::chrono::system_clock                          =  1 │ struct tm          = 56 │
// │ xtd::decimal             =  8 │ xtd::decimal_object      = 40 │ n/a                                                     │ long double        =  8 │
// │ xtd::double_             =  8 │ xtd::double_object       = 40 │ std::double_t                                      =  8 │ double             =  8 │
// │ n/a                           │ xtd::enum_object         = 40 │ n/a                                                     │ enum               =  4 │
// │ xtd::guid                = 56 │ xtd::guid                = 56 │ n/a                                                     │ n/a                     │
// │ xtd::int16               =  2 │ xtd::int16_object        = 40 │ std::int16_t                                       =  2 │ short              =  2 │
// │ xtd::int32               =  4 │ xtd::int32_object        = 40 │ std::int32_t                                       =  4 │ int                =  4 │
// │ xtd::int64               =  8 │ xtd::int64_object        = 40 │ std::int64_t                                       =  8 │ long               =  8 │
// │ xtd::intptr              =  8 │ xtd::intptr_object       = 40 │ std::intptr_t                                      =  8 │ long long          =  8 │
// │ xtd::object              =  8 │ xtd::object              =  8 │ n/a                                                     │ n/a                     │
// │ xtd::ptrdiff             =  8 │ xtd::ptrdiff_object      = 40 │ n/a                                                     │ ptrdiff_t          =  8 │
// │ xtd::sbyte               =  1 │ xtd::sbyte_object        = 40 │ std::int8_t                                        =  1 │ char               =  1 │
// │ xtd::single              =  4 │ xtd::single_object       = 40 │ std::float_t                                       =  4 │ float              =  4 │
// │ xtd::size                =  8 │ xtd::size_object         = 40 │ n/a                                                     │ size_t             =  8 │
// │ xtd::string              = 64 │ xtd::string              = 64 │ std::string                                        = 24 │ n/a                     │
// │ xtd::time_span           = 40 │ xtd::time_span           = 40 │ std::chrono::time_point<std::chrono::system_clock> =  8 │ n/a                     │
// │ xtd::uint16              =  2 │ xtd::uint16_object       = 40 │ std::uint16_t                                      =  2 │ unsigned short     =  2 │
// │ xtd::uint32              =  4 │ xtd::uint32_object       = 40 │ std::uint32_t                                      =  4 │ unsigned int       =  4 │
// │ xtd::uint64              =  8 │ xtd::uint64_object       = 40 │ std::uint64_t                                      =  8 │ unsigned long      =  8 │
// │ xtd::uintptr             =  8 │ xtd::uintptr_object      = 40 │ std::uintptr_t                                     =  8 │ unsigned long long =  8 │
// │ xtd::uri                 = 56 │ xtd::uri                 = 56 │ n/a                                                     │ n/a                     │
// │ xtd::version             = 40 │ xtd::version             = 40 │ n/a                                                     │ n/a                     │
// │ xtd::wchar               =  4 │ xtd::wchar_object        = 40 │ n/a                                                     │ wchar_t            =  4 │
// │ xtd::drawing::point      = 24 │ xtd::drawing::point      = 24 │ n/a                                                     │ n/a                     │
// │ xtd::drawing::rectangle  = 32 │ xtd::drawing::rectangle  = 32 │ n/a                                                     │ n/a                     │
// │ xtd::drawing::size       = 24 │ xtd::drawing::size       = 24 │ n/a                                                     │ n/a                     │
// └───────────────────────────────┴───────────────────────────────┴─────────────────────────────────────────────────────────┴─────────────────────────┘
