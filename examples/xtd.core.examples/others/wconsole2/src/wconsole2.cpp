#include <xtd/xtd>
#include <string>

using namespace std;
using namespace xtd;

int main() {
  console::out << L"Hello "_s;
  console::out << L"World!"_s << endl;
  console::out << L"Enter your name: "_s;
  ustring name;
  console::in >> name;
  console::out << L"Good day, "_s;
  console::out << name;
  console::out << L"!"_s << endl;
}

// This code produces the following output:
//
// Hello World!
// Enter your name: James
// Good day, James!
