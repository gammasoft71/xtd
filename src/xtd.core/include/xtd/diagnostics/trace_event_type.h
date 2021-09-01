/// @file
/// @brief Contains xtd::diagnostics::trace_event_type enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Identifies the type of event that has caused the trace.
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @see trace
    enum class trace_event_type {
      /// @brief Fatal error or application crash.
      critical = 0b1,
      /// @brief Recoverable error.
      error = 0b10,
      /// @brief Warning Noncritical problem.
      warning = 0b100,
      /// @brief Informational message.
      information = 0b1000,
      /// @brief Debugging trace.
      verbose = 0b10000,
      /// @brief Starting of a logical operation.
      start = 0b100000000,
      /// @brief Stopping of a logical operation.
      stop = 0b1000000000,
      /// @brief Suspension of a logical operation.
      suspend = 0b10000000000,
      /// @brief Resumption of a logical operation.
      resume = 0b100000000000,
      /// @brief Changing of correlation identity.
      transfer = 0b1000000000000,
    };

    inline std::ostream& operator<<(std::ostream& os, xtd::diagnostics::trace_event_type value) {return os << to_string(value, {{diagnostics::trace_event_type::critical, "critical"}, {diagnostics::trace_event_type::error, "error"}, {diagnostics::trace_event_type::information, "information"}, {diagnostics::trace_event_type::resume, "resume"}, {diagnostics::trace_event_type::start, "start"}, {diagnostics::trace_event_type::stop, "stop"}, {diagnostics::trace_event_type::suspend, "suspend"}, {diagnostics::trace_event_type::transfer, "transfer"}, {diagnostics::trace_event_type::verbose, "verbose"}, {diagnostics::trace_event_type::warning, "warning"}});}
    inline std::wostream& operator<<(std::wostream& os, xtd::diagnostics::trace_event_type value) {return os << to_string(value, {{diagnostics::trace_event_type::critical, L"critical"}, {diagnostics::trace_event_type::error, L"error"}, {diagnostics::trace_event_type::information, L"information"}, {diagnostics::trace_event_type::resume, L"resume"}, {diagnostics::trace_event_type::start, L"start"}, {diagnostics::trace_event_type::stop, L"stop"}, {diagnostics::trace_event_type::suspend, L"suspend"}, {diagnostics::trace_event_type::transfer, L"transfer"}, {diagnostics::trace_event_type::verbose, L"verbose"}, {diagnostics::trace_event_type::warning, L"warning"}});}
  }
}
