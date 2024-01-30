#include <xtd/forms/visual_styles/toggle_button_state>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms::visual_styles;
using namespace xtd::tunit;

namespace xtd::forms::visual_styles::tests {
  class test_class_(toggle_button_state_tests) {
  public:
    void test_method_(unchecked_normal) {
      assert::are_equal(1, enum_object<>::to_int32(toggle_button_state::unchecked_normal), csf_);
      assert::are_equal("unchecked_normal", enum_object<>::to_string(toggle_button_state::unchecked_normal), csf_);
      assert::are_equal(toggle_button_state::unchecked_normal, enum_object<>::parse<toggle_button_state>("unchecked_normal"), csf_);
    }
    
    void test_method_(unchecked_hot) {
      assert::are_equal(2, enum_object<>::to_int32(toggle_button_state::unchecked_hot), csf_);
      assert::are_equal("unchecked_hot", enum_object<>::to_string(toggle_button_state::unchecked_hot), csf_);
      assert::are_equal(toggle_button_state::unchecked_hot, enum_object<>::parse<toggle_button_state>("unchecked_hot"), csf_);
    }
    
    void test_method_(unchecked_pressed) {
      assert::are_equal(3, enum_object<>::to_int32(toggle_button_state::unchecked_pressed), csf_);
      assert::are_equal("unchecked_pressed", enum_object<>::to_string(toggle_button_state::unchecked_pressed), csf_);
      assert::are_equal(toggle_button_state::unchecked_pressed, enum_object<>::parse<toggle_button_state>("unchecked_pressed"), csf_);
    }
    
    void test_method_(unchecked_disabled) {
      assert::are_equal(4, enum_object<>::to_int32(toggle_button_state::unchecked_disabled), csf_);
      assert::are_equal("unchecked_disabled", enum_object<>::to_string(toggle_button_state::unchecked_disabled), csf_);
      assert::are_equal(toggle_button_state::unchecked_disabled, enum_object<>::parse<toggle_button_state>("unchecked_disabled"), csf_);
    }
    
    void test_method_(checked_normal) {
      assert::are_equal(5, enum_object<>::to_int32(toggle_button_state::checked_normal), csf_);
      assert::are_equal("checked_normal", enum_object<>::to_string(toggle_button_state::checked_normal), csf_);
      assert::are_equal(toggle_button_state::checked_normal, enum_object<>::parse<toggle_button_state>("checked_normal"), csf_);
    }
    
    void test_method_(checked_hot) {
      assert::are_equal(6, enum_object<>::to_int32(toggle_button_state::checked_hot), csf_);
      assert::are_equal("checked_hot", enum_object<>::to_string(toggle_button_state::checked_hot), csf_);
      assert::are_equal(toggle_button_state::checked_hot, enum_object<>::parse<toggle_button_state>("checked_hot"), csf_);
    }
    
    void test_method_(checked_pressed) {
      assert::are_equal(7, enum_object<>::to_int32(toggle_button_state::checked_pressed), csf_);
      assert::are_equal("checked_pressed", enum_object<>::to_string(toggle_button_state::checked_pressed), csf_);
      assert::are_equal(toggle_button_state::checked_pressed, enum_object<>::parse<toggle_button_state>("checked_pressed"), csf_);
    }
    
    void test_method_(checked_disabled) {
      assert::are_equal(8, enum_object<>::to_int32(toggle_button_state::checked_disabled), csf_);
      assert::are_equal("checked_disabled", enum_object<>::to_string(toggle_button_state::checked_disabled), csf_);
      assert::are_equal(toggle_button_state::checked_disabled, enum_object<>::parse<toggle_button_state>("checked_disabled"), csf_);
    }
    
    void test_method_(mixed_normal) {
      assert::are_equal(9, enum_object<>::to_int32(toggle_button_state::mixed_normal), csf_);
      assert::are_equal("mixed_normal", enum_object<>::to_string(toggle_button_state::mixed_normal), csf_);
      assert::are_equal(toggle_button_state::mixed_normal, enum_object<>::parse<toggle_button_state>("mixed_normal"), csf_);
    }
    
    void test_method_(mixed_hot) {
      assert::are_equal(10, enum_object<>::to_int32(toggle_button_state::mixed_hot), csf_);
      assert::are_equal("mixed_hot", enum_object<>::to_string(toggle_button_state::mixed_hot), csf_);
      assert::are_equal(toggle_button_state::mixed_hot, enum_object<>::parse<toggle_button_state>("mixed_hot"), csf_);
    }
    
    void test_method_(mixed_pressed) {
      assert::are_equal(11, enum_object<>::to_int32(toggle_button_state::mixed_pressed), csf_);
      assert::are_equal("mixed_pressed", enum_object<>::to_string(toggle_button_state::mixed_pressed), csf_);
      assert::are_equal(toggle_button_state::mixed_pressed, enum_object<>::parse<toggle_button_state>("mixed_pressed"), csf_);
    }
    
    void test_method_(mixed_disabled) {
      assert::are_equal(12, enum_object<>::to_int32(toggle_button_state::mixed_disabled), csf_);
      assert::are_equal("mixed_disabled", enum_object<>::to_string(toggle_button_state::mixed_disabled), csf_);
      assert::are_equal(toggle_button_state::mixed_disabled, enum_object<>::parse<toggle_button_state>("mixed_disabled"), csf_);
    }
  };
}
