#include <xtd/ustring>
#include <xtd/ustring>
#include <xtd/format_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  template <typename Value>
  class numeric_parse_string_default_tests;
  
  test_class_attribute<numeric_parse_string_default_tests<char>> numeric_parse_string_default_tests_class_char_attr {"numeric_parse_string_default_tests<char>"};
  test_class_attribute<numeric_parse_string_default_tests<unsigned char>> numeric_parse_string_default_tests_class_unsigned_char_attr {"numeric_parse_string_default_tests<unsigned_char>"};
  test_class_attribute<numeric_parse_string_default_tests<short>> numeric_parse_string_default_tests_class_short_attr {"numeric_parse_string_default_tests<short>"};
  test_class_attribute<numeric_parse_string_default_tests<unsigned short>> numeric_parse_string_default_tests_class_unsigned_short_attr {"numeric_parse_string_default_tests<unsigned_short>"};
  test_class_attribute<numeric_parse_string_default_tests<int>> numeric_parse_string_default_tests_class_int_attr {"numeric_parse_string_default_tests<int>"};
  test_class_attribute<numeric_parse_string_default_tests<unsigned int>> numeric_parse_string_default_tests_class_unsigned_int_attr {"numeric_parse_string_default_tests<unsigned_int>"};
  test_class_attribute<numeric_parse_string_default_tests<long>> numeric_parse_string_default_tests_class_long_attr {"numeric_parse_string_default_tests<long>"};
  test_class_attribute<numeric_parse_string_default_tests<unsigned long>> numeric_parse_string_default_tests_class_unsigned_long_attr {"numeric_parse_string_default_tests<unsigned_long>"};
  test_class_attribute<numeric_parse_string_default_tests<long long>> numeric_parse_string_default_tests_class_long_long_attr {"numeric_parse_string_default_tests<long_long>"};
  test_class_attribute<numeric_parse_string_default_tests<unsigned long long>> numeric_parse_string_default_tests_class_unsigned_long_long_attr {"numeric_parse_string_default_tests<unsigned_long_long>"};
  test_class_attribute<numeric_parse_string_default_tests<sbyte>> numeric_parse_string_default_tests_class_sbyte_attr {"numeric_parse_string_default_tests<sbyte>"};
  test_class_attribute<numeric_parse_string_default_tests<int16>> numeric_parse_string_default_tests_class_int16_attr {"numeric_parse_string_default_tests<int16>"};
  test_class_attribute<numeric_parse_string_default_tests<int32>> numeric_parse_string_default_tests_class_int32_attr {"numeric_parse_string_default_tests<int32>"};
  test_class_attribute<numeric_parse_string_default_tests<int64>> numeric_parse_string_default_tests_class_int64_attr {"numeric_parse_string_default_tests<int64>"};
  test_class_attribute<numeric_parse_string_default_tests<intptr>> numeric_parse_string_default_tests_class_intptr_attr {"numeric_parse_string_default_tests<intptr>"};
  test_class_attribute<numeric_parse_string_default_tests<ptrdiff_t>> numeric_parse_string_default_tests_class_ptrdiff_t_attr {"numeric_parse_string_default_tests<ptrdiff_t>"};
  test_class_attribute<numeric_parse_string_default_tests<size_t>> numeric_parse_string_default_tests_class_size_t_attr {"numeric_parse_string_default_tests<size_t>"};
  test_class_attribute<numeric_parse_string_default_tests<xtd::byte>> numeric_parse_string_default_tests_class_byte_t_attr {"numeric_parse_string_default_tests<xtd::byte>"};
  test_class_attribute<numeric_parse_string_default_tests<uint16>> numeric_parse_string_default_tests_class_uint16_attr {"numeric_parse_string_default_tests<uint16>"};
  test_class_attribute<numeric_parse_string_default_tests<uint32>> numeric_parse_string_default_tests_class_uint32_attr {"numeric_parse_string_default_tests<uint32>"};
  test_class_attribute<numeric_parse_string_default_tests<uint64>> numeric_parse_string_default_tests_class_uint64_attr {"numeric_parse_string_default_tests<uint64>"};
  test_class_attribute<numeric_parse_string_default_tests<uintptr>> numeric_parse_string_default_tests_class_uintptr_attr {"numeric_parse_string_default_tests<uintptr>"};
  
  template <typename Value>
  class numeric_parse_string_default_tests : public test_class {
    inline static std::locale previous_locale;
    static void class_initialize_(class_initialize) {
      previous_locale = std::locale::global(std::locale("en_US.UTF-8"));
    }
    
    static void test_cleanup_(test_cleanup) {
      std::locale::global(previous_locale);
    }
    
    void test_method_(parse_default) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42"), csf_);
    }
    
    void test_method_(parse_default_with_leading_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>(" \f\n\r\t\v42"), csf_);
    }
    
    void test_method_(parse_default_with_trailing_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42 \f\n\r\t\v"), csf_);
    }
    
    void test_method_(parse_default_with_leading_plus_sign) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("+42"), csf_);
    }
    
    void test_method_(parse_default_with_two_leading_plus_sign) {
      assert::throws<format_exception>([] {xtd::parse<Value>("++42");}, csf_);
    }
    
    void test_method_(parse_default_with_leading_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("-42"), csf_);
