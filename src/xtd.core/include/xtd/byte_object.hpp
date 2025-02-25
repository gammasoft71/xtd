/// @file
/// @brief Contains xtd::byte_object alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "byte.hpp"
#include "box_integer.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Boxed types
  
  /// @{
  /// @brief Represent a boxed byte.
  /// @par Header
  /// ```cpp
  /// #include <xtd/byte_object>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  /// @par Examples
  /// The following example shows how to create and use xtd::byte_object.
  /// ```cpp
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// xtd::byte unboxed_object = 42;
  /// byte_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// ```
  using byte_object = box_integer<xtd::byte>;
  /// @}
}
