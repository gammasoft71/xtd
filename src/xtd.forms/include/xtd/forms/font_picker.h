/// @file
/// @brief Contains xtd::forms::font_picker control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "font_picker_event_handler.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a picker control that displays available fonts along with controls.
    /// @par Header
    /// @code #include <xtd/forms/font_picker> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                  | macOS                                    | Gnome                                    |
    /// | ----- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
    /// | Light |  @image html control_font_picker_w.png   |  @image html control_font_picker_m.png   |  @image html control_font_picker_g.png   |
    /// | Dark  |  @image html control_font_picker_wd.png  |  @image html control_font_picker_md.png  |  @image html control_font_picker_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of font_picker picker.
    /// @include font_picker.cpp
    class forms_export_ font_picker : public control {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the font_picker class.
      font_picker();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the color selected by the user.
      /// @return The color selected by the user. If a color is not selected, the default value is black.
      /// @remarks The color selected by the user in the color picker at run time, as defined in color structure.
      virtual const drawing::color& color() const noexcept;
      /// @brief Sets the color selected by the user.
      /// @param color The color selected by the user. If a color is not selected.
      /// @brief This instance of control.
      /// @remarks The color selected by the user in the color picker at run time, as defined in color structure.
      virtual font_picker& color(const drawing::color& color);
      
      /// @brief Gets the selected font.
      /// @return The selected font.
      drawing::font font() const noexcept override;
      /// @brief Sets the selected font.
      /// @param font The selected font.
      /// @return Current control.
      control& font(const drawing::font& font) override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create();
      /// @brief A factory to create an xtd::forms::font_picker with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::font_picker with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::font_picker with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::font_picker.
      /// @param name The name of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::font_picker with specified font.
      /// @param font The selected font.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const drawing::font& font);
      /// @brief A factory to create an xtd::forms::font_picker with specified font, and location.
      /// @param font The selected font.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const drawing::font& font, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::font_picker with specified font, location, and size.
      /// @param font The selected font.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const drawing::font& font, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::font_picker with specified font, location, size, and name.
      /// @param font The selected font.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::font_picker.
      /// @param name The name of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const drawing::font& font, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::font_picker with specified font, and color.
      /// @param font The selected font.
      /// @param color The color selected by the user. If a color is not selected.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const drawing::font& font, const xtd::drawing::color& color);
      /// @brief A factory to create an xtd::forms::font_picker with specified font, color, and location.
      /// @param font The selected font.
      /// @param color The color selected by the user. If a color is not selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const drawing::font& font, const xtd::drawing::color& color, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::font_picker with specified font, color, location, and size.
      /// @param font The selected font.
      /// @param color The color selected by the user. If a color is not selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const drawing::font& font, const xtd::drawing::color& color, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::font_picker with specified font, color, location, size, and name.
      /// @param font The selected font.
      /// @param color The color selected by the user. If a color is not selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::font_picker.
      /// @param name The name of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const drawing::font& font, const xtd::drawing::color& color, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::font_picker with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const control& parent);
      /// @brief A factory to create an xtd::forms::font_picker with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::font_picker.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::font_picker with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::font_picker.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::font_picker with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::font_picker.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::font_picker.
      /// @param name The name of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::font_picker with specified parent, and font.
      /// @param parent The parent that contains the new created xtd::forms::font_picker.
      /// @param font The selected font.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const control& parent, const drawing::font& font);
      /// @brief A factory to create an xtd::forms::font_picker with specified parent, font, and location.
      /// @param parent The parent that contains the new created xtd::forms::font_picker.
      /// @param font The selected font.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const control& parent, const drawing::font& font, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::font_picker with specified parent, font, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::font_picker.
      /// @param font The selected font.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const control& parent, const drawing::font& font, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::font_picker with specified parent, font, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::font_picker.
      /// @param font The selected font.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::font_picker.
      /// @param name The name of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const control& parent, const drawing::font& font, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::font_picker with specified parent, font, and color.
      /// @param parent The parent that contains the new created xtd::forms::font_picker.
      /// @param font The selected font.
      /// @param color The color selected by the user. If a color is not selected.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const control& parent, const drawing::font& font, const xtd::drawing::color& color);
      /// @brief A factory to create an xtd::forms::font_picker with specified parent, font, color, and location.
      /// @param parent The parent that contains the new created xtd::forms::font_picker.
      /// @param font The selected font.
      /// @param color The color selected by the user. If a color is not selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const control& parent, const drawing::font& font, const xtd::drawing::color& color, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::font_picker with specified parent, font, color, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::font_picker.
      /// @param font The selected font.
      /// @param color The color selected by the user. If a color is not selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const control& parent, const drawing::font& font, const xtd::drawing::color& color, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::font_picker with specified parent, font, color, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::font_picker.
      /// @param font The selected font.
      /// @param color The color selected by the user. If a color is not selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::font_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::font_picker.
      /// @param name The name of the xtd::forms::font_picker.
      /// @return New xtd::forms::font_picker created.
      static font_picker create(const control& parent, const drawing::font& font, const xtd::drawing::color& color, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the value of the font property changes.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<font_picker, font_picker_event_handler> font_picker_changed;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      /// @brief Raises the xtd::forms::control::font_changed event.
      /// @param e An event_args that contains the event data.
      void on_font_picker_changed(const font_picker_event_args& e);
      
      void on_handle_created(const event_args& e) override;
      
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void wm_command_control(message& message);
      void wm_command_control_selchange(message& message);
      
      std::shared_ptr<data> data_;
    };
  }
}
