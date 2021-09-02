/// @file
/// @brief Contains xtd::forms::color_picker picker contrtols.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a picker control that displays available colors along with controls that enable the user to define custom colors.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks The inherited member show_dialog must be invoked to create this specific common dialog box. hook_proc can be overridden to implement specific dialog box hook functionality. Use color to retrieve the color selected by the user.
    /// @remarks When you create an instance of color_dialog, some of the read/write properties are set to initial values. For a list of these values, see the color_dialog constructor.
    /// @par Examples
    /// The following code example demonstrate the use of color_picker picker.
    /// @include color_picker.cpp
    /// @par Windows
    /// @image html color_picker_w.png
    /// <br>
    /// @image html color_picker_wd.png
    /// @par macOS
    /// @image html color_picker_m.png
    /// <br>
    /// @image html color_picker_md.png
    /// @par Gnome
    /// @image html color_picker_g.png
    /// <br>
    /// @image html color_picker_gd.png
    class forms_export_ color_picker : public control {
    public:
      /// @brief Initializes a new instance of the color_picker class.
      color_picker();

      /// @brief Gets the color selected by the user.
      /// @return The color selected by the user. If a color is not selected, the default value is black.
      /// @remarks The color selected by the user in the color picker at run time, as defined in color structure.
      const drawing::color& color() const {return color_;}
      /// @brief Sets the color selected by the user.
      /// @param color The color selected by the user. If a color is not selected.
      /// @remarks The color selected by the user in the color picker at run time, as defined in color structure.
      void color(const drawing::color& color);
      
      drawing::size default_size() const override {return {100, 25};}
      
      
      /// @brief Gets a value indicating whether the dialog box  shows alpha values and an opacity selector (slider).
      /// @return true if the dialog box  shows alpha values and an opacity selector (slider); otherwise, false. The default is true.
      bool alpha_color() const {return alpha_color_;}
      /// @brief Sets a value indicating whether the user can use the dialog box to define custom colors.
      /// @param alpha_color true if the dialog box  shows alpha values and an opacity selector (slider); otherwise, false.
      color_picker& alpha_color(bool alpha_color) {
        if (alpha_color_ != alpha_color) {
          alpha_color_ = alpha_color;
          recreate_handle();
        }
        return *this;
      }

      /// @brief Occurs when the value of the color property changes.
      /// @ingroup events
      event<color_picker, event_handler> color_changed;
      
    protected:
      forms::create_params create_params() const override;
      
      /// @brief Raises the color_changed event.
      /// @param e An event_args that contains the event data.
      void on_color_changed(const event_args& e);
      
      void on_handle_created(const event_args& e) override;
      
      void wnd_proc(message& message) override;
      
    private:
      void wm_click(message& message);
      drawing::color color_;
      bool alpha_color_ = false;
    };
  }
}
