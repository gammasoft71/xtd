#include <xtd/xtd>

auto main() -> int {
  console::out << "Hello, " << "World!" << environment::new_line;
  console::out << "Value = " << 42 << environment::new_line;
  console::out << "Value (Hex) = 0x" << int32_object(42).to_string("X") << environment::new_line;
  console::out << "Current date = " << date_time::now() << environment::new_line;
  console::out << "Day of week = " << enum_object {day_of_week::monday} << environment::new_line;
  console::out << "Duration = " << 23_h + 5_min + 24_s << environment::new_line;
}

// This code produces the following output :
//
// Hello, World!
// Value = 42
// Value (Hex) = 0x2A
// Current date = 6/22/2026 10:47:09 AM
// Day of week = monday
// Duration = 23:05:24
