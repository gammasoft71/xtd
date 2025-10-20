#include <xtd/xtd>

using namespace xtd::globalization;

enum class cap {title, middle, end};

template<typename number_t>
auto print_number(const string& text, number_t value, cap c) {
  if (c == cap::title)
    console::out
    << "┌───────────────────────────┬────────────┬──────────────────────────────────┐" << environment::new_line
    << "│  number                   │   format   │      representation              │" << environment::new_line
    << "├───────────────────────────┼────────────┼──────────────────────────────────┤" << environment::new_line;
  
  console::out << "│ " << text.pad_right(25) << " │ {}         │ " << format("{}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:b}       │ " << format("{:b}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:b32}     │ " << format("{:b32}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:B}       │ " << format("{:B}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:B32}     │ " << format("{:B32}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:c}       │ " << format("{:c}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:C}       │ " << format("{:C}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:d}       │ " << format("{:d}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:d16}     │ " << format("{:d16}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:D}       │ " << format("{:D}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:D16}     │ " << format("{:D16}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:e}       │ " << format("{:e}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:E}       │ " << format("{:E}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:f}       │ " << format("{:f}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:f4}      │ " << format("{:f4}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:F}       │ " << format("{:F}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:F4}      │ " << format("{:F4}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:g}       │ " << format("{:g}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:G}       │ " << format("{:G}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:o}       │ " << format("{:o}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:o16}     │ " << format("{:o16}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:O}       │ " << format("{:O}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:O16}     │ " << format("{:O16}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:n}       │ " << format("{:n}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:N}       │ " << format("{:N}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:p}       │ " << format("{:p}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:P}       │ " << format("{:P}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:x}       │ " << format("{:x}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:x16}     │ " << format("{:x16}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:X}       │ " << format("{:X}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(25) << " │ {:X16}     │ " << format("{:X16}", value).pad_right(32) << " │" << environment::new_line;

  if (c != cap::end)
    console::out << "├───────────────────────────┼────────────┼──────────────────────────────────┤" << environment::new_line;
  else
    console::out << "└───────────────────────────┴────────────┴──────────────────────────────────┘" << environment::new_line;
}

auto main() -> int {
  culture_info::current_culture(culture_info {"en-US"}); // change to us for currency
  print_number("0", 0, cap::title);
  print_number("42_s8", 42_s8, cap::middle);
  print_number("123456789ull", 123456789ull, cap::middle);
  print_number("int16_object::min_value", int16_object::min_value, cap::middle);
  print_number("int32_object::max_value", int32_object::max_value, cap::end);
}

// This code produces the following output :
//
// ┌───────────────────────────┬────────────┬──────────────────────────────────┐
// │  number                   │   format   │      representation              │
// ├───────────────────────────┼────────────┼──────────────────────────────────┤
// │ 0                         │ {}         │ 0                                │
// │ 0                         │ {:b}       │ 0                                │
// │ 0                         │ {:b32}     │ 00000000000000000000000000000000 │
// │ 0                         │ {:B}       │ 0                                │
// │ 0                         │ {:B32}     │ 00000000000000000000000000000000 │
// │ 0                         │ {:c}       │ $0.00                            │
// │ 0                         │ {:C}       │ $0.00                            │
// │ 0                         │ {:d}       │ 0                                │
// │ 0                         │ {:d16}     │ 0000000000000000                 │
// │ 0                         │ {:D}       │ 0                                │
// │ 0                         │ {:D16}     │ 0000000000000000                 │
// │ 0                         │ {:e}       │ 0.000000e+00                     │
// │ 0                         │ {:E}       │ 0.000000E+00                     │
// │ 0                         │ {:f}       │ 0.00                             │
// │ 0                         │ {:f4}      │ 0.0000                           │
// │ 0                         │ {:F}       │ 0.00                             │
// │ 0                         │ {:F4}      │ 0.0000                           │
// │ 0                         │ {:g}       │ 0                                │
// │ 0                         │ {:G}       │ 0                                │
// │ 0                         │ {:o}       │ 0                                │
// │ 0                         │ {:o16}     │ 0000000000000000                 │
// │ 0                         │ {:O}       │ 0                                │
// │ 0                         │ {:O16}     │ 0000000000000000                 │
// │ 0                         │ {:n}       │ 0.00                             │
// │ 0                         │ {:N}       │ 0.00                             │
// │ 0                         │ {:p}       │ 0.00 %                           │
// │ 0                         │ {:P}       │ 0.00 %                           │
// │ 0                         │ {:x}       │ 0                                │
// │ 0                         │ {:x16}     │ 0000000000000000                 │
// │ 0                         │ {:X}       │ 0                                │
// │ 0                         │ {:X16}     │ 0000000000000000                 │
// ├───────────────────────────┼────────────┼──────────────────────────────────┤
// │ 42_s8                     │ {}         │ 42                               │
// │ 42_s8                     │ {:b}       │ 101010                           │
// │ 42_s8                     │ {:b32}     │ 00000000000000000000000000101010 │
// │ 42_s8                     │ {:B}       │ 101010                           │
// │ 42_s8                     │ {:B32}     │ 00000000000000000000000000101010 │
// │ 42_s8                     │ {:c}       │ $42.00                           │
// │ 42_s8                     │ {:C}       │ $42.00                           │
// │ 42_s8                     │ {:d}       │ 42                               │
// │ 42_s8                     │ {:d16}     │ 0000000000000042                 │
// │ 42_s8                     │ {:D}       │ 42                               │
// │ 42_s8                     │ {:D16}     │ 0000000000000042                 │
// │ 42_s8                     │ {:e}       │ 4.200000e+01                     │
// │ 42_s8                     │ {:E}       │ 4.200000E+01                     │
// │ 42_s8                     │ {:f}       │ 42.00                            │
// │ 42_s8                     │ {:f4}      │ 42.0000                          │
// │ 42_s8                     │ {:F}       │ 42.00                            │
// │ 42_s8                     │ {:F4}      │ 42.0000                          │
// │ 42_s8                     │ {:g}       │ 42                               │
// │ 42_s8                     │ {:G}       │ 42                               │
// │ 42_s8                     │ {:o}       │ 52                               │
// │ 42_s8                     │ {:o16}     │ 0000000000000052                 │
// │ 42_s8                     │ {:O}       │ 52                               │
// │ 42_s8                     │ {:O16}     │ 0000000000000052                 │
// │ 42_s8                     │ {:n}       │ 42.00                            │
// │ 42_s8                     │ {:N}       │ 42.00                            │
// │ 42_s8                     │ {:p}       │ 4200.00 %                        │
// │ 42_s8                     │ {:P}       │ 4200.00 %                        │
// │ 42_s8                     │ {:x}       │ 2a                               │
// │ 42_s8                     │ {:x16}     │ 000000000000002a                 │
// │ 42_s8                     │ {:X}       │ 2A                               │
// │ 42_s8                     │ {:X16}     │ 000000000000002A                 │
// ├───────────────────────────┼────────────┼──────────────────────────────────┤
// │ 123456789ull              │ {}         │ 123456789                        │
// │ 123456789ull              │ {:b}       │ 111010110111100110100010101      │
// │ 123456789ull              │ {:b32}     │ 00000111010110111100110100010101 │
// │ 123456789ull              │ {:B}       │ 111010110111100110100010101      │
// │ 123456789ull              │ {:B32}     │ 00000111010110111100110100010101 │
// │ 123456789ull              │ {:c}       │ $123,456,789.00                  │
// │ 123456789ull              │ {:C}       │ $123,456,789.00                  │
// │ 123456789ull              │ {:d}       │ 123456789                        │
// │ 123456789ull              │ {:d16}     │ 0000000123456789                 │
// │ 123456789ull              │ {:D}       │ 123456789                        │
// │ 123456789ull              │ {:D16}     │ 0000000123456789                 │
// │ 123456789ull              │ {:e}       │ 1.234568e+08                     │
// │ 123456789ull              │ {:E}       │ 1.234568E+08                     │
// │ 123456789ull              │ {:f}       │ 123456789.00                     │
// │ 123456789ull              │ {:f4}      │ 123456789.0000                   │
// │ 123456789ull              │ {:F}       │ 123456789.00                     │
// │ 123456789ull              │ {:F4}      │ 123456789.0000                   │
// │ 123456789ull              │ {:g}       │ 123456789                        │
// │ 123456789ull              │ {:G}       │ 123456789                        │
// │ 123456789ull              │ {:o}       │ 726746425                        │
// │ 123456789ull              │ {:o16}     │ 0000000726746425                 │
// │ 123456789ull              │ {:O}       │ 726746425                        │
// │ 123456789ull              │ {:O16}     │ 0000000726746425                 │
// │ 123456789ull              │ {:n}       │ 123,456,789.00                   │
// │ 123456789ull              │ {:N}       │ 123,456,789.00                   │
// │ 123456789ull              │ {:p}       │ 12345678900.00 %                 │
// │ 123456789ull              │ {:P}       │ 12345678900.00 %                 │
// │ 123456789ull              │ {:x}       │ 75bcd15                          │
// │ 123456789ull              │ {:x16}     │ 00000000075bcd15                 │
// │ 123456789ull              │ {:X}       │ 75BCD15                          │
// │ 123456789ull              │ {:X16}     │ 00000000075BCD15                 │
// ├───────────────────────────┼────────────┼──────────────────────────────────┤
// │ int16_object::min_value   │ {}         │ -32768                           │
// │ int16_object::min_value   │ {:b}       │ 1000000000000000                 │
// │ int16_object::min_value   │ {:b32}     │ 00000000000000001000000000000000 │
// │ int16_object::min_value   │ {:B}       │ 1000000000000000                 │
// │ int16_object::min_value   │ {:B32}     │ 00000000000000001000000000000000 │
// │ int16_object::min_value   │ {:c}       │ -$32,768.00                      │
// │ int16_object::min_value   │ {:C}       │ -$32,768.00                      │
// │ int16_object::min_value   │ {:d}       │ -32768                           │
// │ int16_object::min_value   │ {:d16}     │ -0000000000032768                │
// │ int16_object::min_value   │ {:D}       │ -32768                           │
// │ int16_object::min_value   │ {:D16}     │ -0000000000032768                │
// │ int16_object::min_value   │ {:e}       │ -3.276800e+04                    │
// │ int16_object::min_value   │ {:E}       │ -3.276800E+04                    │
// │ int16_object::min_value   │ {:f}       │ -32768.00                        │
// │ int16_object::min_value   │ {:f4}      │ -32768.0000                      │
// │ int16_object::min_value   │ {:F}       │ -32768.00                        │
// │ int16_object::min_value   │ {:F4}      │ -32768.0000                      │
// │ int16_object::min_value   │ {:g}       │ -32768                           │
// │ int16_object::min_value   │ {:G}       │ -32768                           │
// │ int16_object::min_value   │ {:o}       │ 1777777777777777700000           │
// │ int16_object::min_value   │ {:o16}     │ 1777777777777777700000           │
// │ int16_object::min_value   │ {:O}       │ 1777777777777777700000           │
// │ int16_object::min_value   │ {:O16}     │ 1777777777777777700000           │
// │ int16_object::min_value   │ {:n}       │ -32,768.00                       │
// │ int16_object::min_value   │ {:N}       │ -32,768.00                       │
// │ int16_object::min_value   │ {:p}       │ -3276800.00 %                    │
// │ int16_object::min_value   │ {:P}       │ -3276800.00 %                    │
// │ int16_object::min_value   │ {:x}       │ ffffffffffff8000                 │
// │ int16_object::min_value   │ {:x16}     │ ffffffffffff8000                 │
// │ int16_object::min_value   │ {:X}       │ FFFFFFFFFFFF8000                 │
// │ int16_object::min_value   │ {:X16}     │ FFFFFFFFFFFF8000                 │
// ├───────────────────────────┼────────────┼──────────────────────────────────┤
// │ int32_object::max_value   │ {}         │ 2147483647                       │
// │ int32_object::max_value   │ {:b}       │ 1111111111111111111111111111111  │
// │ int32_object::max_value   │ {:b32}     │ 01111111111111111111111111111111 │
// │ int32_object::max_value   │ {:B}       │ 1111111111111111111111111111111  │
// │ int32_object::max_value   │ {:B32}     │ 01111111111111111111111111111111 │
// │ int32_object::max_value   │ {:c}       │ $2,147,483,647.00                │
// │ int32_object::max_value   │ {:C}       │ $2,147,483,647.00                │
// │ int32_object::max_value   │ {:d}       │ 2147483647                       │
// │ int32_object::max_value   │ {:d16}     │ 0000002147483647                 │
// │ int32_object::max_value   │ {:D}       │ 2147483647                       │
// │ int32_object::max_value   │ {:D16}     │ 0000002147483647                 │
// │ int32_object::max_value   │ {:e}       │ 2.147484e+09                     │
// │ int32_object::max_value   │ {:E}       │ 2.147484E+09                     │
// │ int32_object::max_value   │ {:f}       │ 2147483647.00                    │
// │ int32_object::max_value   │ {:f4}      │ 2147483647.0000                  │
// │ int32_object::max_value   │ {:F}       │ 2147483647.00                    │
// │ int32_object::max_value   │ {:F4}      │ 2147483647.0000                  │
// │ int32_object::max_value   │ {:g}       │ 2147483647                       │
// │ int32_object::max_value   │ {:G}       │ 2147483647                       │
// │ int32_object::max_value   │ {:o}       │ 17777777777                      │
// │ int32_object::max_value   │ {:o16}     │ 0000017777777777                 │
// │ int32_object::max_value   │ {:O}       │ 17777777777                      │
// │ int32_object::max_value   │ {:O16}     │ 0000017777777777                 │
// │ int32_object::max_value   │ {:n}       │ 2,147,483,647.00                 │
// │ int32_object::max_value   │ {:N}       │ 2,147,483,647.00                 │
// │ int32_object::max_value   │ {:p}       │ 214748364700.00 %                │
// │ int32_object::max_value   │ {:P}       │ 214748364700.00 %                │
// │ int32_object::max_value   │ {:x}       │ 7fffffff                         │
// │ int32_object::max_value   │ {:x16}     │ 000000007fffffff                 │
// │ int32_object::max_value   │ {:X}       │ 7FFFFFFF                         │
// │ int32_object::max_value   │ {:X16}     │ 000000007FFFFFFF                 │
// └───────────────────────────┴────────────┴──────────────────────────────────┘
