#include <xtd/console>
#include <xtd/environment>
#include <xtd/startup>

using namespace std;
using namespace xtd;

namespace startup3_example {
  class program {
  public:
    static void main(const vector<ustring>& args) {
      // Write arguments to the console output
      for (auto arg : args)
        console::write_line(arg);
        
      // return 42
      environment::exit_code(42);
    }
  };
}

auto main(int argc, char* argv[])->int {
  return startup::safe_run(startup3_example::program::main, argc, argv);
}
// Is approximately the same as :
//
// auto main(int argc, char* argv[])->int {
//   try {
//     startup3_example::program::main({argv + 1, argv + argc});
//     return environment::exit_code();
//   } catch(const std::exception& e) {
//     if (dynamic_cast<const system_exception*>(&e)) console::write_line(static_cast<const system_exception&>(e).to_string());
//     else console::write_line(e.what());
//   } catch(...) {
//     console::write_line("Unhandled exception: Unknown exception occurred");
//   }
// }


// This code produces the following output if one two "three four" five are entered on command line:
//
// one
// two
// three four
// five
