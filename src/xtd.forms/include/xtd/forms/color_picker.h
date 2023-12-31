/// @file
/// @brief Contains xtd::forms::color_picker picker controls.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "color_picker_event_handler.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a picker control that displays available colors along with controls that enable the user to define custom colors.
    /// @par Header
    /// @code #include <xtd/forms/color_picker> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks The inherited member show_dialog must be invoked to create this specific common dialog box. hook_proc can be overridden to implement specific dialog box hook functionality. Use color to retrieve the color selected by the user.
    /// @remarks When you create an instance of color_dialog, some of the read/write properties are set to initial values. For a list of these values, see the color_dialog constructor.
    /// @par Appearance
    /// |       | Windows                                   | macOS                                     | Gnome                                     |
    /// | ----- | ----------------------------------------- | ----------------------------------------- | ----------------------------------------- |
    /// | Light |  @image html control_color_picker_w.png   |  @image html control_color_picker_m.png   |  @image html control_color_picker_g.png   |
    /// | Dark  |  @image html control_color_picker_wd.png  |  @image html control_color_picker_md.png  |  @image html control_color_picker_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of color_picker picker.
    /// @include color_picker.cpp
    class forms_export_ color_picker : public control {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the color_picker class.
      color_picker();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets a value indicating whether the dialog box  shows alpha values and an opacity selector (slider).
      /// @return true if the dialog box  shows alpha values and an opacity selector (slider); otherwise, false. The default is true.
      virtual bool alpha_color() const noexcept;
      /// @brief Sets a value indicating whether the user can use the dialog box to define custom colors.
      /// @param alpha_color true if the dialog box  shows alpha values and an opacity selector (slider); otherwise, false.
      virtual color_picker& alpha_color(bool alpha_color);
      
      /// @brief Gets the color selected by the user.
      /// @return The color selected by the user. If a color is not selected, the default value is black.
      /// @remarks The color selected by the user in the color picker at run time, as defined in color structure.
      virtual const drawing::color& color() const noexcept;
      /// @brief Sets the color selected by the user.
      /// @param color The color selected by the user. If a color is not selected.
      /// @remarks The color selected by the user in the color picker at run time, as defined in color structure.
      virtual color_picker& color(const drawing::color& color);
      /// @}
      
      
      /// @name Methods
      
      /// @{
      using control::create;
      /// @brief A factory to create an xtd::forms::color_picker with specified color, location, size, and name.
      /// @param color The color selected by the user. If a color is not selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::color_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::color_picker.
      /// @param name The name of the xtd::forms::color_picker.
      /// @return New xtd::forms::color_picker created.
      static color_picker create(const xtd::drawing::color& color, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @brief A factory to create an xtd::forms::color_picker with specified parent, color, location ,size, and name.
      /// @param parent The parent that contains the new created xtd::forms::color_picker.
      /// @param color The color selected by the user. If a color is not selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::color_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::color_picker.
      /// @param name The name of the xtd::forms::color_picker.
      /// @return New xtd::forms::color_picker created.
      static color_picker create(const control& parent, const xtd::drawing::color& color, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the value of the color property changes.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<color_picker, color_picker_event_handler> color_picker_changed;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      /// @brief Raises the color_changed event.
      /// @param e An event_args that contains the event data.
      void on_color_picker_changed(const color_picker_event_args& e);
      
      void on_handle_created(const event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void wm_command_control(message& message);
      void wm_command_control_selchange(message& message);
      
      std::shared_ptr<data> data_;
    };
  }
}
