#include <xtd/strings>
#include <xtd/tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  template <typename Value>
  class test_fixed_point_format;
  
  test_class_attribute<test_fixed_point_format<float>> test_fixed_point_format_class_float_attr {"test_fixed_point_format<float>"};
  test_class_attribute<test_fixed_point_format<double>> test_fixed_point_format_class_double_attr {"test_fixed_point_format<double>"};
  test_class_attribute<test_fixed_point_format<long double>> test_fixed_point_format_class_long_double_attr {"test_fixed_point_format<long double>"};

  template<typename Value>
  class test_fixed_point_format : public test_class {
  private:
    template<typename V>
    static V to_value(V value) {return value;}
    
  public:
    void test_method_(format_with_default_argument) {
      assert::are_equal("42", strings::format("{0}", to_value<Value>(42)));
    }
    
    void test_method_(format_with_decimal_with_default_argument) {
      assert::are_equal("42.24", strings::format("{0}", to_value<Value>(42.24)));
    }

    void test_method_(format_without_format_argument_separator) {
      assert::throws<std::invalid_argument>([]{strings::format("{0F}", to_value<Value>(42.24));});
    }
    
    void test_method_(format_with_left_alignment) {
      assert::are_equal("  42.24", strings::format("{0,7}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_left_alignment_with_plus) {
      assert::are_equal("  42.24", strings::format("{0,+7}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_left_alignment_with_zero) {
      assert::are_equal("42.24", strings::format("{0,0}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_right_alignment) {
      assert::are_equal("42.24  ", strings::format("{0,-7}", to_value<Value>(42.24)));
    }
    
    void test_method_(format_with_right_alignment_with_zero) {
      assert::are_equal("42.24", strings::format("{0,-0}", to_value<Value>(42.24)));
    }

  };
}
