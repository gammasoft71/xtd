/// @file
/// @brief Contains xtd::diagnostics::debug class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cassert>
#include "assert_dialog_result.h"
#include "../strings.h"

/// @cond
// Workaround : the standard c++ assert macro on Visual Studio shows a message box.
#ifdef __VISUALC__
#define xtd_debug_break() __debugbreak()
#else
#define xtd_debug_break() assert(false)
#endif
/// @endcond

/// @brief Checks for a condition; if the condition is false, displays a message box that shows the call stack.
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @param condition The conditional expression to evaluate. If the condition is true, a failure message is not sent and the message box is not displayed.
/// @param message The message to send to the xtd::diagnostics::debug::listeners collection.
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
#define xtd_assert_message(condition, message) \
  if (!condition) { \
    xtd::diagnostics::debug::fail(message); \
    auto result = xtd::diagnostics::debug::assert_dialog(xtd::strings::format("{}\n\n{}", message, xtd::diagnostics::stack_trace(xtd::diagnostics::stack_frame(csf_)))); \
    if (result == xtd::diagnostics::assert_dialog_result::abort) ::exit(EXIT_FAILURE); \
    if (result == xtd::diagnostics::assert_dialog_result::retry) xtd_debug_break(); \
  }

/// @brief Checks for a condition; if the condition is false, displays a message box that shows the call stack.
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @param condition The conditional expression to evaluate. If the condition is true, a failure message is not sent and the message box is not displayed.
#define xtd_assert(condition) \
  xtd_assert_message(condition, "")
#else
#define xtd_assert(condition)
#define xtd_assert_message(condition, message)
#endif
