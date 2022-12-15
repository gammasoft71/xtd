#include <xtd/xtd>

using namespace xtd;

int main() {
  console::out << ustring::format("{},{,10}!", "Hello", "World"_s) << environment::new_line;
}

// This code produces the following output:
//
// Hello,     World!
