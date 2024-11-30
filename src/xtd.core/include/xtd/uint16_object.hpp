/// @file
/// @brief Contains xtd::uint16_object alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "box_integer.hpp"
#include "uint16.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Boxed types
  
  /// @{
  /// @brief Represent a boxed uint16.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  /// @par Examples
  /// The following example shows how to create and use xtd::uint16_object.
  /// ```cpp
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// uint16 unboxed_object = 42;
  /// uint16_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// ```
  using uint16_object = box_integer<uint16>;
  /// @}
}
