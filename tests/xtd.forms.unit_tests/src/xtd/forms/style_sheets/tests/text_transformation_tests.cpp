#include <xtd/forms/style_sheets/text_transformation>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace xtd::forms::style_sheets::tests {
  class test_class_(text_transformation_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(text_transformation::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(text_transformation::none), csf_);
      assert::are_equal(text_transformation::none, enum_object<>::parse<text_transformation>("none"), csf_);
    }
    
    void test_method_(lowercase) {
      assert::are_equal(1, enum_object<>::to_int32(text_transformation::lowercase), csf_);
      assert::are_equal("lowercase", enum_object<>::to_string(text_transformation::lowercase), csf_);
      assert::are_equal(text_transformation::lowercase, enum_object<>::parse<text_transformation>("lowercase"), csf_);
    }
    
    void test_method_(uppercase) {
      assert::are_equal(2, enum_object<>::to_int32(text_transformation::uppercase), csf_);
      assert::are_equal("uppercase", enum_object<>::to_string(text_transformation::uppercase), csf_);
      assert::are_equal(text_transformation::uppercase, enum_object<>::parse<text_transformation>("uppercase"), csf_);
    }
    
    void test_method_(capitalize) {
      assert::are_equal(3, enum_object<>::to_int32(text_transformation::capitalize), csf_);
      assert::are_equal("capitalize", enum_object<>::to_string(text_transformation::capitalize), csf_);
      assert::are_equal(text_transformation::capitalize, enum_object<>::parse<text_transformation>("capitalize"), csf_);
    }
  };
}
