#pragma once
#include "environment.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The specified expression is cleared automaticaly when the scope is ended.
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// // mo is released automatically after the end closure }.
  /// using_(auto values = {1, 2, 3, 4, 5}) {
  ///   cout << strings::join(", ", values) << endl;
  /// }
  /// @endcode
  /// @remarks same as @block_scope_
  /// @ingroup keywords
  #define using_(...) \
    for (bool __xtd_using__ = true; __xtd_using__; __xtd_using__ = false)\
      for (__VA_ARGS__; __xtd_using__; __xtd_using__ = false)
}
