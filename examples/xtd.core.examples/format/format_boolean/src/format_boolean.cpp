#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

enum class cap {title, middle, end};

auto print_boolean(const string& text, bool value, cap c) {
  if (c == cap::title)
    console::out << "┌───────────┬────────────┬──────────────────────────────────┐" << environment::new_line
                 << "│  boolean  │   format   │      representation              │" << environment::new_line
                 << "├───────────┼────────────┼──────────────────────────────────┤" << environment::new_line;

  console::out <<  "│ " << text.pad_right(9) << " │ {}         │ " << string::format("{}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:b}       │ " << string::format("{:b}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:b4}      │ " << string::format("{:b4}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:b8}      │ " << string::format("{:b8}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:B}       │ " << string::format("{:B}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:B4}      │ " << string::format("{:B4}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:B8}      │ " << string::format("{:B8}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:d}       │ " << string::format("{:d}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:d2}      │ " << string::format("{:d2}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:D}       │ " << string::format("{:D}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:D2}      │ " << string::format("{:D2}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:g}       │ " << string::format("{:g}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:G}       │ " << string::format("{:G}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:o}       │ " << string::format("{:o}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:o3}      │ " << string::format("{:o3}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:O}       │ " << string::format("{:O}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:O3}      │ " << string::format("{:O3}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:x}       │ " << string::format("{:x}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:x5}      │ " << string::format("{:x5}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:X}       │ " << string::format("{:X}", value).pad_right(32) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(9) << " │ {:X5}      │ " << string::format("{:X5}", value).pad_right(32) << " |" << environment::new_line;

  if (c != cap::end)
    console::out << "├───────────┼────────────┼──────────────────────────────────┤" << environment::new_line;
  else
    console::out << "└───────────┴────────────┴──────────────────────────────────┘" << environment::new_line;
}

auto main() -> int {
  print_boolean("true", true, cap::title);
  print_boolean("false", false, cap::middle);
  print_boolean("1", 1, cap::middle);
  print_boolean("0", 0, cap::end);
}

// This code produces the following output :
//
// ┌───────────┬────────────┬──────────────────────────────────┐
// │  boolean  │   format   │      representation              │
// ├───────────┼────────────┼──────────────────────────────────┤
// │ true      │ {}         │ true                             |
// │ true      │ {:b}       │ 1                                |
// │ true      │ {:b4}      │ 0001                             |
// │ true      │ {:b8}      │ 00000001                         |
// │ true      │ {:B}       │ 1                                |
// │ true      │ {:B4}      │ 0001                             |
// │ true      │ {:B8}      │ 00000001                         |
// │ true      │ {:d}       │ 1                                |
// │ true      │ {:d2}      │ 01                               |
// │ true      │ {:D}       │ 1                                |
// │ true      │ {:D2}      │ 01                               |
// │ true      │ {:g}       │ true                             |
// │ true      │ {:G}       │ true                             |
// │ true      │ {:o}       │ 1                                |
// │ true      │ {:o3}      │ 001                              |
// │ true      │ {:O}       │ 1                                |
// │ true      │ {:O3}      │ 001                              |
// │ true      │ {:x}       │ 1                                |
// │ true      │ {:x5}      │ 00001                            |
// │ true      │ {:X}       │ 1                                |
// │ true      │ {:X5}      │ 00001                            |
// ├───────────┼────────────┼──────────────────────────────────┤
// │ false     │ {}         │ false                            |
// │ false     │ {:b}       │ 0                                |
// │ false     │ {:b4}      │ 0000                             |
// │ false     │ {:b8}      │ 00000000                         |
// │ false     │ {:B}       │ 0                                |
// │ false     │ {:B4}      │ 0000                             |
// │ false     │ {:B8}      │ 00000000                         |
// │ false     │ {:d}       │ 0                                |
// │ false     │ {:d2}      │ 00                               |
// │ false     │ {:D}       │ 0                                |
// │ false     │ {:D2}      │ 00                               |
// │ false     │ {:g}       │ false                            |
// │ false     │ {:G}       │ false                            |
// │ false     │ {:o}       │ 0                                |
// │ false     │ {:o3}      │ 000                              |
// │ false     │ {:O}       │ 0                                |
// │ false     │ {:O3}      │ 000                              |
// │ false     │ {:x}       │ 0                                |
// │ false     │ {:x5}      │ 00000                            |
// │ false     │ {:X}       │ 0                                |
// │ false     │ {:X5}      │ 00000                            |
// ├───────────┼────────────┼──────────────────────────────────┤
// │ 1         │ {}         │ true                             |
// │ 1         │ {:b}       │ 1                                |
// │ 1         │ {:b4}      │ 0001                             |
// │ 1         │ {:b8}      │ 00000001                         |
// │ 1         │ {:B}       │ 1                                |
// │ 1         │ {:B4}      │ 0001                             |
// │ 1         │ {:B8}      │ 00000001                         |
// │ 1         │ {:d}       │ 1                                |
// │ 1         │ {:d2}      │ 01                               |
// │ 1         │ {:D}       │ 1                                |
// │ 1         │ {:D2}      │ 01                               |
// │ 1         │ {:g}       │ true                             |
// │ 1         │ {:G}       │ true                             |
// │ 1         │ {:o}       │ 1                                |
// │ 1         │ {:o3}      │ 001                              |
// │ 1         │ {:O}       │ 1                                |
// │ 1         │ {:O3}      │ 001                              |
// │ 1         │ {:x}       │ 1                                |
// │ 1         │ {:x5}      │ 00001                            |
// │ 1         │ {:X}       │ 1                                |
// │ 1         │ {:X5}      │ 00001                            |
// ├───────────┼────────────┼──────────────────────────────────┤
// │ 0         │ {}         │ false                            |
// │ 0         │ {:b}       │ 0                                |
// │ 0         │ {:b4}      │ 0000                             |
// │ 0         │ {:b8}      │ 00000000                         |
// │ 0         │ {:B}       │ 0                                |
// │ 0         │ {:B4}      │ 0000                             |
// │ 0         │ {:B8}      │ 00000000                         |
// │ 0         │ {:d}       │ 0                                |
// │ 0         │ {:d2}      │ 00                               |
// │ 0         │ {:D}       │ 0                                |
// │ 0         │ {:D2}      │ 00                               |
// │ 0         │ {:g}       │ false                            |
// │ 0         │ {:G}       │ false                            |
// │ 0         │ {:o}       │ 0                                |
// │ 0         │ {:o3}      │ 000                              |
// │ 0         │ {:O}       │ 0                                |
// │ 0         │ {:O3}      │ 000                              |
// │ 0         │ {:x}       │ 0                                |
// │ 0         │ {:x5}      │ 00000                            |
// │ 0         │ {:X}       │ 0                                |
// │ 0         │ {:X5}      │ 00000                            |
// └───────────┴────────────┴──────────────────────────────────┘
