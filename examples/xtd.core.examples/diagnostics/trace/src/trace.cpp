// Specify -DTRACE when compiling or add #define TRACE in the source file.

#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

int main() {
  trace::listeners().push_back(make_shared<ostream_trace_listener>(console::out));
  trace::auto_flush(true);
  trace::indent();
  trace::write_line("Entering Main");
  console::write_line("Hello World.");
  trace::write_line("Exiting Main");
  trace::unindent();
}

// This code produces the following output :
//
//     Entering Main
// Hello World.
//     Exiting Main
