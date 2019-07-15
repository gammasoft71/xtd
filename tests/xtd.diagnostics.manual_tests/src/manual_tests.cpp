#include <xtd/xtd.diagnostics>
#include <iostream>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

// The main entry point for the application.
int main() {
  //cout << "Hello, World!" << endl;
  default_trace_listener dtl;
  dtl << "Message1";
  dtl << " next";
}

// This code produces the following output with colors:
//
// Hello, World!
