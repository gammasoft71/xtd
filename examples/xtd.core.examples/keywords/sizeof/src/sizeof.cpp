#include <xtd/console>
#include <xtd/environment>
#include <xtd/sizeof>

using namespace xtd;

auto main() -> int {
  console::write_line("sizeof :");
  console::write_line("┌───────────────────┬─────────────────────┬─────────────────────────┐");
  console::write_line("│  xtd              │  std                │ native                  │");
  console::write_line("├───────────────────┼─────────────────────┼─────────────────────────┤");
  console::write_line("│ xtd::boolean = {,2} │ ------------------- │ bool               = {,2} │", sizeof_(xtd::boolean), sizeof_(bool));
  console::write_line("│ xtd::char_   = {,2} │ ------------------- │ char               = {,2} │", sizeof_(xtd::char_), sizeof_(char));
  console::write_line("│ xtd::char8   = {,2} │ ------------------- │ char8_t            = {,2} │", sizeof_(xtd::char8), sizeof_(char8_t));
  console::write_line("│ xtd::char16  = {,2} │ ------------------- │ char16_t           = {,2} │", sizeof_(xtd::char16), sizeof_(char16_t));
  console::write_line("│ xtd::char32  = {,2} │ ------------------- │ char32_t           = {,2} │", sizeof_(xtd::char32), sizeof_(char32_t));
  console::write_line("│ xtd::wchar   = {,2} │ ------------------- │ wchar_t            = {,2} │", sizeof_(xtd::wchar), sizeof_(wchar_t));
  console::write_line("│ xtd::single  = {,2} │ std::float_t   = {,2} │ float              = {,2} │", sizeof_(xtd::single), sizeof_(std::float_t), sizeof_(float));
  console::write_line("│ xtd::double_ = {,2} │ std::double_t  = {,2} │ double             = {,2} │", sizeof_(xtd::double_), sizeof_(std::double_t), sizeof_(double));
  console::write_line("│ xtd::decimal = {,2} │ ------------------- │ long double        = {,2} │", sizeof_(xtd::decimal), sizeof_(long double));
  console::write_line("│ xtd::sbyte   = {,2} │ std::int8_t    = {,2} │ char               = {,2} │", sizeof_(xtd::sbyte), sizeof_(std::int8_t), sizeof_(char));
  console::write_line("│ xtd::int16   = {,2} │ std::int16_t   = {,2} │ short              = {,2} │", sizeof_(xtd::int16), sizeof_(std::int16_t), sizeof_(short));
  console::write_line("│ xtd::int32   = {,2} │ std::int32_t   = {,2} │ int                = {,2} │", sizeof_(xtd::int32), sizeof_(std::int32_t), sizeof_(int));
  console::write_line("│ xtd::int64   = {,2} │ std::int64_t   = {,2} │ long               = {,2} │", sizeof_(xtd::int64), sizeof_(std::int64_t), sizeof_(long));
  console::write_line("│ xtd::intptr  = {,2} │ std::intptr_t  = {,2} │ long long          = {,2} │", sizeof_(xtd::intptr), sizeof_(std::intptr_t), sizeof_(long long));
  console::write_line("│ xtd::byte    = {,2} │ std::int8_t    = {,2} │ unsigned char      = {,2} │", sizeof_(xtd::byte), sizeof_(std::uint8_t), sizeof_(unsigned char));
  console::write_line("│ xtd::uint16  = {,2} │ std::uint16_t  = {,2} │ unsigned short     = {,2} │", sizeof_(xtd::uint16), sizeof_(std::uint16_t), sizeof_(unsigned short));
  console::write_line("│ xtd::uint32  = {,2} │ std::uint32_t  = {,2} │ unsigned int       = {,2} │", sizeof_(xtd::uint32), sizeof_(std::uint32_t), sizeof_(unsigned int));
  console::write_line("│ xtd::uint64  = {,2} │ std::uint64_t  = {,2} │ unsigned long      = {,2} │", sizeof_(xtd::uint64), sizeof_(std::uint64_t), sizeof_(unsigned long));
  console::write_line("│ xtd::uintptr = {,2} │ std::uintptr_t = {,2} │ unsigned long long = {,2} │", sizeof_(xtd::uintptr), sizeof_(std::uintptr_t), sizeof_(unsigned long long));
  console::write_line("│ xtd::size    = {,2} │ ------------------- │ size_t             = {,2} │", sizeof_(xtd::size), sizeof_(size_t));
  console::write_line("│ xtd::ptrdiff = {,2} │ ------------------- │ ptrdiff_t          = {,2} │", sizeof_(xtd::ptrdiff), sizeof_(ptrdiff_t));
  console::write_line("└───────────────────┴─────────────────────┴─────────────────────────┘");
}

// This code produces the following output :
//
// sizeof :
// ┌───────────────────┬─────────────────────┬─────────────────────────┐
// │  xtd              │  std                │ native                  │
// ├───────────────────┼─────────────────────┼─────────────────────────┤
// │ xtd::boolean =  1 │ ------------------- │ bool               =  1 │
// │ xtd::char_   =  1 │ ------------------- │ char               =  1 │
// │ xtd::char8   =  1 │ ------------------- │ char8_t            =  1 │
// │ xtd::char16  =  2 │ ------------------- │ char16_t           =  2 │
// │ xtd::char32  =  4 │ ------------------- │ char32_t           =  4 │
// │ xtd::wchar   =  4 │ ------------------- │ wchar_t            =  4 │
// │ xtd::single  =  4 │ std::float_t   =  4 │ float              =  4 │
// │ xtd::double_ =  8 │ std::double_t  =  8 │ double             =  8 │
// │ xtd::decimal =  8 │ ------------------- │ long double        =  8 │
// │ xtd::sbyte   =  1 │ std::int8_t    =  1 │ char               =  1 │
// │ xtd::int16   =  2 │ std::int16_t   =  2 │ short              =  2 │
// │ xtd::int32   =  4 │ std::int32_t   =  4 │ int                =  4 │
// │ xtd::int64   =  8 │ std::int64_t   =  8 │ long               =  8 │
// │ xtd::intptr  =  8 │ std::intptr_t  =  8 │ long long          =  8 │
// │ xtd::byte    =  1 │ std::int8_t    =  1 │ unsigned char      =  1 │
// │ xtd::uint16  =  2 │ std::uint16_t  =  2 │ unsigned short     =  2 │
// │ xtd::uint32  =  4 │ std::uint32_t  =  4 │ unsigned int       =  4 │
// │ xtd::uint64  =  8 │ std::uint64_t  =  8 │ unsigned long      =  8 │
// │ xtd::uintptr =  8 │ std::uintptr_t =  8 │ unsigned long long =  8 │
// │ xtd::size    =  8 │ ------------------- │ size_t             =  8 │
// │ xtd::ptrdiff =  8 │ ------------------- │ ptrdiff_t          =  8 │
// └───────────────────┴─────────────────────┴─────────────────────────┘
