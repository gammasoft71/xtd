#include <xtd/forms/style_sheets/text_decoration>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace xtd::forms::style_sheets::tests {
  class test_class_(text_decoration_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(text_decoration::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(text_decoration::none), csf_);
      assert::are_equal(text_decoration::none, enum_object<>::parse<text_decoration>("none"), csf_);
    }
    
    void test_method_(overline) {
      assert::are_equal(1, enum_object<>::to_int32(text_decoration::overline), csf_);
      assert::are_equal("overline", enum_object<>::to_string(text_decoration::overline), csf_);
      assert::are_equal(text_decoration::overline, enum_object<>::parse<text_decoration>("overline"), csf_);
    }
    
    void test_method_(line_through) {
      assert::are_equal(2, enum_object<>::to_int32(text_decoration::line_through), csf_);
      assert::are_equal("line_through", enum_object<>::to_string(text_decoration::line_through), csf_);
      assert::are_equal(text_decoration::line_through, enum_object<>::parse<text_decoration>("line_through"), csf_);
    }
    
    void test_method_(underline) {
      assert::are_equal(3, enum_object<>::to_int32(text_decoration::underline), csf_);
      assert::are_equal("underline", enum_object<>::to_string(text_decoration::underline), csf_);
      assert::are_equal(text_decoration::underline, enum_object<>::parse<text_decoration>("underline"), csf_);
    }
  };
}

