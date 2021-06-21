/// @file
/// @brief Contains xtd::diagnostics::debug class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdlib>
#define __XTD_CORE_INTERNAL__
#include "../internal/__assert.h"
#undef __XTD_CORE_INTERNAL__

/// @brief Checks for a condition; if the condition is false, displays a message box that shows the call stack.
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @param condition The conditional expression to evaluate. If the condition is true, a failure message is not sent and the message box is not displayed.
/// @param message (optional) The message to send to the xtd::diagnostics::debug::listeners collection.
/// @param stack_frame (optional) The stack frame corresponding to the generated assert.
#define xtd_assert_(...) \
  xtd::diagnostics::debug::cassert_(__VA_ARGS__)
