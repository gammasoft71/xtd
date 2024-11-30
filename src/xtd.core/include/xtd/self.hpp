/// @file
/// @brief Contains #self_ keyword.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
}

/// @brief The #self_ expression is a reference value expression whose value is the reference of the implicit object parameter (the object on which the non-static member function (up to C++23) implicit object member function (since C++23) is called).
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @remarks #self_ is equivalent to *this.
#define self_\
  (*this)
