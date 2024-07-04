#include <xtd/format_exception>
#include <xtd/ustring>

using namespace std;
using namespace xtd;

class character {
public:
  character(const ustring& name, const ustring& rank) noexcept : name_(name), rank_(rank) {}
  
  const ustring& name() const noexcept {return name_;}
  const ustring& rank() const noexcept {return rank_;}
  
  ustring to_string() const noexcept {return to_string("", locale {});}
  ustring to_string(const ustring& format, const locale& loc) const {
    auto fmt = ustring::is_empty(format) ? "F" : format;
    if (fmt == "F") return name_ + " (" + rank_ + ")";
    if (fmt == "N") return name_;
    if (fmt == "R") return rank_;
    throw format_exception(current_stack_frame_);
  }
  
private:
  ustring name_;
  ustring rank_;
};

template<>
string xtd::to_string(const character& value, const string& fmt, const locale& loc) {return value.to_string(fmt, loc);}

auto main() -> int {
  auto c = character {"Jean-Luc Picard", "Captain"};
 
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
