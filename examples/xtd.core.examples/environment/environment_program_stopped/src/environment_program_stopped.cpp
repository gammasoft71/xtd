#include <xtd/xtd>

using namespace xtd;

namespace environment_cancel_sgnal_example {
  class program static_ {
  public:
    // The main entry point for the application.
    static auto main() {
      environment::program_stopped += [] {
        console::write_line("The program is stopped!");
      };
    }
  };
}

startup_(environment_cancel_sgnal_example::program);

// This code produces the following output :
//
// The program is stopped!
