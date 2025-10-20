#include <xtd/xtd>

using namespace xtd::globalization;

class character {
public:
  character(const string& name, const string& rank) noexcept : name_(name), rank_(rank) {}
  
  const string& name() const noexcept {return name_;}
  const string& rank() const noexcept {return rank_;}
  
  string to_string() const noexcept {return to_string("F", culture_info::current_culture());}
  string to_string(const string& fmt) const noexcept {return to_string(fmt, culture_info::current_culture());}
  string to_string(const string& fmt, const std::locale& loc) const {
    if (fmt == "F") return name_ + " (" + rank_ + ")";
    if (fmt == "N") return name_;
    if (fmt == "R") return rank_;
    throw xtd::format_exception {};
  }
  
private:
  string name_;
  string rank_;
};

template<>
string xtd::to_string(const character& value, const string& fmt, const std::locale& loc) {return value.to_string(fmt, loc);}

using characters = list<character>;

auto main() -> int {
  character c("Jean-Luc Picard", "Captain");
  console::out << string::sprintf("%s", c.to_string()) << environment::new_line;
  console::out << string::sprintf("%s", c.to_string("F")) << environment::new_line;
  console::out << string::sprintf("%s", c.to_string("N")) << environment::new_line;
  console::out << string::sprintf("%s", c.to_string("R")) << environment::new_line;
}

// This code produces the following output :
//
// Jean-Luc Picard (Captain)
// Jean-Luc Picard (Captain)
// Jean-Luc Picard
// Captain
