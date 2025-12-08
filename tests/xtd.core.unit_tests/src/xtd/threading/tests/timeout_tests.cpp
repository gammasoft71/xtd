#include <xtd/threading/timeout>
#include <xtd/tunit/assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::threading::tests {
  class test_class_(timeout_tests) {
    auto test_method_(infinite) {
      assert::are_equal(-1, timeout::infinite);
    }
    
    auto test_method_(infinite_time_span) {
      assert::are_equal(time_span {-1}, timeout::infinite_time_span);
    }
  };
}
