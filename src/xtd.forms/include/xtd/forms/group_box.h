/// @file
/// @brief Contains xtd::forms::group_box container.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "border_style.h"
#include "flat_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows control that displays a frame around a group of controls with an optional caption.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Examples
    /// The following code example demonstrate the use of group_box container.
    /// @include group_box.cpp
    /// @par Examples
    /// The following code example demonstrate the use of group_box container and check_box controls.
    /// @include group_box_and_check_box.cpp
    /// @par Examples
    /// The following code example demonstrate the use of group_box container and radio_button controls.
    /// @include group_box_and_radio_button.cpp
    class forms_export_ group_box : public control {
    public:
      /// @brief Initializes a new instance of the group_box class.
      group_box();

      /// @brief Gets how the group_box behaves when its auto_size property is enabled
      /// @return One of the xtd::forms::auto_size_mode values. The default is xtd::forms::auto_size_mode::grow_only.
      virtual forms::auto_size_mode auto_size_mode() const {return auto_size_mode_;}
      /// @brief Sets how the group_box behaves when its auto_size property is enabled
      /// @param value One of the xtd::forms::auto_size_mode values. The default is xtd::forms::auto_size_mode::grow_only.
      /// @return Current group_box.
      virtual group_box& auto_size_mode(forms::auto_size_mode value);
      
      drawing::size default_size() const override {return {200, 100};}
      
    protected:
      forms::create_params create_params() const override;
      
      drawing::size measure_control() const override;
      
      void on_font_changed(const xtd::event_args& e) override;
      
      void on_resize(const xtd::event_args& e) override;
      
      void on_text_changed(const xtd::event_args& e) override;
      
      /// @cond
      xtd::forms::flat_style flat_style_ = xtd::forms::flat_style::system;
      /// @endcond
    };
  }
}
