/// @file
/// @brief Contains xtd::forms::create_params class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include <xtd/drawing/point>
#include <xtd/drawing/size>
#include <xtd/object>
#include <xtd/string>
#include <cstdint>
#include <iostream>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Encapsulates the information needed when creating a control.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/create_params>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks The information in a create_params can be used to pass information about the initial state and appearance of a control. Most control derived controls override the create_params property to pass in the appropriate values or include additional information in the create_params.
    /// @note The constants used to set the style, ex_style, and class_style properties are defined in the xtd.forms.native library as constants.
    class create_params : public xtd::object, xtd::iequatable<create_params> {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the create_params class.
      create_params();
      /// @}
      
      /// @cond
      create_params(const create_params& other);
      auto operator =(const create_params& other) -> create_params&;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the control's initial text.
      /// @return The control's initial text.
      [[nodiscard]] auto caption() const noexcept -> const xtd::string&;
      /// @brief Gets the control's initial text.
      /// @param value The control's initial text.
      /// @return Current create_params instance.
      auto caption(const xtd::string& value) -> create_params&;
      
      /// @brief Gets the name of the Windows class to derive the control from.
      /// @return The name of the Windows class to derive the control from.
      /// @remarks The default value for this property is empty (""), indicating that the control is not derived from an existing control class. To derive from an existing control class, store the system class name in this property. For example, to derive from the standard Button control, set this property to "button".
      [[nodiscard]] auto class_name() const noexcept -> const xtd::string&;
      /// @brief Sets the name of the Windows class to derive the control from.
      /// @param value The name of the Windows class to derive the control from.
      /// @return Current create_param instance.
      /// @remarks The default value for this property is empty (""), indicating that the control is not derived from an existing control class. To derive from an existing control class, store the system class name in this property. For example, to derive from the standard Button control, set this property to "button".
      auto class_name(const xtd::string& value) -> create_params&;
      
      /// @brief Gets a bitwise combination of class style values.
      /// @return A bitwise combination of the class style values.
      /// @remarks see class_styles.h file
      [[nodiscard]] auto class_style() const noexcept -> xtd::usize;
      /// @brief Gets a bitwise combination of class style values.
      /// @param value A bitwise combination of the class style values.
      /// @return Current create_param instance.
      /// @remarks see class_styles.h file
      auto class_style(xtd::usize value) -> create_params&;
      
      /// @brief Gets a bitwise combination of extended window style values.
      /// @return A bitwise combination of the extended window style values.
      /// @remarks The ex_style property supports extended appearance and initial state values to apply to the control.
      /// @remarks see window_styles.h file
      [[nodiscard]] auto ex_style() const noexcept -> xtd::usize;
      /// @brief Sets a bitwise combination of extended window style values.
      /// @param value A bitwise combination of the extended window style values.
      /// @return Current create_param instance.
      /// @remarks The ex_style property supports extended appearance and initial state values to apply to the control.
      /// @remarks see window_styles.h file
      auto ex_style(xtd::usize value) -> create_params&;
      
      /// @brief Gets the initial height of the control.
      /// @return The numeric value that represents the initial height of the control.
      [[nodiscard]] auto height() const noexcept -> xtd::int32;
      /// @brief Sets the initial height of the control.
      /// @param value The numeric value that represents the initial height of the control.
      /// @return Current create_param instance.
      auto height(xtd::int32 value) -> create_params&;
      
      /// @brief Gets the initial location of the control.
      /// @return The xtd::drawing::point that represents the initial location of the control.
      [[nodiscard]] auto location() const noexcept -> xtd::drawing::point;
      /// @brief Sets the initial location of the control.
      /// @param value The xtd::drawing::point that represents the initial location of the control.
      /// @return Current create_param instance.
      auto location(const xtd::drawing::point value) -> create_params&;
      
      /// @brief Gets additional parameter information needed to create the control.
      /// @return An intptr that holds additional parameter information needed to create the control.
      [[nodiscard]] auto param() const noexcept -> xtd::intptr;
      /// @brief Sets additional parameter information needed to create the control.
      /// @param value An intptr that holds additional parameter information needed to create the control.
      /// @return Current create_param instance.
      auto param(xtd::intptr value) -> create_params&;
      
      /// @brief Gets or sets the control's parent.
      /// @return An intptr that contains the window handle of the control's parent.
      [[nodiscard]] auto parent() const noexcept -> xtd::intptr;
      /// @brief Sets or sets the control's parent.
      /// @param value An intptr that contains the window handle of the control's parent.
      /// @return Current create_param instance.
      auto parent(xtd::intptr value) -> create_params&;
      
      /// @brief Gets a bitwise combination of window style values.
      /// @return A bitwise combination of the window style values.
      /// @remarks The Style property controls the appearance of the control and its initial state.
      [[nodiscard]] auto style() const noexcept -> xtd::usize;
      /// @brief Sets a bitwise combination of window style values.
      /// @param value A bitwise combination of the window style values.
      /// @return Current create_param instance.
      /// @remarks The Style property controls the appearance of the control and its initial state.
      auto style(xtd::usize value) -> create_params&;
      
      /// @brief Gets the initial size of the control.
      /// @return The xtd::drawing::size that represents the initial size of the control.
      [[nodiscard]] auto size() const noexcept -> xtd::drawing::size;
      /// @brief Sets the initial size of the control.
      /// @param value The xtd::drawing::size that represents the initial size of the control.
      /// @return Current create_param instance.
      auto size(const xtd::drawing::size value) -> create_params&;
      
      /// @brief Gets the initial width of the control.
      /// @return The numeric value that represents the initial width of the control.
      [[nodiscard]] auto width() const noexcept -> xtd::int32;
      /// @brief Sets the initial width of the control.
      /// @param value The numeric value that represents the initial width of the control.
      /// @return Current create_param instance.
      auto width(xtd::int32 value) -> create_params&;
      
      /// @brief Gets the initial left position of the control.
      /// @return The numeric value that represents the initial left position of the control.
      [[nodiscard]] auto x() const noexcept -> xtd::int32;
      /// @brief Sets the initial left position of the control.
      /// @param value The numeric value that represents the initial left position of the control.
      /// @return Current create_param instance.
      auto x(xtd::int32 value) -> create_params&;
      
      /// @brief Gets the initial top position of the control.
      /// @return The numeric value that represents the initial top position of the control.
      [[nodiscard]] auto y() const noexcept -> xtd::int32;
      /// @brief Sets the initial top position of the control.
      /// @param value The numeric value that represents the initial top position of the control.
      /// @return Current create_param instance.
      auto y(xtd::int32 value) -> create_params&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const xtd::object& obj) const noexcept -> bool override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const create_params& other) const noexcept -> bool override;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
      
      /// @brief Returns a string that represents the current object.
      /// @return A string that represents the current object.
      [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
