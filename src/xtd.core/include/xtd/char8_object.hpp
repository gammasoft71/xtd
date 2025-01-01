/// @file
/// @brief Contains xtd::char8_object alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "box_char.hpp"
#include "char8.hpp"

#if defined(__xtd__cpp_lib_char8_t)
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Boxed types
  
  /// @{
  /// @brief Represent a boxed char8.
  /// @par Header
  /// ```cpp
  /// #include <xtd/char8_object>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  /// @par Examples
  /// The following example shows how to create and use xtd::char8_object.
  /// ```cpp
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// char8 unboxed_object = u8'a';
  /// char8_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = a;
  /// ```
  using char8_object = box_char<char8>;
  /// @}
}
#endif

