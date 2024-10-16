#include <xtd/forms/flat_style>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(flat_style_tests) {
  public:
    void test_method_(flat) {
      assert::are_equal(0, enum_object<>::to_int32(flat_style::flat));
      assert::are_equal("flat", enum_object<>::to_string(flat_style::flat));
      assert::are_equal(flat_style::flat, enum_object<>::parse<flat_style>("flat"));
    }
    
    void test_method_(popup) {
      assert::are_equal(1, enum_object<>::to_int32(flat_style::popup));
      assert::are_equal("popup", enum_object<>::to_string(flat_style::popup));
      assert::are_equal(flat_style::popup, enum_object<>::parse<flat_style>("popup"));
    }
    
    void test_method_(standard) {
      assert::are_equal(2, enum_object<>::to_int32(flat_style::standard));
      assert::are_equal("standard", enum_object<>::to_string(flat_style::standard));
      assert::are_equal(flat_style::standard, enum_object<>::parse<flat_style>("standard"));
    }
    
    void test_method_(system) {
      assert::are_equal(3, enum_object<>::to_int32(flat_style::system));
      assert::are_equal("system", enum_object<>::to_string(flat_style::system));
      assert::are_equal(flat_style::system, enum_object<>::parse<flat_style>("system"));
    }
  };
}
