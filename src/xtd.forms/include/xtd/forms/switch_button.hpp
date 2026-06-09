/// @file
/// @brief Contains xtd::forms::switch_button control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#include "button_base.hpp"
#include <xtd/optional>

namespace xtd {
  namespace forms {
    /// @brief Represents a standard Windows switch button.
    /// ```cpp
    /// class forms_export_ switch_button : public xtd::forms::button_base
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::forms::component → xtd::forms::control → xtd::forms::button_base → xtd::forms::switch_button
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/switch_button>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                    | macOS                                      | Gnome                                      |
    /// | ----- | ------------------------------------------ | ------------------------------------------ | ------------------------------------------ |
    /// | Light |  @image html control_switch_button_w.png   |  @image html control_switch_button_m.png   |  @image html control_switch_button_g.png   |
    /// | Dark  |  @image html control_switch_button_wd.png  |  @image html control_switch_button_md.png  |  @image html control_switch_button_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of switch button control.
    /// @include switch_button.cpp
    class switch_button : public xtd::forms::button_base {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// Initialize new instance of switch_button class.
      switch_button();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicating whether the checked and the switch_button's appearance are automatically changed when the switch_button is clicked.
      /// @return `true` if the checked value and the appearance of the control are automatically changed on the click event; otherwise, `false`. The default value is `true`.
      /// @remarks If auto_check is set to `false`, you will need to add code to update the checked in the click event handler.
      [[nodiscard]] virtual auto auto_check() const noexcept -> bool;
      /// @brief Sets a value indicating whether the checked and the switch_button's appearance are automatically changed when the switch_button is clicked.
      /// @param value `true` if the checked value and the appearance of the control are automatically changed on the click event; otherwise, `false`. The default value is `true`.
      /// @return Current switch_button instance.
      /// @remarks If auto_check is set to `false`, you will need to add code to update the checked in the click event handler.
      virtual auto auto_check(bool value) -> switch_button&;
      
      /// @brief Gets the checked background color for the control.
      /// @return A xtd::drawing::color that represents the checked background color of the control. The default is the value of the xtd::forms::theme_colors::current_theme::accent color.
      [[nodiscard]] virtual auto checked_back_color() const noexcept -> xtd::drawing::color;
      /// @brief Sets the checked background color for the control.
      /// @param value A xtd::drawing::color that represents the checked background color of the control. The default is the value of the xtd::forms::theme_colors::current_theme::accent color.
      virtual auto checked_back_color(const xtd::drawing::color& value) -> switch_button&;
      /// @brief Resets the checked background color for the control.
      /// @param xtd::null.
      virtual auto checked_back_color(xtd::null_ptr) -> switch_button&;
      
      /// @brief Gets the slider color for the control.
      /// @return A xtd::drawing::color that represents the slider color of the control. The default is the value of the xtd::switch_button::back_color property.
      [[nodiscard]] virtual auto slider_color() const noexcept -> xtd::drawing::color;
      /// @brief Sets the slider color for the control.
      /// @param value A xtd::drawing::color that represents the slider color of the control. The default is the value of the xtd::switch_button::back_color property.
      virtual auto slider_color(const xtd::drawing::color& value) -> switch_button&;
      /// @brief Resets the slider color for the control.
      /// @param xtd::null.
      virtual auto slider_color(xtd::null_ptr) -> switch_button&;
      
      /// @brief Gets a value indicating whether the switch_button is rounded appearance.
      /// @return `true` if the switch_button is in the rounded appearance; otherwise, `false`. The default value is `true`.
      [[nodiscard]] virtual auto rounded() const noexcept -> bool;
      /// @brief Sets a value indicating whether the switch_button is rounded appearance.
      /// @param value `true` if the switch_button is in the rounded appearance; otherwise, `false`. The default value is `true`.
      /// @return Current switch_button instance.
      virtual auto rounded(bool value) -> switch_button&;
      
      /// @brief Gets a value indicating whether the switch_button is in the checked state.
      /// @return `true` if the switch_button is in the checked state; otherwise, `false`. The default value is `false`.
      [[nodiscard]] virtual auto checked() const noexcept -> bool;
      /// @brief Sets a value indicating whether the switch_button is in the checked state.
      /// @param value `true` if the switch_button is in the checked state; otherwise, `false`. The default value is `false`.
      /// @return Current switch_button instance.
      virtual auto checked(bool value) -> switch_button&;
      
