#include <xtd/console>
#include <xtd/int32_object>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;
using namespace xtd;

auto main(int argc, char* argv[])->int {
  int x = 0;
  //
  if ((argc == 2) && (int32_object::try_parse(argv[1], x) == true) && ((x >= 1) && (x <= 9))) {
    for (int i = 1; i <= x; i++) {
      console::write_line("Beep number {}.", i);
      console::beep();
      sleep_for(milliseconds {100});
    }
  } else
    console::write_line("Usage: Enter the number of times (between 1 and 9) to beep.");
}

// This code produces the following output if 3 is entered on command line:
//
// Beep number 1.
// Beep number 2.
// Beep number 3.

