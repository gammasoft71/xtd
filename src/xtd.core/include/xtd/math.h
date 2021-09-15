/// @file
/// @brief Contains xtd::math class.
#pragma once
#include "static.h"
#include "types.h"
#include <limits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides constants and static methods for trigonometric, logarithmic, and other common mathematical functions.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks This class cannot be inherited.
  /// @par Examples
  /// The following example uses several mathematical and trigonometric functions from the xtd::math class to calculate the inner angles of a trapezoid.
  /// @include math.cpp
  class math static_ {
  public:
    /// @brief Represents the natural logarithmic base, specified by the constant, e. This field is constant.
    /// @remarks The value of this field is 2.7182818284590452354.
    static constexpr double e = 2.7182818284590452354;
    /// @brief Represents the smallest positive Double value greater than zero. This field is constant.
    /// @remarks The value of this field is 4.94066e-324.
    static constexpr double epsilon = 4.94066e-324;
    /// @brief Represents the largest possible value of double. This field is constant.
    /// @remarks The value of this field is  1.7976931348623157E+308.
    static constexpr double max_value = std::numeric_limits<double>::max();
    /// @brief Represents the smallest possible value of double. This field is constant.
    /// @remarks The value of this field is -1.7976931348623157E+308.
    static constexpr double min_value = std::numeric_limits<double>::lowest();
    /// @brief Represents not a number (NaN). This field is constant.
    /// @remarks The value of this field is std::numeric_limits<double>::quiet_NaN().
    static constexpr double NaN = std::numeric_limits<double>::quiet_NaN();
    /// @brief Represents negative infinity. This field is constant.
    /// @remarks The value of this field is -std::numeric_limits<double>::infinity().
    static constexpr double negative_infinity = -std::numeric_limits<double>::infinity();
    /// @brief Represents the ratio of the circumference of a circle to its diameter, specified by the constant, π. This field is constant.
    /// @remarks The value of this field is 3.14159265358979323846.
    static constexpr double pi = 3.14159265358979323846;
    /// @brief Represents positive infinity. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<double>::infinity().
    static constexpr double positive_infinity = std::numeric_limits<double>::infinity();
    /// @brief Represents the number of radians in one turn, specified by the constant, τ.
    /// @remarks The value of this field is 2.7182818284590451.
    static constexpr double tau = 2.7182818284590451;

    /// @brief Returns the absolute value of a decimal number
    /// @param value A number in the range std::numeric_limit<decimal_t>::lowest() <= value <= std::numeric_limit<decimal_t>::max().
    /// @return A decimal number, x, such that 0 <= x <= std::numeric_limit<decimal_t>::max()std::numeric_limit<decimal_t>::max().
    static decimal_t abs(decimal_t value);
    
    /// @brief Returns the absolute value of a double-precision floating-point number
    /// @param value A number in the range std::numeric_limit<double>::lowest() <= value <= std::numeric_limit<double>::max().
    /// @return A double-precision floating-point number, x, such that 0 <= x <= std::numeric_limit<douuble>::max().
    static double abs(double value);
    
    /// @brief Returns the absolute value of a single-precision floating-point number
    /// @param value A number in the range std::numeric_limit<float>::lowest() <= value <= std::numeric_limit<float>::max().
    /// @return A single-precision floating-point number, x, such that 0 <= x <= std::numeric_limit<float>::max().
    static float abs(float value);

    /// @brief Returns the absolute value of a 16-bit signed integer.
    /// @param value A number in the range std::numeric_limit<int16_t>::lowest() <= value <= std::numeric_limit<int16_t>::max().
    /// @return A 16-bit signed integer, x, such that 0 <= x <= std::numeric_limit<int16_t>::max().
    /// @exception xtd::overflow_exception value equals std::numeric_limit<int16_t>::lowest().
    static int16_t abs(int16_t value);
    
    /// @brief Returns the absolute value of a 32-bit signed integer
    /// @param value A number in the range std::numeric_limit<int32_t>::lowest() <= value <= std::numeric_limit<int32_t>::max().
    /// @return A 32-bit signed integer, x, such that 0 <= x <= std::numeric_limit<int32_t>::max().
    /// @exception xtd::overflow_exception value equals std::numeric_limit<int32_t>::lowest().
    static int32_t abs(int32_t value);
    
    /// @brief Returns the absolute value of a 64-bit signed integer
    /// @param value A number in the range std::numeric_limit<int64_t>::lowestlowest() <= value <= std::numeric_limit<int64_t>::max().
    /// @return A 64-bit signed integer, x, such that 0 <= x <= std::numeric_limit<int64_t>::max().
    /// @exception xtd::overflow_exception value equals std::numeric_limit<int64_t>::lowest().
    static int64_t abs(int64_t value);
    
    /// @brief Returns the absolute value of a 8-bit signed integer.
    /// @param value A number in the range std::numeric_limit<sbyte_t>::lowest() <= value <= std::numeric_limit<sbyte_t>::max().
    /// @return A 8-bit signed integer, x, such that 0 <= x <= std::numeric_limit<sbyte_t>::max().
    /// @exception xtd::overflow_exception value equals std::numeric_limit<sbyte_tsbyte_t>::lowest().
    static sbyte_t abs(sbyte_t value);
    
    /// @brief Returns the absolute value of a 64-bit signed integer
    /// @param value A number in the range std::numeric_limit<llong_t>::lowest() <= value <= std::numeric_limit<llong_t>::max().
    /// @return A 8-bit signed integer, x, such that 0 <= x <= std::numeric_limit<llong_t>::max().
    /// @exception xtd::overflow_exception value equals std::numeric_limit<llong_t>::lowest().
    static llong_t abs(llong_t value);

    /// @brief Returns the angle whose cosine is the specified number.
    /// @param value A number representing a cosine, where -1 <= value <= 1.
    /// @return An angle, A, measured in radians, such that 0 <= A <= PI. -or- NaN if value < -1 or d > 1.
    static double acos(double value);
    
    /// @brief Returns the angle whose sine is the specified number.
    /// @param value A number representing a sine, where -1 <= value <= 1.
    /// @return An angle, A, measured in radians, such that -PI/2 <= A <= PI/2. -or- NaN if value < -1 or d > 1.
    static double asin(double value);
    
    /// @brief Returns the angle whose tangent is the specified number.
    /// @param value A number representing a tangent.
    /// @return An angle, A, measured in radians, such that -PI/2 <= ? <= PI/2. -or- NaN if value equals NaN, -PI/2 rounded to double precision (-1.5707963267949) if d equals NegativeInfinity, or PI/2 rounded to double precision (1.5707963267949) if d equals PositiveInfinity
    static double atan(double value);
    
    /// @brief Returns the angle whose tangent is the specified number.
    /// @param y The y coordinate of a point.
    /// @param x The x coordinate of a point.
    /// @return An angle, A, measured in radians, such that -PI <= A <= PI, and tan(?) = y / x, where (x, y) is a point in the Cartesian plane. Observe the following:
    /// * For (x, y) in quadrant 1, 0 < A < PI/2.
    /// * For (x, y) in quadrant 2, PI/2 < A <= PI.
    /// * For (x, y) in quadrant 3, -PI < A < -PI/2.
    /// * For (x, y) in quadrant 4, -PI/2 < A < 0.
    /// * For points on the boundaries of the quadrants, the return value is the following:
    /// * If x is 0 and y is not negative, A = 0.
    /// * If x is 0 and y is negative, A = PI.
    /// * If x is positive and y is 0, A = PI/2.
    /// * If x is negative and y is 0, A = -PI/2.
    /// @remarks The return value is the angle in the Cartesian plane formed by the x-axis, and a vector starting from the origin, (0,0), and terminating at the point, (x,y).
    static double atan2(double y, double x);

    /// @brief Produces the full product of two 32-bit numbers.
    /// @param a The first int32 to multiply.
    /// @param b The second int32 to multiply.
    /// @return The int64 containing the product of the specified numbers.
    static int64_t big_mul(int32_t a, int32_t b);

    /// @brief Returns the smallest integer greater than or equal to the specified double-precision floating-point number.
    /// @param value A double-precision floating-point number.
    /// @return The smallest integer greater than or equal to value. If value is equal to xtd::math::NaN, xtd::math::negative_infinity, or xtd::math::positive_infinity, that value is returned.
    static decimal ceiling(decimal value);
    
    /// @brief Returns the smallest integer greater than or equal to the specified double-precision floating-point number.
    /// @param value A double-precision floating-point number.
    /// @return The smallest integer greater than or equal to value. If value is equal to xtd::math::NaN, xtd::math::negative_infinity, or xtd::math::positive_infinity, that value is returned.
    static double ceiling(double value);
    
    /// @brief Returns the cosine of the specified angle.
    /// @param value An angle, measured in radians.
    /// @return The cosine of value. If value is equal to xtd::math::NaN, xtd::math::negative_infinity, or xtd::math::positive_infinity, this method returns xtd::math::NaN.
    static double cos(double value);
    
    /// @brief Returns the hyperbolic cosine of the specified angle.
    /// @param value An angle, measured in radians.
    /// @return The hyperbolic cosine of value. If value is equal to xtd::math::negative_infinity() or xtd::math::posittive_:infinity, xtd::math::positive_infinity is returned. If value is equal to xtd::math::NaN, xtd::math::NaN is returned.
    static double cosh(double value);

    /// @brief Convert degrees to radians.
    /// @param degrees A double-precision floating-point number.
    /// @return A converted degrees from radians.
    static double degrees_to_radians(double degrees);

    /// @brief Returns a value indicating whether the specified number evaluates to negative or positive infinity.
    /// @param value A double-precision floating-point number.
    /// @return true if value evaluates to xtd::math::positive_infinity or xtd::math::negative_infinity; otherwise, false.
    static bool is_infinity(double value);
    
    /// @brief Returns a value indicating whether the specified number evaluates to negative infinity.
    /// @param value A double-precision floating-point number.
    /// @return true if value evaluates to xtd::math::negative_infinity; otherwise, false.
    static bool is_negative_infinity(double value);

    /// @brief Returns a value indicating whether the specified number evaluates to positive infinity.
    /// @param value A double-precision floating-point number.
    /// @return true if value evaluates to xtd::math::positive_infinity; otherwise, false.
    static bool is_positive_infinity(double value);

    /// @brief Returns a value indicating whether the specified number evaluates to not a number.
    /// @param value A double-precision floating-point number.
    /// @return true if value evaluates to not a number; otherwise, false.
    static bool is_NaN(double value);

    /// @brief Convert radians to degrees.
    /// @param radians A double-precision floating-point number.
    /// @return A converted radians from degrees.
    static double radians_to_degrees(double radians);
  };
}
