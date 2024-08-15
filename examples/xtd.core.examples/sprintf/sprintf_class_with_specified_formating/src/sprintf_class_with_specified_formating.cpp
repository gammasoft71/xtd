#include <xtd/collections/generic/list>
#include <xtd/format_exception>
#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;
using namespace xtd::collections;

class character : iformatable {
public:
  character(const ustring& name, const ustring& rank) noexcept : name_(name), rank_(rank) {}
  
  const ustring& name() const noexcept {return name_;}
  const ustring& rank() const noexcept {return rank_;}
  
  ustring to_string() const noexcept {return to_string("F", std::locale {});}
  ustring to_string(const ustring& fmt) const noexcept {return to_string(fmt, std::locale {});}
  ustring to_string(const ustring& fmt, const std::locale& loc) const override {
    if (fmt == "F") return name_ + " (" + rank_ + ")";
    if (fmt == "N") return name_;
    if (fmt == "R") return rank_;
    throw xtd::format_exception(current_stack_frame_);
  }
  
private:
  ustring name_;
  ustring rank_;
};

using characters = generic::list<character>;

auto main() -> int {
  character c("Jean-Luc Picard", "Captain");
  console::out << ustring::sprintf("%s", c.to_string()) << environment::new_line;
  console::out << ustring::sprintf("%s", c.to_string("F")) << environment::new_line;
  console::out << ustring::sprintf("%s", c.to_string("N")) << environment::new_line;
  console::out << ustring::sprintf("%s", c.to_string("R")) << environment::new_line;
}

// This code produces the following output :
//
// Jean-Luc Picard (Captain)
// Jean-Luc Picard (Captain)
// Jean-Luc Picard
// Captain
