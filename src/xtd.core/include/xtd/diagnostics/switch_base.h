/// @file
/// @brief Contains xtd::diagnostics::switch_base class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <map>
#include <vector>
#include "../object.h"
#include "../ustring.h"
#include "source_levels.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides an abstract base class to create new debugging and tracing switches.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks A switch provides an efficient mechanism for controlling tracing and debugging output at run time using external settings. The switch_base class implements default behavior for switches, allowing you to change the switch level at run time.
    /// @remarks This class is the base class for the boolean_switch, source_switch and the trace_switch classes. These switches meet most debugging and tracing needs.
    /// @par Notes to implementers
    /// If you need trace levels, or mechanisms for setting switch levels different from those provided by boolean_switch, source_switch and trace_switch, you can inherit from switch_base. When inheriting from this class, you must implement the switch_setting method.
    class switch_base : public object {
    public:
      /// @cond
      switch_base(const switch_base& value) = default;
      switch_base& operator=(const switch_base& value) = default;
      bool operator==(const switch_base& value) const;
      bool operator!=(const switch_base& value) const;
      /// @endcond

      /// @brief Gets the custom switch attributes
      /// @rettur nA StringDictionary containing the case-insensitive custom attributes for the trace switch.
      const std::map<xtd::ustring, xtd::ustring>& attributes() const;
      /// @brief Gets the custom switch attributes
      /// @return A StringDictionary containing the case-insensitive custom attributes for the trace switch.
      std::map<xtd::ustring, xtd::ustring>& attributes();
      /// @brief Sets the custom switch attributes
      /// @param attributes A StringDictionary containing the case-insensitive custom attributes for the trace switch.
      void attributes(const std::map<xtd::ustring, xtd::ustring>& attributes);
      
      /// @brief Gets a description of the switch
      /// @return The description of the switch. The default value is an empty string ("").
      /// @remarks This property should indicate the function of the switch; for example, "Enables tracing for a directory watcher component." The value is set by the descriptor parameter in the switch_base constructor.
      const xtd::ustring& description() const;
      
      /// @brief Gets a name used to identify the switch.
      /// @return The name used to identify the switch. The default value is an empty string ("").
      /// @remarks When you create a new switch_base object, the display_name finds initial switch settings. For more information, see the switch_base constructor.
      const xtd::ustring& display_name() const;

    protected:
      /// @brief Initializes a new instance of the switch_base class.
      /// @param display_name The name of the switch.
      /// @param description The description for the switch.
      /// @remarks When you create a new switch_base object, the value of the display_name parameter is used to find initial switch settings. The default value is an empty string ("").
      /// @par Notes to inheritors
      /// To set the value of the switch, set the switch_setting property in the constructor.
      switch_base(const xtd::ustring& display_name, const xtd::ustring& description);
      /// @brief Initializes a new instance of the switch_base class.
      /// @param display_name The name of the switch.
      /// @param description The description for the switch.
      /// @param default_switch_value The default value for the switch.
      /// @remarks The display_name parameter is used to set the value of the display_name property, and the description parameter is use to set the value of the description property. The default_switch_value parameter is the value for the switch if the value property is not set by code.
      switch_base(const xtd::ustring& display_name, const xtd::ustring& description, const xtd::ustring& default_switch_value);
      
      /// @brief Gets the current setting for this switch.
      /// @return The current setting for this switch. The default is zero.
      int32_t switch_setting() const;
      /// @brief Sets the current setting for this switch.
      /// @param switch_setting The current setting for this switch. The default is zero.
      void switch_setting(int32_t switch_setting);

      /// @brief Gets the value of the switch.
      /// @return A string representing the value of the switch.
      /// @remarks The on_value_changed method is called when the value of the value property is changed. The on_value_changed method parses the value of this property and converts it to an integer value, which is then used to set the switch_setting property.
      /// @par Notes to inheritors
      /// You should override the on_value_changed() method and provide a conversion operation that sets the appropriate switch_setting value for your switch.
      const xtd::ustring& value() const;
      /// @brief Sets the value of the switch.
      /// @param value A string representing the value of the switch.
      /// @remarks The on_value_changed method is called when the value of the value property is changed. The on_value_changed method parses the value of this property and converts it to an integer value, which is then used to set the switch_setting property.
      /// @par Notes to inheritors
      /// You should override the on_value_changed() method and provide a conversion operation that sets the appropriate switch_setting value for your switch.
      void value(const xtd::ustring& value);
      
      /// @brief Gets the custom attributes supported by the switch.
      /// @return A string array that contains the names of the custom attributes supported by the switch, or null if there no custom attributes are supported.
      /// @remarks The default implementation for the get_supported_attributes method returns {} (mepty array)l. If a switch is added in a configuration file and custom attributes are specified that are not included in the string array returned by get_supported_attributes, a configuration_exception is thrown when the switch is loaded.
      /// @par Notes to Inheritors
      /// When inheriting from the switch_base class or a derived class, you can override the get_supported_attributes() method to provide custom attributes for your class.
      virtual std::vector<xtd::ustring> get_supported_attributes() const;
      
      /// @brief Invoked when the switch_setting property is changed.
      virtual void on_switch_setting_changed();
      
      /// @brief Invoked when the value property is changed.
      /// @remarks The default implementation parses the new value of the value property to an integer value which it uses to set the switch_setting property.
      /// @par Not to Inheritors
      /// You should override this method and use a conversion that sets the appropriate switch_setting value for your switch.
      virtual void on_value_changed();
      
    private:
      xtd::ustring display_name_;
      xtd::ustring description_;
      std::map<xtd::ustring, xtd::ustring> attributes_;
      int32_t switch_setting_ = 0;
      xtd::ustring value_;
    };
  }
}
