/// @file
/// @brief Contains xtd::forms::color_picker picker controls.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "control.hpp"
#include "color_picker_event_handler.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a picker control that displays available colors along with controls that enable the user to define custom colors.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/color_picker>
    /// ```
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
    /// | Light |  @image html control_color_picker_w.png   |  @image html control_color_picker_m.png   |  @image html control_color_picker_g.png   |
    /// | Dark  |  @image html control_color_picker_wd.png  |  @image html control_color_picker_md.png  |  @image html control_color_picker_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of color_picker picker.
    /// @include color_picker.cpp
    class forms_export_ color_picker : public control {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the color_picker class.
      color_picker();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicating whether the dialog box  shows alpha values and an opacity selector (slider).
      /// @return `true` if the dialog box  shows alpha values and an opacity selector (slider); otherwise, `false`. The default is `true`.
      [[nodiscard]] virtual auto alpha_color() const noexcept -> bool;
      /// @brief Sets a value indicating whether the user can use the dialog box to define custom colors.
      /// @param value `true` if the dialog box  shows alpha values and an opacity selector (slider); otherwise, `false`.
      virtual auto alpha_color(bool value) -> color_picker&;
      
      /// @brief Gets the color selected by the user.
      /// @return The color selected by the user. If a color is not selected, the default value is black.
      /// @remarks The color selected by the user in the color picker at run time, as defined in color structure.
      [[nodiscard]] virtual auto color() const noexcept -> const xtd::drawing::color&;
      /// @brief Sets the color selected by the user.
      /// @param value The color selected by the user. If a color is not selected.
      /// @remarks The color selected by the user in the color picker at run time, as defined in color structure.
      virtual auto color(const xtd::drawing::color& value) -> color_picker&;
      /// @}
      
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::color_picker.
      /// @return New xtd::forms::color_picker created.
      [[nodiscard]] static auto create() -> color_picker;
      /// @brief A factory to create an xtd::forms::color_picker with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::color_picker.
      /// @return New xtd::forms::color_picker created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location) -> color_picker;
      /// @brief A factory to create an xtd::forms::color_picker with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::color_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::color_picker.
      /// @return New xtd::forms::color_picker created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size) -> color_picker;
      /// @brief A factory to create an xtd::forms::color_picker with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::color_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::color_picker.
      /// @param name The name of the xtd::forms::color_picker.
      /// @return New xtd::forms::color_picker created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> color_picker;
      /// @brief A factory to create an xtd::forms::color_picker with specified color.
      /// @param color The color selected by the user. If a color is not selected.
      /// @return New xtd::forms::color_picker created.
      [[nodiscard]] static auto create(const xtd::drawing::color& color) -> color_picker;
      /// @brief A factory to create an xtd::forms::color_picker with specified color, and location.
      /// @param color The color selected by the user. If a color is not selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::color_picker.
      /// @return New xtd::forms::color_picker created.
      [[nodiscard]] static auto create(const xtd::drawing::color& color, const xtd::drawing::point& location) -> color_picker;
      /// @brief A factory to create an xtd::forms::color_picker with specified color, location, and size.
      /// @param color The color selected by the user. If a color is not selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::color_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::color_picker.
      /// @return New xtd::forms::color_picker created.
      [[nodiscard]] static auto create(const xtd::drawing::color& color, const xtd::drawing::point& location, const xtd::drawing::size& size) -> color_picker;
      /// @brief A factory to create an xtd::forms::color_picker with specified color, location, size, and name.
      /// @param color The color selected by the user. If a color is not selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::color_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::color_picker.
      /// @param name The name of the xtd::forms::color_picker.
      /// @return New xtd::forms::color_picker created.
      [[nodiscard]] static auto create(const xtd::drawing::color& color, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> color_picker;
      /// @brief A factory to create an xtd::forms::color_picker with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::color_picker.
      /// @return New xtd::forms::color_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent) -> color_picker;
      /// @brief A factory to create an xtd::forms::color_picker with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::color_picker.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::color_picker.
      /// @return New xtd::forms::color_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location) -> color_picker;
      /// @brief A factory to create an xtd::forms::color_picker with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::color_picker.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::color_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::color_picker.
      /// @return New xtd::forms::color_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> color_picker;
      /// @brief A factory to create an xtd::forms::color_picker with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::color_picker.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::color_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::color_picker.
      /// @param name The name of the xtd::forms::color_picker.
      /// @return New xtd::forms::color_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> color_picker;
      /// @brief A factory to create an xtd::forms::color_picker with specified parent, and color.
      /// @param parent The parent that contains the new created xtd::forms::color_picker.
      /// @param color The color selected by the user. If a color is not selected.
      /// @return New xtd::forms::color_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::color& color) -> color_picker;
      /// @brief A factory to create an xtd::forms::color_picker with specified parent, color, and location.
      /// @param parent The parent that contains the new created xtd::forms::color_picker.
      /// @param color The color selected by the user. If a color is not selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::color_picker.
      /// @return New xtd::forms::color_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::color& color, const xtd::drawing::point& location) -> color_picker;
      /// @brief A factory to create an xtd::forms::color_picker with specified parent, color, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::color_picker.
      /// @param color The color selected by the user. If a color is not selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::color_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::color_picker.
      /// @return New xtd::forms::color_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::color& color, const xtd::drawing::point& location, const xtd::drawing::size& size) -> color_picker;
      /// @brief A factory to create an xtd::forms::color_picker with specified parent, color, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::color_picker.
      /// @param color The color selected by the user. If a color is not selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::color_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::color_picker.
      /// @param name The name of the xtd::forms::color_picker.
      /// @return New xtd::forms::color_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::color& color, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> color_picker;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the value of the color property changes.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<color_picker, xtd::forms::color_picker_event_handler> color_picker_changed;
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      [[nodiscard]] auto create_params() const noexcept -> xtd::forms::create_params override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Raises the color_changed event.
      /// @param e An event_args that contains the event data.
      auto on_color_picker_changed(const color_picker_event_args& e) -> void;
      
      auto on_handle_created(const event_args& e) -> void override;
      auto wnd_proc(message& message) -> void override;
      /// @}
      
    private:
      auto wm_command_control(message& message) -> void;
      auto wm_command_control_selchange(message& message) -> void;
      
      xtd::sptr<data> data_;
    };
  }
}
