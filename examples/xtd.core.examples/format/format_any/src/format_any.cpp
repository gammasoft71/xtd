#include <xtd/console>
#include <xtd/environment>
#include <xtd/register_any_stringer>
#include <xtd/unregister_any_stringer>
#include <xtd/ustring>

using namespace std;
using namespace xtd;

class character {
public:
  character(const ustring& name, const ustring& rank) noexcept : name_(name), rank_(rank) {}
  
  const ustring& name() const noexcept {return name_;}
  const ustring& rank() const noexcept {return rank_;}
  
  ustring to_string() const noexcept {return name_ + " (" + rank_ + ")";}
   
private:
  ustring name_;
  ustring rank_;
};

auto main() -> int {
  auto value = make_any<int>(42);
  console::out << ustring::format("{}", value) << environment::new_line;
  
  value = make_any<ustring>("Star Trek: The Next Generation");
  console::out << ustring::format("{}", value) << environment::new_line;
  
  value = make_any<character>("Jean-Luc Picard", "Captain");
  console::out << "Before register_any_stringer : " << ustring::format("{}", value) << environment::new_line;
  
  register_any_stringer<character>([](auto value) {return value.to_string();});
  console::out << "After register_any_stringer : " << ustring::format("{}", value) << environment::new_line;
  
  unregister_any_stringer<character>();
  console::out << "After unregister_any_stringer : " << ustring::format("{}", value) << environment::new_line;
}

// This code produces the following output :
//
// 42
// Star Trek: The Next Generation
// Before register_any_stringer : (unregistered)
// After register_any_stringer : Jean-Luc Picard (Captain)
// After unregister_any_stringer : (unregistered)
