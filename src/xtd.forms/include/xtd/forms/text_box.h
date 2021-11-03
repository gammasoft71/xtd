/// @file
/// @brief Contains xtd::forms::text_box control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "border_style.h"
#include "character_casing.h"
#include "text_box_base.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows text box.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of text box control.
    /// @include text_box.cpp
    class forms_export_ text_box : public text_box_base {
    public:
      /// @brief initializes a new instance of the text_box class.
      text_box();

      /// @brief Gets a value indicating whether pressing ENTER in a multiline text_box control creates a new line of text in the control or activates the default button for the form.
      /// @return true if the ENTER key creates a new line of text in a multiline version of the control; false if the ENTER key activates the default button for the form. The default is false.
      /// @remarks If the value of this property is false, the user must press CTRL+ENTER to create a new line in a multiline text_box control. If there is no default button for the form, the ENTER key will always create a new line of text in the control, regardless of the value of this property.
      virtual bool accepts_return() const {return accepts_return_;}
      /// @brief Sets a value indicating whether pressing ENTER in a multiline text_box control creates a new line of text in the control or activates the default button for the form.
      /// @param value true if the ENTER key creates a new line of text in a multiline version of the control; false if the ENTER key activates the default button for the form. The default is false.
      /// @return Current text_box instance.
      /// @remarks If the value of this property is false, the user must press CTRL+ENTER to create a new line in a multiline text_box control. If there is no default button for the form, the ENTER key will always create a new line of text in the control, regardless of the value of this property.
      virtual text_box& accepts_return(bool value) {
        if (accepts_return_ != value) {
          accepts_return_ = value;
          recreate_handle();
          on_accepts_return_changed(event_args::empty);
        }
        return *this;
      }
      
      /// @brief Gets whether the text_box control modifies the case of characters as they are typed.
      /// @return One of the xtd::forms::character_casing enumeration values that specifies whether the text_box control modifies the case of characters. The default is xtd::forms::character_casing::normal.
      /// @remarks You can use the character_casing property to change the case of characters as required by your application. For example, you could change the case of all characters entered in a text_box control used for password entry to uppercase or lowercase to enforce a policy for passwords.
      virtual xtd::forms::character_casing character_casing() const {return character_casing_;}
      /// @brief Sets whether the text_box control modifies the case of characters as they are typed.
      /// @param value One of the xtd::forms::character_casing enumeration values that specifies whether the text_box control modifies the case of characters. The default is xtd::forms::character_casing::normal.
      /// @return Current text_box instance.
      /// @remarks You can use the character_casing property to change the case of characters as required by your application. For example, you could change the case of all characters entered in a text_box control used for password entry to uppercase or lowercase to enforce a policy for passwords.
      virtual text_box& character_casing(xtd::forms::character_casing value);

      drawing::color default_back_color() const override {return xtd::forms::theme_colors::current_theme().text_box();}
      
      drawing::color default_fore_color() const override {return xtd::forms::theme_colors::current_theme().text_box_text();}
      
      drawing::size default_size() const override {return {100, 21};}

      /// @brief Gets the character used to mask characters of a password in a single-line TextBox control.
      /// @return The character used to mask characters entered in a single-line text_box control. Set the value of this property to '0' (U+0000) if you do not want the control to mask characters as they are typed. The default value is '0' (U+0000).
      /// @remarks The use_system_password_char property has precedence over the password_char property. Whenever the use_system_password_char is set to true, the default system password character is used and any character set by password_char is ignored.
      /// @remarks When the password_char property is set, cut and copy actions in the control using the keyboard cannot be performed.
      virtual char32_t password_char() const {return password_char_;}
      /// @brief Sets the character used to mask characters of a password in a single-line TextBox control.
      /// @param value The character used to mask characters entered in a single-line text_box control. Set the value of this property to '0' (U+0000) if you do not want the control to mask characters as they are typed. The default value is '0' (U+0000).
      /// @return Current text_box instance.
      /// @remarks The use_system_password_char property has precedence over the password_char property. Whenever the use_system_password_char is set to true, the default system password character is used and any character set by password_char is ignored.
      /// @remarks When the password_char property is set, cut and copy actions in the control using the keyboard cannot be performed.
      virtual text_box& password_char(char32_t value);
      
      using text_box_base::selection_length;
      /// @brief Gets the number of characters selected in the text box.
      /// @return The number of characters selected in the text box.
      /// @remarks You can use this property to determine if any characters are currently selected in the text box control before performing operations on the selected text. When the value of the selection_length property is set to a value that is larger than the number of characters within the text of the control, the value of the selection_length property is set to the entire length of text within the control minus the value of the selection_start property (if any value is specified for the selection_start property).
      size_t selection_length() const override;

      using text_box_base::selection_start;
      /// @brief Gets o the starting point of text selected in the text box.
      /// @return The starting position of text selected in the text box.
      /// @remarks If no text is selected in the control, this property indicates the insertion point, or caret, for new text. If you set this property to a location beyond the length of the text in the control, the selection start position will be placed after the last character. When text is selected in the text box control, changing this property might decrease the value of the SelectionLength property. If the remaining text in the control after the position indicated by the selection_start property is less than the value of the selection_length property, the value of the selection_length property is automatically decreased. The value of the selection_start property never causes an increase in the selection_length property.
      size_t selection_start() const override;
      
      const xtd::ustring& text() const override;
      control& text(const xtd::ustring& text) override;
      
      /// @brief Gets a value indicating whether the text in the TextBox control should appear as the default password character.
      /// @return true if the text in the TextBox control should appear as the default password character; otherwise, false.
      /// @remarks The use_system_password_char property has precedence over the password_char property. Whenever the use_system_password_char is set to true, the default system password character is used and any character set by password_char is ignored.
      virtual bool use_system_password_char() const {return use_system_password_char_;}
      /// @brief Sets a value indicating whether the text in the TextBox control should appear as the default password character.
      /// @param value true if the text in the TextBox control should appear as the default password character; otherwise, false.
      /// @return Current text_box instance.
      /// @remarks The use_system_password_char property has precedence over the password_char property. Whenever the use_system_password_char is set to true, the default system password character is used and any character set by password_char is ignored.
      virtual text_box& use_system_password_char(bool value);
      
      /// @brief Occurs when the value of the accepts_return property has changed.
      /// @ingroup events
      event<text_box, event_handler> accepts_return_changed;

      void append_text(const xtd::ustring& value) override;
      
      void select(size_t start, size_t length) override;

    protected:
      forms::create_params create_params() const override;
      
      drawing::size measure_control() const override;
      
      /// @brief Raises the text_box::accepts_return_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_accepts_return_changed(const event_args& e) {if (can_raise_events()) accepts_return_changed(*this, e);}

      void on_handle_created(const event_args& e) override;
      void on_paint(paint_event_args& e) override;
      void on_text_changed(const event_args& e) override;
      
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;

      /// @cond
      void wm_key_char(message& message);
      void wm_set_text(message& message);

      bool accepts_return_ = false;
      xtd::forms::character_casing character_casing_ = xtd::forms::character_casing::normal;
      char32_t password_char_ = 0;
      bool use_system_password_char_ = false;
      /// @endcond
    };
  }
}
