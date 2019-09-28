#pragma once
#include "appearance.hpp"
#include "button_base.hpp"
#include "check_state.hpp"
#include "content_alignment.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows check_box.
    /// @remarks Use a check_box to give the user an option, such as true/false or yes/no. The check_box control can display an image or text or both.
    /// @remarks check_box and radio_button controls have a similar function: they allow the user to choose from a list of options. check_box controls let the user pick a combination of options. In contrast, radio_button controls allow a user to choose from mutually exclusive options.
    /// @remarks The appearance property determines whether the check_box appears as a typical check_box or as a button.
    /// @remarks The three_state property determines whether the control supports two or three states. Use the checked property to get or set the value of a two-state check_box control and use the check_state property to get or set the value of a three-state check_box control.
    /// @note If the three_state property is set to true, the checked property will return true for either a checked or indeterminate state.
    /// @remarks The flat_style property determines the style and appearance of the control. If the flat_style property is set to flat_style::system, the user's operating system determines the appearance of the control.
    /// @note When the flat_style property is set to flat_style::system, the check_align property is ignored and the control is displayed using the content_alignment::middle_left or content_alignment::middle_right alignment. If the check_align property is set to one of the right alignments, the control is displayed using the content_alignment::middle_right alignment; otherwise, it is displayed using the content_alignment::middle_left alignment.
    /// @remarks The following describes an indeterminate state: You have a check_box that determines if the selected text in a rich_text_box is bold. When you select text you can click the check_box to bold the selection. Likewise, when you select some text, the check_box displays whether the selected text is bold. If your selected text contains text that is bold and normal, the check_box will have an indeterminate state.
    /// @par Example
    /// The following code example demonstrate the use of check_box control.
    /// @include check_box.cpp
    class check_box : public button_base {
    public:
      /// @brief Initializes a new instance of the CheckBox class.
      /// @remarks By default, when a new check_box is instantiated, auto_check is set to true, checked is set to false, and appearance is set to normal.
      check_box();

      /// @brief Gets the value that determines the appearance of a check_box control.
      /// @return One of the appearance values. The default value is normal.
      /// @remarks If appearance value is set to normal, the check_box has a typical appearance. If the value is set to button, the check_box appears like a toggle button, which can be toggled to an up or down state.
      virtual forms::appearance appearance() const {return this->appearance_;}
      /// @brief Gets the value that determines the appearance of a check_box control.
      /// @param appearance One of the appearance values. The default value is normal.
      /// @remarks If appearance value is set to normal, the check_box has a typical appearance. If the value is set to button, the check_box appears like a toggle button, which can be toggled to an up or down state.
      virtual check_box& appearance(forms::appearance appearance);

      /// @brief Gets a value indicating whether the checked or check_state values and the check_box's appearance are automatically changed when the check_box is clicked.
      /// @return true if the checked value or check_state value and the appearance of the control are automatically changed on the click event; otherwise, false. The default value is true.
      /// @remarks If auto_check is set to false, you will need to add code to update the checked or check_state values in the click event handler.
      virtual bool auto_check() const {return this->auto_check_;}
      /// @brief Sets a value indicating whether the checked or check_state values and the check_box's appearance are automatically changed when the check_box is clicked.
      /// @param auto_check true if the checked value or check_state value and the appearance of the control are automatically changed on the click event; otherwise, false. The default value is true.
      /// @remarks If auto_check is set to false, you will need to add code to update the checked or check_state values in the click event handler.
      virtual check_box& auto_check(bool auto_check);
      
      virtual content_alignment check_align() const {return this->check_align_;}
      virtual check_box& check_align(content_alignment check_align);
      
      virtual bool checked() const {return this->checked_;}
      virtual check_box& checked(bool checked);
      
      virtual forms::check_state check_state() const {return this->check_state_;}
      virtual check_box& check_state(forms::check_state check_state);
      
      drawing::size default_size() const override {return {104, 24};}
      
      virtual bool three_state() const {return this->three_state_;}
      virtual check_box& three_state(bool three_state);
      
      event<check_box, event_handler<control>> appearance_changed;
      
      event<check_box, event_handler<control>> checked_changed;
      
      event<check_box, event_handler<control>> check_state_changed;

    protected:
      forms::create_params create_params() const override;

      drawing::size measure_control() const override;

      virtual void on_appearance_changed(const event_args& e) {this->appearance_changed(*this, e);}
      
      virtual void on_checked_changed(const event_args& e) {this->checked_changed(*this, e);}
      
      virtual void on_check_state_changed(const event_args& e) {this->check_state_changed(*this, e);}

      void on_handle_created(const event_args& e) override;
      
      /// @cond
      void wnd_proc(message& message) override;
      virtual void wm_mouse_double_click(message& message);
      virtual void wm_mouse_up(message& message);

      forms::appearance appearance_ = forms::appearance::normal;
      bool auto_check_ = true;
      bool three_state_ = 0;
      bool checked_ = false;
      content_alignment check_align_ = content_alignment::middle_left;
      forms::check_state check_state_ = forms::check_state::unchecked;
      /// @endcond
    };
  }
}
