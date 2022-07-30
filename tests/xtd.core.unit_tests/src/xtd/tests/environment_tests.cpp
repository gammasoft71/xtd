#include <xtd/environment.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(environment_tests) {
  public:
    void test_method_(new_line) {
      assert::are_equal("\n", environment::new_line(), csf_);
    }
  };
}
