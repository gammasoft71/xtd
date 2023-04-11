#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace main3_example {
  class program {
  public:
    static void main(const vector<ustring>& args) {
      // Write arguments to the console output
      for (ustring arg : args)
        console::write_line(arg);
        
      // return 42
      environment::exit_code(42);
    }
  };
}

startup_(main3_example::program);
// startup_(main3_example::program); is same as :
//
// auto main(int argc, char* argv[])->int {
//   main3_example::program::main({argv + 1, argv + argc});
//   return environment::exit_code();
// }


// This code produces the following output if one two "three four" five are entered on command line:
//
// one
// two
// three four
// five
