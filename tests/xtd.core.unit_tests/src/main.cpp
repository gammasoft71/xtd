#include <xtd/tunit/tunit_main.h>

auto main(int argc, char* argv[])->int {
  return xtd::startup::safe_run(tunit_main_, argc, argv);
}
