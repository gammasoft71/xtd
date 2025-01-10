#include <xtd/format>
#include <xtd/format_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
#if defined(__xtd__cpp_lib_char8_t)
  template<class value_t>
  class format_u8string_numeric_tests;
  
  test_class_attribute<format_u8string_numeric_tests<unsigned char>> format_u8string_numeric_tests_class_unsigned_char_attr {"format_u8string_numeric_tests<unsigned_char>"};
  test_class_attribute<format_u8string_numeric_tests<short>> format_u8string_numeric_tests_class_short_attr {"format_u8string_numeric_tests<short>"};
  test_class_attribute<format_u8string_numeric_tests<unsigned short>> format_u8string_numeric_tests_class_unsigned_short_attr {"format_u8string_numeric_tests<unsigned_short>"};
  test_class_attribute<format_u8string_numeric_tests<int>> format_u8string_numeric_tests_class_int_attr {"format_u8string_numeric_tests<int>"};
  test_class_attribute<format_u8string_numeric_tests<unsigned int>> format_u8string_numeric_tests_class_unsigned_int_attr {"format_u8string_numeric_tests<unsigned_int>"};
  test_class_attribute<format_u8string_numeric_tests<long>> format_u8string_numeric_tests_class_long_attr {"format_u8string_numeric_tests<long>"};
  test_class_attribute<format_u8string_numeric_tests<unsigned long>> format_u8string_numeric_tests_class_unsigned_long_attr {"format_u8string_numeric_tests<unsigned_long>"};
  test_class_attribute<format_u8string_numeric_tests<long long>> format_u8string_numeric_tests_class_long_long_attr {"format_u8string_numeric_tests<long_long>"};
  test_class_attribute<format_u8string_numeric_tests<unsigned long long>> format_u8string_numeric_tests_class_unsigned_long_long_attr {"format_u8string_numeric_tests<unsigned_long_long>"};
  test_class_attribute<format_u8string_numeric_tests<sbyte>> format_u8string_numeric_tests_class_sbyte_attr {"format_u8string_numeric_tests<sbyte>"};
  test_class_attribute<format_u8string_numeric_tests<int16>> format_u8string_numeric_tests_class_int16_attr {"format_u8string_numeric_tests<int16>"};
  test_class_attribute<format_u8string_numeric_tests<int32>> format_u8string_numeric_tests_class_int32_attr {"format_u8string_numeric_tests<int32>"};
  test_class_attribute<format_u8string_numeric_tests<int64>> format_u8string_numeric_tests_class_int64_attr {"format_u8string_numeric_tests<int64>"};
  test_class_attribute<format_u8string_numeric_tests<intptr>> format_u8string_numeric_tests_class_intptr_attr {"format_u8string_numeric_tests<intptr>"};
  test_class_attribute<format_u8string_numeric_tests<ptrdiff_t>> format_u8string_numeric_tests_class_ptrdiff_t_attr {"format_u8string_numeric_tests<ptrdiff_t>"};
  test_class_attribute<format_u8string_numeric_tests<size_t>> format_u8string_numeric_tests_class_size_t_attr {"format_u8string_numeric_tests<size_t>"};
  test_class_attribute<format_u8string_numeric_tests<xtd::byte>> format_u8string_numeric_tests_class_byte_attr {"format_u8string_numeric_tests<xtd::byte>"};
  test_class_attribute<format_u8string_numeric_tests<uint16>> format_u8string_numeric_tests_class_uint16_attr {"format_u8string_numeric_tests<uint16>"};
  test_class_attribute<format_u8string_numeric_tests<uint32>> format_u8string_numeric_tests_class_uint32_attr {"format_u8string_numeric_tests<uint32>"};
  test_class_attribute<format_u8string_numeric_tests<uint64>> format_u8string_numeric_tests_class_uint64_attr {"format_u8string_numeric_tests<uint64>"};
  test_class_attribute<format_u8string_numeric_tests<uintptr>> format_u8string_numeric_tests_class_uintptr_attr {"format_u8string_numeric_tests<uintptr>"};
  
  template<class value_t>
  class format_u8string_numeric_tests : public test_class {
    inline static std::locale previous_locale;
    static void class_initialize_(class_initialize) {
      previous_locale = std::locale::global(std::locale("en_US.UTF-8"));
    }
    
    static void class_cleanup_(class_cleanup) {
      std::locale::global(previous_locale);
    }
    
    void test_method_(format_with_default_argument) {
      assert::are_equal(u8"42", format(u8"{0}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_without_format_argument_separator) {
      assert::throws<format_exception>([] {format(u8"{0D}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_left_alignment) {
      assert::are_equal(u8"  42", format(u8"{0,4}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_left_alignment_with_plus) {
      assert::are_equal(u8"  42", format(u8"{0,+4}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_left_alignment_to_zero) {
      assert::are_equal(u8"42", format(u8"{0,0}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_right_alignment) {
      assert::are_equal(u8"42  ", format(u8"{0,-4}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_right_alignment_to_zero) {
      assert::are_equal(u8"42", format(u8"{0,-0}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_alignment_empty) {
      assert::are_equal(u8"42", format(u8"{0,}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_alignment_invalid) {
      assert::throws<format_exception>([] {format(u8"{0,a}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_binary_argument) {
      assert::are_equal(u8"101010", format(u8"{0:b}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_binary_argument_and_one_digit_precision) {
      assert::are_equal(u8"00101010", format(u8"{0:B8}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_binary_argument_and_two_digits_precision) {
      assert::are_equal(u8"0000101010", format(u8"{0:B10}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_binary_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:B100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_binary_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:B-3}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_binary_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:Ba}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_currency_argument) {
      assert::are_equal(u8"$42.00", format(u8"{0:c}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_currency_argument_and_one_digit_precision) {
      assert::are_not_equal("$42.00000", format(u8"{0:C5}", static_cast<value_t>(42)), "The precision of currency format  is ignored");
      assert::are_equal(u8"$42.00", format(u8"{0:C5}", static_cast<value_t>(42)), "The precision of currency format is ignored");
    }
    
    void test_method_(format_with_currency_argument_and_two_digits_precision) {
      assert::are_not_equal("$42.00000", format(u8"{0:C10}", static_cast<value_t>(42)), "The precision of currency format  is ignored");
      assert::are_equal(u8"$42.00", format(u8"{0:C10}", static_cast<value_t>(42)), "The precision of currency format is ignored");
    }
    
    void test_method_(format_with_currency_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:C100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_currency_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:C-5}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_currency_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:Ca}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_decimal_argument) {
      assert::are_equal(u8"42", format(u8"{0:d}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_decimal_argument_and_one_digit_precision) {
      assert::are_equal(u8"00042", format(u8"{0:D5}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_decimal_argument_and_two_digits_precision) {
      assert::are_equal(u8"0000000042", format(u8"{0:D10}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_decimal_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:D100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_decimal_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:D-5}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_decimal_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:Da}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_negative_with_decimal_argument_and_one_digit_precision) {
      if (std::is_signed<value_t>::value)
        assert::are_equal(u8"-000123", format(u8"{0:D6}", static_cast<value_t>(-123)));
    }
    
    void test_method_(format_negative_with_decimal_argument_and_two_digits_precision) {
      if (std::is_signed<value_t>::value)
        assert::are_equal(u8"-0000000123", format(u8"{0:D10}", static_cast<value_t>(-123)));
    }
    
    void test_method_(format_negative_with_decimal_argument_and_three_digits_precision) {
      if (std::is_signed<value_t>::value)
        assert::throws<xtd::format_exception>([] {format(u8"{0:D100}", static_cast<value_t>(-123));});
    }
    
    void test_method_(format_negative_with_decimal_argument_and_negative_precision) {
      if (std::is_signed<value_t>::value)
        assert::throws<xtd::format_exception>([] {format(u8"{0:D-6}", static_cast<value_t>(-123));});
    }
    
    void test_method_(format_with_exponencial_argument) {
      assert::are_equal(u8"4.200000e+01", format(u8"{0:e}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_exponencial_argument_and_one_digit_precision) {
      assert::are_equal(u8"4.20000000E+01", format(u8"{0:E8}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_exponencial_argument_and_two_digits_precision) {
      assert::are_equal(u8"4.2000000000E+01", format(u8"{0:E10}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_exponencial_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:E100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_exponencial_argument_and_nagetive_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:E-10}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_exponencial_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:Ea}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_fixed_point_argument) {
      assert::are_equal(u8"42.00", format(u8"{0:f}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_fixed_point_argument_and_one_digit_precision) {
      assert::are_equal(u8"42.0000", format(u8"{0:F4}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_fixed_point_argument_and_two_digits_precision) {
      assert::are_equal(u8"42.0000000000", format(u8"{0:F10}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_fixed_point_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:F100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_fixed_point_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:F-4}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_fixed_point_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:Fa}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_general_argument) {
      assert::are_equal(u8"42", format(u8"{0:g}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_general_argument_and_one_digit_precision) {
      assert::are_equal(u8"42", format(u8"{0:G2}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_general_argument_and_two_digits_precision) {
      assert::are_equal(u8"42", format(u8"{0:G10}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_general_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:G100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_general_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:G-2}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_general_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:Ga}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_number_argument) {
      if (std::is_same<value_t, unsigned char>::value || std::is_same<value_t, sbyte>::value || std::is_same<value_t, xtd::byte>::value)
        assert::are_equal(u8"123.00", format(u8"{0:n}", static_cast<value_t>(123)));
      else if (std::is_same<value_t, short>::value || std::is_same<value_t, unsigned short>::value)
        assert::are_equal(u8"1,234.00", format(u8"{0:n}", static_cast<value_t>(1234)));
      else
        assert::are_equal(u8"1,234,567.00", format(u8"{0:n}", static_cast<value_t>(1234567)));
    }
    
    void test_method_(format_with_number_argument_and_one_digit_precision) {
      if (std::is_same<value_t, unsigned char>::value || std::is_same<value_t, sbyte>::value || std::is_same<value_t, xtd::byte>::value)
        assert::are_equal(u8"123.0000", format(u8"{0:N4}", static_cast<value_t>(123)));
      else if (std::is_same<value_t, short>::value || std::is_same<value_t, unsigned short>::value)
        assert::are_equal(u8"1,234.0000", format(u8"{0:N4}", static_cast<value_t>(1234)));
      else
        assert::are_equal(u8"1,234,567.0000", format(u8"{0:N4}", static_cast<value_t>(1234567)));
    }
    
    void test_method_(format_with_number_argument_and_two_digits_precision) {
      if (std::is_same<value_t, unsigned char>::value || std::is_same<value_t, sbyte>::value || std::is_same<value_t, xtd::byte>::value)
        assert::are_equal(u8"123.0000000000", format(u8"{0:N10}", static_cast<value_t>(123)));
      else if (std::is_same<value_t, short>::value || std::is_same<value_t, unsigned short>::value)
        assert::are_equal(u8"1,234.0000000000", format(u8"{0:N10}", static_cast<value_t>(1234)));
      else
        assert::are_equal(u8"1,234,567.0000000000", format(u8"{0:N10}", static_cast<value_t>(1234567)));
    }
    
    void test_method_(format_with_number_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:N100}", static_cast<value_t>(123));});
    }
    
    void test_method_(format_with_number_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:N-4}", static_cast<value_t>(123));});
    }
    
    void test_method_(format_with_number_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:Na}", static_cast<value_t>(123));});
    }
    
    void test_method_(format_with_octal_argument) {
      assert::are_equal(u8"52", format(u8"{0:o}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_octal_argument_and_one_digit_precision) {
      assert::are_equal(u8"00052", format(u8"{0:O5}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_octal_argument_and_two_digits_precision) {
      assert::are_equal(u8"0000000052", format(u8"{0:O10}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_octal_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:O100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_octal_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:O-5}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_octal_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:Oa}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_percent_argument) {
      assert::are_equal(u8"100.00 %", format(u8"{0:p}", static_cast<value_t>(1)));
    }
    
    void test_method_(format_with_percent_argument_and_one_digit_precision) {
      assert::are_equal(u8"600.0000 %", format(u8"{0:P4}", static_cast<value_t>(6)));
    }
    
    void test_method_(format_with_percent_argument_and_two_digits_precision) {
      assert::are_equal(u8"600.0000000000 %", format(u8"{0:P10}", static_cast<value_t>(6)));
    }
    
    void test_method_(format_with_percent_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:P100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_percent_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:P-4}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_percent_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:Pa}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_hexadecimal_argument) {
      assert::are_equal(u8"2a", format(u8"{0:x}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_hexadecimal_argument_and_one_digit_precision) {
      assert::are_equal(u8"002A", format(u8"{0:X4}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_hexadecimal_argument_and_two_digits_precision) {
      assert::are_equal(u8"000000002A", format(u8"{0:X10}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_hexadecimal_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:X100}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_hexadecimal_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:X-4}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_hexadecimal_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:Xa}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_alignment_before_format) {
      assert::are_equal(u8"    42", format(u8"{0,6:D}", static_cast<value_t>(42)));
    }
    
    void test_method_(format_with_alignment_after_format) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:D,6}", static_cast<value_t>(42));});
    }
    
    void test_method_(format_with_invalid_format) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:V}", static_cast<value_t>(42));});
    }
  };
#endif
}
