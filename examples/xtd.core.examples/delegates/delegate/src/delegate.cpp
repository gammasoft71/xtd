#include <xtd/xtd>

auto goodbye(const string& s) -> void {
  console::write_line("Goodbye {}", s);
}

class object {
public:
  auto hello(const string& s) -> void {
    console::write_line("Hello {}", s);
  }
};

auto main() -> int {
  using example_function = delegate<void(const string&)>;
  auto instance = ::object {};
  auto str = string {"World"};
  
  //equivanet to : example_function f = {std::bind(&::object::hello, &instance, std::placeholders::_1)};
  auto f = example_function {instance, &::object::hello};
  
  // equivalent to : instance.hello(str)
  f(str);
  f = goodbye;
  
  // equivalent to : goodbye(str)
  f(str);
  return 0;
}

// This code produces the following output :
//
// Hello, World
// Goodbye, World
