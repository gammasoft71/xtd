#include <xtd/xtd>

using namespace std;
using namespace xtd;

void goodbye(const ustring& s) {
  console::write_line("Goodbye {}", s);
}

class object {
public:
  void hello(const ustring& s) {
    console::write_line("Hello {}", s);
  }
};

auto main()->int {
  using example_function = delegate<void(const ustring&)>;
  ::object instance;
  ustring str("World");
  
  //equivanet to : example_function f = {std::bind(&::object::hello, &instance, std::placeholders::_1)};
  example_function f = {instance, &::object::hello};
  
  // equivalent to : instance.hello(str)
  f(str);
  f = goodbye;
  
  // equivalent to : goodbye(str)
  f(str);
  return 0;
}

// This code produces the following output:
//
// Hello, World
// Goodbye, World
