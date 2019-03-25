#include <xtd/strings>
#include <xtd/tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  template <typename Value>
  class test_numeric_format;
  
  test_class_attribute<test_numeric_format<short>> test_numeric_format_class_short_attr {"test_numeric_format<short>"};
  test_class_attribute<test_numeric_format<unsigned short>> test_numeric_format_class_unsigned_short_attr {"test_numeric_format<unsigned short>"};
  test_class_attribute<test_numeric_format<int>> test_numeric_format_class_int_attr {"test_numeric_format<int>"};
  test_class_attribute<test_numeric_format<unsigned int>> test_numeric_format_class_unsigned_int_attr {"test_numeric_format<unsigned int>"};
  test_class_attribute<test_numeric_format<long>> test_numeric_format_class_long_attr {"test_numeric_format<long>"};
  test_class_attribute<test_numeric_format<unsigned long>> test_numeric_format_class_unsigned_long_attr {"test_numeric_format<unsigned long>"};
  test_class_attribute<test_numeric_format<long long>> test_numeric_format_class_long_long_attr {"test_numeric_format<long long>"};
  test_class_attribute<test_numeric_format<unsigned long long>> test_numeric_format_class_unsigned_long_long_attr {"test_numeric_format<unsigned long long>"};

  template<typename Value>
  class test_numeric_format : public test_class {
  public:
    void test_method_(string_format_int_with_default_argument) {
      assert::are_equal("42", strings::format("{0}", static_cast<Value>(42)));
    }
    
    void test_method_(string_format_string_with_currency_argument) {
      assert::are_equal("$42.00", strings::format("{0:c}", static_cast<Value>(42)));
    }
    
    void test_method_(string_format_int_with_currency_argument_and_precision) {
       assert::are_not_equal("$42.00000", strings::format("{0:C5}", static_cast<Value>(42)), "The precision of currency format  is ignored");
      assert::are_equal("$42.00", strings::format("{0:C5}", static_cast<Value>(42)), "The precision of currency format is ignored");
    }
    
    void test_method_(string_format_string_with_decimal_argument) {
      assert::are_equal("42", strings::format("{0:d}", static_cast<Value>(42)));
    }
    
    void test_method_(string_format_int_with_decimal_argument_and_precision) {
      assert::are_equal("00042", strings::format("{0:D5}", static_cast<Value>(42)));
    }
    
    void test_method_(string_format_nevative_int_with_decimal_argument_and_precision) {
      assume::is_true(std::is_signed<Value>::value, "Does not test with unsigned");
      assert::are_equal("-001234", strings::format("{0:D6}", static_cast<Value>(-1234)));
    }
    
    void test_method_(string_format_string_with_exponencial_argument) {
      assert::are_equal("4.200000e+01", strings::format("{0:e}", static_cast<Value>(42)));
    }
    
    void test_method_(string_format_int_with_exponencial_argument_and_precision) {
      assert::are_equal("4.2000000000E+01", strings::format("{0:E10}", static_cast<Value>(42)));
    }
    
    void test_method_(string_format_string_with_fixed_point_argument) {
      assert::are_equal("42.00", strings::format("{0:f}", static_cast<Value>(42)));
    }
    
    void test_method_(string_format_int_with_fixed_point_argument_and_precision) {
      assert::are_equal("42.0000", strings::format("{0:F4}", static_cast<Value>(42)));
    }
    
    void test_method_(string_format_string_with_general_argument) {
      assert::are_equal("42", strings::format("{0:g}", static_cast<Value>(42)));
    }
    
    void test_method_(string_format_int_with_general_argument_and_precision) {
      assert::are_equal("42", strings::format("{0:G2}", static_cast<Value>(42)));
    }
    
    void test_method_(string_format_string_with_number_argument) {
      if (std::is_same<Value, short>::value || std::is_same<Value, unsigned short>::value)
        assert::are_equal("1,234.00", strings::format("{0:n}", static_cast<Value>(1234)));
      else
        assert::are_equal("1,234,567.00", strings::format("{0:n}", static_cast<Value>(1234567)));
    }
    
    void test_method_(string_format_int_with_number_argument_and_precision) {
      if (std::is_same<Value, short>::value || std::is_same<Value, unsigned short>::value)
        assert::are_equal("1,234.0000", strings::format("{0:N4}", static_cast<Value>(1234)));
      else
        assert::are_equal("1,234,567.00", strings::format("{0:n}", static_cast<Value>(1234567)));
    }
    
    void test_method_(string_format_string_with_octal_argument) {
      assert::are_equal("52", strings::format("{0:o}", static_cast<Value>(42)));
    }
    
    void test_method_(string_format_int_with_octal_argument_and_precision) {
      assert::are_equal("00052", strings::format("{0:O5}", static_cast<Value>(42)));
    }

    void test_method_(string_format_string_with_percent_argument) {
      assert::are_equal("100.00 %", strings::format("{0:p}", static_cast<Value>(1)));
    }
    
    void test_method_(string_format_int_with_percent_argument_and_precision) {
      assert::are_equal("600.0000 %", strings::format("{0:P4}", static_cast<Value>(6)));
    }
    
    void test_method_(string_format_string_with_round_trip_argument) {
      assert::throws<std::invalid_argument>([]{strings::format("{0:r}", static_cast<Value>(42));});
    }
    
    void test_method_(string_format_int_with_round_trip_argument_and_precision) {
      assert::throws<std::invalid_argument>([]{strings::format("{0:R4}", static_cast<Value>(42));});
    }
    
    void test_method_(string_format_string_with_hexadecimal_argument) {
      assert::are_equal("2a", strings::format("{0:x}", static_cast<Value>(42)));
    }
    
    void test_method_(string_format_int_with_hexadecimal_argument_and_precision) {
      assert::are_equal("002A", strings::format("{0:X4}", static_cast<Value>(42)));
    }
    
    void test_method_(string_format_int_with_invalid_format) {
      assert::throws<std::invalid_argument>([]{strings::format("{0:V2}", static_cast<Value>(42));});
    }
  };
}
