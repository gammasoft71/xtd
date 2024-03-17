/// @file
/// @brief Contains xtd::box_integer class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once

/// @cond
// Like Windows.h, some includes define max as a macro and this causes compilation errors.
#undef max
/// @endcond

#include "box.h"
#include "number_styles.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a boxed integer object.
  /// @code
  /// class box_integer : public xtd::box<type_t>
  /// @endcode
  /// @par Inheritance
  /// xtd::object → xtd::box <type_t> → xtd::box_integer <type_t>  /// @par Namespace
  /// @par Header
  /// @code #include <xtd/box_integer> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks You can use xtd::box to represent a class or structure that does not inherit from xtd::object. Typically used for integral types.
  /// @remarks Use xtd::boxing to box an object.
  /// @remarks Use xtd::unboxing to unbox an object.
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  /// @par Examples
  /// The following example shows how to create and use xtd::box_integer<int32>.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// int32 unboxed_object = 42;
  /// box_integer<int32> boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// @endcode
  template<typename type_t>
  class box_integer : public xtd::box<type_t> {
  public:
    /// @cond
    box_integer() = default;
    box_integer(const type_t& value) : xtd::box<type_t>(value) {}
    box_integer(const box_integer&) = default;
    box_integer(box_integer&&) = default;
    box_integer& operator =(const box_integer&) = default;
    /// @endcond
    
    /// @name Public Fields
    
    /// @{
    /// @brief Represents the largest possible value of type_t. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::max().
    static constexpr type_t max_value = std::numeric_limits<type_t>::max();
    /// @brief Represents the smallest possible value of type_t. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::lowest().
    static constexpr type_t min_value = std::numeric_limits<type_t>::lowest();
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    using box<type_t>::parse;
    /// @brief Converts the string to its type_t equivalent.
    /// @param value A string containing a type_t to convert.
    /// @return A type_t equivalent to the number contained in value.
    static type_t parse(const xtd::ustring& value, xtd::number_styles styles) {return xtd::parse<type_t>(value, styles);}
    using box<type_t>::try_parse;
    /// @brief Converts the string to its type_t equivalent.
    /// @param value A string containing a type_t to convert.
    /// @return A type_t equivalent to the number contained in value.
    static bool parse(const xtd::ustring& value, type_t& result, xtd::number_styles styles) {return xtd::try_parse<type_t>(value, result, styles);}
    /// @}
  };
}
