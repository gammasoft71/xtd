#include <xtd/xtd>

using namespace std;
using namespace std::this_thread;
using namespace xtd;

namespace environment_program_exit_example {
  class program static_ {
  public:
    // The main entry point for the application.
    static auto main() {
      environment::program_exit += [] {
        console::write_line("The program is stopped!");
      };
      
      console::write_line("Start");
      // Do something...
      auto do_something_thread = thread([] {
        for (auto step = 0; step < 50; ++step) {
          console::write('.');
          sleep_for(100_ms);
        }
        console::write_line();
      });
      do_something_thread.join();
      console::write_line("End");
      
      // Uncomment the following lines to see the result with the environment::exit method.
      //environment::exit(exit_status::success);
      //console::write_line("After exit");
    }
  };
}

startup_(environment_program_exit_example::program);

// This code produces the following output :
//
// Start
// ..................................................
// End
// The program is stopped!

