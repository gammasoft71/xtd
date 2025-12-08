#include <xtd/math>
#include <xtd/double_object>
#include <xtd/overflow_exception>
#include <xtd/using>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(double_object_tests) {
    auto test_method_(epsilon) {
      assert::are_equal(4.94066e-324, double_object::epsilon);
    }
    
    auto test_method_(max_value) {
      assert::are_equal(std::numeric_limits<double>::max(), double_object::max_value);
    }
    
    auto test_method_(min_value) {
      assert::are_equal(std::numeric_limits<double>::lowest(), double_object::min_value);
    }
    
    auto test_method_(NaN) {
      assert::is_NaN(double_object::NaN);
    }
    
    auto test_method_(negative_infinity) {
      assert::are_equal(-std::numeric_limits<double>::infinity(), double_object::negative_infinity);
    }
    
    auto test_method_(positive_infinity) {
      assert::are_equal(std::numeric_limits<double>::infinity(), double_object::positive_infinity);
    }
    
    auto test_method_(is_infinity) {
      assert::is_false(double_object::is_infinity(0.0));
      assert::is_false(double_object::is_infinity(1.0));
      assert::is_false(double_object::is_infinity(255.0));
      assert::is_false(double_object::is_infinity(4294967295.0));
      assert::is_false(double_object::is_infinity(0.00390625));
      assert::is_false(double_object::is_infinity(0.00000000023283064365386962890625));
      assert::is_false(double_object::is_infinity(1.23456789012345E-300));
      assert::is_false(double_object::is_infinity(1.2345678901234565));
      assert::is_false(double_object::is_infinity(1.23456789012345678E+300));
      assert::is_false(double_object::is_infinity(double_object::epsilon));
      assert::is_false(double_object::is_infinity(double_object::min_value));
      assert::is_false(double_object::is_infinity(double_object::max_value));
      assert::is_false(double_object::is_infinity(double_object::NaN));
      assert::is_true(double_object::is_infinity(double_object::negative_infinity));
      assert::is_true(double_object::is_infinity(double_object::positive_infinity));
    }
    
    auto test_method_(is_negative_infinity) {
      assert::is_false(double_object::is_negative_infinity(0.0));
      assert::is_false(double_object::is_negative_infinity(1.0));
      assert::is_false(double_object::is_negative_infinity(255.0));
      assert::is_false(double_object::is_negative_infinity(4294967295.0));
      assert::is_false(double_object::is_negative_infinity(0.00390625));
      assert::is_false(double_object::is_negative_infinity(0.00000000023283064365386962890625));
      assert::is_false(double_object::is_negative_infinity(1.23456789012345E-300));
      assert::is_false(double_object::is_negative_infinity(1.2345678901234565));
      assert::is_false(double_object::is_negative_infinity(1.23456789012345678E+300));
      assert::is_false(double_object::is_negative_infinity(double_object::epsilon));
      assert::is_false(double_object::is_negative_infinity(double_object::min_value));
      assert::is_false(double_object::is_negative_infinity(double_object::max_value));
      assert::is_false(double_object::is_negative_infinity(double_object::NaN));
      assert::is_true(double_object::is_negative_infinity(double_object::negative_infinity));
      assert::is_false(double_object::is_negative_infinity(double_object::positive_infinity));
    }
    
    auto test_method_(is_positive_infinity) {
      assert::is_false(double_object::is_positive_infinity(0.0));
      assert::is_false(double_object::is_positive_infinity(1.0));
      assert::is_false(double_object::is_positive_infinity(255.0));
      assert::is_false(double_object::is_positive_infinity(4294967295.0));
      assert::is_false(double_object::is_positive_infinity(0.00390625));
      assert::is_false(double_object::is_positive_infinity(0.00000000023283064365386962890625));
      assert::is_false(double_object::is_positive_infinity(1.23456789012345E-300));
      assert::is_false(double_object::is_positive_infinity(1.2345678901234565));
      assert::is_false(double_object::is_positive_infinity(1.23456789012345678E+300));
      assert::is_false(double_object::is_positive_infinity(double_object::epsilon));
      assert::is_false(double_object::is_positive_infinity(double_object::min_value));
      assert::is_false(double_object::is_positive_infinity(double_object::max_value));
      assert::is_false(double_object::is_positive_infinity(double_object::NaN));
      assert::is_false(double_object::is_positive_infinity(double_object::negative_infinity));
      assert::is_true(double_object::is_positive_infinity(double_object::positive_infinity));
    }
    
    auto test_method_(is_NaN) {
      assert::is_false(double_object::is_NaN(0.0));
      assert::is_false(double_object::is_NaN(1.0));
      assert::is_false(double_object::is_NaN(255.0));
      assert::is_false(double_object::is_NaN(4294967295.0));
      assert::is_false(double_object::is_NaN(0.00390625));
      assert::is_false(double_object::is_NaN(0.00000000023283064365386962890625));
      assert::is_false(double_object::is_NaN(1.23456789012345E-300));
      assert::is_false(double_object::is_NaN(1.2345678901234565));
      assert::is_false(double_object::is_NaN(1.23456789012345678E+300));
      assert::is_false(double_object::is_NaN(double_object::epsilon));
      assert::is_false(double_object::is_NaN(double_object::min_value));
      assert::is_false(double_object::is_NaN(double_object::max_value));
      assert::is_true(double_object::is_NaN(double_object::NaN));
      assert::is_false(double_object::is_NaN(double_object::negative_infinity));
      assert::is_false(double_object::is_NaN(double_object::positive_infinity));
    }
    
    auto test_method_(format) {
      assert::are_equal("0", string::format("{}", 0.0));
      assert::are_equal("1", string::format("{}", 1.0));
      assert::are_equal("255", string::format("{}", 255.0));
      assert::are_equal("4294967295", string::format("{}", 4294967295.0));
      assert::are_equal("0.00390625", string::format("{}", 0.00390625));
      assert::are_equal("2.3283064365387E-10", string::format("{}", 0.00000000023283064365386962890625));
      assert::are_equal("1.23456789012345E-300", string::format("{}", 1.23456789012345E-300));
      assert::are_equal("1.23456789012346", string::format("{}", 1.2345678901234565));
      assert::are_equal("4.94065645841247E-324", string::format("{}", double_object::epsilon));
      assert::are_equal("nan", string::format("{}", double_object::NaN));
      assert::are_equal("-inf", string::format("{}", double_object::negative_infinity));
      assert::are_equal("inf", string::format("{}", double_object::positive_infinity));
    }
    
    auto test_method_(to_string) {
      assert::are_equal("0", double_object(0.0).to_string());
      assert::are_equal("1", double_object(1.0).to_string());
      assert::are_equal("255", double_object(255.0).to_string());
      assert::are_equal("4294967295", double_object(4294967295.0).to_string());
      assert::are_equal("0.00390625", double_object(0.00390625).to_string());
      assert::are_equal("2.3283064365387E-10", double_object(0.00000000023283064365386962890625).to_string());
      assert::are_equal("1.23456789012345E-300", double_object(1.23456789012345E-300).to_string());
      assert::are_equal("1.23456789012346", double_object(1.2345678901234565).to_string());
      assert::are_equal("4.94065645841247E-324", double_object(double_object::epsilon).to_string());
      assert::are_equal("nan", double_object(double_object::NaN).to_string());
      assert::are_equal("-inf", double_object(double_object::negative_infinity).to_string());
      assert::are_equal("inf", double_object(double_object::positive_infinity).to_string());
    }
  };
}
