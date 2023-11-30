#include <xtd/console>
#include <xtd/parse>

using namespace std;
using namespace xtd;

auto main()->int {
  locale::global(locale {"en_US.UTF-8"}); // change to us for currency
  auto i1 = xtd::parse<int>("42");
  console::write_line(i1);
  auto i2 = xtd::parse<int>("+42.8", number_styles::number);
  console::write_line(i2);
  auto i3 = xtd::parse<int>("0x2A", number_styles::hex_number);
  console::write_line(i3);
  auto i4 = xtd::parse<int>("052", number_styles::octal_number);
  console::write_line(i4);
  auto i5 = xtd::parse<int>("0b00101010", number_styles::binary_number);
  console::write_line(i5);
  auto i6 = xtd::parse<int>("$42", number_styles::currency);
  console::write_line(i6);
  auto i7 = xtd::parse<int>("$42", number_styles::currency);
  console::write_line(i7);
  auto i8 = xtd::parse<int>("(42)", number_styles::number | number_styles::allow_parentheses);
  console::write_line(i8);
  try {
    auto i9 = xtd::parse<int>("Not number", number_styles::any);
    console::write_line(i9);
  } catch (const system_exception& e) {
    console::write_line("Exception : {}", e.message());
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
