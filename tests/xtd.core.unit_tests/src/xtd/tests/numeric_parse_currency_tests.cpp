#include <xtd/string>
#include <xtd/format_exception>
#include <xtd/globalization/culture_info>
#include <xtd/tunit/assert>
#include <xtd/tunit/register_test_class_types>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  template<class value_t>
  class numeric_parse_string_currency_tests;
  
  auto register_numeric_parse_string_currency_tests = register_test_class_types<numeric_parse_string_currency_tests, char, unsigned char, short, unsigned short, int, unsigned int, long, unsigned long, long long, unsigned long long, sbyte, int16, int32, int64, intptr, ptrdiff, size, byte, uint16, uint32, uint64, uintptr> {};
  
  template<class value_t>
  class numeric_parse_string_currency_tests : public test_class {
    inline static xtd::globalization::culture_info previous_culture;
    
    static void class_initialize_(class_initialize) {
      previous_culture = xtd::globalization::culture_info::current_culture();
      xtd::globalization::culture_info::current_culture(xtd::globalization::culture_info {"en-US"});
    }
    
    static void class_cleanup_(class_cleanup) {
      xtd::globalization::culture_info::current_culture(previous_culture);
    }
    
    auto test_method_(parse_styles_currency) {
      assert::are_equal(static_cast<value_t>(42), xtd::parse<value_t>("42", number_styles::currency));
    }
    
    auto test_method_(parse_styles_currency_with_leading_white_spaces) {
      assert::are_equal(static_cast<value_t>(42), xtd::parse<value_t>(" \f\n\r\t\v42", number_styles::currency));
    }
    
    auto test_method_(parse_styles_currency_with_trailing_white_spaces) {
      assert::are_equal(static_cast<value_t>(42), xtd::parse<value_t>("42 \f\n\r\t\v", number_styles::currency));
    }
    
    auto test_method_(parse_styles_currency_with_leading_plus_sign) {
      assert::are_equal(static_cast<value_t>(42), xtd::parse<value_t>("+42", number_styles::currency));
    }
    
    auto test_method_(parse_styles_currency_with_two_leading_plus_sign) {
      assert::throws<format_exception>([] {xtd::parse<value_t>("++42", number_styles::currency);});
    }
    
    auto test_method_(parse_styles_currency_with_leading_minus_sign) {
      if (std::is_signed<value_t>::value)
        assert::are_equal(static_cast<value_t>(-42), xtd::parse<value_t>("-42", number_styles::currency));
      #if !defined (__linux__)
      else
        assert::throws<format_exception>([] {xtd::parse<value_t>("-42", number_styles::currency);});
      #endif
    }
    
    auto test_method_(parse_styles_currency_with_two_leading_minus_sign) {
      assert::throws<format_exception>([] {xtd::parse<value_t>("--42", number_styles::currency);});
    }
    
    auto test_method_(parse_styles_currency_with_trailing_plus_sign) {
      assert::are_equal(static_cast<value_t>(42), xtd::parse<value_t>("42+", number_styles::currency));
    }
    
    auto test_method_(parse_styles_currency_with_two_trailing_plus_sign) {
      assert::throws<format_exception>([] {xtd::parse<value_t>("42++", number_styles::currency);});
    }
    
    auto test_method_(parse_styles_currency_with_trailing_minus_sign) {
      if (std::is_signed<value_t>::value)
        assert::are_equal(static_cast<value_t>(-42), xtd::parse<value_t>("42-", number_styles::currency));
      #if !defined (__linux__)
      else
        assert::throws<format_exception>([] {xtd::parse<value_t>("42-", number_styles::currency);});
      #endif
    }
    
    auto test_method_(parse_styles_currency_with_two_trailing_minus_sign) {
      assert::throws<format_exception>([] {xtd::parse<value_t>("42--", number_styles::currency);});
    }
    
    auto test_method_(parse_styles_currency_with_parentheses) {
      if (std::is_signed<value_t>::value)
        assert::are_equal(static_cast<value_t>(-42), xtd::parse<value_t>("(42)", number_styles::currency));
      #if !defined (__linux__)
      else
        assert::throws<format_exception>([] {xtd::parse<value_t>("(42)", number_styles::currency);});
      #endif
    }
    
    auto test_method_(parse_styles_currency_with_two_parentheses) {
      assert::throws<format_exception>([] {xtd::parse<value_t>("((42))", number_styles::currency);});
    }
    
    auto test_method_(parse_styles_currency_with_decimal_point) {
      assert::are_equal(static_cast<value_t>(42), xtd::parse<value_t>("42.0", number_styles::currency));
    }
    
    auto test_method_(parse_styles_currency_with_two_decimal_point) {
      assert::throws<format_exception>([] {xtd::parse<value_t>("4.2.0", number_styles::currency);});
    }
    
    auto test_method_(parse_styles_currency_with_thousands) {
      if (!std::is_same<value_t, sbyte>::value && !std::is_same<value_t, char>::value && !std::is_same<value_t, unsigned char>::value)
        assert::are_equal(static_cast<value_t>(1234), xtd::parse<value_t>("1,234", number_styles::currency));
    }
    
    auto test_method_(parse_styles_currency_with_two_thousands) {
      if (!std::is_same<value_t, sbyte>::value && !std::is_same<value_t, char>::value && !std::is_same<value_t, unsigned char>::value)
        assert::throws<format_exception>([] {xtd::parse<value_t>("1,,234", number_styles::currency);});
    }
    
    auto test_method_(parse_styles_currency_with_exponent) {
      assert::throws<format_exception>([] {xtd::parse<value_t>("4E+01", number_styles::currency);});
    }
    
    auto test_method_(parse_styles_currency_with_leading_currency_symbol) {
      assert::are_equal(static_cast<value_t>(42), xtd::parse<value_t>("$42", number_styles::currency));
    }
    
    auto test_method_(parse_styles_currency_with_trailing_currency_symbol) {
      assert::are_equal(static_cast<value_t>(42), xtd::parse<value_t>("42$", number_styles::currency));
    }
    
    auto test_method_(parse_styles_currency_with_binary_specifier) {
      assert::throws<format_exception>([] {xtd::parse<value_t>("0b101010", number_styles::currency);});
    }
    
    auto test_method_(parse_styles_currency_with_octal_specifier) {
      assert::are_equal(static_cast<value_t>(52), xtd::parse<value_t>("052", number_styles::currency));
    }
    
    auto test_method_(parse_styles_currency_with_hexa_specifier) {
      assert::throws<format_exception>([] {xtd::parse<value_t>("0x2A", number_styles::currency);});
    }
    
    auto test_method_(parse_styles_currency_invalid) {
      assert::throws<format_exception>([] {xtd::parse<value_t>("z42", number_styles::currency);});
    }
  };
}
