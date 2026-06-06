/// @file
/// @brief Contains xtd::forms::button control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "button_base.hpp"
#include "dialog_result.hpp"
#include "ibutton_control.hpp"
#include "timer.hpp"
#include "visual_styles/push_button_state.hpp"
#include <xtd/environment>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows button control.
    /// ```cpp
    /// class forms_export_ button : public xtd::forms::ibutton_control, public xtd::forms::button_base
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::forms::component → xtd::forms::control → xtd::forms::button_base → xtd::forms::button
    /// @par Implements
    /// xtd::forms::ibutton_control
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/button>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks A Button can be clicked by using the mouse, ENTER key, or SPACEBAR if the button has focus.
    /// @remarks Set the accept_button or cancel_button property of a form to allow users to click a button by pressing the ENTER or ESC keys even if the button does not have focus. This gives the form the behavior of a dialog box.
    /// @remarks When you display a form using the show_dialog method, you can use the dialog_result property of a button to specify the return value of show_dialog.
    /// @remarks You can change the button's appearance. For example, to make it appear flat for a Web look, set the flat_style property to flat_style::flat. The flat_style property can also be set to flat_style::popup, which appears flat until the mouse pointer passes over the button; then the button takes on the standard Windows button appearance.
    /// @note If the control that has focus accepts and processes the ENTER key press, the button does not process it. For example, if a multiline text_box or another button has focus, that control processes the ENTER key press instead of the accept button.
    /// @par Appearance
    /// |       | Windows                             | macOS                               | Gnome                               |
    /// | ----- | ----------------------------------- | ----------------------------------- | ----------------------------------- |
    /// | Light |  @image html control_button_w.png   |  @image html control_button_m.png   |  @image html control_button_g.png   |
    /// | Dark  |  @image html control_button_wd.png  |  @image html control_button_md.png  |  @image html control_button_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of button control.
    /// @include button.cpp
    /// @par Examples
    /// The following code example demonstrates the use of button control with bitmap.
    /// @include bitmap_button.cpp
    class forms_export_ button : public xtd::forms::ibutton_control, public xtd::forms::button_base {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the button class.
      /// @remarks By default the button displays no caption. To specify the caption text, set the text property.
      button();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets if this button instance is auto repeat.
      /// @return `true`, if is auto repeat; otherwise `false`. Default is `false`.
      [[nodiscard]] virtual auto auto_repeat() const noexcept -> bool;
      /// @brief Sets if this button instance is auto repeat.
      /// @param value `true`, if is auto repeat; otherwise `false`. Default is `false`.
      /// @return This button.
      virtual auto auto_repeat(bool value) -> button&;
      
      /// @brief Gets the auto repeat delay.
      /// @return Auto repeat delay. Default is 300 ms.
      [[nodiscard]] virtual auto auto_repeat_delay() const noexcept -> xtd::time_span;
      /// @brief Gets the auto repeat delay.
      /// @param value Auto repeat delay. Default is 300 ms.
      /// @return This button.
      virtual auto auto_repeat_delay(const xtd::time_span& value) -> button&;
      /// @brief Gets the auto repeat delay.
      /// @param value Auto repeat delay in milliseconds. Default is 300 ms.
      /// @return This button.
      virtual auto auto_repeat_delay(xtd::int32 value) -> button&;

      /// @brief Gets the auto repeat delay.
      /// @return Auto repeat delay in milliseconds. Default is 300 ms.
      [[nodiscard]] virtual auto auto_repeat_delay_milliseconds() const noexcept -> xtd::int32;

      /// @brief Gets the auto repeat interval.
      /// @return Auto repeat interval. Default is 100 ms.
      [[nodiscard]] virtual auto auto_repeat_interval() const noexcept -> xtd::time_span;
      /// @brief Gets the auto repeat interval.
      /// @param value Auto repeat interval. Default is 100 ms.
      /// @return This button.
      virtual auto auto_repeat_interval(const xtd::time_span& value) -> button&;
      /// @brief Gets the auto repeat interval.
      /// @param value Auto repeat interval in milliseconds. Default is 100 ms.
      /// @return This button.
      virtual auto auto_repeat_interval(xtd::int32 value) -> button&;

      /// @brief Gets the auto repeat interval.
      /// @return Auto repeat interval in milliseconds. Default is 100 ms.
      [[nodiscard]] virtual auto auto_repeat_interval_milliseconds() const noexcept -> xtd::int32;

      /// @brief Gets the mode by which the button automatically resizes itself.
      /// @return One of the AutoSizeMode values. The default value is grow_only.
      [[nodiscard]] virtual auto auto_size_mode() const noexcept -> xtd::forms::auto_size_mode;
      /// @brief Sets the mode by which the button automatically resizes itself.
      /// @param value One of the AutoSizeMode values. The default value is grow only.
      virtual auto auto_size_mode(xtd::forms::auto_size_mode value) -> button&;
      
      [[nodiscard]] auto dialog_result() const noexcept -> xtd::forms::dialog_result override;
      auto dialog_result(xtd::forms::dialog_result value) -> xtd::forms::control& override;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      auto notify_default(bool value) -> void override;
      
      auto perform_click() -> void override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::button.
      /// @return New xtd::forms::button created.
      [[nodiscard]] static auto create() -> button;
      /// @brief A factory to create an xtd::forms::button with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location) -> button;
      /// @brief A factory to create an xtd::forms::button with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size) -> button;
      /// @brief A factory to create an xtd::forms::button with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::button.
      /// @param name The name of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> button;
      /// @brief A factory to create an xtd::forms::button with specified text.
      /// @param text A string that represent text of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      [[nodiscard]] static auto create(const xtd::string& text) -> button;
      /// @brief A factory to create an xtd::forms::button with specified text, and location.
      /// @param text A string that represent text of the xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      [[nodiscard]] static auto create(const xtd::string& text, const xtd::drawing::point& location) -> button;
      /// @brief A factory to create an xtd::forms::button with specified text, location, and size.
      /// @param text A string that represent text of the xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      [[nodiscard]] static auto create(const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size) -> button;
      /// @brief A factory to create an xtd::forms::button with specified text, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::button.
      /// @param name The name of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      [[nodiscard]] static auto create(const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> button;
      /// @brief A factory to create an xtd::forms::button with specified parent,.
      /// @param parent The parent that contains the new created xtd::forms::button.
      /// @return New xtd::forms::button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent) -> button;
      /// @brief A factory to create an xtd::forms::button with specified parent, location.
      /// @param parent The parent that contains the new created xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location) -> button;
      /// @brief A factory to create an xtd::forms::button with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> button;
      /// @brief A factory to create an xtd::forms::button with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::button.
      /// @param name The name of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> button;
      /// @brief A factory to create an xtd::forms::button with specified parent, and text.
      /// @param parent The parent that contains the new created xtd::forms::button.
      /// @param text A string that represent text of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::string& text) -> button;
      /// @brief A factory to create an xtd::forms::button with specified parent, text, and location.
      /// @param parent The parent that contains the new created xtd::forms::button.
      /// @param text A string that represent text of the xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::string& text, const xtd::drawing::point& location) -> button;
      /// @brief A factory to create an xtd::forms::button with specified parent, text, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::button.
      /// @param text A string that represent text of the xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size) -> button;
      /// @brief A factory to create an xtd::forms::button with specified parent, text, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::button.
      /// @param text A string that represent text of the xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::button.
      /// @param name The name of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> button;
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      [[nodiscard]] auto create_params() const noexcept -> xtd::forms::create_params override;
      
      /// @brief Gets state.
      /// @return One of xtd::forms::visual_styles::push_button_state values.
      [[nodiscard]] auto state() const noexcept -> xtd::forms::visual_styles::push_button_state;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      [[nodiscard]] auto measure_control() const noexcept -> xtd::drawing::size override;
      
      auto on_click(const event_args& e) -> void override;
      auto on_enabled_changed(const event_args& e) -> void override;
      auto on_handle_created(const event_args& e) -> void override;
      auto on_image_changed(const xtd::event_args& e) -> void override;
      auto on_mouse_down(const mouse_event_args& e) -> void override;
      auto on_mouse_enter(const event_args& e) -> void override;
      auto on_mouse_leave(const event_args& e) -> void override;
      auto on_mouse_up(const mouse_event_args& e) -> void override;
      auto on_paint(paint_event_args& e) -> void override;
      /// @}
      
    private:
      auto auto_repeat_perform_click() -> void;
      
      xtd::sptr<data> data_;
    };
  }
}
