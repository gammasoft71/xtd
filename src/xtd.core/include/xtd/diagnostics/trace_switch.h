/// @file
/// @brief Contains xtd::diagnostics::trace_switch class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "switch_base.h"
#include "debug.h"
#include "trace_level.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides a multilevel switch to control tracing and debug output without recompiling your code.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks You can use a trace switch to filter out messages based on their importance. The trace_switch class provides the trace_error, trace_warning, trace_info, and trace_verbose properties to test the level of the switch. The level property gets or sets the switch's trace_level.
    /// @remarks You can set the level of a trace_switch through the application configuration file and then use the configured trace_switch level in your application. Alternately, you can create a trace_switch in your code and set the level directly to instrument a specific section of code.
    class trace_switch : public xtd::diagnostics::switch_base {
    public:
      /// @brief Initializes a new instance of the xtd::diagnostics::trace_switch class, using the specified display name and description.
      /// @param display_name The name to display on a user interface.
      /// @param description The description of the switch.
      /// @remarks he xtd::diagnostics::trace_switch class provides the xtd::diagnostics::trace_switch::trace_error, xtd::diagnostics::trace_switch::trace_warning, xtd::diagnostics::trace_switch::trace_info, and xtd::diagnostics::trace_switcht::trace_verbose properties to test the Level of the switch. The xtd::diagnostics::trace_switch::level property gets or sets the switch's xtd::diagnostics::trace_level.
      /// @note To improve performance, you can make xtd::diagnostics::trace_switch members static in your class.
      trace_switch(const xtd::ustring& display_name, const xtd::ustring& description);
      /// @brief Initializes a new instance of the xtd::diagnostics::trace_switch class, using the specified display name, description, and default value for the switch.
      /// @param display_name The name to display on a user interface.
      /// @param description The description of the switch.
      /// @param default_switch_value The default value of the switch.
      /// @remarks The display_name parameter is used to set the value of the xtd::diagnostics::trace_switch::display_name property, the description parameter is use to set the value of the xtd::diagnostics::trace_switch::description property, and the default_switch_value parameter is saved as a field and used to initialize the xtd::diagnostics::trace_switch::value property on first reference.
      trace_switch(const xtd::ustring& display_name, const xtd::ustring& description, const xtd::ustring& default_switch_value);

      /// @brief Gets the trace level that determines the messages the switch allows.
      /// @return One of the xtd::diagnostics::trace_level values that specifies the level of messages that are allowed by the switch.
      /// @remarks Setting this property updates the xtd::diagnostics::trace_switch::trace_error, xtd::diagnostics::trace_switch::trace_warning, xtd::diagnostics::trace_switch::trace_info, and xtd::diagnostics::trace_switch::trace_verbose properties to reflect the new value.
      xtd::diagnostics::trace_level level() const;
      /// @brief Sets the trace level that determines the messages the switch allows.
      /// @param level One of the xtd::diagnostics::trace_level values that specifies the level of messages that are allowed by the switch.
      /// @remarks Setting this property updates the xtd::diagnostics::trace_switch::trace_error, xtd::diagnostics::trace_switch::trace_warning, xtd::diagnostics::trace_switch::trace_info, and xtd::diagnostics::trace_switch::trace_verbose properties to reflect the new value.
      void level(xtd::diagnostics::trace_level level);
      
      /// @brief Gets a value indicating whether the switch allows error-handling messages.
      /// @return true if the xtd::diagnostics::trace_switch::level property is set to xtd::diagnostics::trace_level::error, xtd::diagnostics::trace_level::warning, xtd::diagnostics::trace_level::info, or xtd::diagnostics::trace_level::verbose; otherwise, false.
      bool trace_error() const;

      /// @brief Gets a value indicating whether the switch allows informational messages.
      /// @return true if the xtd::diagnostics::trace_switch::level property is set to xtd::diagnostics::trace_level::info, or xtd::diagnostics::trace_level::verbose; otherwise, false.
      bool trace_info() const;

      /// @brief Gets a value indicating whether the switch allows all messages.
      /// @return true if the xtd::diagnostics::trace_switch::level property is set to xtd::diagnostics::trace_level::verbose; otherwise, false.
      bool trace_verbose() const;

      /// @brief Gets a value indicating whether the switch allows warning messages.
      /// @return true if the xtd::diagnostics::trace_switch::level property is set to xtd::diagnostics::trace_level::warning, xtd::diagnostics::trace_level::info, or xtd::diagnostics::trace_level::verbose; otherwise, false.
      bool trace_warning() const;

    protected:
      void on_switch_setting_changed() override;
      
      void on_value_changed() override;
    };
  }
}
