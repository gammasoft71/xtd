/// @file
/// @brief Contains xtd::cdebug ostream.
#pragma once
#include <iostream>
#include "tracestreambuf.h"

/// @cond
inline xtd::tracestreambuf __ctracestreambuf__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
#if defined(TRACE)
  /// @brief Provides an std::ostream for xtd::diagnostics::trace.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  inline std::ostream ctrace(&__ctracestreambuf__);
#else
  /// @brief Provides an std::ostream for xtd::diagnostics::trace.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  inline std::ostream ctrace(nullptr);
#endif
}
