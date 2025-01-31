/// @file
/// @brief Contains xtd::forms::text_box control.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "border_style.hpp"
#include "character_casing.hpp"
#include "text_box_base.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows text box.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/text_box>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                               | macOS                                 | Gnome                                 |
    /// | ----- | ------------------------------------- | ------------------------------------- | ------------------------------------- |
    /// | Light |  @image html control_text_box_w.png   |  @image html control_text_box_m.png   |  @image html control_text_box_g.png   |
    /// | Dark  |  @image html control_text_box_wd.png  |  @image html control_text_box_md.png  |  @image html control_text_box_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of text box control.
    /// @include text_box.cpp
    class forms_export_ text_box : public text_box_base {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief initializes a new instance of the text_box class.
      text_box();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicating whether pressing ENTER in a multiline text_box control creates a new line of text in the control or activates the default button for the form.
      /// @return `true` if the ENTER key creates a new line of text in a multiline version of the control; `false` if the ENTER key activates the default button for the form. The default is `false`.
      /// @remarks If the value of this property is `false`, the user must press CTRL+ENTER to create a new line in a multiline text_box control. If there is no default button for the form, the ENTER key will always create a new line of text in the control, regardless of the value of this property.
      virtual bool accepts_return() const noexcept;
      /// @brief Sets a value indicating whether pressing ENTER in a multiline text_box control creates a new line of text in the control or activates the default button for the form.
      /// @param value `true` if the ENTER key creates a new line of text in a multiline version of the control; `false` if the ENTER key activates the default button for the form. The default is `false`.
      /// @return Current text_box instance.
      /// @remarks If the value of this property is `false`, the user must press CTRL+ENTER to create a new line in a multiline text_box control. If there is no default button for the form, the ENTER key will always create a new line of text in the control, regardless of the value of this property.
      virtual text_box& accepts_return(bool value);
      
      /// @brief Gets whether the text_box control modifies the case of characters as they are typed.
      /// @return One of the xtd::forms::character_casing enumeration values that specifies whether the text_box control modifies the case of characters. The default is xtd::forms::character_casing::normal.
      /// @remarks You can use the character_casing property to change the case of characters as required by your application. For example, you could change the case of all characters entered in a text_box control used for password entry to uppercase or lowercase to enforce a policy for passwords.
      virtual xtd::forms::character_casing character_casing() const noexcept;
      /// @brief Sets whether the text_box control modifies the case of characters as they are typed.
      /// @param value One of the xtd::forms::character_casing enumeration values that specifies whether the text_box control modifies the case of characters. The default is xtd::forms::character_casing::normal.
      /// @return Current text_box instance.
      /// @remarks You can use the character_casing property to change the case of characters as required by your application. For example, you could change the case of all characters entered in a text_box control used for password entry to uppercase or lowercase to enforce a policy for passwords.
      virtual text_box& character_casing(xtd::forms::character_casing value);
      
      /// @brief Gets the character used to mask characters of a password in a single-line TextBox control.
      /// @return The character used to mask characters entered in a single-line text_box control. Set the value of this property to '0' (U+0000) if you do not want the control to mask characters as they are typed. The default value is '0' (U+0000).
      /// @remarks The use_system_password_char property has precedence over the password_char property. Whenever the use_system_password_char is set to `true`, the default system password character is used and any character set by password_char is ignored.
      /// @remarks When the password_char property is set, cut and copy actions in the control using the keyboard cannot be performed.
      virtual char32 password_char() const noexcept;
      /// @brief Sets the character used to mask characters of a password in a single-line TextBox control.
      /// @param value The character used to mask characters entered in a single-line text_box control. Set the value of this property to '0' (U+0000) if you do not want the control to mask characters as they are typed. The default value is '0' (U+0000).
      /// @return Current text_box instance.
      /// @remarks The use_system_password_char property has precedence over the password_char property. Whenever the use_system_password_char is set to `true`, the default system password character is used and any character set by password_char is ignored.
      /// @remarks When the password_char property is set, cut and copy actions in the control using the keyboard cannot be performed.
      virtual text_box& password_char(char32 value);
      
      /// @brief Gets the text that is displayed when the control has no text and does not have the focus.
      /// @return The text that is displayed when the control has no text and does not have the focus.
      const xtd::string& placeholder_text() const noexcept;
      /// @brief Sets the text that is displayed when the control has no text and does not have the focus.
      /// @param value The text that is displayed when the control has no text and does not have the focus.
      /// @return Current text_box instance.
      text_box& placeholder_text(const xtd::string& value);
      
      using text_box_base::selection_length;
      /// @brief Gets the number of characters selected in the text box.
      /// @return The number of characters selected in the text box.
      /// @remarks You can use this property to determine if any characters are currently selected in the text box control before performing operations on the selected text. When the value of the selection_length property is set to a value that is larger than the number of characters within the text of the control, the value of the selection_length property is set to the entire length of text within the control minus the value of the selection_start property (if any value is specified for the selection_start property).
      size_t selection_length() const noexcept override;
      
      using text_box_base::selection_start;
      /// @brief Gets o the starting point of text selected in the text box.
      /// @return The starting position of text selected in the text box.
      /// @remarks If no text is selected in the control, this property indicates the insertion point, or caret, for new text. If you set this property to a location beyond the length of the text in the control, the selection start position will be placed after the last character. When text is selected in the text box control, changing this property might decrease the value of the SelectionLength property. If the remaining text in the control after the position indicated by the selection_start property is less than the value of the selection_length property, the value of the selection_length property is automatically decreased. The value of the selection_start property never causes an increase in the selection_length property.
      size_t selection_start() const noexcept override;
      
      const xtd::string& text() const noexcept override;
      control& text(const xtd::string& text) override;
      
      /// @brief Gets a value indicating whether the text in the TextBox control should appear as the default password character.
      /// @return `true` if the text in the TextBox control should appear as the default password character; otherwise, `false`.
      /// @remarks The use_system_password_char property has precedence over the password_char property. Whenever the use_system_password_char is set to `true`, the default system password character is used and any character set by password_char is ignored.
      virtual bool use_system_password_char() const noexcept;
      /// @brief Sets a value indicating whether the text in the TextBox control should appear as the default password character.
      /// @param value `true` if the text in the TextBox control should appear as the default password character; otherwise, `false`.
      /// @return Current text_box instance.
      /// @remarks The use_system_password_char property has precedence over the password_char property. Whenever the use_system_password_char is set to `true`, the default system password character is used and any character set by password_char is ignored.
      virtual text_box& use_system_password_char(bool value);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      void append_text(const xtd::string& value) override;

      void select(size_t start, size_t length) override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::text_box.
      /// @return New xtd::forms::text_box created.
      static text_box create();
      /// @brief A factory to create an xtd::forms::text_box with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::text_box.
      /// @return New xtd::forms::text_box created.
      static text_box create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::text_box with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::text_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::text_box.
      /// @return New xtd::forms::text_box created.
      static text_box create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::text_box with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::text_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::text_box.
      /// @param name The name of the xtd::forms::text_box.
      /// @return New xtd::forms::text_box created.
      static text_box create(const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @brief A factory to create an xtd::forms::text_box with specified text.
      /// @param text A string that represent text of the xtd::forms::text_box.
      /// @return New xtd::forms::text_box created.
      static text_box create(const xtd::string& text);
      /// @brief A factory to create an xtd::forms::text_box with specified text, and location.
      /// @param text A string that represent text of the xtd::forms::text_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::text_box.
      /// @return New xtd::forms::text_box created.
      static text_box create(const xtd::string& text, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::text_box with specified text, location, and size.
      /// @param text A string that represent text of the xtd::forms::text_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::text_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::text_box.
      /// @return New xtd::forms::text_box created.
      static text_box create(const xtd::string& text, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::text_box with specified text, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::text_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::text_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::text_box.
      /// @param name The name of the xtd::forms::text_box.
      /// @return New xtd::forms::text_box created.
      static text_box create(const xtd::string& text, const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @brief A factory to create an xtd::forms::text_box with specified parent,.
      /// @param parent The parent that contains the new created xtd::forms::text_box.
      /// @return New xtd::forms::text_box created.
      static text_box create(const control& parent);
      /// @brief A factory to create an xtd::forms::text_box with specified parent, location.
      /// @param parent The parent that contains the new created xtd::forms::text_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::text_box.
      /// @return New xtd::forms::text_box created.
      static text_box create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::text_box with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::text_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::text_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::text_box.
      /// @return New xtd::forms::text_box created.
      static text_box create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::text_box with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::text_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::text_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::text_box.
      /// @param name The name of the xtd::forms::text_box.
      /// @return New xtd::forms::text_box created.
      static text_box create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @brief A factory to create an xtd::forms::text_box with specified parent, and text.
      /// @param parent The parent that contains the new created xtd::forms::text_box.
      /// @param text A string that represent text of the xtd::forms::text_box.
      /// @return New xtd::forms::text_box created.
      static text_box create(const control& parent, const xtd::string& text);
      /// @brief A factory to create an xtd::forms::text_box with specified parent, text, and location.
      /// @param parent The parent that contains the new created xtd::forms::text_box.
      /// @param text A string that represent text of the xtd::forms::text_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::text_box.
      /// @return New xtd::forms::text_box created.
      static text_box create(const control& parent, const xtd::string& text, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::text_box with specified parent, text, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::text_box.
      /// @param text A string that represent text of the xtd::forms::text_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::text_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::text_box.
      /// @return New xtd::forms::text_box created.
      static text_box create(const control& parent, const xtd::string& text, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::text_box with specified parent, text, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::text_box.
      /// @param text A string that represent text of the xtd::forms::text_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::text_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::text_box.
      /// @param name The name of the xtd::forms::text_box.
      /// @return New xtd::forms::text_box created.
      static text_box create(const control& parent, const xtd::string& text, const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the value of the accepts_return property has changed.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<text_box, event_handler> accepts_return_changed;
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      drawing::color default_back_color() const noexcept override;
      drawing::color default_fore_color() const noexcept override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Creates a new object that is a copy of the current instance.
      /// @return A new object that is a copy of this instance.
      /// @par Notes to Implementers
      /// All controls must be override the clone method.
      xtd::uptr<xtd::object> clone() const override;
      
      drawing::size measure_control() const noexcept override;
      
      /// @brief Raises the text_box::accepts_return_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_accepts_return_changed(const event_args& e);
      
      void on_handle_created(const event_args& e) override;
      void on_text_changed(const event_args& e) override;
      
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;
      /// @}
      
      /// @cond
      void wm_key_char(message& message);
      void wm_set_text(message& message);
      /// @endcond
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
