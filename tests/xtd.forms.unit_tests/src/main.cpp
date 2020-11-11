#include <xtd/xtd.forms>
#include <xtd/xtd.tunit>

using namespace xtd::forms;
using namespace xtd::tunit;

int main() {
  application::initialize();
  int result = console_unit_test().run();
  application::cleanup();
  return result;
}
