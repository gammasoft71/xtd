#define TRACE
#include <xtd/ctrace>

using namespace std;
using namespace xtd;

auto main() -> int {
  ctrace << "Hello, World!" << endl;
}

// This code produces the following debug output :
//
// Hello, World!
