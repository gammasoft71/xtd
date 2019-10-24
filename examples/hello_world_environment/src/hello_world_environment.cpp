#include <xtd/xtd.core>
#include <iostream>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  cout << "Hello, " << environment::user_name() << "!" << endl;
}

// This code can produces the following output:
//
// Hello, gammasoft71!
