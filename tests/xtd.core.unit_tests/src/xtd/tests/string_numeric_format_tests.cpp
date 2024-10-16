#include <xtd/string>
#include <xtd/format_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  template <typename value_t>
  class string_numeric_format_tests;
  
  test_class_attribute<string_numeric_format_tests<unsigned char>> string_numeric_format_tests_class_unsigned_char_attr {"string_numeric_format_tests<unsigned_char>"};
  test_class_attribute<string_numeric_format_tests<short>> string_numeric_format_tests_class_short_attr {"string_numeric_format_tests<short>"};
  test_class_attribute<string_numeric_format_tests<unsigned short>> string_numeric_format_tests_class_unsigned_short_attr {"string_numeric_format_tests<unsigned_short>"};
  test_class_attribute<string_numeric_format_tests<int>> string_numeric_format_tests_class_int_attr {"string_numeric_format_tests<int>"};
  test_class_attribute<string_numeric_format_tests<unsigned int>> string_numeric_format_tests_class_unsigned_int_attr {"string_numeric_format_tests<unsigned_int>"};
  test_class_attribute<string_numeric_format_tests<long>> string_numeric_format_tests_class_long_attr {"string_numeric_format_tests<long>"};
  test_class_attribute<string_numeric_format_tests<unsigned long>> string_numeric_format_tests_class_unsigned_long_attr {"string_numeric_format_tests<unsigned_long>"};
  test_class_attribute<string_numeric_format_tests<long long>> string_numeric_format_tests_class_long_long_attr {"string_numeric_format_tests<long_long>"};
  test_class_attribute<string_numeric_format_tests<unsigned long long>> string_numeric_format_tests_class_unsigned_long_long_attr {"string_numeric_format_tests<unsigned_long_long>"};
  test_class_attribute<string_numeric_format_tests<sbyte>> string_numeric_format_tests_class_sbyte_attr {"string_numeric_format_tests<sbyte>"};
  test_class_attribute<string_numeric_format_tests<int16>> string_numeric_format_tests_class_int16_attr {"string_numeric_format_tests<int16>"};
  test_class_attribute<string_numeric_format_tests<int32>> string_numeric_format_tests_class_int32_attr {"string_numeric_format_tests<int32>"};
  test_class_attribute<string_numeric_format_tests<int64>> string_numeric_format_tests_class_int64_attr {"string_numeric_format_tests<int64>"};
  test_class_attribute<string_numeric_format_tests<intptr>> string_numeric_format_tests_class_intptr_attr {"string_numeric_format_tests<intptr>"};
  test_class_attribute<string_numeric_format_tests<ptrdiff_t>> string_numeric_format_tests_class_ptrdiff_t_attr {"string_numeric_format_tests<ptrdiff_t>"};
  test_class_attribute<string_numeric_format_tests<size_t>> string_numeric_format_tests_class_size_t_attr {"string_numeric_format_tests<size_t>"};
  test_class_attribute<string_numeric_format_tests<xtd::byte>> string_numeric_format_tests_class_byte_attr {"string_numeric_format_tests<xtd::byte>"};
  test_class_attribute<string_numeric_format_tests<uint16>> string_numeric_format_tests_class_uint16_attr {"string_numeric_format_tests<uint16>"};
  test_class_attribute<string_numeric_format_tests<uint32>> string_numeric_format_tests_class_uint32_attr {"string_numeric_format_tests<uint32>"};
  test_class_attribute<string_numeric_format_tests<uint64>> string_numeric_format_tests_class_uint64_attr {"string_numeric_format_tests<uint64>"};
  test_class_attribute<string_numeric_format_tests<uintptr>> string_numeric_format_tests_class_uintptr_attr {"string_numeric_format_tests<uintptr>"};
  
  template<typename value_t>
  class string_numeric_format_tests : public test_class {
    inline static std::locale previous_locale;
    static void class_initialize_(class_initialize) {
      previous_locale = std::locale::global(std::locale("en_US.UTF-8"));
    }
    
    static void class_cleanup_(class_cleanup) {
      std::locale::global(previous_locale);
    }
    
    void test_method_(format_with_default_argument) {
      assert::are_equal("42", string::format("{0}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_without_format_argument_separator) {
      assert::throws<format_exception>([] {string::format("{0D}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_left_alignment) {
      assert::are_equal("  42", string::format("{0,4}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_left_alignment_with_plus) {
      assert::are_equal("  42", string::format("{0,+4}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_left_alignment_to_zero) {
      assert::are_equal("42", string::format("{0,0}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_right_alignment) {
      assert::are_equal("42  ", string::format("{0,-4}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_right_alignment_to_zero) {
      assert::are_equal("42", string::format("{0,-0}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_alignment_empty) {
      assert::are_equal("42", string::format("{0,}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_alignment_invalid) {
      assert::throws<format_exception>([] {string::format("{0,a}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_binary_argument) {
      assert::are_equal("101010", string::format("{0:b}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_binary_argument_and_one_digit_precision) {
      assert::are_equal("00101010", string::format("{0:B8}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_binary_argument_and_two_digits_precision) {
      assert::are_equal("0000101010", string::format("{0:B10}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_binary_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:B100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_binary_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:B-3}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_binary_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:Ba}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_currency_argument) {
      assert::are_equal("$42.00", string::format("{0:c}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_currency_argument_and_one_digit_precision) {
      assert::are_not_equal("$42.00000", string::format("{0:C5}", static_cast<value_t>(42)), "The precision of currency format  is ignored");
      assert::are_equal("$42.00", string::format("{0:C5}", static_cast<value_t>(42)), "The precision of currency format is ignored");
    }
    
    void test_method_(format_with_currency_argument_and_two_digits_precision) {
      assert::are_not_equal("$42.00000", string::format("{0:C10}", static_cast<value_t>(42)), "The precision of currency format  is ignored");
      assert::are_equal("$42.00", string::format("{0:C10}", static_cast<value_t>(42)), "The precision of currency format is ignored");
    }
    
    void test_method_(format_with_currency_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:C100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_currency_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:C-5}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_currency_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:Ca}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_decimal_argument) {
      assert::are_equal("42", string::format("{0:d}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_decimal_argument_and_one_digit_precision) {
      assert::are_equal("00042", string::format("{0:D5}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_decimal_argument_and_two_digits_precision) {
      assert::are_equal("0000000042", string::format("{0:D10}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_decimal_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:D100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_decimal_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:D-5}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_decimal_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:Da}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_negative_with_decimal_argument_and_one_digit_precision) {
      if (std::is_signed<value_t>::value)
        assert::are_equal("-000123", string::format("{0:D6}", static_cast<value_t>(-123)));
    }
    
    void test_method_(format_negative_with_decimal_argument_and_two_digits_precision) {
      if (std::is_signed<value_t>::value)
        assert::are_equal("-0000000123", string::format("{0:D10}", static_cast<value_t>(-123)));
    }
    
    void test_method_(format_negative_with_decimal_argument_and_three_digits_precision) {
      if (std::is_signed<value_t>::value)
        assert::throws<xtd::format_exception>([] {string::format("{0:D100}", static_cast<value_t>(-123));});
    }
    
    void test_method_(format_negative_with_decimal_argument_and_negative_precision) {
      if (std::is_signed<value_t>::value)
        assert::throws<xtd::format_exception>([] {string::format("{0:D-6}", static_cast<value_t>(-123));});
    }
    
    void test_method_(format_with_exponencial_argument) {
      assert::are_equal("4.200000e+01", string::format("{0:e}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_exponencial_argument_and_one_digit_precision) {
      assert::are_equal("4.20000000E+01", string::format("{0:E8}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_exponencial_argument_and_two_digits_precision) {
      assert::are_equal("4.2000000000E+01", string::format("{0:E10}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_exponencial_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:E100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_exponencial_argument_and_nagetive_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:E-10}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_exponencial_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:Ea}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_fixed_point_argument) {
      assert::are_equal("42.00", string::format("{0:f}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_fixed_point_argument_and_one_digit_precision) {
      assert::are_equal("42.0000", string::format("{0:F4}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_fixed_point_argument_and_two_digits_precision) {
      assert::are_equal("42.0000000000", string::format("{0:F10}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_fixed_point_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:F100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_fixed_point_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:F-4}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_fixed_point_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:Fa}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_general_argument) {
      assert::are_equal("42", string::format("{0:g}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_general_argument_and_one_digit_precision) {
      assert::are_equal("42", string::format("{0:G2}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_general_argument_and_two_digits_precision) {
      assert::are_equal("42", string::format("{0:G10}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_general_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:G100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_general_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:G-2}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_general_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:Ga}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_number_argument) {
      if (std::is_same<value_t, unsigned char>::value || std::is_same<value_t, sbyte>::value || std::is_same<value_t, xtd::byte>::value)
        assert::are_equal("123.00", string::format("{0:n}", static_cast<value_t>(123)));
      else if (std::is_same<value_t, short>::value || std::is_same<value_t, unsigned short>::value)
        assert::are_equal("1,234.00", string::format("{0:n}", static_cast<value_t>(1234)));
      else
        assert::are_equal("1,234,567.00", string::format("{0:n}", static_cast<value_t>(1234567)));
    }
    
    void test_method_(format_with_number_argument_and_one_digit_precision) {
      if (std::is_same<value_t, unsigned char>::value || std::is_same<value_t, sbyte>::value || std::is_same<value_t, xtd::byte>::value)
        assert::are_equal("123.0000", string::format("{0:N4}", static_cast<value_t>(123)));
      else if (std::is_same<value_t, short>::value || std::is_same<value_t, unsigned short>::value)
        assert::are_equal("1,234.0000", string::format("{0:N4}", static_cast<value_t>(1234)));
      else
        assert::are_equal("1,234,567.0000", string::format("{0:N4}", static_cast<value_t>(1234567)));
    }
    
    void test_method_(format_with_number_argument_and_two_digits_precision) {
      if (std::is_same<value_t, unsigned char>::value || std::is_same<value_t, sbyte>::value || std::is_same<value_t, xtd::byte>::value)
        assert::are_equal("123.0000000000", string::format("{0:N10}", static_cast<value_t>(123)));
      else if (std::is_same<value_t, short>::value || std::is_same<value_t, unsigned short>::value)
        assert::are_equal("1,234.0000000000", string::format("{0:N10}", static_cast<value_t>(1234)));
      else
        assert::are_equal("1,234,567.0000000000", string::format("{0:N10}", static_cast<value_t>(1234567)));
    }
    
    void test_method_(format_with_number_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:N100}", static_cast<value_t>(123));});
    }
    
    void test_method_(format_with_number_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:N-4}", static_cast<value_t>(123));});
    }
    
    void test_method_(format_with_number_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:Na}", static_cast<value_t>(123));});
    }
    
    void test_method_(format_with_octal_argument) {
      assert::are_equal("52", string::format("{0:o}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_octal_argument_and_one_digit_precision) {
      assert::are_equal("00052", string::format("{0:O5}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_octal_argument_and_two_digits_precision) {
      assert::are_equal("0000000052", string::format("{0:O10}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_octal_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:O100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_octal_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:O-5}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_octal_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:Oa}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_percent_argument) {
      assert::are_equal("100.00 %", string::format("{0:p}", static_cast<value_t>(1)));
    }
    
    void test_method_(format_with_percent_argument_and_one_digit_precision) {
      assert::are_equal("600.0000 %", string::format("{0:P4}", static_cast<value_t>(6)));
    }
    
    void test_method_(format_with_percent_argument_and_two_digits_precision) {
      assert::are_equal("600.0000000000 %", string::format("{0:P10}", static_cast<value_t>(6)));
    }
    
    void test_method_(format_with_percent_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:P100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_percent_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:P-4}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_percent_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:Pa}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_hexadecimal_argument) {
      assert::are_equal("2a", string::format("{0:x}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_hexadecimal_argument_and_one_digit_precision) {
      assert::are_equal("002A", string::format("{0:X4}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_hexadecimal_argument_and_two_digits_precision) {
      assert::are_equal("000000002A", string::format("{0:X10}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_hexadecimal_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:X100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_hexadecimal_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:X-4}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_hexadecimal_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {string::format("{0:Xa}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_alignment_before_format) {
      assert::are_equal("    42", string::format("{0,6:D}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_alignment_after_format) {
      assert::throws<xtd::format_exception>([] {string::format("{0:D,6}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_invalid_format) {
      assert::throws<xtd::format_exception>([] {string::format("{0:V}", static_cast<value_t>(42));});
    }
  };
}
