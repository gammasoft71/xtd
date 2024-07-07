#include <xtd/console>

using namespace xtd;

auto main() -> int {
  object* o = nullptr;
  object* p = null;
  object* q = new object;
  
  console::write_line(object::reference_equals(*o, *p));
  p = q;
  console::write_line(object::reference_equals(*p, *q));
  console::write_line(object::reference_equals(*o, *p));
  
  delete q;
}

// This code produces the following output:
//
// true
// true
// false
