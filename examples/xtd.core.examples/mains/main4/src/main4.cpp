#include <xtd/console>
#include <xtd/environment>
#include <xtd/startup>

using namespace xtd;

namespace main4_example {
  class program {
  public:
    static int main(const std::vector<ustring>& args) {
      // Write arguments to the console output
      for (auto arg : args)
        console::write_line(arg);
        
      return 42;
    }
  };
}

startup_(main4_example::program::main);
// Is the same as :
//
// auto main() -> int {
//   return startup::safe_run(main4_example::program::main);
// }


// This code produces the following output if one two "three four" five are entered on command line:
//
// one
// two
// three four
// five
