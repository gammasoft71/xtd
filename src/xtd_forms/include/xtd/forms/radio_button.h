#pragma once
#include "appearance.h"
#include "button_base.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Enables the user to select a single option from a group of choices when paired with other radio_button controls.
    /// @remarks The radio_button control can display text, an Image, or both.
    /// @remarks When the user selects one option button (also known as a radio button) within a group, the others clear automatically. All radio_button controls in a given container, such as a Form, constitute a group. To create multiple groups on one form, place each group in its own container, such as a group_box or panel control.
    /// @remarks radio_button and check_box controls have a similar function: they offer choices a user can select or clear. The difference is that multiple check_box controls can be selected at the same time, but option buttons are mutually exclusive.
    /// @remarks Use the checked property to get or set the state of a radio_button. The option button's appearance can be altered to appear as a toggle-style button or as a standard option button by setting the appearance property.
    /// @par Example
    /// The following code example demonstrate the use of radio_button control.
    /// @include radio_button.cpp
    class radio_button : public button_base {
    public:
      /// @brief Initializes a new instance of the radio_button class.
      /// @remarks The default view of the radio_button has its text aligned to the right of the button and the auto_check property is set to true.
      radio_button();

      /// @brief Gets a value determining the appearance of the radio_button.
      /// @return One of the appearance values. The default value is normal.
      /// @remarks If the appearance value is set to normal, then the radio_button control is drawn with a circular check box. If the value is set to button, then the radio_button is drawn as a control that can be toggled to an up or down state. Either type can display text, an image, or both.
      virtual forms::appearance appearance() const {return this->appearance_;}
      /// @brief Sets a value determining the appearance of the radio_button.
      /// @param appearance One of the appearance values. The default value is normal.
      /// @remarks If the appearance value is set to normal, then the radio_button control is drawn with a circular check box. If the value is set to button, then the radio_button is drawn as a control that can be toggled to an up or down state. Either type can display text, an image, or both.
      virtual radio_button& appearance(forms::appearance appearance);

      /// @brief Gets a value indicating whether the checked value and the appearance of the control automatically change when the control is clicked.
      /// @return true if the checked value and the appearance of the control automatically change on the click event; otherwise, false. The default value is true.
      /// @remarks If the checked value is set to false, the radio_button portion of the control must be checked in code in the click event handler. In addition, if the radio_button is part of a radio_button control group, this property ensures that only one of the controls is checked at a given time.
      /// @remarks If the auto_check property is set to false, a group of radio_button controls will not act as a mutually exclusive group and the checked property must be updated in code.
      virtual bool auto_check() const {return this->auto_check_;}
      /// @brief Sets a value indicating whether the checked value and the appearance of the control automatically change when the control is clicked.
      /// @param auto_check true if the checked value and the appearance of the control automatically change on the click event; otherwise, false. The default value is true.
      /// @remarks If the checked value is set to false, the radio_button portion of the control must be checked in code in the click event handler. In addition, if the radio_button is part of a radio_button control group, this property ensures that only one of the controls is checked at a given time.
      /// @remarks If the auto_check property is set to false, a group of radio_button controls will not act as a mutually exclusive group and the checked property must be updated in code.
      virtual radio_button& auto_check(bool auto_check);
      
      /// @brief Gets a value indicating whether the control is checked.
      /// @return true if the check box is checked; otherwise, false.
      virtual bool checked() const {return this->checked_;}
      /// @brief Sets a value indicating whether the control is checked.
      /// @param checked true if the check box is checked; otherwise, false.
      virtual radio_button& checked(bool checked);
      
      /// @brief Gets the horizontal and vertical alignment of the check mark on a check_box control.
      /// @return One of the content_alignment values. The default value is middle_left.
      virtual content_alignment check_align() const {return this->check_align_;}
      /// @brief Sets the horizontal and vertical alignment of the check mark on a check_box control.
      /// @param check_align One of the content_alignment values. The default value is middle_left.
      virtual radio_button& check_align(content_alignment check_align);

      /// @brief Gets the default size of the control.
      /// @return Returns a size with a width of 104 and a height of 24.
      drawing::size default_size() const override {return {104, 25};}

      /// @brief Generates a click event for the control, simulating a click by a user.
      void perform_click();

      /// @brief Returns a string that represents the progress_bar control.
      /// @return A string that represents the current progress_bar.
      /// @remarks The return string includes the type and the values for the minimum, maximum, and value properties.
      std::string to_string() const override {return strings::format("{}, checked: {}", strings::full_class_name(*this), this->checked_);}

      /// @brief Occurs when the appearance property value changes.
      event<radio_button, event_handler<control&>> appearance_changed;

      /// @brief Occurs when the value of the checked property changes.
      event<radio_button, event_handler<control&>> checked_changed;

    protected:
      /// @brief Gets the required creation parameters when the control handle is created.
      /// @return A create_params that contains the required creation parameters when the handle to the control is created.
      forms::create_params create_params() const override;
      
      /// @brief Measure this control.
      /// @return The drawing::size size of this control.
      /// @remarks This method is used when auto_size is true.
      drawing::size measure_control() const override;

      /// @brief Raises the appearance_changed event.
      /// @param e An EventArgs that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_appearance_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Note to Inhearitors
      /// When overriding on_appearance_changed(const event_args&) in a derived class, be sure to call the base class' on_appearance_changed(const event_args&) method so that registered delegates receive the event.
      virtual void on_appearance_changed(const event_args& e) {this->appearance_changed(*this, e);}
      
      /// @brief Raises the checked_changed event.
      /// @param e An EventArgs that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_checked_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Note to Inhearitors
      /// When overriding on_checked_changed(const event_args&) in a derived class, be sure to call the base class' on_checked_changed(const event_args&) method so that registered delegates receive the event.
      virtual void on_checked_changed(const event_args& e) {this->checked_changed(*this, e);}
      
      /// @brief Overrides the on_handle_created(const event_args&) method.
      /// @param e An event_args that contains the event data.
      void on_handle_created(const event_args& e) override;
      
      /// @cond
      void wnd_proc(message& message) override;
      void wm_mouse_double_click(message& message);
      void wm_mouse_up(message& message);

      forms::appearance appearance_ = forms::appearance::normal;
      bool auto_check_ = true;
      bool checked_ = false;
      content_alignment check_align_ = content_alignment::middle_left;
      /// @endcond
    };
  }
}
