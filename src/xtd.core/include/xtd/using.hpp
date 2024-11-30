/// @file
/// @brief Contains #using_ keyword.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The specified expression is cleared automatically when the scope is ended.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core keywords
  /// @par Examples
  /// ```cpp
  /// // values is released automatically after the end closure }.
  /// using_(auto values = {1, 2, 3, 4, 5}) {
  ///   cout << string::join(", ", values) << endl;
  /// }
  /// ```
  /// same as :
  /// ```cpp
  /// using_(auto values = {1, 2, 3, 4, 5})
  ///   cout << string::join(", ", values) << endl;
  /// ```
  /// same as :
  /// ```cpp
  /// {
  ///   auto values = {1, 2, 3, 4, 5};
  ///   cout << string::join(", ", values) << endl;
  /// }
  /// ```
  /// @remarks same as #block_scope_
#define using_(...) \
  for (bool __xtd_using__ = true; __xtd_using__; __xtd_using__ = false)\
    for (__VA_ARGS__; __xtd_using__; __xtd_using__ = false)
}
