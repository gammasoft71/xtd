/// @file
/// @brief Contains xtd::cdebug object.
#pragma once
#include <iostream>
#include "debugstreambuf.h"

inline xtd::diagnostics::debugstreambuf __cdebugstreambuf__;

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
  /// @brief Provides an std::ostream for xtd::diagnostics::debug.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  inline std::ostream cdebug(&__cdebugstreambuf__);
#else
  /// @brief Provides an std::ostream for xtd::diagnostics::debug.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  inline std::ostream cdebug(nullptr);
#endif
}
