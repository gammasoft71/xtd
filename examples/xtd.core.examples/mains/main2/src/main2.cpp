#include <xtd/xtd>

using namespace xtd;

namespace main2_example {
  class program {
  public:
    static int main() {
      // Write arguments to the console output
      for (ustring arg : environment::get_command_line_args())
        console::write_line(arg);
        
      return 42;
    }
  };
}

startup_(main2_example::program);
// startup_(main2_example::program); is same as :
//
// auto main(int argc, char* argv[])->int {
//   return main2_example::program::main();
// }


// This code produces the following output if one two "three four" five are entered on command line:
//
// /!---OMITTED---!/main2
// one
// two
// three four
// five