#if !defined (__linux__)
      else
        assert::throws<format_exception>([] {xtd::parse<Value>("-42");}, csf_);
#endif
    }
    
    void test_method_(parse_default_with_two_leading_minus_sign) {
      assert::throws<format_exception>([] {xtd::parse<Value>("--42");}, csf_);
    }
    
    void test_method_(parse_default_with_trailing_plus_sign) {
      assert::throws<format_exception>([] {xtd::parse<Value>("42+");}, csf_);
    }
    
    void test_method_(parse_default_with_two_trailing_plus_sign) {
      assert::throws<format_exception>([] {xtd::parse<Value>("42++");}, csf_);
    }
    
    void test_method_(parse_default_with_trailing_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::throws<format_exception>([] {xtd::parse<Value>("42-");}, csf_);
#if !defined (__linux__)
      else
        assert::throws<format_exception>([] {xtd::parse<Value>("42-", number_styles::number);}, csf_);
#endif
    }
    
    void test_method_(parse_default_with_two_trailing_minus_sign) {
      assert::throws<format_exception>([] {xtd::parse<Value>("42--");}, csf_);
    }
    
    void test_method_(parse_default_with_parentheses) {
      if (std::is_signed<Value>::value)
        assert::throws<format_exception>([] {xtd::parse<Value>("(42)");}, csf_);
      else
        assert::throws<format_exception>([] {xtd::parse<Value>("(42)");}, csf_);
    }
    
    void test_method_(parse_default_with_two_parentheses) {
      assert::throws<format_exception>([] {xtd::parse<Value>("((42))");}, csf_);
    }
    
    void test_method_(parse_default_with_decimal_point) {
      assert::throws<format_exception>([] {xtd::parse<Value>("42.0");}, csf_);
    }
    
    void test_method_(parse_default_with_two_decimal_point) {
      assert::throws<format_exception>([] {xtd::parse<Value>("4.2.0");}, csf_);
    }
    
    void test_method_(parse_default_with_thousands) {
      if (!std::is_same<Value, sbyte>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::throws<format_exception>([] {xtd::parse<Value>("1,234");}, csf_);
    }
    
    void test_method_(parse_default_with_two_thousands) {
      if (!std::is_same<Value, sbyte>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::throws<format_exception>([] {xtd::parse<Value>("1,,234");}, csf_);
    }
    
    void test_method_(parse_default_with_exponent) {
      assert::throws<format_exception>([] {xtd::parse<Value>("4E+01");}, csf_);
    }
    
    void test_method_(parse_default_with_leading_currency_symbol) {
      assert::throws<format_exception>([] {xtd::parse<Value>("$42");}, csf_);
    }
    
    void test_method_(parse_default_with_trailing_currency_symbol) {
      assert::throws<format_exception>([] {xtd::parse<Value>("42$");}, csf_);
    }
    
    void test_method_(parse_default_with_binary_specifier) {
      assert::throws<format_exception>([] {xtd::parse<Value>("0b101010");}, csf_);
    }
    
    void test_method_(parse_default_with_octal_specifier) {
      assert::are_equal(static_cast<Value>(52), xtd::parse<Value>("052"), csf_);
    }
    
    void test_method_(parse_default_with_hexa_specifier) {
      assert::throws<format_exception>([] {xtd::parse<Value>("0x2A");}, csf_);
    }
    
    void test_method_(parse_default_invalid) {
      assert::throws<format_exception>([] {xtd::parse<Value>("z42");}, csf_);
    }
  };
}
