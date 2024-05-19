#include <xtd/console>
#include <xtd/parse>

using namespace std;
using namespace xtd;

auto main() -> int {
  locale::global(locale {"en_US.UTF-8"}); // change to us for currency
  auto d1 = xtd::parse<double>("12.345");
  console::write_line(d1);
  auto d2 = xtd::parse<double>("$12.345", number_styles::currency);
  console::write_line(d2);
  auto d3 = xtd::parse<double>("1.234500e+01", number_styles::number | number_styles::allow_exponent);
  console::write_line(d3);
  auto d4 = xtd::parse<double>("inf");
  console::write_line(d4);
  auto d5 = xtd::parse<double>("-inf");
  console::write_line(d5);
  auto d6 = xtd::parse<double>("nan");
  console::write_line(d6);
  try {
    auto d7 = xtd::parse<double>("Not floating point", number_styles::any);
    console::write_line(d7);
  } catch (const system_exception& e) {
    console::write_line("Exception : {}", e.message());
  }
}

// This code produces the following output :
//
// 2.345
// 12.345
// 12.345
// inf
// -inf
// nan
// Exception : invalid character found
