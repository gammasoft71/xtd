/// @file
/// @brief Contains xtd::diagnostics::event_type_filter class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "source_levels.hpp"
#include "trace_filter.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Indicates whether a listener should trace based on the event type.
    /// ```cpp
    /// class core_export_ event_type_filter : public xtd::diagnostics::trace_filter
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::abstract_object → xtd::diagnostics::trace_filter → xtd::diagnostics::event_type_filter
    /// @par Header
    /// ```cpp
    /// #include <xtd/diagnostics/event_type_filter>
    /// ```
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks One of several different types of filters can be assigned to a trace listener through the xtd::diagnostics::trace_listener::filter property to provide a layer of screening beyond that provided by the xtd::diagnostics::trace_switch. The filter can be used to control the event types that are produced by the listener.
    /// @remarks This class filters events based on the value of the xtd::diagnostics::event_type_filter::event_type property. This property can be set by code to specify the event type of messages that should be traced by the listener. The value of the property indicates the threshold at which to begin tracing. Event types at and above the specified level are traced. The xtd::diagnostics::event_type_filter::should_trace method, called by listeners to determine if an event should be traced, uses the value of the xtd::diagnostics::event_type_filter::event_type property.
    class core_export_ event_type_filter : public xtd::diagnostics::trace_filter {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the event_type_filter class.
      /// @param level A bitwise combination of the xtd::diagnostics::source_levels values that specifies the event type of the messages to trace.
      explicit event_type_filter(xtd::diagnostics::source_levels level);
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the event type of the messages to trace.
      /// @return A bitwise combination of the xtd::diagnostics::source_levels values.
      /// @remarks The xtd::diagnostics::event_type_filter::event_type property indicates the level at which to trace.
      xtd::diagnostics::source_levels event_type() const noexcept;
      /// @brief Sets the event type of the messages to trace.
      /// @param level A bitwise combination of the xtd::diagnostics::source_levels values.
      /// @remarks The xtd::diagnostics::event_type_filter::event_type property indicates the level at which to trace.
      void event_type(xtd::diagnostics::source_levels level) noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Determines whether the trace listener should trace the event.
      /// @param cache The xtd::diagnostics::trace_event_cache that contains information for the trace event.
      /// @param source The name of the source.
      /// @param event_type One of the trace_event_type values specifying the type of event that has caused the trace
      /// @param id A trace identifier number.
      /// @param message Message to write.
      /// @param data1 A trace data object.
      /// @param data_array A trace data object.
      /// @remarks If the value of the event_type parameter is greater than or equal to the value of the xtd::diagnostics::event_type_filter::event_type property, the method returns `true`.
      bool should_trace(const xtd::diagnostics::trace_event_cache& cache, const xtd::string& source, xtd::diagnostics::trace_event_type event_type, int32 id, const xtd::string& message, xtd::any_object data1, const xtd::collections::generic::list<xtd::any_object>& data_array) noexcept override;
      /// @}
      
    private:
      xtd::diagnostics::source_levels level_ = xtd::diagnostics::source_levels::off;
    };
  }
}
