#include <xtd/as>
#include <xtd/console>

using namespace xtd;

class my_base_class : public object {
};

class my_derived_class: public my_base_class {
};

auto main() -> int {
  auto my_base = my_base_class {};
  auto my_derived = my_derived_class {};
  object& o = as<object>(my_derived);
  my_base_class& b = as<my_base_class>(my_derived);
  
  console::write_line("my_base: type is {}", my_base.get_type());
  console::write_line("my_derived: type is {}", my_derived.get_type());
  console::write_line("object o = my_derived: type is {}", o.get_type());
  console::write_line("my_base_class b = my_derived: type is {}", b.get_type());
  
  console::write_line();
  console::write_line("my_base: type is {}", typeof_(my_base));
  console::write_line("my_derived: type is {}", typeof_(my_derived));
  console::write_line("object o = my_derived: type is {}", typeof_(o));
  console::write_line("my_base_class b = my_derived: type is {}", typeof_(b));
}

// This code produces the following output:
//
// my_base: type is my_base_class
// my_derived: type is my_derived_class
// object o = my_derived: type is my_derived_class
// my_base_class b = my_derived: type is my_derived_class
//
// my_base: type is my_base_class
// my_derived: type is my_derived_class
// object o = my_derived: type is my_derived_class
// my_base_class b = my_derived: type is my_derived_class
