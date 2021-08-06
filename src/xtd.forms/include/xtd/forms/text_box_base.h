/// @file
/// @brief Contains xtd::forms::text_box_base control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include <xtd/bit_converter.h>
#include <xtd/argument_out_of_range_exception.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class text_box_base : public control {
    public:
      /// @brief Gets a value indicating whether pressing the TAB key in a multiline text box control types a TAB character in the control instead of moving the focus to the next control in the tab order.
      /// @return true if users can enter tabs in a multiline text box using the TAB key; false if pressing the TAB key moves the focus. The default is false.
      virtual bool accepts_tab() const {return accepts_tab_;}
      /// @brief Sets a value indicating whether pressing the TAB key in a multiline text box control types a TAB character in the control instead of moving the focus to the next control in the tab order.
      /// @param value true if users can enter tabs in a multiline text box using the TAB key; false if pressing the TAB key moves the focus. The default is false.
      /// @return Current text_box_base instance.
      virtual text_box_base& accepts_tab(bool value) {
        if (accepts_tab_ != value) {
          accepts_tab_ = value;
          recreate_handle();
          on_accepts_tab_changed(event_args::empty);
        }
        return *this;
      }
      
      /// @brief Gets the border type of the text box control.
      /// @return A xtd::forms::border_style that represents the border type of the text box control. The default is fixed_single.
      virtual forms::border_style border_style() const {return border_style_;}
      /// @brief Sets the border type of the text box control.
      /// @param border_style A xtd::forms::border_style that represents the border type of the text box control. The default is fixed_single.
      /// @return Current text_box_base instance.
      virtual text_box_base& border_style(forms::border_style border_style) {
        if (border_style_ != border_style) {
          border_style_ = border_style;
          recreate_handle();
          on_border_style_changed(event_args::empty);
        }
        return *this;
      }


      forms::cursor default_cursor() const override {return forms::cursors::ibeam();}

      /// @brief Gets the lines of text in a text box control.
      /// @return An array of strings that contains the text in a text box control.
      /// @remarks Each element in the array becomes a line of text in the text box control. If the multiline property of the text box control is set to true and a newline character appears in the text, the text following the newline character is added to a new element in the array and displayed on a separate line.
      std::vector<xtd::ustring> lines() const {
        return text().split({'\n'});
      }
      /// @brief Sets the lines of text in a text box control.
      /// @param lines An array of strings that contains the text in a text box control.
      /// @return Current text_box_base instance.
      /// @remarks Each element in the array becomes a line of text in the text box control. If the multiline property of the text box control is set to true and a newline character appears in the text, the text following the newline character is added to a new element in the array and displayed on a separate line.
      text_box_base& lines(const std::vector<xtd::ustring>& lines) {
        text(xtd::ustring::join("\n", lines));
        return *this;
      }
      
      /// @brief Gets a value indicating whether this is a multiline text box control.
      /// @return true if the control is a multiline text box control; otherwise, false. The default is false.
      /// @remarks A multiline text box allows you to display more than one line of text in the control. If the word_wrap property is set to true, text entered into the multiline text box is wrapped to the next line in the control. If the word_wrap property is set to false, text entered into the multiline text box control will be displayed on the same line until a newline character is entered.
      virtual bool multiline() const {return multiline_;}
      /// @brief Sets a value indicating whether this is a multiline text box control.
      /// @param value true if the control is a multiline text box control; otherwise, false. The default is false.
      /// @return Current text_box_base instance.
      /// @remarks A multiline text box allows you to display more than one line of text in the control. If the word_wrap property is set to true, text entered into the multiline text box is wrapped to the next line in the control. If the word_wrap property is set to false, text entered into the multiline text box control will be displayed on the same line until a newline character is entered.
      virtual text_box_base& multiline(bool value) {
        if (multiline_ != value) {
          multiline_ = value;
          recreate_handle();
          on_multiline_changed(event_args::empty);
        }
        return *this;
      }
      
      /// @brief Gets a value indicating whether text in the text box is read-only.
      /// @return true if the text box is read-only; otherwise, false. The default is false.
      /// @remarks When this property is set to true, the contents of the control cannot be changed by the user at runtime. With this property set to true, you can still set the value of the Text property in code. You can use this feature instead of disabling the control with the Enabled property to allow the contents to be copied and ToolTips to be shown.
      virtual bool read_only() const {return read_only_;}
      /// @brief Sets a value indicating whether text in the text box is read-only.
      /// @param value true if the text box is read-only; otherwise, false. The default is false.
      /// @return Current text_box_base instance.
      /// @remarks When this property is set to true, the contents of the control cannot be changed by the user at runtime. With this property set to true, you can still set the value of the Text property in code. You can use this feature instead of disabling the control with the Enabled property to allow the contents to be copied and ToolTips to be shown.
      virtual text_box_base& read_only(bool value) {
        if (read_only_ != value) {
          read_only_ = value;
          recreate_handle();
          on_read_only_changed(event_args::empty);
        }
        return *this;
      }

      /// @brief Gets the number of characters selected in the text box.
      /// @return The number of characters selected in the text box.
      /// @remarks You can use this property to determine if any characters are currently selected in the text box control before performing operations on the selected text. When the value of the selection_length property is set to a value that is larger than the number of characters within the text of the control, the value of the selection_length property is set to the entire length of text within the control minus the value of the selection_start property (if any value is specified for the selection_start property).
      virtual size_t selection_length() const {return selection_length_;}
      /// @brief Sets the number of characters selected in the text box.
      /// @param value The number of characters selected in the text box.
      /// @return Current text_box_base instance.
      /// @remarks You can use this property to determine if any characters are currently selected in the text box control before performing operations on the selected text. When the value of the selection_length property is set to a value that is larger than the number of characters within the text of the control, the value of the selection_length property is set to the entire length of text within the control minus the value of the selection_start property (if any value is specified for the selection_start property).
      virtual text_box_base& selection_length(size_t value) {
        select(selection_start_, value);
        return *this;
      }
      
      /// @brief Gets o the starting point of text selected in the text box.
      /// @return The starting position of text selected in the text box.
      /// @remarks If no text is selected in the control, this property indicates the insertion point, or caret, for new text. If you set this property to a location beyond the length of the text in the control, the selection start position will be placed after the last character. When text is selected in the text box control, changing this property might decrease the value of the SelectionLength property. If the remaining text in the control after the position indicated by the selection_start property is less than the value of the selection_length property, the value of the selection_length property is automatically decreased. The value of the selection_start property never causes an increase in the selection_length property.
      virtual size_t selection_start() const {return selection_start_;}
      /// @brief Gets o the starting point of text selected in the text box.
      /// @param value The starting position of text selected in the text box.
      /// @return Current text_box_base instance.
      /// @remarks If no text is selected in the control, this property indicates the insertion point, or caret, for new text. If you set this property to a location beyond the length of the text in the control, the selection start position will be placed after the last character. When text is selected in the text box control, changing this property might decrease the value of the SelectionLength property. If the remaining text in the control after the position indicated by the selection_start property is less than the value of the selection_length property, the value of the selection_length property is automatically decreased. The value of the selection_start property never causes an increase in the selection_length property.
      virtual text_box_base& selection_start(size_t value) {
        select(value, selection_length_);
        return *this;
      }
      
      /// @brief Indicates whether a multiline text box control automatically wraps words to the beginning of the next line when necessary.
      /// @return true if the multiline text box control wraps words; false if the text box control automatically scrolls horizontally when the user types past the right edge of the control. The default is true.
      virtual bool word_wrap() const {return word_wrap_;}
      /// @brief Indicates whether a multiline text box control automatically wraps words to the beginning of the next line when necessary.
      /// @param value true if the multiline text box control wraps words; false if the text box control automatically scrolls horizontally when the user types past the right edge of the control. The default is true.
      /// @return Current text_box_base instance.
      virtual text_box_base& word_wrap(bool value) {
        if (word_wrap_ != value) {
          word_wrap_ = value;
          recreate_handle();
        }
        return *this;
      }

      /// @brief Appends text to the current text of a text box.
      /// @param value The text to append to the current contents of the text box.
      virtual void append_text(const xtd::ustring& value) {
        suspend_layout();
        text(text() + value);
        select(text().size(), 0);
        resume_layout();
      }
      
      /// @brief Clears all text from the text box control.
      /// @remarks You can use this method to clear the contents of the control instead of assigning the text property an empty string.
      void clear() {
        text("");
      }
      
      /// @brief Selects a range of text in the text box.
      /// @param start The position of the first character in the current text selection within the text box.
      /// @param length The number of characters to select.
      /// @exception argument_out_of_range_exception The value of the start parameter is less than zero.
      virtual void select(size_t start, size_t length) {
        if (selection_start_ != start || length != selection_length_) {
          if (start > text().size()) throw argument_out_of_range_exception("start greater than text size"_t, current_stack_frame_);
          if (start + length > text().size()) throw argument_out_of_range_exception("start + lenght greater than text size"_t, current_stack_frame_);
          selection_start_ = start;
          selection_length_ = length;
        }
      }
      
      /// @brief Selects all text in the text box.
      ///@remarks This method enables you to select all text within the control. You can use this method in conjunction with the cut method, which requires text to be selected in the control, to cut the entire contents of the control and paste them into the clipboard.
      void select_all() {
        select(0, text().size());
      }
      
      /// @brief Occurs when the value of the accepts_tab property has changed.
      /// @ingroup events
      event<text_box_base, event_handler> accepts_tab_changed;
      
      /// @brief Occurs when the value of the accepts_tab border_style has changed.
      /// @ingroup events
      event<text_box_base, event_handler> border_style_changed;
      
      /// @brief Occurs when the value of the accepts_tab border_style has changed.
      /// @ingroup events
      event<text_box_base, event_handler> multiline_changed;
      
      /// @brief Occurs when the value of the read_only property has changed.
      /// @ingroup events
      event<text_box_base, event_handler> read_only_changed;

    protected:
      /// @brief initializes a new instance of the text_box_base class.
      text_box_base() = default;

      /// @brief Raises the text_box_base::accepts_tab_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_accepts_tab_changed(const event_args& e) {
        if (can_raise_events()) accepts_tab_changed(*this, e);
      }
      
      /// @brief Raises the text_box_base::border_style_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_border_style_changed(const event_args& e) {
        if (can_raise_events()) border_style_changed(*this, e);
      }
      
      /// @brief Raises the text_box_base::text_box_base::multiline_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_multiline_changed(const event_args& e) {
        if (can_raise_events()) multiline_changed(*this, e);
      }

      /// @brief Raises the text_box_base::read_only_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_read_only_changed(const event_args& e) {
        if (can_raise_events()) read_only_changed(*this, e);
      }

      /// @cond
      bool accepts_tab_ = false;
      xtd::forms::border_style border_style_ = xtd::forms::border_style::fixed_single;
      bool multiline_ = false;
      bool read_only_ = false;
      bool word_wrap_ = true;
      mutable size_t selection_start_ = 0;
      mutable size_t selection_length_ = 0;
      /// @endcond
    };
  }
}
