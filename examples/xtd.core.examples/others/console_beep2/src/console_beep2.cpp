#include <xtd/xtd>
#include <thread>

using namespace std::chrono;
using namespace std::this_thread;
using namespace xtd;

auto main(int argc, char* argv[])->int {
  int x = 0;
  //
  if ((argc == 2) && (int32_object::try_parse(argv[1], x) == true) && ((x >= 1) && (x <= 9))) {
    for (int i = 1; i <= x; i++) {
      console::out << ustring::format("Beep number {}.", i) << beep() << environment::new_line;
      sleep_for(milliseconds(100));
    }
  } else
    console::out << "Usage: Enter the number of times (between 1 and 9) to beep." << environment::new_line;
}
