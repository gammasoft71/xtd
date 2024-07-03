#include <xtd/console>
#include <xtd/environment>
#include <xtd/iformatable>

using namespace std;
using namespace xtd;

class foo : public object, public iformatable {
public:
  explicit foo(int value) : value_ {value} {}
  
  int value() const noexcept {return value_;}
  
  using object::to_string;
  ustring to_string(const ustring& format, const locale& loc) const override {return ustring::format(ustring::format("{{:{}}}", format), value_);}
  
private:
  int value_ = 0;
};

auto main() -> int {
  console::out << "format :" << environment::new_line;
  console::out << ustring::format("  {}", foo {42}) << environment::new_line;
  console::out << ustring::format("  0b{:b8}", foo {42}) << environment::new_line;
  console::write_line();

  console::write_line("write_line :");
  console::write_line("  {}", foo {84});
  console::write_line("  0b{:b8}", foo {84});
}

// This code produces the following output :
//
// format :
//   42
//   0b00101010
//
// write_line :
//   84
//   0b01010100
