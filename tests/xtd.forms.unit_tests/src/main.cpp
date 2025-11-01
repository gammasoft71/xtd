#include <xtd/tunit/console_unit_test>
#include <xtd/startup>

namespace xtd::forms {
  class unit_tests {
  public:
    static auto main() {
      xtd::tunit::settings::default_settings().brief(environment::get_environment_variable("CI") == "true");
      return xtd::tunit::console_unit_test {}.run();
    }
  };
}

startup_(xtd::forms::unit_tests::main);
