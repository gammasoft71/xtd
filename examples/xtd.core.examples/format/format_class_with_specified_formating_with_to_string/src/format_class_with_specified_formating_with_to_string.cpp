#include <xtd/format_exception>
#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

class character {
public:
  character(const ustring& name, const ustring& rank) noexcept : name_(name), rank_(rank) {}
  
  const ustring& name() const noexcept {return name_;}
  const ustring& rank() const noexcept {return rank_;}
  
  ustring to_string() const noexcept {return to_string("", std::locale {});}
  ustring to_string(const ustring& format, const std::locale& loc) const {
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
std::string xtd::to_string(const character& value, const std::string& fmt, const std::locale& loc) {return value.to_string(fmt, loc);}

auto main() -> int {
  auto c = character {"Jean-Luc Picard", "Captain"};
 
  console::out << ustring::format("{}", c) << environment::new_line;
  console::out << ustring::format("{:F}", c) << environment::new_line;
  console::out << ustring::format("{:N}", c) << environment::new_line;
  console::out << ustring::format("{:R}", c) << environment::new_line;
}

// This code produces the following output :
//
// Jean-Luc Picard (Captain)
// Jean-Luc Picard (Captain)
// Jean-Luc Picard
// Captain
