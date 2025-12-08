#include <xtd/math>
#include <xtd/decimal_object>
#include <xtd/overflow_exception>
#include <xtd/using>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(decimal_object_tests) {
    auto test_method_(epsilon) {
      assert::are_equal(0, decimal_object::epsilon);
    }
    
    auto test_method_(max_value) {
      assert::are_equal(std::numeric_limits<decimal>::max(), decimal_object::max_value);
    }
    
    auto test_method_(min_value) {
      assert::are_equal(std::numeric_limits<decimal>::lowest(), decimal_object::min_value);
    }
    
    auto test_method_(NaN) {
      assert::is_NaN(decimal_object::NaN);
    }
    
    auto test_method_(negative_infinity) {
      assert::are_equal(-std::numeric_limits<decimal>::infinity(), decimal_object::negative_infinity);
    }
    
    auto test_method_(positive_infinity) {
      assert::are_equal(std::numeric_limits<decimal>::infinity(), decimal_object::positive_infinity);
    }
    
    auto test_method_(is_infinity) {
      assert::is_false(decimal_object::is_infinity(0.0l));
      assert::is_false(decimal_object::is_infinity(1.0l));
      assert::is_false(decimal_object::is_infinity(255.0l));
      assert::is_false(decimal_object::is_infinity(4294967295.0l));
      assert::is_false(decimal_object::is_infinity(0.00390625l));
      assert::is_false(decimal_object::is_infinity(0.00000000023283064365386962890625l));
      assert::is_false(decimal_object::is_infinity(1.23456789012345E-300l));
      assert::is_false(decimal_object::is_infinity(1.2345678901234565l));
      assert::is_false(decimal_object::is_infinity(1.23456789012345678E+300l));
      assert::is_false(decimal_object::is_infinity(decimal_object::min_value));
      assert::is_false(decimal_object::is_infinity(decimal_object::max_value));
      assert::is_false(decimal_object::is_infinity(decimal_object::NaN));
      assert::is_true(decimal_object::is_infinity(decimal_object::negative_infinity));
      assert::is_true(decimal_object::is_infinity(decimal_object::positive_infinity));
    }
    
    auto test_method_(is_negative_infinity) {
      assert::is_false(decimal_object::is_negative_infinity(0.0l));
      assert::is_false(decimal_object::is_negative_infinity(1.0l));
      assert::is_false(decimal_object::is_negative_infinity(255.0l));
      assert::is_false(decimal_object::is_negative_infinity(4294967295.0l));
      assert::is_false(decimal_object::is_negative_infinity(0.00390625l));
      assert::is_false(decimal_object::is_negative_infinity(0.00000000023283064365386962890625l));
      assert::is_false(decimal_object::is_negative_infinity(1.23456789012345E-300l));
      assert::is_false(decimal_object::is_negative_infinity(1.2345678901234565l));
      assert::is_false(decimal_object::is_negative_infinity(1.23456789012345678E+300l));
      assert::is_false(decimal_object::is_negative_infinity(decimal_object::min_value));
      assert::is_false(decimal_object::is_negative_infinity(decimal_object::max_value));
      assert::is_false(decimal_object::is_negative_infinity(decimal_object::NaN));
      assert::is_true(decimal_object::is_negative_infinity(decimal_object::negative_infinity));
      assert::is_false(decimal_object::is_negative_infinity(decimal_object::positive_infinity));
    }
    
    auto test_method_(is_positive_infinity) {
      assert::is_false(decimal_object::is_positive_infinity(0.0l));
      assert::is_false(decimal_object::is_positive_infinity(1.0l));
      assert::is_false(decimal_object::is_positive_infinity(255.0l));
      assert::is_false(decimal_object::is_positive_infinity(4294967295.0l));
      assert::is_false(decimal_object::is_positive_infinity(0.00390625l));
      assert::is_false(decimal_object::is_positive_infinity(0.00000000023283064365386962890625l));
      assert::is_false(decimal_object::is_positive_infinity(1.23456789012345E-300l));
      assert::is_false(decimal_object::is_positive_infinity(1.2345678901234565l));
      assert::is_false(decimal_object::is_positive_infinity(1.23456789012345678E+300l));
      assert::is_false(decimal_object::is_positive_infinity(decimal_object::min_value));
      assert::is_false(decimal_object::is_positive_infinity(decimal_object::max_value));
      assert::is_false(decimal_object::is_positive_infinity(decimal_object::NaN));
      assert::is_false(decimal_object::is_positive_infinity(decimal_object::negative_infinity));
      assert::is_true(decimal_object::is_positive_infinity(decimal_object::positive_infinity));
    }
    
    auto test_method_(is_NaN) {
      assert::is_false(decimal_object::is_NaN(0.0l));
      assert::is_false(decimal_object::is_NaN(1.0l));
      assert::is_false(decimal_object::is_NaN(255.0l));
      assert::is_false(decimal_object::is_NaN(4294967295.0l));
      assert::is_false(decimal_object::is_NaN(0.00390625l));
      assert::is_false(decimal_object::is_NaN(0.00000000023283064365386962890625l));
      assert::is_false(decimal_object::is_NaN(1.23456789012345E-300l));
      assert::is_false(decimal_object::is_NaN(1.2345678901234565l));
      assert::is_false(decimal_object::is_NaN(1.23456789012345678E+300l));
      assert::is_false(decimal_object::is_NaN(decimal_object::min_value));
      assert::is_false(decimal_object::is_NaN(decimal_object::max_value));
      assert::is_true(decimal_object::is_NaN(decimal_object::NaN));
      assert::is_false(decimal_object::is_NaN(decimal_object::negative_infinity));
      assert::is_false(decimal_object::is_NaN(decimal_object::positive_infinity));
    }
    
    auto test_method_(format) {
      assert::are_equal("0", string::format("{}", 0.0l));
      assert::are_equal("1", string::format("{}", 1.0l));
      assert::are_equal("255", string::format("{}", 255.0l));
      assert::are_equal("4294967295", string::format("{}", 4294967295.0l));
      assert::are_equal("0.00390625", string::format("{}", 0.00390625l));
      assert::are_equal("2.3283064365387E-10", string::format("{}", 0.00000000023283064365386962890625l));
      assert::are_equal("1.23456789012345E-300", string::format("{}", 1.23456789012345E-300l));
      assert::are_equal("1.23456789012346", string::format("{}", 1.2345678901234565l));
      assert::are_equal("nan", string::format("{}", decimal_object::NaN));
      assert::are_equal("-inf", string::format("{}", decimal_object::negative_infinity));
      assert::are_equal("inf", string::format("{}", decimal_object::positive_infinity));
    }
    
    auto test_method_(to_string) {
      assert::are_equal("0", decimal_object(0.0l).to_string());
      assert::are_equal("1", decimal_object(1.0l).to_string());
      assert::are_equal("255", decimal_object(255.0l).to_string());
      assert::are_equal("4294967295", decimal_object(4294967295.0l).to_string());
      assert::are_equal("0.00390625", decimal_object(0.00390625l).to_string());
      assert::are_equal("2.3283064365387E-10", decimal_object(0.00000000023283064365386962890625l).to_string());
      assert::are_equal("1.23456789012345E-300", decimal_object(1.23456789012345E-300l).to_string());
      assert::are_equal("1.23456789012346", decimal_object(1.2345678901234565l).to_string());
      assert::are_equal("nan", decimal_object(decimal_object::NaN).to_string());
      assert::are_equal("-inf", decimal_object(decimal_object::negative_infinity).to_string());
      assert::are_equal("inf", decimal_object(decimal_object::positive_infinity).to_string());
    }
  };
}
