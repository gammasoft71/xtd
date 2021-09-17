/// @file
/// @brief Contains xtd::diagnostics::trace_options enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Specifies trace data options to be written to the trace output.
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
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

    /// @cond
    inline xtd::diagnostics::trace_options& operator^=(xtd::diagnostics::trace_options& lhs, xtd::diagnostics::trace_options rhs) {lhs = static_cast<xtd::diagnostics::trace_options>(static_cast<int>(lhs) ^ static_cast<int>(rhs)); return lhs;}
    inline xtd::diagnostics::trace_options& operator&=(xtd::diagnostics::trace_options& lhs, xtd::diagnostics::trace_options rhs) {lhs = static_cast<xtd::diagnostics::trace_options>(static_cast<int>(lhs) & static_cast<int>(rhs)); return lhs;}
    inline xtd::diagnostics::trace_options& operator|=(xtd::diagnostics::trace_options& lhs, xtd::diagnostics::trace_options rhs) {lhs = static_cast<xtd::diagnostics::trace_options>(static_cast<int>(lhs) | static_cast<int>(rhs)); return lhs;}
    inline xtd::diagnostics::trace_options& operator+=(xtd::diagnostics::trace_options& lhs, xtd::diagnostics::trace_options rhs) {lhs = static_cast<xtd::diagnostics::trace_options>(static_cast<int>(lhs) + static_cast<int>(rhs)); return lhs;}
    inline xtd::diagnostics::trace_options& operator-=(xtd::diagnostics::trace_options& lhs, xtd::diagnostics::trace_options rhs) {lhs = static_cast<xtd::diagnostics::trace_options>(static_cast<int>(lhs) - static_cast<int>(rhs)); return lhs;}
    inline xtd::diagnostics::trace_options operator^(xtd::diagnostics::trace_options lhs, xtd::diagnostics::trace_options rhs) {return static_cast<xtd::diagnostics::trace_options>(static_cast<int>(lhs) ^ static_cast<int>(rhs));}
    inline xtd::diagnostics::trace_options operator&(xtd::diagnostics::trace_options lhs, xtd::diagnostics::trace_options rhs) {return static_cast<xtd::diagnostics::trace_options>(static_cast<int>(lhs) & static_cast<int>(rhs));}
    inline xtd::diagnostics::trace_options operator|(xtd::diagnostics::trace_options lhs, xtd::diagnostics::trace_options rhs) {return static_cast<xtd::diagnostics::trace_options>(static_cast<int>(lhs) | static_cast<int>(rhs));}
    inline xtd::diagnostics::trace_options operator+(xtd::diagnostics::trace_options lhs, xtd::diagnostics::trace_options rhs) {return static_cast<xtd::diagnostics::trace_options>(static_cast<int>(lhs) + static_cast<int>(rhs));}
    inline xtd::diagnostics::trace_options operator-(xtd::diagnostics::trace_options lhs, xtd::diagnostics::trace_options rhs) {return static_cast<xtd::diagnostics::trace_options>(static_cast<int>(lhs) - static_cast<int>(rhs));}
    inline xtd::diagnostics::trace_options operator~(xtd::diagnostics::trace_options lhs) {return static_cast<xtd::diagnostics::trace_options>(~static_cast<int>(lhs));}
    inline std::ostream& operator<<(std::ostream& os, xtd::diagnostics::trace_options value) {return os << to_string(value, {{xtd::diagnostics::trace_options::none, "none"}, {diagnostics::trace_options::logical_operation_stack, "logical_operation_stack"}, {diagnostics::trace_options::date_time, "date_time"}, {diagnostics::trace_options::timestamp, "timestamp"}, {diagnostics::trace_options::process_id, "process_id"}, {diagnostics::trace_options::thread_id, "thread_id"}, {diagnostics::trace_options::callstack, "callstack"}});}
    inline std::wostream& operator<<(std::wostream& os, xtd::diagnostics::trace_options value) {return os << to_string(value, {{xtd::diagnostics::trace_options::none, L"none"}, {diagnostics::trace_options::logical_operation_stack, L"logical_operation_stack"}, {diagnostics::trace_options::date_time, L"date_time"}, {diagnostics::trace_options::timestamp, L"timestamp"}, {diagnostics::trace_options::process_id, L"process_id"}, {diagnostics::trace_options::thread_id, L"thread_id"}, {diagnostics::trace_options::callstack, L"callstack"}});}
    /// @endcond
  }
}
