#include <xtd/console>
#include <xtd/date_time>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  auto now = xtd::date_time::now();
  console::out << now << environment::new_line;
  console::out << date_time::sprintf("%Y", now) << environment::new_line;
  console::out << date_time::sprintf("%EY", now) << environment::new_line;
  console::out << date_time::sprintf("%y", now) << environment::new_line;
  console::out << date_time::sprintf("%0y", now) << environment::new_line;
  console::out << date_time::sprintf("%Ey", now) << environment::new_line;
  console::out << date_time::sprintf("%C", now) << environment::new_line;
  console::out << date_time::sprintf("%EC", now) << environment::new_line;
  console::out << date_time::sprintf("%G", now) << environment::new_line;
  console::out << date_time::sprintf("%g", now) << environment::new_line;
  console::out << date_time::sprintf("%b", now) << environment::new_line;
  console::out << date_time::sprintf("%h", now) << environment::new_line;
  console::out << date_time::sprintf("%B", now) << environment::new_line;
  console::out << date_time::sprintf("%m", now) << environment::new_line;
  console::out << date_time::sprintf("%0m", now) << environment::new_line;
  console::out << date_time::sprintf("%U", now) << environment::new_line;
  console::out << date_time::sprintf("%0U", now) << environment::new_line;
  console::out << date_time::sprintf("%W", now) << environment::new_line;
  console::out << date_time::sprintf("%0W", now) << environment::new_line;
  console::out << date_time::sprintf("%V", now) << environment::new_line;
  console::out << date_time::sprintf("%0V", now) << environment::new_line;
  console::out << date_time::sprintf("%j", now) << environment::new_line;
  console::out << date_time::sprintf("%d", now) << environment::new_line;
  console::out << date_time::sprintf("%0d", now) << environment::new_line;
  console::out << date_time::sprintf("%e", now) << environment::new_line;
  console::out << date_time::sprintf("%0e", now) << environment::new_line;
  console::out << date_time::sprintf("%a", now) << environment::new_line;
  console::out << date_time::sprintf("%A", now) << environment::new_line;
  console::out << date_time::sprintf("%w", now) << environment::new_line;
  console::out << date_time::sprintf("%0w", now) << environment::new_line;
  console::out << date_time::sprintf("%u", now) << environment::new_line;
  console::out << date_time::sprintf("%0u", now) << environment::new_line;
  console::out << date_time::sprintf("%H", now) << environment::new_line;
  console::out << date_time::sprintf("%0h", now) << environment::new_line;
  console::out << date_time::sprintf("%I", now) << environment::new_line;
  console::out << date_time::sprintf("%0I", now) << environment::new_line;
  console::out << date_time::sprintf("%M", now) << environment::new_line;
  console::out << date_time::sprintf("%0M", now) << environment::new_line;
  console::out << date_time::sprintf("%S", now) << environment::new_line;
  console::out << date_time::sprintf("%0S", now) << environment::new_line;
  console::out << date_time::sprintf("%c", now) << environment::new_line;
  console::out << date_time::sprintf("%Ec", now) << environment::new_line;
  console::out << date_time::sprintf("%x", now) << environment::new_line;
  console::out << date_time::sprintf("%Ex", now) << environment::new_line;
  console::out << date_time::sprintf("%X", now) << environment::new_line;
  console::out << date_time::sprintf("%EX", now) << environment::new_line;
  console::out << date_time::sprintf("%D", now) << environment::new_line;
  console::out << date_time::sprintf("%F", now) << environment::new_line;
  console::out << date_time::sprintf("%r", now) << environment::new_line;
  console::out << date_time::sprintf("%R", now) << environment::new_line;
  console::out << date_time::sprintf("%T", now) << environment::new_line;
  console::out << date_time::sprintf("%p", now) << environment::new_line;
  console::out << date_time::sprintf("%z", now) << environment::new_line;
  console::out << date_time::sprintf("%Z", now) << environment::new_line;
}

// This code can be produce the following output :
//
// Sat Jan  2 03:04:05 2021
// 2021
// 2021
// 21
// 21
// 21
// 20
// 20
// 2020
// 20
// Jan
// Jan
// January
// 01
// 01
// 00
// 00
// 00
// 00
// 53
// 53
// 002
// 02
// 02
// 2
// 02
// Sat
// Saturday
// 6
// 6
// 6
// 6
// 03
// Jan
// 03
// 03
// 04
// 04
// 05
// 05
// Sat Jan  2 03:04:05 2021
// Sat Jan  2 03:04:05 2021
// 01/02/21
// 01/02/21
// 03:04:05
// 03:04:05
// 01/02/21
// 2021-01-02
// 03:04:05 AM
// 03:04
// 03:04:05
// AM
// +0100
// CET
