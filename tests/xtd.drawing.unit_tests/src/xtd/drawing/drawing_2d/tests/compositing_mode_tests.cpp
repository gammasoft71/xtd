#include <xtd/drawing/drawing_2d/compositing_mode>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::drawing_2d;
using namespace xtd::tunit;

namespace xtd::drawing::drawing_2d::tests {
  class test_class_(compositing_mode_tests) {
    void test_method_(source_over) {
      assert::are_equal(0, enum_object<>::to_int32(compositing_mode::source_over), csf_);
      assert::are_equal("source_over", enum_object<>::to_string(compositing_mode::source_over), csf_);
      assert::are_equal(compositing_mode::source_over, enum_object<>::parse<compositing_mode>("source_over"), csf_);
    }
    
    void test_method_(source_copy) {
      assert::are_equal(1, enum_object<>::to_int32(compositing_mode::source_copy), csf_);
      assert::are_equal("source_copy", enum_object<>::to_string(compositing_mode::source_copy), csf_);
      assert::are_equal(compositing_mode::source_copy, enum_object<>::parse<compositing_mode>("source_copy"), csf_);
    }
  };
}
