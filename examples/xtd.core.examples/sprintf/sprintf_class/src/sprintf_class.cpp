#include <xtd/xtd>

using namespace std;
using namespace xtd;

class character {
public:
  character(const ustring& name, const ustring& rank) noexcept : name_(name), rank_(rank) {}
  
  const ustring& name() const noexcept {return name_;}
  const ustring& rank() const noexcept {return rank_;}

  ustring to_string() const noexcept {return name_ + " (" + rank_ + ")";}
  
private:
  ustring name_;
  ustring rank_;
};

using characters = vector<character>;

int main() {
  for (auto c : characters {{"Jean-Luc Picard", "Captain"}, {"William Riker", "Commander"}, {"Data", "Commander"}, {"Beverly Crusher", "Commander"}, {"Geordi La Forge", "Lieutenant Commander"}, {"Worf", "Lieutenant Commander"}, {"Tasha Yar", "Lieutenant"}})
    cout << ustring::sprintf("%s", c.to_string()) << endl;
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
