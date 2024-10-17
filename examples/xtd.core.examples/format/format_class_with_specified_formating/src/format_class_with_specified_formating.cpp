#include <xtd/format_exception>
#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

class character : public iformatable {
public:
  character(const string& name, const string& rank) noexcept : name_(name), rank_(rank) {}
  
  const string& name() const noexcept {return name_;}
  const string& rank() const noexcept {return rank_;}
  
  string to_string() const noexcept {return to_string("", std::locale {});}
  string to_string(const string& format, const std::locale& loc) const override {
    auto fmt = string::is_empty(format) ? "F" : format;
    if (fmt == "F") return name_ + " (" + rank_ + ")";
    if (fmt == "N") return name_;
    if (fmt == "R") return rank_;
    throw format_exception {};
  }
  
private:
  string name_;
  string rank_;
};

auto main() -> int {
  auto c = character {"Jean-Luc Picard", "Captain"};
 
  console::out << string::format("{}", c) << environment::new_line;
  console::out << string::format("{:F}", c) << environment::new_line;
  console::out << string::format("{:N}", c) << environment::new_line;
  console::out << string::format("{:R}", c) << environment::new_line;
}

// This code produces the following output :
//
// Jean-Luc Picard (Captain)
// Jean-Luc Picard (Captain)
// Jean-Luc Picard
// Captain
