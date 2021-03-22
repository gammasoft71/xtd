/// @file
/// @brief Contains xtd::diagnostics::source_filter class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "trace_filter.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Indicates whether a listener should trace a message based on the source of a trace.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks One of several different types of filters can be assigned to a trace listener to provide a layer of screening beyond that provided by the trace switch. The filter can be used to control the level of tracing that is produced by the listener.
    /// @remarks This class filters events based on a specific trace source set by the user.
    /// @remarks source_filter overrides the should_trace method and defines a source property that specifies the name of the trace source to be traced by the listener.
    /// @note This filter is provided because multiple trace sources can simultaneously use the same trace listener.
    class source_filter : public xtd::diagnostics::trace_filter {
    public:
      /// @brief Initializes a new instance of the source_filter class, specifying the name of the trace source.
      /// @param source The name of the trace source.
      source_filter(const std::string& source) : source_(source) {}

      /// @brief Gets the name of the trace source.
      /// @return The name of the trace source.
      const std::string& source() const {return source_;}
      /// @brief Gets the name of the trace source.
      /// @param source The name of the trace source.
      void source(const std::string& source) {source_ = source;}
      
      /// @brief Determines whether the trace listener should trace the event.
      /// @param chache The trace_event_cache that contains information for the trace event.
      /// @param source The name of the source.
      /// @param event_type One of the trace_event_type values specifying the type of event that has caused the trace
      /// @param id A trace identifier number.
      /// @param message Message to write.
      /// @param data1 A trace data object.
      /// @param data_array A trace data object.
      bool should_trace(const xtd::diagnostics::trace_event_cache& cache, const std::string& source, xtd::diagnostics::trace_event_type event_type, int32_t id, const std::string& message, std::any data1, const std::vector<std::any>& data_array) override {
        return source == source_;
      }
      
    private:
      std::string source_;
    };
  }
}
