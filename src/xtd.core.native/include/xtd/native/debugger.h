/// @file
/// @brief Contains debug API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
#include <cstdint>
#include <map>
#include <string>
#include <vector>
#include "constant_special_item_id_list.h"
#include "environment_variable_target.h"
#include "platform_ids.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace diagnostics {
    class debug;
    class debugger;
    class default_trace_listener;
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains debugger native API.
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ debugger final {
      friend xtd::diagnostics::debug;
      friend xtd::diagnostics::debugger;
      friend xtd::diagnostics::default_trace_listener;
    protected:
      static void debug_break();
      static bool is_attached();
      static bool is_logging();
      static bool launch();
      /// @brief Displays an assert dialog that shows the text.
      /// @param text The assert dialog text.
      /// @param caption The assert dialog caption.
      /// @return The assert dialog result. (see assert_dialog_results.h file).
      /// @remarks In general the assert dialog is a system message box.
      /// @warning Internal use only
     static int32_t show_assert_dialog(const std::string& text, const std::string& caption);
      /// @brief Writes a specified message to the debuger output.
      /// @param message Message to write.
      /// @warning Internal use only
      static void log(int32_t level, const std::string& category, const std::string& message);
    };
  }
}
