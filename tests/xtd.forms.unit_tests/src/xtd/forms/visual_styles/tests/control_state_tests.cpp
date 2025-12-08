#include <xtd/forms/visual_styles/control_state>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms::visual_styles;
using namespace xtd::tunit;

namespace xtd::forms::visual_styles::tests {
  class test_class_(control_state_tests) {
  public:
    auto test_method_(normal) {
      assert::are_equal(1, enum_object<>::to_int32(control_state::normal));
      assert::are_equal("normal", enum_object<>::to_string(control_state::normal));
      assert::are_equal(control_state::normal, enum_object<>::parse<control_state>("normal"));
    }
    
    auto test_method_(hot) {
      assert::are_equal(2, enum_object<>::to_int32(control_state::hot));
      assert::are_equal("hot", enum_object<>::to_string(control_state::hot));
      assert::are_equal(control_state::hot, enum_object<>::parse<control_state>("hot"));
    }
    
    auto test_method_(pressed) {
      assert::are_equal(3, enum_object<>::to_int32(control_state::pressed));
      assert::are_equal("pressed", enum_object<>::to_string(control_state::pressed));
      assert::are_equal(control_state::pressed, enum_object<>::parse<control_state>("pressed"));
    }
    
    auto test_method_(disabled) {
      assert::are_equal(4, enum_object<>::to_int32(control_state::disabled));
      assert::are_equal("disabled", enum_object<>::to_string(control_state::disabled));
      assert::are_equal(control_state::disabled, enum_object<>::parse<control_state>("disabled"));
    }
  };
}
