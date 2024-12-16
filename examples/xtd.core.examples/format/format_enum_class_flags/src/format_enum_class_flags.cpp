#include <xtd/console>
#include <xtd/enum_class>
#include <xtd/environment>
#include <xtd/format>

using namespace xtd;

enum class text_styles {
  normal =    0b0,
  bold =      0b1,
  italic =    0b10,
  underline = 0b100,
  strikeout = 0b1000,
};

// Add text_style enum class flags operators and register flags attribute.
flags_attribute_(, text_styles);

// Only this operator is needed for text_styles enum class to be recognized by xtd::string::format().
template<> struct xtd::enum_register<text_styles> {
  explicit operator auto() const noexcept {return xtd::enum_collection<text_styles> {{text_styles::normal, "normal"}, {text_styles::bold, "bold"}, {text_styles::italic, "italic"}, {text_styles::underline, "underline"}, {text_styles::strikeout, "strikeout"}};}
};

enum class cap {title, middle, end};

auto print_text_styles(const string& text, text_styles value, cap c) {
  if (c == cap::title)
    console::out
    << "┌───────────────────────────────────────────────┬────────────┬──────────────────────────────────┐" << environment::new_line
    << "│  text_styles                                  │   format   │      representation              │" << environment::new_line
    << "├───────────────────────────────────────────────┼────────────┼──────────────────────────────────┤" << environment::new_line;
  
  console::out << "│ " << text.pad_right(45) << " │ {}         │ " << format("{}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:b}       │ " << format("{:b}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:b4}      │ " << format("{:b4}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:B}       │ " << format("{:B}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:B4}      │ " << format("{:B4}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:d}       │ " << format("{:d}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:d1}      │ " << format("{:d1}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:D}       │ " << format("{:D}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:D1}      │ " << format("{:D1}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:g}       │ " << format("{:g}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:G}       │ " << format("{:G}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:o}       │ " << format("{:o}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:o2}      │ " << format("{:o2}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:O}       │ " << format("{:O}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:O2}      │ " << format("{:O2}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:x}       │ " << format("{:x}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:x2}      │ " << format("{:x2}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:X}       │ " << format("{:X}", value).pad_right(32) << " │" << environment::new_line;
  console::out << "│ " << text.pad_right(45) << " │ {:X2}      │ " << format("{:X2}", value).pad_right(32) << " │" << environment::new_line;
  
  if (c != cap::end)
    console::out << "├───────────────────────────────────────────────┼────────────┼──────────────────────────────────┤" << environment::new_line;
  else
    console::out << "└───────────────────────────────────────────────┴────────────┴──────────────────────────────────┘" << environment::new_line;
}

auto main() -> int {
  print_text_styles("text_styles::normal", text_styles::normal, cap::title);
  print_text_styles("text_styles::bold|text_styles::italic", text_styles::bold|text_styles::italic, cap::middle);
  print_text_styles("text_styles::strikeout", text_styles::strikeout, cap::end);
}

// This code produces the following output :
//
// ┌───────────────────────────────────────────────┬────────────┬──────────────────────────────────┐
// │  text_styles                                  │   format   │      representation              │
// ├───────────────────────────────────────────────┼────────────┼──────────────────────────────────┤
// │ text_styles::normal                           │ {}         │ normal                           │
// │ text_styles::normal                           │ {:b}       │ 0                                │
// │ text_styles::normal                           │ {:b4}      │ 0000                             │
// │ text_styles::normal                           │ {:B}       │ 0                                │
// │ text_styles::normal                           │ {:B4}      │ 0000                             │
// │ text_styles::normal                           │ {:d}       │ 0                                │
// │ text_styles::normal                           │ {:d1}      │ 0                                │
// │ text_styles::normal                           │ {:D}       │ 0                                │
// │ text_styles::normal                           │ {:D1}      │ 0                                │
// │ text_styles::normal                           │ {:g}       │ normal                           │
// │ text_styles::normal                           │ {:G}       │ normal                           │
// │ text_styles::normal                           │ {:o}       │ 0                                │
// │ text_styles::normal                           │ {:o2}      │ 00                               │
// │ text_styles::normal                           │ {:O}       │ 0                                │
// │ text_styles::normal                           │ {:O2}      │ 00                               │
// │ text_styles::normal                           │ {:x}       │ 0                                │
// │ text_styles::normal                           │ {:x2}      │ 00                               │
// │ text_styles::normal                           │ {:X}       │ 0                                │
// │ text_styles::normal                           │ {:X2}      │ 00                               │
// ├───────────────────────────────────────────────┼────────────┼──────────────────────────────────┤
// │ text_styles::bold|text_styles::italic         │ {}         │ bold, italic                     │
// │ text_styles::bold|text_styles::italic         │ {:b}       │ 11                               │
// │ text_styles::bold|text_styles::italic         │ {:b4}      │ 0011                             │
// │ text_styles::bold|text_styles::italic         │ {:B}       │ 11                               │
// │ text_styles::bold|text_styles::italic         │ {:B4}      │ 0011                             │
// │ text_styles::bold|text_styles::italic         │ {:d}       │ 3                                │
// │ text_styles::bold|text_styles::italic         │ {:d1}      │ 3                                │
// │ text_styles::bold|text_styles::italic         │ {:D}       │ 3                                │
// │ text_styles::bold|text_styles::italic         │ {:D1}      │ 3                                │
// │ text_styles::bold|text_styles::italic         │ {:g}       │ bold, italic                     │
// │ text_styles::bold|text_styles::italic         │ {:G}       │ bold, italic                     │
// │ text_styles::bold|text_styles::italic         │ {:o}       │ 3                                │
// │ text_styles::bold|text_styles::italic         │ {:o2}      │ 03                               │
// │ text_styles::bold|text_styles::italic         │ {:O}       │ 3                                │
// │ text_styles::bold|text_styles::italic         │ {:O2}      │ 03                               │
// │ text_styles::bold|text_styles::italic         │ {:x}       │ 3                                │
// │ text_styles::bold|text_styles::italic         │ {:x2}      │ 03                               │
// │ text_styles::bold|text_styles::italic         │ {:X}       │ 3                                │
// │ text_styles::bold|text_styles::italic         │ {:X2}      │ 03                               │
// ├───────────────────────────────────────────────┼────────────┼──────────────────────────────────┤
// │ text_styles::strikeout                        │ {}         │ strikeout                        │
// │ text_styles::strikeout                        │ {:b}       │ 1000                             │
// │ text_styles::strikeout                        │ {:b4}      │ 1000                             │
// │ text_styles::strikeout                        │ {:B}       │ 1000                             │
// │ text_styles::strikeout                        │ {:B4}      │ 1000                             │
// │ text_styles::strikeout                        │ {:d}       │ 8                                │
// │ text_styles::strikeout                        │ {:d1}      │ 8                                │
// │ text_styles::strikeout                        │ {:D}       │ 8                                │
// │ text_styles::strikeout                        │ {:D1}      │ 8                                │
// │ text_styles::strikeout                        │ {:g}       │ strikeout                        │
// │ text_styles::strikeout                        │ {:G}       │ strikeout                        │
// │ text_styles::strikeout                        │ {:o}       │ 10                               │
// │ text_styles::strikeout                        │ {:o2}      │ 10                               │
// │ text_styles::strikeout                        │ {:O}       │ 10                               │
// │ text_styles::strikeout                        │ {:O2}      │ 10                               │
// │ text_styles::strikeout                        │ {:x}       │ 8                                │
// │ text_styles::strikeout                        │ {:x2}      │ 08                               │
// │ text_styles::strikeout                        │ {:X}       │ 8                                │
// │ text_styles::strikeout                        │ {:X2}      │ 08                               │
// └───────────────────────────────────────────────┴────────────┴──────────────────────────────────┘
