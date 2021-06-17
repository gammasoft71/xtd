/// @file
/// @brief Contains #block_scope_ keyword.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The specified expression is cleared automaticaly when the scope is ended.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core keywords
  /// @par Examples
  /// @code
  /// // values is released automatically after the end closure }.
  /// block_scope_(auto values = {1, 2, 3, 4, 5}) {
  ///   cout << strings::join(", ", values) << endl;
  /// }
  /// @endcode
  /// @remarks same as #using_
  #define block_scope_(...) \
    for (bool __xtd_block_scope__ = true; __xtd_block_scope__; __xtd_block_scope__ = false)\
      for (__VA_ARGS__; __xtd_block_scope__; __xtd_block_scope__ = false)
}
