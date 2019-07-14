/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once
#include <any>
#include <string>
#include <vector>
#include <xtd/diagnostics/trace_event_cache.hpp>
#include <xtd/diagnostics/trace_event_type.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides the base class for trace filter implementations.
    class trace_filter {
    public:
      /// @brief Initializes a new instance of the TraceFilter class.
      trace_filter() = default;
      
      /// @brief When overridden in a derived class, determines whether the trace listener should trace the event.
      /// @param cache The trace_event_cache that contains information for the trace event.
      /// @param source The name of the source.
      /// @param event_type One of the trace_event_type values specifying the type of event that has caused the trace.
      /// @param id A trace identifier number.
      /// @param format_or_message Either the format to use for writing an array of arguments specified by the args parameter, or a message to write.
      /// @param args An array of argument objects.
      /// @param data1 A trace data object.
      /// @param data An array of trace data objects.
      /// @return true to trace the specified event; otherwise, false.
      /// @remarks Implementations of this method should return true if the event specified by the passed parameters should be traced. Otherwise the method should return false. For example, a filter that allows only error events to pass through to the listener should inspect the eventType parameter and return true if the trace event type level is set to TraceEventType.Error or greater; otherwise, it should return false.
      /// @remarks Implementations of the method should be prepared to handle null in the following parameters: args, data1, data, formatOrMessage, and cache. If the parameter value is null, the parameter is not part of the event. For example, if the args parameter is null, it means that the event does not have any arguments. If the data parameter is null, then there are either one or no data objects. If there is one data object, it will be found in the data1 parameter. The reason for the distinction between a single data object and an array of data objects is for performance. There is no reason to create an object array if only one object is traced, as is normally the case. If the data parameter is not null, the data1 parameter must also not be null.
      /// @remarks It is guaranteed that the source parameter is not null and not an empty string ("").
      virtual bool should_trace(const trace_event_cache& cache, const std::string& source, const trace_event_type& event_type, int id, const std::string& format_or_message, const std::vector<std::any>& args, const std::any& data1, const std::vector<std::any>& data) = 0;
    };
  }
}
