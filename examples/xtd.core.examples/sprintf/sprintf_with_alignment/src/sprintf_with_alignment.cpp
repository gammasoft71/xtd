#include <xtd/xtd>

using namespace xtd;

int main() {
  console::out << ustring::sprintf("[%10d]", 42) << environment::new_line;
  console::out << ustring::sprintf("[%-10d]", 42) << environment::new_line;
  console::out << ustring::sprintf("[%010d]", 42) << environment::new_line;
}

// This code produces the following output :
//
// [        42]
// [42        ]
// [0000000042]
