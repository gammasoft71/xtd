/// @file
/// @brief Contains xtd::forms::command_link_button control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "button_base.h"
#include "dialog_result.h"
#include "ibutton_control.h"
#include "timer.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows coommand link button control.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of command link button control.
    /// @include command_link_button.cpp
    /// @par Windows
    /// @image html command_link_button_w.png
    /// <br>
    /// @image html command_link_button_wd.png
    /// @par macOS
    /// @image html command_link_button_m.png
    /// <br>
    /// @image html command_link_button_md.png
    /// @par Gnome
    /// @image html command_link_button_g.png
    /// <br>
    /// @image html command_link_button_gd.png
    class forms_export_ command_link_button : public button_base {
    public:
      /// @brief Initializes a new instance of the button class.
      /// @remarks By default the button displays no caption. To specify the caption text, set the text property.
      command_link_button();
      
      /// @brief Gets the mode by which the button automatically resizes itself.
      /// @return One of the AutoSizeMode values. The default value is grow_only.
      virtual forms::auto_size_mode auto_size_mode() const {return auto_size_mode_;}
      /// @brief Sets the mode by which the button automatically resizes itself.
      /// @param value One of the AutoSizeMode values. The default value is growonly.
      virtual command_link_button& auto_size_mode(forms::auto_size_mode value);
      
      /// @brief Set text and supplementary text.
      /// @param text A string that represent control text
      /// @param supplementary_text A string thatt represent supplementary text.
      /// @remarks Is equavant to call text property with text and spplementary_text separed by "\n".
      virtual control& texts(const xtd::ustring& text, const xtd::ustring& supplementary_text) {return this->text(ustring::format("{}{}{}", text, environment::new_line(), supplementary_text));}

      drawing::size default_size() const override {return {200, 60};}
      
      drawing::size measure_control() const override;
      
    protected:
      forms::create_params create_params() const override;
      
      void on_handle_created(const event_args& e) override;
      
      /*
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;
       */

      /// @cond
      forms::dialog_result dialog_result_ = forms::dialog_result::none;
      /// @endcond

    private:
      //void wm_click(message& message);
      //void wm_mouse_up(message& message);
   };
  }
}
