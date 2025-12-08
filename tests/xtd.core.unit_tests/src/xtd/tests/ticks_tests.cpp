#include <xtd/ticks>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(ticks_tests) {
    auto test_method_(create_ticks_0) {
      ticks t(0);
      assert::are_equal(0, t.count());
    }
    
    auto test_method_(create_ticks_1000) {
      ticks t(1000);
      assert::are_equal(1000, t.count());
    }
    
    auto test_method_(cast_ticks_to_nanoseconds) {
      ticks t(42);
      assert::are_equal(std::chrono::nanoseconds {4200}, std::chrono::duration_cast<std::chrono::nanoseconds>(t));
    }
    
    auto test_method_(cast_ticks_to_milliseconds) {
      ticks t(423567);
      assert::are_equal(std::chrono::milliseconds {42}, std::chrono::duration_cast<std::chrono::milliseconds>(t));
    }
  };
}
