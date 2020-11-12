#include <xtd/strings>
#include <xtd/tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  template <typename Value>
  class test_numeric_parse_string;
  
  test_class_attribute<test_numeric_parse_string<char>> test_numeric_parse_string_class_char_attr {"test_numeric_parse_string<char>"};
  test_class_attribute<test_numeric_parse_string<unsigned char>> test_numeric_parse_string_class_unsigned_char_attr {"test_numeric_parse_string<unsigned char>"};
  test_class_attribute<test_numeric_parse_string<short>> test_numeric_parse_string_class_short_attr {"test_numeric_parse_string<short>"};
  test_class_attribute<test_numeric_parse_string<unsigned short>> test_numeric_parse_string_class_unsigned_short_attr {"test_numeric_parse_string<unsigned short>"};
  test_class_attribute<test_numeric_parse_string<int>> test_numeric_parse_string_class_int_attr {"test_numeric_parse_string<int>"};
  test_class_attribute<test_numeric_parse_string<unsigned int>> test_numeric_parse_string_class_unsigned_int_attr {"test_numeric_parse_string<unsigned int>"};
  test_class_attribute<test_numeric_parse_string<long>> test_numeric_parse_string_class_long_attr {"test_numeric_parse_string<long>"};
  test_class_attribute<test_numeric_parse_string<unsigned long>> test_numeric_parse_string_class_unsigned_long_attr {"test_numeric_parse_string<unsigned long>"};
  test_class_attribute<test_numeric_parse_string<long long>> test_numeric_parse_string_class_long_long_attr {"test_numeric_parse_string<long long>"};
  test_class_attribute<test_numeric_parse_string<unsigned long long>> test_numeric_parse_string_class_unsigned_long_long_attr {"test_numeric_parse_string<unsigned long long>"};
  test_class_attribute<test_numeric_parse_string<int8_t>> test_numeric_parse_string_class_int8_t_attr {"test_numeric_parse_string<int8_t>"};
  test_class_attribute<test_numeric_parse_string<int16_t>> test_numeric_parse_string_class_int16_t_attr {"test_numeric_parse_string<int16_t>"};
  test_class_attribute<test_numeric_parse_string<int32_t>> test_numeric_parse_string_class_int32_t_attr {"test_numeric_parse_string<int32_t>"};
  test_class_attribute<test_numeric_parse_string<int64_t>> test_numeric_parse_string_class_int64_t_attr {"test_numeric_parse_string<int64_t>"};
  test_class_attribute<test_numeric_parse_string<intptr_t>> test_numeric_parse_string_class_intptr_t_attr {"test_numeric_parse_string<intptr_t>"};
  test_class_attribute<test_numeric_parse_string<ptrdiff_t>> test_numeric_parse_string_class_ptrdiff_t_attr {"test_numeric_parse_string<ptrdiff_t>"};
  test_class_attribute<test_numeric_parse_string<size_t>> test_numeric_parse_string_class_size_t_attr {"test_numeric_parse_string<size_t>"};
  test_class_attribute<test_numeric_parse_string<uint8_t>> test_numeric_parse_string_class_uint8_t_attr {"test_numeric_parse_string<uint8_t>"};
  test_class_attribute<test_numeric_parse_string<uint16_t>> test_numeric_parse_string_class_uint16_t_attr {"test_numeric_parse_string<uint16_t>"};
  test_class_attribute<test_numeric_parse_string<uint32_t>> test_numeric_parse_string_class_uint32_t_attr {"test_numeric_parse_string<uint32_t>"};
  test_class_attribute<test_numeric_parse_string<uint64_t>> test_numeric_parse_string_class_uint64_t_attr {"test_numeric_parse_string<uint64_t>"};
  test_class_attribute<test_numeric_parse_string<uintptr_t>> test_numeric_parse_string_class_uintptr_t_attr {"test_numeric_parse_string<uintptr_t>"};
  
  template <typename Value>
  class test_numeric_parse_string : public test_class {
  public:
    static void class_initialize_(class_initialize) {
      std::locale::global(std::locale("en_US.UTF-8"));
    }
    
    void test_method_(parse_default) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42"));
    }
    
    void test_method_(parse_default_with_leading_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>(" \f\n\r\t\v42"));
    }
    
    void test_method_(parse_default_with_trailing_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42 \f\n\r\t\v"));
    }
    
    void test_method_(parse_default_with_leading_plus_sign) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("+42"));
    }
    
    void test_method_(parse_default_with_two_leading_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("++42");});
    }
    
    void test_method_(parse_default_with_leading_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("-42"));
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("-42");});
    }

    void test_method_(parse_default_with_two_leading_minus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("--42");});
    }
    
    void test_method_(parse_default_with_trailing_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42+");});
    }
    
    void test_method_(parse_default_with_two_trailing_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42++");});
    }
    
    void test_method_(parse_default_with_trailing_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42-");});
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42-", number_styles::number);});
    }
    
    void test_method_(parse_default_with_two_trailing_minus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42--");});
    }
    
    void test_method_(parse_default_with_parentheses) {
      if (std::is_signed<Value>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("(42)");});
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("(42)");});
    }
    
    void test_method_(parse_default_with_two_parentheses) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("((42))");});
    }
    
    void test_method_(parse_default_with_decimal_point) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42.0");});
    }
    
    void test_method_(parse_default_with_two_decimal_point) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("4.2.0");});
    }
    
    void test_method_(parse_default_with_thousands) {
      if (!std::is_same<Value, int8_t>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("1,234");});
    }

    void test_method_(parse_default_with_two_thousands) {
      if (!std::is_same<Value, int8_t>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("1,,234");});
    }
    
    void test_method_(parse_default_with_exponent) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("4E+01");});
    }
    
    void test_method_(parse_default_with_leading_currency_symbol) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("$42");});
    }
    
    void test_method_(parse_default_with_trailing_currency_symbol) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42$");});
    }
    
    void test_method_(parse_default_with_binary_specifier) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("0b42");});
    }
    
    void test_method_(parse_default_with_octal_specifier) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("042"));
    }
    
    void test_method_(parse_default_with_hexa_specifier) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("0x42");});
    }

    void test_method_(parse_default_invalid) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("z42");});
    }
    
    /*
    void test_method_(parse_styles_none) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42", number_styles::none));
    }

    void test_method_(parse_styles_none_with_leading_white_spaces) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>(" \f\n\r\t\v42", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_trailing_white_spaces) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42 \f\n\r\t\v", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_leading_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("+42", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_two_leading_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("++42", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_leading_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("-42", number_styles::none);});
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("-42", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_two_leading_minus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("--42", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_trailing_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42+", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_two_trailing_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42++", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_trailing_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42-", number_styles::none);});
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42-", number_styles::number);});
    }
    
    void test_method_(parse_styles_none_with_two_trailing_minus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42--", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_parentheses) {
      if (std::is_signed<Value>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("(42)", number_styles::none);});
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("(42)", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_two_parentheses) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("((42))", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_decimal_point) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42.0", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_two_decimal_point) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("4.2.0", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_thousands) {
      if (!std::is_same<Value, int8_t>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("1,234", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_two_thousands) {
      if (!std::is_same<Value, int8_t>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("1,,234", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_exponent) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("4E+01", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_leading_currency_symbol) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("$42", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_trailing_currency_symbol) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42$", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_binary_specifier) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("0b42", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_with_octal_specifier) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("042", number_styles::none));
    }
    
    void test_method_(parse_styles_none_with_hexa_specifier) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("0x42", number_styles::none);});
    }
    
    void test_method_(parse_styles_none_invalid) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("z42", number_styles::none);});
    }
    
    void test_method_(parse_styles_integer) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42", number_styles::integer));
    }
    
    void test_method_(parse_styles_integer_with_leading_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>(" \f\n\r\t\v42", number_styles::integer));
    }
    
    void test_method_(parse_styles_integer_with_trailing_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42 \f\n\r\t\v", number_styles::integer));
    }
    
    void test_method_(parse_styles_integer_with_leading_plus_sign) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("+42", number_styles::integer));
    }
    
    void test_method_(parse_styles_integer_with_two_leading_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("++42", number_styles::integer);});
    }
    
    void test_method_(parse_styles_integer_with_leading_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("-42", number_styles::integer));
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("-42", number_styles::integer);});
    }
    
    void test_method_(parse_styles_integer_with_two_leading_minus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("--42", number_styles::integer);});
    }
    
    void test_method_(parse_styles_integer_with_trailing_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42+", number_styles::integer);});
    }
    
    void test_method_(parse_styles_integer_with_two_trailing_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42++", number_styles::integer);});
    }
    
    void test_method_(parse_styles_integer_with_trailing_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42-", number_styles::integer);});
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42-", number_styles::number);});
    }
    
    void test_method_(parse_styles_integer_with_two_trailing_minus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42--", number_styles::integer);});
    }
    
    void test_method_(parse_styles_integer_with_parentheses) {
      if (std::is_signed<Value>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("(42)", number_styles::integer);});
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("(42)", number_styles::integer);});
    }
    
    void test_method_(parse_styles_integer_with_two_parentheses) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("((42))", number_styles::integer);});
    }
    
    void test_method_(parse_styles_integer_with_decimal_point) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42.0", number_styles::integer);});
    }
    
    void test_method_(parse_styles_integer_with_two_decimal_point) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("4.2.0", number_styles::integer);});
    }
    
    void test_method_(parse_styles_integer_with_thousands) {
      if (!std::is_same<Value, int8_t>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("1,234", number_styles::integer);});
    }
    
    void test_method_(parse_styles_integer_with_two_thousands) {
      if (!std::is_same<Value, int8_t>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("1,,234", number_styles::integer);});
    }
    
    void test_method_(parse_styles_integer_with_exponent) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("4E+01", number_styles::integer);});
    }
    
    void test_method_(parse_styles_integer_with_currency_symbol) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("$42", number_styles::integer);});
    }
    
    void test_method_(parse_styles_integer_with_binary_specifier) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("0b42", number_styles::integer);});
    }
    
    void test_method_(parse_styles_integer_with_octal_specifier) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("042", number_styles::integer));
    }
    
    void test_method_(parse_styles_integer_with_hexa_specifier) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("0x42", number_styles::integer);});
    }
    
    void test_method_(parse_styles_integer_invalid) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("z42", number_styles::integer);});
    }
    
    void test_method_(parse_styles_number) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42", number_styles::number));
    }
    
    void test_method_(parse_styles_number_with_leading_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>(" \f\n\r\t\v42", number_styles::number));
    }
    
    void test_method_(parse_styles_number_with_trailing_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42 \f\n\r\t\v", number_styles::number));
    }
    
    void test_method_(parse_styles_number_with_leading_plus_sign) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("+42", number_styles::number));
    }
    
    void test_method_(parse_styles_number_with_two_leading_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("++42", number_styles::number);});
    }
    
    void test_method_(parse_styles_number_with_leading_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("-42", number_styles::number));
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("-42", number_styles::number);});
    }
    
    void test_method_(parse_styles_number_with_two_leading_minus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("--42", number_styles::number);});
    }
    
    void test_method_(parse_styles_number_with_trailing_plus_sign) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42+", number_styles::number));
    }
    
    void test_method_(parse_styles_number_with_two_trailing_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42++", number_styles::number);});
    }
    
    void test_method_(parse_styles_number_with_trailing_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("42-", number_styles::number));
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42-", number_styles::number);});
    }
    
    void test_method_(parse_styles_number_with_two_trailing_minus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42--", number_styles::number);});
    }
    
    void test_method_(parse_styles_number_with_parentheses) {
      if (std::is_signed<Value>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("(42)", number_styles::number);});
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("(42)", number_styles::number);});
    }
    
    void test_method_(parse_styles_number_with_two_parentheses) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("((42))", number_styles::number);});
    }
    
    void test_method_(parse_styles_number_with_decimal_point) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42.0", number_styles::number));
    }
    
    void test_method_(parse_styles_number_with_two_decimal_point) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("4.2.0", number_styles::number);});
    }
    
    void test_method_(parse_styles_number_with_thousands) {
      if (!std::is_same<Value, int8_t>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::are_equal(static_cast<Value>(1234), xtd::parse<Value>("1,234", number_styles::number));
    }
    
    void test_method_(parse_styles_number_with_two_thousands) {
      if (!std::is_same<Value, int8_t>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::are_equal(static_cast<Value>(1234), xtd::parse<Value>("1,,234", number_styles::number));
    }
    
    void test_method_(parse_styles_number_with_exponent) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("4E+01", number_styles::number);});
    }
    
    void test_method_(parse_styles_number_with_leading_currency_symbol) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("$42", number_styles::number);});
    }
    
    void test_method_(parse_styles_number_with_trailing_currency_symbol) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42$", number_styles::number);});
    }
    
    void test_method_(parse_styles_number_with_binary_specifier) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("0b42", number_styles::number);});
    }
    
    void test_method_(parse_styles_number_with_octal_specifier) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("042", number_styles::number));
    }
    
    void test_method_(parse_styles_number_with_hexa_specifier) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("0x42", number_styles::number);});
    }
    
    void test_method_(parse_styles_number_invalid) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("z42", number_styles::number);});
    }
    
    void test_method_(parse_styles_fixed_point) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42", number_styles::fixed_point));
    }
    
    void test_method_(parse_styles_fixed_point_with_leading_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>(" \f\n\r\t\v42", number_styles::fixed_point));
    }
    
    void test_method_(parse_styles_fixed_point_with_trailing_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42 \f\n\r\t\v", number_styles::fixed_point));
    }
    
    void test_method_(parse_styles_fixed_point_with_leading_plus_sign) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("+42", number_styles::fixed_point));
    }
    
    void test_method_(parse_styles_fixed_point_with_two_leading_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("++42", number_styles::fixed_point);});
    }
    
    void test_method_(parse_styles_fixed_point_with_leading_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("-42", number_styles::fixed_point));
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("-42", number_styles::fixed_point);});
    }
    
    void test_method_(parse_styles_fixed_point_with_two_leading_minus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("--42", number_styles::fixed_point);});
    }
    
    void test_method_(parse_styles_fixed_point_with_trailing_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42+", number_styles::fixed_point);});
    }
    
    void test_method_(parse_styles_fixed_point_with_two_trailing_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42++", number_styles::fixed_point);});
    }
    
    void test_method_(parse_styles_fixed_point_with_trailing_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42-", number_styles::fixed_point);});
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42-", number_styles::fixed_point);});
    }
    
    void test_method_(parse_styles_fixed_point_with_two_trailing_minus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42--", number_styles::fixed_point);});
    }
    
    void test_method_(parse_styles_fixed_point_with_parentheses) {
      if (std::is_signed<Value>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("(42)", number_styles::fixed_point);});
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("(42)", number_styles::fixed_point);});
    }
    
    void test_method_(parse_styles_fixed_point_with_two_parentheses) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("((42))", number_styles::fixed_point);});
    }
    
    void test_method_(parse_styles_fixed_point_with_decimal_point) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42.0", number_styles::fixed_point));
    }
    
    void test_method_(parse_styles_fixed_point_with_two_decimal_point) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("4.2.0", number_styles::fixed_point);});
    }
    
    void test_method_(parse_styles_fixed_point_with_thousands) {
      if (!std::is_same<Value, int8_t>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("1,234", number_styles::fixed_point);});
    }
    
    void test_method_(parse_styles_fixed_point_with_two_thousands) {
      if (!std::is_same<Value, int8_t>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("1,,234", number_styles::fixed_point);});
    }
    
    void test_method_(parse_styles_fixed_point_with_exponent) {
      assert::are_equal(static_cast<Value>(40), xtd::parse<Value>("4E+01", number_styles::fixed_point));
    }
    
    void test_method_(parse_styles_fixed_point_with_leading_currency_symbol) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("$42", number_styles::fixed_point);});
    }
    
    void test_method_(parse_styles_fixed_point_with_trailing_currency_symbol) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42$", number_styles::fixed_point);});
    }
    
    void test_method_(parse_styles_fixed_point_with_binary_specifier) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("0b42", number_styles::fixed_point);});
    }
    
    void test_method_(parse_styles_fixed_point_with_octal_specifier) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("042", number_styles::fixed_point));
    }
    
    void test_method_(parse_styles_fixed_point_with_hexa_specifier) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("0x42", number_styles::fixed_point);});
    }
    
    void test_method_(parse_styles_fixed_point_invalid) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("z42", number_styles::fixed_point);});
    }
    
    void test_method_(parse_styles_currency) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42", number_styles::currency));
    }
    
    void test_method_(parse_styles_currency_with_leading_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>(" \f\n\r\t\v42", number_styles::currency));
    }
    
    void test_method_(parse_styles_currency_with_trailing_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42 \f\n\r\t\v", number_styles::currency));
    }
    
    void test_method_(parse_styles_currency_with_leading_plus_sign) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("+42", number_styles::currency));
    }
    
    void test_method_(parse_styles_currency_with_two_leading_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("++42", number_styles::currency);});
    }
    
    void test_method_(parse_styles_currency_with_leading_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("-42", number_styles::currency));
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("-42", number_styles::currency);});
    }
    
    void test_method_(parse_styles_currency_with_two_leading_minus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("--42", number_styles::currency);});
    }
    
    void test_method_(parse_styles_currency_with_trailing_plus_sign) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42+", number_styles::currency));
    }
    
    void test_method_(parse_styles_currency_with_two_trailing_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42++", number_styles::currency);});
    }
    
    void test_method_(parse_styles_currency_with_trailing_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("42-", number_styles::currency));
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42-", number_styles::currency);});
    }
    
    void test_method_(parse_styles_currency_with_two_trailing_minus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42--", number_styles::currency);});
    }
    
    void test_method_(parse_styles_currency_with_parentheses) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("(42)", number_styles::currency));
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("(42)", number_styles::currency);});
    }
    
    void test_method_(parse_styles_currency_with_two_parentheses) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("((42))", number_styles::currency);});
    }
    
    void test_method_(parse_styles_currency_with_decimal_point) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42.0", number_styles::currency));
    }
    
    void test_method_(parse_styles_currency_with_two_decimal_point) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("4.2.0", number_styles::currency);});
    }
    
    void test_method_(parse_styles_currency_with_thousands) {
      if (!std::is_same<Value, int8_t>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::are_equal(static_cast<Value>(1234), xtd::parse<Value>("1,234", number_styles::currency));
    }
    
    void test_method_(parse_styles_currency_with_two_thousands) {
      if (!std::is_same<Value, int8_t>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::are_equal(static_cast<Value>(1234), xtd::parse<Value>("1,,234", number_styles::currency));
    }
    
    void test_method_(parse_styles_currency_with_exponent) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("4E+01", number_styles::currency);});
    }
    
    void test_method_(parse_styles_currency_with_leading_currency_symbol) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("$42", number_styles::currency));
    }
    
    void test_method_(parse_styles_currency_with_trailing_currency_symbol) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42$", number_styles::currency));
    }

    void test_method_(parse_styles_currency_with_binary_specifier) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("0b42", number_styles::currency);});
    }
    
    void test_method_(parse_styles_currency_with_octal_specifier) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("042", number_styles::currency));
    }
    
    void test_method_(parse_styles_currency_with_hexa_specifier) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("0x42", number_styles::currency);});
    }
    
    void test_method_(parse_styles_currency_invalid) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("z42", number_styles::currency);});
    }
    
    void test_method_(parse_styles_any) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42", number_styles::any));
    }
    
    void test_method_(parse_styles_any_with_leading_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>(" \f\n\r\t\v42", number_styles::any));
    }
    
    void test_method_(parse_styles_any_with_trailing_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42 \f\n\r\t\v", number_styles::any));
    }
    
    void test_method_(parse_styles_any_with_leading_plus_sign) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("+42", number_styles::any));
    }
    
    void test_method_(parse_styles_any_with_two_leading_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("++42", number_styles::any);});
    }
    
    void test_method_(parse_styles_any_with_leading_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("-42", number_styles::any));
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("-42", number_styles::any);});
    }
    
    void test_method_(parse_styles_any_with_two_leading_minus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("--42", number_styles::any);});
    }
    
    void test_method_(parse_styles_any_with_trailing_plus_sign) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42+", number_styles::any));
    }
    
    void test_method_(parse_styles_any_with_two_trailing_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42++", number_styles::any);});
    }
    
    void test_method_(parse_styles_any_with_trailing_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("42-", number_styles::any));
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42-", number_styles::any);});
    }
    
    void test_method_(parse_styles_any_with_two_trailing_minus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("42--", number_styles::any);});
    }
    
    void test_method_(parse_styles_any_with_parentheses) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("(42)", number_styles::any));
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("(42)", number_styles::any);});
    }
    
    void test_method_(parse_styles_any_with_two_parentheses) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("((42))", number_styles::any);});
    }
    
    void test_method_(parse_styles_any_with_decimal_point) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42.0", number_styles::any));
    }
    
    void test_method_(parse_styles_any_with_two_decimal_point) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("4.2.0", number_styles::any);});
    }
    
    void test_method_(parse_styles_any_with_thousands) {
      if (!std::is_same<Value, int8_t>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::are_equal(static_cast<Value>(1234), xtd::parse<Value>("1,234", number_styles::any));
    }
    
    void test_method_(parse_styles_any_with_two_thousands) {
      if (!std::is_same<Value, int8_t>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::are_equal(static_cast<Value>(1234), xtd::parse<Value>("1,,234", number_styles::any));
    }
    
    void test_method_(parse_styles_any_with_exponent) {
      assert::are_equal(static_cast<Value>(40), xtd::parse<Value>("4E+01", number_styles::any));
    }
    
    void test_method_(parse_styles_any_with_leading_currency_symbol) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("$42", number_styles::any));
    }
    
    void test_method_(parse_styles_any_with_trailing_currency_symbol) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42$", number_styles::any));
    }
    
    void test_method_(parse_styles_any_with_binary_specifier) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("0b42", number_styles::any);});
    }
    
    void test_method_(parse_styles_any_with_octal_specifier) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("042", number_styles::any));
    }
    
    void test_method_(parse_styles_any_with_hexa_specifier) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("0x42", number_styles::any);});
    }
    
    void test_method_(parse_styles_any_invalid) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("z42", number_styles::any);});
    }
     */

    void test_method_(parse_with_number_styles_binary) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("0b101010", number_styles::binary_number));
    }

    void test_method_(parse_with_number_styles_octal) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("052", number_styles::octal_number));
    }

    void test_method_(parse_with_number_styles_hexa) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("0x2A", number_styles::hex_number));
    }
  };
}
