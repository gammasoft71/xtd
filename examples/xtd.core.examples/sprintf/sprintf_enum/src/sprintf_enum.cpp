#include <xtd/xtd>

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

template<> struct xtd::enum_register<week_day> {
  explicit operator auto() const noexcept {return xtd::enum_collection<week_day> {{week_day::monday, "monday"}, {week_day::tuesday, "tuesday"}, {week_day::wednesday, "wednesday"}, {week_day::thursday, "thursday"}, {week_day::friday, "friday"}, {week_day::saturday, "saturday"}, {week_day::sunday, "sunday"}};}
};

int main() {
  console::out << string::sprintf("%s", enum_object {week_day::saturday}.to_string("")) << environment::new_line;
  console::out << string::sprintf("0b%s", enum_object {week_day::saturday}.to_string("b")) << environment::new_line;
  console::out << string::sprintf("0b%s", enum_object {week_day::saturday}.to_string("B")) << environment::new_line;
  console::out << string::sprintf("0b%s", enum_object {week_day::saturday}.to_string("d")) << environment::new_line;
  console::out << string::sprintf("%s", enum_object {week_day::saturday}.to_string("D")) << environment::new_line;
  console::out << string::sprintf("%s", enum_object {week_day::saturday}.to_string("g")) << environment::new_line;
  console::out << string::sprintf("%s", enum_object {week_day::saturday}.to_string("G")) << environment::new_line;
  console::out << string::sprintf("0%s", enum_object {week_day::saturday}.to_string("o")) << environment::new_line;
  console::out << string::sprintf("0%s", enum_object {week_day::saturday}.to_string("O")) << environment::new_line;
  console::out << string::sprintf("0x%s", enum_object {week_day::saturday}.to_string("x")) << environment::new_line;
  console::out << string::sprintf("0x%s", enum_object {week_day::saturday}.to_string("X")) << environment::new_line;
}

// This code produces the following output :
//
// saturday
// 0b101
// 0b101
// 0b5
// 5
// saturday
// saturday
// 05
// 05
// 0x5
// 0x5
