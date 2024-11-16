/// @file
/// @brief Contains #sizeof_ keyword.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Used to obtain the size in bytes of the object representation of type or expression.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core keywords
  /// @par Examples
  /// Some C++ examples:
  /// @include sizeof.cpp
#define sizeof_(...) \
  sizeof(__VA_ARGS__)
}
