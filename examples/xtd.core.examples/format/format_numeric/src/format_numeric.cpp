#include <xtd/console>
#include <xtd/ustring>

using namespace std;
using namespace xtd;

enum class cap { title, middle, end };

void print_number(const char* text, int number, cap c) {
  if (c == cap::title) {
    console::write_line("┌───────────┬────────────┬──────────────────────────────────┐");
    console::write_line("│  number   │   format   │      representation              │");
    console::write_line("├───────────┼────────────┼──────────────────────────────────┤");
  }
  
  console::write_line("│ {,-9} │ {{}}         │ {,-32} │", text, ustring::format("{}", number));
  console::write_line("│ {,-9} │ {{:b}}       │ {,-32} │", text, ustring::format("{:b}", number));
  console::write_line("│ {,-9} │ {{:b32}}     │ {,-32} │", text, ustring::format("{:b32}", number));
  console::write_line("│ {,-9} │ {{:c}}       │ {,-32} │", text, ustring::format("{:c}", number));
  console::write_line("│ {,-9} │ {{:C}}       │ {,-32} │", text, ustring::format("{:C}", number));
  console::write_line("│ {,-9} │ {{:d}}       │ {,-32} │", text, ustring::format("{:d}", number));
  console::write_line("│ {,-9} │ {{:d16}}     │ {,-32} │", text, ustring::format("{:d16}", number));
  console::write_line("│ {,-9} │ {{:D}}       │ {,-32} │", text, ustring::format("{:D}", number));
  console::write_line("│ {,-9} │ {{:D16}}     │ {,-32} │", text, ustring::format("{:D16}", number));
  console::write_line("│ {,-9} │ {{:e}}       │ {,-32} │", text, ustring::format("{:e}", number));
  console::write_line("│ {,-9} │ {{:E}}       │ {,-32} │", text, ustring::format("{:E}", number));
  console::write_line("│ {,-9} │ {{:f}}       │ {,-32} │", text, ustring::format("{:f}", number));
  console::write_line("│ {,-9} │ {{:f4}}      │ {,-32} │", text, ustring::format("{:f4}", number));
  console::write_line("│ {,-9} │ {{:F}}       │ {,-32} │", text, ustring::format("{:F}", number));
  console::write_line("│ {,-9} │ {{:F4}}      │ {,-32} │", text, ustring::format("{:F4}", number));
  console::write_line("│ {,-9} │ {{:g}}       │ {,-32} │", text, ustring::format("{:g}", number));
  console::write_line("│ {,-9} │ {{:G}}       │ {,-32} │", text, ustring::format("{:G}", number));
  console::write_line("│ {,-9} │ {{:o}}       │ {,-32} │", text, ustring::format("{:o}", number));
  console::write_line("│ {,-9} │ {{:o16}}     │ {,-32} │", text, ustring::format("{:o16}", number));
  console::write_line("│ {,-9} │ {{:O}}       │ {,-32} │", text, ustring::format("{:O}", number));
  console::write_line("│ {,-9} │ {{:O16}}     │ {,-32} │", text, ustring::format("{:O16}", number));
  console::write_line("│ {,-9} │ {{:n}}       │ {,-32} │", text, ustring::format("{:n}", number));
  console::write_line("│ {,-9} │ {{:N}}       │ {,-32} │", text, ustring::format("{:N}", number));
  console::write_line("│ {,-9} │ {{:p}}       │ {,-32} │", text, ustring::format("{:p}", number));
  console::write_line("│ {,-9} │ {{:P}}       │ {,-32} │", text, ustring::format("{:P}", number));
  console::write_line("│ {,-9} │ {{:x}}       │ {,-32} │", text, ustring::format("{:x}", number));
  console::write_line("│ {,-9} │ {{:x16}}     │ {,-32} │", text, ustring::format("{:x16}", number));
  console::write_line("│ {,-9} │ {{:X}}       │ {,-32} │", text, ustring::format("{:X}", number));
  console::write_line("│ {,-9} │ {{:X16}}     │ {,-32} │", text, ustring::format("{:X16}", number));

  if (c != cap::end)
    console::write_line("├───────────┼────────────┼──────────────────────────────────┤");
  else
    console::write_line("└───────────┴────────────┴──────────────────────────────────┘");
}


auto main() -> int {
  locale::global(locale {"en_US.UTF-8"}); // change to us for currency
  print_number("0", 0, cap::title);
  print_number("42", 42, cap::middle);
  print_number("123456789", 123456789, cap::end);
}

