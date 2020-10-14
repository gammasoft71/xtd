/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once
#include "source_levels.h"
#include "trace_filter.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Indicates whether a listener should trace based on the event type.
    /// @remarks One of several different types of filters can be assigned to a trace listener through the filter property to provide a layer of screening beyond that provided by the trace_switch. The filter can be used to control the event types that are produced by the listener.
    /// @remarks This class filters events based on the value of the event_type property. This property can be set by code to specify the event type of messages that should be traced by the listener. The value of the property indicates the threshold at which to begin tracing. Event types at and above the specified level are traced. The should_trace method, called by listeners to determine if an event should be traced, uses the value of the event_type property.
    class event_type_filter : public xtd::diagnostics::trace_filter {
    public:
      /// @brief Initializes a new instance of the event_type_filter class.
      /// @param level A bitwise combination of the source_levels values that specifies the event type of the messages to trace.
      event_type_filter(xtd::diagnostics::source_levels level) : level_(level) {}

      /// @brief Gets the event type of the messages to trace.
      /// @return A bitwise combination of the source_levels values.
      xtd::diagnostics::source_levels event_type() const {return level_;}
      /// @brief Sets the event type of the messages to trace.
      /// @param level A bitwise combination of the source_levels values.
      void event_type(xtd::diagnostics::source_levels level) {level_ = level;}
      
      /// @brief Determines whether the trace listener should trace the event.
      /// @param chache The trace_event_cache that contains information for the trace event.
      /// @param source The name of the source.
      /// @param event_type One of the trace_event_type values specifying the type of event that has caused the trace
      /// @param id A trace identifier number.
      /// @param message Message to write.
      /// @param data1 A trace data object.
      /// @param data_array A trace data object.
      bool should_trace(const xtd::diagnostics::trace_event_cache& cache, const std::string& source, xtd::diagnostics::trace_event_type event_type, int32_t id, const std::string& message, std::any data1, const std::vector<std::any>& data_array) override {
        return (static_cast<int>(event_type) & static_cast<int>(level_)) != 0;
      }
      
    private:
      xtd::diagnostics::source_levels level_ = xtd::diagnostics::source_levels::off;
    };
  }
}
