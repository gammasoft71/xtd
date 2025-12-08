#include <xtd/as>
#include <xtd/math>
#include <xtd/double_object>
#include <xtd/overflow_exception>
#include <xtd/block_scope>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(math_tests) {
    auto test_method_(e) {
      assert::are_equal(2.7182818284590452354, math::e);
    }
    
    auto test_method_(pi) {
      assert::are_equal(3.14159265358979323846, math::pi);
    }
    
    auto test_method_(tau) {
      assert::are_equal(2.7182818284590451, math::tau);
    }
    
    auto test_method_(abs_decimal) {
      assert::are_equal(std::numeric_limits<decimal>::max(), math::abs(std::numeric_limits<decimal>::max()));
      assert::are_equal(1.6354E-16l, math::abs(1.6354E-16l));
      assert::are_equal(15.098123l, math::abs(15.098123l));
      assert::are_equal(.0l, math::abs(.0));
      assert::are_equal(19.069713l, math::abs(-19.069713l));
      assert::are_equal(15.058e18l, math::abs(-15.058e18l));
      assert::are_equal(-std::numeric_limits<decimal>::lowest(), math::abs(std::numeric_limits<decimal>::lowest()));
    }
    
    auto test_method_(abs_double) {
      assert::are_equal(double_object::max_value, math::abs(double_object::max_value));
      assert::are_equal(1.6354E-16, math::abs(1.6354E-16));
      assert::are_equal(15.098123, math::abs(15.098123));
      assert::are_equal(.0, math::abs(.0));
      assert::are_equal(19.069713, math::abs(-19.069713));
      assert::are_equal(15.058e18, math::abs(-15.058e18));
      assert::are_equal(-double_object::min_value, math::abs(double_object::min_value));
    }
    
    auto test_method_(abs_single) {
      assert::are_equal(std::numeric_limits<float>::max(), math::abs(std::numeric_limits<float>::max()));
      assert::are_equal(16.354e-12f, math::abs(16.354e-12f));
      assert::are_equal(15.098123f, math::abs(15.098123f));
      assert::are_equal(.0f, math::abs(.0f));
      assert::are_equal(19.069713f, math::abs(-19.069713f));
      assert::are_equal(15.058e17f, math::abs(-15.058e17f));
      assert::are_equal(-std::numeric_limits<float>::lowest(), math::abs(std::numeric_limits<float>::lowest()));
    }
    
    auto test_method_(abs_int16) {
      assert::are_equal(std::numeric_limits<int16>::max(), math::abs(std::numeric_limits<int16>::max()));
      assert::are_equal(as<int16>(10328), math::abs(as<int16>(10328)));
      assert::are_equal(as<int16>(0), math::abs(as<int16>(0)));
      assert::are_equal(as<int16>(1476), math::abs(as<int16>(-1476)));
      assert::throws<overflow_exception>([] {math::abs(std::numeric_limits<int16>::lowest());});
    }
    
    auto test_method_(abs_int32) {
      assert::are_equal(std::numeric_limits<int32>::max(), math::abs(std::numeric_limits<int32>::max()));
      assert::are_equal(16921, math::abs(16921));
      assert::are_equal(0, math::abs(0));
      assert::are_equal(804128, math::abs(-804128));
      assert::throws<overflow_exception>([] {math::abs(std::numeric_limits<int32>::lowest());});
    }
    
    auto test_method_(abs_int64) {
      assert::are_equal(std::numeric_limits<int64>::max(), math::abs(std::numeric_limits<int64>::max()));
      assert::are_equal(as<int64>(109013), math::abs(as<int64>(109013)));
      assert::are_equal(as<int64>(0), math::abs(as<int64>(0)));
      assert::are_equal(as<int64>(6871982), math::abs(as<int64>(-6871982)));
      assert::throws<overflow_exception>([] {math::abs(std::numeric_limits<int64>::lowest());});
    }
    
    auto test_method_(abs_sbyte) {
      assert::are_equal(std::numeric_limits<sbyte>::max(), math::abs(std::numeric_limits<sbyte>::max()));
      assert::are_equal(as<sbyte>(98), math::abs(as<sbyte>(98)));
      assert::are_equal(as<sbyte>(0), math::abs(as<sbyte>(0)));
      assert::are_equal(as<sbyte>(32), math::abs(as<sbyte>(-32)));
      assert::throws<overflow_exception>([] {math::abs(std::numeric_limits<sbyte>::lowest());});
    }
    
    auto test_method_(abs_llong) {
      assert::are_equal(std::numeric_limits<slong>::max(), math::abs(std::numeric_limits<slong>::max()));
      assert::are_equal(109013ll, math::abs(109013ll));
      assert::are_equal(0ll, math::abs(0ll));
      assert::are_equal(6871982ll, math::abs(-6871982ll));
      assert::throws<overflow_exception>([] {math::abs(std::numeric_limits<slong>::lowest());});
    }
    
    auto test_method_(acos) {
      assert::is_NaN(math::acos(-1.1));
      assert::are_equal(3.14159265358979, math::acos(-1), .000000001);
      assert::are_equal(2.0943951023932, math::acos(-.5), .000000001);
      assert::are_equal(1.5707963267949, math::acos(.0), .000000001);
      assert::are_equal(1.0471975511966, math::acos(.5), .000000001);
      assert::are_equal(.0, math::acos(1));
      assert::is_NaN(math::acos(1.1));
    }
    
    auto test_method_(asin) {
      assert::is_NaN(math::asin(-1.1));
      assert::are_equal(-1.5707963267949, math::asin(-1), .000000001);
      assert::are_equal(-0.523598775598299, math::asin(-.5), .000000001);
      assert::are_equal(.0, math::asin(.0));
      assert::are_equal(0.523598775598299, math::asin(.5), .000000001);
      assert::are_equal(1.5707963267949, math::asin(1), .000000001);
      assert::is_NaN(math::asin(1.1));
    }
    
    auto test_method_(atan) {
      assert::is_NaN(math::atan(double_object::NaN));
      assert::are_equal(-1.5707963267949, math::atan(double_object::negative_infinity), .000000001);
      assert::are_equal(-1.41296513650674, math::atan(math::degrees_to_radians(-360)), .000000001);
      assert::are_equal(-1.36169168297116, math::atan(math::degrees_to_radians(-270)), .000000001);
      assert::are_equal(-1.26262725567891, math::atan(math::degrees_to_radians(-180)), .000000001);
      assert::are_equal(-1.00388482185389, math::atan(math::degrees_to_radians(-90)), .000000001);
      assert::are_equal(.0, math::atan(.0));
      assert::are_equal(1.00388482185389, math::atan(math::degrees_to_radians(90)), .000000001);
      assert::are_equal(1.26262725567891, math::atan(math::degrees_to_radians(180)), .000000001);
      assert::are_equal(1.36169168297116, math::atan(math::degrees_to_radians(270)), .000000001);
      assert::are_equal(1.41296513650674, math::atan(math::degrees_to_radians(360)), .000000001);
      assert::are_equal(1.5707963267949, math::atan(double_object::positive_infinity), .000000001);
    }
    
    auto test_method_(atan2) {
      assert::are_equal(0.463647609000806, math::atan2(1, 2), .000000000000001);
      assert::are_equal(0.839287844473872, math::atan2(127, 114), .000000000000001);
      assert::are_equal(0, math::atan2(0, 1));
      assert::are_equal(math::pi, math::atan2(0, -1));
      assert::are_equal(math::pi / 2, math::atan2(1, 0));
      assert::are_equal(-math::pi / 2, math::atan2(-1, 0));
      assert::is_NaN(math::atan2(double_object::NaN, 1));
      assert::is_NaN(math::atan2(1, double_object::NaN));
      assert::is_NaN(math::atan2(double_object::positive_infinity, double_object::positive_infinity));
      assert::is_NaN(math::atan2(double_object::positive_infinity, double_object::negative_infinity));
      assert::is_NaN(math::atan2(double_object::negative_infinity, double_object::negative_infinity));
      assert::is_NaN(math::atan2(double_object::negative_infinity, double_object::positive_infinity));
    }
    
    auto test_method_(big_mul) {
      assert::are_equal(4611686014132420609LL, math::big_mul(std::numeric_limits<int32>::max(), std::numeric_limits<int32>::max()));
    }
    
    auto test_method_(ceiling) {
      assert::are_equal(8, math::ceiling(7.03));
      assert::are_equal(8, math::ceiling(7.64));
      assert::are_equal(1, math::ceiling(0.12));
      assert::are_equal(0, math::ceiling(-0.12));
      assert::are_equal(-7, math::ceiling(-7.1));
      assert::are_equal(-7, math::ceiling(-7.6));
    }
    
    auto test_method_(cos) {
      assert::are_equal(1, math::cos(math::degrees_to_radians(0.0)));
      assert::are_equal(6.12303176911189E-17, math::cos(math::degrees_to_radians(90.0)), .0001);
      assert::is_NaN(math::cos(double_object::NaN));
      assert::is_NaN(math::cos(double_object::negative_infinity));
      assert::is_NaN(math::cos(double_object::positive_infinity));
    }
    
    auto test_method_(cosh) {
      assert::are_equal(1, math::cosh(0.0));
      assert::are_equal(10.0676619957778, math::cosh(3.0), .0000000000001);
      assert::are_equal(11013.2329201033, math::cosh(10.0), .0000000001);
      assert::is_true(double_object::is_positive_infinity(math::cosh(double_object::positive_infinity)));
      assert::is_true(double_object::is_positive_infinity(math::cosh(double_object::negative_infinity)));
      assert::is_NaN(math::cosh(double_object::NaN));
    }
    
    auto test_method_(degrees_to_radians) {
      assert::are_equal(-6.28318530717959, math::degrees_to_radians(-360.0), .00000000000001);
      assert::are_equal(-4.71238898038469, math::degrees_to_radians(-270.0), .00000000000001);
      assert::are_equal(-3.14159265358979, math::degrees_to_radians(-180.0), .0000000000001);
      assert::are_equal(-1.5707963267949, math::degrees_to_radians(-90.0), .0000000000001);
      assert::are_equal(0.0, math::degrees_to_radians(0.0));
      assert::are_equal(1.5707963267949, math::degrees_to_radians(90.0), .0000000000001);
      assert::are_equal(3.14159265358979, math::degrees_to_radians(180.0), .00000000000001);
      assert::are_equal(4.71238898038469, math::degrees_to_radians(270.0), .00000000000001);
      assert::are_equal(6.28318530717959, math::degrees_to_radians(360.0), .00000000000001);
    }
    
    auto test_method_(div_rem_int32) {
      block_scope_(int32 remainder = 0) {
        assert::are_equal(1073741, math::div_rem(std::numeric_limits<int32>::max(), as<int32>(2000), remainder));
        assert::are_equal(1647, remainder);
      }
      
      block_scope_(int32 remainder = 0) {
        assert::are_equal(6, math::div_rem(as<int32>(13952), as<int32>(2000), remainder));
        assert::are_equal(1952, remainder);
      }
      
      block_scope_(int32 remainder = 0) {
        assert::are_equal(0, math::div_rem(as<int32>(0), as<int32>(2000), remainder));
        assert::are_equal(0, remainder);
      }
      
      block_scope_(int32 remainder = 0) {
        assert::are_equal(-7, math::div_rem(as<int32>(-14032), as<int32>(2000), remainder));
        assert::are_equal(-32, remainder);
      }
      
      block_scope_(int32 remainder = 0) {
        assert::are_equal(-1073741, math::div_rem(std::numeric_limits<int32>::lowest(), as<int32>(2000), remainder));
        assert::are_equal(-1648, remainder);
      }
      
      block_scope_(int32 remainder = 0) {
        assert::are_equal(-1073741, math::div_rem(std::numeric_limits<int32>::max(), as<int32>(-2000), remainder));
        assert::are_equal(1647, remainder);
      }
      
      block_scope_(int32 remainder = 0) {
        assert::are_equal(-6, math::div_rem(as<int32>(13952), as<int32>(-2000), remainder));
        assert::are_equal(1952, remainder);
      }
      
      block_scope_(int32 remainder = 0) {
        assert::are_equal(0, math::div_rem(as<int32>(0), as<int32>(-2000), remainder));
        assert::are_equal(0, remainder);
      }
      
      block_scope_(int32 remainder = 0) {
        assert::are_equal(7, math::div_rem(as<int32>(-14032), as<int32>(-2000), remainder));
        assert::are_equal(-32, remainder);
      }
      
      block_scope_(int32 remainder = 0) {
        assert::are_equal(1073741, math::div_rem(std::numeric_limits<int32>::lowest(), as<int32>(-2000), remainder));
        assert::are_equal(-1648, remainder);
      }
    }
    
    auto test_method_(div_rem_int64) {
      block_scope_(int64 remainder = 0) {
        assert::are_equal(4611686018427387LL, math::div_rem(std::numeric_limits<int64>::max(), as<int64>(2000), remainder));
        assert::are_equal(1807, remainder);
      }
      
      block_scope_(int64 remainder = 0) {
        assert::are_equal(6, math::div_rem(as<int64>(13952), as<int64>(2000), remainder));
        assert::are_equal(1952, remainder);
      }
      
      block_scope_(int64 remainder = 0) {
        assert::are_equal(0, math::div_rem(as<int64>(0), as<int64>(2000), remainder));
        assert::are_equal(0, remainder);
      }
      
      block_scope_(int64 remainder = 0) {
        assert::are_equal(-7, math::div_rem(as<int64>(-14032), as<int64>(2000), remainder));
        assert::are_equal(-32, remainder);
      }
      
      block_scope_(int64 remainder = 0) {
        assert::are_equal(-4611686018427387LL, math::div_rem(std::numeric_limits<int64>::lowest(), as<int64>(2000), remainder));
        assert::are_equal(-1808, remainder);
      }
      
      block_scope_(int64 remainder = 0) {
        assert::are_equal(-4611686018427387LL, math::div_rem(std::numeric_limits<int64>::max(), as<int64>(-2000), remainder));
        assert::are_equal(1807, remainder);
      }
      
      block_scope_(int64 remainder = 0) {
        assert::are_equal(-6, math::div_rem(as<int64>(13952), as<int64>(-2000), remainder));
        assert::are_equal(1952, remainder);
      }
      
      block_scope_(int64 remainder = 0) {
        assert::are_equal(0, math::div_rem(as<int64>(0), as<int64>(-2000), remainder));
        assert::are_equal(0, remainder);
      }
      
      block_scope_(int64 remainder = 0) {
        assert::are_equal(7, math::div_rem(as<int64>(-14032), as<int64>(-2000), remainder));
        assert::are_equal(-32, remainder);
      }
      
      block_scope_(int64 remainder = 0) {
        assert::are_equal(4611686018427387LL, math::div_rem(std::numeric_limits<int64>::lowest(), as<int64>(-2000), remainder));
        assert::are_equal(-1808, remainder);
      }
    }
    
    auto test_method_(exp) {
      assert::are_equal(1.0, math::exp(0.0));
      assert::are_equal(148.413159, math::exp(5.0), .000001);
      assert::is_NaN(math::exp(double_object::NaN));
      assert::is_true(double_object::is_positive_infinity(math::exp(double_object::positive_infinity)));
      assert::are_equal(0.0, math::exp(double_object::negative_infinity));
    }
    
    auto test_method_(ieee_remainder) {
      assert::are_equal(-1.0, math::ieee_remainder(3.0, 2.0));
      assert::are_equal(0.0, math::ieee_remainder(4.0, 2.0));
      assert::are_equal(1.0, math::ieee_remainder(10.0, 3.0));
      assert::are_equal(-1.0, math::ieee_remainder(11.0, 3.0));
      assert::are_equal(-1.0, math::ieee_remainder(27.0, 4.0));
      assert::are_equal(-2.0, math::ieee_remainder(28.0, 5.0));
      assert::are_equal(1.8, math::ieee_remainder(17.8, 4.0), .000000000000001);
      assert::are_equal(1.4, math::ieee_remainder(17.8, 4.1), .00000000000001);
      assert::are_equal(0.0999999999999979, math::ieee_remainder(-16.3, 4.1), .000000000000001);
      assert::are_equal(1.4, math::ieee_remainder(17.8, -4.1), .00000000000001);
      assert::are_equal(-1.4, math::ieee_remainder(-17.8, -4.1), .00000000000001);
      assert::is_NaN(math::ieee_remainder(12.0, 0.0));
    }
    
    auto test_method_(floor) {
      assert::are_equal(7.0, math::floor(7.03));
      assert::are_equal(7.0, math::floor(7.64));
      assert::are_equal(0.0, math::floor(0.12));
      assert::are_equal(-1.0, math::floor(-0.12));
      assert::are_equal(-8.0, math::floor(-7.1));
      assert::are_equal(-8.0, math::floor(-7.6));
    }
    
    auto test_method_(log) {
      assert::are_equal(0.18232155679395459, math::log(1.2), 0.0000000000000001);
      assert::is_true(double_object::is_negative_infinity(math::log(0)));
      assert::is_NaN(math::log(-1));
      assert::is_NaN(math::log(double_object::NaN));
      assert::is_true(double_object::is_positive_infinity(math::log(double_object::positive_infinity)));
    }
    
    auto test_method_(log_with_new_base) {
      assert::are_equal(3.0, math::log(8.0, 2.0));
      assert::are_equal(2.0, math::log(100.0, 10.0));
      assert::are_equal(4.0, math::log(65536, 16));
      assert::is_NaN(math::log(-1, 10));
      assert::is_NaN(math::log(100, -1));
      assert::is_NaN(math::log(2, 0));
      assert::is_NaN(math::log(2, double_object::positive_infinity));
      assert::is_NaN(math::log(double_object::NaN, 10));
      assert::is_NaN(math::log(100, double_object::NaN));
      assert::is_NaN(math::log(100, 1));
      assert::is_true(double_object::is_positive_infinity(math::log(0, 0.5)));
      assert::is_true(double_object::is_positive_infinity(math::log(double_object::positive_infinity, 2)));
      assert::is_true(double_object::is_negative_infinity(math::log(0, 2)));
      assert::is_true(double_object::is_negative_infinity(math::log(double_object::positive_infinity, 0.5)));
    }
    
    auto test_method_(log10) {
      assert::are_equal(0.0, math::log10(1));
      assert::are_equal(1.0, math::log10(10));
      assert::are_equal(3.0, math::log10(1000));
      assert::is_true(double_object::is_negative_infinity(math::log10(0)));
      assert::is_NaN(math::log10(-1));
      assert::is_NaN(math::log10(double_object::NaN));
      assert::is_true(double_object::is_positive_infinity(math::log10(double_object::positive_infinity)));
    }
    
    auto test_method_(max_byte) {
      assert::are_equal(52u, math::max(as<xtd::byte>(2), as<xtd::byte>(52)));
      assert::are_equal(22u, math::max(as<xtd::byte>(22), as<xtd::byte>(5)));
      assert::are_equal(16u, math::max(as<xtd::byte>(16), as<xtd::byte>(16)));
    }
    
    auto test_method_(max_decimal) {
      assert::are_equal(52.0l, math::max(2.0l, 52.0l));
      assert::are_equal(22.0l, math::max(22.0l, 5.0l));
      assert::are_equal(16.0l, math::max(16.0l, 16.0l));
    }
    
    auto test_method_(max_double) {
      assert::are_equal(52, math::max(2.0, 52.0));
      assert::are_equal(22, math::max(22.0, 5.0));
      assert::are_equal(16, math::max(16.0, 16.0));
    }
    
    auto test_method_(max_int16) {
      assert::are_equal(52, math::max(as<int16>(2), as<int16>(52)));
      assert::are_equal(22, math::max(as<int16>(22), as<int16>(5)));
      assert::are_equal(16, math::max(as<int16>(16), as<int16>(16)));
    }
    
    auto test_method_(max_int32) {
      assert::are_equal(52, math::max(2, 52));
      assert::are_equal(22, math::max(22, 5));
      assert::are_equal(16, math::max(16, 16));
    }
    
    auto test_method_(max_int64) {
      assert::are_equal(52, math::max(as<int64>(2), as<int64>(52)));
      assert::are_equal(22, math::max(as<int64>(22), as<int64>(5)));
      assert::are_equal(16, math::max(as<int64>(16), as<int64>(16)));
    }
    
    auto test_method_(max_llong) {
      assert::are_equal(52, math::max(as<slong>(2), as<slong>(52)));
      assert::are_equal(22, math::max(as<slong>(22), as<slong>(5)));
      assert::are_equal(16, math::max(as<slong>(16), as<slong>(16)));
    }
    
    auto test_method_(max_sbyte) {
      assert::are_equal(52, math::max(as<sbyte>(2), as<sbyte>(52)));
      assert::are_equal(22, math::max(as<sbyte>(22), as<sbyte>(5)));
      assert::are_equal(16, math::max(as<sbyte>(16), as<sbyte>(16)));
    }
    
    auto test_method_(max_single) {
      assert::are_equal(52.0f, math::max(2.0f, 52.0f));
      assert::are_equal(22.0f, math::max(22.0f, 5.0f));
      assert::are_equal(16.0f, math::max(16.0f, 16.0f));
    }
    
    auto test_method_(max_uint16) {
      assert::are_equal(52u, math::max(as<uint16>(2), as<uint16>(52)));
      assert::are_equal(22u, math::max(as<uint16>(22), as<uint16>(5)));
      assert::are_equal(16u, math::max(as<uint16>(16), as<uint16>(16)));
    }
    
    auto test_method_(max_uint32) {
      assert::are_equal(52u, math::max(2u, 52u));
      assert::are_equal(22u, math::max(22u, 5u));
      assert::are_equal(16u, math::max(16u, 16u));
    }
    
    auto test_method_(max_uint64) {
      assert::are_equal(52u, math::max(as<uint64>(2), as<uint64>(52)));
      assert::are_equal(22u, math::max(as<uint64>(22), as<uint64>(5)));
      assert::are_equal(16u, math::max(as<uint64>(16), as<uint64>(16)));
    }
    
    auto test_method_(max_ullong) {
      assert::are_equal(52u, math::max(as<xtd::ulong>(2), as<xtd::ulong>(52)));
      assert::are_equal(22u, math::max(as<xtd::ulong>(22), as<xtd::ulong>(5)));
      assert::are_equal(16u, math::max(as<xtd::ulong>(16), as<xtd::ulong>(16)));
    }
    
    auto test_method_(min_byte) {
      assert::are_equal(2u, math::min(as<xtd::byte>(2), as<xtd::byte>(52)));
      assert::are_equal(5u, math::min(as<xtd::byte>(22), as<xtd::byte>(5)));
      assert::are_equal(16u, math::min(as<xtd::byte>(16), as<xtd::byte>(16)));
    }
    
    auto test_method_(min_decimal) {
      assert::are_equal(2.0l, math::min(2.0l, 52.0l));
      assert::are_equal(5.0l, math::min(22.0l, 5.0l));
      assert::are_equal(16.0l, math::min(16.0l, 16.0l));
    }
    
    auto test_method_(min_double) {
      assert::are_equal(2.0, math::min(2.0, 52.0));
      assert::are_equal(5.0, math::min(22.0, 5.0));
      assert::are_equal(16.0, math::min(16.0, 16.0));
    }
    
    auto test_method_(min_int16) {
      assert::are_equal(2, math::min(as<int16>(2), as<int16>(52)));
      assert::are_equal(5, math::min(as<int16>(22), as<int16>(5)));
      assert::are_equal(16, math::min(as<int16>(16), as<int16>(16)));
    }
    
    auto test_method_(min_int32) {
      assert::are_equal(2, math::min(2, 52));
      assert::are_equal(5, math::min(22, 5));
      assert::are_equal(16, math::min(16, 16));
    }
    
    auto test_method_(min_int64) {
      assert::are_equal(2, math::min(as<int64>(2), as<int64>(52)));
      assert::are_equal(5, math::min(as<int64>(22), as<int64>(5)));
      assert::are_equal(16, math::min(as<int64>(16), as<int64>(16)));
    }
    
    auto test_method_(min_llong) {
      assert::are_equal(2, math::min(as<slong>(2), as<slong>(52)));
      assert::are_equal(5, math::min(as<slong>(22), as<slong>(5)));
      assert::are_equal(16, math::min(as<slong>(16), as<slong>(16)));
    }
    
    auto test_method_(min_sbyte) {
      assert::are_equal(2, math::min(as<sbyte>(2), as<sbyte>(52)));
      assert::are_equal(5, math::min(as<sbyte>(22), as<sbyte>(5)));
      assert::are_equal(16, math::min(as<sbyte>(16), as<sbyte>(16)));
    }
    
    auto test_method_(min_single) {
      assert::are_equal(2.0f, math::min(2.0f, 52.0f));
      assert::are_equal(5.0f, math::min(22.0f, 5.0f));
      assert::are_equal(16.0f, math::min(16.0f, 16.0f));
    }
    
    auto test_method_(min_uint16) {
      assert::are_equal(2u, math::min(as<uint16>(2), as<uint16>(52)));
      assert::are_equal(5u, math::min(as<uint16>(22), as<uint16>(5)));
      assert::are_equal(16u, math::min(as<uint16>(16), as<uint16>(16)));
    }
    
    auto test_method_(min_uint32) {
      assert::are_equal(2u, math::min(2u, 52u));
      assert::are_equal(5u, math::min(22u, 5u));
      assert::are_equal(16u, math::min(16u, 16u));
    }
    
    auto test_method_(min_uint64) {
      assert::are_equal(2u, math::min(as<uint64>(2), as<uint64>(52)));
      assert::are_equal(5u, math::min(as<uint64>(22), as<uint64>(5)));
      assert::are_equal(16u, math::min(as<uint64>(16), as<uint64>(16)));
    }
    
    auto test_method_(min_ullong) {
      assert::are_equal(2u, math::min(as<xtd::ulong>(2), as<xtd::ulong>(52)));
      assert::are_equal(5u, math::min(as<xtd::ulong>(22), as<xtd::ulong>(5)));
      assert::are_equal(16u, math::min(as<xtd::ulong>(16), as<xtd::ulong>(16)));
    }
    
    auto test_method_(pow) {
      assert::are_equal(8, math::pow(2, 3));
      assert::is_NaN(math::pow(double_object::NaN, 3));
      assert::is_NaN(math::pow(2, double_object::NaN));
      assert::are_equal(1, math::pow(2, 0));
      assert::are_equal(0, math::pow(double_object::negative_infinity, -1));
      assert::is_true(double_object::is_negative_infinity(math::pow(double_object::negative_infinity, 11)));
      assert::is_true(double_object::is_positive_infinity(math::pow(double_object::negative_infinity, 10)));
      assert::is_NaN(math::pow(-1, 0.5));
      assert::is_true(double_object::is_positive_infinity(math::pow(0, double_object::negative_infinity)));
      assert::are_equal(0, math::pow(0, double_object::positive_infinity));
      assert::are_equal(0, math::pow(-2, double_object::negative_infinity));
      assert::are_equal(0, math::pow(2, double_object::negative_infinity));
      assert::is_true(double_object::is_positive_infinity(math::pow(-2, double_object::positive_infinity)));
      assert::is_true(double_object::is_positive_infinity(math::pow(2, double_object::positive_infinity)));
      assert::is_true(double_object::is_positive_infinity(math::pow(0, -1)));
      assert::are_equal(0, math::pow(0, 1));
      assert::are_equal(1, math::pow(1, 3));
      assert::are_equal(0, math::pow(double_object::positive_infinity, -1));
      assert::is_true(double_object::is_positive_infinity(math::pow(double_object::positive_infinity, 1)));
    }
    
    auto test_method_(radians_to_degrees) {
      assert::are_equal(-360.0, math::radians_to_degrees(-6.28318530717959), .000000001);
      assert::are_equal(-270.0, math::radians_to_degrees(-4.71238898038469), .000000001);
      assert::are_equal(-180.0, math::radians_to_degrees(-3.14159265358979), .000000001);
      assert::are_equal(-90.0, math::radians_to_degrees(-1.5707963267949), .000000001);
      assert::are_equal(0.0, math::radians_to_degrees(0.0));
      assert::are_equal(90.0, math::radians_to_degrees(1.5707963267949), .000000001);
      assert::are_equal(180.0, math::radians_to_degrees(3.14159265358979), .000000001);
      assert::are_equal(270.0, math::radians_to_degrees(4.71238898038469), .000000001);
      assert::are_equal(360.0, math::radians_to_degrees(6.28318530717959), .000000001);
    }
    
    auto test_method_(radians_to_degrees_degrees_to_radians) {
      assert::are_equal(-360.0, math::radians_to_degrees(math::degrees_to_radians(-360.0)));
      assert::are_equal(-270.0, math::radians_to_degrees(math::degrees_to_radians(-270.0)));
      assert::are_equal(-180.0, math::radians_to_degrees(math::degrees_to_radians(-180.0)));
      assert::are_equal(-90.0, math::radians_to_degrees(math::degrees_to_radians(-90.0)));
      assert::are_equal(0.0, math::radians_to_degrees(math::degrees_to_radians(0.0)));
      assert::are_equal(90.0, math::radians_to_degrees(math::degrees_to_radians(90.0)));
      assert::are_equal(180.0, math::radians_to_degrees(math::degrees_to_radians(180.0)));
      assert::are_equal(270.0, math::radians_to_degrees(math::degrees_to_radians(270.0)));
      assert::are_equal(360.0, math::radians_to_degrees(math::degrees_to_radians(360.0)));
    }
    
    auto test_method_(round) {
      assert::are_equal(11.0, math::round(11.1));
      assert::are_equal(11.0, math::round(11.4));
      assert::are_equal(12.0, math::round(11.5));
      assert::are_equal(12.0, math::round(11.9));
    }
    
    auto test_method_(round_decimal) {
      assert::are_equal(11.58, math::round(11.581, 2));
      assert::are_equal(11.58, math::round(11.584, 2));
      assert::are_equal(11.59, math::round(11.585, 2));
      assert::are_equal(11.59, math::round(11.589, 2));
    }
    
    auto test_method_(sign_decimal) {
      assert::are_equal(-1.0l, math::sign(-10.0l));
      assert::are_equal(0.0l, math::sign(0.0l));
      assert::are_equal(1.0l, math::sign(10.0l));
      assert::throws<arithmetic_exception>([] {math::sign(std::numeric_limits<decimal>::quiet_NaN());});
    }
    
    auto test_method_(sign_double) {
      assert::are_equal(-1.0, math::sign(-10.0));
      assert::are_equal(0.0, math::sign(0.0));
      assert::are_equal(1.0, math::sign(10.0));
      assert::throws<arithmetic_exception>([] {math::sign(double_object::NaN);});
    }
    
    auto test_method_(sign_int16) {
      assert::are_equal(-1, math::sign(as<int16>(-10)));
      assert::are_equal(0, math::sign(as<int16>(0)));
      assert::are_equal(1, math::sign(as<int16>(10)));
    }
    
    auto test_method_(sign_int32) {
      assert::are_equal(-1, math::sign(-10));
      assert::are_equal(0, math::sign(0));
      assert::are_equal(1, math::sign(10));
    }
    
    auto test_method_(sign_int64) {
      assert::are_equal(-1, math::sign(as<int64>(-10)));
      assert::are_equal(0, math::sign(as<int64>(0)));
      assert::are_equal(1, math::sign(as<int64>(10)));
    }
    
    auto test_method_(sign_sbyte) {
      assert::are_equal(-1, math::sign(as<sbyte>(-10)));
      assert::are_equal(0, math::sign(as<sbyte>(0)));
      assert::are_equal(1, math::sign(as<sbyte>(10)));
    }
    
    auto test_method_(sign_single) {
      assert::are_equal(-1.0f, math::sign(-10.0f));
      assert::are_equal(0.0f, math::sign(0.0f));
      assert::are_equal(1.0f, math::sign(10.0f));
      assert::throws<arithmetic_exception>([] {math::sign(std::numeric_limits<float>::quiet_NaN());});
    }
    
    auto test_method_(sin) {
      assert::are_equal(0.0, math::sin(math::degrees_to_radians(0.0)));
      assert::are_equal(0.707106781186547, math::sin(math::degrees_to_radians(45)), .0000000001);
      assert::are_equal(1.0, math::sin(math::degrees_to_radians(90.0)));
      assert::is_NaN(math::sin(double_object::NaN));
      assert::is_NaN(math::sin(double_object::negative_infinity));
      assert::is_NaN(math::sin(double_object::positive_infinity));
    }
    
    auto test_method_(sinh) {
      assert::are_equal(0.0, math::sinh(0.0));
      assert::are_equal(2.30129890230729, math::sinh(math::degrees_to_radians(90)), .00000000000001);
      assert::is_true(double_object::is_positive_infinity(math::sinh(double_object::positive_infinity)));
      assert::is_true(double_object::is_negative_infinity(math::sinh(double_object::negative_infinity)));
      assert::is_NaN(math::sinh(double_object::NaN));
    }
    
    auto test_method_(sqrt) {
      assert::are_equal(0.0, math::sqrt(0.0));
      assert::are_equal(1.0, math::sqrt(1.0));
      assert::are_equal(2.0, math::sqrt(4.0));
      assert::are_equal(3.0, math::sqrt(9.0));
      assert::is_NaN(math::sqrt(-1.0));
      assert::is_NaN(math::sqrt(double_object::NaN));
      assert::is_true(double_object::is_positive_infinity(math::sqrt(double_object::positive_infinity)));
    }
    
    auto test_method_(tan) {
      assert::are_equal(0.0, math::tan(0.0));
      assert::is_NaN(math::tan(double_object::NaN));
      assert::is_NaN(math::tan(double_object::negative_infinity));
      assert::is_NaN(math::tan(double_object::positive_infinity));
    }
    
    auto test_method_(tanh) {
      assert::are_equal(-1.0, math::tanh(double_object::negative_infinity));
      assert::are_equal(1.0, math::tanh(double_object::positive_infinity));
      assert::is_NaN(math::tanh(double_object::NaN));
    }
    
    auto test_method_(truncate_decimal) {
      assert::are_equal(0.0l, math::truncate(0.0l));
      assert::are_equal(1.0l, math::truncate(1.0l));
      assert::are_equal(2.0l, math::truncate(2.4l));
      assert::are_equal(2.0l, math::truncate(2.8l));
      assert::are_equal(-1.0l, math::truncate(-1.0l));
      assert::are_equal(-2.0l, math::truncate(-2.4l));
    }
    
    auto test_method_(truncate_double) {
      assert::are_equal(0.0, math::truncate(0.0));
      assert::are_equal(1.0, math::truncate(1.0));
      assert::are_equal(2.0, math::truncate(2.4));
      assert::are_equal(2.0, math::truncate(2.8));
      assert::are_equal(-1.0, math::truncate(-1.0));
      assert::are_equal(-2.0, math::truncate(-2.4));
    }
  };
}
