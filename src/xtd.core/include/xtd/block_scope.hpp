/// @file
/// @brief Contains #block_scope_ keyword.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The specified expression is cleared automatically when the scope is ended.
  /// @par Header
  /// ```cpp
  /// #include <xtd/block_scope>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core keywords
  /// @par Examples
  /// ```cpp
  /// // values is released automatically after the end closure }.
  /// block_scope_(auto values = {1, 2, 3, 4, 5}) {
  ///   cout << string::join(", ", values) << endl;
  /// }
  /// ```
  /// @remarks same as #using_
#define block_scope_(...) \
  for (bool __xtd_block_scope__ = true; __xtd_block_scope__; __xtd_block_scope__ = false)\
    for (__VA_ARGS__; __xtd_block_scope__; __xtd_block_scope__ = false)
}
