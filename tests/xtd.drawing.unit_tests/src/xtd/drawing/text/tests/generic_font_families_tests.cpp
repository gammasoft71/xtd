#include <xtd/drawing/text/generic_font_families>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::text;
using namespace xtd::tunit;

namespace xtd::drawing::text::tests {
  class test_class_(generic_font_families_tests) {
  public:
    void test_method_(serif) {
      assert::are_equal(0, enum_object<>::to_int32(generic_font_families::serif), csf_);
      assert::are_equal("serif", enum_object<>::to_string(generic_font_families::serif), csf_);
      assert::are_equal(generic_font_families::serif, enum_object<>::parse<generic_font_families>("serif"), csf_);
    }
    
    void test_method_(sans_serif) {
      assert::are_equal(1, enum_object<>::to_int32(generic_font_families::sans_serif), csf_);
      assert::are_equal("sans_serif", enum_object<>::to_string(generic_font_families::sans_serif), csf_);
      assert::are_equal(generic_font_families::sans_serif, enum_object<>::parse<generic_font_families>("sans_serif"), csf_);
    }
    
    void test_method_(monospace) {
      assert::are_equal(2, enum_object<>::to_int32(generic_font_families::monospace), csf_);
      assert::are_equal("monospace", enum_object<>::to_string(generic_font_families::monospace), csf_);
      assert::are_equal(generic_font_families::monospace, enum_object<>::parse<generic_font_families>("monospace"), csf_);
    }
  };
}
