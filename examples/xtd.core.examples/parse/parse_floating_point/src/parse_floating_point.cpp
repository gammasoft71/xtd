#include <xtd/xtd>

using namespace std;
using namespace xtd;

auto main()->int {
  locale::global(locale("en_US.UTF-8")); // change to us for currency
  double d1 = xtd::parse<double>("12.345");
  console::write_line(d1);
  double d2 = xtd::parse<double>("$12.345", number_styles::currency);
  console::write_line(d2);
  double d3 = xtd::parse<double>("1.234500e+01", number_styles::number | number_styles::allow_exponent);
  console::write_line(d3);
  double d4 = xtd::parse<double>("inf");
  console::write_line(d4);
  double d5 = xtd::parse<double>("-inf");
  console::write_line(d5);
  double d6 = xtd::parse<double>("nan");
  console::write_line(d6);
  try {
    double d7 = xtd::parse<int>("Not floating point", number_styles::any);
    console::write_line(d7);
  } catch (const exception& e) {
    console::write_line("Exception : {}", e.what());
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
