#include <xtd/xtd>
#include <string>

using namespace std;
using namespace xtd;

int main() {
  console::out << "Hello ";
  console::out << "World!" << endl;
  console::out << "Enter your name: ";
  ustring name;
  console::in >> name;
  console::out << "Good day, ";
  console::out << name;
  console::out << "!" << endl;
}

// This code produces the following output:
//
// Hello World!
// Enter your name: James
// Good day, James!
