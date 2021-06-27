/// @file
/// @brief Contains xtd::diagnostics::boolean_switch class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <optional>
#include "switch_base.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @briefProvides a simple on/off switch that controls debugging and tracing output.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks You can use a boolean trace switch to enable or disable messages based on their importance. Use the xtd::diagnostics::boolean_switch::enabled property to get the current value of the switch.
    /// @remarks You can create a xtd::diagnostics::boolean_switch in your code and set the xtd::diagnostics::boolean_switch::enabled property directly to instrument a specific section of code.
    /// @par Examples
    /// This example configuration section defines a xtd::diagnostics::boolean_switch with the xtd::diagnostics::boolean_switch::display_name property set to my_switch and the xtd::diagnostics::boolean_switch::enabled value set to true. Within your application, you can use the configured switch value by creating a xtd::diagnostics::boolean_switch with the same name, as shown in the following code example.
    /// @code
    /// private:
    ///   inline static xtd::diagnostics::boolean_switch boolean_switch("my_switch", "This is my switch");
    ///
    /// public:
    ///   static void main() {
    ///     //...
    ///     console.write_line("Boolean switch {0} configured as {1}", boolean_switch.display_name(), boolean_switch.enabled());
    ///     if (boolean_switch.enabled()) {
    ///       //...
    ///     }
    ///   }
    /// @endcode
    /// @remarks You must enable tracing or debugging to use a switch. The syntax is compiler specific. If you use other than cmake to manage your build, refer to the documentation of your build nanager.
    ///  * To enable debug mode with cmake, add the add_definitions(-DDEBUG) command line in the CMakeLists.txt of your porject, or you can add #define DEBUG to the top of your file.
    ///  * To enable trace mode with cmake, add the add_definitions(-DTRACE) command line in the CMakeLists.txt of your porject, or you can add #define TRACE to the top of your file.
    /// @note These debug and trace compiler switches are not required when using the xtd::diagnostics::boolean_switch class in isolation. They are only required in conjunction with xtd::diagnostics::trace or xtd::diagnostics::debug methods that are conditionally compiled.
    /// @remarks For more information on instrumenting your application, see xtd::diagnostics::debug and xtd::diagnostics::trace.
    /// @note To improve performance, you can make xtd::diagnostics::boolean_switch members static in your class.
    class boolean_switch : public xtd::diagnostics::switch_base {
    public:
      /// @brief Initializes a new instance of the xtd::diagnostics::boolean_switch class with the specified display name and description.
      /// @param display_name The name to display on a user interface.
      /// @param description The description of the switch.
      /// @par Examples
      /// The following example creates a xtd::diagnostics::boolean_switch and uses the switch to determine whether to print an error message. The switch is created at the class level. The Main method passes its location to MyMethod, which prints an error message and where the error occurred.
      /// @code
      /// /* Class level declaration.*/
      /// private:
      ///   // Create a BooleanSwitch for data.
      ///   inline static xtd::diagnostics::boolean_switch data_switch("data", "data_access module");
      ///
      /// public:
      ///   static void my_method(const std::string& location) {
      ///     // Insert code here to handle processing.
      ///     if (data_switch.enabled())
      ///       console::write_line("Error happened at {}", location);
      ///   }
      ///
      ///   static void main(const std::vector<std::string>& args) {
      ///     //Run the method which writes an error message specifying the location of the error.
      ///     my_method("in Main");
      ///   }
      /// @endcode
      /// @remarks When you create a xtd::diagnostics::boolean_switch, the display_name parameter is used to find initial switch settings. If the constructor cannot find initial settings, the xtd::diagnostics::boolean_switch::enabled property is set to false (disabled).
      /// @remarks The switches you created should be static.
      boolean_switch(const std::string& display_name, const std::string& description);
      /// @brief Initializes a new instance of the xtd::diagnostics::boolean_switch class with the specified display name, description, and default switch value.
      /// @param display_name The name to display on a user interface.
      /// @param description The description of the switch.
      /// @param default_switch_value The default value of the switch.
      /// @remarks The display_name parameter is used to set the value of the xtd::diagnostics::boolean_switch::display_name property, and the description parameter is use to set the value of the xtd::diagnostics::boolean_switch::description property. The default_switch_value parameter is saved as a field and used to initialize the xtd::diagnostics::boolean_switch::value property on first reference. For more information about constructor use, see the xtd::diagnostics::boolean_switch::booleanswitch(std::sring, std::string) constructor.
      boolean_switch(const std::string& display_name, const std::string& description, const std::string& default_switch_value);
      
      /// @brief Gets a value indicating whether the switch is enabled or disabled.
      /// @return true if the switch is enabled; otherwise, false. The default is false.
      /// @remarks By default, this field is set to false (disabled). To enable the switch, assign this field the value of true. To disable the switch, assign the value to false. The value of this property is determined by the value of the base class property xtd::diagnostics::boolean_switch::switch_setting.
      bool enabled() const;
      /// @brief Sets a value indicating whether the switch is enabled or disabled.
      /// @param enabled true if the switch is enabled; otherwise, false. The default is false.
      /// @remarks By default, this field is set to false (disabled). To enable the switch, assign this field the value of true. To disable the switch, assign the value to false. The value of this property is determined by the value of the base class property xtd::diagnostics::boolean_switch::switch_setting.
      void enabled(bool enabled);
      
    protected:
      /// @brief Determines whether the new value of the Value property can be parsed as a Boolean value.
      /// @remarks The xtd::diagnostics::boolean_switch::on_value_changed method determines whether the new value is a valid string representation of a boolean value ("false" or "true"). If so, the method sets the xtd::diagnostics::boolean_switch::switch_setting property to 0 or 1. Otherwise, the base method is called, which converts the string value to an integer value, which is then used to set the xtd::diagnostics::boolean_switch::switch_setting property.
      void on_value_changed() override;
      
    private:
      mutable std::optional<bool> enabled_;
    };
  }
}

