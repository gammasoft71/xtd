#include <xtd/console>

using namespace xtd;

auto main() -> int {
  auto object1 = new_ptr<object>();
  auto object2 = new_ptr<object>();
  
  auto object3 = object2;
  console::write_line(object1->equals(*object3));
  object3 = object1;
  console::write_line(object1->equals(*object3));
}

// This code produces the following output:
//
// false
// true
