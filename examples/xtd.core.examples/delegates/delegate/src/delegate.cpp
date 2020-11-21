#include <xtd/xtd.core>

using namespace std;
using namespace xtd;

void goodbye(const string& s) {
  console::write_line("Goodbye {}", s);
}

class object {
public:
  void hello(const std::string& s) {
    console::write_line("Hello {}", s);
  }
};

int main() {
  using example_function = delegate<void(const string&)>;
  ::object instance;
  string str("World");
  //example_function f = {instance, &::object::hello};
  example_function f = {std::bind(&::object::hello, &instance, std::placeholders::_1)};

  // equivalent to instance.hello(str)
  f(str);
  f = goodbye;
  
  // equivalent to goodbye(str)
  f(str);
  return 0;
}

// This code produces the following output:
//
// Hello, World
// Goodbye, World
