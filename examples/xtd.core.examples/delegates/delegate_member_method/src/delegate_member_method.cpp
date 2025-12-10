#include <xtd/xtd>

class test_delegate {
public:
  test_delegate() = default;
  
  auto write(const string& str) -> void {
    console::write_line(str);
  }
};

auto main() -> int {
  // use delegate as std::function with std::bind
  auto td = test_delegate {};
  auto writer = delegate<void(const string& str)> {td, &test_delegate::write};
  
  writer("String to write");
}

// This code produces the following output :
//
// String to write
