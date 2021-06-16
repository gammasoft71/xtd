/// @file
/// @brief Contains xtd::forms::user_control control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "container_control.h"
#include "border_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows user control.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of user control.
    /// @include user_control.cpp
    /// @par Windows
    /// @image html user_control_w.png
    /// <br>
    /// @image html user_control_wd.png
    /// @par macOS
    /// @image html user_control_m.png
    /// <br>
    /// @image html user_control_md.png
    /// @par Gnome
    /// @image html user_control_g.png
    /// <br>
    /// @image html user_control_gd.png
    class forms_export_ user_control : public container_control {
    public:
      /// @brief Initialises a new instance of user_control class.
      user_control();

      /// @brief Gets the mode by which the user_control automatically resizes itself.
      /// @return An auto_size_mode enumerated value. The default is grow_only.
      virtual forms::auto_size_mode auto_size_mode() const {return auto_size_mode_;}
      /// @brief Sets the mode by which the panel automatically resizes itself.
      /// @param value An auto_size_mode enumerated value. The default is grow_only.
      /// @return Current user_control instance.
      virtual user_control& auto_size_mode(forms::auto_size_mode value);
      
      /// @brief Gets the border style for the control.
      /// @return One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual forms::border_style border_style() const {return border_style_;}
      /// @brief Sets the border style for the control.
      /// @param border_style One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @return Current user_control instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual user_control& border_style(forms::border_style border_style);

      drawing::size default_size() const override {return {150, 150};}
      
    protected:
      forms::create_params create_params() const override;
      
      void on_handle_created(const event_args& e) override;
      
      void on_layout(const event_args& e) override;

      /// @cond
      forms::border_style border_style_ = forms::border_style::none;
      /// @endcond
    };
  }
}
