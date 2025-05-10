#include <xtd/tunit/console_unit_test>
#include <xtd/startup>

namespace xtd::drawing {
  class unit_tests {
  public:
    static auto main() -> int {
#if defined(__XTD_BUILD_WITH_CONTINUOUS_INTEGRATION_SYSTEM__)
      xtd::tunit::settings::default_settings().brief(true);
#endif
      return xtd::tunit::console_unit_test {}.run();
    }
  };
}

startup_(xtd::drawing::unit_tests::main);
