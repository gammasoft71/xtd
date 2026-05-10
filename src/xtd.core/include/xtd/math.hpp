/// @file
/// @brief Contains xtd::math class.
#pragma once

/// @cond
// Workaround : Like Windows.h (with NOMINMAX defined), some includes define max as a macro and this causes compilation errors.
#if defined(_MSC_VER) && defined(max)
#  if __cplusplus < 202302L
#    pragma message("The macro `max` is defined. If you include the `Windows.h` file, please define the 'NOMINMAX' constant before including `Windows.h`. xtd will undef the `max` macro.")
#  else
#    warning "The macro `max` is defined. If you include the `Windows.h` file, please define the 'NOMINMAX' constant before including `Windows.h`. xtd will undef the `max` macro."
#  endif
#  undef max
#endif
#if defined(_MSC_VER) && defined(min)
#  if __cplusplus < 202302L
#    pragma message("The macro `min` is defined. If you include the `Windows.h` file, please define the 'NOMINMAX' constant before including `Windows.h`. xtd will undef the `min` macro.")
#  else
#    warning "The macro `min` is defined. If you include the `Windows.h` file, please define the 'NOMINMAX' constant before including `Windows.h`. xtd will undef the `min` macro."
#  endif
#  undef min
#endif
/// @endcond

