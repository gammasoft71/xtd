#include <xtd/xtd>

class persona : public istringable<persona> {
public:
  persona() = default;
  persona(const string& name, const string& rank) noexcept : name_(name), rank_(rank) {}
  
  auto name() const noexcept -> const string& {return name_;}
  auto rank() const noexcept -> const string& {return rank_;}
  
  auto to_string() const noexcept -> string override {return name_ + " (" + rank_ + ")";}
  
  friend bool operator ==(const persona& lhs, const persona& rhs) noexcept {return lhs.name() == rhs.name() && lhs.rank() == rhs.rank();}

private:
  string name_;
  string rank_;
};

using characters = list<persona>;

auto main() -> int {
  for (auto c : characters {{"Jean-Luc Picard", "Captain"}, {"William Riker", "Commander"}, {"Data", "Commander"}, {"Beverly Crusher", "Commander"}, {"Geordi La Forge", "Lieutenant Commander"}, {"Worf", "Lieutenant Commander"}, {"Tasha Yar", "Lieutenant"}})
    console::out << format("{}", c) << environment::new_line;
}

// This code produces the following output :
//
// Jean-Luc Picard (Captain)
// William Riker (Commander)
// Data (Commander)
// Beverly Crusher (Commander)
// Geordi La Forge (Lieutenant Commander)
// Worf (Lieutenant Commander)
// Tasha Yar (Lieutenant)
