#include <xtd/forms/tick_style>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(tick_style_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(tick_style::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(tick_style::none), csf_);
      assert::are_equal(tick_style::none, enum_object<>::parse<tick_style>("none"), csf_);
    }
    
    void test_method_(top_left) {
      assert::are_equal(1, enum_object<>::to_int32(tick_style::top_left), csf_);
      assert::are_equal("top_left", enum_object<>::to_string(tick_style::top_left), csf_);
      assert::are_equal(tick_style::top_left, enum_object<>::parse<tick_style>("top_left"), csf_);
    }
    
    void test_method_(bottom_right) {
      assert::are_equal(2, enum_object<>::to_int32(tick_style::bottom_right), csf_);
      assert::are_equal("bottom_right", enum_object<>::to_string(tick_style::bottom_right), csf_);
      assert::are_equal(tick_style::bottom_right, enum_object<>::parse<tick_style>("bottom_right"), csf_);
    }
    
    void test_method_(both) {
      assert::are_equal(3, enum_object<>::to_int32(tick_style::both), csf_);
      assert::are_equal("both", enum_object<>::to_string(tick_style::both), csf_);
      assert::are_equal(tick_style::both, enum_object<>::parse<tick_style>("both"), csf_);
    }
  };
}
