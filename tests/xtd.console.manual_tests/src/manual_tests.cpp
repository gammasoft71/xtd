#include <xtd/console>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  console::write_line("{0:D} 0x{0:X} 0{0:O} 0b{0:B}", 42);
  cout << format("{} {}", 42, "test") << endl;
}
