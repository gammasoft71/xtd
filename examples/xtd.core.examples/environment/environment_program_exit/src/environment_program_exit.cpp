#include <xtd/console>
#include <xtd/environment>
#include <xtd/startup>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace xtd;

namespace environment_program_exit_example {
  class program static_ {
  public:
    // The main entry point for the application.
    static auto main(auto args) {
      environment::program_exit += [](auto e) {
        console::write_line("The program is stopped {}ly!", e.exit_mode());
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
      
      if (args.size() == 1 && args[0] == "exit") {
        console::write_line("Before environment::exit");
        environment::exit(exit_status::success);
        console::write_line("After environment::exit");
      } else if (args.size() == 1 && args[0] == "quick_exit") {
        console::write_line("Before environment::quick_exit");
        environment::quick_exit(exit_status::success);
        console::write_line("After environment::quick_exit");
      }
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

