#include <xtd/xtd>

using namespace std;
using namespace xtd;

class character {
public:
  character(const string& name, const string& rank) noexcept : name_(name), rank_(rank) {}
  
  const string& name() const noexcept {return name_;}
  const string& rank() const noexcept {return rank_;}

  string to_string() const noexcept {return name_ + " (" + rank_ + ")";}
  
private:
  string name_;
  string rank_;
};

using characters = vector<character>;

int main() {
  for (auto c : characters {{"Jean-Luc Picard", "Captain"}, {"William Riker", "Commander"}, {"Data", "Commander"}, {"Beverly Crusher", "Commander"}, {"Geordi La Forge", "Lieutenant Commander"}, {"Worf", "Lieutenant Commander"}, {"Tasha Yar", "Lieutenant"}})
    cout << strings::sprintf("%s", c.to_string()) << endl;
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
