/// @file
/// @brief Contains xtd::forms::create_params cllass.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <iostream>
#include <string>
#include <xtd/drawing/point.h>
#include <xtd/drawing/size.h>
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Encapsulates the information needed when creating a control.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms_native
    /// @remarks The information in a create_params can be used to pass information about the initial state and appearance of a control. Most control derived controls override the create_params property to pass in the appropriate values or include additional information in the create_params.
    /// @note The constants used to set the style, ex_style, and class_style properties are defined in the xtd.forms.native library as constants.
    class create_params {
    public:
      /// @brief Initializes a new instance of the create_params class.
      create_params() = default;
      
      /// @cond
      create_params(const create_params&) = default;
      create_params& operator=(create_params&) = default;
      /// @endcond
      
      /// @brief Gets the control's initial text.
      /// @return The control's initial text.
      const xtd::ustring& caption() const {return caption_;}
      /// @brief Gets the control's initial text.
      /// @param caption The control's initial text.
      /// @return Current create_params instance.
      create_params& caption(const xtd::ustring& caption) {
        caption_ = caption;
        return *this;
      }
      
      /// @brief Gets the name of the Windows class to derive the control from.
      /// @return The name of the Windows class to derive the control from.
      /// @remarks The default value for this property is empty (""), indicating that the control is not derived from an existing control class. To derive from an existing control class, store the system class name in this property. For example, to derive from the standard Button control, set this property to "button".
      const xtd::ustring& class_name() const {return class_name_;}
      /// @brief Sets the name of the Windows class to derive the control from.
      /// @param class_name The name of the Windows class to derive the control from.
      /// @return Current create_param instance.
      /// @remarks The default value for this property is empty (""), indicating that the control is not derived from an existing control class. To derive from an existing control class, store the system class name in this property. For example, to derive from the standard Button control, set this property to "button".
      create_params& class_name(const xtd::ustring& class_name) {
        class_name_ = class_name;
        return *this;
      }
      
      /// @brief Gets a bitwise combination of class style values.
      /// @return A bitwise combination of the class style values.
      /// @remarks see class_styles.h file
      size_t class_style() const {return class_style_;}
      /// @brief Gets a bitwise combination of class style values.
      /// @param class_style A bitwise combination of the class style values.
      /// @return Current create_param instance.
      /// @remarks see class_styles.h file
      create_params& class_style(size_t class_style) {
        class_style_ = class_style;
        return *this;
      }

      /// @brief Gets a bitwise combination of extended window style values.
      /// @return A bitwise combination of the extended window style values.
      /// @remarks The ex_style property supports extended appearance and initial state values to apply to the control.
      /// @remarks see window_styles.h file
      size_t ex_style() const {return ex_style_;}
      /// @brief Sets a bitwise combination of extended window style values.
      /// @param ex_Sttyle A bitwise combination of the extended window style values.
      /// @return Current create_param instance.
      /// @remarks The ex_style property supports extended appearance and initial state values to apply to the control.
      /// @remarks see window_styles.h file
      create_params& ex_style(size_t ex_style) {
        ex_style_ = ex_style;
        return *this;
      }

      /// @brief Gets the initial height of the control.
      /// @return The numeric value that represents the initial height of the control.
      int32_t height() const {return size_.height();}
      /// @brief Sets the initial height of the control.
      /// @param height The numeric value that represents the initial height of the control.
      /// @return Current create_param instance.
      create_params& height(int32_t height) {
        size_.height(height);
        return *this;
      }

      /// @brief Gets the initial location of the control.
      /// @return The xtd::drawing::point that represents the initial location of the control.
      drawing::point location() const {return location_;}
      /// @brief Sets the initial location of the control.
      /// @param location The xtd::drawing::point that represents the initial location of the control.
      /// @return Current create_param instance.
      create_params& location(const drawing::point location) {
        location_ = location;
        return *this;
      }

      /// @brief Gets additional parameter information needed to create the control.
      /// @return An intptr_t that holds additional parameter information needed to create the control.
      intptr_t param() const {return param_;}
      /// @brief Sets additional parameter information needed to create the control.
      /// @param param An intptr_t that holds additional parameter information needed to create the control.
      /// @return Current create_param instance.
      create_params& param(intptr_t param) {
        param_ = param;
        return *this;
      }

      /// @brief Gets or sets the control's parent.
      /// @return An intptr_t that contains the window handle of the control's parent.
      intptr_t parent() const {return parent_;}
      /// @brief Sets or sets the control's parent.
      /// @param parent An intptr_t that contains the window handle of the control's parent.
      /// @return Current create_param instance.
      create_params& parent(intptr_t parent) {
        parent_ = parent;
        return *this;
      }

      /// @brief Gets a bitwise combination of window style values.
      /// @return A bitwise combination of the window style values.
      /// @remarks The Style property controls the appearance of the control and its initial state.
      size_t style() const {return style_;}
      /// @brief Sets a bitwise combination of window style values.
      /// @param style A bitwise combination of the window style values.
      /// @return Current create_param instance.
      /// @remarks The Style property controls the appearance of the control and its initial state.
      create_params& style(size_t style) {
        style_ = style;
        return *this;
      }

      /// @brief Gets the initial size of the control.
      /// @return The xtd::drawing::size that represents the initial size of the control.
      drawing::size size() const {return size_;}
      /// @brief Sets the initial size of the control.
      /// @param location The xtd::drawing::size that represents the initial size of the control.
      /// @return Current create_param instance.
      create_params& size(const drawing::size size) {
        size_ = size;
        return *this;
      }

      /// @brief Gets the initial width of the control.
      /// @return The numeric value that represents the initial width of the control.
      int32_t width() const {return size_.width();}
      /// @brief Sets the initial width of the control.
      /// @param height The numeric value that represents the initial width of the control.
      /// @return Current create_param instance.
      create_params& width(int32_t width) {
        size_.width(width);
        return *this;
      }

      /// @brief Gets the initial left position of the control.
      /// @return The numeric value that represents the initial left position of the control.
      int32_t x() const {return location_.x();}
      /// @brief Sets the initial left position of the control.
      /// @param x The numeric value that represents the initial left position of the control.
      /// @return Current create_param instance.
      create_params& x(int32_t x) {
        location_.x(x);
        return *this;
      }
      
      /// @brief Gets the initial top position of the control.
      /// @return The numeric value that represents the initial top position of the control.
      int32_t y() const {return location_.y();}
      /// @brief Sets the initial top position of the control.
      /// @param x The numeric value that represents the initial top position of the control.
      /// @return Current create_param instance.
      create_params& y(int32_t y) {
        location_.y(y);
        return *this;
      }

      /// @brief Returns a string that represents the current object.
      /// @return A string that represents the current object.
      xtd::ustring to_string() const {return ustring::format("create_params {{'{}' , '{}', 0x{:X}, 0x{:X}, {{{}, {}, {}, {}}}}}", class_name_, caption_, style_, ex_style_, location_.x(), location_.y(), size_.width(), size_.height());}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const create_params& create_params) noexcept {return os << create_params.to_string();}
      /// @endcond

    private:
      xtd::ustring caption_;
      xtd::ustring class_name_;
      size_t class_style_ = 0;
      size_t ex_style_ = 0;
      drawing::point location_ = {-1, -1};
      intptr_t param_ = 0;
      intptr_t parent_ = 0;
      size_t style_ = 0;
      drawing::size size_ = {-1, -1};
    };
  }
}
