/// @file
/// @brief Contains xtd::ctrace ostream.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "tracestreambuf.hpp"
#include <iostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  #if !defined(NTRACE)
  /// @brief A xtd::tracestreambuf variable used by xtd::ctrace ostream.
  inline xtd::tracestreambuf ctracestreambuf;
  
  /// @brief Provides an std::ostream for xtd::diagnostics::trace.
  /// @par Header
  /// ```cpp
  /// #include <xtd/ctrace>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core debug
  inline std::ostream ctrace(&ctracestreambuf);
  #else
  /// @brief Provides an std::ostream for xtd::diagnostics::trace.
  /// @par Header
  /// ```cpp
  /// #include <xtd/ctrace>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core debug
  inline std::ostream ctrace(nullptr);
  #endif
}
