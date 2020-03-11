/// @file
/// @brief Contains xtd::ctrace object.
#pragma once
#include <iostream>
#include "tracestreambuf.h"

inline xtd::diagnostics::tracestreambuf __ctracestreambuf__;

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
#if defined(TRACE)
  inline std::ostream ctrace(&__ctracestreambuf__);
#else
  inline std::ostream ctrace(nullptr);
#endif
}
