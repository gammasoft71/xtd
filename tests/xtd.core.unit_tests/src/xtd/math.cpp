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
      assert::are_equal(16.354e-12f, math::abs(16.354e-12f));
      assert::are_equal(15.098123f, math::abs(15.098123f));
      assert::are_equal(.0f, math::abs(.0f));
      assert::are_equal(19.069713f, math::abs(-19.069713f));
      assert::are_equal(15.058e17f, math::abs(-15.058e17f));
      assert::are_equal(-numeric_limits<float>::lowest(), math::abs(numeric_limits<float>::lowest()), csf_);
    }

    void test_method_(abs_int16) {
      assert::are_equal(numeric_limits<int16_t>::max(), math::abs(numeric_limits<int16_t>::max()), csf_);
      assert::are_equal(static_cast<int16_t>(10328), math::abs(static_cast<int16_t>(10328)));
      assert::are_equal(static_cast<int16_t>(0), math::abs(static_cast<int16_t>(0)));
      assert::are_equal(static_cast<int16_t>(1476), math::abs(static_cast<int16_t>(-1476)));
      assert::throws<overflow_exception>([] {math::abs(numeric_limits<int16_t>::lowest());}, csf_);
    }
    
    void test_method_(abs_int32) {
      assert::are_equal(numeric_limits<int32_t>::max(), math::abs(numeric_limits<int32_t>::max()), csf_);
      assert::are_equal(16921, math::abs(16921));
      assert::are_equal(0, math::abs(0));
      assert::are_equal(804128, math::abs(-804128));
      assert::throws<overflow_exception>([] {math::abs(numeric_limits<int32_t>::lowest());}, csf_);
    }
    
    void test_method_(abs_int64) {
      assert::are_equal(numeric_limits<int64_t>::max(), math::abs(numeric_limits<int64_t>::max()), csf_);
      assert::are_equal(109013ll, math::abs(109013ll));
      assert::are_equal(0ll, math::abs(0ll));
      assert::are_equal(6871982ll, math::abs(-6871982ll));
      assert::throws<overflow_exception>([] {math::abs(numeric_limits<int64_t>::lowest());}, csf_);
    }
    
    void test_method_(abs_sbyte) {
      assert::are_equal(numeric_limits<sbyte_t>::max(), math::abs(numeric_limits<sbyte_t>::max()), csf_);
      assert::are_equal(static_cast<sbyte_t>(98), math::abs(static_cast<sbyte_t>(98)));
      assert::are_equal(static_cast<sbyte_t>(0), math::abs(static_cast<sbyte_t>(0)));
      assert::are_equal(static_cast<sbyte_t>(32), math::abs(static_cast<sbyte_t>(-32)));
      assert::throws<overflow_exception>([] {math::abs(numeric_limits<sbyte_t>::lowest());}, csf_);
    }
  };
}
