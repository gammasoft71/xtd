#include <xtd/xtd>

using namespace xtd::globalization;

class character : public iformatable {
public:
  character() = default;
  character(const string& name, const string& rank) noexcept : name_(name), rank_(rank) {}
  
  const string& name() const noexcept {return name_;}
  const string& rank() const noexcept {return rank_;}
  
  string to_string() const noexcept {return to_string("", culture_info::current_culture());}
  string to_string(const string& format, const std::locale& loc) const override {
    auto fmt = string::is_empty(format) ? "F" : format;
    if (fmt == "F") return name_ + " (" + rank_ + ")";
    if (fmt == "N") return name_;
    if (fmt == "R") return rank_;
    throw format_exception {};
  }
  
private:
  string name_;
  string rank_;
};

enum class cap {title, middle, end};

auto print_character(const string& text, const character& value, cap c) {
  if (c == cap::title)
    console::out
    << "┌───────────────────────────────────────────────┬────────────┬──────────────────────────────────────────┐" << environment::new_line
    << "│  character                                    │   format   │      representation                      │" << environment::new_line
    << "├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤" << environment::new_line;
  
  console::out <<  "│ " << text.pad_right(45) << " │ {}         │ " << format("{}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(45) << " │ {:F}       │ " << format("{:F}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(45) << " │ {:N}       │ " << format("{:N}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(45) << " │ {:R}       │ " << format("{:R}", value).pad_right(40) << " │" << environment::new_line;

  if (c != cap::end)
    console::out << "├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤" << environment::new_line;
  else
    console::out << "└───────────────────────────────────────────────┴────────────┴──────────────────────────────────────────┘" << environment::new_line;
}

auto main() -> int {
  print_character("{}", character {}, cap::title);
  print_character("{\"Jean-Luc Picard\", \"Captain\"}", character {"Jean-Luc Picard", "Captain"}, cap::middle);
  print_character("{\"William Riker\", \"Commander\"}", character {"William Riker", "Commander"}, cap::middle);
  print_character("{\"Data\", \"Commander\"}", character {"Data", "Commander"}, cap::middle);
  print_character("{\"Beverly Crusher\", \"Commander\"}", character {"Beverly Crusher", "Commander"}, cap::middle);
  print_character("{\"Geordi La Forge\", \"Lieutenant Commander\"}", character {"Geordi La Forge", "Lieutenant Commander"}, cap::middle);
  print_character("{\"Worf\", \"Lieutenant Commander\"}", character {"Worf", "Lieutenant Commander"}, cap::middle);
  print_character("{\"Tasha Yar\", \"Lieutenant\"}", character {"Tasha Yar", "Lieutenant"}, cap::end);
}

// This code produces the following output :
//
// ┌───────────────────────────────────────────────┬────────────┬──────────────────────────────────────────┐
// │  character                                    │   format   │      representation                      │
// ├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ {}                                            │ {}         │  ()                                      │
// │ {}                                            │ {:F}       │  ()                                      │
// │ {}                                            │ {:N}       │                                          │
// │ {}                                            │ {:R}       │                                          │
// ├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ {"Jean-Luc Picard", "Captain"}                │ {}         │ Jean-Luc Picard (Captain)                │
// │ {"Jean-Luc Picard", "Captain"}                │ {:F}       │ Jean-Luc Picard (Captain)                │
// │ {"Jean-Luc Picard", "Captain"}                │ {:N}       │ Jean-Luc Picard                          │
// │ {"Jean-Luc Picard", "Captain"}                │ {:R}       │ Captain                                  │
// ├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ {"William Riker", "Commander"}                │ {}         │ William Riker (Commander)                │
// │ {"William Riker", "Commander"}                │ {:F}       │ William Riker (Commander)                │
// │ {"William Riker", "Commander"}                │ {:N}       │ William Riker                            │
// │ {"William Riker", "Commander"}                │ {:R}       │ Commander                                │
// ├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ {"Data", "Commander"}                         │ {}         │ Data (Commander)                         │
// │ {"Data", "Commander"}                         │ {:F}       │ Data (Commander)                         │
// │ {"Data", "Commander"}                         │ {:N}       │ Data                                     │
// │ {"Data", "Commander"}                         │ {:R}       │ Commander                                │
// ├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ {"Beverly Crusher", "Commander"}              │ {}         │ Beverly Crusher (Commander)              │
// │ {"Beverly Crusher", "Commander"}              │ {:F}       │ Beverly Crusher (Commander)              │
// │ {"Beverly Crusher", "Commander"}              │ {:N}       │ Beverly Crusher                          │
// │ {"Beverly Crusher", "Commander"}              │ {:R}       │ Commander                                │
// ├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ {"Geordi La Forge", "Lieutenant Commander"}   │ {}         │ Geordi La Forge (Lieutenant Commander)   │
// │ {"Geordi La Forge", "Lieutenant Commander"}   │ {:F}       │ Geordi La Forge (Lieutenant Commander)   │
// │ {"Geordi La Forge", "Lieutenant Commander"}   │ {:N}       │ Geordi La Forge                          │
// │ {"Geordi La Forge", "Lieutenant Commander"}   │ {:R}       │ Lieutenant Commander                     │
// ├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ {"Worf", "Lieutenant Commander"}              │ {}         │ Worf (Lieutenant Commander)              │
// │ {"Worf", "Lieutenant Commander"}              │ {:F}       │ Worf (Lieutenant Commander)              │
// │ {"Worf", "Lieutenant Commander"}              │ {:N}       │ Worf                                     │
// │ {"Worf", "Lieutenant Commander"}              │ {:R}       │ Lieutenant Commander                     │
// ├───────────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ {"Tasha Yar", "Lieutenant"}                   │ {}         │ Tasha Yar (Lieutenant)                   │
// │ {"Tasha Yar", "Lieutenant"}                   │ {:F}       │ Tasha Yar (Lieutenant)                   │
// │ {"Tasha Yar", "Lieutenant"}                   │ {:N}       │ Tasha Yar                                │
// │ {"Tasha Yar", "Lieutenant"}                   │ {:R}       │ Lieutenant                               │
// └───────────────────────────────────────────────┴────────────┴──────────────────────────────────────────┘
