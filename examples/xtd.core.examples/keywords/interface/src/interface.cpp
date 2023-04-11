#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace interface_example {
  class istringable interface_ {
  public:
    virtual ustring to_string() const = 0;
  };
  
  class program : public istringable {
  public:
    program() = default;
    ustring to_string() const override {return "program";}
  };
}

auto main()->int {
  std::shared_ptr<interface_example::istringable> stringable = std::make_shared<interface_example::program>();
  cout << stringable->to_string() << endl;
}

// This code produces the following output:
//
// program
