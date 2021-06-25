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
    /// @brief Provides a set of methods and properties that help you debug the execution of your code. This class cannot be inherited.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core diagnostics debug
    class core_export_ debugger static_ {
    public:
      /// @brief Gets a value that indicates whether a debugger is attached to the process.
      /// @return true if a debugger is attached; otherwise, false.
      static bool is_attached();

      /// @brief Signals a breakpoint to an attached debugger.
      /// @remarks f no debugger is attached, users are asked if they want to attach a debugger. If users say yes, the debugger is started. If a debugger is attached, the debugger is signaled with a user breakpoint event, and the debugger suspends execution of the process just as if a debugger breakpoint had been hit.
      /// @par Examples
      /// The following code example demonstrates how to stop the debugger at the call to write_line.
      /// @code
      /// debugger_break_();
      /// console::write_line("Hello, world.");
      /// @endcode
      static void debug_break();

      static bool is_logging();

      static bool launch();

      static void log(int level, std::string& category, const std::string& message);
    };
  }
}

#if defined(_MSC_VER)
/// @brief Signals a breakpoint to an attached debugger.
/// @par Library
/// xtd.core
/// @ingroup xtd_core debug
/// @par Examples
/// The following code example demonstrates how to stop the debugger at the call to write_line.
/// @code
/// debugger_break_();
/// console::write_line("Hello, world.");
/// @endcode
#define debug_break_() \
  __debugbreak()
#else
#define debug_break_() \
  std::abort()
#endif
