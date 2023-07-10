#include <xtd/console>
#include <xtd/delegate>
#include <xtd/environment>

using namespace xtd;

auto main()->int {
  // use delegate as std::function
  delegate<void(const ustring& str)> writer([](const ustring & str)  {
    console::out << str << environment::new_line();
  });
  
  writer("Value to write");
}

// This code produces the following output:
//
// Hello, World!
