#include <xtd/format>
#include <xtd/format_exception>
#include <xtd/globalization/culture_info>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  template<class value_t>
  class format_wstring_numeric_tests;
  
  test_class_attribute<format_wstring_numeric_tests<unsigned char>> format_wstring_numeric_tests_class_unsigned_char_attr {"format_wstring_numeric_tests<unsigned_char>"};
  test_class_attribute<format_wstring_numeric_tests<short>> format_wstring_numeric_tests_class_short_attr {"format_wstring_numeric_tests<short>"};
  test_class_attribute<format_wstring_numeric_tests<unsigned short>> format_wstring_numeric_tests_class_unsigned_short_attr {"format_wstring_numeric_tests<unsigned_short>"};
  test_class_attribute<format_wstring_numeric_tests<int>> format_wstring_numeric_tests_class_int_attr {"format_wstring_numeric_tests<int>"};
  test_class_attribute<format_wstring_numeric_tests<unsigned int>> format_wstring_numeric_tests_class_unsigned_int_attr {"format_wstring_numeric_tests<unsigned_int>"};
  test_class_attribute<format_wstring_numeric_tests<long>> format_wstring_numeric_tests_class_long_attr {"format_wstring_numeric_tests<long>"};
  test_class_attribute<format_wstring_numeric_tests<unsigned long>> format_wstring_numeric_tests_class_unsigned_long_attr {"format_wstring_numeric_tests<unsigned_long>"};
  test_class_attribute<format_wstring_numeric_tests<long long>> format_wstring_numeric_tests_class_long_long_attr {"format_wstring_numeric_tests<long_long>"};
  test_class_attribute<format_wstring_numeric_tests<unsigned long long>> format_wstring_numeric_tests_class_unsigned_long_long_attr {"format_wstring_numeric_tests<unsigned_long_long>"};
  test_class_attribute<format_wstring_numeric_tests<sbyte>> format_wstring_numeric_tests_class_sbyte_attr {"format_wstring_numeric_tests<sbyte>"};
  test_class_attribute<format_wstring_numeric_tests<int16>> format_wstring_numeric_tests_class_int16_attr {"format_wstring_numeric_tests<int16>"};
  test_class_attribute<format_wstring_numeric_tests<int32>> format_wstring_numeric_tests_class_int32_attr {"format_wstring_numeric_tests<int32>"};
  test_class_attribute<format_wstring_numeric_tests<int64>> format_wstring_numeric_tests_class_int64_attr {"format_wstring_numeric_tests<int64>"};
  test_class_attribute<format_wstring_numeric_tests<intptr>> format_wstring_numeric_tests_class_intptr_attr {"format_wstring_numeric_tests<intptr>"};
  test_class_attribute<format_wstring_numeric_tests<ptrdiff_t>> format_wstring_numeric_tests_class_ptrdiff_t_attr {"format_wstring_numeric_tests<ptrdiff_t>"};
  test_class_attribute<format_wstring_numeric_tests<size_t>> format_wstring_numeric_tests_class_size_t_attr {"format_wstring_numeric_tests<size_t>"};
  test_class_attribute<format_wstring_numeric_tests<xtd::byte>> format_wstring_numeric_tests_class_byte_attr {"format_wstring_numeric_tests<xtd::byte>"};
  test_class_attribute<format_wstring_numeric_tests<uint16>> format_wstring_numeric_tests_class_uint16_attr {"format_wstring_numeric_tests<uint16>"};
  test_class_attribute<format_wstring_numeric_tests<uint32>> format_wstring_numeric_tests_class_uint32_attr {"format_wstring_numeric_tests<uint32>"};
  test_class_attribute<format_wstring_numeric_tests<uint64>> format_wstring_numeric_tests_class_uint64_attr {"format_wstring_numeric_tests<uint64>"};
  test_class_attribute<format_wstring_numeric_tests<uintptr>> format_wstring_numeric_tests_class_uintptr_attr {"format_wstring_numeric_tests<uintptr>"};
  
  template<class value_t>
  class format_wstring_numeric_tests : public test_class {
    inline static xtd::globalization::culture_info previous_culture;
    
    static void class_initialize_(class_initialize) {
      previous_culture = xtd::globalization::culture_info::current_culture();
      xtd::globalization::culture_info::current_culture(xtd::globalization::culture_info {"en-US"});
    }
    
    static void class_cleanup_(class_cleanup) {
      xtd::globalization::culture_info::current_culture(previous_culture);
    }
    
    auto test_method_(format_with_default_argument) {
      assert::are_equal(L"42", format(L"{0}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_without_format_argument_separator) {
      assert::throws<format_exception>([] {format(L"{0D}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_left_alignment) {
      assert::are_equal(L"  42", format(L"{0,4}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_left_alignment_with_plus) {
      assert::are_equal(L"  42", format(L"{0,+4}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_left_alignment_to_zero) {
      assert::are_equal(L"42", format(L"{0,0}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_right_alignment) {
      assert::are_equal(L"42  ", format(L"{0,-4}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_right_alignment_to_zero) {
      assert::are_equal(L"42", format(L"{0,-0}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_alignment_empty) {
      assert::are_equal(L"42", format(L"{0,}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_alignment_invalid) {
      assert::throws<format_exception>([] {format(L"{0,a}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_binary_argument) {
      assert::are_equal(L"101010", format(L"{0:b}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_binary_argument_and_one_digit_precision) {
      assert::are_equal(L"00101010", format(L"{0:B8}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_binary_argument_and_two_digits_precision) {
      assert::are_equal(L"0000101010", format(L"{0:B10}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_binary_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:B100}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_binary_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:B-3}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_binary_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:Ba}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_currency_argument) {
      assert::are_equal(L"$42.00", format(L"{0:c}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_currency_argument_and_one_digit_precision) {
      assert::are_not_equal("$42.00000", format(L"{0:C5}", static_cast<value_t>(42)), "The precision of currency format  is ignored");
      assert::are_equal(L"$42.00", format(L"{0:C5}", static_cast<value_t>(42)), "The precision of currency format is ignored");
    }
    
    auto test_method_(format_with_currency_argument_and_two_digits_precision) {
      assert::are_not_equal("$42.00000", format(L"{0:C10}", static_cast<value_t>(42)), "The precision of currency format  is ignored");
      assert::are_equal(L"$42.00", format(L"{0:C10}", static_cast<value_t>(42)), "The precision of currency format is ignored");
    }
    
    auto test_method_(format_with_currency_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:C100}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_currency_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:C-5}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_currency_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:Ca}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_decimal_argument) {
      assert::are_equal(L"42", format(L"{0:d}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_decimal_argument_and_one_digit_precision) {
      assert::are_equal(L"00042", format(L"{0:D5}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_decimal_argument_and_two_digits_precision) {
      assert::are_equal(L"0000000042", format(L"{0:D10}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_decimal_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:D100}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_decimal_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:D-5}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_decimal_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:Da}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_negative_with_decimal_argument_and_one_digit_precision) {
      if (std::is_signed<value_t>::value)
        assert::are_equal(L"-000123", format(L"{0:D6}", static_cast<value_t>(-123)));
    }
    
    auto test_method_(format_negative_with_decimal_argument_and_two_digits_precision) {
      if (std::is_signed<value_t>::value)
        assert::are_equal(L"-0000000123", format(L"{0:D10}", static_cast<value_t>(-123)));
    }
    
    auto test_method_(format_negative_with_decimal_argument_and_three_digits_precision) {
      if (std::is_signed<value_t>::value)
        assert::throws<xtd::format_exception>([] {format(L"{0:D100}", static_cast<value_t>(-123));});
    }
    
    auto test_method_(format_negative_with_decimal_argument_and_negative_precision) {
      if (std::is_signed<value_t>::value)
        assert::throws<xtd::format_exception>([] {format(L"{0:D-6}", static_cast<value_t>(-123));});
    }
    
    auto test_method_(format_with_exponencial_argument) {
      assert::are_equal(L"4.200000e+01", format(L"{0:e}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_exponencial_argument_and_one_digit_precision) {
      assert::are_equal(L"4.20000000E+01", format(L"{0:E8}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_exponencial_argument_and_two_digits_precision) {
      assert::are_equal(L"4.2000000000E+01", format(L"{0:E10}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_exponencial_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:E100}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_exponencial_argument_and_nagetive_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:E-10}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_exponencial_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:Ea}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_fixed_point_argument) {
      assert::are_equal(L"42.00", format(L"{0:f}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_fixed_point_argument_and_one_digit_precision) {
      assert::are_equal(L"42.0000", format(L"{0:F4}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_fixed_point_argument_and_two_digits_precision) {
      assert::are_equal(L"42.0000000000", format(L"{0:F10}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_fixed_point_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:F100}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_fixed_point_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:F-4}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_fixed_point_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:Fa}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_general_argument) {
      assert::are_equal(L"42", format(L"{0:g}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_general_argument_and_one_digit_precision) {
      assert::are_equal(L"42", format(L"{0:G2}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_general_argument_and_two_digits_precision) {
      assert::are_equal(L"42", format(L"{0:G10}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_general_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:G100}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_general_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:G-2}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_general_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:Ga}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_number_argument) {
      if (std::is_same<value_t, unsigned char>::value || std::is_same<value_t, sbyte>::value || std::is_same<value_t, xtd::byte>::value)
        assert::are_equal(L"123.00", format(L"{0:n}", static_cast<value_t>(123)));
      else if (std::is_same<value_t, short>::value || std::is_same<value_t, unsigned short>::value)
        assert::are_equal(L"1,234.00", format(L"{0:n}", static_cast<value_t>(1234)));
      else
        assert::are_equal(L"1,234,567.00", format(L"{0:n}", static_cast<value_t>(1234567)));
    }
    
    auto test_method_(format_with_number_argument_and_one_digit_precision) {
      if (std::is_same<value_t, unsigned char>::value || std::is_same<value_t, sbyte>::value || std::is_same<value_t, xtd::byte>::value)
        assert::are_equal(L"123.0000", format(L"{0:N4}", static_cast<value_t>(123)));
      else if (std::is_same<value_t, short>::value || std::is_same<value_t, unsigned short>::value)
        assert::are_equal(L"1,234.0000", format(L"{0:N4}", static_cast<value_t>(1234)));
      else
        assert::are_equal(L"1,234,567.0000", format(L"{0:N4}", static_cast<value_t>(1234567)));
    }
    
    auto test_method_(format_with_number_argument_and_two_digits_precision) {
      if (std::is_same<value_t, unsigned char>::value || std::is_same<value_t, sbyte>::value || std::is_same<value_t, xtd::byte>::value)
        assert::are_equal(L"123.0000000000", format(L"{0:N10}", static_cast<value_t>(123)));
      else if (std::is_same<value_t, short>::value || std::is_same<value_t, unsigned short>::value)
        assert::are_equal(L"1,234.0000000000", format(L"{0:N10}", static_cast<value_t>(1234)));
      else
        assert::are_equal(L"1,234,567.0000000000", format(L"{0:N10}", static_cast<value_t>(1234567)));
    }
    
    auto test_method_(format_with_number_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:N100}", static_cast<value_t>(123));});
    }
    
    auto test_method_(format_with_number_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:N-4}", static_cast<value_t>(123));});
    }
    
    auto test_method_(format_with_number_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:Na}", static_cast<value_t>(123));});
    }
    
    auto test_method_(format_with_octal_argument) {
      assert::are_equal(L"52", format(L"{0:o}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_octal_argument_and_one_digit_precision) {
      assert::are_equal(L"00052", format(L"{0:O5}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_octal_argument_and_two_digits_precision) {
      assert::are_equal(L"0000000052", format(L"{0:O10}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_octal_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:O100}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_octal_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:O-5}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_octal_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:Oa}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_percent_argument) {
      assert::are_equal(L"100.00 %", format(L"{0:p}", static_cast<value_t>(1)));
    }
    
    auto test_method_(format_with_percent_argument_and_one_digit_precision) {
      assert::are_equal(L"600.0000 %", format(L"{0:P4}", static_cast<value_t>(6)));
    }
    
    auto test_method_(format_with_percent_argument_and_two_digits_precision) {
      assert::are_equal(L"600.0000000000 %", format(L"{0:P10}", static_cast<value_t>(6)));
    }
    
    auto test_method_(format_with_percent_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:P100}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_percent_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:P-4}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_percent_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:Pa}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_hexadecimal_argument) {
      assert::are_equal(L"2a", format(L"{0:x}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_hexadecimal_argument_and_one_digit_precision) {
      assert::are_equal(L"002A", format(L"{0:X4}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_hexadecimal_argument_and_two_digits_precision) {
      assert::are_equal(L"000000002A", format(L"{0:X10}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_hexadecimal_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:X100}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_hexadecimal_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:X-4}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_hexadecimal_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(L"{0:Xa}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_alignment_before_format) {
      assert::are_equal(L"    42", format(L"{0,6:D}", static_cast<value_t>(42)));
    }
    
    auto test_method_(format_with_alignment_after_format) {
      assert::throws<xtd::format_exception>([] {format(L"{0:D,6}", static_cast<value_t>(42));});
    }
    
    auto test_method_(format_with_invalid_format) {
      assert::throws<xtd::format_exception>([] {format(L"{0:V}", static_cast<value_t>(42));});
    }
  };
}
