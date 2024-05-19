#include <xtd/console>
#include <xtd/delegate>

using namespace xtd;

class test_delegate {
public:
  test_delegate() = default;
  
  void write(const ustring& str) {
    console::write_line(str);
  }
};

auto main() -> int {
  // use delegate as std::function with std::bind
  auto td = test_delegate {};
  auto writer = delegate<void(const ustring& str)> {td, &test_delegate::write};
  
  writer("String to write");
}

// This code produces the following output:
//
// String to write
