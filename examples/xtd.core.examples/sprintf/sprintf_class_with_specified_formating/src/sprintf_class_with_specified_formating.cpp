#include <xtd/xtd>

using namespace std;
using namespace xtd;

class character {
public:
  character(const ustring& name, const ustring& rank) noexcept : name_(name), rank_(rank) {}
  
  const ustring& name() const noexcept {return name_;}
  const ustring& rank() const noexcept {return rank_;}

  ustring to_string() const noexcept {return to_string("F");}
  ustring to_string(const ustring& fmt) const {
    if (fmt == "F") return name_ + " (" + rank_ + ")";
    if (fmt == "N") return name_;
    if (fmt == "R") return rank_;
    throw xtd::format_exception(current_stack_frame_);
  }
  
private:
  ustring name_;
  ustring rank_;
};

// Only this method is needed for character class to be recognized by ustring::format() with specified formating (F, N or R).
template<>
string xtd::to_string(const character& value, const string& fmt, const locale& loc) {return value.to_string(fmt);}

using characters = vector<character>;

int main() {
  character c("Jean-Luc Picard", "Captain");
  cout << ustring::sprintf("%s", c.to_string()) << endl;
  cout << ustring::sprintf("%s", c.to_string("F")) << endl;
  cout << ustring::sprintf("%s", c.to_string("N")) << endl;
  cout << ustring::sprintf("%s", c.to_string("R")) << endl;
}

// This code produces the following output :
//
// Jean-Luc Picard (Captain)
// Jean-Luc Picard (Captain)
// Jean-Luc Picard
// Captain