#include "byte.hpp"
#include "double.hpp"
#include "double_object.hpp"
#include "int16.hpp"
#include "int32.hpp"
#include "int64.hpp"
#include "sbyte.hpp"
#include "single.hpp"
#include "single_object.hpp"
#include "slong.hpp"
#include "static.hpp"
#include "uint16.hpp"
#include "uint32.hpp"
#include "uint64.hpp"
#include "ulong.hpp"
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
    /// @brief Represents the ratio of the circumference of a circle to its diameter, specified by the constant, π. This field is constant.
    /// @remarks The value of this field is 3.14159265358979323846.
    static constexpr double pi = 3.14159265358979323846;
    /// @brief Represents the number of radians in one turn, specified by the constant, τ.
    /// @remarks The value of this field is 2.7182818284590451.
    static constexpr double tau = 2.7182818284590451;
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Returns the absolute value of a decimal number
    /// @param value A number in the range xtd::decimal_object::min_value <= value <= xtd::decimal_object::max_value.
    /// @return A decimal number, x, such that 0 <= x <= xtd::decimal_object::max_value.
    [[nodiscard]] static auto abs(xtd::decimal value) -> xtd::decimal;
    /// @brief Returns the absolute value of a double-precision floating-point number
    /// @param value A number in the range xtd::double_object::min_value <= value <= xtd::double_object::max_value.
    /// @return A double-precision floating-point number, x, such that 0 <= x <= stdxtd::double_object::max_value.
    [[nodiscard]] static auto abs(double value) -> double;
    /// @brief Returns the absolute value of a single-precision floating-point number
    /// @param value A number in the range xtd::single_object::min_value <= value <= xtd::single_object::max_value.
    /// @return A single-precision floating-point number, x, such that 0 <= x <= xtd::single_object::max_value.
    [[nodiscard]] static auto abs(xtd::single value) -> xtd::single;
    /// @brief Returns the absolute value of a 16-bit signed integer.
    /// @param value A number in the range xtd::int16_object::min_value <= value <= xtd::int16_object::max_value.
    /// @return A 16-bit signed integer, x, such that 0 <= x <= xtd::int16_object::max_value.
    /// @exception xtd::overflow_exception value equals xtd::int16_object::min_value.
    [[nodiscard]] static auto abs(xtd::int16 value) -> xtd::int16;
    /// @brief Returns the absolute value of a 32-bit signed integer
    /// @param value A number in the range xtd::int32_object::min_value <= value <= xtd::int32_object::max_value.
    /// @return A 32-bit signed integer, x, such that 0 <= x <= xtd::int32_object::max_value.
    /// @exception xtd::overflow_exception value equals xtd::int32_object::min_value.
    [[nodiscard]] static auto abs(xtd::int32 value) -> xtd::int32;
    /// @brief Returns the absolute value of a 64-bit signed integer
    /// @param value A number in the range xtd::int64_object::min_value <= value <= xtd::int64_object::max_value.
    /// @return A 64-bit signed integer, x, such that 0 <= x <= xtd::int64_object::max_value.
    /// @exception xtd::overflow_exception value equals xtd::int64_object::min_value.
    [[nodiscard]] static auto abs(xtd::int64 value) -> xtd::int64;
    /// @brief Returns the absolute value of a 8-bit signed integer.
    /// @param value A number in the range xtd::sbyte_object::min_value <= value <= xtd::sbyte_object::max_value.
    /// @return A 8-bit signed integer, x, such that 0 <= x <= xtd::sbyte_object::max_value.
    /// @exception xtd::overflow_exception value equals xtd::sbyte_object::min_value.
    [[nodiscard]] static auto abs(xtd::sbyte value) -> xtd::sbyte;
    /// @brief Returns the absolute value of a 64-bit signed integer
    /// @param value A number in the range xtd::slong_object::min_value <= value <= xtd::slong_object::max_value.
    /// @return A 8-bit signed integer, x, such that 0 <= x <= xtd::slong_object::max_value.
    /// @exception xtd::overflow_exception value equals xtd::slong_object::min_value.
    [[nodiscard]] static auto abs(xtd::slong value) -> xtd::slong;
    
    /// @brief Returns the angle whose cosine is the specified number.
    /// @param value A number representing a cosine, where -1 <= value <= 1.
    /// @return An angle, A, measured in radians, such that 0 <= A <= PI. <br>-or-<br> math::NaN if value < -1 or d > 1.
    [[nodiscard]] static auto acos(double value) -> double;
    
    /// @brief Returns the angle whose sine is the specified number.
    /// @param value A number representing a sine, where -1 <= value <= 1.
    /// @return An angle, A, measured in radians, such that -PI/2 <= A <= PI/2. <br>-or-<br> math::NaN if value < -1 or d > 1.
    [[nodiscard]] static auto asin(double value) -> double;
    
    /// @brief Returns the angle whose tangent is the specified number.
    /// @param value A number representing a tangent.
    /// @return An angle, A, measured in radians, such that -PI/2 <= ? <= PI/2. <br>-or-<br> math::NaN if value equals math::NaN, -PI/2 rounded to double precision (-1.5707963267949) if d equals math::negative_infinity, or PI/2 rounded to double precision (1.5707963267949) if d equals math::positive_infinity
    [[nodiscard]] static auto atan(double value) -> double;
    
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
    [[nodiscard]] static auto atan2(double y, double x) -> double;
    
    /// @brief Produces the full product of two 32-bit numbers.
    /// @param a The first xtd::int32 to multiply.
    /// @param b The second xtd::int32 to multiply.
    /// @return The xtd::int64 containing the product of the specified numbers.
    [[nodiscard]] static auto big_mul(xtd::int32 a, xtd::int32 b) -> xtd::int64;
    
    /// @brief Returns the smallest integer greater than or equal to the specified double-precision floating-point number.
    /// @param value A double-precision floating-point number.
    /// @return The smallest integer greater than or equal to value. If value is equal to xtd::math::NaN, xtd::math::negative_infinity, or xtd::math::positive_infinity, that value is returned.
    [[nodiscard]] static auto ceiling(xtd::decimal value) -> xtd::decimal;
    /// @brief Returns the smallest integer greater than or equal to the specified double-precision floating-point number.
    /// @param value A double-precision floating-point number.
    /// @return The smallest integer greater than or equal to value. If value is equal to xtd::math::NaN, xtd::math::negative_infinity, or xtd::math::positive_infinity, that value is returned.
    [[nodiscard]] static double ceiling(double value);
    
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    [[nodiscard]] static auto clamp(xtd::byte value, xtd::byte min, xtd::byte max) noexcept -> xtd::byte;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    [[nodiscard]] static auto clamp(xtd::decimal value, xtd::decimal min, xtd::decimal max) noexcept -> xtd::decimal;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    [[nodiscard]] static auto clamp(double value, double min, double max) noexcept -> double;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    [[nodiscard]] static auto clamp(xtd::int16 value, xtd::int16 min, xtd::int16 max) noexcept -> xtd::int16;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    [[nodiscard]] static auto clamp(xtd::int32 value, xtd::int32 min, xtd::int32 max) noexcept -> xtd::int32;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    [[nodiscard]] static auto clamp(xtd::int64 value, xtd::int64 min, xtd::int64 max) noexcept -> xtd::int64;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    [[nodiscard]] static auto clamp(xtd::slong value, xtd::slong min, xtd::slong max) noexcept -> xtd::slong;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    [[nodiscard]] static auto clamp(xtd::sbyte value, xtd::sbyte min, xtd::sbyte max) noexcept -> xtd::sbyte;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    [[nodiscard]] static auto clamp(xtd::single value, xtd::single min, xtd::single max) noexcept -> xtd::single;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    [[nodiscard]] static auto clamp(xtd::uint16 value, xtd::uint16 min, xtd::uint16 max) noexcept -> xtd::uint16;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    [[nodiscard]] static auto clamp(xtd::uint32 value, xtd::uint32 min, xtd::uint32 max) noexcept -> xtd::uint32;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    [[nodiscard]] static auto clamp(xtd::uint64 value, xtd::uint64 min, xtd::uint64 max) noexcept -> xtd::uint64;
    /// @brief Returns value clamped to the inclusive range of min and max.
    /// @param value The value to be clamped.
    /// @param min The lower bound of the result.
    /// @param max The upper bound of the result.
    /// @return value if min <= value <= max.<br>-or-<br>min if value < min.<br>>-or-<br>max if max < value.
    [[nodiscard]] static auto clamp(xtd::ulong value, xtd::ulong min, xtd::ulong max) noexcept -> xtd::ulong;
    
    /// @brief Returns the cosine of the specified angle.
    /// @param value An angle, measured in radians.
    /// @return The cosine of value. If value is equal to xtd::math::NaN, xtd::math::negative_infinity, or xtd::math::positive_infinity, this method returns xtd::math::NaN.
    [[nodiscard]] static auto cos(double value) -> double;
    
    /// @brief Returns the hyperbolic cosine of the specified angle.
    /// @param value An angle, measured in radians.
    /// @return The hyperbolic cosine of value. If value is equal to xtd::math::negative_infinity() or xtd::math::positive_:infinity, xtd::math::positive_infinity is returned. If value is equal to xtd::math::NaN, xtd::math::NaN is returned.
    [[nodiscard]] static auto cosh(double value) -> double;
    
    /// @brief Convert degrees to radians.
    /// @param degrees A double-precision floating-point number.
    /// @return A converted degrees from radians.
    [[nodiscard]] static auto degrees_to_radians(double degrees) noexcept -> double;
    
    /// @brief Calculates the quotient of two 32-bit signed integers and also returns the remainder in an output parameter.
    /// @param dividend The dividend.
    /// @param divisor The divisor.
    /// @param remainder An angle, measured in radians.
    /// @return The remainder.
    [[nodiscard]] static auto div_rem(xtd::int32 dividend, xtd::int32 divisor, xtd::int32& remainder) -> xtd::int32;
    /// @brief Calculates the quotient of two 64-bit signed integers and also returns the remainder in an output parameter.
    /// @param dividend The dividend.
    /// @param divisor The divisor.
    /// @param remainder An angle, measured in radians.
    /// @return The remainder.
    [[nodiscard]] static auto div_rem(xtd::int64 dividend, xtd::int64 divisor, xtd::int64& remainder) -> xtd::int64;
    
    /// @brief Returns e raised to the specified power.
    /// @param value A number specifying a power.
    /// @return The number e raised to the power d. If value equals xtd::math::NaN or xtd::math::positive_infinity, that value is returned. If value equals xtd::math::negative_infinity, 0 is returned.
    [[nodiscard]] static auto exp(double value) -> double;
    
    /// @brief Returns the largest integer less than or equal to the specified decimal number.
    /// @param value A double-precision floating-point number.
    /// @return The largest integer less than or equal to value.
    [[nodiscard]] static auto floor(xtd::decimal value) -> xtd::decimal;
    /// @brief Returns the largest integer less than or equal to the specified decimal number.
    /// @param value A double-precision floating-point number.
    /// @return The largest integer less than or equal to value.
    [[nodiscard]] static auto floor(double value) -> double;
    
    /// @brief Returns the remainder resulting from the division of a specified number by another specified number.
    /// @param dividend A dividend.
    /// @param divisor A divisor.
    /// @return A number equal to x - (y Q), where Q is the quotient of x / y rounded to the nearest integer (if x / y falls halfway between two integers, the even integer is returned).
    /// * If x - (y Q) is zero, the value +0 is returned if x is positive, or -0 if x is negative.
    /// * If y = 0, xtd::math::NaN is returned.
    [[nodiscard]] static auto ieee_remainder(double dividend, double divisor) -> double;
    
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
    [[nodiscard]] static auto log(double value) -> double;
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
    [[nodiscard]] static auto log(double a, double new_base) -> double;
    
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
    [[nodiscard]] static auto log10(double value) -> double;
    
    /// @brief Returns the larger of two 8-bit unsigned integers.
    /// @param a The first of two 8-bit unsigned integers to compare.
    /// @param b The second of two 8-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is larger.
    [[nodiscard]] static auto max(xtd::byte a, xtd::byte b) noexcept -> xtd::byte;
    /// @brief Returns the larger of two double single.
    /// @param a The first of two double single to compare.
    /// @param b The second of two double single to compare.
    /// @return Parameter a or b, whichever is larger.
    [[nodiscard]] static auto max(xtd::decimal a, xtd::decimal b) noexcept -> xtd::decimal;
    /// @brief Returns the larger of two double single.
    /// @param a The first of two double single to compare.
    /// @param b The second of two double single to compare.
    /// @return Parameter a or b, whichever is larger.
    [[nodiscard]] static auto max(double a, double b) noexcept -> double;
    /// @brief Returns the larger of two 16-bit signed integers.
    /// @param a The first of two 16-bit signed integers to compare.
    /// @param b The second of two 16-bit signed integers to compare.
    /// @return Parameter a or b, whichever is larger.
    [[nodiscard]] static auto max(xtd::int16 a, xtd::int16 b) noexcept -> xtd::int16;
    /// @brief Returns the larger of two 32-bit signed integers.
    /// @param a The first of two 32-bit signed integers to compare.
    /// @param b The second of two 32-bit signed integers to compare.
    /// @return Parameter a or b, whichever is larger.
    [[nodiscard]] static auto max(xtd::int32 a, xtd::int32 b) noexcept -> xtd::int32;
    /// @brief Returns the larger of two 64-bit signed integers.
    /// @param a The first of two 64-bit signed integers to compare.
    /// @param b The second of two 64-bit signed integers to compare.
    /// @return Parameter a or b, whichever is larger.
    [[nodiscard]] static auto max(xtd::int64 a, xtd::int64 b) noexcept -> xtd::int64;
    /// @brief Returns the larger of two 64-bit signed integers.
    /// @param a The first of two 64-bit signed integers to compare.
    /// @param b The second of two 64-bit signed integers to compare.
    /// @return Parameter a or b, whichever is larger.
    [[nodiscard]] static auto max(xtd::slong a, xtd::slong b) noexcept -> xtd::slong;
    /// @brief Returns the larger of two 8-bit signed integers.
    /// @param a The first of two 8-bit signed integers to compare.
    /// @param b The second of two 8-bit signed integers to compare.
    /// @return Parameter a or b, whichever is larger.
    [[nodiscard]] static auto max(xtd::sbyte a, xtd::sbyte b) noexcept -> xtd::sbyte;
    /// @brief Returns the larger of two single single.
    /// @param a The first of two single single to compare.
    /// @param b The second of two single single to compare.
    /// @return Parameter a or b, whichever is larger.
    [[nodiscard]] static auto max(xtd::single a, xtd::single b) noexcept -> xtd::single;
    /// @brief Returns the larger of two 16-bit unsigned integers.
    /// @param a The first of two 16-bit unsigned integers to compare.
    /// @param b The second of two 16-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is larger.
    [[nodiscard]] static auto max(xtd::uint16 a, xtd::uint16 b) noexcept -> xtd::uint16;
    /// @brief Returns the larger of two 32-bit unsigned integers.
    /// @param a The first of two 32-bit unsigned integers to compare.
    /// @param b The second of two 32-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is larger.
    [[nodiscard]] static auto max(xtd::uint32 a, xtd::uint32 b) noexcept -> xtd::uint32;
    /// @brief Returns the larger of two 64-bit unsigned integers.
    /// @param a The first of two 64-bit unsigned integers to compare.
    /// @param b The second of two 64-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is larger.
    [[nodiscard]] static auto max(xtd::uint64 a, xtd::uint64 b) noexcept -> xtd::uint64;
    /// @brief Returns the larger of two 64-bit unsigned integers.
    /// @param a The first of two 64-bit unsigned integers to compare.
    /// @param b The second of two 64-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is larger.
    [[nodiscard]] static auto max(xtd::ulong a, xtd::ulong b) noexcept -> xtd::ulong;
    
    /// @brief Returns the smaller of two 8-bit unsigned integers.
    /// @param a The first of two 8-bit unsigned integers to compare.
    /// @param b The second of two 8-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    [[nodiscard]] static auto min(xtd::byte a, xtd::byte b) noexcept -> xtd::byte;
    /// @brief Returns the smaller of two double single.
    /// @param a The first of two double single to compare.
    /// @param b The second of two double single to compare.
    /// @return Parameter a or b, whichever is smaller.
    [[nodiscard]] static auto min(xtd::decimal a, xtd::decimal b) noexcept -> xtd::decimal;
    /// @brief Returns the smaller of two double single.
    /// @param a The first of two double single to compare.
    /// @param b The second of two double single to compare.
    /// @return Parameter a or b, whichever is smaller.
    [[nodiscard]] static auto min(double a, double b) noexcept -> double;
    /// @brief Returns the smaller of two 16-bit signed integers.
    /// @param a The first of two 16-bit signed integers to compare.
    /// @param b The second of two 16-bit signed integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    [[nodiscard]] static auto min(xtd::int16 a, xtd::int16 b) noexcept -> xtd::int16;
    /// @brief Returns the smaller of two 32-bit signed integers.
    /// @param a The first of two 32-bit signed integers to compare.
    /// @param b The second of two 32-bit signed integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    [[nodiscard]] static auto min(xtd::int32 a, xtd::int32 b) noexcept -> xtd::int32;
    /// @brief Returns the smaller of two 64-bit signed integers.
    /// @param a The first of two 64-bit signed integers to compare.
    /// @param b The second of two 64-bit signed integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    [[nodiscard]] static auto min(xtd::int64 a, xtd::int64 b) noexcept -> xtd::int64;
    /// @brief Returns the smaller of two 64-bit signed integers.
    /// @param a The first of two 64-bit signed integers to compare.
    /// @param b The second of two 64-bit signed integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    [[nodiscard]] static auto min(xtd::slong a, xtd::slong b) noexcept -> xtd::slong;
    /// @brief Returns the smaller of two 8-bit signed integers.
    /// @param a The first of two 8-bit signed integers to compare.
    /// @param b The second of two 8-bit signed integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    [[nodiscard]] static auto min(xtd::sbyte a, xtd::sbyte b) noexcept -> xtd::sbyte;
    /// @brief Returns the smaller of two single single.
    /// @param a The first of two single single to compare.
    /// @param b The second of two single single to compare.
    /// @return Parameter a or b, whichever is smaller.
    [[nodiscard]] static auto min(xtd::single a, xtd::single b) noexcept -> xtd::single;
    /// @brief Returns the smaller of two 16-bit unsigned integers.
    /// @param a The first of two 16-bit unsigned integers to compare.
    /// @param b The second of two 16-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    [[nodiscard]] static auto min(xtd::uint16 a, xtd::uint16 b) noexcept -> xtd::uint16;
    /// @brief Returns the smaller of two 32-bit unsigned integers.
    /// @param a The first of two 32-bit unsigned integers to compare.
    /// @param b The second of two 32-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    [[nodiscard]] static auto min(xtd::uint32 a, xtd::uint32 b) noexcept -> xtd::uint32;
    /// @brief Returns the smaller of two 64-bit unsigned integers.
    /// @param a The first of two 64-bit unsigned integers to compare.
    /// @param b The second of two 64-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    [[nodiscard]] static auto min(xtd::uint64 a, xtd::uint64 b) noexcept -> xtd::uint64;
    /// @brief Returns the smaller of two 64-bit unsigned integers.
    /// @param a The first of two 64-bit unsigned integers to compare.
    /// @param b The second of two 64-bit unsigned integers to compare.
    /// @return Parameter a or b, whichever is smaller.
    [[nodiscard]] static auto min(xtd::ulong a, xtd::ulong b) noexcept -> xtd::ulong;
    
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
    [[nodiscard]] static auto pow(double x, double y) -> double;
    
    /// @brief Convert radians to degrees.
    /// @param radians A double-precision floating-point number.
    /// @return A converted radians from degrees.
    [[nodiscard]] static auto radians_to_degrees(double radians) noexcept -> double;
    
    /// @brief Rounds a double-precision floating-point value to the nearest integral value.
    /// @param value A double-precision floating-point number to be rounded.
    /// @return The integer nearest value. If the fractional component of a is halfway between two integers, one of which is even and the other odd, then the even number is returned. Note that this method returns a double instead of an integral type.
    [[nodiscard]] static auto round(xtd::decimal value) -> xtd::decimal;
    /// @brief Rounds a xtd::decimal value to a specified number of fractional digits.
    /// @param value A double-precision floating-point number to be rounded.
    /// @param decimals The number of xtd::decimal places in the return value.
    /// @return The number nearest to d that contains a number of fractional digits equal to decimals.
    [[nodiscard]] static auto round(xtd::decimal value, xtd::int32 decimals) -> xtd::decimal;
    /// @brief Rounds a double-precision floating-point value to the nearest integral value.
    /// @param value A double-precision floating-point number to be rounded.
    /// @return The integer nearest value. If the fractional component of a is halfway between two integers, one of which is even and the other odd, then the even number is returned. Note that this method returns a double instead of an integral type.
    [[nodiscard]] static auto round(double value) -> double;
    /// @brief Rounds a xtd::decimal value to a specified number of fractional digits.
    /// @param value A double-precision floating-point number to be rounded.
    /// @param decimals The number of xtd::decimal places in the return value.
    /// @return The number nearest to d that contains a number of fractional digits equal to decimals.
    [[nodiscard]] static auto round(double value, xtd::int32 decimals) -> double;
    
    /// @brief Returns a value indicating the sign of a double-precision floating-point number.
    /// @param value A signed number.
    /// @return xtd::int32 A number that indicates the sign of value, as shown in the following table.
    ///
    /// | Return value | Meaning                     |
    /// | ------------ | --------------------------- |
    /// | -1           | value is less than zero.    |
    /// | 0            | value is equal to zero.     |
    /// | 1            | value is greater than zero. |
    /// @exception xtd::arithmetic_exception value is equal to NaN.
    [[nodiscard]] static auto sign(xtd::decimal value) -> xtd::int32;
    /// @brief Returns a value indicating the sign of a double-precision floating-point number.
    /// @param value A signed number.
    /// @return xtd::int32 A number that indicates the sign of value, as shown in the following table.
    ///
    /// | Return value | Meaning                     |
    /// | ------------ | --------------------------- |
    /// | -1           | value is less than zero.    |
    /// | 0            | value is equal to zero.     |
    /// | 1            | value is greater than zero. |
    /// @exception xtd::arithmetic_exception value is equal to NaN.
    [[nodiscard]] static auto sign(double value) -> xtd::int32;
    /// @brief Returns a value indicating the sign of a 16-bit signed integer.
    /// @param value A signed number.
    /// @return xtd::int32 A number that indicates the sign of value, as shown in the following table.
    ///
    /// | Return value | Meaning                     |
    /// | ------------ | --------------------------- |
    /// | -1           | value is less than zero.    |
    /// | 0            | value is equal to zero.     |
    /// | 1            | value is greater than zero. |
    [[nodiscard]] static auto sign(xtd::int16 value) -> xtd::int32;
    /// @brief Returns a value indicating the sign of a 32-bit signed integer.
    /// @param value A signed number.
    /// @return xtd::int32 A number that indicates the sign of value, as shown in the following table.
    ///
    /// | Return value | Meaning                     |
    /// | ------------ | --------------------------- |
    /// | -1           | value is less than zero.    |
    /// | 0            | value is equal to zero.     |
    /// | 1            | value is greater than zero. |
    [[nodiscard]] static auto sign(xtd::int32 value) -> xtd::int32;
    /// @brief Returns a value indicating the sign of a 64-bit signed integer.
    /// @param value A signed number.
    /// @return xtd::int32 A number that indicates the sign of value, as shown in the following table.
    ///
    /// | Return value | Meaning                     |
    /// | ------------ | --------------------------- |
    /// | -1           | value is less than zero.    |
    /// | 0            | value is equal to zero.     |
    /// | 1            | value is greater than zero. |
    [[nodiscard]] static auto sign(xtd::int64 value) -> xtd::int32;
    /// @brief Returns a value indicating the sign of a 64-bit signed integer.
    /// @param value A signed number.
    /// @return xtd::int32 A number that indicates the sign of value, as shown in the following table.
    ///
    /// | Return value | Meaning                     |
    /// | ------------ | --------------------------- |
    /// | -1           | value is less than zero.    |
    /// | 0            | value is equal to zero.     |
    /// | 1            | value is greater than zero. |
    [[nodiscard]] static auto sign(xtd::slong value) -> xtd::int32;
    /// @brief Returns a value indicating the sign of an 8-bit signed integer.
    /// @param value A signed number.
    /// @return xtd::int32 A number that indicates the sign of value, as shown in the following table.
    ///
    /// | Return value | Meaning                     |
    /// | ------------ | --------------------------- |
    /// | -1           | value is less than zero.    |
    /// | 0            | value is equal to zero.     |
    /// | 1            | value is greater than zero. |
    [[nodiscard]] static auto sign(xtd::sbyte value) -> xtd::int32;
    /// @brief Returns a value indicating the sign of a single-precision floating-point number.
    /// @param value A signed number.
    /// @return xtd::int32 A number that indicates the sign of value, as shown in the following table.
    ///
    /// | Return value | Meaning                     |
    /// | ------------ | --------------------------- |
    /// | -1           | value is less than zero.    |
    /// | 0            | value is equal to zero.     |
    /// | 1            | value is greater than zero. |
    /// @exception xtd::arithmetic_exception value is equal to NaN.
    [[nodiscard]] static auto sign(xtd::single value) -> xtd::int32;
    
    /// @brief Returns the sine of the specified angle.
    /// @param value An angle, measured in radians.
    /// @return double The sine of value. If value is equal to math::NaN, math::negative_infinity, or math::positiveI_infinity, this method returns math::NaN.
    [[nodiscard]] static auto sin(double value) -> double;
    
    /// @brief Returns the hyperbolic sine of the specified angle.
    /// @param value An angle, measured in radians.
    /// @return double The sine of a. If a is equal to math::NaN, math::negative_infinity, or math::positive_infinity, this method returns math::NaN.
    [[nodiscard]] static auto sinh(double value) -> double;
    
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
    [[nodiscard]] static auto sqrt(double value) -> double;
    
    /// @brief Returns the tangent of the specified angle.
    /// @param value An angle, measured in radians.
    /// @return The tangent of value. If value is equal to math::NaN, math::negative_infinity, or math::positive_infinity, this method returns math::NaN.
    [[nodiscard]] static auto tan(double value) -> double;
    
    /// @brief Returns the hyperbolic tangent of the specified angle.
    /// @param value An angle, measured in radians.
    /// @return The hyperbolic tangent of value. If value is equal to math::negative_infinity, this method returns -1. If value is equal to math::positive_infinity, this method returns 1. If value is equal to math::NaN, this method returns math::NaN.
    [[nodiscard]] static auto tanh(double value) -> double;
    
    /// @brief Calculates the integral part of a specified double-precision floating-point number.
    /// @param value A number to truncate.
    /// @return The integral part of d; that is, the number that remains after any fractional digits have been discarded, or one of the values listed in the following table.
    ///
    /// | value            | Return value     |
    /// | ---------------- | ---------------- |
    /// | NaN              | NaN              |
    /// | NegativeInfinity | NegativeInfinity |
    /// | PositiveInfinity | PositiveInfinity |
    [[nodiscard]] static auto truncate(xtd::decimal value) -> xtd::decimal;
    /// @brief Calculates the integral part of a specified double-precision floating-point number.
    /// @param value A number to truncate.
    /// @return The integral part of d; that is, the number that remains after any fractional digits have been discarded, or one of the values listed in the following table.
    ///
    /// | value                   | Return value            |
    /// | ----------------------- | ----------------------- |
    /// | math::NaN               | math::NaN               |
    /// | math::negative_infinity | math::negative_infinity |
    /// | math::positive_infinity | math::positive_infinity |
    [[nodiscard]] static auto truncate(double value) -> double;
    /// @}
    
    /// @name Public Deprecated Fields
    
    /// @{
    /// @brief Represents the smallest positive Double value greater than zero. This field is constant.
    /// @remarks The value of this field is 4.94066e-324.
    /// @deprecated Replaced by xtd::double_object::epsilon - Will be removed in version 1.2.0.
    [[deprecated("Replaced by xtd::double_object::epsilon - Will be removed in version 1.2.0.")]]
    static constexpr auto epsilon = xtd::double_object::epsilon;
    /// @brief Represents infinity. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<double>::infinity().
    /// @deprecated Replaced by xtd::double_object::positive_infinity - Will be removed in version 1.2.0.
    [[deprecated("Replaced by xtd::double_object::positive_infinity - Will be removed in version 1.2.0.")]]
    static constexpr auto infinity = xtd::double_object::positive_infinity;
    /// @brief Represents the largest possible value of double. This field is constant.
    /// @remarks The value of this field is  1.7976931348623157E+308.
    /// @deprecated Replaced by xtd::double_object::max_value - Will be removed in version 1.2.0.
    [[deprecated("Replaced by xtd::double_object::max_value - Will be removed in version 1.2.0.")]]
    static constexpr auto max_value = xtd::double_object::max_value;
    /// @brief Represents the smallest possible value of double. This field is constant.
    /// @remarks The value of this field is -1.7976931348623157E+308.
    /// @deprecated Replaced by xtd::double_object::min_value - Will be removed in version 1.2.0.
    [[deprecated("Replaced by xtd::double_object::min_value - Will be removed in version 1.2.0.")]]
    static constexpr auto min_value = xtd::double_object::min_value;
    /// @brief Represents not a number (NaN). This field is constant.
    /// @remarks The value of this field is std::numeric_limits<double>::quiet_NaN().
    /// @deprecated Replaced by xtd::double_object::NaN - Will be removed in version 1.2.0.
    [[deprecated("Replaced by xtd::double_object::NaN - Will be removed in version 1.2.0.")]]
    static constexpr auto NaN = xtd::double_object::NaN;
    /// @brief Represents negative infinity. This field is constant.
    /// @remarks The value of this field is -std::numeric_limits<double>::infinity().
    /// @deprecated Replaced by xtd::double_object::negative_infinity - Will be removed in version 1.2.0.
    [[deprecated("Replaced by xtd::double_object::negative_infinity - Will be removed in version 1.2.0.")]]
    static constexpr auto negative_infinity = xtd::double_object::negative_infinity;
    /// @brief Represents positive infinity. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<double>::infinity().
    /// @deprecated Replaced by xtd::double_object::positive_infinity - Will be removed in version 1.2.0.
    [[deprecated("Replaced by xtd::double_object::positive_infinity - Will be removed in version 1.2.0.")]]
    static constexpr auto positive_infinity = xtd::double_object::positive_infinity;
    /// @}
    
    /// @name Public Deprecated Static Methods
    
    /// @{
    /// @brief Returns a value indicating whether the specified number evaluates to negative or positive infinity.
    /// @param value A double-precision floating-point number.
    /// @return `true` if value evaluates to xtd::math::positive_infinity or xtd::math::negative_infinity; otherwise, `false`.
    /// @deprecated Replaced by xtd::double_object::is_infinity - Will be removed in version 1.2.0.
    [[deprecated("Replaced by xtd::double_object::is_infinity - Will be removed in version 1.2.0.")]]
    [[nodiscard]] static auto is_infinity(double value) noexcept -> bool;
    
    /// @brief Returns a value indicating whether the specified number evaluates to negative infinity.
    /// @param value A double-precision floating-point number.
    /// @return `true` if value evaluates to xtd::math::negative_infinity; otherwise, `false`.
    /// @deprecated Replaced by xtd::double_object::is_negative_infinity - Will be removed in version 1.2.0.
    [[deprecated("Replaced by xtd::double_object::is_negative_infinity - Will be removed in version 1.2.0.")]]
    [[nodiscard]] static auto is_negative_infinity(double value) noexcept -> bool;
    
    /// @brief Returns a value indicating whether the specified number evaluates to positive infinity.
    /// @param value A double-precision floating-point number.
    /// @return `true` if value evaluates to xtd::math::positive_infinity; otherwise, `false`.
    /// @deprecated Replaced by xtd::double_object::is_positive_infinity - Will be removed in version 1.2.0.
    [[deprecated("Replaced by xtd::double_object::is_positive_infinity - Will be removed in version 1.2.0.")]]
    [[nodiscard]] static auto is_positive_infinity(double value) noexcept -> bool;
    
    /// @brief Returns a value indicating whether the specified number evaluates to not a number.
    /// @param value A double-precision floating-point number.
    /// @return `true` if value evaluates to not a number; otherwise, `false`.
    /// @deprecated Replaced by xtd::double_object::is_NaN - Will be removed in version 1.2.0.
    [[deprecated("Replaced by xtd::double_object::is_NaN - Will be removed in version 1.2.0.")]]
    [[nodiscard]] static auto is_NaN(double value) noexcept -> bool;
    /// @}
  };
}
