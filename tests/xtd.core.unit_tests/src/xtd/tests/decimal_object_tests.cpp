#include <xtd/math>
#include <xtd/decimal_object>
#include <xtd/overflow_exception>
#include <xtd/using>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(decimal_object_tests) {
  public:
    void test_method_(epsilon) {
      assert::are_equal(0, decimal_object::epsilon, csf_);
    }
    
    void test_method_(max_value) {
      assert::are_equal(numeric_limits<decimal>::max(), decimal_object::max_value, csf_);
    }
    
    void test_method_(min_value) {
      assert::are_equal(numeric_limits<decimal>::lowest(), decimal_object::min_value, csf_);
    }
    
    void test_method_(NaN) {
      assert::is_NaN(decimal_object::NaN, csf_);
    }
    
    void test_method_(negative_infinity) {
      assert::are_equal(-numeric_limits<decimal>::infinity(), decimal_object::negative_infinity, csf_);
    }
    
    void test_method_(positive_infinity) {
      assert::are_equal(numeric_limits<decimal>::infinity(), decimal_object::positive_infinity, csf_);
    }

    void test_method_(is_infinity) {
      assert::is_false(decimal_object::is_infinity(0.0l), csf_);
      assert::is_false(decimal_object::is_infinity(1.0l), csf_);
      assert::is_false(decimal_object::is_infinity(255.0l), csf_);
      assert::is_false(decimal_object::is_infinity(4294967295.0l), csf_);
      assert::is_false(decimal_object::is_infinity(0.00390625l), csf_);
      assert::is_false(decimal_object::is_infinity(0.00000000023283064365386962890625l), csf_);
      assert::is_false(decimal_object::is_infinity(1.23456789012345E-300l), csf_);
      assert::is_false(decimal_object::is_infinity(1.2345678901234565l), csf_);
      assert::is_false(decimal_object::is_infinity(1.23456789012345678E+300l), csf_);
      assert::is_false(decimal_object::is_infinity(decimal_object::min_value), csf_);
      assert::is_false(decimal_object::is_infinity(decimal_object::max_value), csf_);
      assert::is_false(decimal_object::is_infinity(decimal_object::NaN), csf_);
      assert::is_true(decimal_object::is_infinity(decimal_object::negative_infinity), csf_);
      assert::is_true(decimal_object::is_infinity(decimal_object::positive_infinity), csf_);
    }
    
    void test_method_(is_negative_infinity) {
      assert::is_false(decimal_object::is_negative_infinity(0.0l), csf_);
      assert::is_false(decimal_object::is_negative_infinity(1.0l), csf_);
      assert::is_false(decimal_object::is_negative_infinity(255.0l), csf_);
      assert::is_false(decimal_object::is_negative_infinity(4294967295.0l), csf_);
      assert::is_false(decimal_object::is_negative_infinity(0.00390625l), csf_);
      assert::is_false(decimal_object::is_negative_infinity(0.00000000023283064365386962890625l), csf_);
      assert::is_false(decimal_object::is_negative_infinity(1.23456789012345E-300l), csf_);
      assert::is_false(decimal_object::is_negative_infinity(1.2345678901234565l), csf_);
      assert::is_false(decimal_object::is_negative_infinity(1.23456789012345678E+300l), csf_);
      assert::is_false(decimal_object::is_negative_infinity(decimal_object::min_value), csf_);
      assert::is_false(decimal_object::is_negative_infinity(decimal_object::max_value), csf_);
      assert::is_false(decimal_object::is_negative_infinity(decimal_object::NaN), csf_);
      assert::is_true(decimal_object::is_negative_infinity(decimal_object::negative_infinity), csf_);
      assert::is_false(decimal_object::is_negative_infinity(decimal_object::positive_infinity), csf_);
    }
    
    void test_method_(is_positive_infinity) {
      assert::is_false(decimal_object::is_positive_infinity(0.0l), csf_);
      assert::is_false(decimal_object::is_positive_infinity(1.0l), csf_);
      assert::is_false(decimal_object::is_positive_infinity(255.0l), csf_);
      assert::is_false(decimal_object::is_positive_infinity(4294967295.0l), csf_);
      assert::is_false(decimal_object::is_positive_infinity(0.00390625l), csf_);
      assert::is_false(decimal_object::is_positive_infinity(0.00000000023283064365386962890625l), csf_);
      assert::is_false(decimal_object::is_positive_infinity(1.23456789012345E-300l), csf_);
      assert::is_false(decimal_object::is_positive_infinity(1.2345678901234565l), csf_);
      assert::is_false(decimal_object::is_positive_infinity(1.23456789012345678E+300l), csf_);
      assert::is_false(decimal_object::is_positive_infinity(decimal_object::min_value), csf_);
      assert::is_false(decimal_object::is_positive_infinity(decimal_object::max_value), csf_);
      assert::is_false(decimal_object::is_positive_infinity(decimal_object::NaN), csf_);
      assert::is_false(decimal_object::is_positive_infinity(decimal_object::negative_infinity), csf_);
      assert::is_true(decimal_object::is_positive_infinity(decimal_object::positive_infinity), csf_);
    }
    
    void test_method_(is_NaN) {
      assert::is_false(decimal_object::is_NaN(0.0l), csf_);
      assert::is_false(decimal_object::is_NaN(1.0l), csf_);
      assert::is_false(decimal_object::is_NaN(255.0l), csf_);
      assert::is_false(decimal_object::is_NaN(4294967295.0l), csf_);
      assert::is_false(decimal_object::is_NaN(0.00390625l), csf_);
      assert::is_false(decimal_object::is_NaN(0.00000000023283064365386962890625l), csf_);
      assert::is_false(decimal_object::is_NaN(1.23456789012345E-300l), csf_);
      assert::is_false(decimal_object::is_NaN(1.2345678901234565l), csf_);
      assert::is_false(decimal_object::is_NaN(1.23456789012345678E+300l), csf_);
      assert::is_false(decimal_object::is_NaN(decimal_object::min_value), csf_);
      assert::is_false(decimal_object::is_NaN(decimal_object::max_value), csf_);
      assert::is_true(decimal_object::is_NaN(decimal_object::NaN), csf_);
      assert::is_false(decimal_object::is_NaN(decimal_object::negative_infinity), csf_);
      assert::is_false(decimal_object::is_NaN(decimal_object::positive_infinity), csf_);
    }
    
    void test_method_(format) {
      assert::are_equal("0", ustring::format("{}", 0.0l), csf_);
      assert::are_equal("1", ustring::format("{}", 1.0l), csf_);
      assert::are_equal("255", ustring::format("{}", 255.0l), csf_);
      assert::are_equal("4294967295", ustring::format("{}", 4294967295.0l), csf_);
      assert::are_equal("0.00390625", ustring::format("{}", 0.00390625l), csf_);
      assert::are_equal("2.3283064365387E-10", ustring::format("{}", 0.00000000023283064365386962890625l), csf_);
      assert::are_equal("1.23456789012345E-300", ustring::format("{}", 1.23456789012345E-300l), csf_);
      assert::are_equal("1.23456789012346", ustring::format("{}", 1.2345678901234565l), csf_);
      assert::are_equal("nan", ustring::format("{}", decimal_object::NaN), csf_);
      assert::are_equal("-inf", ustring::format("{}", decimal_object::negative_infinity), csf_);
      assert::are_equal("inf", ustring::format("{}", decimal_object::positive_infinity), csf_);
    }
    
    void test_method_(to_string) {
      assert::are_equal("0", decimal_object(0.0l).to_string(), csf_);
      assert::are_equal("1", decimal_object(1.0l).to_string(), csf_);
      assert::are_equal("255", decimal_object(255.0l).to_string(), csf_);
      assert::are_equal("4.29497e+09", decimal_object(4294967295.0l).to_string(), csf_);
      assert::are_equal("0.00390625", decimal_object(0.00390625l).to_string(), csf_);
      assert::are_equal("2.32831e-10", decimal_object(0.00000000023283064365386962890625l).to_string(), csf_);
      assert::are_equal("1.23457e-300", decimal_object(1.23456789012345E-300l).to_string(), csf_);
      assert::are_equal("1.23457", decimal_object(1.2345678901234565l).to_string(), csf_);
      assert::are_equal("nan", decimal_object(decimal_object::NaN).to_string(), csf_);
      assert::are_equal("-inf", decimal_object(decimal_object::negative_infinity).to_string(), csf_);
      assert::are_equal("inf", decimal_object(decimal_object::positive_infinity).to_string(), csf_);
    }
  };
}
