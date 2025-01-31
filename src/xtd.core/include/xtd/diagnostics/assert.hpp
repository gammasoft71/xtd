/// @file
/// @brief Contains xtd::diagnostics::assert_ keyword.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "debug.hpp"
#include "debug_break.hpp"

/// @brief Checks for a condition; if the condition is `false`, displays a message box that shows the call stack.
/// @par Header
/// ```cpp
/// #include <xtd/diagnostics/assert>
/// ```
/// @par Library
/// xtd.core
/// @ingroup xtd_core debug
/// @param condition The conditional expression to evaluate. If the condition is true, a failure message is not sent and the message box is not displayed.
/// @param message (optional) The brief message to send to the xtd::diagnostics::debug::listeners collection.
/// @param detail_message (optional) The detail message to send to the xtd::diagnostics::debug::listeners collection.
/// @par Examples
/// The following example shows how to use #assert_ macro.
/// @include assert_.cpp
/// @par Examples
/// The following example shows how to use #assert_ macro with message.
/// @include assert_with_message.cpp
#define assert_(...) \
  if (xtd::diagnostics::debug::__should_aborted__(__VA_ARGS__)) debug_break_()
