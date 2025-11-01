#include <xtd/tunit/console_unit_test>
#include <xtd/startup>

struct __xtd_initialize_all_cultures__ {
  __xtd_initialize_all_cultures__() {culture_info::initialize_all_cultures();}
} __initialize_all_cultures__;

namespace xtd::core {
  class unit_tests {
  public:
    static auto main() {
      xtd::tunit::settings::default_settings().brief(environment::get_environment_variable("CI") == "true");
      return xtd::tunit::console_unit_test {}.run();
    }
  };
}

startup_(xtd::core::unit_tests::main);
