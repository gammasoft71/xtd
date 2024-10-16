#include <xtd/string>
#include <xtd/format_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(string_boolean_format_tests) {
    void test_method_(format_false_with_default_argument) {
      assert::are_equal("false", xtd::string::format("{0}", false));
    }
    
    void test_method_(format_true_with_default_argument) {
      assert::are_equal("true", xtd::string::format("{0}", true));
    }
    
    void test_method_(format_false_with_left_alignment) {
      assert::are_equal("     false", string::format("{0,10}", false));
    }
    
    void test_method_(format_true_with_left_alignment) {
      assert::are_equal("      true", string::format("{0,10}", true));
    }
    
    void test_method_(format_false_with_right_alignment) {
      assert::are_equal("false     ", string::format("{0, -10}", false));
    }
    
    void test_method_(format_true_with_right_alignment) {
      assert::are_equal("true      ", string::format("{0, -10}", true));
    }
    
    void test_method_(format_false_with_zero_alignment) {
      assert::are_equal("false", string::format("{0,0}", false));
    }
    
    void test_method_(formatn_true_with_zer_alignment) {
      assert::are_equal("true", string::format("{0,0}", true));
    }
    
    void test_method_(format_false_with_binary_argument) {
      assert::are_equal("0", xtd::string::format("{0:b}", false));
    }
    
    void test_method_(format_true_with_binaryl_argument) {
      assert::are_equal("1", xtd::string::format("{0:B}", true));
    }
    
    void test_method_(format_false_with_decimal_argument) {
      assert::are_equal("0", xtd::string::format("{0:d}", false));
    }
    
    void test_method_(format_true_with_decimal_argument) {
      assert::are_equal("1", xtd::string::format("{0:D}", true));
    }
    
    void test_method_(format_false_with_general_argument) {
      assert::are_equal("false", xtd::string::format("{0:g}", false));
    }
    
    void test_method_(format_true_with_general_argument) {
      assert::are_equal("true", xtd::string::format("{0:G}", true));
    }
    
    void test_method_(format_false_with_octal_argument) {
      assert::are_equal("0", xtd::string::format("{0:o}", false));
    }
    
    void test_method_(format_true_with_octal_argument) {
      assert::are_equal("1", xtd::string::format("{0:O}", true));
    }
    
    void test_method_(format_false_with_hexadecimal_argument) {
      assert::are_equal("0", xtd::string::format("{0:x}", false));
    }
    
    void test_method_(format_true_with_hexadecimal_argument) {
      assert::are_equal("1", xtd::string::format("{0:X}", true));
    }
    
    void test_method_(format_false_with_invalid_argument) {
      assert::throws<xtd::format_exception>([] {xtd::string::format("{0:e}", true);});
    }
    
    void test_method_(format_true_with_invalid_argument) {
      assert::throws<xtd::format_exception>([] {xtd::string::format("{0:z1}", true);});
    }
  };
}
