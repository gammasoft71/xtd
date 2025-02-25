/// @file
/// @brief Contains xtd::ulong_object alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "box_integer.hpp"
#include "ulong.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Boxed types
  
  /// @{
  /// @brief Represent a boxed ulong.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  /// @par Examples
  /// The following example shows how to create and use xtd::ulong_object.
  /// ```cpp
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// ulong unboxed_object = 42;
  /// ulong_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// ```
  using ulong_object = box_integer<ulong>;
  /// @}
}
