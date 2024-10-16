#include <xtd/forms/button_state>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(button_state_tests) {
  public:
    void test_method_(normal) {
      assert::are_equal(0, enum_object<>::to_int32(button_state::normal));
      assert::are_equal("normal", enum_object<>::to_string(button_state::normal));
      assert::are_equal(button_state::normal, enum_object<>::parse<button_state>("normal"));
    }
    
    void test_method_(inactive) {
      assert::are_equal(256, enum_object<>::to_int32(button_state::inactive));
      assert::are_equal("inactive", enum_object<>::to_string(button_state::inactive));
      assert::are_equal(button_state::inactive, enum_object<>::parse<button_state>("inactive"));
    }
    
    void test_method_(pushed) {
      assert::are_equal(512, enum_object<>::to_int32(button_state::pushed));
      assert::are_equal("pushed", enum_object<>::to_string(button_state::pushed));
      assert::are_equal(button_state::pushed, enum_object<>::parse<button_state>("pushed"));
    }
    
    void test_method_(checked) {
      assert::are_equal(1024, enum_object<>::to_int32(button_state::checked));
      assert::are_equal("checked", enum_object<>::to_string(button_state::checked));
      assert::are_equal(button_state::checked, enum_object<>::parse<button_state>("checked"));
    }
    
    void test_method_(flat) {
      assert::are_equal(16384, enum_object<>::to_int32(button_state::flat));
      assert::are_equal("flat", enum_object<>::to_string(button_state::flat));
      assert::are_equal(button_state::flat, enum_object<>::parse<button_state>("flat"));
    }
    
    void test_method_(all) {
      assert::are_equal(18176, enum_object<>::to_int32(button_state::all));
      assert::are_equal("inactive, pushed, checked, flat", enum_object<>::to_string(button_state::all));
      assert::are_equal(button_state::all, enum_object<>::parse<button_state>("inactive, pushed, checked, flat"));
    }
  };
}
