#include <xtd/forms/visual_styles/push_button_state.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms::visual_styles;
using namespace xtd::tunit;

namespace xtd::forms::visual_styles::tests {
  class test_class_(push_button_state_tests) {
  public:
    void test_method_(normal) {
      assert::are_equal(1, enum_object<>::to_int32(push_button_state::normal), csf_);
      assert::are_equal("normal", enum_object<>::to_string(push_button_state::normal), csf_);
      assert::are_equal(push_button_state::normal, enum_object<>::parse<push_button_state>("normal"), csf_);
    }
    
    void test_method_(hot) {
      assert::are_equal(2, enum_object<>::to_int32(push_button_state::hot), csf_);
      assert::are_equal("hot", enum_object<>::to_string(push_button_state::hot), csf_);
      assert::are_equal(push_button_state::hot, enum_object<>::parse<push_button_state>("hot"), csf_);
    }
    
    void test_method_(pressed) {
      assert::are_equal(3, enum_object<>::to_int32(push_button_state::pressed), csf_);
      assert::are_equal("pressed", enum_object<>::to_string(push_button_state::pressed), csf_);
      assert::are_equal(push_button_state::pressed, enum_object<>::parse<push_button_state>("pressed"), csf_);
    }
    
    void test_method_(checked) {
      assert::are_equal(4, enum_object<>::to_int32(push_button_state::checked), csf_);
      assert::are_equal("checked", enum_object<>::to_string(push_button_state::checked), csf_);
      assert::are_equal(push_button_state::checked, enum_object<>::parse<push_button_state>("checked"), csf_);
    }

    void test_method_(disabled) {
      assert::are_equal(5, enum_object<>::to_int32(push_button_state::disabled), csf_);
      assert::are_equal("disabled", enum_object<>::to_string(push_button_state::disabled), csf_);
      assert::are_equal(push_button_state::disabled, enum_object<>::parse<push_button_state>("disabled"), csf_);
    }
    
    void test_method_(default_state) {
      assert::are_equal(6, enum_object<>::to_int32(push_button_state::default_state), csf_);
      assert::are_equal("default_state", enum_object<>::to_string(push_button_state::default_state), csf_);
      assert::are_equal(push_button_state::default_state, enum_object<>::parse<push_button_state>("default_state"), csf_);
    }
  };
}

