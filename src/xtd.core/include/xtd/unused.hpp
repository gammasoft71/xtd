/// @file
/// @brief Contains #unused_ keyword.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief It may be used to suppress the "unused variable" or "unused local typedefs" compiler warnings when the variable or typedef can't be removed or commented out, e.g. when some blocks of the code are conditionally activated.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param args variables to suppress the unused warning
  /// @par Examples
  /// This example sho how to use Unused():
  /// @include unused.cpp
  template <typename ...args_t>
  void unused(args_t&& ... args) {}
  
  /// @brief It may be used to suppress the "unused variable" or "unused local typedefs" compiler warnings when the variable or typedef can't be removed or commented out, e.g. when some blocks of the code are conditionally activated.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd_core
  /// @ingroup xtd_core keywords
  /// @param args variables to suppress the unused warning
  /// @par Examples
  /// This example sho how to use Unused():
  /// @include unused.cpp
#define unused_ \
  xtd::unused
}
