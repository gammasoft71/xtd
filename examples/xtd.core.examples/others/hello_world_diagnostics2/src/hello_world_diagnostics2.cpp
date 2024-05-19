#define TRACE
#include <xtd/ctrace>

using namespace std;
using namespace xtd;

auto main() -> int {
  ctrace << "Hello, World!" << endl;
}

// This code can produces the following output debug:
//
// Hello, World!
