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
    throw format_exception(current_stack_frame_);
  }

  // Only this operator is needed for character class to be recognized by ustring::format() without specified formating.
  friend ostream& operator<<(ostream& os, const character& value) noexcept {return os << value.to_string();}
  
private:
  string name_;
  string rank_;
};

// Only this method is needed for character class to be recognized by ustring::format() with specified formating (F, N or R).
template<>
string xtd::to_string(const character& value, const string& fmt, const locale& loc) {return value.to_string(fmt);}

int main() {
  character c("Jean-Luc Picard", "Captain");
  cout << ustring::format("{}", c) << endl;
  cout << ustring::format("{:F}", c) << endl;
  cout << ustring::format("{:N}", c) << endl;
  cout << ustring::format("{:R}", c) << endl;
}

// This code produces the following output :
//
// Jean-Luc Picard (Captain)
// Jean-Luc Picard (Captain)
// Jean-Luc Picard
// Captain
