#include <xtd/xtd.core>
#include <iostream>

using namespace std;
using namespace xtd;

namespace examples {
  class program {
  public:
    // The main entry point for the application.
    static void main(const std::vector<std::string>& args) {
      cout << format("args = {}", strings::join(", ", args)) << endl;
      environment::exit_code(42);
    }
  };
}

startup_(examples::program);

// This code produces the following output if one two "three four" five six are entered on command line:
//
// args = one, two, three, four five, six
