/// @file
/// @brief Contains xtd::cdebug ostream.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "debugstreambuf.hpp"
#include <iostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
  /// @brief A xtd::debugstreambuf variable used by xtd::cdebug ostream.
  inline xtd::debugstreambuf cdebugstreambuf;
  
  /// @brief Provides an std::ostream for xtd::diagnostics::debug.
  /// @par Header
  /// ```cpp
  /// #include <xtd/cdebug>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core debug
  inline std::ostream cdebug(&cdebugstreambuf);
  #else
  /// @brief Provides an std::ostream for xtd::diagnostics::debug.
  /// @par Header
  /// ```cpp
  /// #include <xtd/cdebug>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core debug
  inline std::ostream cdebug(nullptr);
  #endif
}
