#include <xtd/xtd>

auto main() -> int {
  // use delegate as std::function
  auto writer = delegate<void(const string& str)> {[](const string & str)  {
    console::out << str << environment::new_line;
  }};
  
  writer("Value to write");
}

// This code produces the following output :
//
// Hello, World!
