#include <xtd/tunit/tunit_main>

auto main(int argc, char* argv[])->int {
  return xtd::startup::safe_run(tunit_main_, argc, argv);
}
