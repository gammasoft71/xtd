#include <xtd/ustring.h>
#include <xtd/format_exception.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  template <typename Value>
  class test_wstring_numeric_format;
  
  test_class_attribute<test_wstring_numeric_format<char>> test_wstring_numeric_format_class_char_attr {"test_wstring_numeric_format<char>"};
  test_class_attribute<test_wstring_numeric_format<unsigned char>> test_wstring_numeric_format_class_unsigned_char_attr {"test_wstring_numeric_format<unsigned char>"};
  test_class_attribute<test_wstring_numeric_format<short>> test_wstring_numeric_format_class_short_attr {"test_wstring_numeric_format<short>"};
  test_class_attribute<test_wstring_numeric_format<unsigned short>> test_wstring_numeric_format_class_unsigned_short_attr {"test_wstring_numeric_format<unsigned short>"};
  test_class_attribute<test_wstring_numeric_format<int>> test_wstring_numeric_format_class_int_attr {"test_wstring_numeric_format<int>"};
  test_class_attribute<test_wstring_numeric_format<unsigned int>> test_wstring_numeric_format_class_unsigned_int_attr {"test_wstring_numeric_format<unsigned int>"};
  test_class_attribute<test_wstring_numeric_format<long>> test_wstring_numeric_format_class_long_attr {"test_wstring_numeric_format<long>"};
  test_class_attribute<test_wstring_numeric_format<unsigned long>> test_wstring_numeric_format_class_unsigned_long_attr {"test_wstring_numeric_format<unsigned long>"};
  test_class_attribute<test_wstring_numeric_format<long long>> test_wstring_numeric_format_class_long_long_attr {"test_wstring_numeric_format<long long>"};
  test_class_attribute<test_wstring_numeric_format<unsigned long long>> test_wstring_numeric_format_class_unsigned_long_long_attr {"test_wstring_numeric_format<unsigned long long>"};
  test_class_attribute<test_wstring_numeric_format<int8_t>> test_wstring_numeric_format_class_int8_t_attr {"test_wstring_numeric_format<int8_t>"};
  test_class_attribute<test_wstring_numeric_format<int16_t>> test_wstring_numeric_format_class_int16_t_attr {"test_wstring_numeric_format<int16_t>"};
  test_class_attribute<test_wstring_numeric_format<int32_t>> test_wstring_numeric_format_class_int32_t_attr {"test_wstring_numeric_format<int32_t>"};
  test_class_attribute<test_wstring_numeric_format<int64_t>> test_wstring_numeric_format_class_int64_t_attr {"test_wstring_numeric_format<int64_t>"};
  test_class_attribute<test_wstring_numeric_format<intptr_t>> test_wstring_numeric_format_class_intptr_t_attr {"test_wstring_numeric_format<intptr_t>"};
  test_class_attribute<test_wstring_numeric_format<ptrdiff_t>> test_wstring_numeric_format_class_ptrdiff_t_attr {"test_wstring_numeric_format<ptrdiff_t>"};
  test_class_attribute<test_wstring_numeric_format<size_t>> test_wstring_numeric_format_class_size_t_attr {"test_wstring_numeric_format<size_t>"};
  test_class_attribute<test_wstring_numeric_format<uint8_t>> test_wstring_numeric_format_class_uint8_t_attr {"test_wstring_numeric_format<uint8_t>"};
  test_class_attribute<test_wstring_numeric_format<uint16_t>> test_wstring_numeric_format_class_uint16_t_attr {"test_wstring_numeric_format<uint16_t>"};
  test_class_attribute<test_wstring_numeric_format<uint32_t>> test_wstring_numeric_format_class_uint32_t_attr {"test_wstring_numeric_format<uint32_t>"};
  test_class_attribute<test_wstring_numeric_format<uint64_t>> test_wstring_numeric_format_class_uint64_t_attr {"test_wstring_numeric_format<uint64_t>"};
  test_class_attribute<test_wstring_numeric_format<uintptr_t>> test_wstring_numeric_format_class_uintptr_t_attr {"test_wstring_numeric_format<uintptr_t>"};

  template<typename Value>
  class test_wstring_numeric_format : public test_class {
  public:
    static void class_initialize_(class_initialize) {
      std::locale::global(std::locale("en_US.UTF-8"));
    }
    
    void test_method_(format_with_default_argument) {
      if (std::is_same<Value, char>::value)
        assert::are_equal(L"*", ustring::format(L"{0}", static_cast<Value>(42)), csf_);
      else
        assert::are_equal(L"42", ustring::format(L"{0}", static_cast<Value>(42)), csf_);
    }

    void test_method_(format_without_format_argument_separator) {
      assert::throws<format_exception>([]{ustring::format(L"{0D}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_left_alignment) {
      if (std::is_same<Value, char>::value)
        assert::are_equal(L"   *", ustring::format(L"{0,4}", static_cast<Value>(42)), csf_);
      else
        assert::are_equal(L"  42", ustring::format(L"{0,4}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_left_alignment_with_plus) {
      if (std::is_same<Value, char>::value)
        assert::are_equal(L"   *", ustring::format(L"{0,+4}", static_cast<Value>(42)), csf_);
      else
        assert::are_equal(L"  42", ustring::format(L"{0,+4}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_left_alignment_to_zero) {
      if (std::is_same<Value, char>::value)
        assert::are_equal(L"*", ustring::format(L"{0,0}", static_cast<Value>(42)), csf_);
      else
        assert::are_equal(L"42", ustring::format(L"{0,0}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_right_alignment) {
      if (std::is_same<Value, char>::value)
        assert::are_equal(L"*   ", ustring::format(L"{0,-4}", static_cast<Value>(42)), csf_);
      else
        assert::are_equal(L"42  ", ustring::format(L"{0,-4}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_right_alignment_to_zero) {
      if (std::is_same<Value, char>::value)
        assert::are_equal(L"*", ustring::format(L"{0,-0}", static_cast<Value>(42)), csf_);
      else
        assert::are_equal(L"42", ustring::format(L"{0,-0}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_alignment_empty) {
      if (std::is_same<Value, char>::value)
        assert::are_equal(L"*", ustring::format(L"{0,}", static_cast<Value>(42)), csf_);
      else
        assert::are_equal(L"42", ustring::format(L"{0,}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_alignment_invalid) {
      assert::throws<format_exception>([]{ustring::format(L"{0,a}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_binary_argument) {
      assert::are_equal(L"101010", ustring::format(L"{0:b}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_binary_argument_and_one_digit_precision) {
      assert::are_equal(L"00101010", ustring::format(L"{0:B8}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_binary_argument_and_two_digits_precision) {
      assert::are_equal(L"0000101010", ustring::format(L"{0:B10}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_binary_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:B100}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_binary_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:B-3}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_binary_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:Ba}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_currency_argument) {
      assert::are_equal(L"$42.00", ustring::format(L"{0:c}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_currency_argument_and_one_digit_precision) {
      assert::are_not_equal(L"$42.00000", ustring::format(L"{0:C5}", static_cast<Value>(42)), "The precision of currency format  is ignored", csf_);
      assert::are_equal(L"$42.00", ustring::format(L"{0:C5}", static_cast<Value>(42)), "The precision of currency format is ignored", csf_);
    }
    
    void test_method_(format_with_currency_argument_and_two_digits_precision) {
      assert::are_not_equal(L"$42.00000", ustring::format(L"{0:C10}", static_cast<Value>(42)), "The precision of currency format  is ignored", csf_);
      assert::are_equal(L"$42.00", ustring::format(L"{0:C10}", static_cast<Value>(42)), "The precision of currency format is ignored", csf_);
    }

    void test_method_(format_with_currency_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:C100}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_currency_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:C-5}", static_cast<Value>(42));}, csf_);
    }
  
    void test_method_(format_with_currency_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:Ca}", static_cast<Value>(42));}, csf_);
    }

    void test_method_(format_with_decimal_argument) {
      assert::are_equal(L"42", ustring::format(L"{0:d}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_decimal_argument_and_one_digit_precision) {
      assert::are_equal(L"00042", ustring::format(L"{0:D5}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_decimal_argument_and_two_digits_precision) {
      assert::are_equal(L"0000000042", ustring::format(L"{0:D10}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_decimal_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:D100}", static_cast<Value>(42));}, csf_);
    }

    void test_method_(format_with_decimal_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:D-5}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_decimal_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:Da}", static_cast<Value>(42));}, csf_);
    }

    void test_method_(format_negative_with_decimal_argument_and_one_digit_precision) {
      if(std::is_signed<Value>::value)
        assert::are_equal(L"-000123", ustring::format(L"{0:D6}", static_cast<Value>(-123)), csf_);
    }
    
    void test_method_(format_negative_with_decimal_argument_and_two_digits_precision) {
      if (std::is_signed<Value>::value)
        assert::are_equal(L"-0000000123", ustring::format(L"{0:D10}", static_cast<Value>(-123)), csf_);
    }
    
    void test_method_(format_negative_with_decimal_argument_and_three_digits_precision) {
      if (std::is_signed<Value>::value)
        assert::throws<xtd::format_exception>([]{ustring::format(L"{0:D100}", static_cast<Value>(-123));}, csf_);
    }
    
    void test_method_(format_negative_with_decimal_argument_and_negative_precision) {
      if (std::is_signed<Value>::value)
        assert::throws<xtd::format_exception>([]{ustring::format(L"{0:D-6}", static_cast<Value>(-123));}, csf_);
    }
    
    void test_method_(format_with_exponencial_argument) {
      assert::are_equal(L"4.200000e+01", ustring::format(L"{0:e}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_exponencial_argument_and_one_digit_precision) {
      assert::are_equal(L"4.20000000E+01", ustring::format(L"{0:E8}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_exponencial_argument_and_two_digits_precision) {
      assert::are_equal(L"4.2000000000E+01", ustring::format(L"{0:E10}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_exponencial_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:E100}", static_cast<Value>(42));}, csf_);
    }

    void test_method_(format_with_exponencial_argument_and_nagetive_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:E-10}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_exponencial_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:Ea}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_fixed_point_argument) {
      assert::are_equal(L"42.00", ustring::format(L"{0:f}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_fixed_point_argument_and_one_digit_precision) {
      assert::are_equal(L"42.0000", ustring::format(L"{0:F4}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_fixed_point_argument_and_two_digits_precision) {
      assert::are_equal(L"42.0000000000", ustring::format(L"{0:F10}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_fixed_point_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:F100}", static_cast<Value>(42));}, csf_);
    }

    void test_method_(format_with_fixed_point_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:F-4}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_fixed_point_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:Fa}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_general_argument) {
      assert::are_equal(L"42", ustring::format(L"{0:g}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_general_argument_and_one_digit_precision) {
      assert::are_equal(L"42", ustring::format(L"{0:G2}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_general_argument_and_two_digits_precision) {
      assert::are_equal(L"42", ustring::format(L"{0:G10}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_general_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:G100}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_general_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:G-2}", static_cast<Value>(42));}, csf_);
    }

    void test_method_(format_with_general_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:Ga}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_number_argument) {
      if (std::is_same<Value, char>::value || std::is_same<Value, unsigned char>::value || std::is_same<Value, int8_t>::value || std::is_same<Value, uint8_t>::value)
        assert::are_equal(L"123.00", ustring::format(L"{0:n}", static_cast<Value>(123)), csf_);
      else if (std::is_same<Value, short>::value || std::is_same<Value, unsigned short>::value)
        assert::are_equal(L"1,234.00", ustring::format(L"{0:n}", static_cast<Value>(1234)), csf_);
      else
        assert::are_equal(L"1,234,567.00", ustring::format(L"{0:n}", static_cast<Value>(1234567)), csf_);
    }
    
    void test_method_(format_with_number_argument_and_one_digit_precision) {
      if (std::is_same<Value, char>::value || std::is_same<Value, unsigned char>::value || std::is_same<Value, int8_t>::value || std::is_same<Value, uint8_t>::value)
        assert::are_equal(L"123.0000", ustring::format(L"{0:N4}", static_cast<Value>(123)), csf_);
      else if (std::is_same<Value, short>::value || std::is_same<Value, unsigned short>::value)
        assert::are_equal(L"1,234.0000", ustring::format(L"{0:N4}", static_cast<Value>(1234)), csf_);
      else
        assert::are_equal(L"1,234,567.0000", ustring::format(L"{0:N4}", static_cast<Value>(1234567)), csf_);
    }
    
    void test_method_(format_with_number_argument_and_two_digits_precision) {
      if (std::is_same<Value, char>::value || std::is_same<Value, unsigned char>::value || std::is_same<Value, int8_t>::value || std::is_same<Value, uint8_t>::value)
        assert::are_equal(L"123.0000000000", ustring::format(L"{0:N10}", static_cast<Value>(123)), csf_);
      else if (std::is_same<Value, short>::value || std::is_same<Value, unsigned short>::value)
        assert::are_equal(L"1,234.0000000000", ustring::format(L"{0:N10}", static_cast<Value>(1234)), csf_);
      else
        assert::are_equal(L"1,234,567.0000000000", ustring::format(L"{0:N10}", static_cast<Value>(1234567)), csf_);
    }
    
    void test_method_(format_with_number_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:N100}", static_cast<Value>(123));}, csf_);
    }

    void test_method_(format_with_number_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:N-4}", static_cast<Value>(123));}, csf_);
    }

    void test_method_(format_with_number_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:Na}", static_cast<Value>(123));}, csf_);
    }
    
    void test_method_(format_with_octal_argument) {
      assert::are_equal(L"52", ustring::format(L"{0:o}", static_cast<Value>(42)));
    }
    
    void test_method_(format_with_octal_argument_and_one_digit_precision) {
      assert::are_equal(L"00052", ustring::format(L"{0:O5}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_octal_argument_and_two_digits_precision) {
      assert::are_equal(L"0000000052", ustring::format(L"{0:O10}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_octal_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:O100}", static_cast<Value>(42));}, csf_);
    }

    void test_method_(format_with_octal_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:O-5}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_octal_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:Oa}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_percent_argument) {
      assert::are_equal(L"100.00 %", ustring::format(L"{0:p}", static_cast<Value>(1)), csf_);
    }
    
    void test_method_(format_with_percent_argument_and_one_digit_precision) {
      assert::are_equal(L"600.0000 %", ustring::format(L"{0:P4}", static_cast<Value>(6)), csf_);
    }
    
    void test_method_(format_with_percent_argument_and_two_digits_precision) {
      assert::are_equal(L"600.0000000000 %", ustring::format(L"{0:P10}", static_cast<Value>(6)), csf_);
    }
    
    void test_method_(format_with_percent_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:P100}", static_cast<Value>(42));}, csf_);
    }

    void test_method_(format_with_percent_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:P-4}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_percent_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:Pa}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_hexadecimal_argument) {
      assert::are_equal(L"2a", ustring::format(L"{0:x}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_hexadecimal_argument_and_one_digit_precision) {
      assert::are_equal(L"002A", ustring::format(L"{0:X4}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_hexadecimal_argument_and_two_digits_precision) {
      assert::are_equal(L"000000002A", ustring::format(L"{0:X10}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_hexadecimal_argument_and_three_digits_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:X100}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_hexadecimal_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:X-4}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_hexadecimal_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:Xa}", static_cast<Value>(42));}, csf_);
    }
    
    void test_method_(format_with_alignment_before_format) {
      assert::are_equal(L"    42", ustring::format(L"{0,6:D}", static_cast<Value>(42)), csf_);
    }
    
    void test_method_(format_with_alignment_after_format) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:D,6}", static_cast<Value>(42));}, csf_);
    }

    void test_method_(format_with_invalid_format) {
      assert::throws<xtd::format_exception>([]{ustring::format(L"{0:V}", static_cast<Value>(42));}, csf_);
    }
  };
}
