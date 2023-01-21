#include <xtd/xtd>

using namespace xtd;

namespace examples {
  class program {
  public:
    static auto main() {
      // Write arguments to the console output
      for (ustring arg : environment::get_command_line_args())
        console::write_line(arg);
        
      return 42;
    }
  };
}

startup_(examples::program);
// startup_(examples::program); is same as :
//
// auto main(int argc, char* argv[])->int {
//   return examples::program::main();
// }


// This code produces the following output if one two "three four" five are entered on command line:
//
// /!---OMITTED---!/main2
// one
// two
// three four
// five
