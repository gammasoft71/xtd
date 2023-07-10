/// @file
/// @brief Contains xtd::wchar_object alias.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "char_object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent a boxed wchar.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// The following example shows how to create and use xtd::wchar_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// wchar unboxed_object = L'a';
  /// wchar_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = a;
  /// @endcode
  using wchar_object = box_char<wchar>;
}
