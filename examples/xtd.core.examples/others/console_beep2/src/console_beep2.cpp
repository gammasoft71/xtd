#include <xtd/threading/thread>
#include <xtd/beep>
#include <xtd/console>
#include <xtd/environment>
#include <xtd/int32_object>
#include <xtd/literals>

using namespace xtd;

auto main(int argc, char* argv[]) -> int {
  int x = 0;
  //
  if ((argc == 2) && (int32_object::try_parse(argv[1], x) == true) && ((x >= 1) && (x <= 9))) {
    for (auto i = 1; i <= x; i++) {
      console::out << ustring::format("Beep number {}.", i) << beep() << environment::new_line;
      threading::thread::sleep(100_ms);
    }
  } else
    console::out << "Usage: Enter the number of times (between 1 and 9) to beep." << environment::new_line;
}
