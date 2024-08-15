#include <xtd/console>
#include <xtd/environment>
#include <xtd/double_object>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  console::out << string::sprintf("%f", 12.345) << environment::new_line;
  console::out << string::sprintf("%F", 12.345) << environment::new_line;
  console::out << string::sprintf("%e", 12.345) << environment::new_line;
  console::out << string::sprintf("%E", 12.345) << environment::new_line;
  console::out << string::sprintf("%g", 12.345) << environment::new_line;
  console::out << string::sprintf("%G", 12.345) << environment::new_line;
  console::out << string::sprintf("0x%a", 12.345) << environment::new_line;
  console::out << string::sprintf("0x%A", 12.345) << environment::new_line;
  console::out << string::sprintf("%G", double_object::epsilon) << environment::new_line;
  console::out << string::sprintf("%f", double_object::NaN) << environment::new_line;
  console::out << string::sprintf("%f", double_object::positive_infinity) << environment::new_line;
  console::out << string::sprintf("%f", double_object::negative_infinity) << environment::new_line;
}

// This code produces the following output :
//
// 12.345000
// 12.345000
// 1.234500e+01
// 1.234500E+01
// 12.345
// 12.345
// 0x0x1.8b0a3d70a3d71p+3
// 0x0X1.8B0A3D70A3D71P+3
// 4.94066E-324
// nan
// inf
// -inf
