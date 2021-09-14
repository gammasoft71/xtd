/// @file
/// @brief Contains xtd::math class.
#pragma once
#include "static.h"
#include "types.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides constants and static methods for trigonometric, logarithmic, and other common mathematical functions.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks This class cannot be inherited.
  /// @par Examples
  /// The following example uses several mathematical and trigonometric functions from the xtd::math class to calculate the inner angles of a trapezoid.
  /// @include math.cpp
  class math static_ {
  public:
    /// @brief Represents the natural logarithmic base, specified by the constant, e. This field is constant.
    /// @remarks The value of this field is 2.7182818284590452354.
    static constexpr double e = 2.7182818284590452354;
    /// @brief Represents the ratio of the circumference of a circle to its diameter, specified by the constant, π. This field is constant.
    /// @remarks The value of this field is 3.14159265358979323846.
    static constexpr double pi = 3.14159265358979323846;
    /// @brief Represents the number of radians in one turn, specified by the constant, τ.
    /// @remarks The value of this field is 2.7182818284590451.
    static constexpr double tau = 2.7182818284590451;

    /// @brief Returns the absolute value of a double-precision floating-point number
    /// @param value A number in the range std::numeric_limit<decimal_t>::min() <= value <= std::numeric_limit<decimal_t>::max().
    /// @return A double-precision floating-point number, x, such that 0 <= x <= double::MaxValue
    static decimal_t abs(decimal_t value);
    
    /// @brief Returns the absolute value of a double-precision floating-point number
    /// @param value A number in the range std::numeric_limit<double>::min() <= value <= std::numeric_limit<double>::max().
    /// @return double A double-precision floating-point number, x, such that 0 <= x <= double::MaxValue
    static double abs(double value);
    
    /// @brief Returns the absolute value of a single-precision floating-point number
    /// @param value A number in the range std::numeric_limit<float>::min() <= value <= std::numeric_limit<float>::max().
    /// @return A single-precision floating-point number, x, such that 0 <= x <= single::MaxValue
    static float abs(float value);

    /// @brief Returns the absolute value of a 16-bit signed integer.
    /// @param value A number in the range std::numeric_limit<int16_t>::min() <= value <= std::numeric_limit<int16_t>::max().
    /// @return A 16-bit signed integer, x, such that 0 <= x <= int16::MaxValue
    /// @exception xtd::overflow_exception value equals Int16::MinValue.
    static int16_t abs(int16_t value);
    
    /// @brief Returns the absolute value of a 32-bit signed integer
    /// @param value A number in the range std::numeric_limit<int32_t>::min() <= value <= std::numeric_limit<int32_t>::max().
    /// @return A 32-bit signed integer, x, such that 0 <= x <= int32::MaxValue
    /// @exception xtd::overflow_exception value equals std::numeric_limit<int32_t>::min().
    static int32_t abs(int32_t value);
    
    /// @brief Returns the absolute value of a 64-bit signed integer
    /// @param value A number in the range std::numeric_limit<int64_t>::min() <= value <= std::numeric_limit<int64_t>::max().
    /// @return A 64-bit signed integer, x, such that 0 <= x <= int64::MaxValue
    /// @exception xtd::overflow_exception value equals std::numeric_limit<int64_t>::min().
    static int64_t abs(int64_t value);
    
    /// @brief Returns the absolute value of a 8-bit signed integer.
    /// @param value A number in the range std::numeric_limit<sbyte_t>::min() <= value <= std::numeric_limit<sbyte_t>::max().
    /// @return A 8-bit signed integer, x, such that 0 <= x <= sbyte::MaxValue
    /// @exception xtd::overflow_exception value equals std::numeric_limit<sbyte_tsbyte_t>::min().
    static sbyte_t abs(sbyte_t value);

  };
}
