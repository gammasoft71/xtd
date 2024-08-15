#include <xtd/console>
#include <xtd/double_object>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  std::locale::global(std::locale {"en_US.UTF-8"}); // change to us for currency
  console::out << string::format("{}", 12.345) << environment::new_line;
  console::out << string::format("{:c}", 12.345) << environment::new_line;
  console::out << string::format("{:C}", 12.345) << environment::new_line;
  console::out << string::format("{:e}", 12.345) << environment::new_line;
  console::out << string::format("{:E}", 12.345) << environment::new_line;
  console::out << string::format("{:f}", 12.345) << environment::new_line;
  console::out << string::format("{:F}", 12.345) << environment::new_line;
  console::out << string::format("{:g}", 12.345) << environment::new_line;
  console::out << string::format("{:G}", 12.345) << environment::new_line;
  console::out << string::format("{:n}", 12.345) << environment::new_line;
  console::out << string::format("{:N}", 12.345) << environment::new_line;
  console::out << string::format("{:p}", .0012345) << environment::new_line;
  console::out << string::format("{:P}", .0012345) << environment::new_line;
  console::out << string::format("{}", double_object::positive_infinity) << environment::new_line;
  console::out << string::format("{}", double_object::negative_infinity) << environment::new_line;
  console::out << string::format("{}", double_object::NaN) << environment::new_line;
  console::out << string::format("{}", std::numeric_limits<double>::signaling_NaN()) << environment::new_line;
}

// This code produces the following output :
//
// 12.345
// $12.35
// $12.35
// 1.234500e+01
// 1.234500E+01
// 12.35
// 12.35
// 12.345
// 12.345
// 12.35
// 12.35
// 0.12 %
// 0.12 %
// inf
// -inf
// nan
// nan
