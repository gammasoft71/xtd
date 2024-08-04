/// @file
/// @brief Contains xtd::box_enum alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "boolean.h"
#include "box.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent a boxed bool.
  /// @par Header
  /// ```cpp
  /// #include <xtd/boolean_object>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// The following example shows how to create and use xtd::boolean_object.
  /// ```cpp
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// bool unboxed_object = true;
  /// boolean_object boxed_object = unboxed_bool;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = true;
  /// ```
  using boolean_object = box<bool>;
}
