#include <xtd/xtd>

using namespace xtd::globalization;

enum class cap {title, middle, end};

template<typename number_t>
auto print_floating_point(const string& text, number_t value, cap c) {
  if (c == cap::title)
    console::out
    << "┌─────────────────────────────────────┬────────────┬──────────────────────────────────────────────────────────────────┐" << environment::new_line
    << "│  floating_point                     │   format   │      representation                                              │" << environment::new_line
    << "├─────────────────────────────────────┼────────────┼──────────────────────────────────────────────────────────────────┤" << environment::new_line;
  
  console::out << "│ " << text.pad_right(35) << " │ {}         │ " << format("{}", value).pad_right(64) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(35) << " │ {:b}       │ " << format("{:b}", value).pad_right(64) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(35) << " │ {:B}       │ " << format("{:B}", value).pad_right(64) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(35) << " │ {:c}       │ " << format("{:c}", value).pad_right(64) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(35) << " │ {:C}       │ " << format("{:C}", value).pad_right(64) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(35) << " │ {:e}       │ " << format("{:e}", value).pad_right(64) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(35) << " │ {:E}       │ " << format("{:E}", value).pad_right(64) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(35) << " │ {:f}       │ " << format("{:f}", value).pad_right(64) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(35) << " │ {:F}       │ " << format("{:F}", value).pad_right(64) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(35) << " │ {:g}       │ " << format("{:g}", value).pad_right(64) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(35) << " │ {:G}       │ " << format("{:G}", value).pad_right(64) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(35) << " │ {:n}       │ " << format("{:n}", value).pad_right(64) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(35) << " │ {:N}       │ " << format("{:N}", value).pad_right(64) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(35) << " │ {:p}       │ " << format("{:p}", value).pad_right(64) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(35) << " │ {:P}       │ " << format("{:P}", value).pad_right(64) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(35) << " │ {:x}       │ " << format("{:x}", value).pad_right(64) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(35) << " │ {:X}       │ " << format("{:X}", value).pad_right(64) << " │" << environment::new_line;

  if (c != cap::end)
    console::out << "├─────────────────────────────────────┼────────────┼──────────────────────────────────────────────────────────────────┤" << environment::new_line;
  else
    console::out << "└─────────────────────────────────────┴────────────┴──────────────────────────────────────────────────────────────────┘" << environment::new_line;
}

auto main() -> int {
  culture_info::current_culture(culture_info {"en-US"}); // change to us for currency
  print_floating_point(".0", .0, cap::title);
  print_floating_point("12.345f", 12.345f, cap::middle);
  print_floating_point("3.1415e-4", 3.1415e-4, cap::middle);
  print_floating_point("double_object::positive_infinity", double_object::positive_infinity, cap::middle);
  print_floating_point("single_object::negative_infinity", single_object::negative_infinity, cap::middle);
  print_floating_point("double_object::NaN", double_object::NaN, cap::middle);
  print_floating_point("single_object::min_value", single_object::min_value, cap::middle);
  print_floating_point("double_object::max_value", double_object::max_value, cap::end);
}

