#include <xtd/tunit/console_unit_test>
#include <xtd/startup>

namespace xtd::forms {
  class unit_tests {
  public:
    static auto main() {
      settings::default_settings().brief(true);
      return tunit::console_unit_test {}.run();
    }
  };
}

startup_(unit_tests::main);
