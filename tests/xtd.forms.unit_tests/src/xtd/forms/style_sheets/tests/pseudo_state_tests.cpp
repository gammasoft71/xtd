#include <xtd/forms/style_sheets/pseudo_state>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace xtd::forms::style_sheets::tests {
  class test_class_(pseudo_state_tests) {
  public:
    void test_method_(standard) {
      assert::are_equal(0, enum_object<>::to_int32(pseudo_state::standard));
      assert::are_equal("standard", enum_object<>::to_string(pseudo_state::standard));
      assert::are_equal(pseudo_state::standard, enum_object<>::parse<pseudo_state>("standard"));
    }
    
    void test_method_(hover) {
      assert::are_equal(1, enum_object<>::to_int32(pseudo_state::hover));
      assert::are_equal("hover", enum_object<>::to_string(pseudo_state::hover));
      assert::are_equal(pseudo_state::hover, enum_object<>::parse<pseudo_state>("hover"));
    }
    
    void test_method_(pressed) {
      assert::are_equal(2, enum_object<>::to_int32(pseudo_state::pressed));
      assert::are_equal("pressed", enum_object<>::to_string(pseudo_state::pressed));
      assert::are_equal(pseudo_state::pressed, enum_object<>::parse<pseudo_state>("pressed"));
    }
    
    void test_method_(disabled) {
      assert::are_equal(4, enum_object<>::to_int32(pseudo_state::disabled));
      assert::are_equal("disabled", enum_object<>::to_string(pseudo_state::disabled));
      assert::are_equal(pseudo_state::disabled, enum_object<>::parse<pseudo_state>("disabled"));
    }
    
    void test_method_(focused) {
      assert::are_equal(8, enum_object<>::to_int32(pseudo_state::focused));
      assert::are_equal("focused", enum_object<>::to_string(pseudo_state::focused));
      assert::are_equal(pseudo_state::focused, enum_object<>::parse<pseudo_state>("focused"));
    }
    
    void test_method_(default_state) {
      assert::are_equal(16, enum_object<>::to_int32(pseudo_state::default_state));
      assert::are_equal("default_state", enum_object<>::to_string(pseudo_state::default_state));
      assert::are_equal(pseudo_state::default_state, enum_object<>::parse<pseudo_state>("default_state"));
    }
    
    void test_method_(unchecked) {
      assert::are_equal(0, enum_object<>::to_int32(pseudo_state::unchecked));
      assert::are_equal("standard", enum_object<>::to_string(pseudo_state::unchecked));
      assert::are_equal(pseudo_state::unchecked, enum_object<>::parse<pseudo_state>("standard"));
    }
    
    void test_method_(checked) {
      assert::are_equal(32, enum_object<>::to_int32(pseudo_state::checked));
      assert::are_equal("checked", enum_object<>::to_string(pseudo_state::checked));
      assert::are_equal(pseudo_state::checked, enum_object<>::parse<pseudo_state>("checked"));
    }
    
    void test_method_(mixed) {
      assert::are_equal(64, enum_object<>::to_int32(pseudo_state::mixed));
      assert::are_equal("mixed", enum_object<>::to_string(pseudo_state::mixed));
      assert::are_equal(pseudo_state::mixed, enum_object<>::parse<pseudo_state>("mixed"));
    }
  };
}
