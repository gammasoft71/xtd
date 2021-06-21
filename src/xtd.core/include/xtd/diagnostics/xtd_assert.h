/// @file
/// @brief Contains xtd::diagnostics::debug class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdlib>
#include "assert_dialog_result.h"
#include "../strings.h"

/// @cond
// Workaround : the std::abort function on Visual Studio shows a message box.
#if defined(_MSC_VER)
#define __std_abort__ __debugbreak
#else
#define __std_abort__ std::abort
#endif
/// @endcond

#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
/// @brief Checks for a condition; if the condition is false, displays a message box that shows the call stack.
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @param condition The conditional expression to evaluate. If the condition is true, a failure message is not sent and the message box is not displayed.
/// @param message The message to send to the xtd::diagnostics::debug::listeners collection.
#define xtd_assert_message_stack_frame(condition, message, stack_frame) \
  if (!(condition)) { \
    auto result = xtd::diagnostics::debug::assert_dialog(message, stack_frame); \
    if (result == xtd::diagnostics::assert_dialog_result::abort) std::exit(EXIT_FAILURE); \
    if (result == xtd::diagnostics::assert_dialog_result::retry) __std_abort__(); \
  }

/// @brief Checks for a condition; if the condition is false, displays a message box that shows the call stack.
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @param condition The conditional expression to evaluate. If the condition is true, a failure message is not sent and the message box is not displayed.
/// @param message The message to send to the xtd::diagnostics::debug::listeners collection.
#define xtd_assert_message(condition, message) \
  xtd_assert_message_stack_frame(condition, message, csf_)

/// @brief Checks for a condition; if the condition is false, displays a message box that shows the call stack.
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @param condition The conditional expression to evaluate. If the condition is true, a failure message is not sent and the message box is not displayed.
#define xtd_assert(condition) \
  xtd_assert_message_stack_frame(condition, "", csf_)
#else
#define xtd_assert_message_stack_frame(condition, message, const xtd::diagnostics_stack_frame& stack_frame)
#define xtd_assert_message(condition, message)
#define xtd_assert(condition)
#endif
