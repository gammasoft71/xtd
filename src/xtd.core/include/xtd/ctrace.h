/// @file
/// @brief Contains xtd::ctrace ostream.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "tracestreambuf.h"
#include <iostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  #if defined(TRACE)
  /// @brief A xtd::tracestreambuf variable used by xtd::ctrace ostream.
  inline xtd::tracestreambuf ctracestreambuf;
  
  /// @brief Provides an std::ostream for xtd::diagnostics::trace.
  /// @par Header
  /// @code #include <xtd/ctrace> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  inline std::ostream ctrace(&ctracestreambuf);
  #else
  /// @brief Provides an std::ostream for xtd::diagnostics::trace.
  /// @par Header
  /// @code #include <xtd/ctrace> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  inline std::ostream ctrace(nullptr);
  #endif
}