// This code produces the following output :
//
// ┌───────────┬────────────┬──────────────────────────────────┐
// │  number   │   format   │      representation              │
// ├───────────┼────────────┼──────────────────────────────────┤
// │ 0         │ {}         │ 0                                │
// │ 0         │ {:b}       │ 0                                │
// │ 0         │ {:b32}     │ 00000000000000000000000000000000 │
// │ 0         │ {:c}       │ $0.00                            │
// │ 0         │ {:C}       │ $0.00                            │
// │ 0         │ {:d}       │ 0                                │
// │ 0         │ {:d16}     │ 0000000000000000                 │
// │ 0         │ {:D}       │ 0                                │
// │ 0         │ {:D16}     │ 0000000000000000                 │
// │ 0         │ {:e}       │ 0.000000e+00                     │
// │ 0         │ {:E}       │ 0.000000E+00                     │
// │ 0         │ {:f}       │ 0.00                             │
// │ 0         │ {:f4}      │ 0.0000                           │
// │ 0         │ {:F}       │ 0.00                             │
// │ 0         │ {:F4}      │ 0.0000                           │
// │ 0         │ {:g}       │ 0                                │
// │ 0         │ {:G}       │ 0                                │
// │ 0         │ {:o}       │ 0                                │
// │ 0         │ {:o16}     │ 0000000000000000                 │
// │ 0         │ {:O}       │ 0                                │
// │ 0         │ {:O16}     │ 0000000000000000                 │
// │ 0         │ {:n}       │ 0.00                             │
// │ 0         │ {:N}       │ 0.00                             │
// │ 0         │ {:p}       │ 0.00 %                           │
// │ 0         │ {:P}       │ 0.00 %                           │
// │ 0         │ {:x}       │ 0                                │
// │ 0         │ {:x16}     │ 0000000000000000                 │
// │ 0         │ {:X}       │ 0                                │
// │ 0         │ {:X16}     │ 0000000000000000                 │
// ├───────────┼────────────┼──────────────────────────────────┤
// │ 42        │ {}         │ 42                               │
// │ 42        │ {:b}       │ 101010                           │
// │ 42        │ {:b32}     │ 00000000000000000000000000101010 │
// │ 42        │ {:c}       │ $42.00                           │
// │ 42        │ {:C}       │ $42.00                           │
// │ 42        │ {:d}       │ 42                               │
// │ 42        │ {:d16}     │ 0000000000000042                 │
// │ 42        │ {:D}       │ 42                               │
// │ 42        │ {:D16}     │ 0000000000000042                 │
// │ 42        │ {:e}       │ 4.200000e+01                     │
// │ 42        │ {:E}       │ 4.200000E+01                     │
// │ 42        │ {:f}       │ 42.00                            │
// │ 42        │ {:f4}      │ 42.0000                          │
// │ 42        │ {:F}       │ 42.00                            │
// │ 42        │ {:F4}      │ 42.0000                          │
// │ 42        │ {:g}       │ 42                               │
// │ 42        │ {:G}       │ 42                               │
// │ 42        │ {:o}       │ 52                               │
// │ 42        │ {:o16}     │ 0000000000000052                 │
// │ 42        │ {:O}       │ 52                               │
// │ 42        │ {:O16}     │ 0000000000000052                 │
// │ 42        │ {:n}       │ 42.00                            │
// │ 42        │ {:N}       │ 42.00                            │
// │ 42        │ {:p}       │ 4200.00 %                        │
// │ 42        │ {:P}       │ 4200.00 %                        │
// │ 42        │ {:x}       │ 2a                               │
// │ 42        │ {:x16}     │ 000000000000002a                 │
// │ 42        │ {:X}       │ 2A                               │
// │ 42        │ {:X16}     │ 000000000000002A                 │
// ├───────────┼────────────┼──────────────────────────────────┤
// │ 123456789 │ {}         │ 123456789                        │
// │ 123456789 │ {:b}       │ 111010110111100110100010101      │
// │ 123456789 │ {:b32}     │ 00000111010110111100110100010101 │
// │ 123456789 │ {:c}       │ $123,456,789.00                  │
// │ 123456789 │ {:C}       │ $123,456,789.00                  │
// │ 123456789 │ {:d}       │ 123456789                        │
// │ 123456789 │ {:d16}     │ 0000000123456789                 │
// │ 123456789 │ {:D}       │ 123456789                        │
// │ 123456789 │ {:D16}     │ 0000000123456789                 │
// │ 123456789 │ {:e}       │ 1.234568e+08                     │
// │ 123456789 │ {:E}       │ 1.234568E+08                     │
// │ 123456789 │ {:f}       │ 123456789.00                     │
// │ 123456789 │ {:f4}      │ 123456789.0000                   │
// │ 123456789 │ {:F}       │ 123456789.00                     │
// │ 123456789 │ {:F4}      │ 123456789.0000                   │
// │ 123456789 │ {:g}       │ 123456789                        │
// │ 123456789 │ {:G}       │ 123456789                        │
// │ 123456789 │ {:o}       │ 726746425                        │
// │ 123456789 │ {:o16}     │ 0000000726746425                 │
// │ 123456789 │ {:O}       │ 726746425                        │
// │ 123456789 │ {:O16}     │ 0000000726746425                 │
// │ 123456789 │ {:n}       │ 123,456,789.00                   │
// │ 123456789 │ {:N}       │ 123,456,789.00                   │
// │ 123456789 │ {:p}       │ 12345678900.00 %                 │
// │ 123456789 │ {:P}       │ 12345678900.00 %                 │
// │ 123456789 │ {:x}       │ 75bcd15                          │
// │ 123456789 │ {:x16}     │ 00000000075bcd15                 │
// │ 123456789 │ {:X}       │ 75BCD15                          │
// │ 123456789 │ {:X16}     │ 00000000075BCD15                 │
// └───────────┴────────────┴──────────────────────────────────┘
