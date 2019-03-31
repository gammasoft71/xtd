#include <xtd/strings>
#include <xtd/tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  template <typename Value>
  class test_wstring_fixed_point_format;
  
  test_class_attribute<test_wstring_fixed_point_format<float>> test_wstring_fixed_point_format_class_float_attr {"test_wstring_fixed_point_format<float>"};
  test_class_attribute<test_wstring_fixed_point_format<double>> test_wstring_fixed_point_format_class_double_attr {"test_wstring_fixed_point_format<double>"};
  test_class_attribute<test_wstring_fixed_point_format<long double>> test_wstring_fixed_point_format_class_long_double_attr {"test_wstring_fixed_point_format<long double>"};

  template<typename Value>
  class test_wstring_fixed_point_format : public test_class {
  private:
    template<typename V>
    static V to_value(V value) {return value;}
    
  public:
    void test_method_(format_with_default_argument) {
      assert::are_equal(L"42", strings::format(L"{0}", to_value<Value>(42.0)));
    }
    
    void test_method_(format_with_decimals_with_default_argument) {
      assert::are_equal(L"42.24", strings::format(L"{0}", to_value<Value>(42.24)));
    }

    void test_method_(format_without_format_argument_separator) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0F}", to_value<Value>(42.24));});
    }
    
    void test_method_(format_with_left_alignment) {
      assert::are_equal(L"  42.24", strings::format(L"{0,7}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_left_alignment_with_plus) {
      assert::are_equal(L"  42.24", strings::format(L"{0,+7}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_left_alignment_with_zero) {
      assert::are_equal(L"42.24", strings::format(L"{0,0}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_right_alignment) {
      assert::are_equal(L"42.24  ", strings::format(L"{0,-7}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_right_alignment_with_zero) {
      assert::are_equal(L"42.24", strings::format(L"{0,-0}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_alignment_empty) {
      assert::are_equal(L"42.24", strings::format(L"{0,}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_alignment_invalid) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0,a}", to_value<Value>(42.24));});
    }
    
    void test_method_(format_with_currency_argument) {
      assert::are_equal(L"$42.24", strings::format(L"{0:c}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_currency_argument_and_one_digit_precision) {
      assert::are_not_equal(L"$42.24000", strings::format(L"{0:C5}", to_value<Value>(42.24)), "The precision of currency format  is ignored");
      assert::are_equal(L"$42.24", strings::format(L"{0:C5}", to_value<Value>(42.24)), "The precision of currency format is ignored");
    }
    
    void test_method_(format_with_currency_argument_and_two_digits_precision) {
      assert::are_not_equal(L"$42.24000", strings::format(L"{0:C10}", to_value<Value>(42.24)), "The precision of currency format  is ignored");
      assert::are_equal(L"$42.24", strings::format(L"{0:C10}", to_value<Value>(42.24)), "The precision of currency format is ignored");
    }
    
    void test_method_(format_with_currency_argument_and_three_digitis_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:C100}", to_value<Value>(42.24));});
    }
    
    void test_method_(format_with_currency_argument_and_negative_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:C-5}", to_value<Value>(42.24));});
    }

    void test_method_(format_with_currency_argument_and_invalid_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:Ca}", to_value<Value>(42.24));});
    }
    
    void test_method_(format_with_exponencial_argument) {
      assert::are_equal(L"4.224000e+01", strings::format(L"{0:e}", to_value<Value>(42.24)));
    }
    
   void test_method_(format_with_exponencial_argument_and_one_digit_precision) {
      if (std::is_same<Value, float>::value)
        assert::are_equal(L"4.22400017E+01", strings::format(L"{0:E8}", to_value<Value>(42.24)));
      else
        assert::are_equal(L"4.22400000E+01", strings::format(L"{0:E8}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_exponencial_argument_and_two_digits_precision) {
      if (std::is_same<Value, float>::value)
        assert::are_equal(L"4.2240001678E+01", strings::format(L"{0:E10}", to_value<Value>(42.24)));
      else
        assert::are_equal(L"4.2240000000E+01", strings::format(L"{0:E10}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_exponencial_argument_and_three_digitis_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:E100}", to_value<Value>(42.24));});
    }
    
    void test_method_(format_with_exponencial_argument_and_negative_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:E-8}", to_value<Value>(42.24));});
    }
    
    void test_method_(format_with_exponencial_argument_and_invalid_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:Ea}", to_value<Value>(42.24));});
    }
    
    void test_method_(format_with_fixed_point_argument) {
      assert::are_equal(L"42.24", strings::format(L"{0:f}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_fixed_point_argument_and_one_digit_precision) {
      assert::are_equal(L"42.2400", strings::format(L"{0:F4}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_fixed_point_argument_and_two_digits_precision) {
      if (std::is_same<Value, float>::value)
        assert::are_equal(L"42.2400016785", strings::format(L"{0:F10}", to_value<Value>(42.24)));
      else
        assert::are_equal(L"42.2400000000", strings::format(L"{0:F10}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_fixed_point_argument_and_three_digitis_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0F100}", to_value<Value>(42.24));});
    }
    
    void test_method_(format_with_fixed_point_argument_and_negative_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0F-4}", to_value<Value>(42.24));});
    }
    
    void test_method_(format_with_fixed_point_argument_and_invalid_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:Fa}", to_value<Value>(42.24));});
    }
    
    void test_method_(format_with_general_argument) {
      assert::are_equal(L"42", strings::format(L"{0:g}", to_value<Value>(42.0)));
    }
    
    void test_method_(format_with_decimals_with_general_argument) {
      if (std::is_same<Value, float>::value)
        assert::are_equal(L"42.24000168", strings::format(L"{0:g}", to_value<Value>(42.24)));
      else
        assert::are_equal(L"42.24", strings::format(L"{0:g}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_general_argument_and_one_digit_precision) {
      assert::are_equal(L"42", strings::format(L"{0:G4}", to_value<Value>(42.0)));
    }
    
    void test_method_(format_with_decimals_with_general_argument_and_one_digit_precision) {
      assert::are_equal(L"42.24", strings::format(L"{0:G4}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_generals_argument_and_two_digits_precision) {
      assert::are_equal(L"42", strings::format(L"{0:G10}", to_value<Value>(42.0)));
    }
    
    void test_method_(format_with_decimals_with_general_argument_and_two_digits_precision) {
      if (std::is_same<Value, float>::value)
        assert::are_equal(L"42.24000168", strings::format(L"{0:G10}", to_value<Value>(42.24)));
      else
        assert::are_equal(L"42.24", strings::format(L"{0:G10}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_generals_argument_and_three_digitis_precision) {
      assert::are_equal(L"42", strings::format(L"{0:G10}", to_value<Value>(42.0)));
    }

    void test_method_(format_with_decimals_with_general_argument_and_three_digitis_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:G100}", to_value<Value>(42.24));});
    }
    
    void test_method_(format_with_general_argument_and_negative_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:G-4}", to_value<Value>(42.0));});
    }

    void test_method_(format_with_decimals_with_general_argument_and_negative_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:G-4}", to_value<Value>(42.24));});
    }
    
    void test_method_(format_with_decimals_with_general_argument_and_invalid_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:Ga}", to_value<Value>(42.0));});
    }
    
    void test_method_(format_with_general_argument_and_invalid_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:Ga}", to_value<Value>(42.24));});
    }
    
    void test_method_(format_with_number_argument) {
      if (std::is_same<Value, float>::value)
        assert::are_equal(L"1,234,567.88", strings::format(L"{0:n}", to_value<Value>(1234567.89)));
      else
        assert::are_equal(L"1,234,567.89", strings::format(L"{0:n}", to_value<Value>(1234567.89)));
    }
    
    void test_method_(format_with_number_argument_and_one_digit_precision) {
      if (std::is_same<Value, float>::value)
        assert::are_equal(L"1,234,567.8750", strings::format(L"{0:N4}", to_value<Value>(1234567.89)));
      else
        assert::are_equal(L"1,234,567.8900", strings::format(L"{0:N4}", to_value<Value>(1234567.89)));
    }
    
    void test_method_(format_with_number_argument_and_two_digits_precision) {
      if (std::is_same<Value, float>::value)
        assert::are_equal(L"1,234,567.8750000000", strings::format(L"{0:N10}", to_value<Value>(1234567.89)));
      else
        assert::are_equal(L"1,234,567.8899999999", strings::format(L"{0:N10}", to_value<Value>(1234567.89)));
    }
    
    void test_method_(format_with_number_argument_and_three_digitis_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:N100}", to_value<Value>(1234567.89));});
    }

    void test_method_(format_with_number_argument_and_negative_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:N-4", to_value<Value>(1234567.89));});
    }
    
    void test_method_(format_with_number_argument_and_invalid_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:Na}", to_value<Value>(1234567.89));});
    }
    
    void test_method_(format_with_percent_argument) {
      assert::are_equal(L"100.00 %", strings::format(L"{0:p}", to_value<Value>(1.0)));
    }
    
    void test_method_(format_with_percent_argument_and_one_digit_precision) {
      assert::are_equal(L"6.5000 %", strings::format(L"{0:P4}", to_value<Value>(0.065)));
    }
    
    void test_method_(format_with_percent_argument_and_two_digits_precision) {
      assert::are_equal(L"6.5000000000 %", strings::format(L"{0:P10}", to_value<Value>(0.065)));
    }
    
    void test_method_(format_with_percent_argument_and_three_digitis_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:P100}", to_value<Value>(0.42));});
    }

    void test_method_(format_with_percent_argument_and_negative_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:P-2}", to_value<Value>(0.42));});
    }
    
    void test_method_(format_with_percent_argument_and_invalid_precision) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:Pa}", to_value<Value>(0.42));});
    }
    
    void test_method_(format_with_alignment_before_format) {
      assert::are_equal(L" 42.00", strings::format(L"{0,6:F}", to_value<Value>(42.0)));
    }
    
    void test_method_(format_with_alignmentafter_format) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:F,6}", to_value<Value>(42.0));});
    }

    void test_method_(format_with_invalid_format) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0:V}", to_value<Value>(42.0));});
    }
  };
}
