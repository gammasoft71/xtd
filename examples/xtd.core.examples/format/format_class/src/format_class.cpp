#include <xtd/collections/generic/list>
#include <xtd/ustring>

using namespace xtd;
using namespace xtd::collections::generic;

class character {
public:
  character() = default;
  character(const ustring& name, const ustring& rank) noexcept : name_(name), rank_(rank) {}
  
  const ustring& name() const noexcept {return name_;}
  const ustring& rank() const noexcept {return rank_;}
  
  ustring to_string() const noexcept {return name_ + " (" + rank_ + ")";}
  
  // Only this operator is needed for character class to be recognized by ustring::format() without specified formating.
  friend std::ostream& operator <<(std::ostream& os, const character& value) noexcept {return os << value.to_string();}
  friend bool operator ==(const character& lhs, const character& rhs) noexcept {return lhs.name() == rhs.name() && lhs.rank() == rhs.rank();}

private:
  ustring name_;
  ustring rank_;
};

using characters = list<character>;

auto main() -> int {
  for (auto c : characters {{"Jean-Luc Picard", "Captain"}, {"William Riker", "Commander"}, {"Data", "Commander"}, {"Beverly Crusher", "Commander"}, {"Geordi La Forge", "Lieutenant Commander"}, {"Worf", "Lieutenant Commander"}, {"Tasha Yar", "Lieutenant"}})
    std::cout << ustring::format("{}", c) << std::endl;
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
