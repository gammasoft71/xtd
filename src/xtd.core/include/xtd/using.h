/// @file
/// @brief Contains #using_ keyword.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
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
  /// @code
  /// // values is released automatically after the end closure }.
  /// using_(auto values = {1, 2, 3, 4, 5}) {
  ///   cout << ustring::join(", ", values) << endl;
  /// }
  /// @endcode
  /// same as :
  /// @code
  /// using_(auto values = {1, 2, 3, 4, 5})
  ///   cout << ustring::join(", ", values) << endl;
  /// @endcode
  /// same as :
  /// @code
  /// {
  ///   auto values = {1, 2, 3, 4, 5};
  ///   cout << ustring::join(", ", values) << endl;
  /// }
  /// @endcode
  /// @remarks same as #block_scope_
  #define using_(...) \
    for (bool __xtd_using__ = true; __xtd_using__; __xtd_using__ = false)\
      for (__VA_ARGS__; __xtd_using__; __xtd_using__ = false)
}
