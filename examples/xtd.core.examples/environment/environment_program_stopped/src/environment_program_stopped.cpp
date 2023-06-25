#include <xtd/xtd>

using namespace std;
using namespace std::this_thread;
using namespace xtd;

namespace environment_cancel_sgnal_example {
  class program static_ {
  public:
    // The main entry point for the application.
    static auto main() {
      environment::program_stopped += [] {
        console::write_line("The program is stopped!");
      };
      
      console::write_line("Start");
      // Do something...
      auto t = thread([] {
        for (auto step = 0; step < 50; ++step) {
          console::write('.');
          sleep_for(100_ms);
        }
        console::write_line();
      });
      t.join();
      console::write_line("End");
    }
  };
}

startup_(environment_cancel_sgnal_example::program);

// This code produces the following output :
//
// Start
// ..................................................
// End
// The program is stopped!

