#include <xtd/collections/generic/list>
#include <xtd/console>
#include <xtd/environment>
#include <xtd/format>

using namespace xtd;
using namespace xtd::collections::generic;

class character : public object {
public:
  character() = default;
  character(const string& name, const string& rank) noexcept : name_(name), rank_(rank) {}
  
  const string& name() const noexcept {return name_;}
  const string& rank() const noexcept {return rank_;}
  
  string to_string() const noexcept override {return name_ + " (" + rank_ + ")";}
  
private:
  string name_;
  string rank_;
};

using characters = list<character>;

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
