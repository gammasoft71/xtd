/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once
#include <xtd/xtd.strings>
#include "source_levels.h"
#include "switch_base.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @cond Provides a multilevel switch to control tracing and debug output without recompiling your code.
    /// @remarks The switch property of the trace_source class is a source_switch object. The source_switch class provides a level property to test the event level of the switch. The level property gets or sets the switch's trace_level value.
    /// @remarks The switch is used to check whether a trace should be propagated or ignored. Each trace_source trace method calls the should_trace method before calling the listeners. If the should_trace method returns false, the trace is ignored and the trace method exits. If the should_trace method returns true, the trace is passed to the listeners.
    class source_switch : public xtd::diagnostics::switch_base {
    public:
      /// @brief Initializes a new instance of the source_switch class, specifying the name of the source.
      /// @param name The name of the source.
      /// @remarks The name parameter is used to set the value of the display_name property.
      explicit source_switch(const std::string& name) : switch_base(name, "") {}
      /// @brief Initializes a new instance of the source_switch class, specifying the display name and the default value for the source switch.
      /// @param display_name The name of the source.
      /// @param default_switch_value The default value for the switch.
      /// @remarks The display_name parameter is used to set the value of the display_name property; the default_switch_value parameter is saved as a field and used to initialize the value property on first reference.
      source_switch(const std::string& display_name, const std::string& default_switch_value) : switch_base(display_name, "", default_switch_value) {}

      /// @brief Gets the level of the switch.
      /// @return One of the SourceLevels values that represents the event level of the switch.
      /// @remarks This property gets its value from the switch_setting property. Setting this property also modifies the switch_setting property.
      xtd::diagnostics::source_levels level() const {return static_cast<xtd::diagnostics::source_levels>(switch_setting());}
      /// @brief Sets the level of the switch.
      /// @param level One of the SourceLevels values that represents the event level of the switch.
      /// @remarks This property gets its value from the switch_setting property. Setting this property also modifies the switch_setting property.
      void level(xtd::diagnostics::source_levels level) {switch_setting(static_cast<int32_t>(level));}

      /// @brief Determines if trace listeners should be called, based on the trace event type.
      /// @param event_type One of the trace_event_type values.
      /// @return true if the trace listeners should be called; otherwise, false.
      /// @remarks This method is called by the trace methods in the trace_source class to determine whether listeners should be called to write a trace.
      /// @note Application code should not call this method; it is intended to be called only by methods in the trace_source class.
      bool should_trace(trace_event_type event_type) {
        return (switch_setting() & static_cast<int>(event_type)) != 0;
      }
      
    protected:
      /// @brief Invoked when the value of the value property changes.
      /// @remarks The on_value_changed method converts the new value of the value property to the integer representation of the matching field in the source_levels enumeration, and then uses this integer to set the switch_setting property.
      void on_value_changed() override {
        switch_setting(static_cast<int32_t>(xtd::parse<source_levels>(value())));
      }
    };
  }
}
