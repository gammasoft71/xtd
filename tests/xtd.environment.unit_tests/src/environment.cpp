#include <xtd/xtd.environment>
#include <xtd/tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_environment) {
  public:
    void test_method_(new_line) {
      assert::are_equal_("\n", environment::new_line());
    }
  };
}
