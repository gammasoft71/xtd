#include <xtd/console>
#include <xtd/enum>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

enum week_day {
  monday,
  tuesday,
  wednesday,
  thursday,
  friday,
  saturday,
  sunday
};

// Only this operator is needed for week_day enum to be recognized by string::format().
template<> struct xtd::enum_register<week_day> {
  explicit operator auto() const noexcept {return xtd::enum_collection<week_day> {{week_day::monday, "monday"}, {week_day::tuesday, "tuesday"}, {week_day::wednesday, "wednesday"}, {week_day::thursday, "thursday"}, {week_day::friday, "friday"}, {week_day::saturday, "saturday"}, {week_day::sunday, "sunday"}};}
};

auto main() -> int {
  console::out << string::format("{}", week_day::saturday) << environment::new_line;
  console::out << string::format("0b{:b}", week_day::saturday) << environment::new_line;
  console::out << string::format("0b{:B}", week_day::saturday) << environment::new_line;
  console::out << string::format("{:d}", week_day::saturday) << environment::new_line;
  console::out << string::format("{:D}", week_day::saturday) << environment::new_line;
  console::out << string::format("{:g}", week_day::saturday) << environment::new_line;
  console::out << string::format("{:G}", week_day::saturday) << environment::new_line;
  console::out << string::format("0{:o}", week_day::saturday) << environment::new_line;
  console::out << string::format("0{:O}", week_day::saturday) << environment::new_line;
  console::out << string::format("0x{:x}", week_day::saturday) << environment::new_line;
  console::out << string::format("0x{:X}", week_day::saturday) << environment::new_line;
}

// This code produces the following output :
//
// saturday
// 0b101
// 0b101
// 5
// 5
// saturday
// saturday
// 05
// 05
// 0x5
// 0x5
