#include <xtd/xtd>
#include <iostream>

using namespace std;
using namespace xtd;

namespace examples {
  class program {
  public:
    static void main(const std::vector<std::string>& args) {
      cout << ustring::format("args = {}", ustring::join(", ", args)) << endl;
      environment::exit_code(42);
    }
  };
}

startup_(examples::program);

// This code produces the following output if one two "three four" five six are entered on command line:
//
// args = one, two, three four, five, six
