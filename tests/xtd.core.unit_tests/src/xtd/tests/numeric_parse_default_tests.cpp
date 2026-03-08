#include <xtd/string>
#include <xtd/string>
#include <xtd/format_exception>
#include <xtd/globalization/culture_info>
#include <xtd/tunit/assert>
#include <xtd/tunit/generic_test_class>
#include <xtd/tunit/test_method_attribute>

namespace xtd::tests {
  generic_test_class_(numeric_parse_string_default_tests, signed char, unsigned char, short, unsigned short, int, unsigned int, long, unsigned long, long long, unsigned long long, sbyte, int16, int32, int64, intptr, ptrdiff, size, byte, uint16, uint32, uint64, uintptr) {
    inline static xtd::globalization::culture_info previous_culture;
    
    static void class_initialize_(class_initialize) {
      previous_culture = xtd::globalization::culture_info::current_culture();
      xtd::globalization::culture_info::current_culture(xtd::globalization::culture_info {"en-US"});
    }
    
    static void class_cleanup_(class_cleanup) {
      xtd::globalization::culture_info::current_culture(previous_culture);
    }
    
    auto test_method_(parse_default) {
      assert::are_equal(static_cast<type_t>(42), xtd::parse<type_t>("42"));
    }
    
    auto test_method_(parse_default_with_leading_white_spaces) {
      assert::are_equal(static_cast<type_t>(42), xtd::parse<type_t>(" \f\n\r\t\v42"));
    }
    
    auto test_method_(parse_default_with_trailing_white_spaces) {
      assert::are_equal(static_cast<type_t>(42), xtd::parse<type_t>("42 \f\n\r\t\v"));
    }
    
    auto test_method_(parse_default_with_leading_plus_sign) {
      assert::are_equal(static_cast<type_t>(42), xtd::parse<type_t>("+42"));
    }
    
    auto test_method_(parse_default_with_two_leading_plus_sign) {
      assert::throws<format_exception>([] {xtd::parse<type_t>("++42");});
    }
    
    auto test_method_(parse_default_with_leading_minus_sign) {
      if (std::is_signed<type_t>::value)
        assert::are_equal(static_cast<type_t>(-42), xtd::parse<type_t>("-42"));
      #if !defined (__linux__)
      else
        assert::throws<format_exception>([] {xtd::parse<type_t>("-42");});
      #endif
    }
    
    auto test_method_(parse_default_with_two_leading_minus_sign) {
      assert::throws<format_exception>([] {xtd::parse<type_t>("--42");});
    }
    
    auto test_method_(parse_default_with_trailing_plus_sign) {
      assert::throws<format_exception>([] {xtd::parse<type_t>("42+");});
    }
    
    auto test_method_(parse_default_with_two_trailing_plus_sign) {
      assert::throws<format_exception>([] {xtd::parse<type_t>("42++");});
    }
    
    auto test_method_(parse_default_with_trailing_minus_sign) {
      if (std::is_signed<type_t>::value)
        assert::throws<format_exception>([] {xtd::parse<type_t>("42-");});
      #if !defined (__linux__)
      else
        assert::throws<format_exception>([] {xtd::parse<type_t>("42-", number_styles::number);});
      #endif
    }
    
    auto test_method_(parse_default_with_two_trailing_minus_sign) {
      assert::throws<format_exception>([] {xtd::parse<type_t>("42--");});
    }
    
    auto test_method_(parse_default_with_parentheses) {
      if (std::is_signed<type_t>::value)
        assert::throws<format_exception>([] {xtd::parse<type_t>("(42)");});
      else
        assert::throws<format_exception>([] {xtd::parse<type_t>("(42)");});
    }
    
    auto test_method_(parse_default_with_two_parentheses) {
      assert::throws<format_exception>([] {xtd::parse<type_t>("((42))");});
    }
    
    auto test_method_(parse_default_with_decimal_point) {
      assert::throws<format_exception>([] {xtd::parse<type_t>("42.0");});
    }
    
    auto test_method_(parse_default_with_two_decimal_point) {
      assert::throws<format_exception>([] {xtd::parse<type_t>("4.2.0");});
    }
    
    auto test_method_(parse_default_with_thousands) {
      if (!std::is_same<type_t, sbyte>::value && !std::is_same<type_t, char>::value && !std::is_same<type_t, unsigned char>::value)
        assert::throws<format_exception>([] {xtd::parse<type_t>("1,234");});
    }
    
    auto test_method_(parse_default_with_two_thousands) {
      if (!std::is_same<type_t, sbyte>::value && !std::is_same<type_t, char>::value && !std::is_same<type_t, unsigned char>::value)
        assert::throws<format_exception>([] {xtd::parse<type_t>("1,,234");});
    }
    
    auto test_method_(parse_default_with_exponent) {
      assert::throws<format_exception>([] {xtd::parse<type_t>("4E+01");});
    }
    
    auto test_method_(parse_default_with_leading_currency_symbol) {
      assert::throws<format_exception>([] {xtd::parse<type_t>("$42");});
    }
    
    auto test_method_(parse_default_with_trailing_currency_symbol) {
      assert::throws<format_exception>([] {xtd::parse<type_t>("42$");});
    }
    
    auto test_method_(parse_default_with_binary_specifier) {
      assert::throws<format_exception>([] {xtd::parse<type_t>("0b101010");});
    }
    
    auto test_method_(parse_default_with_octal_specifier) {
      assert::are_equal(static_cast<type_t>(52), xtd::parse<type_t>("052"));
    }
    
    auto test_method_(parse_default_with_hexa_specifier) {
      assert::throws<format_exception>([] {xtd::parse<type_t>("0x2A");});
    }
    
    auto test_method_(parse_default_invalid) {
      assert::throws<format_exception>([] {xtd::parse<type_t>("z42");});
    }
  };
}
