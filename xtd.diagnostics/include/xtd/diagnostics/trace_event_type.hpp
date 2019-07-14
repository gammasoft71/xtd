/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once
#include <map>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Identifies the type of event that has caused the trace.
    /// @see trace
    enum class trace_event_type {
      /// @brief Fatal error or application crash.
      critical,
      /// @brief Recoverable error.
      error,
      /// @brief Informational message.
      information,
      /// @brief Resumption of a logical operation.
      resume,
      /// @brief Starting of a logical operation.
      start,
      /// @brief Stopping of a logical operation.
      stop,
      /// @brief Suspension of a logical operation.
      suspend,
      /// @brief Changing of correlation identity.
      transfer,
      /// @brief Debugging trace.
      verbose,
      /// @brief Warning Noncritical problem.
      warning
    };
  }
}
