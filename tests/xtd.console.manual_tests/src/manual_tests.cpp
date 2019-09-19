#include <atomic>
#include <xtd/xtd.console>

using namespace std;
using namespace xtd;
using namespace std::string_literals;

// The main entry point for the application.
int main() {
  cout << xtd::strings::format("{}, {}!", "Hello", "World"s) << endl;
}
