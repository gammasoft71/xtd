/// @file
/// @brief Contains xtd::diagnostics::trace_filter class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../collections/generic/list.hpp"
#include "../any_object.hpp"
#include "../abstract.hpp"
#include "../string.hpp"
#include "default_trace_listener.hpp"
#include "source_levels.hpp"
#include "source_switch.hpp"
#include "trace_listener_collection.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides the base class for trace filter implementations.
    /// ```cpp
    /// class core_export_ trace_filter abstract_
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::abstract_object → xtd::diagnostics::trace_filter
    /// @par Header
    /// ```cpp
    /// #include <xtd/diagnostics/trace_filter>
    /// ```
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks Trace filters can be used by trace listeners to provide an extra layer of filtering beyond that provided by trace switches. The trace filter for a trace listener can be found in the listener's filter property. Trace switches determine if a trace is to be sent to the trace listeners. Trace filters allow the individual trace listeners to determine whether or not the trace is to be written to the associated output medium. For example, as determined by each trace filter, a trace may be written to the console by a console_trace_listener, but not to the event log by a event_log_trace_listener.
    /// @remarks Filters that inherit from the trace_filter class can be used by trace listeners that inherit from the trace_listener class to perform filtering of events being traced. trace_filter contains a single method, should_trace, which takes event data and returns a flag indicating whether the event should be traced.
    class core_export_ trace_filter abstract_ {
    public:
      /// @name Public Methods
      
      /// @{
      /// @brief When overridden in a derived class, determines whether the trace listener should trace the event.
      /// @param cache The trace_event_cache that contains information for the trace event.
      /// @param source The name of the source.
      /// @param event_type One of the trace_event_type values specifying the type of event that has caused the trace
      /// @param id A trace identifier number.
      /// @param message Message to write.
      /// @param data1 A trace data object.
      /// @param data_array A trace data object.
      virtual bool should_trace(const xtd::diagnostics::trace_event_cache& cache, const xtd::string& source, xtd::diagnostics::trace_event_type event_type, int32 id, const xtd::string& message, xtd::any_object data1, const xtd::collections::generic::list<xtd::any_object>& data_array) noexcept = 0;
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initializes a new instance of the trace_filter class.
      trace_filter() = default;
      /// @}
      
      /// @name Protectted methods
      
      /// @{
      /// @brief determines whether the trace listener should trace the event.
      /// @param cache The trace_event_cache that contains information for the trace event.
      /// @param source The name of the source.
      /// @param event_type One of the trace_event_type values specifying the type of event that has caused the trace
      /// @param id A trace identifier number.
      /// @param message Message to write.
      bool should_trace(const xtd::diagnostics::trace_event_cache& cache, const xtd::string& source, xtd::diagnostics::trace_event_type event_type, int32 id, const xtd::string& message) noexcept;
      /// @brief determines whether the trace listener should trace the event.
      /// @param cache The trace_event_cache that contains information for the trace event.
      /// @param source The name of the source.
      /// @param event_type One of the trace_event_type values specifying the type of event that has caused the trace
      /// @param id A trace identifier number.
      /// @param message Message to write.
      /// @param data1 A trace data object.
      bool should_trace(const xtd::diagnostics::trace_event_cache& cache, const xtd::string& source, xtd::diagnostics::trace_event_type event_type, int32 id, const xtd::string& message, xtd::any_object data1) noexcept;
      /// @}
    };
  }
}
