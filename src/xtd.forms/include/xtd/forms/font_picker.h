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
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of font_picker picker.
    /// @include font_picker.cpp
    class forms_export_ font_picker : public control {
    public:
      /// @brief Initializes a new instance of the font_picker class.
      font_picker();

      /// @brief Gets the color selected by the user.
      /// @return The color selected by the user. If a color is not selected, the default value is black.
      /// @remarks The color selected by the user in the color picker at run time, as defined in color structure.
      const drawing::color& color() const {return color_;}
      /// @brief Sets the color selected by the user.
      /// @param color The color selected by the user. If a color is not selected.
      /// @brief This instance of control.
      /// @remarks The color selected by the user in the color picker at run time, as defined in color structure.
      control& color(const drawing::color& color);
      
      /// @brief Gets the selected font.
      /// @return The selected font.
      drawing::font font() const override {return font_;}
      /// @brief Sets the selected font.
      /// @param font The selected font.
      /// @return Current control.
      control& font(const drawing::font& font) override;
      
      drawing::size default_size() const override {return {100, 25};}
      
      /// @brief Occurs when the value of the font property changes.
      /// @ingroup events
      event<font_picker, event_handler> font_changed;

    protected:
      forms::create_params create_params() const override;
      
      /// @brief Raises the font_changed event.
      /// @param e An event_args that contains the event data.
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
