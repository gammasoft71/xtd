/// @file
/// @brief Contains xtd::char8_object alias.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "box_char"

#if defined(__cpp_lib_char8_t)
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Boxed types
  
  /// @{
  /// @brief Represent a boxed char8.
  /// @par Header
  /// @code #include <xtd/char8_object> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  /// @par Examples
  /// The following example shows how to create and use xtd::char8_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// char8 unboxed_object = u8'a';
  /// char8_object boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = a;
  /// @endcode
  using char8_object = box_char<char8>;
  /// @}
}
#endif

