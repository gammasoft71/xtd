#include <xtd/forms/day>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(day_tests) {
  public:
    auto test_method_(monday) {
      assert::are_equal(0, enum_object<>::to_int32(day::monday));
      assert::are_equal("monday", enum_object<>::to_string(day::monday));
      assert::are_equal(day::monday, enum_object<>::parse<day>("monday"));
    }
    
    auto test_method_(tuesday) {
      assert::are_equal(1, enum_object<>::to_int32(day::tuesday));
      assert::are_equal("tuesday", enum_object<>::to_string(day::tuesday));
      assert::are_equal(day::tuesday, enum_object<>::parse<day>("tuesday"));
    }
    
    auto test_method_(wednesday) {
      assert::are_equal(2, enum_object<>::to_int32(day::wednesday));
      assert::are_equal("wednesday", enum_object<>::to_string(day::wednesday));
      assert::are_equal(day::wednesday, enum_object<>::parse<day>("wednesday"));
    }
    
    auto test_method_(thursday) {
      assert::are_equal(3, enum_object<>::to_int32(day::thursday));
      assert::are_equal("thursday", enum_object<>::to_string(day::thursday));
      assert::are_equal(day::thursday, enum_object<>::parse<day>("thursday"));
    }
    
    auto test_method_(friday) {
      assert::are_equal(4, enum_object<>::to_int32(day::friday));
      assert::are_equal("friday", enum_object<>::to_string(day::friday));
      assert::are_equal(day::friday, enum_object<>::parse<day>("friday"));
    }
    
    auto test_method_(saturday) {
      assert::are_equal(5, enum_object<>::to_int32(day::saturday));
      assert::are_equal("saturday", enum_object<>::to_string(day::saturday));
      assert::are_equal(day::saturday, enum_object<>::parse<day>("saturday"));
    }
    
    auto test_method_(sunday) {
      assert::are_equal(6, enum_object<>::to_int32(day::sunday));
      assert::are_equal("sunday", enum_object<>::to_string(day::sunday));
      assert::are_equal(day::sunday, enum_object<>::parse<day>("sunday"));
    }
    
    auto test_method_(default_day) {
      assert::are_equal(7, enum_object<>::to_int32(day::default_day));
      assert::are_equal("default_day", enum_object<>::to_string(day::default_day));
      assert::are_equal(day::default_day, enum_object<>::parse<day>("default_day"));
    }
  };
}
