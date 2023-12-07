#include <xtd/io/directory>
#include <xtd/io/file>
#include <xtd/io/path>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::io;

class core_manual_test {
public:
  static auto entry_point() {
      console::write_line("Hello, World!");
  }
};

auto main()->int {
  startup::safe_run(core_manual_test::entry_point);
}
