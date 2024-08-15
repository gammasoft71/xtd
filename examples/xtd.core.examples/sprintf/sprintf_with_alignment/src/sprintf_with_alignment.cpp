#include <xtd/xtd>

using namespace xtd;

int main() {
  console::out << string::sprintf("[%10d]", 42) << environment::new_line;
  console::out << string::sprintf("[%-10d]", 42) << environment::new_line;
  console::out << string::sprintf("[%010d]", 42) << environment::new_line;
}

// This code produces the following output :
//
// [        42]
// [42        ]
// [0000000042]
