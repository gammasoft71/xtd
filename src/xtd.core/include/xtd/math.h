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
    /// @brief Represents infinity. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<double>::infinity().
    static constexpr double infinity = std::numeric_limits<double>::infinity();
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
    static constexpr double negative_infinity = -infinity;
    /// @brief Represents the ratio of the circumference of a circle to its diameter, specified by the constant, π. This field is constant.
    /// @remarks The value of this field is 3.14159265358979323846.
    static constexpr double pi = 3.14159265358979323846;
    /// @brief Represents positive infinity. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<double>::infinity().
    static constexpr double positive_infinity = +infinity;
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
    /// @return An angle, A, measured in radians, such that 0 <= A <= PI. -or- math::NaN if value < -1 or d > 1.
    static double acos(double value);
    
    /// @brief Returns the angle whose sine is the specified number.
    /// @param value A number representing a sine, where -1 <= value <= 1.
    /// @return An angle, A, measured in radians, such that -PI/2 <= A <= PI/2. -or- math::NaN if value < -1 or d > 1.
    static double asin(double value);
    
    /// @brief Returns the angle whose tangent is the specified number.
    /// @param value A number representing a tangent.
    /// @return An angle, A, measured in radians, such that -PI/2 <= ? <= PI/2. -or- math::NaN if value equals math::NaN, -PI/2 rounded to double precision (-1.5707963267949) if d equals math::negative_infinity, or PI/2 rounded to double precision (1.5707963267949) if d equals math::positive_infinity
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

    /// @brief Calculates the quotient of two 32-bit signed integers and also returns the remainder in an output parameter.
    /// @param dividend The dividend.
    /// @param divisor The divisor.
    /// @param remainder An angle, measured in radians.
    /// @return The remainder.
    static int32_t div_rem(int32_t dividend, int32_t divisor, int32_t& remainder);
    
    /// @brief Calculates the quotient of two 64-bit signed integers and also returns the remainder in an output parameter.
    /// @param dividend The dividend.
    /// @param divisor The divisor.
    /// @param remainder An angle, measured in radians.
    /// @return The remainder.
    static int64_t div_rem(int64_t dividend, int64_t divisor, int64_t& remainder);

    /// @brief Returns e raised to the specified power.
    /// @param value A number specifying a power.
    /// @return The number e raised to the power d. If value equals xtd::math::NaN or xtd::math::positive_infinity, that value is returned. If value equals xtd::math::negative_infinity, 0 is returned.
    static double exp(double value);
    
    /// @brief Returns the largest integer less than or equal to the specified decimal number.
    /// @param value A double-precision floating-point number.
    /// @return The largest integer less than or equal to value.
    static decimal_t floor(decimal_t value);
    
    /// @brief Returns the largest integer less than or equal to the specified decimal number.
    /// @param value A double-precision floating-point number.
    /// @return The largest integer less than or equal to value.
    static double floor(double value);
    
    /// @brief Returns the remainder resulting from the division of a specified number by another specified number.
    /// @param dividend A dividend.
    /// @param divisor A divisor.
    /// @return A number equal to x - (y Q), where Q is the quotient of x / y rounded to the nearest integer (if x / y falls halfway between two integers, the even integer is returned).
    /// * If x - (y Q) is zero, the value +0 is returned if x is positive, or -0 if x is negative.
    /// * If y = 0, xtd::math::NaN is returned.
    static double ieee_remainder(double dividend, double divisor);

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

    /// @brief Returns the natural (base e) logarithm of a specified number.
    /// @param value A number whose logarithm is to be found.
    /// @return One of the values in the following table.
    /// | value parameter                       | Return value                                                  |
    /// |---------------------------------------|---------------------------------------------------------------|
    /// | Positive                              | The natural logarithm of d; that is, ln value, or log e value |
    /// | Zero                                  | xtd::math::negative_infinity                                  |
    /// | Negative                              | xtd::math::NaN                                                |
    /// | Equal to xtd::math::NaN               | xtd::math::NaN                                                |
    /// | Equal to xtd::math::positive_infinity | xtd::math::positive_infinity                                  |
    /// @remarks Parameter value is specified as a base 10 number.
    static double log(double value);
    
    /// @brief Returns the logarithm of a specified number in a specified base.
    /// @param a The number whose logarithm is to be found.
    /// @param new_base The base of the logarithm.
    /// @return One of the values in the following table. (+Infinity denotes math::positive_infinity, -Infinity denotes math::negative_infinity, and math::NaN denotes math::NaN.)
    /// | a                                | new_base                                | Return value                 |
    /// |----------------------------------|-----------------------------------------| -----------------------------|
    /// | a > 0                            | (0 < new_base < 1) -or- (new_base > 1)  | log new_base (a)             |
    /// | a < 0                            | (any value)                             | xtd::math::NaN               |
    /// | (any value)                      | new_base < 0                            | xtd::math::NaN               |
    /// | a != 1                           | new_base = 0                            | xtd::math::NaN               |
    /// | a != 1                           | new_base = xtd::math::positive_infinity | xtd::math::NaN               |
    /// | a = xtd::math::NaN               | (any value)                             | xtd::math::NaN               |
    /// | (any value)                      | new_base = xtd::math::NaN               | xtd::math::NaN               |
    /// | (any value)                      | new_base = 1                            | xtd::math::NaN               |
    /// | a = 0                            | 0 < new_base < 1                        | xtd::math::positive_infinity |
    /// | a = 0                            | new_base > 1                            | xtd::math::negative_infinity |
    /// | a = xtd::math::positive_infinity | 0 < new_base < 1                        | xtd::math::negative_infinity |
    /// | a = xtd::math::positive_infinity | new_base > 1                            | xtd::math::positive_infinity |
    /// | a = 1                            | new_base = 0                            | 0                            |
    /// | a = 1                            | new_base = xtd::math::positive_infinity | 0                            |
    static double log(double a, double new_base);
    
    /// @brief Returns the base 10 logarithm of a specified number.
    /// @param value A number whose logarithm is to be found.
    /// @return One of the values in the following table.
    /// | value parameter                       | Return value                                                  |
    /// |---------------------------------------|---------------------------------------------------------------|
    /// | Positive                              | The natural logarithm of d; that is, ln value, or log e value |
    /// | Zero                                  | xtd::math::negative_infinity                                  |
    /// | Negative                              | xtd::math::NaN                                                |
    /// | Equal to xtd::math::NaN               | xtd::math::NaN                                                |
    /// | Equal to xtd::math::positive_infinity | xtd::math::positive_infinity                                  |
    /// @remarks Parameter value is specified as a base 10 number.
    static double log10(double value);

    /// @brief Returns the larger of two 8-bit unsigned integers.
    /// @param a The first of two 8-bit unsigned integers to compare.
    /// @param b The second of two 8-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static byte_t max(byte_t a, byte_t b);
    
    /// @brief Returns the larger of two double single.
    /// @param a The first of two double single to compare.
    /// @param b The second of two double single to compare.
    /// @return Parameter a or b, whichever is larger.
    static decimal_t max(decimal_t a, decimal_t b);
    
    /// @brief Returns the larger of two double single.
    /// @param a The first of two double single to compare.
    /// @param b The second of two double single to compare.
    /// @return Parameter a or b, whichever is larger.
    static double max(double a, double b);
    
    /// @brief Returns the larger of two 16-bit signed integers.
    /// @param a The first of two 16-bit signed integers to compare.
    /// @param b The second of two 16-bit signed integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static int16_t max(int16_t a, int16_t b);
    
    /// @brief Returns the larger of two 32-bit signed integers.
    /// @param a The first of two 32-bit signed integers to compare.
    /// @param b The second of two 32-bit signed integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static int32_t max(int32_t a, int32_t b);
    
    /// @brief Returns the larger of two 64-bit signed integers.
    /// @param a The first of two 64-bit signed integers to compare.
    /// @param b The second of two 64-bit signed integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static int64_t max(int64_t a, int64_t b);
    
    /// @brief Returns the larger of two 64-bit signed integers.
    /// @param a The first of two 64-bit signed integers to compare.
    /// @param b The second of two 64-bit signed integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static llong_t max(llong_t a, llong_t b);

    /// @brief Returns the larger of two 8-bit signed integers.
    /// @param a The first of two 8-bit signed integers to compare.
    /// @param b The second of two 8-bit signed integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static sbyte_t max(sbyte_t a, sbyte_t b);
    
    /// @brief Returns the larger of two single single.
    /// @param a The first of two signle single to compare.
    /// @param b The second of two single single to compare.
    /// @return Parameter a or b, whichever is larger.
    static float max(float a, float b);
    
    /// @brief Returns the larger of two 16-bit unsigned integers.
    /// @param a The first of two 16-bit unsigned integers to compare.
    /// @param b The second of two 16-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static uint16_t max(uint16_t a, uint16_t b);
    
    /// @brief Returns the larger of two 32-bit unsigned integers.
    /// @param a The first of two 32-bit unsigned integers to compare.
    /// @param b The second of two 32-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static uint32_t max(uint32_t a, uint32_t b);
    
    /// @brief Returns the larger of two 64-bit unsigned integers.
    /// @param a The first of two 64-bit unsigned integers to compare.
    /// @param b The second of two 64-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static uint64_t max(uint64_t a, uint64_t b);
    
    /// @brief Returns the larger of two 64-bit unsigned integers.
    /// @param a The first of two 64-bit unsigned integers to compare.
    /// @param b The second of two 64-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static ullong_t max(ullong_t a, ullong_t b);

    /// @brief Returns the smaller of two 8-bit unsigned integers.
    /// @param a The first of two 8-bit unsigned integers to compare.
    /// @param b The second of two 8-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static byte_t min(byte_t a, byte_t b);
    
    /// @brief Returns the smaller of two double single.
    /// @param a The first of two double single to compare.
    /// @param b The second of two double single to compare.
    /// @return Parameter a or b, whichever is smaller.
    static decimal_t min(decimal_t a, decimal_t b);
    
    /// @brief Returns the smaller of two double single.
    /// @param a The first of two double single to compare.
    /// @param b The second of two double single to compare.
    /// @return Parameter a or b, whichever is smaller.
    static double min(double a, double b);
    
    /// @brief Returns the smaller of two 16-bit signed integers.
    /// @param a The first of two 16-bit signed integers to compare.
    /// @param b The second of two 16-bit signed integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static int16_t min(int16_t a, int16_t b);
    
    /// @brief Returns the smaller of two 32-bit signed integers.
    /// @param a The first of two 32-bit signed integers to compare.
    /// @param b The second of two 32-bit signed integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static int32_t min(int32_t a, int32_t b);
    
    /// @brief Returns the smaller of two 64-bit signed integers.
    /// @param a The first of two 64-bit signed integers to compare.
    /// @param b The second of two 64-bit signed integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static int64_t min(int64_t a, int64_t b);
    
    /// @brief Returns the smaller of two 64-bit signed integers.
    /// @param a The first of two 64-bit signed integers to compare.
    /// @param b The second of two 64-bit signed integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static llong_t min(llong_t a, llong_t b);

    /// @brief Returns the smaller of two 8-bit signed integers.
    /// @param a The first of two 8-bit signed integers to compare.
    /// @param b The second of two 8-bit signed integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static sbyte_t min(sbyte_t a, sbyte_t b);
    
    /// @brief Returns the smaller of two single single.
    /// @param a The first of two signle single to compare.
    /// @param b The second of two single single to compare.
    /// @return Parameter a or b, whichever is smaller.
    static float min(float a, float b);
    
    /// @brief Returns the smaller of two 16-bit unsigned integers.
    /// @param a The first of two 16-bit unsigned integers to compare.
    /// @param b The second of two 16-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static uint16_t min(uint16_t a, uint16_t b);
    
    /// @brief Returns the smaller of two 32-bit unsigned integers.
    /// @param a The first of two 32-bit unsigned integers to compare.
    /// @param b The second of two 32-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static uint32_t min(uint32 a, uint32 b);
    
    /// @brief Returns the smaller of two 64-bit unsigned integers.
    /// @param a The first of two 64-bit unsigned integers to compare.
    /// @param b The second of two 64-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static uint64 min(uint64_t a, uint64_t b);
    
    /// @brief Returns the smaller of two 64-bit unsigned integers.
    /// @param a The first of two 64-bit unsigned integers to compare.
    /// @param b The second of two 64-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static ullong_t min(ullong_t a, ullong_t b);

    /// @brief Returns a specified number raised to the specified power.
    /// @param x A double-precision floating-point number to be raised to a power.
    /// @param y A double-precision floating-point number that specifies a power.
    /// @return The number x raised to the power y.
    /// @remarks The following table indicates the return value when various values or ranges of values are specified for the x and y parameters. For more information, see Double::math::positive_infinity, Double::math::negative_infinity, and Double::NaN.
    /// | Parameters                                                                                                       | Return value            |
    /// |------------------------------------------------------------------------------------------------------------------|-------------------------|
    /// | x or y = math::NaN.                                                                                              | math::NaN               |
    /// | x = Any value except math::NaN; y = 0.                                                                           | 1                       |
    /// | x = math::negative_infinity; y < 0.                                                                              | 0                       |
    /// | x = math::negative_infinity; y is positive odd integer.                                                          | math::negative_infinity |
    /// | x = math::negative_infinity; y is positive but not an odd integer.                                               | math::positive_infinity |
    /// | x < 0 but not math::negative_infinity; y is not an integer, math::negative_infinity, or math::positive_infinity. | math::NaN               |
    /// | x = -1; y = math::negative_infinity or math::positive_infinity.                                                  | math::NaN               |
    /// | -1 < x < 1; y = math::negative_infinity.                                                                         | math::positive_infinity |
    /// | -1 < x < 1; y = math::positive_infinity.                                                                         | 0                       |
    /// | x < -1 or x > 1; y = math::negative_infinity.                                                                    | 0                       |
    /// | x < -1 or x > 1; y = math::positive_infinity.                                                                    | math::positive_infinity |
    /// | x = 0; y < 0.                                                                                                    | math::positive_infinity |
    /// | x = 0; y > 0.                                                                                                    | 0                       |
    /// | x = 1; y is any value except math::NaN.                                                                          | 1                       |
    /// | x = math::positive_infinity; y < 0                                                                               | 0                       |
    /// | x = math::positive_infinity; y > 0.                                                                              | math::positive_infinity |
    static double pow(double x, double y);

    /// @brief Convert radians to degrees.
    /// @param radians A double-precision floating-point number.
    /// @return A converted radians from degrees.
    static double radians_to_degrees(double radians);

    /// @brief Rounds a double-precision floating-point value to the nearest integral value.
    /// @param value A double-precision floating-point number to be rounded.
    /// @return The integer nearest value. If the fractional component of a is halfway between two integers, one of which is even and the other odd, then the even number is returned. Note that this method returns a double instead of an integral type.
    static decimal_t round(decimal_t value);
    
    /// @brief Rounds a decimal value to a specified number of fractional digits.
    /// @param value A double-precision floating-point number to be rounded.
    /// @param decimals The number of decimal places in the return value.
    /// @return The number nearest to d that contains a number of fractional digits equal to decimals.
    static decimal_t round(decimal_t value, int32_t decimals);
    
    /// @brief Rounds a double-precision floating-point value to the nearest integral value.
    /// @param value A double-precision floating-point number to be rounded.
    /// @return The integer nearest value. If the fractional component of a is halfway between two integers, one of which is even and the other odd, then the even number is returned. Note that this method returns a double instead of an integral type.
    static double round(double value);
    
    /// @brief Rounds a decimal value to a specified number of fractional digits.
    /// @param value A double-precision floating-point number to be rounded.
    /// @param decimals The number of decimal places in the return value.
    /// @return The number nearest to d that contains a number of fractional digits equal to decimals.
    static double round(double value, int32_t decimals);
  };
}
