/// @file
/// @brief Contains __assert__ macros.

/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#pragma once
#include <cstdlib>

/// @cond
#define __CMD_CASSERT_MACRO_0_ARGS__(cmd) cmd(false, "", csf_)
#define __CMD_CASSERT_MACRO_1_ARGS__(cmd, arg1) cmd(arg1, "", csf_)
#define __CMD_CASSERT_MACRO_2_ARGS__(cmd, arg1, arg2) cmd(arg1, arg2, csf_)
#define __GET_CASSERT_MACRO_LAST_ARG(arg1, arg2, arg3, ...) arg3
#define __CMD_CASSERT_MACRO_CHOOSER(cmd, ...) __GET_CASSERT_MACRO_LAST_ARG(__VA_ARGS__, __CMD_CASSERT_MACRO_2_ARGS__, __CMD_CASSERT_MACRO_1_ARGS__, __CMD_CASSERT_MACRO_0_ARGS__, )
#define __CMD_CASSERT_MACRO_ARGS(cmd, ...) __CMD_CASSERT_MACRO_CHOOSER(cmd, __VA_ARGS__)(cmd, __VA_ARGS__)

// Workaround : the std::abort function on Visual Studio shows a message box.
#if defined(_MSC_VER)
#define __std_abort__ __debugbreak
#else
#define __std_abort__ std::abort
#endif

#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
#define __assert__(condition, message, stack_frame) \
  if (!(condition)) { \
    auto result = xtd::diagnostics::debug::assert_dialog(message, stack_frame); \
    if (result == xtd::diagnostics::assert_dialog_result::abort) std::exit(EXIT_FAILURE); \
    if (result == xtd::diagnostics::assert_dialog_result::retry) __std_abort__(); \
  }
#else
#define __assert__(condition, message, const xtd::diagnostics_stack_frame& stack_frame)
#endif
/// @endcond
