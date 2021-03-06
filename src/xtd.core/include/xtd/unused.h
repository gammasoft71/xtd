#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief  It may be used to suppress the "unused variable" or "unused local typedefs" compiler warnings when the variable or typedef can't be removed or commented out, e.g. when some blocks of the code are conditionally activated.
  /// @par Library
  /// xtd_core
  /// @param args variables to suppress the unsed warning
  /// @par Examples
  /// This example sho how to use Unused():
  /// @include unused.cpp
  template <typename ...Args>
  void unused(Args&& ... args) {}

  /// @brief  It may be used to suppress the "unused variable" or "unused local typedefs" compiler warnings when the variable or typedef can't be removed or commented out, e.g. when some blocks of the code are conditionally activated.
  /// @par Library
  /// xtd_core
  /// @param args variables to suppress the unsed warning
  /// @par Examples
  /// This example sho how to use Unused():
  /// @include unused.cpp
  /// @ingroup keywords
  #define unused_ \
    unused
}
