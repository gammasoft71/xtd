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
    /// @name Public Fields
    
    /// @{
    /// @brief Represents the natural logarithmic base, specified by the constant, e. This field is constant.
    /// @remarks The value of this field is 2.7182818284590452354.
    static constexpr double e = 2.7182818284590452354;
    /// @brief Represents the smallest positive Double value greater than zero. This field is constant.
    /// @remarks The value of this field is 4.94066e-324.
    /// @deprecated Replaced by xtd::double_object::epsilon - Will be removed in version 0.4.0
    [[deprecated("Replaced by xtd::double_object::epsilon - Will be removed in version 0.4.0")]]
    static constexpr double epsilon = 4.94066e-324;
    /// @brief Represents infinity. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<double>::infinity().
    /// @deprecated Replaced by xtd::double_object::positive_infinity - Will be removed in version 0.4.0
    [[deprecated("Replaced by xtd::double_object::positive_infinity - Will be removed in version 0.4.0")]]
    static constexpr double infinity = std::numeric_limits<double>::infinity();
    /// @brief Represents the largest possible value of double. This field is constant.
    /// @remarks The value of this field is  1.7976931348623157E+308.
    /// @deprecated Replaced by xtd::double_object::max_value - Will be removed in version 0.4.0
    [[deprecated("Replaced by xtd::double_object::max_value - Will be removed in version 0.4.0")]]
    static constexpr double max_value = std::numeric_limits<double>::max();
    /// @brief Represents the smallest possible value of double. This field is constant.
    /// @remarks The value of this field is -1.7976931348623157E+308.
    /// @deprecated Replaced by xtd::double_object::min_value - Will be removed in version 0.4.0
    [[deprecated("Replaced by xtd::double_object::min_value - Will be removed in version 0.4.0")]]
    static constexpr double min_value = std::numeric_limits<double>::lowest();
    /// @brief Represents not a number (NaN). This field is constant.
    /// @remarks The value of this field is std::numeric_limits<double>::quiet_NaN().
    /// @deprecated Replaced by xtd::double_object::NaN - Will be removed in version 0.4.0
    [[deprecated("Replaced by xtd::double_object::NaN - Will be removed in version 0.4.0")]]
    static constexpr double NaN = std::numeric_limits<double>::quiet_NaN();
    /// @brief Represents negative infinity. This field is constant.
    /// @remarks The value of this field is -std::numeric_limits<double>::infinity().
    /// @deprecated Replaced by xtd::double_object::negative_infinity - Will be removed in version 0.4.0
    [[deprecated("Replaced by xtd::double_object::negative_infinity - Will be removed in version 0.4.0")]]
    static constexpr double negative_infinity = -std::numeric_limits<double>::infinity();
    /// @brief Represents the ratio of the circumference of a circle to its diameter, specified by the constant, π. This field is constant.
    /// @remarks The value of this field is 3.14159265358979323846.
    static constexpr double pi = 3.14159265358979323846;
    /// @brief Represents positive infinity. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<double>::infinity().
    /// @deprecated Replaced by xtd::double_object::positive_infinity - Will be removed in version 0.4.0
    [[deprecated("Replaced by xtd::double_object::positive_infinity - Will be removed in version 0.4.0")]]
    static constexpr double positive_infinity = +std::numeric_limits<double>::infinity();
    /// @brief Represents the number of radians in one turn, specified by the constant, τ.
    /// @remarks The value of this field is 2.7182818284590451.
    static constexpr double tau = 2.7182818284590451;
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Returns the absolute value of a decimal number
    /// @param value A number in the range std::numeric_limit<decimal>::lowest() <= value <= std::numeric_limit<decimal>::max().
    /// @return A decimal number, x, such that 0 <= x <= std::numeric_limit<decimal>::max()std::numeric_limit<decimal>::max().
    static decimal abs(decimal value);
    /// @brief Returns the absolute value of a double-precision floating-point number
    /// @param value A number in the range std::numeric_limit<double>::lowest() <= value <= std::numeric_limit<double>::max().
    /// @return A double-precision floating-point number, x, such that 0 <= x <= std::numeric_limit<double>::max().
    static double abs(double value);
    /// @brief Returns the absolute value of a single-precision floating-point number
    /// @param value A number in the range std::numeric_limit<float>::lowest() <= value <= std::numeric_limit<float>::max().
    /// @return A single-precision floating-point number, x, such that 0 <= x <= std::numeric_limit<float>::max().
    static float abs(float value);
    /// @brief Returns the absolute value of a 16-bit signed integer.
    /// @param value A number in the range std::numeric_limit<int16>::lowest() <= value <= std::numeric_limit<int16>::max().
    /// @return A 16-bit signed integer, x, such that 0 <= x <= std::numeric_limit<int16>::max().
    /// @exception xtd::overflow_exception value equals std::numeric_limit<int16>::lowest().
    static int16 abs(int16 value);
    /// @brief Returns the absolute value of a 32-bit signed integer
    /// @param value A number in the range std::numeric_limit<int32>::lowest() <= value <= std::numeric_limit<int32>::max().
    /// @return A 32-bit signed integer, x, such that 0 <= x <= std::numeric_limit<int32>::max().
    /// @exception xtd::overflow_exception value equals std::numeric_limit<int32>::lowest().
    static int32 abs(int32 value);
    /// @brief Returns the absolute value of a 64-bit signed integer
    /// @param value A number in the range std::numeric_limit<int64>::min() <= value <= std::numeric_limit<int64>::max().
    /// @return A 64-bit signed integer, x, such that 0 <= x <= std::numeric_limit<int64>::max().
    /// @exception xtd::overflow_exception value equals std::numeric_limit<int64>::lowest().
    static int64 abs(int64 value);
    /// @brief Returns the absolute value of a 8-bit signed integer.
    /// @param value A number in the range std::numeric_limit<sbyte>::lowest() <= value <= std::numeric_limit<sbyte>::max().
    /// @return A 8-bit signed integer, x, such that 0 <= x <= std::numeric_limit<sbyte>::max().
    /// @exception xtd::overflow_exception value equals std::numeric_limit<sbyte_tsbyte_t>::lowest().
    static sbyte abs(sbyte value);
    /// @brief Returns the absolute value of a 64-bit signed integer
    /// @param value A number in the range std::numeric_limit<slong>::lowest() <= value <= std::numeric_limit<slong>::max().
    /// @return A 8-bit signed integer, x, such that 0 <= x <= std::numeric_limit<slong>::max().
    /// @exception xtd::overflow_exception value equals std::numeric_limit<slong>::lowest().
    static slong abs(slong value);
    
    /// @brief Returns the angle whose cosine is the specified number.
    /// @param value A number representing a cosine, where -1 <= value <= 1.
    /// @return An angle, A, measured in radians, such that 0 <= A <= PI. <br>-or-<br> math::NaN if value < -1 or d > 1.
    static double acos(double value);
    
    /// @brief Returns the angle whose sine is the specified number.
    /// @param value A number representing a sine, where -1 <= value <= 1.
    /// @return An angle, A, measured in radians, such that -PI/2 <= A <= PI/2. <br>-or-<br> math::NaN if value < -1 or d > 1.
    static double asin(double value);
    
    /// @brief Returns the angle whose tangent is the specified number.
    /// @param value A number representing a tangent.
    /// @return An angle, A, measured in radians, such that -PI/2 <= ? <= PI/2. <br>-or-<br> math::NaN if value equals math::NaN, -PI/2 rounded to double precision (-1.5707963267949) if d equals math::negative_infinity, or PI/2 rounded to double precision (1.5707963267949) if d equals math::positive_infinity
    static double atan(double value);
    
    /// @brief Returns the angle whose tangent is the specified number.
    /// @param y The y coordinate of a point.
    /// @param x The x coordinate of a point.
    /// @return An angle, A, measured in radians, such that -PI <= A <= PI, and tan(?) = y / x, where (x, y) is a point in the Cartesian plane.
    ///
    /// Observe the following:
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
    static int64 big_mul(int32 a, int32 b);
    
    /// @brief Returns the smallest integer greater than or equal to the specified double-precision floating-point number.
    /// @param value A double-precision floating-point number.
    /// @return The smallest integer greater than or equal to value. If value is equal to xtd::math::NaN, xtd::math::negative_infinity, or xtd::math::positive_infinity, that value is returned.
    static decimal ceiling(decimal value);
    
    /// @brief Returns the smallest integer greater than or equal to the specified double-precision floating-point number.
    /// @param value A double-precision floating-point number.
    /// @return The smallest integer greater than or equal to value. If value is equal to xtd::math::NaN, xtd::math::negative_infinity, or xtd::math::positive_infinity, that value is returned.
    static double ceiling(double value);
    
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    static xtd::byte clamp(xtd::byte value, xtd::byte min, xtd::byte max) noexcept;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    static decimal clamp(decimal value, decimal min, decimal max) noexcept;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    static double clamp(double value, double min, double max) noexcept;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    static int16 clamp(int16 value, int16 min, int16 max) noexcept;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    static int32 clamp(int32 value, int32 min, int32 max) noexcept;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    static int64 clamp(int64 value, int64 min, int64 max) noexcept;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    static slong clamp(slong value, slong min, slong max) noexcept;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    static sbyte clamp(sbyte value, sbyte min, sbyte max) noexcept;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    static float clamp(float value, float min, float max) noexcept;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    static uint16 clamp(uint16 value, uint16 min, uint16 max) noexcept;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    static uint32 clamp(uint32 value, uint32 min, uint32 max) noexcept;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    static uint64 clamp(uint64 value, uint64 min, uint64 max) noexcept;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    static xtd::ulong clamp(xtd::ulong value, xtd::ulong min, xtd::ulong max) noexcept;
    
    /// @brief Returns the cosine of the specified angle.
    /// @param value An angle, measured in radians.
    /// @return The cosine of value. If value is equal to xtd::math::NaN, xtd::math::negative_infinity, or xtd::math::positive_infinity, this method returns xtd::math::NaN.
    static double cos(double value);
    
    /// @brief Returns the hyperbolic cosine of the specified angle.
    /// @param value An angle, measured in radians.
    /// @return The hyperbolic cosine of value. If value is equal to xtd::math::negative_infinity() or xtd::math::positive_:infinity, xtd::math::positive_infinity is returned. If value is equal to xtd::math::NaN, xtd::math::NaN is returned.
    static double cosh(double value);
    
    /// @brief Convert degrees to radians.
    /// @param degrees A double-precision floating-point number.
    /// @return A converted degrees from radians.
    static double degrees_to_radians(double degrees) noexcept;
    
    /// @brief Calculates the quotient of two 32-bit signed integers and also returns the remainder in an output parameter.
    /// @param dividend The dividend.
    /// @param divisor The divisor.
    /// @param remainder An angle, measured in radians.
    /// @return The remainder.
    static int32 div_rem(int32 dividend, int32 divisor, int32& remainder);
    /// @brief Calculates the quotient of two 64-bit signed integers and also returns the remainder in an output parameter.
    /// @param dividend The dividend.
    /// @param divisor The divisor.
    /// @param remainder An angle, measured in radians.
    /// @return The remainder.
    static int64 div_rem(int64 dividend, int64 divisor, int64& remainder);
    
    /// @brief Returns e raised to the specified power.
    /// @param value A number specifying a power.
    /// @return The number e raised to the power d. If value equals xtd::math::NaN or xtd::math::positive_infinity, that value is returned. If value equals xtd::math::negative_infinity, 0 is returned.
    static double exp(double value);
    
    /// @brief Returns the largest integer less than or equal to the specified decimal number.
    /// @param value A double-precision floating-point number.
    /// @return The largest integer less than or equal to value.
    static decimal floor(decimal value);
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
    /// @deprecated Replaced by xtd::double_object::is_infinity - Will be removed in version 0.4.0
    [[deprecated("Replaced by xtd::double_object::is_infinity - Will be removed in version 0.4.0")]]
    static bool is_infinity(double value) noexcept;
    
    /// @brief Returns a value indicating whether the specified number evaluates to negative infinity.
    /// @param value A double-precision floating-point number.
    /// @return true if value evaluates to xtd::math::negative_infinity; otherwise, false.
    /// @deprecated Replaced by xtd::double_object::is_negative_infinity - Will be removed in version 0.4.0
    [[deprecated("Replaced by xtd::double_object::is_negative_infinity - Will be removed in version 0.4.0")]]
    static bool is_negative_infinity(double value) noexcept;
    
    /// @brief Returns a value indicating whether the specified number evaluates to positive infinity.
    /// @param value A double-precision floating-point number.
    /// @return true if value evaluates to xtd::math::positive_infinity; otherwise, false.
    /// @deprecated Replaced by xtd::double_object::is_positive_infinity - Will be removed in version 0.4.0
    [[deprecated("Replaced by xtd::double_object::is_positive_infinity - Will be removed in version 0.4.0")]]
    static bool is_positive_infinity(double value) noexcept;
    
    /// @brief Returns a value indicating whether the specified number evaluates to not a number.
    /// @param value A double-precision floating-point number.
    /// @return true if value evaluates to not a number; otherwise, false.
    /// @deprecated Replaced by xtd::double_object::is_NaN - Will be removed in version 0.4.0
    [[deprecated("Replaced by xtd::double_object::is_NaN - Will be removed in version 0.4.0")]]
    static bool is_NaN(double value) noexcept;
    
    /// @brief Returns the natural (base e) logarithm of a specified number.
    /// @param value A number whose logarithm is to be found.
    /// @return One of the values in the following table.
    ///
    /// | value parameter                       | Return value                                                  |
    /// | ------------------------------------- | ------------------------------------------------------------- |
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
    ///
    /// | a                                | new_base                                | Return value                 |
    /// | -------------------------------- | --------------------------------------- | ---------------------------- |
    /// | a > 0                            | (0 < new_base < 1) <br>-or-<br> (new_base > 1)  | log new_base (a)             |
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
    ///
    /// | value parameter                       | Return value                                                  |
    /// | ------------------------------------- | ------------------------------------------------------------- |
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
    static xtd::byte max(xtd::byte a, xtd::byte b) noexcept;
    /// @brief Returns the larger of two double single.
    /// @param a The first of two double single to compare.
    /// @param b The second of two double single to compare.
    /// @return Parameter a or b, whichever is larger.
    static decimal max(decimal a, decimal b) noexcept;
    /// @brief Returns the larger of two double single.
    /// @param a The first of two double single to compare.
    /// @param b The second of two double single to compare.
    /// @return Parameter a or b, whichever is larger.
    static double max(double a, double b) noexcept;
    /// @brief Returns the larger of two 16-bit signed integers.
    /// @param a The first of two 16-bit signed integers to compare.
    /// @param b The second of two 16-bit signed integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static int16 max(int16 a, int16 b) noexcept;
    /// @brief Returns the larger of two 32-bit signed integers.
    /// @param a The first of two 32-bit signed integers to compare.
    /// @param b The second of two 32-bit signed integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static int32 max(int32 a, int32 b) noexcept;
    /// @brief Returns the larger of two 64-bit signed integers.
    /// @param a The first of two 64-bit signed integers to compare.
    /// @param b The second of two 64-bit signed integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static int64 max(int64 a, int64 b) noexcept;
    /// @brief Returns the larger of two 64-bit signed integers.
    /// @param a The first of two 64-bit signed integers to compare.
    /// @param b The second of two 64-bit signed integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static slong max(slong a, slong b) noexcept;
    /// @brief Returns the larger of two 8-bit signed integers.
    /// @param a The first of two 8-bit signed integers to compare.
    /// @param b The second of two 8-bit signed integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static sbyte max(sbyte a, sbyte b) noexcept;
    /// @brief Returns the larger of two single single.
    /// @param a The first of two single single to compare.
    /// @param b The second of two single single to compare.
    /// @return Parameter a or b, whichever is larger.
    static float max(float a, float b) noexcept;
    /// @brief Returns the larger of two 16-bit unsigned integers.
    /// @param a The first of two 16-bit unsigned integers to compare.
    /// @param b The second of two 16-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static uint16 max(uint16 a, uint16 b) noexcept;
    /// @brief Returns the larger of two 32-bit unsigned integers.
    /// @param a The first of two 32-bit unsigned integers to compare.
    /// @param b The second of two 32-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static uint32 max(uint32 a, uint32 b) noexcept;
    /// @brief Returns the larger of two 64-bit unsigned integers.
    /// @param a The first of two 64-bit unsigned integers to compare.
    /// @param b The second of two 64-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static uint64 max(uint64 a, uint64 b) noexcept;
    /// @brief Returns the larger of two 64-bit unsigned integers.
    /// @param a The first of two 64-bit unsigned integers to compare.
    /// @param b The second of two 64-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is larger.
    static xtd::ulong max(xtd::ulong a, xtd::ulong b) noexcept;
    
    /// @brief Returns the smaller of two 8-bit unsigned integers.
    /// @param a The first of two 8-bit unsigned integers to compare.
    /// @param b The second of two 8-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static xtd::byte min(xtd::byte a, xtd::byte b) noexcept;
    /// @brief Returns the smaller of two double single.
    /// @param a The first of two double single to compare.
    /// @param b The second of two double single to compare.
    /// @return Parameter a or b, whichever is smaller.
    static decimal min(decimal a, decimal b) noexcept;
    /// @brief Returns the smaller of two double single.
    /// @param a The first of two double single to compare.
    /// @param b The second of two double single to compare.
    /// @return Parameter a or b, whichever is smaller.
    static double min(double a, double b) noexcept;
    /// @brief Returns the smaller of two 16-bit signed integers.
    /// @param a The first of two 16-bit signed integers to compare.
    /// @param b The second of two 16-bit signed integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static int16 min(int16 a, int16 b) noexcept;
    /// @brief Returns the smaller of two 32-bit signed integers.
    /// @param a The first of two 32-bit signed integers to compare.
    /// @param b The second of two 32-bit signed integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static int32 min(int32 a, int32 b) noexcept;
    /// @brief Returns the smaller of two 64-bit signed integers.
    /// @param a The first of two 64-bit signed integers to compare.
    /// @param b The second of two 64-bit signed integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static int64 min(int64 a, int64 b) noexcept;
    /// @brief Returns the smaller of two 64-bit signed integers.
    /// @param a The first of two 64-bit signed integers to compare.
    /// @param b The second of two 64-bit signed integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static slong min(slong a, slong b) noexcept;
    /// @brief Returns the smaller of two 8-bit signed integers.
    /// @param a The first of two 8-bit signed integers to compare.
    /// @param b The second of two 8-bit signed integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static sbyte min(sbyte a, sbyte b) noexcept;
    /// @brief Returns the smaller of two single single.
    /// @param a The first of two single single to compare.
    /// @param b The second of two single single to compare.
    /// @return Parameter a or b, whichever is smaller.
    static float min(float a, float b) noexcept;
    /// @brief Returns the smaller of two 16-bit unsigned integers.
    /// @param a The first of two 16-bit unsigned integers to compare.
    /// @param b The second of two 16-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static uint16 min(uint16 a, uint16 b) noexcept;
    /// @brief Returns the smaller of two 32-bit unsigned integers.
    /// @param a The first of two 32-bit unsigned integers to compare.
    /// @param b The second of two 32-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static uint32 min(uint32 a, uint32 b) noexcept;
    /// @brief Returns the smaller of two 64-bit unsigned integers.
    /// @param a The first of two 64-bit unsigned integers to compare.
    /// @param b The second of two 64-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static uint64 min(uint64 a, uint64 b) noexcept;
    /// @brief Returns the smaller of two 64-bit unsigned integers.
    /// @param a The first of two 64-bit unsigned integers to compare.
    /// @param b The second of two 64-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    static xtd::ulong min(xtd::ulong a, xtd::ulong b) noexcept;
    
    /// @brief Returns a specified number raised to the specified power.
    /// @param x A double-precision floating-point number to be raised to a power.
    /// @param y A double-precision floating-point number that specifies a power.
    /// @return The number x raised to the power y.
    /// @remarks The following table indicates the return value when various values or ranges of values are specified for the x and y parameters. For more information, see Double::math::positive_infinity, Double::math::negative_infinity, and Double::NaN.
    ///
    /// | Parameters                                                                                                       | Return value            |
    /// | ---------------------------------------------------------------------------------------------------------------- | ----------------------- |
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
    static double radians_to_degrees(double radians) noexcept;
    
    /// @brief Rounds a double-precision floating-point value to the nearest integral value.
    /// @param value A double-precision floating-point number to be rounded.
    /// @return The integer nearest value. If the fractional component of a is halfway between two integers, one of which is even and the other odd, then the even number is returned. Note that this method returns a double instead of an integral type.
    static decimal round(decimal value);
    /// @brief Rounds a decimal value to a specified number of fractional digits.
    /// @param value A double-precision floating-point number to be rounded.
    /// @param decimals The number of decimal places in the return value.
    /// @return The number nearest to d that contains a number of fractional digits equal to decimals.
    static decimal round(decimal value, int32 decimals);
    /// @brief Rounds a double-precision floating-point value to the nearest integral value.
    /// @param value A double-precision floating-point number to be rounded.
    /// @return The integer nearest value. If the fractional component of a is halfway between two integers, one of which is even and the other odd, then the even number is returned. Note that this method returns a double instead of an integral type.
    static double round(double value);
    /// @brief Rounds a decimal value to a specified number of fractional digits.
    /// @param value A double-precision floating-point number to be rounded.
    /// @param decimals The number of decimal places in the return value.
    /// @return The number nearest to d that contains a number of fractional digits equal to decimals.
    static double round(double value, int32 decimals);
    
    /// @brief Returns a value indicating the sign of a double-precision floating-point number.
    /// @param value A signed number.
    /// @return int32 A number that indicates the sign of value, as shown in the following table.
    ///
    /// | Return value | Meaning                     |
    /// | ------------ | --------------------------- |
    /// | -1           | value is less than zero.    |
    /// | 0            | value is equal to zero.     |
    /// | 1            | value is greater than zero. |
    /// @exception xtd::arithmetic_exception value is equal to NaN.
    static int32 sign(decimal value);
    /// @brief Returns a value indicating the sign of a double-precision floating-point number.
    /// @param value A signed number.
    /// @return int32 A number that indicates the sign of value, as shown in the following table.
    ///
    /// | Return value | Meaning                     |
    /// | ------------ | --------------------------- |
    /// | -1           | value is less than zero.    |
    /// | 0            | value is equal to zero.     |
    /// | 1            | value is greater than zero. |
    /// @exception xtd::arithmetic_exception value is equal to NaN.
    static int32 sign(double value);
    /// @brief Returns a value indicating the sign of a 16-bit signed integer.
    /// @param value A signed number.
    /// @return int32 A number that indicates the sign of value, as shown in the following table.
    ///
    /// | Return value | Meaning                     |
    /// | ------------ | --------------------------- |
    /// | -1           | value is less than zero.    |
    /// | 0            | value is equal to zero.     |
    /// | 1            | value is greater than zero. |
    static int32 sign(int16 value);
    /// @brief Returns a value indicating the sign of a 32-bit signed integer.
    /// @param value A signed number.
    /// @return int32 A number that indicates the sign of value, as shown in the following table.
    ///
    /// | Return value | Meaning                     |
    /// | ------------ | --------------------------- |
    /// | -1           | value is less than zero.    |
    /// | 0            | value is equal to zero.     |
    /// | 1            | value is greater than zero. |
    static int32 sign(int32 value);
    /// @brief Returns a value indicating the sign of a 64-bit signed integer.
    /// @param value A signed number.
    /// @return int32 A number that indicates the sign of value, as shown in the following table.
    ///
    /// | Return value | Meaning                     |
    /// | ------------ | --------------------------- |
    /// | -1           | value is less than zero.    |
    /// | 0            | value is equal to zero.     |
    /// | 1            | value is greater than zero. |
    static int32 sign(int64 value);
    /// @brief Returns a value indicating the sign of a 64-bit signed integer.
    /// @param value A signed number.
    /// @return int32 A number that indicates the sign of value, as shown in the following table.
    ///
    /// | Return value | Meaning                     |
    /// | ------------ | --------------------------- |
    /// | -1           | value is less than zero.    |
    /// | 0            | value is equal to zero.     |
    /// | 1            | value is greater than zero. |
    static int32 sign(slong value);
    /// @brief Returns a value indicating the sign of an 8-bit signed integer.
    /// @param value A signed number.
    /// @return int32 A number that indicates the sign of value, as shown in the following table.
    ///
    /// | Return value | Meaning                     |
    /// | ------------ | --------------------------- |
    /// | -1           | value is less than zero.    |
    /// | 0            | value is equal to zero.     |
    /// | 1            | value is greater than zero. |
    static int32 sign(sbyte value);
    /// @brief Returns a value indicating the sign of a single-precision floating-point number.
    /// @param value A signed number.
    /// @return int32 A number that indicates the sign of value, as shown in the following table.
    ///
    /// | Return value | Meaning                     |
    /// | ------------ | --------------------------- |
    /// | -1           | value is less than zero.    |
    /// | 0            | value is equal to zero.     |
    /// | 1            | value is greater than zero. |
    /// @exception xtd::arithmetic_exception value is equal to NaN.
    static int32 sign(float value);
    
    /// @brief Returns the sine of the specified angle.
    /// @param value An angle, measured in radians.
    /// @return double The sine of value. If value is equal to math::NaN, math::negative_infinity, or math::positiveI_infinity, this method returns math::NaN.
    static double sin(double value);
    
    /// @brief Returns the hyperbolic sine of the specified angle.
    /// @param value An angle, measured in radians.
    /// @return double The sine of a. If a is equal to math::NaN, math::negative_infinity, or math::positive_infinity, this method returns math::NaN.
    static double sinh(double value);
    
    /// @brief Returns the square root of a specified number.
    /// @param value The number whose square root is to be found.
    /// @return One of the values in the following table.
    ///
    /// | value parameter                | Return value                   |
    /// | ------------------------------ | ------------------------------ |
    /// | Zero or positive               | The positive square root of d. |
    /// | Negative                       | math::NaN                      |
    /// | Equals math::NaN               | math::NaN                      |
    /// | Equals math::positive_infinity | math::positive_infinity        |
    static double sqrt(double value);
    
    /// @brief Returns the tangent of the specified angle.
    /// @param value An angle, measured in radians.
    /// @return The tangent of value. If value is equal to math::NaN, math::negative_infinity, or math::positive_infinity, this method returns math::NaN.
    static double tan(double value);
    
    /// @brief Returns the hyperbolic tangent of the specified angle.
    /// @param value An angle, measured in radians.
    /// @return The hyperbolic tangent of value. If value is equal to math::negative_infinity, this method returns -1. If value is equal to math::positive_infinity, this method returns 1. If value is equal to math::NaN, this method returns math::NaN.
    static double tanh(double value);
    
    /// @brief Calculates the integral part of a specified double-precision floating-point number.
    /// @param value A number to truncate.
    /// @return The integral part of d; that is, the number that remains after any fractional digits have been discarded, or one of the values listed in the following table.
    ///
    /// | value            | Return value     |
    /// | ---------------- | ---------------- |
    /// | NaN              | NaN              |
    /// | NegativeInfinity | NegativeInfinity |
    /// | PositiveInfinity | PositiveInfinity |
    static decimal truncate(decimal value);
    /// @brief Calculates the integral part of a specified double-precision floating-point number.
    /// @param value A number to truncate.
    /// @return The integral part of d; that is, the number that remains after any fractional digits have been discarded, or one of the values listed in the following table.
    ///
    /// | value                   | Return value            |
    /// | ----------------------- | ----------------------- |
    /// | math::NaN               | math::NaN               |
    /// | math::negative_infinity | math::negative_infinity |
    /// | math::positive_infinity | math::positive_infinity |
    static double truncate(double value);
    /// @}
  };
}
