#include <xtd/console>
#include <xtd/environment>
#include <xtd/startup>

using namespace xtd;

namespace main4_example {
  class program {
  public:
    static int main(auto args) {
      // Write arguments to the console output
      for (auto arg : args)
        console::write_line(arg);
        
      return 42;
    }
  };
}

startup_(main4_example::program);
// startup_(main4_example::program); is same as :
//
// auto main(int argc, char* argv[])->int {
//   return main4_example::program::main({argv + 1, argv + argc});
// }


// This code produces the following output if one two "three four" five are entered on command line:
//
// one
// two
// three four
// five
