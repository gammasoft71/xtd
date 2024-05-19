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
  cout << ustring::format("{}", value) << endl;
  
  value = make_any<ustring>("Star Trek: The Next Generation");
  cout << ustring::format("{}", value) << endl;
  
  value = make_any<character>("Jean-Luc Picard", "Captain");
  cout << "Before register_any_stringer : " << ustring::format("{}", value) << endl;
  
  register_any_stringer<character>([](auto value) {return value.to_string();});
  cout << "After register_any_stringer : " << ustring::format("{}", value) << endl;
  
  unregister_any_stringer<character>();
  cout << "After unregister_any_stringer : " << ustring::format("{}", value) << endl;
}

// This code produces the following output :
//
// 42
// Star Trek: The Next Generation
// Before register_any_stringer : (unregistered)
// After register_any_stringer : Jean-Luc Picard (Captain)
// After unregister_any_stringer : (unregistered)
