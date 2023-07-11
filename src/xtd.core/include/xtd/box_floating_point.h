/// @file
/// @brief Contains xtd::box_floating_point class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "box_integer.h"

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
    
    /// @brief Represents the smallest positive type_t value greater than zero. This field is constant.
    /// @remarks The value of this field is 4.94066e-324.
    static constexpr type_t epsilon = __get_epsilon(type_t{});
    /// @brief Represents infinity. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::infinity().
    static constexpr type_t infinity = std::numeric_limits<type_t>::infinity();
    /// @brief Represents not a number (NaN). This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::quiet_NaN().
    static constexpr type_t NaN = std::numeric_limits<type_t>::quiet_NaN();
    /// @brief Represents negative infinity. This field is constant.
    /// @remarks The value of this field is -std::numeric_limits<type_t>::infinity().
    static constexpr type_t negative_infinity = -infinity;
    /// @brief Represents positive infinity. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::infinity().
    static constexpr type_t positive_infinity = +infinity;
  };
}
