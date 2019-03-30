#include <xtd/strings>
#include <xtd/tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  template <typename Value>
  class test_string_numeric_format;
  
  test_class_attribute<test_string_numeric_format<char>> test_string_numeric_format_class_char_attr {"test_string_numeric_format<char>"};
  test_class_attribute<test_string_numeric_format<unsigned char>> test_string_numeric_format_class_unsigned_char_attr {"test_string_numeric_format<unsigned char>"};
  test_class_attribute<test_string_numeric_format<short>> test_string_numeric_format_class_short_attr {"test_string_numeric_format<short>"};
  test_class_attribute<test_string_numeric_format<unsigned short>> test_string_numeric_format_class_unsigned_short_attr {"test_string_numeric_format<unsigned short>"};
  test_class_attribute<test_string_numeric_format<int>> test_string_numeric_format_class_int_attr {"test_string_numeric_format<int>"};
  test_class_attribute<test_string_numeric_format<unsigned int>> test_string_numeric_format_class_unsigned_int_attr {"test_string_numeric_format<unsigned int>"};
  test_class_attribute<test_string_numeric_format<long>> test_string_numeric_format_class_long_attr {"test_string_numeric_format<long>"};
  test_class_attribute<test_string_numeric_format<unsigned long>> test_string_numeric_format_class_unsigned_long_attr {"test_string_numeric_format<unsigned long>"};
  test_class_attribute<test_string_numeric_format<long long>> test_string_numeric_format_class_long_long_attr {"test_string_numeric_format<long long>"};
  test_class_attribute<test_string_numeric_format<unsigned long long>> test_string_numeric_format_class_unsigned_long_long_attr {"test_string_numeric_format<unsigned long long>"};
  test_class_attribute<test_string_numeric_format<int8_t>> test_string_numeric_format_class_int8_t_attr {"test_string_numeric_format<int8_t>"};
  test_class_attribute<test_string_numeric_format<int16_t>> test_string_numeric_format_class_int16_t_attr {"test_string_numeric_format<int16_t>"};
  test_class_attribute<test_string_numeric_format<int32_t>> test_string_numeric_format_class_int32_t_attr {"test_string_numeric_format<int32_t>"};
  test_class_attribute<test_string_numeric_format<int64_t>> test_string_numeric_format_class_int64_t_attr {"test_string_numeric_format<int64_t>"};
  test_class_attribute<test_string_numeric_format<intptr_t>> test_string_numeric_format_class_intptr_t_attr {"test_string_numeric_format<intptr_t>"};
  test_class_attribute<test_string_numeric_format<ptrdiff_t>> test_string_numeric_format_class_ptrdiff_t_attr {"test_string_numeric_format<ptrdiff_t>"};
  test_class_attribute<test_string_numeric_format<size_t>> test_string_numeric_format_class_size_t_attr {"test_string_numeric_format<size_t>"};
  test_class_attribute<test_string_numeric_format<uint8_t>> test_string_numeric_format_class_uint8_t_attr {"test_string_numeric_format<uint8_t>"};
  test_class_attribute<test_string_numeric_format<uint16_t>> test_string_numeric_format_class_uint16_t_attr {"test_string_numeric_format<uint16_t>"};
  test_class_attribute<test_string_numeric_format<uint32_t>> test_string_numeric_format_class_uint32_t_attr {"test_string_numeric_format<uint32_t>"};
  test_class_attribute<test_string_numeric_format<uint64_t>> test_string_numeric_format_class_uint64_t_attr {"test_string_numeric_format<uint64_t>"};
  test_class_attribute<test_string_numeric_format<uintptr_t>> test_string_numeric_format_class_uintptr_t_attr {"test_string_numeric_format<uintptr_t>"};

  template<typename Value>
  class test_string_numeric_format : public test_class {
  private:
    template<typename V>
    static V to_value(V value) {return value;}
    
  public:
    void test_method_(format_with_default_argument) {
      if (std::is_same<Value, char>::value || std::is_same<Value, unsigned char>::value || std::is_same<Value, int8_t>::value || std::is_same<Value, uint8_t>::value)
        assert::are_equal("*", strings::format("{0}", to_value<Value>(42)));
      else
        assert::are_equal("42", strings::format("{0}", to_value<Value>(42)));
    }

    void test_method_(format_without_format_argument_separator) {
      assert::throws<std::invalid_argument>([]{strings::format("{0D}", to_value<Value>(42));});
    }
    
    void test_method_(format_with_left_alignment) {
      if (std::is_same<Value, char>::value || std::is_same<Value, unsigned char>::value || std::is_same<Value, int8_t>::value || std::is_same<Value, uint8_t>::value)
        assert::are_equal("   *", strings::format("{0,4}", to_value<Value>(42)));
      else
        assert::are_equal("  42", strings::format("{0,4}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_left_alignment_with_plus) {
      if (std::is_same<Value, char>::value || std::is_same<Value, unsigned char>::value || std::is_same<Value, int8_t>::value || std::is_same<Value, uint8_t>::value)
        assert::are_equal("   *", strings::format("{0,+4}", to_value<Value>(42)));
      else
        assert::are_equal("  42", strings::format("{0,+4}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_left_alignment_to_zero) {
      if (std::is_same<Value, char>::value || std::is_same<Value, unsigned char>::value || std::is_same<Value, int8_t>::value || std::is_same<Value, uint8_t>::value)
        assert::are_equal("*", strings::format("{0,0}", to_value<Value>(42)));
      else
        assert::are_equal("42", strings::format("{0,0}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_right_alignment) {
      if (std::is_same<Value, char>::value || std::is_same<Value, unsigned char>::value || std::is_same<Value, int8_t>::value || std::is_same<Value, uint8_t>::value)
        assert::are_equal("*   ", strings::format("{0,-4}", to_value<Value>(42)));
      else
        assert::are_equal("42  ", strings::format("{0,-4}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_right_alignment_to_zero) {
      if (std::is_same<Value, char>::value || std::is_same<Value, unsigned char>::value || std::is_same<Value, int8_t>::value || std::is_same<Value, uint8_t>::value)
        assert::are_equal("*", strings::format("{0,-0}", to_value<Value>(42)));
      else
        assert::are_equal("42", strings::format("{0,-0}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_alignment_empty) {
      if (std::is_same<Value, char>::value || std::is_same<Value, unsigned char>::value || std::is_same<Value, int8_t>::value || std::is_same<Value, uint8_t>::value)
        assert::are_equal("*", strings::format("{0,}", to_value<Value>(42)));
      else
        assert::are_equal("42", strings::format("{0,}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_alignment_invalid) {
      assert::throws<std::invalid_argument>([]{strings::format("{0,a}", to_value<Value>(42));});
    }
    
    void test_method_(format_with_binary_argument) {
      assert::are_equal("101010", strings::format("{0:b}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_binary_argument_and_precision) {
      assert::are_equal("00101010", strings::format("{0:B8}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_binary_argument_and_negative_precision) {
      assert::are_equal("101010  ", strings::format("{0:B-8}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_binary_argument_and_positive_precision) {
      assert::are_equal("00101010", strings::format("{0:B+8}", to_value<Value>(42)));
    }

    void test_method_(format_with_binary_argument_and_invalid_precision) {
      assert::throws<std::invalid_argument>([]{strings::format("{0:Ba}", to_value<Value>(42));});
    }
    
    void test_method_(format_with_currency_argument) {
      assert::are_equal("$42.00", strings::format("{0:c}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_currency_argument_and_precision) {
      assert::are_not_equal("$42.00000", strings::format("{0:C5}", to_value<Value>(42)), "The precision of currency format  is ignored");
      assert::are_equal("$42.00", strings::format("{0:C5}", to_value<Value>(42)), "The precision of currency format is ignored");
    }
    
    void test_method_(format_with_currency_argument_and_positive_precision) {
      assert::are_not_equal("$42.00000", strings::format("{0:C+5}", to_value<Value>(42)), "The precision of currency format  is ignored");
      assert::are_equal("$42.00", strings::format("{0:C+5}", to_value<Value>(42)), "The precision of currency format is ignored");
    }
    
    void test_method_(format_with_currency_argument_and_negative_precision) {
      assert::are_not_equal("$42.00000", strings::format("{0:C-5}", to_value<Value>(42)), "The precision of currency format  is ignored");
      assert::are_equal("$42.00", strings::format("{0:C-5}", to_value<Value>(42)), "The precision of currency format is ignored");
    }
  
    void test_method_(format_with_currency_argument_and_invalid_precision) {
      assert::throws<std::invalid_argument>([]{strings::format("{0:Ca}", to_value<Value>(42));});
    }

    void test_method_(format_with_decimal_argument) {
      assert::are_equal("42", strings::format("{0:d}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_decimal_argument_and_precision) {
      assert::are_equal("00042", strings::format("{0:D5}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_decimal_argument_and_positive_precision) {
      assert::are_equal("00042", strings::format("{0:D+5}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_decimal_argument_and_negative_precision) {
      assert::are_equal("42   ", strings::format("{0:D-5}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_decimal_argument_and_invalid_precision) {
      assert::throws<std::invalid_argument>([]{strings::format("{0:Da}", to_value<Value>(42));});
    }

    void test_method_(format_negative_with_decimal_argument_and_precision) {
      if(std::is_signed<Value>::value)
        assert::are_equal("-000123", strings::format("{0:D6}", to_value<Value>(-123)));
    }
    
    void test_method_(format_negative_with_decimal_argument_and_positive_precision) {
      if (std::is_signed<Value>::value)
        assert::are_equal("-000123", strings::format("{0:D+6}", to_value<Value>(-123)));
    }
    
    void test_method_(format_negative_with_decimal_argument_and_negative_precision) {
      if (std::is_signed<Value>::value)
        assert::are_equal("-123   ", strings::format("{0:D-6}", to_value<Value>(-123)));
    }
    
    void test_method_(format_with_exponencial_argument) {
      assert::are_equal("4.200000e+01", strings::format("{0:e}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_exponencial_argument_and_precision) {
      assert::are_equal("4.2000000000E+01", strings::format("{0:E10}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_exponencial_argument_and_positive_precision) {
      assert::are_equal("4.2000000000E+01", strings::format("{0:E+10}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_exponencial_argument_and_negative_precision) {
      assert::are_equal("4.200000E+01", strings::format("{0:E-10}", to_value<Value>(42)), "Negative precision for exponencial format reset precision to default (6).");
    }
    
    void test_method_(format_with_exponencial_argument_and_invalid_precision) {
      assert::throws<std::invalid_argument>([]{strings::format("{0:Ea}", to_value<Value>(42));});
    }
    
    void test_method_(format_with_fixed_point_argument) {
      assert::are_equal("42.00", strings::format("{0:f}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_fixed_point_argument_and_precision) {
      assert::are_equal("42.0000", strings::format("{0:F4}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_fixed_point_argument_and_positive_precision) {
      assert::are_equal("42.0000", strings::format("{0:F+4}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_fixed_point_argument_and_negative_precision) {
      assert::are_equal("42.000000", strings::format("{0:F-4}", to_value<Value>(42)), "Negative precision for fixed-point format reset precision to default (6).");
    }
    
    void test_method_(format_with_fixed_point_argument_and_invalid_precision) {
      assert::throws<std::invalid_argument>([]{strings::format("{0:Fa}", to_value<Value>(42));});
    }
    
    void test_method_(format_with_general_argument) {
      assert::are_equal("42", strings::format("{0:g}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_general_argument_and_precision) {
      assert::are_equal("42", strings::format("{0:G2}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_general_argument_and_positive_precision) {
      assert::are_equal("42", strings::format("{0:G+2}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_general_argument_and_negative_precision) {
      assert::are_equal("42", strings::format("{0:G-2}", to_value<Value>(42)));
    }

    void test_method_(format_with_general_argument_and_invalid_precision) {
      assert::throws<std::invalid_argument>([]{strings::format("{0:Ga}", to_value<Value>(42));});
    }
    
    void test_method_(format_with_number_argument) {
      if (std::is_same<Value, char>::value || std::is_same<Value, unsigned char>::value || std::is_same<Value, int8_t>::value || std::is_same<Value, uint8_t>::value)
        assert::are_equal("123.00", strings::format("{0:n}", to_value<Value>(123)));
      else if (std::is_same<Value, short>::value || std::is_same<Value, unsigned short>::value)
        assert::are_equal("1,234.00", strings::format("{0:n}", to_value<Value>(1234)));
      else
        assert::are_equal("1,234,567.00", strings::format("{0:n}", to_value<Value>(1234567)));
    }
    
    void test_method_(format_with_number_argument_and_precision) {
      if (std::is_same<Value, char>::value || std::is_same<Value, unsigned char>::value || std::is_same<Value, int8_t>::value || std::is_same<Value, uint8_t>::value)
        assert::are_equal("123.0000", strings::format("{0:N4}", to_value<Value>(123)));
      else if (std::is_same<Value, short>::value || std::is_same<Value, unsigned short>::value)
        assert::are_equal("1,234.0000", strings::format("{0:N4}", to_value<Value>(1234)));
      else
        assert::are_equal("1,234,567.0000", strings::format("{0:N4}", to_value<Value>(1234567)));
    }
    
    void test_method_(format_with_number_argument_and_positive_precision) {
      if (std::is_same<Value, char>::value || std::is_same<Value, unsigned char>::value || std::is_same<Value, int8_t>::value || std::is_same<Value, uint8_t>::value)
        assert::are_equal("123.0000", strings::format("{0:N+4}", to_value<Value>(123)));
      else if (std::is_same<Value, short>::value || std::is_same<Value, unsigned short>::value)
        assert::are_equal("1,234.0000", strings::format("{0:N+4}", to_value<Value>(1234)));
      else
        assert::are_equal("1,234,567.0000", strings::format("{0:N+4}", to_value<Value>(1234567)));
    }
    
    void test_method_(format_with_number_argument_and_negative_precision) {
      if (std::is_same<Value, char>::value || std::is_same<Value, unsigned char>::value || std::is_same<Value, int8_t>::value || std::is_same<Value, uint8_t>::value)
        assert::are_equal("123.000000", strings::format("{0:N-4}", to_value<Value>(123)), "Negative precision for number format reset precision to default (6).");
      else if (std::is_same<Value, short>::value || std::is_same<Value, unsigned short>::value)
        assert::are_equal("1,234.000000", strings::format("{0:N-4}", to_value<Value>(1234)), "Negative precision for number format reset precision to default (6).");
      else
        assert::are_equal("1,234,567.000000", strings::format("{0:N-4}", to_value<Value>(1234567)), "Negative precision for number format reset precision to default (6).");
    }

    void test_method_(format_with_number_argument_and_invalid_precision) {
      assert::throws<std::invalid_argument>([]{strings::format("{0:Na}", to_value<Value>(123));});
    }
    
    void test_method_(format_with_octal_argument) {
      assert::are_equal("52", strings::format("{0:o}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_octal_argument_and_precision) {
      assert::are_equal("00052", strings::format("{0:O5}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_octal_argument_and_positive_precision) {
      assert::are_equal("00052", strings::format("{0:O+5}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_octal_argument_and_negative_precision) {
      assert::are_equal("52   ", strings::format("{0:O-5}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_octal_argument_and_invalid_precision) {
      assert::throws<std::invalid_argument>([]{strings::format("{0:Oa}", to_value<Value>(42));});
    }
    
    void test_method_(format_with_percent_argument) {
      assert::are_equal("100.00 %", strings::format("{0:p}", to_value<Value>(1)));
    }
    
    void test_method_(format_with_percent_argument_and_precision) {
      assert::are_equal("600.0000 %", strings::format("{0:P4}", to_value<Value>(6)));
    }
    
    void test_method_(format_with_percent_argument_and_positive_precision) {
      assert::are_equal("600.0000 %", strings::format("{0:P+4}", to_value<Value>(6)));
    }
    
    void test_method_(format_with_percent_argument_and_negative_precision) {
      assert::are_equal("600.000000 %", strings::format("{0:P-4}", to_value<Value>(6)), "Negative precision for percent format reset precision to default (6).");
    }
    
    void test_method_(format_with_percent_argument_and_invalid_precision) {
      assert::throws<std::invalid_argument>([]{strings::format("{0:Pa}", to_value<Value>(42));});
    }
    
    void test_method_(format_with_hexadecimal_argument) {
      assert::are_equal("2a", strings::format("{0:x}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_hexadecimal_argument_and_precision) {
      assert::are_equal("002A", strings::format("{0:X4}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_hexadecimal_argument_and_positive_precision) {
      assert::are_equal("002A", strings::format("{0:X+4}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_hexadecimal_argument_and_negative_precision) {
      assert::are_equal("2A  ", strings::format("{0:X-4}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_hexadecimal_argument_and_invalid_precision) {
      assert::throws<std::invalid_argument>([]{strings::format("{0:Xa}", to_value<Value>(42));});
    }
    
    void test_method_(format_with_alignment_before_format) {
      assert::are_equal("    42", strings::format("{0,6:D}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_alignmentafter_format) {
      assert::throws<std::invalid_argument>([]{strings::format("{0:D,6}", to_value<Value>(42));});
    }

    void test_method_(format_with_invalid_format) {
      assert::throws<std::invalid_argument>([]{strings::format("{0:V}", to_value<Value>(42));});
    }
  };
}
