#include <xtd/format>
#include <xtd/format_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(format_u16string_boolean_tests) {
    auto test_method_(format_false_with_default_argument) {
      assert::are_equal(u"false", format(u"{0}", false));
    }
    
    auto test_method_(format_true_with_default_argument) {
      assert::are_equal(u"true", format(u"{0}", true));
    }
    
    auto test_method_(format_false_with_left_alignment) {
      assert::are_equal(u"     false", string::format(u"{0,10}", false));
    }
    
    auto test_method_(format_true_with_left_alignment) {
      assert::are_equal(u"      true", string::format(u"{0,10}", true));
    }
    
    auto test_method_(format_false_with_right_alignment) {
      assert::are_equal(u"false     ", string::format(u"{0, -10}", false));
    }
    
    auto test_method_(format_true_with_right_alignment) {
      assert::are_equal(u"true      ", string::format(u"{0, -10}", true));
    }
    
    auto test_method_(format_false_with_zero_alignment) {
      assert::are_equal(u"false", string::format(u"{0,0}", false));
    }
    
    auto test_method_(formatn_true_with_zer_alignment) {
      assert::are_equal(u"true", string::format(u"{0,0}", true));
    }
    
    auto test_method_(format_false_with_binary_argument) {
      assert::are_equal(u"0", format(u"{0:b}", false));
    }
    
    auto test_method_(format_true_with_binaryl_argument) {
      assert::are_equal(u"1", format(u"{0:B}", true));
    }
    
    auto test_method_(format_false_with_decimal_argument) {
      assert::are_equal(u"0", format(u"{0:d}", false));
    }
    
    auto test_method_(format_true_with_decimal_argument) {
      assert::are_equal(u"1", format(u"{0:D}", true));
    }
    
    auto test_method_(format_false_with_general_argument) {
      assert::are_equal(u"false", format(u"{0:g}", false));
    }
    
    auto test_method_(format_true_with_general_argument) {
      assert::are_equal(u"true", format(u"{0:G}", true));
    }
    
    auto test_method_(format_false_with_octal_argument) {
      assert::are_equal(u"0", format(u"{0:o}", false));
    }
    
    auto test_method_(format_true_with_octal_argument) {
      assert::are_equal(u"1", format(u"{0:O}", true));
    }
    
    auto test_method_(format_false_with_hexadecimal_argument) {
      assert::are_equal(u"0", format(u"{0:x}", false));
    }
    
    auto test_method_(format_true_with_hexadecimal_argument) {
      assert::are_equal(u"1", format(u"{0:X}", true));
    }
    
    auto test_method_(format_false_with_invalid_argument) {
      assert::throws<xtd::format_exception>([] {format(u"{0:e}", true);});
    }
    
    auto test_method_(format_true_with_invalid_argument) {
      assert::throws<xtd::format_exception>([] {format(u"{0:z1}", true);});
    }
  };
}
