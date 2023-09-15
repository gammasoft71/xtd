/// @file
/// @brief Contains xtd::diagnostics::trace_event_type enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../enum"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Identifies the type of event that has caused the trace.
    /// @code
    /// enum class trace_event_type
    /// @endcode
    /// @par Header
    /// @code #include <xtd/diagnostics/trace_event_type> @endcode
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
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::diagnostics::trace_event_type> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::diagnostics::trace_event_type> {{xtd::diagnostics::trace_event_type::critical, "critical"}, {xtd::diagnostics::trace_event_type::error, "error"}, {xtd::diagnostics::trace_event_type::information, "information"}, {xtd::diagnostics::trace_event_type::resume, "resume"}, {xtd::diagnostics::trace_event_type::start, "start"}, {xtd::diagnostics::trace_event_type::stop, "stop"}, {xtd::diagnostics::trace_event_type::suspend, "suspend"}, {xtd::diagnostics::trace_event_type::transfer, "transfer"}, {xtd::diagnostics::trace_event_type::verbose, "verbose"}, {xtd::diagnostics::trace_event_type::warning, "warning"}};}
};
/// @endcond
