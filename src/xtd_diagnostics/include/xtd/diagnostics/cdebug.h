/// @file
/// @brief Contains xtd::cdebug object.
#pragma once
#include <iostream>
#include "debugstreambuf.h"

inline xtd::diagnostics::debugstreambuf __cdebugstreambuf__;

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
  inline std::ostream cdebug(&__cdebugstreambuf__);
#else
  inline std::ostream cdebug(nullptr);
#endif
}
