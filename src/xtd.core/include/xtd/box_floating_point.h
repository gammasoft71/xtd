/// @file
/// @brief Contains xtd::box_floating_point class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "box_integer.h"
#define __XTD_CORE_INTERNAL__
#include "internal/__box_floating_point.h"
#undef __XTD_CORE_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a boxed floating point object.
  /// @code
  /// class box_floating_point : public xtd::box<type_t>
  /// @endcode
  /// @par Inheritance
  /// xtd::object → xtd::box <type_t> → xtd::box_integer <type_t> → box_floating_point <type_t>
  /// @par Header
  /// @code #include <xtd/box°floating_point> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks You can use xtd::box to represent a class or structure that does not inherit from xtd::object. Typically used for integral types.
  /// @remarks Use xtd::boxing to box an object.
  /// @remarks Use xtd::unboxing to unbox an object.
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  /// @par Examples
  /// The following example shows how to create and use xtd::box_floating_point<float>.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// float unboxed_object = 3.14f;
  /// box_floating_point<float> boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 3.14;
  /// @endcode
  template<typename type_t>
  class box_floating_point : public xtd::box_integer<type_t> {
  public:
    /// @cond
    box_floating_point() = default;
    box_floating_point(const type_t& value) : xtd::box_integer<type_t>(value) {}
    box_floating_point(const box_floating_point&) = default;
    box_floating_point(box_floating_point&&) = default;
    box_floating_point& operator =(const box_floating_point&) = default;
    /// @endcond
    
    /// @name Public Fields
    
    /// @{
    /// @brief Represents the smallest positive type_t value greater than zero. This field is constant.
    /// @remarks The value of this field is 4.94066e-324.
    static constexpr type_t epsilon = __get_epsilon(type_t{});
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
    /// @return true if the value is finite (zero, subnormal or normal); false otherwise.
    static bool is_finite(type_t value) noexcept {return !is_infinity(value);}
    /// @brief Returns a value indicating whether the specified number evaluates to negative or positive infinity.
    /// @param value A floating-point number.
    /// @return true if value evaluates to xtd::math::positive_infinity or xtd::math::negative_infinity; otherwise, false.
    static bool is_infinity(type_t value) noexcept {return is_negative_infinity(value) || is_positive_infinity(value);}
    
    /// @brief Returns a value indicating whether the specified number evaluates to negative infinity.
    /// @param value A floating-point number.
    /// @return true if value evaluates to xtd::math::negative_infinity; otherwise, false.
    static bool is_negative_infinity(type_t value) noexcept {return value <= negative_infinity;}
    
    /// @brief Returns a value indicating whether the specified number evaluates to positive infinity.
    /// @param value A floating-point number.
    /// @return true if value evaluates to xtd::math::positive_infinity; otherwise, false.
    static bool is_positive_infinity(type_t value) noexcept {return value >= positive_infinity;}
    
    /// @brief Returns a value indicating whether the specified number evaluates to not a number.
    /// @param value A floating-point number.
    /// @return true if value evaluates to not a number; otherwise, false.
    static bool is_NaN(type_t value) noexcept {return value != value;}
    /// @}
  };
}
