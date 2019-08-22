#define TRACE
#include <xtd/xtd.diagnostics>
#include <iostream>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  ctrace << "Hello, World!" << endl;
}

// This code can produces the following output debug:
//
// Hello, World!
