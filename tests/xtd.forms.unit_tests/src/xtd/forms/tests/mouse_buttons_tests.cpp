#include <xtd/forms/mouse_buttons>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(mouse_buttons_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(mouse_buttons::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(mouse_buttons::none), csf_);
      assert::are_equal(mouse_buttons::none, enum_object<>::parse<mouse_buttons>("none"), csf_);
    }
    
    void test_method_(left) {
      assert::are_equal(1048576, enum_object<>::to_int32(mouse_buttons::left), csf_);
      assert::are_equal("left", enum_object<>::to_string(mouse_buttons::left), csf_);
      assert::are_equal(mouse_buttons::left, enum_object<>::parse<mouse_buttons>("left"), csf_);
    }
    
    void test_method_(right) {
      assert::are_equal(2097152, enum_object<>::to_int32(mouse_buttons::right), csf_);
      assert::are_equal("right", enum_object<>::to_string(mouse_buttons::right), csf_);
      assert::are_equal(mouse_buttons::right, enum_object<>::parse<mouse_buttons>("right"), csf_);
    }
    
    void test_method_(middle) {
      assert::are_equal(4194304, enum_object<>::to_int32(mouse_buttons::middle), csf_);
      assert::are_equal("middle", enum_object<>::to_string(mouse_buttons::middle), csf_);
      assert::are_equal(mouse_buttons::middle, enum_object<>::parse<mouse_buttons>("middle"), csf_);
    }
    
    void test_method_(x_button1) {
      assert::are_equal(8388608, enum_object<>::to_int32(mouse_buttons::x_button1), csf_);
      assert::are_equal("x_button1", enum_object<>::to_string(mouse_buttons::x_button1), csf_);
      assert::are_equal(mouse_buttons::x_button1, enum_object<>::parse<mouse_buttons>("x_button1"), csf_);
    }
    
    void test_method_(x_button2) {
      assert::are_equal(16777216, enum_object<>::to_int32(mouse_buttons::x_button2), csf_);
      assert::are_equal("x_button2", enum_object<>::to_string(mouse_buttons::x_button2), csf_);
      assert::are_equal(mouse_buttons::x_button2, enum_object<>::parse<mouse_buttons>("x_button2"), csf_);
    }
  };
}

