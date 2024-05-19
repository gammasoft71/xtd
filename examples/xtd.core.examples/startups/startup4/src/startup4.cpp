#include <xtd/console>
#include <xtd/startup>

using namespace xtd;

namespace startup4_example {
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

auto main() -> int {
  return startup::safe_run(startup4_example::program::main);
}
// Is approximately the same as :
//
// auto main() -> int {
//   try {
//     auto args = xtd::environment::get_command_line_args();
//     return startup34example::program::main({args.begin() + 1, args.end()});
//   } catch(const std::exception& e) {
//     if (dynamic_cast<const xtd::system_exception*>(&e)) xtd::console::write_line(static_cast<const xtd::system_exception&>(e).to_string());
//     else xtd::console::write_line(e.what());
//   } catch(...) {
//     xtd::console::write_line("Unhandled exception: Unknown exception occurred");
//   }
// }


// This code produces the following output if one two "three four" five are entered on command line:
//
// one
// two
// three four
// five
