/// @file
/// @brief Contains xtd::diagnostics::debug_break keyword.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "debugger.h"

/// @brief Signals a breakpoint to an attached debugger.
/// @par Header
/// @code #include <xtd/diagnostics/debug_break> @endcode
/// @par Library
/// xtd.core
/// @ingroup xtd_core debug
/// @par Examples
/// The following code example demonstrates how to stop the debugger at the call to write_line.
/// @code
/// debug_break_();
/// console::write_line("Hello, world.");
/// @endcode
#define debug_break_() \
  if (xtd::diagnostics::debugger::launch()) __xtd_debugbreak()
