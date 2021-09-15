#include <xtd/math.h>
#include <xtd/xtd.tunit>
#include <limits>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_math) {
  public:
    void test_method_(e) {
      assert::are_equal(2.7182818284590452354, math::e);
    }

    void test_method_(pi) {
      assert::are_equal(3.14159265358979323846, math::pi);
    }

    void test_method_(tau) {
      assert::are_equal(2.7182818284590451, math::tau);
    }

    void test_method_(abs_decimal) {
      assert::are_equal(numeric_limits<decimal_t>::max(), math::abs(numeric_limits<decimal_t>::max()), csf_);
      assert::are_equal(1.6354E-16l, math::abs(1.6354E-16l), csf_);
      assert::are_equal(15.098123l, math::abs(15.098123l), csf_);
      assert::are_equal(.0l, math::abs(.0), csf_);
      assert::are_equal(19.069713l, math::abs(-19.069713l), csf_);
      assert::are_equal(15.058e18l, math::abs(-15.058e18l), csf_);
      assert::are_equal(-numeric_limits<decimal_t>::lowest(), math::abs(numeric_limits<decimal_t>::lowest()), csf_);
    }

    void test_method_(abs_double) {
      assert::are_equal(numeric_limits<double>::max(), math::abs(numeric_limits<double>::max()), csf_);
      assert::are_equal(1.6354E-16, math::abs(1.6354E-16), csf_);
      assert::are_equal(15.098123, math::abs(15.098123), csf_);
      assert::are_equal(.0, math::abs(.0), csf_);
      assert::are_equal(19.069713, math::abs(-19.069713), csf_);
      assert::are_equal(15.058e18, math::abs(-15.058e18), csf_);
      assert::are_equal(-numeric_limits<double>::lowest(), math::abs(numeric_limits<double>::lowest()), csf_);
    }

    void test_method_(abs_single) {
      assert::are_equal(numeric_limits<float>::max(), math::abs(numeric_limits<float>::max()), csf_);
      assert::are_equal(16.354e-12f, math::abs(16.354e-12f), csf_);
      assert::are_equal(15.098123f, math::abs(15.098123f), csf_);
      assert::are_equal(.0f, math::abs(.0f), csf_);
      assert::are_equal(19.069713f, math::abs(-19.069713f), csf_);
      assert::are_equal(15.058e17f, math::abs(-15.058e17f), csf_);
      assert::are_equal(-numeric_limits<float>::lowest(), math::abs(numeric_limits<float>::lowest()), csf_);
    }

    void test_method_(abs_int16) {
      assert::are_equal(numeric_limits<int16_t>::max(), math::abs(numeric_limits<int16_t>::max()), csf_);
      assert::are_equal(static_cast<int16_t>(10328), math::abs(static_cast<int16_t>(10328)), csf_);
      assert::are_equal(static_cast<int16_t>(0), math::abs(static_cast<int16_t>(0)), csf_);
      assert::are_equal(static_cast<int16_t>(1476), math::abs(static_cast<int16_t>(-1476)), csf_);
      assert::throws<overflow_exception>([] {math::abs(numeric_limits<int16_t>::lowest());}, csf_);
    }
    
    void test_method_(abs_int32) {
      assert::are_equal(numeric_limits<int32_t>::max(), math::abs(numeric_limits<int32_t>::max()), csf_);
      assert::are_equal(16921, math::abs(16921), csf_);
      assert::are_equal(0, math::abs(0), csf_);
      assert::are_equal(804128, math::abs(-804128), csf_);
      assert::throws<overflow_exception>([] {math::abs(numeric_limits<int32_t>::lowest());}, csf_);
    }
    
    void test_method_(abs_int64) {
      assert::are_equal(numeric_limits<int64_t>::max(), math::abs(numeric_limits<int64_t>::max()), csf_);
      assert::are_equal(static_cast<int64_t>(109013), math::abs(static_cast<int64_t>(109013)), csf_);
      assert::are_equal(static_cast<int64_t>(0), math::abs(static_cast<int64_t>(0)), csf_);
      assert::are_equal(static_cast<int64_t>(6871982), math::abs(static_cast<int64_t>(-6871982)), csf_);
      assert::throws<overflow_exception>([] {math::abs(numeric_limits<int64_t>::lowest());}, csf_);
    }
    
    void test_method_(abs_sbyte) {
      assert::are_equal(numeric_limits<sbyte_t>::max(), math::abs(numeric_limits<sbyte_t>::max()), csf_);
      assert::are_equal(static_cast<sbyte_t>(98), math::abs(static_cast<sbyte_t>(98)), csf_);
      assert::are_equal(static_cast<sbyte_t>(0), math::abs(static_cast<sbyte_t>(0)), csf_);
      assert::are_equal(static_cast<sbyte_t>(32), math::abs(static_cast<sbyte_t>(-32)), csf_);
      assert::throws<overflow_exception>([] {math::abs(numeric_limits<sbyte_t>::lowest());}, csf_);
    }
    
    void test_method_(abs_llong) {
      assert::are_equal(numeric_limits<llong_t>::max(), math::abs(numeric_limits<llong_t>::max()), csf_);
      assert::are_equal(109013ll, math::abs(109013ll), csf_);
      assert::are_equal(0ll, math::abs(0ll), csf_);
      assert::are_equal(6871982ll, math::abs(-6871982ll), csf_);
      assert::throws<overflow_exception>([] {math::abs(numeric_limits<llong_t>::lowest());}, csf_);
    }

    void test_method_(acos) {
      assert::is_NaN(math::acos(-1.1), csf_);
      assert::are_equal(3.14159265358979, math::acos(-1), .000000001, csf_);
      assert::are_equal(2.0943951023932, math::acos(-.5), .000000001, csf_);
      assert::are_equal(1.5707963267949, math::acos(.0), .000000001, csf_);
      assert::are_equal(1.0471975511966, math::acos(.5), .000000001, csf_);
      assert::are_equal(.0, math::acos(1), csf_);
      assert::is_NaN(math::acos(1.1), csf_);
    }
    
    void test_method_(asin) {
      assert::is_NaN(math::asin(-1.1), csf_);
      assert::are_equal(-1.5707963267949, math::asin(-1), .000000001, csf_);
      assert::are_equal(-0.523598775598299, math::asin(-.5), .000000001, csf_);
      assert::are_equal(.0, math::asin(.0), csf_);
      assert::are_equal(0.523598775598299, math::asin(.5), .000000001, csf_);
      assert::are_equal(1.5707963267949, math::asin(1), .000000001, csf_);
      assert::is_NaN(math::asin(1.1), csf_);
    }
    
    void test_method_(atan) {
      assert::is_NaN(math::atan(numeric_limits<double>::quiet_NaN()), csf_);
      assert::are_equal(-1.5707963267949, math::atan(-numeric_limits<double>::infinity()), .000000001, csf_);
      assert::are_equal(-1.41296513650674, math::atan(math::degrees_to_radians(-360)), .000000001, csf_);
      assert::are_equal(-1.36169168297116, math::atan(math::degrees_to_radians(-270)), .000000001, csf_);
      assert::are_equal(-1.26262725567891, math::atan(math::degrees_to_radians(-180)), .000000001, csf_);
      assert::are_equal(-1.00388482185389, math::atan(math::degrees_to_radians(-90)), .000000001, csf_);
      assert::are_equal(.0, math::atan(.0), csf_);
      assert::are_equal(1.00388482185389, math::atan(math::degrees_to_radians(90)), .000000001, csf_);
      assert::are_equal(1.26262725567891, math::atan(math::degrees_to_radians(180)), .000000001, csf_);
      assert::are_equal(1.36169168297116, math::atan(math::degrees_to_radians(270)), .000000001, csf_);
      assert::are_equal(1.41296513650674, math::atan(math::degrees_to_radians(360)), .000000001, csf_);
      assert::are_equal(1.5707963267949, math::atan(numeric_limits<double>::infinity()), .000000001, csf_);
    }
    
    void test_method_(atan2) {
      assert::are_equal(0.463647609000806, math::atan2(1, 2), .000000000000001, csf_);
      assert::are_equal(0.839287844473872, math::atan2(127, 114), .000000000000001, csf_);
      assert::are_equal(0, math::atan2(0, 1), csf_);
      assert::are_equal(math::pi, math::atan2(0, -1), csf_);
      assert::are_equal(math::pi / 2, math::atan2(1, 0), csf_);
      assert::are_equal(-math::pi / 2, math::atan2(-1, 0), csf_);
      assert::is_NaN(math::atan2(numeric_limits<double>::quiet_NaN(), 1), csf_);
      assert::is_NaN(math::atan2(1, numeric_limits<double>::quiet_NaN()), csf_);
      assert::is_NaN(math::atan2(numeric_limits<double>::infinity(), numeric_limits<double>::infinity()), csf_);
      assert::is_NaN(math::atan2(numeric_limits<double>::infinity(), -numeric_limits<double>::infinity()), csf_);
      assert::is_NaN(math::atan2(-numeric_limits<double>::infinity(), -numeric_limits<double>::infinity()), csf_);
      assert::is_NaN(math::atan2(-numeric_limits<double>::infinity(), numeric_limits<double>::infinity()), csf_);
    }

    void test_method_(big_mul) {
      assert::are_equal(4611686014132420609LL, math::big_mul(numeric_limits<int32_t>::max(), numeric_limits<int32_t>::max()), csf_);
    }

    void test_method_(ceiling) {
      assert::are_equal(8, math::ceiling(7.03), csf_);
      assert::are_equal(8, math::ceiling(7.64), csf_);
      assert::are_equal(1, math::ceiling(0.12), csf_);
      assert::are_equal(0, math::ceiling(-0.12), csf_);
      assert::are_equal(-7, math::ceiling(-7.1), csf_);
      assert::are_equal(-7, math::ceiling(-7.6), csf_);
    }
    
    void test_method_(cos) {
      assert::are_equal(1, math::cos(math::degrees_to_radians(0.0)), csf_);
      assert::are_equal(6.12303176911189E-17, math::cos(math::degrees_to_radians(90.0)), .0001, csf_);
      assert::is_NaN(math::cos(numeric_limits<double>::quiet_NaN()), csf_);
      assert::is_NaN(math::cos(-numeric_limits<double>::infinity()), csf_);
      assert::is_NaN(math::cos(numeric_limits<double>::infinity()), csf_);
    }
    
    void test_method_(cosh) {
      assert::are_equal(1, math::cosh(0.0), csf_);
      assert::are_equal(10.0676619957778, math::cosh(3.0), .0000000000001, csf_);
      assert::are_equal(11013.2329201033, math::cosh(10.0), .0000000001, csf_);
      assert::is_true(math::is_positive_infinity(math::cosh(numeric_limits<double>::infinity())), csf_);
      assert::is_true(math::is_positive_infinity(math::cosh(-numeric_limits<double>::infinity())), csf_);
      assert::is_NaN(math::cosh(numeric_limits<double>::quiet_NaN()), csf_);
    }

    void test_method_(degrees_to_radians) {
      assert::are_equal(-6.28318530717959, math::degrees_to_radians(-360.0), .00000000000001, csf_);
      assert::are_equal(-4.71238898038469, math::degrees_to_radians(-270.0), .00000000000001, csf_);
      assert::are_equal(-3.14159265358979, math::degrees_to_radians(-180.0), .0000000000001, csf_);
      assert::are_equal(-1.5707963267949, math::degrees_to_radians(-90.0), .0000000000001, csf_);
      assert::are_equal(0.0, math::degrees_to_radians(0.0), csf_);
      assert::are_equal(1.5707963267949, math::degrees_to_radians(90.0), .0000000000001, csf_);
      assert::are_equal(3.14159265358979, math::degrees_to_radians(180.0), .00000000000001, csf_);
      assert::are_equal(4.71238898038469, math::degrees_to_radians(270.0), .00000000000001, csf_);
      assert::are_equal(6.28318530717959, math::degrees_to_radians(360.0), .00000000000001, csf_);
    }
    
    void test_method_(radians_to_degrees) {
      assert::are_equal(-360.0, math::radians_to_degrees(-6.28318530717959), .000000001, csf_);
      assert::are_equal(-270.0, math::radians_to_degrees(-4.71238898038469), .000000001, csf_);
      assert::are_equal(-180.0, math::radians_to_degrees(-3.14159265358979), .000000001, csf_);
      assert::are_equal(-90.0, math::radians_to_degrees(-1.5707963267949), .000000001, csf_);
      assert::are_equal(0.0, math::radians_to_degrees(0.0), csf_);
      assert::are_equal(90.0, math::radians_to_degrees(1.5707963267949), .000000001, csf_);
      assert::are_equal(180.0, math::radians_to_degrees(3.14159265358979), .000000001, csf_);
      assert::are_equal(270.0, math::radians_to_degrees(4.71238898038469), .000000001, csf_);
      assert::are_equal(360.0, math::radians_to_degrees(6.28318530717959), .000000001, csf_);
    }
    
    void test_method_(radians_to_degrees_degrees_to_radians) {
      assert::are_equal(-360.0, math::radians_to_degrees(math::degrees_to_radians(-360.0)), csf_);
      assert::are_equal(-270.0, math::radians_to_degrees(math::degrees_to_radians(-270.0)), csf_);
      assert::are_equal(-180.0, math::radians_to_degrees(math::degrees_to_radians(-180.0)), csf_);
      assert::are_equal(-90.0, math::radians_to_degrees(math::degrees_to_radians(-90.0)), csf_);
      assert::are_equal(0.0, math::radians_to_degrees(math::degrees_to_radians(0.0)), csf_);
      assert::are_equal(90.0, math::radians_to_degrees(math::degrees_to_radians(90.0)), csf_);
      assert::are_equal(180.0, math::radians_to_degrees(math::degrees_to_radians(180.0)), csf_);
      assert::are_equal(270.0, math::radians_to_degrees(math::degrees_to_radians(270.0)), csf_);
      assert::are_equal(360.0, math::radians_to_degrees(math::degrees_to_radians(360.0)), csf_);
    }
  };
}
