/// @file
/// @brief Contains #block_scope_ keyword.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "using.hpp"

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
/// same as :
/// ```cpp
/// block_scope_(auto values = {1, 2, 3, 4, 5})
///   cout << string::join(", ", values) << endl;
/// ```
/// same as :
/// ```cpp
/// {
///   auto values = {1, 2, 3, 4, 5};
///   cout << string::join(", ", values) << endl;
/// }
/// ```
/// @remarks same as #using_
#define block_scope_ \
  using_
