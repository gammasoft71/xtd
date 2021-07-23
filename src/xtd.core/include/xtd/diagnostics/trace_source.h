/// @file
/// @brief Contains xtd::diagnostics::trace_source class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <map>
#include "../object.h"
#include "default_trace_listener.h"
#include "source_levels.h"
#include "source_switch.h"
#include "trace_event_cache.h"
#include "trace_listener_collection.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides a set of methods and properties that enable applications to trace the execution of code and associate trace messages with their source.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks The trace_source class is used by applications to produce traces that can be associated with the application. trace_source provides tracing methods that allow you to easily trace events, trace data, and issue informational traces.
    /// @remarks The trace_source class is identified by the name of a source, typically the name of the application. The trace messages coming from a particular component can be initiated by a particular trace source, allowing all messages coming from that component to be easily identified.
    /// @remarks trace_source defines tracing methods but does not actually provide any specific mechanism for generating and storing tracing data. The tracing data is produced by trace listeners, which are plug-ins that can be loaded by trace sources.
    /// @remarks You can customize the tracing output's target by adding or removing trace_istener instances to or from the collection stored in the trace_source::listeners property. By default, trace output is produced using an instance of the default_trace_listener class.
    /// @note Adding a trace listener to the listeners collection can cause an exception to be thrown while tracing, if a resource used by the trace listener is not available. The conditions and the exception thrown depend on the trace listener and cannot be enumerated in this topic. It may be useful to place calls to the trace_source methods in try/catch blocks to detect and handle any exceptions from trace listeners.
    /// @remarks The source_switch class provides the means to dynamically control the tracing output. You can modify the value of the source switch without recompiling your application.
    /// @remarks The trace_event_type enumeration is used to define the event type of the trace message. Trace filters use the trace_event_type to determine if a trace listener should produce the trace message.
    /// @remarks The trace listeners can optionally have an additional layer of filtering through a trace filter. If a trace listener has an associated filter, the listener calls the should_trace method on that filter to determine whether or not to produce the trace information.
    /// @remarks The trace listeners use the values of the trace class properties indent, indent_size, and  auto_flush to format trace output.
    class trace_source : public object {
    public:
      /// @brief Initializes a new instance of the Trace_Source class, using the specified name for the source.
      /// @param name The name of the source (typically, the name of the application).
      explicit trace_source(const std::string& name);
      /// @brief Initializes a new instance of the Trace_Source class, using the specified name for the source.
      /// @param name The name of the source (typically, the name of the application).
      /// @param default_level A bitwise combination of the enumeration values that specifies the default source level at which to trace
      explicit trace_source(const std::string& name, xtd::diagnostics::source_levels default_levels);

      /// @brief Gets the collection of trace listeners for the trace source.
      /// @return A trace_listener_collection that contains the active trace listeners associated with the source.
      /// @remarks Use this property to access and perform operations on the trace listeners.
      xtd::diagnostics::trace_listener_collection& listeners();
      
      /// @brief Sets the collection of trace listeners for the trace source.
      /// @param listeners A trace_listener_collection that contains the active trace listeners associated with the source.
      /// @remarks Use this property to access and perform operations on the trace listeners.
      void listeners(const xtd::diagnostics::trace_listener_collection& listeners);

      /// @brief Gets the name of the trace source.
      /// @return The name of the trace source.
      const std::string& name() const;
      
      /// @brief Gets the source switch value.
      /// @return A SourceSwitch object representing the source switch value.
      /// @remarks The source_switch property allows the filtering of messages before the trace source calls the listeners.
      /// @remarks The switch is used to check whether trace calls should be generated or ignored. Each trace method calls the should_trace method of the source_switch to determine whether to proceed with the trace. If the call returns true, the listeners are called.
      const xtd::diagnostics::source_switch& source_switch() const;
      /// @brief Sets the source switch value.
      /// @param source_switch A SourceSwitch object representing the source switch value.
      /// @remarks The source_switch property allows the filtering of messages before the trace source calls the listeners.
      /// @remarks The switch is used to check whether trace calls should be generated or ignored. Each trace method calls the should_trace method of the source_switch to determine whether to proceed with the trace. If the call returns true, the listeners are called.
      void source_switch(const xtd::diagnostics::source_switch& source_switch);
            
      /// @brief Closes all the trace listeners in the trace listener collection.
      /// @remarks The close method calls the close method of each trace listener in the listeners collection.
      void close();
      
      /// @brief Flushes all the trace listeners in the trace listener collection.
      /// @remarks The flush method calls the flush method of each trace listener in the listeners collection.
      void flush();
      
      /// @brief Writes trace data to the trace listeners in the Listeners collection using the specified event type, event identifier, and trace data.
      /// @param event_type One of the enumeration values that specifies the event type of the trace data.
      /// @param id A numeric identifier for the event.
      /// @param data The trace data.
      /// @remarks The trace_data method, like the trace_event method, is intended for automated tools, but it also allows the attaching of an additional object, such as an exception instance, to the trace.
      /// @remarks The trace_data method calls the source_switch::should_trace method of the source_switch object returned by the source_switch property. If should_trace returns true, trace_data calls the corresponding trace_data method on all listeners. Otherwise, trace_data returns without calling the listeners' methods.
      template<typename object_t>
      void trace_data(const xtd::diagnostics::trace_event_type& event_type, int32_t id, const object_t& data) {
#if defined(TRACE)
        if (source_switch_.should_trace(event_type))
          for (auto listener : listeners_)
            listener->trace_data(trace_event_cache(), name_, event_type, id, data);
#endif
      }
      
      /// @brief Writes trace data to the trace listeners in the Listeners collection using the specified event type, event identifier, and trace data.
      /// @param event_type One of the enumeration values that specifies the event type of the trace data.
      /// @param id A numeric identifier for the event.
      /// @param data The trace data.
      /// @remarks The trace_data method, like the trace_event method, is intended for automated tools, but it also allows the attaching of an additional object, such as an exception instance, to the trace.
      /// @remarks The trace_data method calls the source_switch::should_trace method of the source_switch object returned by the source_switch property. If should_trace returns true, trace_data calls the corresponding trace_data method on all listeners. Otherwise, trace_data returns without calling the listeners' methods.
      template<typename object_t>
      void trace_data(const xtd::diagnostics::trace_event_type& event_type, int32_t id, const std::vector<object_t>& data) {
#if defined(TRACE)
        if (source_switch_.should_trace(event_type))
          for (auto listener : listeners_)
            listener->trace_data(trace_event_cache(), name_, event_type, id, data);
#endif
      }
      
      /// @brief Writes a trace event message to the trace listeners in the listeners collection using the specified event type and event identifier.
      /// @param event_type One of the enumeration values that specifies the event type of the trace data.
      /// @param id A numeric identifier for the event.
      /// @remarks The trace_event method is intended to trace events that can be processed automatically by tools. For example, a monitoring tool can notify an administrator if a specific event is traced by a specific source.
      void trace_event(const xtd::diagnostics::trace_event_type& event_type, int32_t id) {
#if defined(TRACE)
        if (source_switch_.should_trace(event_type))
          for (auto listener : listeners_)
            listener->trace_event(trace_event_cache(), name_, event_type, id);
#endif
      }
      
      /// @brief Writes a trace event message to the trace listeners in the listeners collection using the specified event type, event identifier adn message.
      /// @param event_type One of the enumeration values that specifies the event type of the trace data.
      /// @param id A numeric identifier for the event.
      /// @param message The trace message to write.
      void trace_event(const xtd::diagnostics::trace_event_type& event_type, int32_t id, const std::string& message) {
#if defined(TRACE)
        if (source_switch_.should_trace(event_type))
          for (auto listener : listeners_)
            listener->trace_event(trace_event_cache(), name_, event_type, id, message);
#endif
      }
      
      /// @brief Writes a trace event message to the trace listeners in the listeners collection using the specified event type,  event identifier, and argument array and format
      /// @param event_type One of the enumeration values that specifies the event type of the trace data.
      /// @param id A numeric identifier for the event.
      /// @param format A composite format string that contains text intermixed with zero or more format items, which correspond to objects in the args array.
      /// @param args... An object array containing zero or more objects to format.
      template<typename ...objects>
      void trace_event(const xtd::diagnostics::trace_event_type& event_type, int32_t id, const std::string& format, const objects& ... args) {
#if defined(TRACE)
        if (source_switch_.should_trace(event_type))
          for (auto listener : listeners_)
            listener->trace_event(trace_event_cache(), name_, event_type, id, xtd::strings::format(format, args...));
#endif
      }
    
      /// @brief Writes an informational message to the trace listeners in the listeners collection using the specified message.
      /// @param message The informative message to write.
      /// @remarks The trace_information method provides an informational message intended to be read by users and not by tools.
      /// @remarks trace_information(const std::dtring&, calls the trace_event(const trace_eventType&, Int32_t, const std::string&, ...objects_t) method, setting event_type to trace_event_type.Information and passing the message content as an object array with formatting information. The trace_event(const trace_event_type, Int32_t, std::string&) method in turn calls the trace_event(const trace_event_cache&, const std::string&, trace_event_type, Int32_t, const std::string&) method of each trace listener.
      void trace_information(const std::string& message);
      
      /// @brief Writes an informational message to the trace listeners in the listeners collection using the specified object array and formatting information.
      /// @param format A composite format string that contains text intermixed with zero or more format items, which correspond to objects in the args array.
      /// @param args... An array containing zero or more objects to format.
      /// @remarks The trace_information method provides an informational message intended to be read by users and not by tools.
      /// @remarks trace_information(const std::dtring&, const Objects_t) calls the trace_event(const trace_eventType&, Int32_t, const std::string&, ...objects_t) method, setting event_type to trace_event_type.Information and passing the message content as an object array with formatting information. The trace_event(const trace_event_type, Int32_t, std::string&, ...objects_t) method in turn calls the trace_event(const trace_event_cache&, const std::string&, trace_event_type, Int32_t, const std::string&, ...objects_t) method of each trace listener.
      template<typename ...objects_t>
      void trace_information(const std::string& format, const objects_t& ... args) {trace_event(trace_event_type::information, 0, format, args...);}

      /// @brief Writes a trace transfer message to the trace listeners in the listeners collection using the specified numeric identifier, message, and related activity identifier.
      /// @param id A numeric identifier for the event.
      /// @param message The trace message to write.
      /// @param related_activity_id A structure that identifies the related activity.
      /// @remarks The trace_transfer method calls the trace_transfer method of each trace listener in the listeners property to write the trace information. The default trace_transfer method in the base trace_listener class calls the trace_listener::trace_event(const trace_event_cache&, const std::string&, trace_svent_type, Int32_t, const std::string&) method to process the call, setting event_type to trace_event_type::transfer and appending a string representation of the related_activity_id GUID to message.
      /// @remarks trace_transfer is intended to be used with the logical operations of a correlation_manager. The related_activity_id parameter relates to the activity_id property of a correlation_manager object. If a logical operation begins in one activity and transfers to another, the second activity logs the transfer by calling the trace_transfer method. The trace_transfer call relates the new activity identity to the previous identity. The most likely consumer of this functionality is a trace viewer that can report logical operations that span multiple activities.
      template<typename guid_t>
      void trace_transfer (int32_t id, const std::string& message,const  guid_t& related_activity_id) {
#if defined(TRACE)
        for (auto listener : listeners_)
          listener->trace_transfer(trace_event_cache(), name_, id, message, related_activity_id);
#endif
      }
      
    private:
      std::map<std::string, std::string> attributes_;
      std::string name_;
      /// @todo Update source_swith with this...
      xtd::diagnostics::source_levels switch_levels_ = xtd::diagnostics::source_levels::off;
      xtd::diagnostics::trace_listener_collection listeners_ {std::make_shared<xtd::diagnostics::default_trace_listener>()};
      xtd::diagnostics::source_switch source_switch_ {""};
    };
  }
}
