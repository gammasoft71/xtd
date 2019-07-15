/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once

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

    inline std::ostream& operator<<(std::ostream& os, xtd::diagnostics::trace_event_type tet) {
      switch (tet) {
        case xtd::diagnostics::trace_event_type::critical: os << "critical"; break;
        case xtd::diagnostics::trace_event_type::error: os << "error"; break;
        case xtd::diagnostics::trace_event_type::information: os << "information"; break;
        case xtd::diagnostics::trace_event_type::resume: os << "resume"; break;
        case xtd::diagnostics::trace_event_type::start: os << "start"; break;
        case xtd::diagnostics::trace_event_type::stop: os << "stop"; break;
        case xtd::diagnostics::trace_event_type::suspend: os << "suspend"; break;
        case xtd::diagnostics::trace_event_type::transfer: os << "transfer"; break;
        case xtd::diagnostics::trace_event_type::verbose: os << "verbose"; break;
        case xtd::diagnostics::trace_event_type::warning: os << "warning"; break;
      }
      return os;
    }
  }
}
