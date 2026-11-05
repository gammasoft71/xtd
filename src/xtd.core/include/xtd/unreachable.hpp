/// @file
/// @brief Contains #unreachable_ keyword.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "internal/__xtd_unreachable.hpp"
#undef __XTD_CORE_INTERNAL__
#include <cassert>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The function unreachable expands to a void expression. Executing unreachable() results in undefined behavior.
  /// @remarks An implementation may use this to optimize impossible code branches away (typically, in optimized builds) or to trap them to prevent further execution (typically, in debug builds).
  /// @par Header
  /// ```cpp
  /// #include <xtd/diagnostics/unreachable>
  /// ```
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core debug
  /// @par Examples
  /// The following code example demonstrates how to stop the debugger at the call to write_line.
  /// ```cpp
  ///  switch (value) {
  ///   case 128: [[fallthrough]];
  ///   case 256: [[fallthrough]];
  ///   case 512: return  "good";
  ///   default:  unreachable();
  /// }
  /// ```
  [[noreturn]] inline auto unreachable() -> void {
    assert(false && "xtd::unreachable() was reached");
    __xtd_unreachable();
  }
}
