#include <xtd/console>

using namespace std;
using namespace xtd;

auto main() -> int {
  auto& is = console::in;
  auto& os = console::out;
  
  os << "Ola Mundo!" << endl;
  os << "What is your name: ";
  auto name = ustring::empty_string;
  is >> name;
  
  os << "Buenos Dias, " << name << endl;
}

// This code produces the following output:
//
// Ola Mundo!
// What is your name: James
// Buenos Dias, James!
