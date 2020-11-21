#include <xtd/xtd.core>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  istream& is = console::in;
  ostream& os = console::out;
  
  os << "Hola Mundo!" << endl;
  os << "What is your name: ";
  string name;
  is >> name;
  
  os << "Buenos Dias, " << name << endl;
}

// This code produces the following output:
//
// Hola Mundo!
// What is your name: James
// Buenos Dias, James!
