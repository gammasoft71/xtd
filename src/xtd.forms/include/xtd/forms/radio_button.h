/// @file
/// @brief Contains xtd::forms::radio_button control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "visual_styles/radio_button_state.h"
#include "appearance.h"
#include "button_base.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Enables the user to select a single option from a group of choices when paired with other xtd::forms::radio_button controls.
    /// @code
    /// class forms_export_ radio_button : public xtd::forms::button_base
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::forms::component → xtd::forms::control → xtd::forms::button_base → xtd::forms::radio_button
    /// @par Header
    /// @code #include <xtd/forms/radio_button> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks The radio_button control can display text, an Image, or both.
    /// @remarks When the user selects one option button (also known as a radio button) within a group, the others clear automatically. All radio_button controls in a given container, such as a Form, constitute a group. To create multiple groups on one form, place each group in its own container, such as a group_box or panel control.
    /// @remarks radio_button and check_box controls have a similar function: they offer choices a user can select or clear. The difference is that multiple check_box controls can be selected at the same time, but option buttons are mutually exclusive.
    /// @remarks Use the checked property to get or set the state of a radio_button. The option button's appearance can be altered to appear as a toggle-style button or as a standard option button by setting the appearance property.
    /// @par Appearance
    /// |       | Windows                                   | macOS                                     | Gnome                                     |
    /// | ----- | ----------------------------------------- | ----------------------------------------- | ----------------------------------------- |
    /// | Light |  @image html control_radio_button_w.png   |  @image html control_radio_button_m.png   |  @image html control_radio_button_g.png   |
    /// | Dark  |  @image html control_radio_button_wd.png  |  @image html control_radio_button_md.png  |  @image html control_radio_button_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of radio_button control.
    /// @include radio_button.cpp
    class forms_export_ radio_button : public xtd::forms::button_base {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the radio_button class.
      /// @remarks The default view of the radio_button has its text aligned to the right of the button and the auto_check property is set to true.
      radio_button();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value determining the appearance of the radio_button.
      /// @return One of the appearance values. The default value is normal.
      /// @remarks If the appearance value is set to normal, then the radio_button control is drawn with a circular check box. If the value is set to button, then the radio_button is drawn as a control that can be toggled to an up or down state. Either type can display text, an image, or both.
      virtual forms::appearance appearance() const noexcept;
      /// @brief Sets a value determining the appearance of the radio_button.
      /// @param appearance One of the appearance values. The default value is normal.
      /// @return Current radio_button instance.
      /// @remarks If the appearance value is set to normal, then the radio_button control is drawn with a circular check box. If the value is set to button, then the radio_button is drawn as a control that can be toggled to an up or down state. Either type can display text, an image, or both.
      virtual radio_button& appearance(forms::appearance appearance);
      
      /// @brief Gets a value indicating whether the checked value and the appearance of the control automatically change when the control is clicked.
      /// @return true if the checked value and the appearance of the control automatically change on the click event; otherwise, false. The default value is true.
      /// @remarks If the checked value is set to false, the radio_button portion of the control must be checked in code in the click event handler. In addition, if the radio_button is part of a radio_button control group, this property ensures that only one of the controls is checked at a given time.
      /// @remarks If the auto_check property is set to false, a group of radio_button controls will not act as a mutually exclusive group and the checked property must be updated in code.
      virtual bool auto_check() const noexcept;
      /// @brief Sets a value indicating whether the checked value and the appearance of the control automatically change when the control is clicked.
      /// @param auto_check true if the checked value and the appearance of the control automatically change on the click event; otherwise, false. The default value is true.
      /// @return Current radio_button instance.
      /// @remarks If the checked value is set to false, the radio_button portion of the control must be checked in code in the click event handler. In addition, if the radio_button is part of a radio_button control group, this property ensures that only one of the controls is checked at a given time.
      /// @remarks If the auto_check property is set to false, a group of radio_button controls will not act as a mutually exclusive group and the checked property must be updated in code.
      virtual radio_button& auto_check(bool auto_check);
      
      /// @brief Gets a value indicating whether the control is checked.
      /// @return true if the check box is checked; otherwise, false.
      virtual bool checked() const noexcept;
      /// @brief Sets a value indicating whether the control is checked.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @return Current radio_button instance.
      virtual radio_button& checked(bool checked);
      
      /// @brief Gets the horizontal and vertical alignment of the check mark on a check_box control.
      /// @return One of the content_alignment values. The default value is middle_left.
      virtual content_alignment check_align() const noexcept;
      /// @brief Sets the horizontal and vertical alignment of the check mark on a check_box control.
      /// @param check_align One of the content_alignment values. The default value is middle_left.
      /// @return Current radio_button instance.
      virtual radio_button& check_align(content_alignment check_align);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Generates a click event for the control, simulating a click by a user.
      void perform_click();
      
      /// @brief Returns a string that represents the progress_bar control.
      /// @return A string that represents the current progress_bar.
      /// @remarks The return string includes the type and the values for the minimum, maximum, and value properties.
      xtd::ustring to_string() const noexcept override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create();
      /// @brief A factory to create an xtd::forms::radio_button with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::radio_button with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::radio_button with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::radio_button.
      /// @param name The name of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::radio_button with specified text.
      /// @param text A string that represent text of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const xtd::ustring& text);
      /// @brief A factory to create an xtd::forms::radio_button with specified text, and location.
      /// @param text A string that represent text of the xtd::forms::radio_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const xtd::ustring& text, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::radio_button with specified text, location, and size.
      /// @param text A string that represent text of the xtd::forms::radio_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::radio_button with specified text, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::radio_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::radio_button.
      /// @param name The name of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::radio_button with specified text, and checked.
      /// @param text A string that represent text of the xtd::forms::radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const xtd::ustring& text, bool checked);
      /// @brief A factory to create an xtd::forms::radio_button with specified text, checked, and location.
      /// @param text A string that represent text of the xtd::forms::radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const xtd::ustring& text, bool checked, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::radio_button with specified text, checked, location, and size.
      /// @param text A string that represent text of the xtd::forms::radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const xtd::ustring& text, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::radio_button with specified text, checked, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::radio_button.
      /// @param name The name of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const xtd::ustring& text, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create a xtd::forms::radio_button with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const control& parent);
      /// @brief A factory to create a xtd::forms::radio_button with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::radio_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const control& parent, const drawing::point& location);
      /// @brief A factory to create a xtd::forms::radio_button with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::radio_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create a xtd::forms::radio_button with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::radio_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::radio_button.
      /// @param name The name of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create a xtd::forms::radio_button with specified parent, and text.
      /// @param parent The parent that contains the new created xtd::forms::radio_button.
      /// @param text A string that represent text of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const control& parent, const xtd::ustring& text);
      /// @brief A factory to create a xtd::forms::radio_button with specified parent, text, and location.
      /// @param parent The parent that contains the new created xtd::forms::radio_button.
      /// @param text A string that represent text of the xtd::forms::radio_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const control& parent, const xtd::ustring& text, const drawing::point& location);
      /// @brief A factory to create a xtd::forms::radio_button with specified parent, text, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::radio_button.
      /// @param text A string that represent text of the xtd::forms::radio_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const control& parent, const xtd::ustring& text, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create a xtd::forms::radio_button with specified parent, text, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::radio_button.
      /// @param text A string that represent text of the xtd::forms::radio_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::radio_button.
      /// @param name The name of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const control& parent, const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create a xtd::forms::radio_button with specified parent, text, and checked.
      /// @param parent The parent that contains the new created xtd::forms::radio_button.
      /// @param text A string that represent text of the xtd::forms::radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const control& parent, const xtd::ustring& text, bool checked);
      /// @brief A factory to create a xtd::forms::radio_button with specified parent, text, checked, and location.
      /// @param parent The parent that contains the new created xtd::forms::radio_button.
      /// @param text A string that represent text of the xtd::forms::radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const control& parent, const xtd::ustring& text, bool checked, const drawing::point& location);
      /// @brief A factory to create a xtd::forms::radio_button with specified parent, text, checked, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::radio_button.
      /// @param text A string that represent text of the xtd::forms::radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const control& parent, const xtd::ustring& text, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create a xtd::forms::radio_button with specified parent, text, checked, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::radio_button.
      /// @param text A string that represent text of the xtd::forms::radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::radio_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::radio_button.
      /// @param name The name of the xtd::forms::radio_button.
      /// @return New xtd::forms::radio_button created.
      static radio_button create(const control& parent, const xtd::ustring& text, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the appearance property value changes.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<radio_button, event_handler> appearance_changed;
      
      /// @brief Occurs when the value of the checked property changes.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<radio_button, event_handler> checked_changed;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      /// @brief Gets the required creation parameters when the control handle is created.
      /// @return A create_params that contains the required creation parameters when the handle to the control is created.
      forms::create_params create_params() const noexcept override;
      
      /// @brief Gets state.
      /// @return One of xtd::forms::visual_styles::radio_button_state values.
      xtd::forms::visual_styles::radio_button_state state() const noexcept;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      /// @brief Measure this control.
      /// @return The drawing::size size of this control.
      /// @remarks This method is used when auto_size is true.
      drawing::size measure_control() const noexcept override;
      
      /// @brief Raises the radio_button::appearance_changed event.
      /// @param e An EventArgs that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_appearance_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Note to Inheritors
      /// When overriding on_appearance_changed(const event_args&) in a derived class, be sure to call the base class' on_appearance_changed(const event_args&) method so that registered delegates receive the event.
      virtual void on_appearance_changed(const event_args& e);
      
      /// @brief Raises the radio_button::radio_button::checked_changed event.
      /// @param e An EventArgs that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_checked_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Note to Inheritors
      /// When overriding on_checked_changed(const event_args&) in a derived class, be sure to call the base class' on_checked_changed(const event_args&) method so that registered delegates receive the event.
      virtual void on_checked_changed(const event_args& e);
      
      void on_enabled_changed(const event_args& e) override;
      void on_got_focus(const event_args& e) override;
      
      /// @brief Overrides the on_handle_created(const event_args&) method.
      /// @param e An event_args that contains the event data.
      void on_handle_created(const event_args& e) override;
      
      void on_lost_focus(const event_args& e) override;
      void on_mouse_down(const mouse_event_args& e) override;
      void on_mouse_enter(const event_args& e) override;
      void on_mouse_leave(const event_args& e) override;
      void on_mouse_move(const mouse_event_args& e) override;
      void on_mouse_up(const mouse_event_args& e) override;
      void on_paint(paint_event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
      /// @cond
      void wm_mouse_double_click(message& message);
      void wm_mouse_down(const message& message);
      void wm_mouse_up(const message& message);
      /// @endcond
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
