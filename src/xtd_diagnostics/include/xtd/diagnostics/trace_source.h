/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once
#include <map>
#include "default_trace_listener.h"
#include "source_levels.h"
#include "source_switch.h"
#include "trace_listener_collection.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides a set of methods and properties that enable applications to trace the execution of code and associate trace messages with their source.
    /// @remarks The trace_source class is used by applications to produce traces that can be associated with the application. trace_source provides tracing methods that allow you to easily trace events, trace data, and issue informational traces.
    /// @remarks The trace_source class is identified by the name of a source, typically the name of the application. The trace messages coming from a particular component can be initiated by a particular trace source, allowing all messages coming from that component to be easily identified.
    /// @remarks trace_source defines tracing methods but does not actually provide any specific mechanism for generating and storing tracing data. The tracing data is produced by trace listeners, which are plug-ins that can be loaded by trace sources.
    /// @remarks You can customize the tracing output's target by adding or removing trace_istener instances to or from the collection stored in the trace_source::listeners property. By default, trace output is produced using an instance of the default_trace_listener class.
    /// @note Adding a trace listener to the listeners collection can cause an exception to be thrown while tracing, if a resource used by the trace listener is not available. The conditions and the exception thrown depend on the trace listener and cannot be enumerated in this topic. It may be useful to place calls to the trace_source methods in try/catch blocks to detect and handle any exceptions from trace listeners.
    /// @remarks The source_switch class provides the means to dynamically control the tracing output. You can modify the value of the source switch without recompiling your application.
    /// @remarks The trace_event_type enumeration is used to define the event type of the trace message. Trace filters use the trace_event_type to determine if a trace listener should produce the trace message.
    /// @remarks The trace listeners can optionally have an additional layer of filtering through a trace filter. If a trace listener has an associated filter, the listener calls the should_trace method on that filter to determine whether or not to produce the trace information.
    /// @remarks The trace listeners use the values of the trace class properties indent, indent_size, and  auto_flush to format trace output.
    class trace_source {
    public:
      /// @brief Initializes a new instance of the Trace_Source class, using the specified name for the source.
      /// @param name The name of the source (typically, the name of the application).
      explicit trace_source(const std::string& name) : name_(name) {}
      /// @brief Initializes a new instance of the Trace_Source class, using the specified name for the source.
      /// @param name The name of the source (typically, the name of the application).
      /// @param default_level A bitwise combination of the enumeration values that specifies the default source level at which to trace
      explicit trace_source(const std::string& name, xtd::diagnostics::source_levels default_levels) : name_(name), switch_levels_(default_levels) {}

      /// @brief Gets the collection of trace listeners for the trace source.
      /// @return A trace_listener_collection that contains the active trace listeners associated with the source.
      /// @remarks Use this property to access and perform operations on the trace listeners.
      xtd::diagnostics::trace_listener_collection& listeners() {return listeners_;}
      
      /// @brief Sets the collection of trace listeners for the trace source.
      /// @param listeners A trace_listener_collection that contains the active trace listeners associated with the source.
      /// @remarks Use this property to access and perform operations on the trace listeners.
      void listeners(const xtd::diagnostics::trace_listener_collection& listeners) {listeners_ = listeners;}

      /// @brief Gets the name of the trace source.
      /// @return The name of the trace source.
      const std::string& name() const {return name_;}
      
    private:
      std::map<std::string, std::string> attributes_;
      std::string name_;
      xtd::diagnostics::source_levels switch_levels_ = xtd::diagnostics::source_levels::off;
      xtd::diagnostics::trace_listener_collection listeners_ {std::make_shared<xtd::diagnostics::default_trace_listener>()};
      xtd::diagnostics::source_switch source_switch_ {""};
    };
  }
}
