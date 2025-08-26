#include <xtd/xtd>

namespace interface2_example {
  class istringable : public interface {
  public:
    virtual string to_string() const = 0;
  };
  
  class program : public istringable {
  public:
    program() = default;
    string to_string() const override {return "program";}
  };
}

auto main() -> int {
  auto stringable = as<interface2_example::istringable>(new_ptr<interface2_example::program>());
  console::write_line(stringable->to_string());
}

// This code produces the following output :
//
// program
