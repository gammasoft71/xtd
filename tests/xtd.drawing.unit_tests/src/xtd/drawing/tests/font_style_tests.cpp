#include <xtd/drawing/font_style>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(font_style_tests) {
    auto test_method_(regular) {
      assert::are_equal(0, enum_object<>::to_int32(font_style::regular));
      assert::are_equal("regular", enum_object<>::to_string(font_style::regular));
      assert::are_equal(font_style::regular, enum_object<>::parse<font_style>("regular"));
    }
    
    auto test_method_(bold) {
      assert::are_equal(1, enum_object<>::to_int32(font_style::bold));
      assert::are_equal("bold", enum_object<>::to_string(font_style::bold));
      assert::are_equal(font_style::bold, enum_object<>::parse<font_style>("bold"));
    }
    
    auto test_method_(italic) {
      assert::are_equal(2, enum_object<>::to_int32(font_style::italic));
      assert::are_equal("italic", enum_object<>::to_string(font_style::italic));
      assert::are_equal(font_style::italic, enum_object<>::parse<font_style>("italic"));
    }
    
    auto test_method_(underline) {
      assert::are_equal(4, enum_object<>::to_int32(font_style::underline));
      assert::are_equal("underline", enum_object<>::to_string(font_style::underline));
      assert::are_equal(font_style::underline, enum_object<>::parse<font_style>("underline"));
    }
    
    auto test_method_(strikeout) {
      assert::are_equal(8, enum_object<>::to_int32(font_style::strikeout));
      assert::are_equal("strikeout", enum_object<>::to_string(font_style::strikeout));
      assert::are_equal(font_style::strikeout, enum_object<>::parse<font_style>("strikeout"));
    }
  };
}
