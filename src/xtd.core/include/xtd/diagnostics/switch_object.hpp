/// @file
/// @brief Contains xtd::diagnostics::switch_object class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include "../collections/specialized/string_dictionary.hpp"
#include "../array.hpp"
#include "../iequatable.hpp"
#include "../object.hpp"
#include "../string.hpp"
#include "source_levels.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides an abstract base class to create new debugging and tracing switches.
    /// ```cpp
    /// class core_export_ switch_object : public xtd::object
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::diagnostics::switch_object
    /// @par Header
    /// ```cpp
    /// #include <xtd/diagnostics/switch_object>
    /// ```
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks A switch provides an efficient mechanism for controlling tracing and debugging output at run time using external settings. The switch_object class implements default behavior for switches, allowing you to change the switch level at run time.
    /// @remarks This class is the base class for the boolean_switch, source_switch and the trace_switch classes. These switches meet most debugging and tracing needs.
    /// @par Notes to implementers
    /// If you need trace levels, or mechanisms for setting switch levels different from those provided by boolean_switch, source_switch and trace_switch, you can inherit from switch_object. When inheriting from this class, you must implement the switch_setting method.
    class core_export_ switch_object : public xtd::object, public xtd::iequatable<switch_object> {
    public:
      /// @cond
      switch_object(const switch_object& value) = default;
      switch_object& operator =(const switch_object& value) = default;
      /// @endcond
      
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents the attributes collection.
      using attribute_collection = xtd::collections::specialized::string_dictionary;
      
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the custom switch attributes
      /// @return A xtd::collections::specialized::string_dictionary containing the case-insensitive custom attributes for the trace switch.
      const attribute_collection& attributes() const noexcept;
      /// @brief Gets the custom switch attributes
      /// @return A xtd::collections::specialized::string_dictionary containing the case-insensitive custom attributes for the trace switch.
      attribute_collection& attributes() noexcept;
      /// @brief Sets the custom switch attributes
      /// @param attributes A xtd::collections::specialized::string_dictionary containing the case-insensitive custom attributes for the trace switch.
      void attributes(const attribute_collection& attributes) noexcept;
      
      /// @brief Gets a description of the switch
      /// @return The description of the switch. The default value is an empty string ("").
      /// @remarks This property should indicate the function of the switch; for example, "Enables tracing for a directory watcher component." The value is set by the descriptor parameter in the switch_object constructor.
      const xtd::string& description() const noexcept;
      
      /// @brief Gets a name used to identify the switch.
      /// @return The name used to identify the switch. The default value is an empty string ("").
      /// @remarks When you create a new switch_object object, the display_name finds initial switch settings. For more information, see the switch_object constructor.
      const xtd::string& display_name() const noexcept;
      
      /// @brief Gets the value of the switch.
      /// @return A string representing the value of the switch.
      /// @remarks The on_value_changed method is called when the value of the value property is changed. The on_value_changed method parses the value of this property and converts it to an integer value, which is then used to set the switch_setting property.
      /// @par Notes to inheritors
      /// You should override the on_value_changed() method and provide a conversion operation that sets the appropriate switch_setting value for your switch.
      const xtd::string& value() const noexcept;
      /// @brief Sets the value of the switch.
      /// @param value A string representing the value of the switch.
      /// @remarks The on_value_changed method is called when the value of the value property is changed. The on_value_changed method parses the value of this property and converts it to an integer value, which is then used to set the switch_setting property.
      /// @par Notes to inheritors
      /// You should override the on_value_changed() method and provide a conversion operation that sets the appropriate switch_setting value for your switch.
      void value(const xtd::string& value);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      bool equals(const xtd::object& obj) const noexcept override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      bool equals(const switch_object& other) const noexcept override;
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initializes a new instance of the switch_object class.
      /// @param display_name The name of the switch.
      /// @param description The description for the switch.
      /// @remarks When you create a new switch_object object, the value of the display_name parameter is used to find initial switch settings. The default value is an empty string ("").
      /// @par Notes to inheritors
      /// To set the value of the switch, set the switch_setting property in the constructor.
      switch_object(const xtd::string& display_name, const xtd::string& description);
      /// @}
      
      /// @name Protected Properties
      
      /// @{
      /// @brief Gets the current setting for this switch.
      /// @return The current setting for this switch. The default is zero.
      int32 switch_setting() const noexcept;
      /// @brief Sets the current setting for this switch.
      /// @param switch_setting The current setting for this switch. The default is zero.
      void switch_setting(int32 switch_setting);
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Gets the custom attributes supported by the switch.
      /// @return A string array that contains the names of the custom attributes supported by the switch, or null if there no custom attributes are supported.
      /// @remarks The default implementation for the get_supported_attributes method returns {} (empty array). If a switch is added in a configuration file and custom attributes are specified that are not included in the string array returned by get_supported_attributes, a configuration_exception is thrown when the switch is loaded.
      /// @par Notes to Inheritors
      /// When inheriting from the switch_object class or a derived class, you can override the get_supported_attributes() method to provide custom attributes for your class.
      virtual xtd::array<xtd::string> get_supported_attributes() const noexcept;
      
      /// @brief Invoked when the switch_setting property is changed.
      virtual void on_switch_setting_changed();
      
      /// @brief Invoked when the value property is changed.
      /// @remarks The default implementation parses the new value of the value property to an integer value which it uses to set the switch_setting property.
      /// @par Not to Inheritors
      /// You should override this method and use a conversion that sets the appropriate switch_setting value for your switch.
      virtual void on_value_changed();
      /// @}
      
    private:
      xtd::string display_name_;
      xtd::string description_;
      attribute_collection attributes_;
      int32 switch_setting_ = 0;
      xtd::string value_ = "0";
      inline static xtd::collections::specialized::string_dictionary switches_;
    };
  }
}
