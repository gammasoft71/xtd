#include <xtd/as>
#include <xtd/interface>
#include <xtd/console>

using namespace std;
using namespace xtd;

namespace interface2_example {
  class istringable : public interface {
  public:
    virtual ustring to_string() const = 0;
  };
  
  class program : public istringable {
  public:
    program() = default;
    ustring to_string() const override {return "program";}
  };
}

auto main() -> int {
  auto stringable = as<interface2_example::istringable>(make_shared<interface2_example::program>());
  console::write_line(stringable->to_string());
}

// This code produces the following output:
//
// program
