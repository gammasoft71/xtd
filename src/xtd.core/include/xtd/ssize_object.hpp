/// @file
/// @brief Contains xtd::ssize_object alias.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "box_integer.hpp"
#include "ssize.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Aliases
  
  /// @{
  /// @brief Represent a boxed xtd::ssize.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// The following example shows how to create and use xtd::ssize_object.
  /// ```cpp
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// ssize unboxed_object = 42;
  /// ssize_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = 42;
  /// ```
  using ssize_object = box_integer<xtd::ssize>;
  /// @}
}
