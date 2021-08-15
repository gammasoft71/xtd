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
      /// @brief Signals a breakpoint to an attached debugger.
      /// @warning Internal use only
      static void debug_break();
      /// @brief Gets a value that indicates whether a debugger is attached to the process.
      /// @return true if a debugger is attached; otherwise, false.
      /// @warning Internal use only
      static bool is_attached();
      /// @brief Checks to see if logging is enabled by an attached debugger.
      /// @return true if a debugger is attached and logging is enabled; otherwise, false.
      /// @warning Internal use only
      static bool is_logging();
      /// @brief Launches and attaches a debugger to the process.
      /// @return true if the startup is successful or if the debugger is already attached; otherwise, false.
      /// @remarks If a debugger is already attached, nothing happens.
      /// @remarks Debugger launch is only supported on Windows operating system. On Unix and macOS operating systems, the method returns true without launching a debugger.
      /// @warning Internal use only
      static bool launch();
      /// @brief Displays an assert dialog that shows the text.
      /// @param text The assert dialog text.
      /// @param caption The assert dialog caption.
      /// @return The assert dialog result. (see assert_dialog_results.h file).
      /// @remarks In general the assert dialog is a system message box.
      /// @warning Internal use only
     static int32_t show_assert_dialog(const std::string& text, const std::string& caption);
      /// @brief Posts a message for the attached debugger.
      /// @param level A description of the importance of the message.
      /// @param category The category of the message.
      /// @param message The message to show.
      /// @remarks If there is no debugger attached, this method has no effect. The debugger might or might not report the message, depending upon its settings.
      /// @warning Internal use only
      static void log(int32_t level, const std::string& category, const std::string& message);
    };
  }
}
