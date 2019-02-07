#include <console/console>
#include <fstream>

using namespace gammasoft;
using namespace std;

// The main entry point for the application.
int main() {
  cout << "Hello, World!" << endl;
  console::out << "Hello, World!" << std::endl;
  console::write_line("Hello, World!");
  wcout << L"Hello, World!" << endl;
  wconsole::out << L"Hello, World!" << std::endl;
  wconsole::write_line("Hello, World!");
}
