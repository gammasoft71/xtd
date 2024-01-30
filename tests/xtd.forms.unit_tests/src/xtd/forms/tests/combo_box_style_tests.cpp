#include <xtd/forms/combo_box_style>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(combo_box_style_tests) {
  public:
    void test_method_(simple) {
      assert::are_equal(1, enum_object<>::to_int32(combo_box_style::simple), csf_);
      assert::are_equal("simple", enum_object<>::to_string(combo_box_style::simple), csf_);
      assert::are_equal(combo_box_style::simple, enum_object<>::parse<combo_box_style>("simple"), csf_);
    }
    
    void test_method_(drop_down) {
      assert::are_equal(2, enum_object<>::to_int32(combo_box_style::drop_down), csf_);
      assert::are_equal("drop_down", enum_object<>::to_string(combo_box_style::drop_down), csf_);
      assert::are_equal(combo_box_style::drop_down, enum_object<>::parse<combo_box_style>("drop_down"), csf_);
    }
    
    void test_method_(drop_down_list) {
      assert::are_equal(3, enum_object<>::to_int32(combo_box_style::drop_down_list), csf_);
      assert::are_equal("drop_down_list", enum_object<>::to_string(combo_box_style::drop_down_list), csf_);
      assert::are_equal(combo_box_style::drop_down_list, enum_object<>::parse<combo_box_style>("drop_down_list"), csf_);
    }
  };
}

