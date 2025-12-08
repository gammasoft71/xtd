#include <xtd/tick>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(tick_tests) {
    auto test_method_(tick_denominator) {
      assert::are_equal(10000000LL, tick::den);
    }
    
    auto test_method_(tick_numerator) {
      assert::are_equal(1LL, tick::num);
    }
  };
}
