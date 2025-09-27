/// @file
/// @brief Contains xtd::diagnostics::trace_switch class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "switch_object.hpp"
#include "debug.hpp"
#include "trace_level.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides a multilevel switch to control tracing and debug output without recompiling your code.
    /// ```cpp
    /// class core_export_ trace_switch : public xtd::diagnostics::switch_object
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::diagnostics::switch_object → xtd::diagnostics::trace_switch
    /// @par Header
    /// ```cpp
    /// #include <xtd/diagnostics/trace_switch>
    /// ```
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks You can use a trace switch to filter out messages based on their importance. The trace_switch class provides the trace_error, trace_warning, trace_info, and trace_verbose properties to test the level of the switch. The level property gets or sets the switch's trace_level.
    /// @remarks You can set the level of a trace_switch through the application configuration file and then use the configured trace_switch level in your application. Alternately, you can create a trace_switch in your code and set the level directly to instrument a specific section of code.
    class core_export_ trace_switch : public xtd::diagnostics::switch_object {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::diagnostics::trace_switch class, using the specified display name and description.
      /// @param display_name The name to display on a user interface.
      /// @param description The description of the switch.
      /// @remarks he xtd::diagnostics::trace_switch class provides the xtd::diagnostics::trace_switch::trace_error, xtd::diagnostics::trace_switch::trace_warning, xtd::diagnostics::trace_switch::trace_info, and xtd::diagnostics::trace_switch::trace_verbose properties to test the Level of the switch. The xtd::diagnostics::trace_switch::level property gets or sets the switch's xtd::diagnostics::trace_level.
      /// @note To improve performance, you can make xtd::diagnostics::trace_switch members static in your class.
      trace_switch(const xtd::string& display_name, const xtd::string& description);
      /// @brief Initializes a new instance of the xtd::diagnostics::trace_switch class, using the specified display name, description, and default value for the switch.
      /// @param display_name The name to display on a user interface.
      /// @param description The description of the switch.
      /// @param default_switch_value The default value of the switch.
      /// @remarks The display_name parameter is used to set the value of the xtd::diagnostics::trace_switch::display_name property, the description parameter is use to set the value of the xtd::diagnostics::trace_switch::description property, and the default_switch_value parameter is saved as a field and used to initialize the xtd::diagnostics::trace_switch::value property on first reference.
      trace_switch(const xtd::string& display_name, const xtd::string& description, const xtd::string& default_switch_value);
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the trace level that determines the messages the switch allows.
      /// @return One of the xtd::diagnostics::trace_level values that specifies the level of messages that are allowed by the switch.
      /// @remarks Setting this property updates the xtd::diagnostics::trace_switch::trace_error, xtd::diagnostics::trace_switch::trace_warning, xtd::diagnostics::trace_switch::trace_info, and xtd::diagnostics::trace_switch::trace_verbose properties to reflect the new value.
      xtd::diagnostics::trace_level level() const noexcept;
      /// @brief Sets the trace level that determines the messages the switch allows.
      /// @param level One of the xtd::diagnostics::trace_level values that specifies the level of messages that are allowed by the switch.
      /// @remarks Setting this property updates the xtd::diagnostics::trace_switch::trace_error, xtd::diagnostics::trace_switch::trace_warning, xtd::diagnostics::trace_switch::trace_info, and xtd::diagnostics::trace_switch::trace_verbose properties to reflect the new value.
      void level(xtd::diagnostics::trace_level level) noexcept;
      
      /// @brief Gets a value indicating whether the switch allows error-handling messages.
      /// @return `true` if the xtd::diagnostics::trace_switch::level property is set to xtd::diagnostics::trace_level::error, xtd::diagnostics::trace_level::warning, xtd::diagnostics::trace_level::info, or xtd::diagnostics::trace_level::verbose; otherwise, `false`.
      bool trace_error() const noexcept;
      
      /// @brief Gets a value indicating whether the switch allows informational messages.
      /// @return `true` if the xtd::diagnostics::trace_switch::level property is set to xtd::diagnostics::trace_level::info, or xtd::diagnostics::trace_level::verbose; otherwise, `false`.
      bool trace_info() const noexcept;
      
      /// @brief Gets a value indicating whether the switch allows all messages.
      /// @return `true` if the xtd::diagnostics::trace_switch::level property is set to xtd::diagnostics::trace_level::verbose; otherwise, `false`.
      bool trace_verbose() const noexcept;
      
      /// @brief Gets a value indicating whether the switch allows warning messages.
      /// @return `true` if the xtd::diagnostics::trace_switch::level property is set to xtd::diagnostics::trace_level::warning, xtd::diagnostics::trace_level::info, or xtd::diagnostics::trace_level::verbose; otherwise, `false`.
      bool trace_warning() const noexcept;
      /// @}
      
    protected:
      /// @name Protected Methods
      
      /// @{
      void on_switch_setting_changed() override;
      void on_value_changed() override;
      /// @}
    };
  }
}
