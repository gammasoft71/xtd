#include <xtd/xtd.diagnostics>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

// The main entry point for the application.
int main() {
  cdebug << "This is  message" << std::endl;
  debug::indent();
  cdebug << strings::format("Second message with int={}", 42) << std::endl;
  debug::unindent();
  cdebug << strings::format("Other with bool={}", true) << std::endl;
}

// This code produces the following output with colors:
//
// Hello, World!
