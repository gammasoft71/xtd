#include <xtd/math>
#include <xtd/single_object>
#include <xtd/overflow_exception>
#include <xtd/using>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(single_object_tests) {
    auto test_method_(epsilon) {
      assert::are_equal(1.401298E-45f, single_object::epsilon);
    }
    
    auto test_method_(max_value) {
      assert::are_equal(std::numeric_limits<float>::max(), single_object::max_value);
    }
    
    auto test_method_(min_value) {
      assert::are_equal(std::numeric_limits<float>::lowest(), single_object::min_value);
    }
    
    auto test_method_(NaN) {
      assert::is_NaN(single_object::NaN);
    }
    
    auto test_method_(negative_infinity) {
      assert::are_equal(-std::numeric_limits<float>::infinity(), single_object::negative_infinity);
    }
    
    auto test_method_(positive_infinity) {
      assert::are_equal(std::numeric_limits<float>::infinity(), single_object::positive_infinity);
    }
    
    auto test_method_(is_infinity) {
      assert::is_false(single_object::is_infinity(0.0f));
      assert::is_false(single_object::is_infinity(1.0f));
      assert::is_false(single_object::is_infinity(255.0f));
      assert::is_false(single_object::is_infinity(4294967295.0f));
      assert::is_false(single_object::is_infinity(0.00390625f));
      assert::is_false(single_object::is_infinity(0.00000000023283064365386962890625f));
      assert::is_false(single_object::is_infinity(1.2345E-35f));
      assert::is_false(single_object::is_infinity(1.2345678901234565f));
      assert::is_false(single_object::is_infinity(1.23456789E+35f));
      assert::is_false(single_object::is_infinity(single_object::epsilon));
      assert::is_false(single_object::is_infinity(single_object::min_value));
      assert::is_false(single_object::is_infinity(single_object::max_value));
      assert::is_false(single_object::is_infinity(single_object::NaN));
      assert::is_true(single_object::is_infinity(single_object::negative_infinity));
      assert::is_true(single_object::is_infinity(single_object::positive_infinity));
    }
    
    auto test_method_(is_negative_infinity) {
      assert::is_false(single_object::is_negative_infinity(0.0f));
      assert::is_false(single_object::is_negative_infinity(1.0f));
      assert::is_false(single_object::is_negative_infinity(255.0f));
      assert::is_false(single_object::is_negative_infinity(4294967295.0f));
      assert::is_false(single_object::is_negative_infinity(0.00390625f));
      assert::is_false(single_object::is_negative_infinity(0.00000000023283064365386962890625f));
      assert::is_false(single_object::is_negative_infinity(1.2345E-35f));
      assert::is_false(single_object::is_negative_infinity(1.2345678901234565f));
      assert::is_false(single_object::is_negative_infinity(1.23456789E+35f));
      assert::is_false(single_object::is_negative_infinity(single_object::epsilon));
      assert::is_false(single_object::is_negative_infinity(single_object::min_value));
      assert::is_false(single_object::is_negative_infinity(single_object::max_value));
      assert::is_false(single_object::is_negative_infinity(single_object::NaN));
      assert::is_true(single_object::is_negative_infinity(single_object::negative_infinity));
      assert::is_false(single_object::is_negative_infinity(single_object::positive_infinity));
    }
    
    auto test_method_(is_positive_infinity) {
      assert::is_false(single_object::is_positive_infinity(0.0f));
      assert::is_false(single_object::is_positive_infinity(1.0f));
      assert::is_false(single_object::is_positive_infinity(255.0f));
      assert::is_false(single_object::is_positive_infinity(4294967295.0f));
      assert::is_false(single_object::is_positive_infinity(0.00390625f));
      assert::is_false(single_object::is_positive_infinity(0.00000000023283064365386962890625f));
      assert::is_false(single_object::is_positive_infinity(1.2345E-35f));
      assert::is_false(single_object::is_positive_infinity(1.2345678901234565f));
      assert::is_false(single_object::is_positive_infinity(1.23456789E+35f));
      assert::is_false(single_object::is_positive_infinity(single_object::epsilon));
      assert::is_false(single_object::is_positive_infinity(single_object::min_value));
      assert::is_false(single_object::is_positive_infinity(single_object::max_value));
      assert::is_false(single_object::is_positive_infinity(single_object::NaN));
      assert::is_false(single_object::is_positive_infinity(single_object::negative_infinity));
      assert::is_true(single_object::is_positive_infinity(single_object::positive_infinity));
    }
    
    auto test_method_(is_NaN) {
      assert::is_false(single_object::is_NaN(0.0f));
      assert::is_false(single_object::is_NaN(1.0f));
      assert::is_false(single_object::is_NaN(255.0f));
      assert::is_false(single_object::is_NaN(4294967295.0f));
      assert::is_false(single_object::is_NaN(0.00390625f));
      assert::is_false(single_object::is_NaN(0.00000000023283064365386962890625f));
      assert::is_false(single_object::is_NaN(1.2345E-35f));
      assert::is_false(single_object::is_NaN(1.2345678901234565f));
      assert::is_false(single_object::is_NaN(1.23456789E+35f));
      assert::is_false(single_object::is_NaN(single_object::epsilon));
      assert::is_false(single_object::is_NaN(single_object::min_value));
      assert::is_false(single_object::is_NaN(single_object::max_value));
      assert::is_true(single_object::is_NaN(single_object::NaN));
      assert::is_false(single_object::is_NaN(single_object::negative_infinity));
      assert::is_false(single_object::is_NaN(single_object::positive_infinity));
    }
    
    auto test_method_(format) {
      assert::are_equal("0", string::format("{}", 0.0f));
      assert::are_equal("1", string::format("{}", 1.0f));
      assert::are_equal("65535", string::format("{}", 65535.0f));
      assert::are_equal("0.00390625", string::format("{}", 0.00390625f));
      assert::are_equal("2.328306E-10", string::format("{}", 0.00000000023283064365386962890625f));
      assert::are_equal("1.2345E-35", string::format("{}", 1.2345E-35f));
      assert::are_equal("1.234567", string::format("{}", 1.2345671f));
      assert::are_equal("1.234568E+35", string::format("{}", 1.23456789E+35f));
      assert::are_equal("1.401298E-45", string::format("{}", single_object::epsilon));
      assert::are_equal("-3.402823E+38", string::format("{}", single_object::min_value));
      assert::are_equal("3.402823E+38", string::format("{}", single_object::max_value));
      assert::are_equal("nan", string::format("{}", single_object::NaN));
      assert::are_equal("-inf", string::format("{}", single_object::negative_infinity));
      assert::are_equal("inf", string::format("{}", single_object::positive_infinity));
    }
    
    auto test_method_(to_string) {
      assert::are_equal("0", single_object(0.0f).to_string());
      assert::are_equal("1", single_object(1.0f).to_string());
      assert::are_equal("65535", single_object(65535.0f).to_string());
      assert::are_equal("0.00390625", single_object(0.00390625f).to_string());
      assert::are_equal("2.328306E-10", single_object(0.00000000023283064365386962890625f).to_string());
      assert::are_equal("1.2345E-35", single_object(1.2345E-35f).to_string());
      assert::are_equal("1.234567", single_object(1.2345671f).to_string());
      assert::are_equal("1.234568E+35", single_object(1.23456789E+35f).to_string());
      assert::are_equal("1.401298E-45", single_object(single_object::epsilon).to_string());
      assert::are_equal("-3.402823E+38", single_object(single_object::min_value).to_string());
      assert::are_equal("3.402823E+38", single_object(single_object::max_value).to_string());
      assert::are_equal("nan", single_object(single_object::NaN).to_string());
      assert::are_equal("-inf", single_object(single_object::negative_infinity).to_string());
      assert::are_equal("inf", single_object(single_object::positive_infinity).to_string());
    }
  };
}
