/// @file
/// @brief Contains #sizeof_ keyword.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "size_of.hpp"

/// @brief Used to obtain the size in bytes of the object representation of type or expression.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @par Examples
/// ```cpp
/// // Get the size of a type :
/// xtd::size size1 = sizeof_<int>();
///
/// int i = 42;
/// // Get the size of an object :
/// xtd::size size2 = sizeof_(i);
/// ```
/// @remarks The #sizeof_ operator cannot be overloaded.
#define sizeof_ \
  xtd::size_of
