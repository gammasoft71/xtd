/// @file
/// @brief Contains xtd::diagnostics::debug class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <cstdlib>
#include <mutex>
#include "../core_export.h"
#include "../static.h"

/// @cond
// Workaround : the std::abort function on Visual Studio shows a message box.
#if defined(_MSC_VER)
#define __std_abort__ __debugbreak
#else
#define __std_abort__ std::abort
#endif
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Enables communication with a debugger. This class cannot be inherited.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core diagnostics debug
    class core_export_ debugger static_ {
    public:
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
      /// @note The category parameter is limited to 256 characters. std::strings longer than 256 characters are truncated.
      static void log(int level, std::string& category, const std::string& message);
    };
  }
}

#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
#if defined(_MSC_VER)
/// @brief Signals a breakpoint to an attached debugger.
/// @par Library
/// xtd.core
/// @ingroup xtd_core debug
/// @par Examples
/// The following code example demonstrates how to stop the debugger at the call to write_line.
/// @code
/// debug_break_();
/// console::write_line("Hello, world.");
/// @endcode
#define debug_break_() {\
  xtd::diagnostics::debugger::launch(); \
  __debugbreak(); \
}
#else
/// @brief Signals a breakpoint to an attached debugger.
/// @par Library
/// xtd.core
/// @ingroup xtd_core debug
/// @par Examples
/// The following code example demonstrates how to stop the debugger at the call to write_line.
/// @code
/// debug_break_();
/// console::write_line("Hello, world.");
/// @endcode
#define debug_break_() {\
  xtd::diagnostics::debugger::launch(); \
  std::abort(); \
}
#endif
#else
/// @brief Signals a breakpoint to an attached debugger.
/// @par Library
/// xtd.core
/// @ingroup xtd_core debug
/// @par Examples
/// The following code example demonstrates how to stop the debugger at the call to write_line.
/// @code
/// debug_break_();
/// console::write_line("Hello, world.");
/// @endcode
#define debug_break_()
#endif
