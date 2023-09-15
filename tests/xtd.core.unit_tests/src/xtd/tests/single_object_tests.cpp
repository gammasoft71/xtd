#include <xtd/math>
#include <xtd/single_object>
#include <xtd/overflow_exception>
#include <xtd/using>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(single_object_tests) {
  public:
    void test_method_(epsilon) {
      assert::are_equal(1.401298E-45f, single_object::epsilon, csf_);
    }
    
    void test_method_(max_value) {
      assert::are_equal(numeric_limits<float>::max(), single_object::max_value, csf_);
    }
    
    void test_method_(min_value) {
      assert::are_equal(numeric_limits<float>::lowest(), single_object::min_value, csf_);
    }
    
    void test_method_(NaN) {
      assert::is_NaN(single_object::NaN, csf_);
    }
    
    void test_method_(negative_infinity) {
      assert::are_equal(-numeric_limits<float>::infinity(), single_object::negative_infinity, csf_);
    }
    
    void test_method_(positive_infinity) {
      assert::are_equal(numeric_limits<float>::infinity(), single_object::positive_infinity, csf_);
    }

    void test_method_(is_infinity) {
      assert::is_false(single_object::is_infinity(0.0f), csf_);
      assert::is_false(single_object::is_infinity(1.0f), csf_);
      assert::is_false(single_object::is_infinity(255.0f), csf_);
      assert::is_false(single_object::is_infinity(4294967295.0f), csf_);
      assert::is_false(single_object::is_infinity(0.00390625f), csf_);
      assert::is_false(single_object::is_infinity(0.00000000023283064365386962890625f), csf_);
      assert::is_false(single_object::is_infinity(1.2345E-35f), csf_);
      assert::is_false(single_object::is_infinity(1.2345678901234565f), csf_);
      assert::is_false(single_object::is_infinity(1.23456789E+35f), csf_);
      assert::is_false(single_object::is_infinity(single_object::epsilon), csf_);
      assert::is_false(single_object::is_infinity(single_object::min_value), csf_);
      assert::is_false(single_object::is_infinity(single_object::max_value), csf_);
      assert::is_false(single_object::is_infinity(single_object::NaN), csf_);
      assert::is_true(single_object::is_infinity(single_object::negative_infinity), csf_);
      assert::is_true(single_object::is_infinity(single_object::positive_infinity), csf_);
    }
    
    void test_method_(is_negative_infinity) {
      assert::is_false(single_object::is_negative_infinity(0.0f), csf_);
      assert::is_false(single_object::is_negative_infinity(1.0f), csf_);
      assert::is_false(single_object::is_negative_infinity(255.0f), csf_);
      assert::is_false(single_object::is_negative_infinity(4294967295.0f), csf_);
      assert::is_false(single_object::is_negative_infinity(0.00390625f), csf_);
      assert::is_false(single_object::is_negative_infinity(0.00000000023283064365386962890625f), csf_);
      assert::is_false(single_object::is_negative_infinity(1.2345E-35f), csf_);
      assert::is_false(single_object::is_negative_infinity(1.2345678901234565f), csf_);
      assert::is_false(single_object::is_negative_infinity(1.23456789E+35f), csf_);
      assert::is_false(single_object::is_negative_infinity(single_object::epsilon), csf_);
      assert::is_false(single_object::is_negative_infinity(single_object::min_value), csf_);
      assert::is_false(single_object::is_negative_infinity(single_object::max_value), csf_);
      assert::is_false(single_object::is_negative_infinity(single_object::NaN), csf_);
      assert::is_true(single_object::is_negative_infinity(single_object::negative_infinity), csf_);
      assert::is_false(single_object::is_negative_infinity(single_object::positive_infinity), csf_);
    }
    
    void test_method_(is_positive_infinity) {
      assert::is_false(single_object::is_positive_infinity(0.0f), csf_);
      assert::is_false(single_object::is_positive_infinity(1.0f), csf_);
      assert::is_false(single_object::is_positive_infinity(255.0f), csf_);
      assert::is_false(single_object::is_positive_infinity(4294967295.0f), csf_);
      assert::is_false(single_object::is_positive_infinity(0.00390625f), csf_);
      assert::is_false(single_object::is_positive_infinity(0.00000000023283064365386962890625f), csf_);
      assert::is_false(single_object::is_positive_infinity(1.2345E-35f), csf_);
      assert::is_false(single_object::is_positive_infinity(1.2345678901234565f), csf_);
      assert::is_false(single_object::is_positive_infinity(1.23456789E+35f), csf_);
      assert::is_false(single_object::is_positive_infinity(single_object::epsilon), csf_);
      assert::is_false(single_object::is_positive_infinity(single_object::min_value), csf_);
      assert::is_false(single_object::is_positive_infinity(single_object::max_value), csf_);
      assert::is_false(single_object::is_positive_infinity(single_object::NaN), csf_);
      assert::is_false(single_object::is_positive_infinity(single_object::negative_infinity), csf_);
      assert::is_true(single_object::is_positive_infinity(single_object::positive_infinity), csf_);
    }
    
    void test_method_(is_NaN) {
      assert::is_false(single_object::is_NaN(0.0f), csf_);
      assert::is_false(single_object::is_NaN(1.0f), csf_);
      assert::is_false(single_object::is_NaN(255.0f), csf_);
      assert::is_false(single_object::is_NaN(4294967295.0f), csf_);
      assert::is_false(single_object::is_NaN(0.00390625f), csf_);
      assert::is_false(single_object::is_NaN(0.00000000023283064365386962890625f), csf_);
      assert::is_false(single_object::is_NaN(1.2345E-35f), csf_);
      assert::is_false(single_object::is_NaN(1.2345678901234565f), csf_);
      assert::is_false(single_object::is_NaN(1.23456789E+35f), csf_);
      assert::is_false(single_object::is_NaN(single_object::epsilon), csf_);
      assert::is_false(single_object::is_NaN(single_object::min_value), csf_);
      assert::is_false(single_object::is_NaN(single_object::max_value), csf_);
      assert::is_true(single_object::is_NaN(single_object::NaN), csf_);
      assert::is_false(single_object::is_NaN(single_object::negative_infinity), csf_);
      assert::is_false(single_object::is_NaN(single_object::positive_infinity), csf_);
    }
    
    void test_method_(format) {
      assert::are_equal("0", ustring::format("{}", 0.0f), csf_);
      assert::are_equal("1", ustring::format("{}", 1.0f), csf_);
      assert::are_equal("65535", ustring::format("{}", 65535.0f), csf_);
      assert::are_equal("0.00390625", ustring::format("{}", 0.00390625f), csf_);
      assert::are_equal("2.328306E-10", ustring::format("{}", 0.00000000023283064365386962890625f), csf_);
      assert::are_equal("1.2345E-35", ustring::format("{}", 1.2345E-35f), csf_);
      assert::are_equal("1.234567", ustring::format("{}", 1.2345671f), csf_);
      assert::are_equal("1.234568E+35", ustring::format("{}", 1.23456789E+35f), csf_);
      assert::are_equal("1.4013e-45", ustring::format("{}", single_object::epsilon), csf_);
      assert::are_equal("-3.40282e+38", ustring::format("{}", single_object::min_value), csf_);
      assert::are_equal("3.40282e+38", ustring::format("{}", single_object::max_value), csf_);
      assert::are_equal("nan", ustring::format("{}", single_object::NaN), csf_);
      assert::are_equal("-inf", ustring::format("{}", single_object::negative_infinity), csf_);
      assert::are_equal("inf", ustring::format("{}", single_object::positive_infinity), csf_);
    }
    
    void test_method_(to_string) {
      assert::are_equal("0", single_object(0.0f).to_string(), csf_);
      assert::are_equal("1", single_object(1.0f).to_string(), csf_);
      assert::are_equal("65535", single_object(65535.0f).to_string(), csf_);
      assert::are_equal("0.00390625", single_object(0.00390625f).to_string(), csf_);
      assert::are_equal("2.32831e-10", single_object(0.00000000023283064365386962890625f).to_string(), csf_);
      assert::are_equal("1.2345e-35", single_object(1.2345E-35f).to_string(), csf_);
      assert::are_equal("1.23457", single_object(1.2345671f).to_string(), csf_);
      assert::are_equal("1.23457e+35", single_object(1.23456789E+35f).to_string(), csf_);
      assert::are_equal("1.4013e-45", single_object(single_object::epsilon).to_string(), csf_);
      assert::are_equal("-3.40282e+38", single_object(single_object::min_value).to_string(), csf_);
      assert::are_equal("3.40282e+38", single_object(single_object::max_value).to_string(), csf_);
      assert::are_equal("nan", single_object(single_object::NaN).to_string(), csf_);
      assert::are_equal("-inf", single_object(single_object::negative_infinity).to_string(), csf_);
      assert::are_equal("inf", single_object(single_object::positive_infinity).to_string(), csf_);
    }
  };
}
