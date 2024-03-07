/// @file
/// @brief Contains xtd::forms::user_control control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "border_sides.h"
#include "border_style.h"
#include "container_control.h"
#include <xtd/optional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows user control.
    /// @par Header
    /// @code #include <xtd/forms/user_control> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of user control.
    /// @include user_control.cpp
    class forms_export_ user_control : public container_control {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialises a new instance of user_control class.
      user_control();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the mode by which the user_control automatically resizes itself.
      /// @return An auto_size_mode enumerated value. The default is grow_only.
      virtual forms::auto_size_mode auto_size_mode() const noexcept;
      /// @brief Sets the mode by which the panel automatically resizes itself.
      /// @param value An auto_size_mode enumerated value. The default is grow_only.
      /// @return Current user_control instance.
      virtual user_control& auto_size_mode(forms::auto_size_mode value);
      
      /// @brief Gets the border sides for the control.
      /// @return A bitwise combination of the A bitwise combination values. The default is border_style::all.
      virtual forms::border_sides border_sides() const noexcept;
      /// @brief Sets the border sides for the control.
      /// @param border_style A bitwise combination of the border_sides values. The default is border_style::all.
      virtual user_control& border_sides(forms::border_sides border_sides);
      
      /// @brief Gets the border style for the control.
      /// @return One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual xtd::forms::border_style border_style() const noexcept;
      /// @brief Sets the border style for the control.
      /// @param border_style One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @return Current user_control instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual user_control& border_style(forms::border_style border_style);
      /// @brief Resets the border style for the control.
      /// @param border_style nullptr.
      /// @return Current user_control instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual user_control& border_style(std::nullptr_t border_style);
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::user_control.
      /// @return New xtd::forms::user_control created.
      static user_control create();
      /// @brief A factory to create an xtd::forms::user_control with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::user_control.
      /// @return New xtd::forms::user_control created.
      static user_control create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::user_control with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::user_control.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::user_control.
      /// @return New xtd::forms::user_control created.
      static user_control create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::user_control with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::user_control.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::user_control.
      /// @param name The name of the xtd::forms::user_control.
      /// @return New xtd::forms::user_control created.
      static user_control create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::user_control with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::user_control.
      /// @return New xtd::forms::user_control created.
      static user_control create(const control& parent);
      /// @brief A factory to create an xtd::forms::user_control with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::user_control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::user_control.
      /// @return New xtd::forms::user_control created.
      static user_control create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::user_control with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::user_control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::user_control.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::user_control.
      /// @return New xtd::forms::user_control created.
      static user_control create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::user_control with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::user_control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::user_control.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::user_control.
      /// @param name The name of the xtd::forms::user_control.
      /// @return New xtd::forms::user_control created.
      static user_control create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}

    protected:
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}
      
      /// @name Protected methodds
      
      /// @{
      void on_layout(const event_args& e) override;
      void on_paint(paint_event_args& e) override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
