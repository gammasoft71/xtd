#include <xtd/console>
#include <xtd/environment>
#include <xtd/startup>

using namespace xtd;

namespace startup1_example {
  class program {
  public:
    static void main() {
      // Write arguments to the console output
      for (auto arg : environment::get_command_line_args())
        console::write_line(arg);
        
      // return 42
      environment::exit_code(42);
    }
  };
}

auto main() -> int {
  return startup::safe_run(startup1_example::program::main);
}
// Is approximately the same as :
//
// auto main() -> int {
//   try {
//     startup1_example::program::main();
//     return xtd::environment::exit_code();
//   } catch(const std::exception& e) {
//     if (dynamic_cast<const xtd::system_exception*>(&e)) xtd::console::write_line(static_cast<const xtd::system_exception&>(e).to_string());
//     else xtd::console::write_line(e.what());
//   } catch(...) {
//     xtd::console::write_line("Unhandled exception: Unknown exception occurred");
//   }
// }


// This code produces the following output if one two "three four" five are entered on command line:
//
// /!---OMITTED---!/startup1
// one
// two
// three four
// five
