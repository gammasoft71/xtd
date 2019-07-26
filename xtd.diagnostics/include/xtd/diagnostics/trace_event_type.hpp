/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once
#include <xtd/xtd.strings>

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

    inline std::ostream& operator<<(std::ostream& os, xtd::diagnostics::trace_event_type value) {return os << to_string(value, {{diagnostics::trace_event_type::critical, "critical"}, {diagnostics::trace_event_type::error, "error"}, {diagnostics::trace_event_type::information, "information"}, {diagnostics::trace_event_type::resume, "resume"}, {diagnostics::trace_event_type::start, "start"}, {diagnostics::trace_event_type::stop, "stop"}, {diagnostics::trace_event_type::suspend, "suspend"}, {diagnostics::trace_event_type::transfer, "transfer"}, {diagnostics::trace_event_type::verbose, "verbose"}, {diagnostics::trace_event_type::warning, "warning"}});}
    inline std::wostream& operator<<(std::wostream& os, xtd::diagnostics::trace_event_type value) {return os << to_string(value, {{diagnostics::trace_event_type::critical, L"critical"}, {diagnostics::trace_event_type::error, L"error"}, {diagnostics::trace_event_type::information, L"information"}, {diagnostics::trace_event_type::resume, L"resume"}, {diagnostics::trace_event_type::start, L"start"}, {diagnostics::trace_event_type::stop, L"stop"}, {diagnostics::trace_event_type::suspend, L"suspend"}, {diagnostics::trace_event_type::transfer, L"transfer"}, {diagnostics::trace_event_type::verbose, L"verbose"}, {diagnostics::trace_event_type::warning, L"warning"}});}
  }
}
