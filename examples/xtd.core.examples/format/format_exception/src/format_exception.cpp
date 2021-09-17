#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << ustring::format("{}", exception()) << endl;
  cout << ustring::format("{}", invalid_argument("Invvalid argument")) << endl;
  cout << ustring::format("{}", system_exception("System exception")) << endl;
  cout << ustring::format("{}", argument_out_of_range_exception("Argument out of range exception")) << endl;
}

// This code produces the following output :
//
// exception: std::exception
// exception: Invvalid argument
// xtd::system_exception : System exception
//    at main [0x00005620] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/format/format_exception/Debug/format_exception:line 0
// xtd::argument_out_of_range_exception : Argument out of range exception
//    at main [0x00005620] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/format/format_exception/Debug/format_exception:line 0
