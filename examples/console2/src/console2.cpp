#include <console/console>
#include <string>

using namespace gammasoft;
using namespace std;

// The main entry point for the application.
int main(int argc, char* argv[]) {
  console::out << "Hello ";
  console::out << "World!" << endl;
  console::out << "Enter your name: ";
  string name;
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
