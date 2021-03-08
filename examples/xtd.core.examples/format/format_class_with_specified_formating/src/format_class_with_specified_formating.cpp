#include <xtd/xtd>

using namespace std;
using namespace xtd;

class character {
public:
  character(const string& name, const string& rank) noexcept : name_(name), rank_(rank) {}
  
  const string& name() const noexcept {return name_;}
  const string& rank() const noexcept {return rank_;}

  string to_string() const noexcept {return to_string("F");}
  string to_string(const string& fmt) const {
    if (fmt == "F") return name_ + " (" + rank_ + ")";
    if (fmt == "N") return name_;
    if (fmt == "R") return rank_;
    throw xtd::format_exception(caller_info_);
  }

  // Only this operator is needed for character class to be recognized by format() without specified formating.
  friend ostream& operator<<(ostream& os, const character& value) noexcept {return os << value.to_string();}
  
private:
  string name_;
  string rank_;
};

// Only this method is needed for character class to be recognized by format() with specified formating (F, N or R).
template<>
string xtd::to_string(const character& value, const string& fmt, const locale& loc) {return value.to_string(fmt);}

using characters = vector<character>;

int main() {
  for (auto c : characters {{"Jean-Luc Picard", "Captain"}, {"William Riker", "Commander"}, {"Data", "Commander"}, {"Beverly Crusher", "Commander"}, {"Geordi La Forge", "Lieutenant Commander"}, {"Worf", "Lieutenant Commander"}, {"Tasha Yar", "Lieutenant"}})
    cout << format("{:N}", c) << endl;
}

// This code produces the following output with colors :
//
// Jean-Luc Picard
// William Riker
// Data
// Beverly Crusher
// Geordi La Forge
// Worf
// Tasha Yar
