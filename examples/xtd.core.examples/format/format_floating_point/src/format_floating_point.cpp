#include <xtd/console>
#include <xtd/double_object>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  std::locale::global(std::locale {"en_US.UTF-8"}); // change to us for currency
  console::out << ustring::format("{}", 12.345) << environment::new_line;
  console::out << ustring::format("{:c}", 12.345) << environment::new_line;
  console::out << ustring::format("{:C}", 12.345) << environment::new_line;
  console::out << ustring::format("{:e}", 12.345) << environment::new_line;
  console::out << ustring::format("{:E}", 12.345) << environment::new_line;
  console::out << ustring::format("{:f}", 12.345) << environment::new_line;
  console::out << ustring::format("{:F}", 12.345) << environment::new_line;
  console::out << ustring::format("{:g}", 12.345) << environment::new_line;
  console::out << ustring::format("{:G}", 12.345) << environment::new_line;
  console::out << ustring::format("{:n}", 12.345) << environment::new_line;
  console::out << ustring::format("{:N}", 12.345) << environment::new_line;
  console::out << ustring::format("{:p}", .0012345) << environment::new_line;
  console::out << ustring::format("{:P}", .0012345) << environment::new_line;
  console::out << ustring::format("{}", double_object::positive_infinity) << environment::new_line;
  console::out << ustring::format("{}", double_object::negative_infinity) << environment::new_line;
  console::out << ustring::format("{}", double_object::NaN) << environment::new_line;
  console::out << ustring::format("{}", std::numeric_limits<double>::signaling_NaN()) << environment::new_line;
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
