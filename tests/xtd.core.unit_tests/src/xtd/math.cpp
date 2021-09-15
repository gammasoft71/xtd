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
      assert::are_equal(2.7182818284590452354, math::e, csf_);
    }
    
    void test_method_(epsilon) {
      assert::are_equal(4.94066e-324, math::epsilon, csf_);
    }
    
    void test_method_(max_value) {
      assert::are_equal(numeric_limits<double>::max(), math::max_value, csf_);
    }
    
    void test_method_(min_value) {
      assert::are_equal(numeric_limits<double>::lowest(), math::min_value, csf_);
    }
    
    void test_method_(NaN) {
      assert::is_NaN(math::NaN, csf_);
    }
    
    void test_method_(negative_infinity) {
      assert::are_equal(-numeric_limits<double>::infinity(), math::negative_infinity, csf_);
    }
    
    void test_method_(pi) {
      assert::are_equal(3.14159265358979323846, math::pi, csf_);
    }
    
    void test_method_(positive_infinity) {
      assert::are_equal(numeric_limits<double>::infinity(), math::positive_infinity, csf_);
    }

    void test_method_(tau) {
      assert::are_equal(2.7182818284590451, math::tau, csf_);
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
      assert::are_equal(math::max_value, math::abs(math::max_value), csf_);
      assert::are_equal(1.6354E-16, math::abs(1.6354E-16), csf_);
      assert::are_equal(15.098123, math::abs(15.098123), csf_);
      assert::are_equal(.0, math::abs(.0), csf_);
      assert::are_equal(19.069713, math::abs(-19.069713), csf_);
      assert::are_equal(15.058e18, math::abs(-15.058e18), csf_);
      assert::are_equal(-math::min_value, math::abs(math::min_value), csf_);
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
      assert::are_equal(as<int16_t>(10328), math::abs(as<int16_t>(10328)), csf_);
      assert::are_equal(as<int16_t>(0), math::abs(as<int16_t>(0)), csf_);
      assert::are_equal(as<int16_t>(1476), math::abs(as<int16_t>(-1476)), csf_);
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
      assert::are_equal(as<int64_t>(109013), math::abs(as<int64_t>(109013)), csf_);
      assert::are_equal(as<int64_t>(0), math::abs(as<int64_t>(0)), csf_);
      assert::are_equal(as<int64_t>(6871982), math::abs(as<int64_t>(-6871982)), csf_);
      assert::throws<overflow_exception>([] {math::abs(numeric_limits<int64_t>::lowest());}, csf_);
    }
    
    void test_method_(abs_sbyte) {
      assert::are_equal(numeric_limits<sbyte_t>::max(), math::abs(numeric_limits<sbyte_t>::max()), csf_);
      assert::are_equal(as<sbyte_t>(98), math::abs(as<sbyte_t>(98)), csf_);
      assert::are_equal(as<sbyte_t>(0), math::abs(as<sbyte_t>(0)), csf_);
      assert::are_equal(as<sbyte_t>(32), math::abs(as<sbyte_t>(-32)), csf_);
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
      assert::is_NaN(math::atan(math::NaN), csf_);
      assert::are_equal(-1.5707963267949, math::atan(math::negative_infinity), .000000001, csf_);
      assert::are_equal(-1.41296513650674, math::atan(math::degrees_to_radians(-360)), .000000001, csf_);
      assert::are_equal(-1.36169168297116, math::atan(math::degrees_to_radians(-270)), .000000001, csf_);
      assert::are_equal(-1.26262725567891, math::atan(math::degrees_to_radians(-180)), .000000001, csf_);
      assert::are_equal(-1.00388482185389, math::atan(math::degrees_to_radians(-90)), .000000001, csf_);
      assert::are_equal(.0, math::atan(.0), csf_);
      assert::are_equal(1.00388482185389, math::atan(math::degrees_to_radians(90)), .000000001, csf_);
      assert::are_equal(1.26262725567891, math::atan(math::degrees_to_radians(180)), .000000001, csf_);
      assert::are_equal(1.36169168297116, math::atan(math::degrees_to_radians(270)), .000000001, csf_);
      assert::are_equal(1.41296513650674, math::atan(math::degrees_to_radians(360)), .000000001, csf_);
      assert::are_equal(1.5707963267949, math::atan(math::positive_infinity), .000000001, csf_);
    }
    
    void test_method_(atan2) {
      assert::are_equal(0.463647609000806, math::atan2(1, 2), .000000000000001, csf_);
      assert::are_equal(0.839287844473872, math::atan2(127, 114), .000000000000001, csf_);
      assert::are_equal(0, math::atan2(0, 1), csf_);
      assert::are_equal(math::pi, math::atan2(0, -1), csf_);
      assert::are_equal(math::pi / 2, math::atan2(1, 0), csf_);
      assert::are_equal(-math::pi / 2, math::atan2(-1, 0), csf_);
      assert::is_NaN(math::atan2(math::NaN, 1), csf_);
      assert::is_NaN(math::atan2(1, math::NaN), csf_);
      assert::is_NaN(math::atan2(math::positive_infinity, math::positive_infinity), csf_);
      assert::is_NaN(math::atan2(math::positive_infinity, math::negative_infinity), csf_);
      assert::is_NaN(math::atan2(math::negative_infinity, math::negative_infinity), csf_);
      assert::is_NaN(math::atan2(math::negative_infinity, math::positive_infinity), csf_);
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
      assert::is_NaN(math::cos(math::NaN), csf_);
      assert::is_NaN(math::cos(math::negative_infinity), csf_);
      assert::is_NaN(math::cos(math::positive_infinity), csf_);
    }
    
    void test_method_(cosh) {
      assert::are_equal(1, math::cosh(0.0), csf_);
      assert::are_equal(10.0676619957778, math::cosh(3.0), .0000000000001, csf_);
      assert::are_equal(11013.2329201033, math::cosh(10.0), .0000000001, csf_);
      assert::is_true(math::is_positive_infinity(math::cosh(math::positive_infinity)), csf_);
      assert::is_true(math::is_positive_infinity(math::cosh(math::negative_infinity)), csf_);
      assert::is_NaN(math::cosh(math::NaN), csf_);
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

    void test_method_(div_rem_int32) {
      using_(int32_t remainder = 0) {
        assert::are_equal(1073741, math::div_rem(numeric_limits<int32_t>::max(), as<int32_t>(2000), remainder), csf_);
        assert::are_equal(1647, remainder, csf_);
      }
      
      using_(int32_t remainder = 0) {
        assert::are_equal(6, math::div_rem(as<int32_t>(13952), as<int32_t>(2000), remainder), csf_);
        assert::are_equal(1952, remainder, csf_);
      }
      
      using_(int32_t remainder = 0) {
        assert::are_equal(0, math::div_rem(as<int32_t>(0), as<int32_t>(2000), remainder), csf_);
        assert::are_equal(0, remainder, csf_);
      }
      
      using_(int32_t remainder = 0) {
        assert::are_equal(-7, math::div_rem(as<int32_t>(-14032), as<int32_t>(2000), remainder), csf_);
        assert::are_equal(-32, remainder, csf_);
      }
      
      using_(int32_t remainder = 0) {
        assert::are_equal(-1073741, math::div_rem(numeric_limits<int32_t>::lowest(), as<int32_t>(2000), remainder), csf_);
        assert::are_equal(-1648, remainder, csf_);
      }
      
      using_(int32_t remainder = 0) {
        assert::are_equal(-1073741, math::div_rem(numeric_limits<int32_t>::max(), as<int32_t>(-2000), remainder), csf_);
        assert::are_equal(1647, remainder, csf_);
      }
      
      using_(int32_t remainder = 0) {
        assert::are_equal(-6, math::div_rem(as<int32_t>(13952), as<int32_t>(-2000), remainder), csf_);
        assert::are_equal(1952, remainder, csf_);
      }
      
      using_(int32_t remainder = 0) {
        assert::are_equal(0, math::div_rem(as<int32_t>(0), as<int32_t>(-2000), remainder), csf_);
        assert::are_equal(0, remainder, csf_);
      }
      
      using_(int32_t remainder = 0) {
        assert::are_equal(7, math::div_rem(as<int32_t>(-14032), as<int32_t>(-2000), remainder), csf_);
        assert::are_equal(-32, remainder, csf_);
      }
      
      using_(int32_t remainder = 0) {
        assert::are_equal(1073741, math::div_rem(numeric_limits<int32_t>::lowest(), as<int32_t>(-2000), remainder), csf_);
        assert::are_equal(-1648, remainder, csf_);
      }
    }
    
    void test_method_(div_rem_int64) {
      using_(int64_t remainder = 0) {
        assert::are_equal(4611686018427387LL, math::div_rem(numeric_limits<int64_t>::max(), as<int64_t>(2000), remainder), csf_);
        assert::are_equal(1807, remainder, csf_);
      }
      
      using_(int64_t remainder = 0) {
        assert::are_equal(6, math::div_rem(as<int64_t>(13952), as<int64_t>(2000), remainder), csf_);
        assert::are_equal(1952, remainder, csf_);
      }
      
      using_(int64_t remainder = 0) {
        assert::are_equal(0, math::div_rem(as<int64_t>(0), as<int64_t>(2000), remainder), csf_);
        assert::are_equal(0, remainder, csf_);
      }
      
      using_(int64_t remainder = 0) {
        assert::are_equal(-7, math::div_rem(as<int64_t>(-14032), as<int64_t>(2000), remainder), csf_);
        assert::are_equal(-32, remainder, csf_);
      }
      
      using_(int64_t remainder = 0) {
        assert::are_equal(-4611686018427387LL, math::div_rem(numeric_limits<int64_t>::lowest(), as<int64_t>(2000), remainder), csf_);
        assert::are_equal(-1808, remainder, csf_);
      }
      
      using_(int64_t remainder = 0) {
        assert::are_equal(-4611686018427387LL, math::div_rem(numeric_limits<int64_t>::max(), as<int64_t>(-2000), remainder), csf_);
        assert::are_equal(1807, remainder, csf_);
      }
      
      using_(int64_t remainder = 0) {
        assert::are_equal(-6, math::div_rem(as<int64_t>(13952), as<int64_t>(-2000), remainder), csf_);
        assert::are_equal(1952, remainder, csf_);
      }
      
      using_(int64_t remainder = 0) {
        assert::are_equal(0, math::div_rem(as<int64_t>(0), as<int64_t>(-2000), remainder), csf_);
        assert::are_equal(0, remainder, csf_);
      }
      
      using_(int64_t remainder = 0) {
        assert::are_equal(7, math::div_rem(as<int64_t>(-14032), as<int64_t>(-2000), remainder), csf_);
        assert::are_equal(-32, remainder, csf_);
      }
      
      using_(int64_t remainder = 0) {
        assert::are_equal(4611686018427387LL, math::div_rem(numeric_limits<int64_t>::lowest(), as<int64_t>(-2000), remainder), csf_);
        assert::are_equal(-1808, remainder, csf_);
      }
    }

    void test_method_(exp) {
      assert::are_equal(1.0, math::exp(0.0), csf_);
      assert::are_equal(148.413159, math::exp(5.0), .000001, csf_);
      assert::is_NaN(math::exp(math::NaN), csf_);
      assert::is_true(math::is_positive_infinity(math::exp(math::positive_infinity)), csf_);
      assert::are_equal(0.0, math::exp(math::negative_infinity), csf_);
    }
    
    void test_method_(ieee_remainder) {
      assert::are_equal(-1.0, math::ieee_remainder(3.0, 2.0), csf_);
      assert::are_equal(0.0, math::ieee_remainder(4.0, 2.0), csf_);
      assert::are_equal(1.0, math::ieee_remainder(10.0, 3.0), csf_);
      assert::are_equal(-1.0, math::ieee_remainder(11.0, 3.0), csf_);
      assert::are_equal(-1.0, math::ieee_remainder(27.0, 4.0), csf_);
      assert::are_equal(-2.0, math::ieee_remainder(28.0, 5.0), csf_);
      assert::are_equal(1.8, math::ieee_remainder(17.8, 4.0), .000000000000001, csf_);
      assert::are_equal(1.4, math::ieee_remainder(17.8, 4.1), .00000000000001, csf_);
      assert::are_equal(0.0999999999999979, math::ieee_remainder(-16.3, 4.1), .000000000000001, csf_);
      assert::are_equal(1.4, math::ieee_remainder(17.8, -4.1), .00000000000001, csf_);
      assert::are_equal(-1.4, math::ieee_remainder(-17.8, -4.1), .00000000000001, csf_);
      assert::is_NaN(math::ieee_remainder(12.0, 0.0), csf_);
    }
    
    void test_method_(floor) {
      assert::are_equal(7.0, math::floor(7.03), csf_);
      assert::are_equal(7.0, math::floor(7.64), csf_);
      assert::are_equal(0.0, math::floor(0.12), csf_);
      assert::are_equal(-1.0, math::floor(-0.12), csf_);
      assert::are_equal(-8.0, math::floor(-7.1), csf_);
      assert::are_equal(-8.0, math::floor(-7.6), csf_);
    }

    void test_method_(is_infinity) {
      assert::is_false(math::is_infinity(0.0), csf_);
      assert::is_false(math::is_infinity(1.0), csf_);
      assert::is_false(math::is_infinity(255.0), csf_);
      assert::is_false(math::is_infinity(4294967295.0), csf_);
      assert::is_false(math::is_infinity(0.00390625), csf_);
      assert::is_false(math::is_infinity(0.00000000023283064365386962890625), csf_);
      assert::is_false(math::is_infinity(1.23456789012345E-300), csf_);
      assert::is_false(math::is_infinity(1.2345678901234565), csf_);
      assert::is_false(math::is_infinity(1.23456789012345678E+300), csf_);
      assert::is_false(math::is_infinity(math::epsilon), csf_);
      assert::is_false(math::is_infinity(math::min_value), csf_);
      assert::is_false(math::is_infinity(math::max_value), csf_);
      assert::is_false(math::is_infinity(math::NaN), csf_);
      assert::is_true(math::is_infinity(math::negative_infinity), csf_);
      assert::is_true(math::is_infinity(math::positive_infinity), csf_);
    }
    
    void test_method_(is_negative_infinity) {
      assert::is_false(math::is_negative_infinity(0.0), csf_);
      assert::is_false(math::is_negative_infinity(1.0), csf_);
      assert::is_false(math::is_negative_infinity(255.0), csf_);
      assert::is_false(math::is_negative_infinity(4294967295.0), csf_);
      assert::is_false(math::is_negative_infinity(0.00390625), csf_);
      assert::is_false(math::is_negative_infinity(0.00000000023283064365386962890625), csf_);
      assert::is_false(math::is_negative_infinity(1.23456789012345E-300), csf_);
      assert::is_false(math::is_negative_infinity(1.2345678901234565), csf_);
      assert::is_false(math::is_negative_infinity(1.23456789012345678E+300), csf_);
      assert::is_false(math::is_negative_infinity(math::epsilon), csf_);
      assert::is_false(math::is_negative_infinity(math::min_value), csf_);
      assert::is_false(math::is_negative_infinity(math::max_value), csf_);
      assert::is_false(math::is_negative_infinity(math::NaN), csf_);
      assert::is_true(math::is_negative_infinity(math::negative_infinity), csf_);
      assert::is_false(math::is_negative_infinity(math::positive_infinity), csf_);
    }
    
    void test_method_(is_positive_infinity) {
      assert::is_false(math::is_positive_infinity(0.0), csf_);
      assert::is_false(math::is_positive_infinity(1.0), csf_);
      assert::is_false(math::is_positive_infinity(255.0), csf_);
      assert::is_false(math::is_positive_infinity(4294967295.0), csf_);
      assert::is_false(math::is_positive_infinity(0.00390625), csf_);
      assert::is_false(math::is_positive_infinity(0.00000000023283064365386962890625), csf_);
      assert::is_false(math::is_positive_infinity(1.23456789012345E-300), csf_);
      assert::is_false(math::is_positive_infinity(1.2345678901234565), csf_);
      assert::is_false(math::is_positive_infinity(1.23456789012345678E+300), csf_);
      assert::is_false(math::is_positive_infinity(math::epsilon), csf_);
      assert::is_false(math::is_positive_infinity(math::min_value), csf_);
      assert::is_false(math::is_positive_infinity(math::max_value), csf_);
      assert::is_false(math::is_positive_infinity(math::NaN), csf_);
      assert::is_false(math::is_positive_infinity(math::negative_infinity), csf_);
      assert::is_true(math::is_positive_infinity(math::positive_infinity), csf_);
    }
    
    void test_method_(is_NaN) {
      assert::is_false(math::is_NaN(0.0), csf_);
      assert::is_false(math::is_NaN(1.0), csf_);
      assert::is_false(math::is_NaN(255.0), csf_);
      assert::is_false(math::is_NaN(4294967295.0), csf_);
      assert::is_false(math::is_NaN(0.00390625), csf_);
      assert::is_false(math::is_NaN(0.00000000023283064365386962890625), csf_);
      assert::is_false(math::is_NaN(1.23456789012345E-300), csf_);
      assert::is_false(math::is_NaN(1.2345678901234565), csf_);
      assert::is_false(math::is_NaN(1.23456789012345678E+300), csf_);
      assert::is_false(math::is_NaN(math::epsilon), csf_);
      assert::is_false(math::is_NaN(math::min_value), csf_);
      assert::is_false(math::is_NaN(math::max_value), csf_);
      assert::is_true(math::is_NaN(math::NaN), csf_);
      assert::is_false(math::is_NaN(math::negative_infinity), csf_);
      assert::is_false(math::is_NaN(math::positive_infinity), csf_);
    }

    void test_method_(log) {
      assert::are_equal(0.18232155679395459, math::log(1.2), 0.0000000000000001, csf_);
      assert::is_true(math::is_negative_infinity(math::log(0)), csf_);
      assert::is_NaN(math::log(-1), csf_);
      assert::is_NaN(math::log(math::NaN), csf_);
      assert::is_true(math::is_positive_infinity(math::log(math::positive_infinity)), csf_);
    }
    
    void test_method_(log_with_new_base) {
      assert::are_equal(3.0, math::log(8.0, 2.0), csf_);
      assert::are_equal(2.0, math::log(100.0, 10.0), csf_);
      assert::are_equal(4.0, math::log(65536, 16), csf_);
      assert::is_NaN(math::log(-1, 10), csf_);
      assert::is_NaN(math::log(100, -1), csf_);
      assert::is_NaN(math::log(2, 0), csf_);
      assert::is_NaN(math::log(2, math::positive_infinity), csf_);
      assert::is_NaN(math::log(math::NaN, 10), csf_);
      assert::is_NaN(math::log(100, math::NaN), csf_);
      assert::is_NaN(math::log(100, 1), csf_);
      assert::is_true(math::is_positive_infinity(math::log(0, 0.5)), csf_);
      assert::is_true(math::is_positive_infinity(math::log(math::positive_infinity, 2)), csf_);
      assert::is_true(math::is_negative_infinity(math::log(0, 2)), csf_);
      assert::is_true(math::is_negative_infinity(math::log(math::positive_infinity, 0.5)), csf_);
    }
    
    void test_method_(log10) {
      assert::are_equal(0.0, math::log10(1), csf_);
      assert::are_equal(1.0, math::log10(10), csf_);
      assert::are_equal(3.0, math::log10(1000), csf_);
      assert::is_true(math::is_negative_infinity(math::log10(0)), csf_);
      assert::is_NaN(math::log10(-1), csf_);
      assert::is_NaN(math::log10(math::NaN), csf_);
      assert::is_true(math::is_positive_infinity(math::log10(math::positive_infinity)), csf_);
    }

    void test_method_(max_byte) {
      assert::are_equal(52u, math::max(as<byte_t>(2), as<byte_t>(52)), csf_);
      assert::are_equal(22u, math::max(as<byte_t>(22), as<byte_t>(5))), csf_;
      assert::are_equal(16u, math::max(as<byte_t>(16), as<byte_t>(16)), csf_);
    }
    
    void test_method_(max_decimal) {
      assert::are_equal(52.0l, math::max(2.0l, 52.0l), csf_);
      assert::are_equal(22.0l, math::max(22.0l, 5.0l)), csf_;
      assert::are_equal(16.0l, math::max(16.0l, 16.0l), csf_);
    }

    void test_method_(max_double) {
      assert::are_equal(52, math::max(2.0, 52.0), csf_);
      assert::are_equal(22, math::max(22.0, 5.0), csf_);
      assert::are_equal(16, math::max(16.0, 16.0), csf_);
    }

    void test_method_(max_int16) {
      assert::are_equal(52, math::max(as<int16_t>(2), as<int16_t>(52)), csf_);
      assert::are_equal(22, math::max(as<int16_t>(22), as<int16_t>(5))), csf_;
      assert::are_equal(16, math::max(as<int16_t>(16), as<int16_t>(16)), csf_);
    }
    
    void test_method_(max_int32) {
      assert::are_equal(52, math::max(2, 52), csf_);
      assert::are_equal(22, math::max(22, 5), csf_);
      assert::are_equal(16, math::max(16, 16), csf_);
    }
    
    void test_method_(max_int64) {
      assert::are_equal(52, math::max(as<int64_t>(2), as<int64_t>(52)), csf_);
      assert::are_equal(22, math::max(as<int64_t>(22), as<int64_t>(5)), csf_);
      assert::are_equal(16, math::max(as<int64_t>(16), as<int64_t>(16)), csf_);
    }
    
    void test_method_(max_llong) {
      assert::are_equal(52, math::max(as<llong_t>(2), as<llong_t>(52)), csf_);
      assert::are_equal(22, math::max(as<llong_t>(22), as<llong_t>(5)), csf_);
      assert::are_equal(16, math::max(as<llong_t>(16), as<llong_t>(16)), csf_);
    }

    void test_method_(max_sbyte) {
      assert::are_equal(52, math::max(as<sbyte_t>(2), as<sbyte_t>(52)), csf_);
      assert::are_equal(22, math::max(as<sbyte_t>(22), as<sbyte_t>(5)), csf_);
      assert::are_equal(16, math::max(as<sbyte_t>(16), as<sbyte_t>(16)), csf_);
    }
    
    void test_method_(max_single) {
      assert::are_equal(52.0f, math::max(2.0f, 52.0f), csf_);
      assert::are_equal(22.0f, math::max(22.0f, 5.0f), csf_);
      assert::are_equal(16.0f, math::max(16.0f, 16.0f), csf_);
    }
    
    void test_method_(max_uint16) {
      assert::are_equal(52u, math::max(as<uint16_t>(2), as<uint16_t>(52)), csf_);
      assert::are_equal(22u, math::max(as<uint16_t>(22), as<uint16_t>(5)), csf_);
      assert::are_equal(16u, math::max(as<uint16_t>(16), as<uint16_t>(16)), csf_);
    }
    
    void test_method_(max_uint32) {
      assert::are_equal(52u, math::max(2u, 52u), csf_);
      assert::are_equal(22u, math::max(22u, 5u), csf_);
      assert::are_equal(16u, math::max(16u, 16u), csf_);
    }
    
    void test_method_(max_uint64) {
      assert::are_equal(52u, math::max(as<uint64_t>(2), as<uint64_t>(52)), csf_);
      assert::are_equal(22u, math::max(as<uint64_t>(22), as<uint64_t>(5)), csf_);
      assert::are_equal(16u, math::max(as<uint64_t>(16), as<uint64_t>(16)), csf_);
    }
    
    void test_method_(max_ullong) {
      assert::are_equal(52u, math::max(as<ullong_t>(2), as<ullong_t>(52)), csf_);
      assert::are_equal(22u, math::max(as<ullong_t>(22), as<ullong_t>(5)), csf_);
      assert::are_equal(16u, math::max(as<ullong_t>(16), as<ullong_t>(16)), csf_);
    }

    void test_method_(min_byte) {
      assert::are_equal(2u, math::min(as<byte_t>(2), as<byte_t>(52)), csf_);
      assert::are_equal(5u, math::min(as<byte_t>(22), as<byte_t>(5)), csf_);
      assert::are_equal(16u, math::min(as<byte_t>(16), as<byte_t>(16)), csf_);
    }
    
    void test_method_(min_decimal) {
      assert::are_equal(2.0l, math::min(2.0l, 52.0l), csf_);
      assert::are_equal(5.0l, math::min(22.0l, 5.0l), csf_);
      assert::are_equal(16.0l, math::min(16.0l, 16.0l), csf_);
    }
    
    void test_method_(min_double) {
      assert::are_equal(2.0, math::min(2.0, 52.0), csf_);
      assert::are_equal(5.0, math::min(22.0, 5.0), csf_);
      assert::are_equal(16.0, math::min(16.0, 16.0), csf_);
    }

    void test_method_(min_int16) {
      assert::are_equal(2, math::min(as<int16_t>(2), as<int16_t>(52)), csf_);
      assert::are_equal(5, math::min(as<int16_t>(22), as<int16_t>(5)), csf_);
      assert::are_equal(16, math::min(as<int16_t>(16), as<int16_t>(16)), csf_);
    }
    
    void test_method_(min_int32) {
      assert::are_equal(2, math::min(2, 52), csf_);
      assert::are_equal(5, math::min(22, 5), csf_);
      assert::are_equal(16, math::min(16, 16), csf_);
    }
    
    void test_method_(min_int64) {
      assert::are_equal(2, math::min(as<int64_t>(2), as<int64_t>(52)), csf_);
      assert::are_equal(5, math::min(as<int64_t>(22), as<int64_t>(5)), csf_);
      assert::are_equal(16, math::min(as<int64_t>(16), as<int64_t>(16)), csf_);
    }
    
    void test_method_(min_llong) {
      assert::are_equal(2, math::min(as<llong_t>(2), as<llong_t>(52)), csf_);
      assert::are_equal(5, math::min(as<llong_t>(22), as<llong_t>(5)), csf_);
      assert::are_equal(16, math::min(as<llong_t>(16), as<llong_t>(16)), csf_);
    }
    
    void test_method_(min_sbyte) {
      assert::are_equal(2, math::min(as<sbyte_t>(2), as<sbyte_t>(52)), csf_);
      assert::are_equal(5, math::min(as<sbyte_t>(22), as<sbyte_t>(5)), csf_);
      assert::are_equal(16, math::min(as<sbyte_t>(16), as<sbyte_t>(16)), csf_);
    }
    
    void test_method_(min_single) {
      assert::are_equal(2.0f, math::min(2.0f, 52.0f), csf_);
      assert::are_equal(5.0f, math::min(22.0f, 5.0f), csf_);
      assert::are_equal(16.0f, math::min(16.0f, 16.0f), csf_);
    }
    
    void test_method_(min_uint16) {
      assert::are_equal(2u, math::min(as<uint16_t>(2), as<uint16_t>(52)), csf_);
      assert::are_equal(5u, math::min(as<uint16_t>(22), as<uint16_t>(5)), csf_);
      assert::are_equal(16u, math::min(as<uint16_t>(16), as<uint16_t>(16)), csf_);
    }
    
    void test_method_(min_uint32) {
      assert::are_equal(2u, math::min(2u, 52u), csf_);
      assert::are_equal(5u, math::min(22u, 5u), csf_);
      assert::are_equal(16u, math::min(16u, 16u), csf_);
    }
    
    void test_method_(min_uint64) {
      assert::are_equal(2u, math::min(as<uint64_t>(2), as<uint64_t>(52)), csf_);
      assert::are_equal(5u, math::min(as<uint64_t>(22), as<uint64_t>(5)), csf_);
      assert::are_equal(16u, math::min(as<uint64_t>(16), as<uint64_t>(16)), csf_);
    }
    
    void test_method_(min_ullong) {
      assert::are_equal(2u, math::min(as<ullong_t>(2), as<ullong_t>(52)), csf_);
      assert::are_equal(5u, math::min(as<ullong_t>(22), as<ullong_t>(5)), csf_);
      assert::are_equal(16u, math::min(as<ullong_t>(16), as<ullong_t>(16)), csf_);
    }

    void test_method_(pow) {
      assert::are_equal(8, math::pow(2, 3), csf_);
      assert::is_NaN(math::pow(math::NaN, 3), csf_);
      assert::is_NaN(math::pow(2, math::NaN), csf_);
      assert::are_equal(1, math::pow(2, 0), csf_);
      assert::are_equal(0, math::pow(math::negative_infinity, -1), csf_);
      assert::is_true(math::is_negative_infinity(math::pow(math::negative_infinity, 11)), csf_);
      assert::is_true(math::is_positive_infinity(math::pow(math::negative_infinity, 10)), csf_);
      assert::is_NaN(math::pow(-1, 0.5), csf_);
      assert::is_true(math::is_positive_infinity(math::pow(0, math::negative_infinity)), csf_);
      assert::are_equal(0, math::pow(0, math::positive_infinity), csf_);
      assert::are_equal(0, math::pow(-2, math::negative_infinity), csf_);
      assert::are_equal(0, math::pow(2, math::negative_infinity), csf_);
      assert::is_true(math::is_positive_infinity(math::pow(-2, math::positive_infinity)), csf_);
      assert::is_true(math::is_positive_infinity(math::pow(2, math::positive_infinity)), csf_);
      assert::is_true(math::is_positive_infinity(math::pow(0, -1)), csf_);
      assert::are_equal(0, math::pow(0, 1), csf_);
      assert::are_equal(1, math::pow(1, 3), csf_);
      assert::are_equal(0, math::pow(math::positive_infinity, -1), csf_);
      assert::is_true(math::is_positive_infinity(math::pow(math::positive_infinity, 1)), csf_);
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

    void test_method_(round) {
      assert::are_equal(11.0, math::round(11.1), csf_);
      assert::are_equal(11.0, math::round(11.4), csf_);
      assert::are_equal(12.0, math::round(11.5), csf_);
      assert::are_equal(12.0, math::round(11.9), csf_);
    }
    
    void test_method_(round_decimals) {
      assert::are_equal(11.58, math::round(11.581, 2), csf_);
      assert::are_equal(11.58, math::round(11.584, 2), csf_);
      assert::are_equal(11.59, math::round(11.585, 2), csf_);
      assert::are_equal(11.59, math::round(11.589, 2), csf_);
    }
  };
}
