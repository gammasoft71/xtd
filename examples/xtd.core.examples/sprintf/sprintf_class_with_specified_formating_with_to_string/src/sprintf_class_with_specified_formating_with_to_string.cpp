#include <xtd/collections/generic/list>
#include <xtd/format_exception>
#include <xtd/ustring>

using namespace xtd;
using namespace xtd::collections;

class character {
public:
  character(const ustring& name, const ustring& rank) noexcept : name_(name), rank_(rank) {}
  
  const ustring& name() const noexcept {return name_;}
  const ustring& rank() const noexcept {return rank_;}
  
  ustring to_string() const noexcept {return to_string("F", std::locale {});}
  ustring to_string(const ustring& fmt) const noexcept {return to_string(fmt, std::locale {});}
  ustring to_string(const ustring& fmt, const std::locale& loc) const {
    if (fmt == "F") return name_ + " (" + rank_ + ")";
    if (fmt == "N") return name_;
    if (fmt == "R") return rank_;
    throw xtd::format_exception(current_stack_frame_);
  }
  
private:
  ustring name_;
  ustring rank_;
};

template<>
std::string xtd::to_string(const character& value, const std::string& fmt, const std::locale& loc) {return value.to_string(fmt, loc);}

using characters = generic::list<character>;

auto main() -> int {
  character c("Jean-Luc Picard", "Captain");
  std::cout << ustring::sprintf("%s", c.to_string()) << std::endl;
  std::cout << ustring::sprintf("%s", c.to_string("F")) << std::endl;
  std::cout << ustring::sprintf("%s", c.to_string("N")) << std::endl;
  std::cout << ustring::sprintf("%s", c.to_string("R")) << std::endl;
}

// This code produces the following output :
//
// Jean-Luc Picard (Captain)
// Jean-Luc Picard (Captain)
// Jean-Luc Picard
// Captain
