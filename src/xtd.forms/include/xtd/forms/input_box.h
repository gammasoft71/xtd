/// @file
/// @brief Contains xtd::forms::input_box control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "input_dialog.h"
#include "input_box_style.h"
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays input box.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrate the use of input_box dialog.
    /// @include input_box.cpp
    /// @par Windows
    /// @image html input_box_w.png
    /// <br>
    /// @image html input_box_wd.png
    /// @par macOS
    /// @image html input_box_m.png
    /// <br>
    /// @image html input_box_md.png
    /// @par Gnome
    /// @image html input_box_g.png
    /// <br>
    /// @image html input_box_gd.png
    class input_box final static_ {
    public:
      /// @brief Displays an input box in front of the specified window. The input box displays a text value.
      /// @param value A xtd::ustring that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::ustring& value, const xtd::forms::iwin32_window& owner) {return show_input_box(value, &owner);}
      /// @brief Displays an input box in front of the specified window. The input box displays a input text value with specifiedd invite message text.
      /// @param value A xtd::ustring that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::ustring that specifies the invite message text to display.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::ustring& value, const xtd::forms::iwin32_window& owner, const xtd::ustring& text) {return show_input_box(value, &owner, text);}
      /// @brief Displays an input box in front of the specified window. The input box displays a input text value with specifiedd invite message text and caption title.
      /// @param value A xtd::ustring that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::ustring that specifies the invite message text to display.
      /// @param caption A xtd::ustring that specifies the caption title of dialog.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::ustring& value, const xtd::forms::iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption) {return show_input_box(value, &owner, text, caption);}
      /// @brief Displays an input box in front of the specified window. The input box displays a input text value with specifiedd invite message text, caption title and input box style.
      /// @param value A xtd::ustring that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::ustring that specifies the invite message text to display.
      /// @param caption A xtd::ustring that specifies the caption title of dialog.
      /// @param style On of xtd::forms::input_box_style values.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::ustring& value, const xtd::forms::iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, xtd::forms::input_box_style style) {return show_input_box(value, &owner, text, caption, style);}
      /// @brief Displays an input box in front of the specified window. The input box displays a input text value with specifiedd invite message text, caption title, input box style and character casing.
      /// @param value A xtd::ustring that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::ustring that specifies the invite message text to display.
      /// @param caption A xtd::ustring that specifies the caption title of dialog.
      /// @param style On of xtd::forms::input_box_style values. The default is xtd::forms::input_box_style::normal
      /// @param casing On of xtd::forms::character_casing values. The default is xtd::forms::character_casing::normal
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::ustring& value, const xtd::forms::iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, xtd::forms::input_box_style style, xtd::forms::character_casing casing) {return show_input_box(value, &owner, text, caption, style, casing);}
      /// @brief Displays an input box in front of the specified window. The input box displays a input text value with specifiedd invite message text, caption title, input box style, character casing and word_wrap.
      /// @param value A xtd::ustring that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::ustring that specifies the invite message text to display.
      /// @param caption A xtd::ustring that specifies the caption title of dialog.
      /// @param style On of xtd::forms::input_box_style values. The default is xtd::forms::input_box_style::normal
      /// @param casing On of xtd::forms::character_casing values. The default is xtd::forms::character_casing::normal
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @param word_wrap true if word_wrap; otherwise false. The default is true.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::ustring& value, const xtd::forms::iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, xtd::forms::input_box_style style, xtd::forms::character_casing casing, bool word_wrap) {return show_input_box(value, &owner, text, caption, style, casing, word_wrap);}

      /// @brief Displays an input box. The input box displays a text value.
      /// @param value A xtd::ustring that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::ustring& value) {return show_input_box(value);}
      /// @brief Displays an input box. The input box displays a input text value with specifiedd invite message text.
      /// @param value A xtd::ustring that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::ustring that specifies the invite message text to display.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::ustring& value, const xtd::ustring& text) {return show_input_box(value, nullptr, text);}
      /// @brief Displays an input box. The input box displays a input text value with specifiedd invite message text and caption title.
      /// @param value A xtd::ustring that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::ustring that specifies the invite message text to display.
      /// @param caption A xtd::ustring that specifies the caption title of dialog.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::ustring& value, const xtd::ustring& text, const xtd::ustring& caption) {return show_input_box(value, nullptr, text, caption);}
      /// @brief Displays an input box. The input box displays a input text value with specifiedd invite message text, caption title and input box style.
      /// @param value A xtd::ustring that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::ustring that specifies the invite message text to display.
      /// @param caption A xtd::ustring that specifies the caption title of dialog.
      /// @param style On of xtd::forms::input_box_style values.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::ustring& value, const xtd::ustring& text, const xtd::ustring& caption, xtd::forms::input_box_style style) {return show_input_box(value, nullptr, text, caption, style);}
      /// @brief Displays an input box. The input box displays a input text value with specifiedd invite message text, caption title, input box style and character casing.
      /// @param value A xtd::ustring that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::ustring that specifies the invite message text to display.
      /// @param caption A xtd::ustring that specifies the caption title of dialog.
      /// @param style On of xtd::forms::input_box_style values. The default is xtd::forms::input_box_style::normal
      /// @param casing On of xtd::forms::character_casing values. The default is xtd::forms::character_casing::normal
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::ustring& value, const xtd::ustring& text, const xtd::ustring& caption, xtd::forms::input_box_style style, xtd::forms::character_casing casing) {return show_input_box(value, nullptr, text, caption, style, casing);}
      /// @brief Displays an input box. The input box displays a input text value with specifiedd invite message text, caption title, input box style, character casing and word_wrap.
      /// @param value A xtd::ustring that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::ustring that specifies the invite message text to display.
      /// @param caption A xtd::ustring that specifies the caption title of dialog.
      /// @param style On of xtd::forms::input_box_style values. The default is xtd::forms::input_box_style::normal
      /// @param casing On of xtd::forms::character_casing values. The default is xtd::forms::character_casing::normal
      /// @param word_wrap true if word_wrap; otherwise false. The default is true.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::ustring& value, const xtd::ustring& text, const xtd::ustring& caption, xtd::forms::input_box_style style, xtd::forms::character_casing casing, bool word_wrap) {return show_input_box(value, nullptr, text, caption, style, casing, word_wrap);}

    private:
      static xtd::forms::dialog_result show_input_box(xtd::ustring& value, const xtd::forms::iwin32_window* owner = nullptr, const xtd::ustring& text = "", const xtd::ustring& caption = "", xtd::forms::input_box_style style = xtd::forms::input_box_style::normal, xtd::forms::character_casing casing = xtd::forms::character_casing::normal, bool word_wrap = true) {
        xtd::forms::input_dialog dialog;
        dialog.value(value);
        dialog.message(text);
        dialog.text(caption);
        dialog.character_casing(casing);
        dialog.multiline(style == xtd::forms::input_box_style::multiline);
        dialog.use_system_password_char(style == xtd::forms::input_box_style::password);
        dialog.word_wrap(word_wrap);
        xtd::forms::dialog_result result = owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
        if (result == xtd::forms::dialog_result::ok) value = dialog.value();
        return result;
      }
    };
  }
}
