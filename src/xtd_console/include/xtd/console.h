/// @file
/// @brief Contains xtd::console and xtd::wconsole typedefs.
#pragma once
#include "basic_console.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the standard character input, output, and error streams for console applications.
  /// @remarks This class cannot be inherited.
  /// @par Examples
  /// The following example demonstrates how to read data from, and write data to, the standard input and output streams. Note that these streams can be redirected by using the SetIn and SetOut methods.
  /// @include console1.cpp
  /// @include console_out.cpp
  using console = basic_console<char>;
  
  /// @brief Represents the standard wide character input, output, and error streams for console applications.
  /// @remarks This class cannot be inherited.
  /// @par Examples
  /// The following example demonstrates how to read data from, and write data to, the standard input and output streams. Note that these streams can be redirected by using the SetIn and SetOut methods.
  /// @include console1.cpp
  /// @include console_out.cpp
  using wconsole = basic_console<wchar_t>;
}
