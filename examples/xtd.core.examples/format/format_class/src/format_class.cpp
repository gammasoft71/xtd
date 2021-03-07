#include <xtd/xtd>

using namespace std;
using namespace xtd;

class character {
public:
  character() = default;
  character(const string& name, const string& rank) : name_(name), rank_(rank) {}
  
  const string& name() const {return name_;}
  const string& rank() const {return rank_;}

  string to_string() const {return "{name=" + name_ + ", rank=" + rank_ + "}";}
  
  friend std::ostream& operator <<(std::ostream& os, const character& value) noexcept {return os << value.to_string();}
  
private:
  string name_;
  string rank_;
};

int main() {
  vector<character> characters = {
    {"Jean-Luc Picard", "Captain"},
    {"William Riker", "Commander"},
    {"Data", "Commander"},
    {"Beverly Crusher", "Commander"},
    {"Geordi La Forge", "Lieutenant Commander"},
    {"Worf", "Lieutenant Commander"},
    {"Tasha Yar", "Lieutenant"},
  };
  
  for (auto c : characters)
    cout << format("{}", c) << endl;
}

// This code produces the following output with colors :
//
// saturday night fever
