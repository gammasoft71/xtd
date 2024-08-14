#include <xtd/console>
#include <xtd/environment>

using namespace xtd;

auto main() -> int {
  auto& is = console::in;
  auto& os = console::out;
  
  os << "Ola Mundo!" << environment::new_line;
  os << "What is your name: ";
  auto name = string::empty_string;
  is >> name;
  
  os << "Buenos Dias, " << name << environment::new_line;
}

// This code produces the following output :
//
// Ola Mundo!
// What is your name: James
// Buenos Dias, James!
