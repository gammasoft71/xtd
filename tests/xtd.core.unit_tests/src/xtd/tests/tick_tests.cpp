#include <xtd/tick>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(tick_tests) {
    void test_method_(tick_denominator) {
      assert::are_equal(10000000LL, tick::den, csf_);
    }
    
    void test_method_(tick_numerator) {
      assert::are_equal(1LL, tick::num, csf_);
    }
  };
}
