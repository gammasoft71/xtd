#include <xtd/xtd>

class persona : public iequatable<persona>, public icomparable<persona> {
public:
  persona() = default;
  persona(const string& name, const string& rank) noexcept : name_(name), rank_(rank) {}
  
  const string& name() const noexcept {return name_;}
  const string& rank() const noexcept {return rank_;}
  
  string to_string() const noexcept {return name_ + " (" + rank_ + ")";}
  
  int compare_to(const persona& rhs) const noexcept override {
    if (name_ == rhs.name_ && rank_ == rhs.rank_) return 0;
    if (name_ > rhs.name_) return 1;
    if (name_ == rhs.name_ && rank_ > rhs.rank_) return 1;
    return -1;
  }

  bool equals(const persona& rhs) const noexcept override {return compare_to(rhs) == 0;}

private:
  string name_;
  string rank_;
};

using characters = list<persona>;

auto main() -> int {
  for (auto c : characters {{"Jean-Luc Picard", "Captain"}, {"William Riker", "Commander"}, {"Data", "Commander"}, {"Beverly Crusher", "Commander"}, {"Geordi La Forge", "Lieutenant Commander"}, {"Worf", "Lieutenant Commander"}, {"Tasha Yar", "Lieutenant"}})
  console::out << string::sprintf("%s", c.to_string()) << environment::new_line;
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
