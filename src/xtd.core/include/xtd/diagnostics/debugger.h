/// @file
/// @brief Contains xtd::diagnostics::debugger class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <cstdlib>
#include "../core_export"
#include "../static"
#include "../ustring"

#define __XTD_CORE_INTERNAL__
#include "../internal/__std_abort.h"
#undef __XTD_CORE_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Enables communication with a debugger. This class cannot be inherited.
    /// @code
    /// class core_export_ debugger static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::diagnostics::debugger
    /// @par Header
    /// @code #include <xtd/diagnostics/debugger> @endcode
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core diagnostics debug
    class core_export_ debugger static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Gets a value that indicates whether a debugger is attached to the process.
      /// @return true if a debugger is attached; otherwise, false.
      static bool is_attached();
      
      /// @brief Signals a breakpoint to an attached debugger.
      /// @par Examples
      /// The following code example demonstrates how to stop the debugger at the call to write_line.
      /// @code
      /// debugger_break_();
      /// console::write_line("Hello, world.");
      /// @endcode
      static void debug_break();
      
      /// @brief Checks to see if logging is enabled by an attached debugger.
      /// @return true if a debugger is attached and logging is enabled; otherwise, false.
      static bool is_logging();
      
      /// @brief Launches and attaches a debugger to the process.
      /// @return true if the startup is successful or if the debugger is already attached; otherwise, false.
      /// @remarks If a debugger is already attached, nothing happens.
      /// @remarks Debugger launch is only supported on Windows. On Unix and macOS operating systems, the method returns true without launching a debugger.
      static bool launch();
      
      /// @brief Posts a message for the attached debugger.
      /// @param level A description of the importance of the message.
      /// @param category The category of the message.
      /// @param message The message to show.
      /// @remarks If there is no debugger attached, this method has no effect. The debugger might or might not report the message, depending upon its settings.
      /// @note The category parameter is limited to 256 characters. std::string longer than 256 characters are truncated.
      static void log(int32 level, const xtd::ustring& category, const xtd::ustring& message);
      /// @}
    };
  }
}
