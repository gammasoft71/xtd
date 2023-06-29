#include <xtd/tick.h>
#include <xtd/tunit/assert.h>
#include <xtd/tunit/test_class_attribute.h>
#include <xtd/tunit/test_method_attribute.h>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(tick_tests) {
  public:
    void test_method_(tick_denominator) {
      assert::are_equal(10000000LL, tick::den, csf_);
    }
    
    void test_method_(tick_numerator) {
      assert::are_equal(1LL, tick::num, csf_);
    }
  };
}
