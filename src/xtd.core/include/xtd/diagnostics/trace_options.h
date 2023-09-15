/// @file
/// @brief Contains xtd::diagnostics::trace_options enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../enum"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Specifies trace data options to be written to the trace output.
    /// @code
    /// enum class trace_options
    /// @endcode
    /// @par Header
    /// @code #include <xtd/diagnostics/trace_options> @endcode
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core diagnostics
    /// @remarks This enumeration is used by trace listeners to determine which options, or elements, should be included in the trace output. Trace listeners store the trace options in the trace_output_options property.
    enum class trace_options {
      /// @brief Do not write any elements.
      none = 0,
      /// @brief Write the logical operation stack, which is represented by the return value of the CorrelationManager.LogicalOperationStack property.
      logical_operation_stack = 0b1,
      /// @brief Write the date and time.
      date_time = 0b10,
      /// @brief Write the timestamp, which is represented by the return value of the GetTimestamp method.
      timestamp = 0b100,
      /// @brief Write the process identity, which is represented by the return value of the Process.Id property.
      process_id = 0b1000,
      /// @brief Write the thread identity, which is represented by the return value of the Thread.ManagedThreadId property for the current thread.
      thread_id = 0b10000,
      /// @brief Write the call stack, which is represented by the return value of the Environment.StackTrace property.
      callstack = 0b100000
    };
  }
}

/// @cond
flags_attribute_(xtd::diagnostics, trace_options);

template<> struct xtd::enum_register<xtd::diagnostics::trace_options> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::diagnostics::trace_options> {{xtd::diagnostics::trace_options::none, "none"}, {xtd::diagnostics::trace_options::logical_operation_stack, "logical_operation_stack"}, {xtd::diagnostics::trace_options::date_time, "date_time"}, {xtd::diagnostics::trace_options::timestamp, "timestamp"}, {xtd::diagnostics::trace_options::process_id, "process_id"}, {xtd::diagnostics::trace_options::thread_id, "thread_id"}, {xtd::diagnostics::trace_options::callstack, "callstack"}};}
};
/// @endcond
