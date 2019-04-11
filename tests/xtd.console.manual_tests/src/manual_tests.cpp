#include <atomic>
#include <xtd/console>

using namespace std;
using namespace std::string_literals;

// The main entry point for the application.
int main() {
  xtd::console::output_code_page(65001);
  wcout << xtd::strings::format(L"{}, {}!", L"Hello", L"World"s) << endl;
}
