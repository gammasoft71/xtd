#include <atomic>
#include <xtd/console>

using namespace std;
using namespace std::string_literals;

// The main entry point for the application.
int main() {
  xtd::console::output_code_page(65001);
  auto out = xtd::console::open_standard_output();
  out << xtd::strings::format("{}, {}!", "Hello", "World"s) << endl;
}
