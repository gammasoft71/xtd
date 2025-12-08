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
  class format_u8string_fixed_point_tests;
  
  test_class_attribute<format_u8string_fixed_point_tests<float>> format_u8string_fixed_point_tests_class_float_attr {"format_u8string_fixed_point_tests<float>"};
  test_class_attribute<format_u8string_fixed_point_tests<double>> format_u8string_fixed_point_tests_class_double_attr {"format_u8string_fixed_point_tests<double>"};
  test_class_attribute<format_u8string_fixed_point_tests<long double>> format_u8string_fixed_point_tests_class_long_double_attr {"format_u8string_fixed_point_tests<long_double>"};
  
  template<class value_t>
  class format_u8string_fixed_point_tests : public test_class {
    inline static xtd::globalization::culture_info previous_culture;
    
    static void class_initialize_(class_initialize) {
      previous_culture = xtd::globalization::culture_info::current_culture();
      xtd::globalization::culture_info::current_culture(xtd::globalization::culture_info {"en-US"});
    }
    
    static void class_cleanup_(class_cleanup) {
      xtd::globalization::culture_info::current_culture(previous_culture);
    }
    
    auto test_method_(format_with_default_argument) {
      assert::are_equal(u8"42", format(u8"{0}", static_cast<value_t>(42.0)));
    }
    
    auto test_method_(format_with_decimals_with_default_argument) {
      assert::are_equal(u8"42.24", format(u8"{0}", static_cast<value_t>(42.24)));
    }
    
    auto test_method_(format_without_format_argument_separator) {
      assert::throws<format_exception>([] {format(u8"{0F}", static_cast<value_t>(42.24));});
    }
    
    auto test_method_(format_with_left_alignment) {
      assert::are_equal(u8"  42.24", format(u8"{0,7}", static_cast<value_t>(42.24)));
    }
    
    auto test_method_(format_with_left_alignment_with_plus) {
      assert::are_equal(u8"  42.24", format(u8"{0,+7}", static_cast<value_t>(42.24)));
    }
    
    auto test_method_(format_with_left_alignment_with_zero) {
      assert::are_equal(u8"42.24", format(u8"{0,0}", static_cast<value_t>(42.24)));
    }
    
    auto test_method_(format_with_right_alignment) {
      assert::are_equal(u8"42.24  ", format(u8"{0,-7}", static_cast<value_t>(42.24)));
    }
    
    auto test_method_(format_with_right_alignment_with_zero) {
      assert::are_equal(u8"42.24", format(u8"{0,-0}", static_cast<value_t>(42.24)));
    }
    
    auto test_method_(format_with_alignment_empty) {
      assert::are_equal(u8"42.24", format(u8"{0,}", static_cast<value_t>(42.24)));
    }
    
    auto test_method_(format_with_alignment_invalid) {
      assert::throws<format_exception>([] {format(u8"{0,a}", static_cast<value_t>(42.24));});
    }
    
    auto test_method_(format_with_currency_argument) {
      assert::are_equal(u8"$42.24", format(u8"{0:c}", static_cast<value_t>(42.24)));
    }
    
    auto test_method_(format_with_currency_argument_and_one_digiti_precision) {
      assert::are_not_equal("$42.24000", format(u8"{0:C5}", static_cast<value_t>(42.24)), "The precision of currency format  is ignored");
      assert::are_equal(u8"$42.24", format(u8"{0:C5}", static_cast<value_t>(42.24)), "The precision of currency format is ignored");
    }
    
    auto test_method_(format_with_currency_argument_and_two_digitis_precision) {
      assert::are_not_equal("$42.24000", format(u8"{0:C10}", static_cast<value_t>(42.24)), "The precision of currency format  is ignored");
      assert::are_equal(u8"$42.24", format(u8"{0:C10}", static_cast<value_t>(42.24)), "The precision of currency format is ignored");
    }
    
    auto test_method_(format_with_currency_argument_and_three_digitis_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:C100}", static_cast<value_t>(42.24));});
    }
    
    auto test_method_(format_with_currency_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:C-5}", static_cast<value_t>(42.24));});
    }
    
    auto test_method_(format_with_currency_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:Ca}", static_cast<value_t>(42.24));});
    }
    
    auto test_method_(format_with_exponencial_argument) {
      assert::are_equal(u8"4.224000e+01", format(u8"{0:e}", static_cast<value_t>(42.24)));
    }
    
    auto test_method_(format_with_exponencial_argument_and_one_digiti_precision) {
      if (std::is_same<value_t, float>::value)
        assert::are_equal(u8"4.22400017E+01", format(u8"{0:E8}", static_cast<value_t>(42.24)));
      else
        assert::are_equal(u8"4.22400000E+01", format(u8"{0:E8}", static_cast<value_t>(42.24)));
    }
    
    auto test_method_(format_with_exponencial_argument_and_two_digitis_precision) {
      if (std::is_same<value_t, float>::value)
        assert::are_equal(u8"4.2240001678E+01", format(u8"{0:E10}", static_cast<value_t>(42.24)));
      else
        assert::are_equal(u8"4.2240000000E+01", format(u8"{0:E10}", static_cast<value_t>(42.24)));
    }
    
    auto test_method_(format_with_exponencial_argument_and_three_digitis_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:E100}", static_cast<value_t>(42.24));});
    }
    
    auto test_method_(format_with_exponencial_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:E-8}", static_cast<value_t>(42.24));});
    }
    
    auto test_method_(format_with_exponencial_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:Ea}", static_cast<value_t>(42.24));});
    }
    
    auto test_method_(format_with_fixed_point_argument) {
      assert::are_equal(u8"42.24", format(u8"{0:f}", static_cast<value_t>(42.24)));
    }
    
    auto test_method_(format_with_fixed_point_argument_and_one_digit_precision) {
      assert::are_equal(u8"42.2400", format(u8"{0:F4}", static_cast<value_t>(42.24)));
    }
    
    auto test_method_(format_with_fixed_point_argument_and_two_digitis_precision) {
      if (std::is_same<value_t, float>::value)
        assert::are_equal(u8"42.2400016785", format(u8"{0:F10}", static_cast<value_t>(42.24)));
      else
        assert::are_equal(u8"42.2400000000", format(u8"{0:F10}", static_cast<value_t>(42.24)));
    }
    
    auto test_method_(format_with_fixed_point_argument_and_three_digitis_precision) {
      assert::throws<format_exception>([] {format(u8"{0F100}", static_cast<value_t>(42.24));});
    }
    
    auto test_method_(format_with_fixed_point_argument_and_negative_precision) {
      assert::throws<format_exception>([] {format(u8"{0F-4}", static_cast<value_t>(42.24));});
    }
    
    auto test_method_(format_with_fixed_point_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:Fa}", static_cast<value_t>(42.24));});
    }
    
    auto test_method_(format_with_general_argument) {
      assert::are_equal(u8"42", format(u8"{0:g}", static_cast<value_t>(42.0)));
    }
    
    auto test_method_(format_with_decimals_with_general_argument) {
      assert::are_equal(u8"42.24", format(u8"{0:g}", static_cast<value_t>(42.24)));
    }
    
    auto test_method_(format_with_general_argument_and_one_digiti_precision) {
      assert::are_equal(u8"42", format(u8"{0:G4}", static_cast<value_t>(42.0)));
    }
    
    auto test_method_(format_with_decimals_with_general_argument_and_one_digiti_precision) {
      assert::are_equal(u8"42.24", format(u8"{0:G4}", static_cast<value_t>(42.24)));
    }
    
    auto test_method_(format_with_generals_argument_and_two_digitis_precision) {
      assert::are_equal(u8"42", format(u8"{0:G10}", static_cast<value_t>(42.0)));
    }
    
    auto test_method_(format_with_decimals_with_general_argument_and_two_digitis_precision) {
      if (std::is_same<value_t, float>::value)
        assert::are_equal(u8"42.24000168", format(u8"{0:G10}", static_cast<value_t>(42.24)));
      else
        assert::are_equal(u8"42.24", format(u8"{0:G10}", static_cast<value_t>(42.24)));
    }
    
    auto test_method_(format_with_generals_argument_and_three_digitis_precision) {
      assert::are_equal(u8"42", format(u8"{0:G10}", static_cast<value_t>(42.0)));
    }
    
    auto test_method_(format_with_decimals_with_general_argument_and_three_digitis_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:G100}", static_cast<value_t>(42.24));});
    }
    
    auto test_method_(format_with_general_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:G-4}", static_cast<value_t>(42.0));});
    }
    
    auto test_method_(format_with_decimals_with_general_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:G-4}", static_cast<value_t>(42.24));});
    }
    
    auto test_method_(format_with_decimals_with_general_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:Ga}", static_cast<value_t>(42.0));});
    }
    
    auto test_method_(format_with_general_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:Ga}", static_cast<value_t>(42.24));});
    }
    
    auto test_method_(format_with_number_argument) {
      if (std::is_same<value_t, float>::value)
        assert::are_equal(u8"1,234,567.88", format(u8"{0:n}", static_cast<value_t>(1234567.89)));
      else
        assert::are_equal(u8"1,234,567.89", format(u8"{0:n}", static_cast<value_t>(1234567.89)));
    }
    
    auto test_method_(format_with_number_argument_and_one_digiti_precision) {
      if (std::is_same<value_t, float>::value)
        assert::are_equal(u8"1,234,567.8750", format(u8"{0:N4}", static_cast<value_t>(1234567.89)));
      else
        assert::are_equal(u8"1,234,567.8900", format(u8"{0:N4}", static_cast<value_t>(1234567.89)));
    }
    
    auto test_method_(format_with_number_argument_and_two_digitis_precision) {
      if (std::is_same<value_t, float>::value)
        assert::are_equal(u8"1,234,567.8750000000", format(u8"{0:N10}", static_cast<value_t>(1234567.89)));
      else
        assert::are_equal(u8"1,234,567.8899999999", format(u8"{0:N10}", static_cast<value_t>(1234567.89)));
    }
    
    auto test_method_(format_with_number_argument_and_three_digitis_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:N100}", static_cast<value_t>(1234567.89));});
    }
    
    auto test_method_(format_with_number_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:N-4}", static_cast<value_t>(1234567.89));});
    }
    
    auto test_method_(format_with_number_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:Na}", static_cast<value_t>(1234567.89));});
    }
    
    auto test_method_(format_with_percent_argument) {
      assert::are_equal(u8"100.00 %", format(u8"{0:p}", static_cast<value_t>(1.0)));
    }
    
    auto test_method_(format_with_percent_argument_and_one_digiti_precision) {
      assert::are_equal(u8"6.5000 %", format(u8"{0:P4}", static_cast<value_t>(0.065)));
    }
    
    auto test_method_(format_with_percent_argument_and_two_digitis_precision) {
      assert::are_equal(u8"6.5000000000 %", format(u8"{0:P10}", static_cast<value_t>(0.065)));
    }
    
    auto test_method_(format_with_percent_argument_and_three_digitis_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:P100}", static_cast<value_t>(0.42));});
    }
    
    auto test_method_(format_with_percent_argument_and_negative_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:P-2}", static_cast<value_t>(0.42));});
    }
    
    auto test_method_(format_with_percent_argument_and_invalid_precision) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:Pa}", static_cast<value_t>(0.42));});
    }
    
    auto test_method_(format_with_alignment_before_format) {
      assert::are_equal(u8" 42.00", format(u8"{0,6:F}", static_cast<value_t>(42.0)));
    }
    
    auto test_method_(format_with_alignmentafter_format) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:F,6}", static_cast<value_t>(42.0));});
    }
    
    auto test_method_(format_with_invalid_format) {
      assert::throws<xtd::format_exception>([] {format(u8"{0:V}", static_cast<value_t>(42.0));});
    }
  };
}
