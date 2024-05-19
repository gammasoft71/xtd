#include <xtd/console>
#include <xtd/environment>
#include <xtd/int32_object>

using namespace xtd;

auto main() -> int {
  console::out << "Hello, " << "World!" << environment::new_line;
  console::out << "Value = " << 42 << environment::new_line;
  console::out << "Value (Hex) = 0x" << int32_object(42).to_string("X") << environment::new_line;
  console::out << "Current date = " << date_time::now() << environment::new_line;
  console::out << "DayOfWeek = " << day_of_week::monday << environment::new_line;
  console::out << "Duration = " << 23_h + 5_min + 24_s << environment::new_line;
}

// This code produces the following output:
//
// Hello, World!
// Value = 42
// Value (Hex) = 0x2A
// Current date = Tue Jul  4 15:30:02 2023
// DayOfWeek = (unregistered)
// Duration = 23:05:24
