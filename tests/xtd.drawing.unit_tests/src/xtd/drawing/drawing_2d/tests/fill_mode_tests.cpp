#include <xtd/drawing/drawing_2d/fill_mode>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::drawing2d;
using namespace xtd::tunit;

namespace xtd::drawing::drawing_2d::tests {
  class test_class_(fill_mode_tests) {
    void test_method_(alternate) {
      assert::are_equal(0, enum_object<>::to_int32(fill_mode::alternate), csf_);
      assert::are_equal("alternate", enum_object<>::to_string(fill_mode::alternate), csf_);
      assert::are_equal(fill_mode::alternate, enum_object<>::parse<fill_mode>("alternate"), csf_);
    }
    
    void test_method_(winding) {
      assert::are_equal(1, enum_object<>::to_int32(fill_mode::winding), csf_);
      assert::are_equal("winding", enum_object<>::to_string(fill_mode::winding), csf_);
      assert::are_equal(fill_mode::winding, enum_object<>::parse<fill_mode>("winding"), csf_);
    }
  };
}
