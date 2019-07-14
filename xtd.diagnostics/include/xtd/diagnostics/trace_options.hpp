/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once
#include <map>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Specifies trace data options to be written to the trace output.
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
