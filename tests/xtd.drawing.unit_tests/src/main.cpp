#include <xtd/tunit/console_unit_test>
#include <xtd/startup>

namespace xtd::drawing {
  class unit_tests {
  public:
    static auto main() {
      settings::default_settings().brief(true);
      return console_unit_test {}.run();
    }
  };
}

startup_(unit_tests::main);
