#include <xtd/console>
#include <xtd/enum_class>
#include <xtd/environment>
#include <xtd/format>

using namespace xtd;

enum class week_day {
  monday,
  tuesday,
  wednesday,
  thursday,
  friday,
  saturday,
  sunday
};

// Only this operator is needed for week_day enum class to be recognized by xtd::string::format()
template<> struct xtd::enum_register<week_day> {
  explicit operator auto() const noexcept {return xtd::enum_collection<week_day> {{week_day::monday, "monday"}, {week_day::tuesday, "tuesday"}, {week_day::wednesday, "wednesday"}, {week_day::thursday, "thursday"}, {week_day::friday, "friday"}, {week_day::saturday, "saturday"}, {week_day::sunday, "sunday"}};}
};

enum class cap {title, middle, end};

auto print_week_day(const string& text, week_day value, cap c) {
  if (c == cap::title)
    console::out
    << "┌──────────────────────┬────────────┬──────────────────────────────────┐" << environment::new_line
    << "│  week_day            │   format   │      representation              │" << environment::new_line
    << "├──────────────────────┼────────────┼──────────────────────────────────┤" << environment::new_line;
  
  console::out << "│ " << text.pad_right(20) << " │ {}         │ " << format("{}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:b}       │ " << format("{:b}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:b4}      │ " << format("{:b4}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:B}       │ " << format("{:B}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:B4}      │ " << format("{:B4}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:d}       │ " << format("{:d}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:d1}      │ " << format("{:d1}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:D}       │ " << format("{:D}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:D1}      │ " << format("{:D1}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:g}       │ " << format("{:g}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:G}       │ " << format("{:G}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:o}       │ " << format("{:o}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:o2}      │ " << format("{:o2}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:O}       │ " << format("{:O}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:O2}      │ " << format("{:O2}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:x}       │ " << format("{:x}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:x2}      │ " << format("{:x2}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:X}       │ " << format("{:X}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(20) << " │ {:X2}      │ " << format("{:X2}", value).pad_right(32) << " │" << environment::new_line;
  
  if (c != cap::end)
    console::out << "├──────────────────────┼────────────┼──────────────────────────────────┤" << environment::new_line;
  else
    console::out << "└──────────────────────┴────────────┴──────────────────────────────────┘" << environment::new_line;
}

auto main() -> int {
  print_week_day("week_day::monday", week_day::monday, cap::title);
  print_week_day("week_day::thursday", week_day::thursday, cap::middle);
  print_week_day("week_day::sunday", week_day::sunday, cap::end);
}

// This code produces the following output :
//
// ┌──────────────────────┬────────────┬──────────────────────────────────┐
// │  week_day            │   format   │      representation              │
// ├──────────────────────┼────────────┼──────────────────────────────────┤
// │ week_day::monday     │ {}         │ monday                           │
// │ week_day::monday     │ {:b}       │ 0                                │
// │ week_day::monday     │ {:b4}      │ 0000                             │
// │ week_day::monday     │ {:B}       │ 0                                │
// │ week_day::monday     │ {:B4}      │ 0000                             │
// │ week_day::monday     │ {:d}       │ 0                                │
// │ week_day::monday     │ {:d1}      │ 0                                │
// │ week_day::monday     │ {:D}       │ 0                                │
// │ week_day::monday     │ {:D1}      │ 0                                │
// │ week_day::monday     │ {:g}       │ monday                           │
// │ week_day::monday     │ {:G}       │ monday                           │
// │ week_day::monday     │ {:o}       │ 0                                │
// │ week_day::monday     │ {:o2}      │ 00                               │
// │ week_day::monday     │ {:O}       │ 0                                │
// │ week_day::monday     │ {:O2}      │ 00                               │
// │ week_day::monday     │ {:x}       │ 0                                │
// │ week_day::monday     │ {:x2}      │ 00                               │
// │ week_day::monday     │ {:X}       │ 0                                │
// │ week_day::monday     │ {:X2}      │ 00                               │
// ├──────────────────────┼────────────┼──────────────────────────────────┤
// │ week_day::thursday   │ {}         │ thursday                         │
// │ week_day::thursday   │ {:b}       │ 11                               │
// │ week_day::thursday   │ {:b4}      │ 0011                             │
// │ week_day::thursday   │ {:B}       │ 11                               │
// │ week_day::thursday   │ {:B4}      │ 0011                             │
// │ week_day::thursday   │ {:d}       │ 3                                │
// │ week_day::thursday   │ {:d1}      │ 3                                │
// │ week_day::thursday   │ {:D}       │ 3                                │
// │ week_day::thursday   │ {:D1}      │ 3                                │
// │ week_day::thursday   │ {:g}       │ thursday                         │
// │ week_day::thursday   │ {:G}       │ thursday                         │
// │ week_day::thursday   │ {:o}       │ 3                                │
// │ week_day::thursday   │ {:o2}      │ 03                               │
// │ week_day::thursday   │ {:O}       │ 3                                │
// │ week_day::thursday   │ {:O2}      │ 03                               │
// │ week_day::thursday   │ {:x}       │ 3                                │
// │ week_day::thursday   │ {:x2}      │ 03                               │
// │ week_day::thursday   │ {:X}       │ 3                                │
// │ week_day::thursday   │ {:X2}      │ 03                               │
// ├──────────────────────┼────────────┼──────────────────────────────────┤
// │ week_day::sunday     │ {}         │ sunday                           │
// │ week_day::sunday     │ {:b}       │ 110                              │
// │ week_day::sunday     │ {:b4}      │ 0110                             │
// │ week_day::sunday     │ {:B}       │ 110                              │
// │ week_day::sunday     │ {:B4}      │ 0110                             │
// │ week_day::sunday     │ {:d}       │ 6                                │
// │ week_day::sunday     │ {:d1}      │ 6                                │
// │ week_day::sunday     │ {:D}       │ 6                                │
// │ week_day::sunday     │ {:D1}      │ 6                                │
// │ week_day::sunday     │ {:g}       │ sunday                           │
// │ week_day::sunday     │ {:G}       │ sunday                           │
// │ week_day::sunday     │ {:o}       │ 6                                │
// │ week_day::sunday     │ {:o2}      │ 06                               │
// │ week_day::sunday     │ {:O}       │ 6                                │
// │ week_day::sunday     │ {:O2}      │ 06                               │
// │ week_day::sunday     │ {:x}       │ 6                                │
// │ week_day::sunday     │ {:x2}      │ 06                               │
// │ week_day::sunday     │ {:X}       │ 6                                │
// │ week_day::sunday     │ {:X2}      │ 06                               │
// └──────────────────────┴────────────┴──────────────────────────────────┘
