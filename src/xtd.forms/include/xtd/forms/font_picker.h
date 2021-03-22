/// @file
/// @brief Contains xtd::forms::font_picker control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a picker control that displays available fonts along with controls.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Example
    /// The following code example demonstrate the use of font_picker picker.
    /// @include font_picker.cpp
    /// @par Windows
    /// @image html font_picker_w.png
    /// <br>
    /// @image html font_picker_wd.png
    /// @par macOS
    /// @image html font_picker_m.png
    /// <br>
    /// @image html font_picker_md.png
    /// @par Gnome
    /// @image html font_picker_g.png
    /// <br>
    /// @image html font_picker_gd.png
    class forms_export_ font_picker : public control {
    public:
      font_picker();

      const drawing::color& color() const {return color_;}
      control& color(const drawing::color& color);
      
      drawing::font font() const override {return font_;}
      control& font(const drawing::font& font) override;
      
      drawing::size default_size() const override {return {100, 25};}
      
      event<font_picker, event_handler<control&>> font_changed;

    protected:
      forms::create_params create_params() const override;
      
      void on_font_changed(const event_args& e) override;
      
      void on_handle_created(const event_args& e) override;
      
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;
      
    private:
      void wm_click(message& message);
      drawing::color color_;
      drawing::font font_ = default_font();
    };
  }
}
