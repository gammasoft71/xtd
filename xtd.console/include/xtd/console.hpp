/// @file
/// @brief Contains xtd::console and xtd::wconsole typedefs.
#pragma once
#include "__get_err_rdbuf.hpp"
#include "__get_in_rdbuf.hpp"
#include "__get_out_rdbuf.hpp"
#include "__opaque_console.hpp"
#include "background_color.hpp"
#include "beep.hpp"
#include "foreground_color.hpp"
#include "format.hpp"
#include "reset_color.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
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
