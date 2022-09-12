/// @file
/// @brief Contains xtd::forms::color_picker picker controls.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "color_picker_event_handler.h"

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
    /// The following code example demonstrates the use of color_picker picker.
    /// @include color_picker.cpp
    class forms_export_ color_picker : public control {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the color_picker class.
      color_picker();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the color selected by the user.
      /// @return The color selected by the user. If a color is not selected, the default value is black.
      /// @remarks The color selected by the user in the color picker at run time, as defined in color structure.
      const drawing::color& color() const {return color_;}
      /// @brief Sets the color selected by the user.
      /// @param color The color selected by the user. If a color is not selected.
      /// @remarks The color selected by the user in the color picker at run time, as defined in color structure.
      void color(const drawing::color& color);
      
      /// @brief Gets a value indicating whether the dialog box  shows alpha values and an opacity selector (slider).
      /// @return true if the dialog box  shows alpha values and an opacity selector (slider); otherwise, false. The default is true.
      bool alpha_color() const {return alpha_color_;}
      /// @brief Sets a value indicating whether the user can use the dialog box to define custom colors.
      /// @param alpha_color true if the dialog box  shows alpha values and an opacity selector (slider); otherwise, false.
      color_picker& alpha_color(bool alpha_color) {
        if (alpha_color_ != alpha_color) {
          alpha_color_ = alpha_color;
          post_recreate_handle();
        }
        return *this;
      }
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the value of the color property changes.
      /// @ingroup events
      /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
      event<color_picker, color_picker_event_handler> color_changed;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const override;
      /// @}

      /// @name Protected methods
      
      /// @{
      /// @brief Raises the color_changed event.
      /// @param e An event_args that contains the event data.
      void on_color_changed(const color_picker_event_args& e);

      void on_handle_created(const event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void wm_command_control(message& message);
      void wm_command_control_selchange(message& message);
      drawing::color backup_color_;
      drawing::color color_;
      bool alpha_color_ = true;
    };
  }
}
