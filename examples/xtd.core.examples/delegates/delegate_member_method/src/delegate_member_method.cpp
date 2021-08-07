#include <xtd/xtd>
#include <iostream>
#include <string>

using namespace std;
using namespace xtd;

class test_delegate {
public:
  test_delegate() = default;
  
  void write(const ustring& str) {
    console::write_line(str);
  }
};

int main() {
  // use delegate as std::function with std::bind
  test_delegate td;
  delegate<void(const ustring& str)> writer(td, &test_delegate::write);
  
  writer("String to write");
}

// This code produces the following output:
//
// String to write
