/// @file
/// @brief Contains xtd::cdebug ostream.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <iostream>
#include "debugstreambuf.h"

/// @cond
inline xtd::debugstreambuf __cdebugstreambuf__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
  /// @brief Provides an std::ostream for xtd::diagnostics::debug.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  inline std::ostream cdebug(&__cdebugstreambuf__);
#else
  /// @brief Provides an std::ostream for xtd::diagnostics::debug.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  inline std::ostream cdebug(nullptr);
#endif
}
