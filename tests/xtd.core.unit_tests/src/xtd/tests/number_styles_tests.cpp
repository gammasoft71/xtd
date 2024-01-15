#include <xtd/number_styles>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(number_styles_tests) {
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(number_styles::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(number_styles::none), csf_);
      assert::are_equal(number_styles::none, enum_object<>::parse<number_styles>("none"), csf_);
    }
    
    void test_method_(allow_leading_white) {
      assert::are_equal(1, enum_object<>::to_int32(number_styles::allow_leading_white), csf_);
      assert::are_equal("allow_leading_white", enum_object<>::to_string(number_styles::allow_leading_white), csf_);
      assert::are_equal(number_styles::allow_leading_white, enum_object<>::parse<number_styles>("allow_leading_white"), csf_);
    }
    
    void test_method_(allow_trailing_white) {
      assert::are_equal(2, enum_object<>::to_int32(number_styles::allow_trailing_white), csf_);
      assert::are_equal("allow_trailing_white", enum_object<>::to_string(number_styles::allow_trailing_white), csf_);
      assert::are_equal(number_styles::allow_trailing_white, enum_object<>::parse<number_styles>("allow_trailing_white"), csf_);
    }
    
    void test_method_(allow_leading_sign) {
      assert::are_equal(4, enum_object<>::to_int32(number_styles::allow_leading_sign), csf_);
      assert::are_equal("allow_leading_sign", enum_object<>::to_string(number_styles::allow_leading_sign), csf_);
      assert::are_equal(number_styles::allow_leading_sign, enum_object<>::parse<number_styles>("allow_leading_sign"), csf_);
    }
    
    void test_method_(allow_trailing_sign) {
      assert::are_equal(8, enum_object<>::to_int32(number_styles::allow_trailing_sign), csf_);
      assert::are_equal("allow_trailing_sign", enum_object<>::to_string(number_styles::allow_trailing_sign), csf_);
      assert::are_equal(number_styles::allow_trailing_sign, enum_object<>::parse<number_styles>("allow_trailing_sign"), csf_);
    }
    
    void test_method_(allow_parentheses) {
      assert::are_equal(16, enum_object<>::to_int32(number_styles::allow_parentheses), csf_);
      assert::are_equal("allow_parentheses", enum_object<>::to_string(number_styles::allow_parentheses), csf_);
      assert::are_equal(number_styles::allow_parentheses, enum_object<>::parse<number_styles>("allow_parentheses"), csf_);
    }
    
    void test_method_(allow_decimal_point) {
      assert::are_equal(32, enum_object<>::to_int32(number_styles::allow_decimal_point), csf_);
      assert::are_equal("allow_decimal_point", enum_object<>::to_string(number_styles::allow_decimal_point), csf_);
      assert::are_equal(number_styles::allow_decimal_point, enum_object<>::parse<number_styles>("allow_decimal_point"), csf_);
    }
    
    void test_method_(allow_thousands) {
      assert::are_equal(64, enum_object<>::to_int32(number_styles::allow_thousands), csf_);
      assert::are_equal("allow_thousands", enum_object<>::to_string(number_styles::allow_thousands), csf_);
      assert::are_equal(number_styles::allow_thousands, enum_object<>::parse<number_styles>("allow_thousands"), csf_);
    }
    
    void test_method_(allow_exponent) {
      assert::are_equal(128, enum_object<>::to_int32(number_styles::allow_exponent), csf_);
      assert::are_equal("allow_exponent", enum_object<>::to_string(number_styles::allow_exponent), csf_);
      assert::are_equal(number_styles::allow_exponent, enum_object<>::parse<number_styles>("allow_exponent"), csf_);
    }
    
    void test_method_(allow_currency_symbol) {
      assert::are_equal(256, enum_object<>::to_int32(number_styles::allow_currency_symbol), csf_);
      assert::are_equal("allow_currency_symbol", enum_object<>::to_string(number_styles::allow_currency_symbol), csf_);
      assert::are_equal(number_styles::allow_currency_symbol, enum_object<>::parse<number_styles>("allow_currency_symbol"), csf_);
    }
    
    void test_method_(allow_hex_specifier) {
      assert::are_equal(512, enum_object<>::to_int32(number_styles::allow_hex_specifier), csf_);
      assert::are_equal("allow_hex_specifier", enum_object<>::to_string(number_styles::allow_hex_specifier), csf_);
      assert::are_equal(number_styles::allow_hex_specifier, enum_object<>::parse<number_styles>("allow_hex_specifier"), csf_);
    }
    
    void test_method_(allow_binary_specifier) {
      assert::are_equal(1024, enum_object<>::to_int32(number_styles::allow_binary_specifier), csf_);
      assert::are_equal("allow_binary_specifier", enum_object<>::to_string(number_styles::allow_binary_specifier), csf_);
      assert::are_equal(number_styles::allow_binary_specifier, enum_object<>::parse<number_styles>("allow_binary_specifier"), csf_);
    }
    
    void test_method_(allow_octal_specifier) {
      assert::are_equal(2048, enum_object<>::to_int32(number_styles::allow_octal_specifier), csf_);
      assert::are_equal("allow_octal_specifier", enum_object<>::to_string(number_styles::allow_octal_specifier), csf_);
      assert::are_equal(number_styles::allow_octal_specifier, enum_object<>::parse<number_styles>("allow_octal_specifier"), csf_);
    }
    
    void test_method_(integer) {
      assert::are_equal(7, enum_object<>::to_int32(number_styles::integer), csf_);
      assert::are_equal("integer", enum_object<>::to_string(number_styles::integer), csf_);
      assert::are_equal(number_styles::integer, enum_object<>::parse<number_styles>("integer"), csf_);
    }
    
    void test_method_(number) {
      assert::are_equal(111, enum_object<>::to_int32(number_styles::number), csf_);
      assert::are_equal("number", enum_object<>::to_string(number_styles::number), csf_);
      assert::are_equal(number_styles::number, enum_object<>::parse<number_styles>("number"), csf_);
    }
    
    void test_method_(fixed_point) {
      assert::are_equal(167, enum_object<>::to_int32(number_styles::fixed_point), csf_);
      assert::are_equal("fixed_point", enum_object<>::to_string(number_styles::fixed_point), csf_);
      assert::are_equal(number_styles::fixed_point, enum_object<>::parse<number_styles>("fixed_point"), csf_);
    }
    
    void test_method_(currency) {
      assert::are_equal(383, enum_object<>::to_int32(number_styles::currency), csf_);
      assert::are_equal("currency", enum_object<>::to_string(number_styles::currency), csf_);
      assert::are_equal(number_styles::currency, enum_object<>::parse<number_styles>("currency"), csf_);
    }
    
    void test_method_(any) {
      assert::are_equal(511, enum_object<>::to_int32(number_styles::any), csf_);
      assert::are_equal("any", enum_object<>::to_string(number_styles::any), csf_);
      assert::are_equal(number_styles::any, enum_object<>::parse<number_styles>("any"), csf_);
    }
    
    void test_method_(hex_number) {
      assert::are_equal(515, enum_object<>::to_int32(number_styles::hex_number), csf_);
      assert::are_equal("hex_number", enum_object<>::to_string(number_styles::hex_number), csf_);
      assert::are_equal(number_styles::hex_number, enum_object<>::parse<number_styles>("hex_number"), csf_);
    }
    
    void test_method_(binary_number) {
      assert::are_equal(1027, enum_object<>::to_int32(number_styles::binary_number), csf_);
      assert::are_equal("binary_number", enum_object<>::to_string(number_styles::binary_number), csf_);
      assert::are_equal(number_styles::binary_number, enum_object<>::parse<number_styles>("binary_number"), csf_);
    }
    
    void test_method_(octal_number) {
      assert::are_equal(2051, enum_object<>::to_int32(number_styles::octal_number), csf_);
      assert::are_equal("octal_number", enum_object<>::to_string(number_styles::octal_number), csf_);
      assert::are_equal(number_styles::octal_number, enum_object<>::parse<number_styles>("octal_number"), csf_);
    }
  };
}
