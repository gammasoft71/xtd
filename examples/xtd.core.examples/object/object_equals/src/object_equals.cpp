#include <xtd/console>

using namespace xtd;

auto main() -> int {
  auto object1 = std::make_shared<object>();
  auto object2 = std::make_shared<object>();
  
  auto object3 = object2;
  console::write_line(object1->equals(*object3));
  object3 = object1;
  console::write_line(object1->equals(*object3));
}

// This code produces the following output:
//
// false
// true
