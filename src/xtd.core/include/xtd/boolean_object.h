/// @file
/// @brief Contains xtd::box_enum alias.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "box"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent a boxed bool.
  /// @par Header
  /// @code #include <xtd/boolean_object> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// The following example shows how to create and use xtd::boolean_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// bool unboxed_object = true;
  /// boolean_object boxed_object = unboxed_bool;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = true;
  /// @endcode
  using boolean_object = box<bool>;
}
