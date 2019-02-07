#include <console/console>
#include <fstream>

using namespace gammasoft;

// The main entry point for the application.
int main() {
  console::open_standard_output() << "console::is_out_redireted() = " << std::boolalpha << console::is_out_redireted() << std::endl;
  std::ofstream file("test.txt");
  console::set_out(file);
  console::open_standard_output() << "console::is_out_redireted() = " << console::is_out_redireted() << std::endl;
  console::out << "Hello, World!" << std::endl;
  console::set_out(console::open_standard_output());
  console::out << "Yessss" << std::endl;
}
