#include <xtd/threading/thread>
#include <xtd/console>
#include <xtd/int32_object>

using namespace xtd;
using namespace xtd::threading;

auto main(int argc, char* argv[])->int {
  auto x = 0;
  //
  if ((argc == 2) && (int32_object::try_parse(argv[1], x) == true) && ((x >= 1) && (x <= 9))) {
    for (auto i = 1; i <= x; ++i) {
      console::write_line("Beep number {}.", i);
      console::beep();
      thread::sleep(100_ms);
    }
  } else
    console::write_line("Usage: Enter the number of times (between 1 and 9) to beep.");
}

// This code produces the following output if 3 is entered on command line:
//
// Beep number 1.
// Beep number 2.
// Beep number 3.

