#include <xtd/globalization/culture_types>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::globalization;
using namespace xtd::tunit;

namespace xtd::globalization::tests {
  class test_class_(culture_types_tests) {
    auto test_method_(neutral_cultures) {
      assert::are_equal(1, enum_object<>::to_int32(culture_types::neutral_cultures));
      assert::are_equal("neutral_cultures", enum_object<>::to_string(culture_types::neutral_cultures));
      assert::are_equal(culture_types::neutral_cultures, enum_object<>::parse<culture_types>("neutral_cultures"));
    }
    
    auto test_method_(specific_cultures) {
      assert::are_equal(2, enum_object<>::to_int32(culture_types::specific_cultures));
      assert::are_equal("specific_cultures", enum_object<>::to_string(culture_types::specific_cultures));
      assert::are_equal(culture_types::specific_cultures, enum_object<>::parse<culture_types>("specific_cultures"));
    }
    
    auto test_method_(installed_win32_cultures) {
      assert::are_equal(4, enum_object<>::to_int32(culture_types::installed_win32_cultures));
      assert::are_equal("installed_win32_cultures", enum_object<>::to_string(culture_types::installed_win32_cultures));
      assert::are_equal(culture_types::installed_win32_cultures, enum_object<>::parse<culture_types>("installed_win32_cultures"));
    }
    
    auto test_method_(all_cultures) {
      assert::are_equal(7, enum_object<>::to_int32(culture_types::all_cultures));
      assert::are_equal("all_cultures", enum_object<>::to_string(culture_types::all_cultures));
      assert::are_equal(culture_types::all_cultures, enum_object<>::parse<culture_types>("all_cultures"));
    }
  };
}
