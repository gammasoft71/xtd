#include <atomic>
#include <xtd/console>

using namespace std;
using namespace std::string_literals;

// The main entry point for the application.
int main() {
  xtd::console::output_code_page(65001);

  stringstream ss;
  xtd::console::set_out(ss);
  xtd::console::write("{}, {}!", "Hello", "World"s);
  
  xtd::console::set_out(xtd::console::open_standard_output());
  xtd::console::write_line(ss.str());
}
