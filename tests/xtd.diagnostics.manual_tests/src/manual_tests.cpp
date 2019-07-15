#include <xtd/xtd.diagnostics>
#include <iostream>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

// The main entry point for the application.
int main() {
  //cout << "Hello, World!" << endl;
  console_trace_listener dtl;
  dtl.write_line(xtd::strings::format("level {}", dtl.indent_level()));
  dtl.indent_level(1);
  dtl.write_line(xtd::strings::format("level {}", dtl.indent_level()));
  dtl.indent_level(2);
  dtl.write_line(xtd::strings::format("level {}", dtl.indent_level()));
  dtl.indent_level(0);
  dtl.write_line(xtd::strings::format("level {}", dtl.indent_level()));
  cout << "end ;-)" << endl;
}

// This code produces the following output with colors:
//
// Hello, World!
