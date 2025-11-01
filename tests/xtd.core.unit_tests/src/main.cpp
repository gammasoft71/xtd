#include <xtd/tunit/console_unit_test>
#include <xtd/startup>

namespace xtd {
  class unit_tests {
  public:
    static auto main() {
      settings::default_settings().brief(environment::get_environment_variable("CI") == "true");
      return console_unit_test {}.run();
    }
  };
}

startup_(unit_tests::main);
