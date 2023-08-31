#include <xtd/console>
#include <xtd/environment>
#include <xtd/startup>

using namespace xtd;

namespace startup_example {
  class program {
  public:
    static auto main(const std::vector<ustring>& args) {
      console::write_line("args = {}", ustring::join(", ", args));
      environment::exit_code(42);
    }
  };
}

startup_(startup_example::program::main);

// This code produces the following output if one two "three four" five six are entered on command line:
//
// args = one, two, three four, five, six
