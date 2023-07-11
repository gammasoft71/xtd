/// @file
/// @brief Contains xtd::char_object alias.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "box_char.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent a boxed char.
  /// @par Header
  /// @code #include <xtd/char_object> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// The following example shows how to create and use xtd::char_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// char unboxed_object = 'a';
  /// char_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = a;
  /// @endcode
  using char_object = box_char<char>;
}
