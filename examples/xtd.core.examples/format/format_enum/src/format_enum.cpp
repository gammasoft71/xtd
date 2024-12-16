#include <xtd/console>
#include <xtd/enum>
#include <xtd/environment>
#include <xtd/format>

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

// Only this operator is needed for week_day enum to be recognized by format().
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
  print_week_day("monday", monday, cap::title);
  print_week_day("thursday", thursday, cap::middle);
  print_week_day("sunday", sunday, cap::end);
}

// This code produces the following output :
//
// ┌──────────────────────┬────────────┬──────────────────────────────────┐
// │  week_day            │   format   │      representation              │
// ├──────────────────────┼────────────┼──────────────────────────────────┤
// │ monday               │ {}         │ monday                           │
// │ monday               │ {:b}       │ 0                                │
// │ monday               │ {:b4}      │ 0000                             │
// │ monday               │ {:B}       │ 0                                │
// │ monday               │ {:B4}      │ 0000                             │
// │ monday               │ {:d}       │ 0                                │
// │ monday               │ {:d1}      │ 0                                │
// │ monday               │ {:D}       │ 0                                │
// │ monday               │ {:D1}      │ 0                                │
// │ monday               │ {:g}       │ monday                           │
// │ monday               │ {:G}       │ monday                           │
// │ monday               │ {:o}       │ 0                                │
// │ monday               │ {:o2}      │ 00                               │
// │ monday               │ {:O}       │ 0                                │
// │ monday               │ {:O2}      │ 00                               │
// │ monday               │ {:x}       │ 0                                │
// │ monday               │ {:x2}      │ 00                               │
// │ monday               │ {:X}       │ 0                                │
// │ monday               │ {:X2}      │ 00                               │
// ├──────────────────────┼────────────┼──────────────────────────────────┤
// │ thursday             │ {}         │ thursday                         │
// │ thursday             │ {:b}       │ 11                               │
// │ thursday             │ {:b4}      │ 0011                             │
// │ thursday             │ {:B}       │ 11                               │
// │ thursday             │ {:B4}      │ 0011                             │
// │ thursday             │ {:d}       │ 3                                │
// │ thursday             │ {:d1}      │ 3                                │
// │ thursday             │ {:D}       │ 3                                │
// │ thursday             │ {:D1}      │ 3                                │
// │ thursday             │ {:g}       │ thursday                         │
// │ thursday             │ {:G}       │ thursday                         │
// │ thursday             │ {:o}       │ 3                                │
// │ thursday             │ {:o2}      │ 03                               │
// │ thursday             │ {:O}       │ 3                                │
// │ thursday             │ {:O2}      │ 03                               │
// │ thursday             │ {:x}       │ 3                                │
// │ thursday             │ {:x2}      │ 03                               │
// │ thursday             │ {:X}       │ 3                                │
// │ thursday             │ {:X2}      │ 03                               │
// ├──────────────────────┼────────────┼──────────────────────────────────┤
// │ sunday               │ {}         │ sunday                           │
// │ sunday               │ {:b}       │ 110                              │
// │ sunday               │ {:b4}      │ 0110                             │
// │ sunday               │ {:B}       │ 110                              │
// │ sunday               │ {:B4}      │ 0110                             │
// │ sunday               │ {:d}       │ 6                                │
// │ sunday               │ {:d1}      │ 6                                │
// │ sunday               │ {:D}       │ 6                                │
// │ sunday               │ {:D1}      │ 6                                │
// │ sunday               │ {:g}       │ sunday                           │
// │ sunday               │ {:G}       │ sunday                           │
// │ sunday               │ {:o}       │ 6                                │
// │ sunday               │ {:o2}      │ 06                               │
// │ sunday               │ {:O}       │ 6                                │
// │ sunday               │ {:O2}      │ 06                               │
// │ sunday               │ {:x}       │ 6                                │
// │ sunday               │ {:x2}      │ 06                               │
// │ sunday               │ {:X}       │ 6                                │
// │ sunday               │ {:X2}      │ 06                               │
// └──────────────────────┴────────────┴──────────────────────────────────┘