// This code produces the following output :
//
// ┌─────────────────────────────────────┬────────────┬──────────────────────────────────────────────────────────────────┐
// │  floating_point                     │   format   │      representation                                              │
// ├─────────────────────────────────────┼────────────┼──────────────────────────────────────────────────────────────────┤
// │ .0                                  │ {}         │ 0                                                                │
// │ .0                                  │ {:b}       │ 0                                                                │
// │ .0                                  │ {:B}       │ 0                                                                │
// │ .0                                  │ {:c}       │ $0.00                                                            │
// │ .0                                  │ {:C}       │ $0.00                                                            │
// │ .0                                  │ {:e}       │ 0.000000e+00                                                     │
// │ .0                                  │ {:E}       │ 0.000000E+00                                                     │
// │ .0                                  │ {:f}       │ 0.00                                                             │
// │ .0                                  │ {:F}       │ 0.00                                                             │
// │ .0                                  │ {:g}       │ 0                                                                │
// │ .0                                  │ {:G}       │ 0                                                                │
// │ .0                                  │ {:n}       │ 0.00                                                             │
// │ .0                                  │ {:N}       │ 0.00                                                             │
// │ .0                                  │ {:p}       │ 0.00 %                                                           │
// │ .0                                  │ {:P}       │ 0.00 %                                                           │
// │ .0                                  │ {:x}       │ 0x0p+0                                                           │
// │ .0                                  │ {:X}       │ 0x0p+0                                                           │
// ├─────────────────────────────────────┼────────────┼──────────────────────────────────────────────────────────────────┤
// │ 12.345f                             │ {}         │ 12.345                                                           │
// │ 12.345f                             │ {:b}       │ 1000001010001011000010100011111                                  │
// │ 12.345f                             │ {:B}       │ 1000001010001011000010100011111                                  │
// │ 12.345f                             │ {:c}       │ $12.35                                                           │
// │ 12.345f                             │ {:C}       │ $12.35                                                           │
// │ 12.345f                             │ {:e}       │ 1.234500e+01                                                     │
// │ 12.345f                             │ {:E}       │ 1.234500E+01                                                     │
// │ 12.345f                             │ {:f}       │ 12.35                                                            │
// │ 12.345f                             │ {:F}       │ 12.35                                                            │
// │ 12.345f                             │ {:g}       │ 12.345                                                           │
// │ 12.345f                             │ {:G}       │ 12.345                                                           │
// │ 12.345f                             │ {:n}       │ 12.35                                                            │
// │ 12.345f                             │ {:N}       │ 12.35                                                            │
// │ 12.345f                             │ {:p}       │ 1234.50 %                                                        │
// │ 12.345f                             │ {:P}       │ 1234.50 %                                                        │
// │ 12.345f                             │ {:x}       │ 0x1.8b0a3ep+3                                                    │
// │ 12.345f                             │ {:X}       │ 0x1.8b0a3ep+3                                                    │
// ├─────────────────────────────────────┼────────────┼──────────────────────────────────────────────────────────────────┤
// │ 3.1415e-4                           │ {}         │ 0.00031415                                                       │
// │ 3.1415e-4                           │ {:b}       │ 11111100110100100101101000111111111001110111011010011100010000   │
// │ 3.1415e-4                           │ {:B}       │ 11111100110100100101101000111111111001110111011010011100010000   │
// │ 3.1415e-4                           │ {:c}       │ $0.00                                                            │
// │ 3.1415e-4                           │ {:C}       │ $0.00                                                            │
// │ 3.1415e-4                           │ {:e}       │ 3.141500e-04                                                     │
// │ 3.1415e-4                           │ {:E}       │ 3.141500E-04                                                     │
// │ 3.1415e-4                           │ {:f}       │ 0.00                                                             │
// │ 3.1415e-4                           │ {:F}       │ 0.00                                                             │
// │ 3.1415e-4                           │ {:g}       │ 0.00031415                                                       │
// │ 3.1415e-4                           │ {:G}       │ 0.00031415                                                       │
// │ 3.1415e-4                           │ {:n}       │ 0.00                                                             │
// │ 3.1415e-4                           │ {:N}       │ 0.00                                                             │
// │ 3.1415e-4                           │ {:p}       │ 0.03 %                                                           │
// │ 3.1415e-4                           │ {:P}       │ 0.03 %                                                           │
// │ 3.1415e-4                           │ {:x}       │ 0x1.4968ff9dda71p-12                                             │
// │ 3.1415e-4                           │ {:X}       │ 0x1.4968ff9dda71p-12                                             │
// ├─────────────────────────────────────┼────────────┼──────────────────────────────────────────────────────────────────┤
// │ double_object::positive_infinity    │ {}         │ inf                                                              │
// │ double_object::positive_infinity    │ {:b}       │ 111111111110000000000000000000000000000000000000000000000000000  │
// │ double_object::positive_infinity    │ {:B}       │ 111111111110000000000000000000000000000000000000000000000000000  │
// │ double_object::positive_infinity    │ {:c}       │ $0.00                                                            │
// │ double_object::positive_infinity    │ {:C}       │ $0.00                                                            │
// │ double_object::positive_infinity    │ {:e}       │ inf                                                              │
// │ double_object::positive_infinity    │ {:E}       │ inf                                                              │
// │ double_object::positive_infinity    │ {:f}       │ inf                                                              │
// │ double_object::positive_infinity    │ {:F}       │ inf                                                              │
// │ double_object::positive_infinity    │ {:g}       │ inf                                                              │
// │ double_object::positive_infinity    │ {:G}       │ inf                                                              │
// │ double_object::positive_infinity    │ {:n}       │ inf                                                              │
// │ double_object::positive_infinity    │ {:N}       │ inf                                                              │
// │ double_object::positive_infinity    │ {:p}       │ inf %                                                            │
// │ double_object::positive_infinity    │ {:P}       │ inf %                                                            │
// │ double_object::positive_infinity    │ {:x}       │ inf                                                              │
// │ double_object::positive_infinity    │ {:X}       │ inf                                                              │
// ├─────────────────────────────────────┼────────────┼──────────────────────────────────────────────────────────────────┤
// │ single_object::negative_infinity    │ {}         │ -inf                                                             │
// │ single_object::negative_infinity    │ {:b}       │ 11111111100000000000000000000000                                 │
// │ single_object::negative_infinity    │ {:B}       │ 11111111100000000000000000000000                                 │
// │ single_object::negative_infinity    │ {:c}       │ -$0.00                                                           │
// │ single_object::negative_infinity    │ {:C}       │ -$0.00                                                           │
// │ single_object::negative_infinity    │ {:e}       │ -inf                                                             │
// │ single_object::negative_infinity    │ {:E}       │ -inf                                                             │
// │ single_object::negative_infinity    │ {:f}       │ -inf                                                             │
// │ single_object::negative_infinity    │ {:F}       │ -inf                                                             │
// │ single_object::negative_infinity    │ {:g}       │ -inf                                                             │
// │ single_object::negative_infinity    │ {:G}       │ -inf                                                             │
// │ single_object::negative_infinity    │ {:n}       │ -inf                                                             │
// │ single_object::negative_infinity    │ {:N}       │ -inf                                                             │
// │ single_object::negative_infinity    │ {:p}       │ -inf %                                                           │
// │ single_object::negative_infinity    │ {:P}       │ -inf %                                                           │
// │ single_object::negative_infinity    │ {:x}       │ -inf                                                             │
// │ single_object::negative_infinity    │ {:X}       │ -inf                                                             │
// ├─────────────────────────────────────┼────────────┼──────────────────────────────────────────────────────────────────┤
// │ double_object::NaN                  │ {}         │ nan                                                              │
// │ double_object::NaN                  │ {:b}       │ 111111111111000000000000000000000000000000000000000000000000000  │
// │ double_object::NaN                  │ {:B}       │ 111111111111000000000000000000000000000000000000000000000000000  │
// │ double_object::NaN                  │ {:c}       │ $0.00                                                            │
// │ double_object::NaN                  │ {:C}       │ $0.00                                                            │
// │ double_object::NaN                  │ {:e}       │ nan                                                              │
// │ double_object::NaN                  │ {:E}       │ nan                                                              │
// │ double_object::NaN                  │ {:f}       │ nan                                                              │
// │ double_object::NaN                  │ {:F}       │ nan                                                              │
// │ double_object::NaN                  │ {:g}       │ nan                                                              │
// │ double_object::NaN                  │ {:G}       │ nan                                                              │
// │ double_object::NaN                  │ {:n}       │ nan                                                              │
// │ double_object::NaN                  │ {:N}       │ nan                                                              │
// │ double_object::NaN                  │ {:p}       │ nan %                                                            │
// │ double_object::NaN                  │ {:P}       │ nan %                                                            │
// │ double_object::NaN                  │ {:x}       │ nan                                                              │
// │ double_object::NaN                  │ {:X}       │ nan                                                              │
// ├─────────────────────────────────────┼────────────┼──────────────────────────────────────────────────────────────────┤
// │ single_object::min_value            │ {}         │ -3.402823E+38                                                    │
// │ single_object::min_value            │ {:b}       │ 11111111011111111111111111111111                                 │
// │ single_object::min_value            │ {:B}       │ 11111111011111111111111111111111                                 │
// │ single_object::min_value            │ {:c}       │ -$340,282,346,638,528,859,811,704,183,484,516,925,440.00         │
// │ single_object::min_value            │ {:C}       │ -$340,282,346,638,528,859,811,704,183,484,516,925,440.00         │
// │ single_object::min_value            │ {:e}       │ -3.402823e+38                                                    │
// │ single_object::min_value            │ {:E}       │ -3.402823E+38                                                    │
// │ single_object::min_value            │ {:f}       │ -340282346638528859811704183484516925440.00                      │
// │ single_object::min_value            │ {:F}       │ -340282346638528859811704183484516925440.00                      │
// │ single_object::min_value            │ {:g}       │ -3.402823e+38                                                    │
// │ single_object::min_value            │ {:G}       │ -3.402823E+38                                                    │
// │ single_object::min_value            │ {:n}       │ -340,282,346,638,528,859,811,704,183,484,516,925,440.00          │
// │ single_object::min_value            │ {:N}       │ -340,282,346,638,528,859,811,704,183,484,516,925,440.00          │
// │ single_object::min_value            │ {:p}       │ -inf %                                                           │
// │ single_object::min_value            │ {:P}       │ -inf %                                                           │
// │ single_object::min_value            │ {:x}       │ -0x1.fffffep+127                                                 │
// │ single_object::min_value            │ {:X}       │ -0x1.fffffep+127                                                 │
// ├─────────────────────────────────────┼────────────┼──────────────────────────────────────────────────────────────────┤
// │ double_object::max_value            │ {}         │ 1.79769313486232E+308                                            │
// │ double_object::max_value            │ {:b}       │ 111111111101111111111111111111111111111111111111111111111111111  │
// │ double_object::max_value            │ {:B}       │ 111111111101111111111111111111111111111111111111111111111111111  │
// │ double_object::max_value            │ {:c}       │ $0.00                                                            │
// │ double_object::max_value            │ {:C}       │ $0.00                                                            │
// │ double_object::max_value            │ {:e}       │ 1.797693e+308                                                    │
// │ double_object::max_value            │ {:E}       │ 1.797693E+308                                                    │
// │ double_object::max_value            │ {:f}       │ 179769313486231570814527423731704356798070567525844996598... .00 │
// │ double_object::max_value            │ {:F}       │ 179769313486231570814527423731704356798070567525844996598... .00 │
// │ double_object::max_value            │ {:g}       │ 1.79769313486232e+308                                            │
// │ double_object::max_value            │ {:G}       │ 1.79769313486232E+308                                            │
// │ double_object::max_value            │ {:n}       │ 179,769,313,486,231,570,814,527,423,731,704,356,798,070,... .00  │
// │ double_object::max_value            │ {:N}       │ 179,769,313,486,231,570,814,527,423,731,704,356,798,070,... .00  │
// │ double_object::max_value            │ {:p}       │ inf %                                                            │
// │ double_object::max_value            │ {:P}       │ inf %                                                            │
// │ double_object::max_value            │ {:x}       │ 0x1.fffffffffffffp+1023                                          │
// │ double_object::max_value            │ {:X}       │ 0x1.fffffffffffffp+1023                                          │
// └─────────────────────────────────────┴────────────┴──────────────────────────────────────────────────────────────────┘
