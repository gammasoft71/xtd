/// @file
/// @brief Contains xtd::box_floating_point class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "box.hpp"
#include "decimal.hpp"
#include "real.hpp"
#include <cmath>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a boxed floating point object.
  /// ```cpp
  /// class box_floating_point : public xtd::box<type_t>
  /// ```
  /// @par Inheritance
  /// xtd::object → xtd::box <type_t> → xtd::box <type_t> → box_floating_point <type_t>
  /// @par Header
  /// ```cpp
  /// #include <xtd/box_floating_point>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks You can use xtd::box to represent a class or structure that does not inherit from xtd::object. Typically used for integral types.
  /// @remarks Use xtd::boxing to box an object.
  /// @remarks Use xtd::unboxing to unbox an object.
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  /// @par Examples
  /// The following example shows how to create and use xtd::box_floating_point<float>.
  /// ```cpp
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// float unboxed_object = 3.14f;
  /// box_floating_point<float> boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 3.14;
  /// ```
  template<typename type_t>
  requires xtd::real<type_t>
  class box_floating_point : public xtd::box<type_t> {
  public:
    /// @cond
    box_floating_point() = default;
    box_floating_point(const type_t& value) : xtd::box<type_t>(value) {}
    box_floating_point(const box_floating_point&) = default;
    box_floating_point(box_floating_point&&) = default;
    box_floating_point& operator =(const box_floating_point&) = default;
    /// @endcond
    
    /// @name Public Fields
    
    /// @{
    /// @brief Represents the smallest positive type_t value greater than zero. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::denorm_min().
    static constexpr type_t epsilon = std::numeric_limits<type_t>::denorm_min();
    /// @brief Represents the largest possible value of type_t. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::max().
    static constexpr type_t max_value = std::numeric_limits<type_t>::max();
    /// @brief Represents the smallest possible value of type_t. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::lowest().
    static constexpr type_t min_value = std::numeric_limits<type_t>::lowest();
    /// @brief Represents not a number (NaN). This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::quiet_NaN().
    static constexpr type_t NaN = std::numeric_limits<type_t>::quiet_NaN();
    /// @brief Represents negative infinity. This field is constant.
    /// @remarks The value of this field is -std::numeric_limits<type_t>::infinity().
    static constexpr type_t negative_infinity = -std::numeric_limits<type_t>::infinity();
    /// @brief Represents positive infinity. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::infinity().
    static constexpr type_t positive_infinity = +std::numeric_limits<type_t>::infinity();
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Determines whether the specified value is finite (zero, subnormal, or normal).
    /// @param value A floating-point number.
    /// @return `true` if the value is finite (zero, subnormal or normal); `false` otherwise.
    [[nodiscard]] static auto is_finite(type_t value) noexcept -> bool {return !is_infinity(value) && !is_NaN(value);}
    /// @brief Returns a value indicating whether the specified number evaluates to negative or positive infinity.
    /// @param value A floating-point number.
    /// @return `true` if value evaluates to xtd::math::positive_infinity or xtd::math::negative_infinity; otherwise, `false`.
    [[nodiscard]] static auto is_infinity(type_t value) noexcept -> bool {return is_negative_infinity(value) || is_positive_infinity(value);}
    
    /// @brief Returns a value indicating whether the specified number evaluates to not a number.
    /// @param value A floating-point number.
    /// @return `true` if value evaluates to not a number; otherwise, `false`.
    [[nodiscard]] static auto is_NaN(type_t value) noexcept -> bool {return value != value;}

    /// @brief Returns a value indicating whether the specified number evaluates to negative infinity.
    /// @param value A floating-point number.
    /// @return `true` if value evaluates to xtd::math::negative_infinity; otherwise, `false`.
    [[nodiscard]] static auto is_negative_infinity(type_t value) noexcept -> bool {return value == negative_infinity;}

    /// @brief Returns a value indicating whether the specified number evaluates to normal, i.e. not an infinity, subnormal, not-a-number or zero.
    /// @param value A floating-point number.
    /// @return `true` if value evaluates to normal; otherwise, `false`.
    [[nodiscard]] static auto is_normal(type_t value) noexcept -> bool {return std::fpclassify(value) == FP_NORMAL;}

    /// @brief Returns a value indicating whether the specified number evaluates to positive infinity.
    /// @param value A floating-point number.
    /// @return `true` if value evaluates to xtd::math::positive_infinity; otherwise, `false`.
    [[nodiscard]] static auto is_positive_infinity(type_t value) noexcept -> bool {return value == positive_infinity;}

    /// @brief Returns a value indicating whether the specified number evaluates to subnormal.
    /// @param value A floating-point number.
    /// @return `true` if value evaluates to subnormal; otherwise, `false`.
    [[nodiscard]] static auto is_subnormal(type_t value) noexcept -> bool {return std::fpclassify(value) == FP_SUBNORMAL;}

    /// @brief Determines whether the specified value can be safely converted to type_t without overflow.
    /// @param value The floating point value to validate.
    /// @return true if value is greater than or equal to min_value and less than or equal to max_value; otherwise, false.
    /// @remarks If the value is outside the valid range defined by min_value and max_value, the method returns false.
    [[nodiscard]] static auto is_valid(xtd::real auto value) noexcept -> bool {return !is_NaN(value) && !is_infinity(value) && value >= static_cast<xtd::decimal>(min_value) && value <= static_cast<xtd::decimal>(max_value);}

    /// @brief Returns a value indicating whether the specified number evaluates to zero.
    /// @param value A floating-point number.
    /// @return `true` if value evaluates to zero; otherwise, `false`.
    [[nodiscard]] static auto is_zero(type_t value) noexcept -> bool {return std::fpclassify(value) == FP_ZERO;}

    using box<type_t>::parse;
    /// @brief Converts the string to its type_t equivalent.
    /// @param value A string containing a type_t to convert.
    /// @return A type_t equivalent to the number contained in value.
    [[nodiscard]] static auto parse(const xtd::string& value, xtd::number_styles styles) -> type_t {return xtd::parse<type_t>(value, styles);}
    
    using box<type_t>::try_parse;
    /// @brief Converts the string to its type_t equivalent.
    /// @param value A string containing a type_t to convert.
    /// @return A type_t equivalent to the number contained in value.
    [[nodiscard]] static auto try_parse(const xtd::string& value, type_t& result, xtd::number_styles styles) noexcept -> bool {return xtd::try_parse<type_t>(value, result, styles);}
    /// @}
  };
}
