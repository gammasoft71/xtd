#include <xtd/xtd>

using namespace std;
using namespace xtd;

auto main()->int {
  locale::global(locale("en_US.UTF-8")); // change to us for currency
  int i1 = xtd::parse<int>("42");
  console::write_line(i1);
  int i2 = xtd::parse<int>("+42.8", number_styles::number);
  console::write_line(i2);
  int i3 = xtd::parse<int>("0x2A", number_styles::hex_number);
  console::write_line(i3);
  int i4 = xtd::parse<int>("052", number_styles::octal_number);
  console::write_line(i4);
  int i5 = xtd::parse<int>("0b00101010", number_styles::binary_number);
  console::write_line(i5);
  int i6 = xtd::parse<int>("$42", number_styles::currency);
  console::write_line(i6);
  int i7 = xtd::parse<int>("$42", number_styles::currency);
  console::write_line(i7);
  int i8 = xtd::parse<int>("(42)", number_styles::number | number_styles::allow_parentheses);
  console::write_line(i8);
  try {
    int i9 = xtd::parse<int>("Not number", number_styles::any);
    console::write_line(i9);
  } catch (const exception& e) {
    console::write_line("Exception : {}", e.what());
  }
}

// This code produces the following output :
//
// 42
// 42
// 42
// 42
// 42
// 42
// 42
// -42
// Exception : invalid character found
