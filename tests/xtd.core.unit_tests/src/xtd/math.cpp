#include <xtd/math.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_math) {
  public:
    void test_method_(e) {
      assert::are_equal(2.7182818284590452354, math::e);
    }

    void test_method_(pi) {
      assert::are_equal(3.14159265358979323846, math::pi);
    }

    void test_method_(tau) {
      assert::are_equal(2.7182818284590451, math::tau);
    }
  };
}