      /// @brief Gets a value indicating whether the switch_button text is shown.
      /// @return `true` if the switch_button text is shown; otherwise, `false`. The default value is `false`.
      [[nodiscard]] virtual auto show_text() const noexcept -> bool;
      /// @brief Sets a value indicating whether the switch_button text is shown.
      /// @param value `true` if the switch_button text is shown; otherwise, `false`. The default value is `false`.
      /// @return Current switch_button instance.
      virtual auto show_text(bool value) -> switch_button&;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::switch_button.
      /// @return New xtd::forms::switch_button created.
      [[nodiscard]] static auto create() -> switch_button;
      /// @brief A factory to create an xtd::forms::switch_button with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::switch_button.
      /// @return New xtd::forms::switch_button created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location) -> switch_button;
      /// @brief A factory to create an xtd::forms::switch_button with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::switch_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::switch_button.
      /// @return New xtd::forms::switch_button created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size) -> switch_button;
      /// @brief A factory to create an xtd::forms::switch_button with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::switch_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::switch_button.
      /// @param name The name of the xtd::forms::switch_button.
      /// @return New xtd::forms::switch_button created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> switch_button;
      /// @brief A factory to create an xtd::forms::switch_button with specified text, and checked.
      /// @param text A string that represent text of the xtd::forms::switch_button.
      /// @param checked `true` if the check box is checked; otherwise, `false`.
      /// @return New xtd::forms::switch_button created.
      [[nodiscard]] static auto create(bool checked) -> switch_button;
      /// @brief A factory to create an xtd::forms::switch_button with specified text, checked, and location.
      /// @param text A string that represent text of the xtd::forms::switch_button.
      /// @param checked `true` if the check box is checked; otherwise, `false`.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::switch_button.
      /// @return New xtd::forms::switch_button created.
      [[nodiscard]] static auto create(bool checked, const xtd::drawing::point& location) -> switch_button;
      /// @brief A factory to create an xtd::forms::switch_button with specified text, checked, location, and size.
      /// @param text A string that represent text of the xtd::forms::switch_button.
      /// @param checked `true` if the check box is checked; otherwise, `false`.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::switch_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::switch_button.
      /// @return New xtd::forms::switch_button created.
      [[nodiscard]] static auto create(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> switch_button;
      /// @brief A factory to create an xtd::forms::switch_button with specified text, checked, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::switch_button.
      /// @param checked `true` if the check box is checked; otherwise, `false`.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::switch_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::switch_button.
      /// @param name The name of the xtd::forms::switch_button.
      /// @return New xtd::forms::switch_button created.
      [[nodiscard]] static auto create(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> switch_button;
      /// @brief A factory to create a xtd::forms::switch_button with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::switch_button.
      /// @return New xtd::forms::switch_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent) -> switch_button;
      /// @brief A factory to create a xtd::forms::switch_button with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::switch_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::switch_button.
      /// @return New xtd::forms::switch_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location) -> switch_button;
      /// @brief A factory to create a xtd::forms::switch_button with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::switch_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::switch_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::switch_button.
      /// @return New xtd::forms::switch_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> switch_button;
      /// @brief A factory to create a xtd::forms::switch_button with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::switch_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::switch_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::switch_button.
      /// @param name The name of the xtd::forms::switch_button.
      /// @return New xtd::forms::switch_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> switch_button;
      /// @brief A factory to create a xtd::forms::switch_button with specified parent, text, and checked.
      /// @param parent The parent that contains the new created xtd::forms::switch_button.
      /// @param text A string that represent text of the xtd::forms::switch_button.
      /// @param checked `true` if the check box is checked; otherwise, `false`.
      /// @return New xtd::forms::switch_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, bool checked) -> switch_button;
      /// @brief A factory to create a xtd::forms::switch_button with specified parent, text, checked, and location.
      /// @param parent The parent that contains the new created xtd::forms::switch_button.
      /// @param text A string that represent text of the xtd::forms::switch_button.
      /// @param checked `true` if the check box is checked; otherwise, `false`.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::switch_button.
      /// @return New xtd::forms::switch_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> switch_button;
      /// @brief A factory to create a xtd::forms::switch_button with specified parent, text, checked, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::switch_button.
      /// @param text A string that represent text of the xtd::forms::switch_button.
      /// @param checked `true` if the check box is checked; otherwise, `false`.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::switch_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::switch_button.
      /// @return New xtd::forms::switch_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> switch_button;
      /// @brief A factory to create a xtd::forms::switch_button with specified parent, text, checked, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::switch_button.
      /// @param text A string that represent text of the xtd::forms::switch_button.
      /// @param checked `true` if the check box is checked; otherwise, `false`.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::switch_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::switch_button.
      /// @param name The name of the xtd::forms::switch_button.
      /// @return New xtd::forms::switch_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> switch_button;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the value of the checked property changes.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<switch_button, xtd::event_handler> checked_changed;
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      /// @brief Gets the default size of the control.
      /// @return The default size.
      [[nodiscard]] auto default_size() const noexcept -> xtd::drawing::size override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Raises the switch_button::checked_changed event.
      /// @param e An event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_checked_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      virtual auto on_checked_changed(const xtd::event_args& e) -> void;
      
      auto on_mouse_down(const xtd::forms::mouse_event_args& e) -> void override;
      auto on_handle_created(const xtd::event_args& e) -> void override;
      auto on_paint(xtd::forms::paint_event_args& e) -> void override;
      auto on_resize(const xtd::event_args& e) -> void override;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
