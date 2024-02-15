/// @file
/// @brief Contains xtd::forms::switch_button control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#include "button_base.h"
#include <xtd/optional>

namespace xtd {
  namespace forms {
    /// @brief Represents a standard Windows switch button.
    /// @code
    /// class forms_export_ switch_button : public xtd::forms::button_base
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::forms::component → xtd::forms::control → xtd::forms::button_base → xtd::forms::switch_button
    /// @par Header
    /// @code #include <xtd/forms/switch_button> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                    | macOS                                      | Gnome                                      |
    /// | ----- | ------------------------------------------ | ------------------------------------------ | ------------------------------------------ |
    /// | Light |  @image html control_switch_button_w.png   |  @image html control_switch_button_m.png   |  @image html control_switch_button_g.png   |
    /// | Dark  |  @image html control_switch_button_wd.png  |  @image html control_switch_button_md.png  |  @image html control_switch_button_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of switch button control.
    /// @include switch_button.cpp
    class switch_button : public xtd::forms::button_base {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// Initialize new instance of switch_button class.
      switch_button();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets a value indicating whether the checked and the switch_button's appearance are automatically changed when the switch_button is clicked.
      /// @return true if the checked value and the appearance of the control are automatically changed on the click event; otherwise, false. The default value is true.
      /// @remarks If auto_check is set to false, you will need to add code to update the checked in the click event handler.
      virtual bool auto_check() const noexcept;
      /// @brief Sets a value indicating whether the checked and the switch_button's appearance are automatically changed when the switch_button is clicked.
      /// @param auto_check true if the checked value and the appearance of the control are automatically changed on the click event; otherwise, false. The default value is true.
      /// @return Current switch_button instance.
      /// @remarks If auto_check is set to false, you will need to add code to update the checked in the click event handler.
      virtual switch_button& auto_check(bool auto_check);
      
      /// @brief Gets the checked background color for the control.
      /// @return A xtd::drawing::color that represents the checked background color of the control. The default is the value of the xtd::forms::theme_colors::current_theme::accent color.
      virtual xtd::drawing::color checked_back_color() const noexcept;
      /// @brief Sets the checked background color for the control.
      /// @param color A xtd::drawing::color that represents the checked background color of the control. The default is the value of the xtd::forms::theme_colors::current_theme::accent color.
      virtual switch_button& checked_back_color(const xtd::drawing::color& color);
      /// @cond
      virtual switch_button& checked_back_color(std::nullptr_t);
      /// @endcond
      
      /// @brief Gets the slider color for the control.
      /// @return A xtd::drawing::color that represents the slider color of the control. The default is the value of the xtd::switch_button::back_color property.
      virtual xtd::drawing::color slider_color() const noexcept;
      /// @brief Sets the slider color for the control.
      /// @param color A xtd::drawing::color that represents the slider color of the control. The default is the value of the xtd::switch_button::back_color property.
      virtual switch_button& slider_color(const xtd::drawing::color& color);
      /// @cond
      virtual switch_button& slider_color(std::nullptr_t);
      /// @endcond
      
      /// @brief Gets a value indicating whether the switch_button is rounded appearance.
      /// @return true if the switch_button is in the rounded appearance; otherwise, false. The default value is true.
      virtual bool rounded() const noexcept;
      /// @brief Sets a value indicating whether the switch_button is rounded appearance.
      /// @param value true if the switch_button is in the rounded appearance; otherwise, false. The default value is true.
      /// @return Current switch_button instance.
      virtual switch_button& rounded(bool value);
      
      /// @brief Gets a value indicating whether the switch_button is in the checked state.
      /// @return true if the switch_button is in the checked state; otherwise, false. The default value is false.
      virtual bool checked() const noexcept;
      /// @brief Sets a value indicating whether the switch_button is in the checked state.
      /// @param checked true if the switch_button is in the checked state; otherwise, false. The default value is false.
      /// @return Current switch_button instance.
      virtual switch_button& checked(bool checked);
      
      /// @brief Gets a value indicating whether the switch_button text is shown.
      /// @return true if the switch_button text is shown; otherwise, false. The default value is false.
      virtual bool show_text() const noexcept;
      /// @brief Sets a value indicating whether the switch_button text is shown.
      /// @param value true if the switch_button text is shown; otherwise, false. The default value is false.
      /// @return Current switch_button instance.
      virtual switch_button& show_text(bool value);
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::switch_button with specified text, three_state, check_state, location ,size, and name.
      /// @param text A string that represent text of the xtd::forms::switch_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::switch_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::switch_button.
      /// @param name The name of the xtd::forms::switch_button.
      /// @return New xtd::forms::switch_button created.
      static switch_button create(bool checked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @brief A factory to create a xtd::forms::switch_button with specified parent, text, three_state, check_state, location ,size, and name.
      /// @param parent The parent that contains the new created xtd::forms::switch_button.
      /// @param text A string that represent text of the xtd::forms::switch_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::switch_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::switch_button.
      /// @param name The name of the xtd::forms::switch_button.
      /// @return New xtd::forms::switch_button created.
      static switch_button create(const control& parent, bool checked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the value of the checked property changes.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<switch_button, event_handler> checked_changed;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      /// @brief Gets the default size of the control.
      /// @return The default size.
      drawing::size default_size() const noexcept override;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      /// @brief Raises the switch_button::checked_changed event.
      /// @param e An event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_checked_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      virtual void on_checked_changed(const event_args& e);
      
      void on_mouse_down(const mouse_event_args& e) override;
      void on_handle_created(const event_args& e) override;
      void on_paint(paint_event_args& e) override;
      void on_resize(const event_args& e) override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
