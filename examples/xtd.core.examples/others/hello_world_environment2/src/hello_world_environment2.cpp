#include <xtd/xtd>

using namespace xtd;

int main() {
  console::out << "Hello, " << environment::user_name() << "!" << environment::new_line;
}

// This code can produces the following output:
//
// Hello, gammasoft71!
