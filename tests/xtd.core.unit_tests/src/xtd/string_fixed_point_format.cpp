#include <xtd/ustring.h>
#include <xtd/format_exception.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  template <typename Value>
  class test_string_fixed_point_format;
  
  test_class_attribute<test_string_fixed_point_format<float>> test_string_fixed_point_format_class_float_attr {"test_string_fixed_point_format<float>"};
  test_class_attribute<test_string_fixed_point_format<double>> test_string_fixed_point_format_class_double_attr {"test_string_fixed_point_format<double>"};
  test_class_attribute<test_string_fixed_point_format<long double>> test_string_fixed_point_format_class_long_double_attr {"test_string_fixed_point_format<long double>"};
  
  template<typename Value>
  class test_string_fixed_point_format : public test_class {
  public:
    static void class_initialize_(class_initialize) {
      std::locale::global(std::locale("en_US.UTF-8"));
    }
    
    void test_method_(format_with_default_argument) {
      assert::are_equal("42", ustring::format("{0}", static_cast<Value>(42.0)), csf_);
    }
    
    void test_method_(format_with_decimals_with_default_argument) {
      assert::are_equal("42.24", ustring::format("{0}", static_cast<Value>(42.24)), csf_);
    }
    
    void test_method_(format_without_format_argument_separator) {
      assert::throws<format_exception>([]{ustring::format("{0F}", static_cast<Value>(42.24));}, csf_);
    }
    
    void test_method_(format_with_left_alignment) {
      assert::are_equal("  42.24", ustring::format("{0,7}", static_cast<Value>(42.24)), csf_);
    }
    
    void test_method_(format_with_left_alignment_with_plus) {
      assert::are_equal("  42.24", ustring::format("{0,+7}", static_cast<Value>(42.24)), csf_);
    }
    
    void test_method_(format_with_left_alignment_with_zero) {
      assert::are_equal("42.24", ustring::format("{0,0}", static_cast<Value>(42.24)), csf_);
    }
    
    void test_method_(format_with_right_alignment) {
      assert::are_equal("42.24  ", ustring::format("{0,-7}", static_cast<Value>(42.24)), csf_);
    }
    
    void test_method_(format_with_right_alignment_with_zero) {
      assert::are_equal("42.24", ustring::format("{0,-0}", static_cast<Value>(42.24)), csf_);
    }
    
    void test_method_(format_with_alignment_empty) {
      assert::are_equal("42.24", ustring::format("{0,}", static_cast<Value>(42.24)), csf_);
    }
    
    void test_method_(format_with_alignment_invalid) {
      assert::throws<format_exception>([]{ustring::format("{0,a}", static_cast<Value>(42.24), csf_);});
    }
    
    void test_method_(format_with_currency_argument) {
      assert::are_equal("$42.24", ustring::format("{0:c}", static_cast<Value>(42.24)), csf_);
    }
    
    void test_method_(format_with_currency_argument_and_one_digiti_precision) {
      assert::are_not_equal("$42.24000", ustring::format("{0:C5}", static_cast<Value>(42.24)), "The precision of currency format  is ignored", csf_);
      assert::are_equal("$42.24", ustring::format("{0:C5}", static_cast<Value>(42.24)), "The precision of currency format is ignored", csf_);
    }
    
    void test_method_(format_with_currency_argument_and_two_digitis_precision) {
      assert::are_not_equal("$42.24000", ustring::format("{0:C10}", static_cast<Value>(42.24)), "The precision of currency format  is ignored", csf_);
      assert::are_equal("$42.24", ustring::format("{0:C10}", static_cast<Value>(42.24)), "The precision of currency format is ignored", csf_);
    }
    
    void test_method_(format_with_currency_argument_and_three_digitis_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:C100}", static_cast<Value>(42.24));}, csf_);
    }
    
    void test_method_(format_with_currency_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:C-5}", static_cast<Value>(42.24));}, csf_);
    }
    
    void test_method_(format_with_currency_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:Ca}", static_cast<Value>(42.24));}, csf_);
    }
    
    void test_method_(format_with_exponencial_argument) {
      assert::are_equal("4.224000e+01", ustring::format("{0:e}", static_cast<Value>(42.24)), csf_);
    }
    
    void test_method_(format_with_exponencial_argument_and_one_digiti_precision) {
      if (std::is_same<Value, float>::value)
        assert::are_equal("4.22400017E+01", ustring::format("{0:E8}", static_cast<Value>(42.24)), csf_);
      else
        assert::are_equal("4.22400000E+01", ustring::format("{0:E8}", static_cast<Value>(42.24)), csf_);
    }
    
    void test_method_(format_with_exponencial_argument_and_two_digitis_precision) {
      if (std::is_same<Value, float>::value)
        assert::are_equal("4.2240001678E+01", ustring::format("{0:E10}", static_cast<Value>(42.24)), csf_);
      else
        assert::are_equal("4.2240000000E+01", ustring::format("{0:E10}", static_cast<Value>(42.24)), csf_);
    }
    
    void test_method_(format_with_exponencial_argument_and_three_digitis_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:E100}", static_cast<Value>(42.24), csf_);});
    }
    
    void test_method_(format_with_exponencial_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:E-8}", static_cast<Value>(42.24), csf_);});
    }
    
    void test_method_(format_with_exponencial_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:Ea}", static_cast<Value>(42.24), csf_);});
    }
    
    void test_method_(format_with_fixed_point_argument) {
      assert::are_equal("42.24", ustring::format("{0:f}", static_cast<Value>(42.24)), csf_);
    }
    
    void test_method_(format_with_fixed_point_argument_and_one_digit_precision) {
      assert::are_equal("42.2400", ustring::format("{0:F4}", static_cast<Value>(42.24)), csf_);
    }
    
    void test_method_(format_with_fixed_point_argument_and_two_digitis_precision) {
      if (std::is_same<Value, float>::value)
        assert::are_equal("42.2400016785", ustring::format("{0:F10}", static_cast<Value>(42.24)), csf_);
      else
        assert::are_equal("42.2400000000", ustring::format("{0:F10}", static_cast<Value>(42.24)), csf_);
    }
    
    void test_method_(format_with_fixed_point_argument_and_three_digitis_precision) {
      assert::throws<format_exception>([]{ustring::format("{0F100}", static_cast<Value>(42.24), csf_);});
    }
    
    void test_method_(format_with_fixed_point_argument_and_negative_precision) {
      assert::throws<format_exception>([]{ustring::format("{0F-4}", static_cast<Value>(42.24), csf_);});
    }
    
    void test_method_(format_with_fixed_point_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:Fa}", static_cast<Value>(42.24), csf_);});
    }
    
    void test_method_(format_with_general_argument) {
      assert::are_equal("42", ustring::format("{0:g}", static_cast<Value>(42.0)), csf_);
    }
    
    void test_method_(format_with_decimals_with_general_argument) {
      assert::are_equal("42.24", ustring::format("{0:g}", static_cast<Value>(42.24)), csf_);
    }
    
    void test_method_(format_with_general_argument_and_one_digiti_precision) {
      assert::are_equal("42", ustring::format("{0:G4}", static_cast<Value>(42.0)), csf_);
    }
    
    void test_method_(format_with_decimals_with_general_argument_and_one_digiti_precision) {
      assert::are_equal("42.24", ustring::format("{0:G4}", static_cast<Value>(42.24)), csf_);
    }
    
    void test_method_(format_with_generals_argument_and_two_digitis_precision) {
      assert::are_equal("42", ustring::format("{0:G10}", static_cast<Value>(42.0)), csf_);
    }
    
    void test_method_(format_with_decimals_with_general_argument_and_two_digitis_precision) {
      if (std::is_same<Value, float>::value)
        assert::are_equal("42.24000168", ustring::format("{0:G10}", static_cast<Value>(42.24)), csf_);
      else
        assert::are_equal("42.24", ustring::format("{0:G10}", static_cast<Value>(42.24)), csf_);
    }
    
    void test_method_(format_with_generals_argument_and_three_digitis_precision) {
      assert::are_equal("42", ustring::format("{0:G10}", static_cast<Value>(42.0)), csf_);
    }
    
    void test_method_(format_with_decimals_with_general_argument_and_three_digitis_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:G100}", static_cast<Value>(42.24), csf_);});
    }
    
    void test_method_(format_with_general_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:G-4}", static_cast<Value>(42.0), csf_);});
    }
    
    void test_method_(format_with_decimals_with_general_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:G-4}", static_cast<Value>(42.24), csf_);});
    }
    
    void test_method_(format_with_decimals_with_general_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:Ga}", static_cast<Value>(42.0), csf_);});
    }
    
    void test_method_(format_with_general_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:Ga}", static_cast<Value>(42.24), csf_);});
    }
    
    void test_method_(format_with_number_argument) {
      if (std::is_same<Value, float>::value)
        assert::are_equal("1,234,567.88", ustring::format("{0:n}", static_cast<Value>(1234567.89)), csf_);
      else
        assert::are_equal("1,234,567.89", ustring::format("{0:n}", static_cast<Value>(1234567.89)), csf_);
    }
    
    void test_method_(format_with_number_argument_and_one_digiti_precision) {
      if (std::is_same<Value, float>::value)
        assert::are_equal("1,234,567.8750", ustring::format("{0:N4}", static_cast<Value>(1234567.89)), csf_);
      else
        assert::are_equal("1,234,567.8900", ustring::format("{0:N4}", static_cast<Value>(1234567.89)), csf_);
    }
    
    void test_method_(format_with_number_argument_and_two_digitis_precision) {
      if (std::is_same<Value, float>::value)
        assert::are_equal("1,234,567.8750000000", ustring::format("{0:N10}", static_cast<Value>(1234567.89)), csf_);
      else
        assert::are_equal("1,234,567.8899999999", ustring::format("{0:N10}", static_cast<Value>(1234567.89)), csf_);
    }
    
    void test_method_(format_with_number_argument_and_three_digitis_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:N100}", static_cast<Value>(1234567.89));}, csf_);
    }
    
    void test_method_(format_with_number_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:N-4}", static_cast<Value>(1234567.89));}, csf_);
    }
    
    void test_method_(format_with_number_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:Na}", static_cast<Value>(1234567.89));}, csf_);
    }
    
    void test_method_(format_with_percent_argument) {
      assert::are_equal("100.00 %", ustring::format("{0:p}", static_cast<Value>(1.0)), csf_);
    }
    
    void test_method_(format_with_percent_argument_and_one_digiti_precision) {
      assert::are_equal("6.5000 %", ustring::format("{0:P4}", static_cast<Value>(0.065)), csf_);
    }
    
    void test_method_(format_with_percent_argument_and_two_digitis_precision) {
      assert::are_equal("6.5000000000 %", ustring::format("{0:P10}", static_cast<Value>(0.065)), csf_);
    }
    
    void test_method_(format_with_percent_argument_and_three_digitis_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:P100}", static_cast<Value>(0.42), csf_);});
    }
    
    void test_method_(format_with_percent_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:P-2}", static_cast<Value>(0.42), csf_);});
    }
    
    void test_method_(format_with_percent_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:Pa}", static_cast<Value>(0.42), csf_);});
    }
    
    void test_method_(format_with_alignment_before_format) {
      assert::are_equal(" 42.00", ustring::format("{0,6:F}", static_cast<Value>(42.0)), csf_);
    }
    
    void test_method_(format_with_alignmentafter_format) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:F,6}", static_cast<Value>(42.0));}, csf_);
    }
    
    void test_method_(format_with_invalid_format) {
      assert::throws<xtd::format_exception>([]{ustring::format("{0:V}", static_cast<Value>(42.0));}, csf_);
    }
  };
}
