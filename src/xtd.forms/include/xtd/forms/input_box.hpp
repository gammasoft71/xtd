/// @file
/// @brief Contains xtd::forms::input_box control.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.hpp"
#include "character_casing.hpp"
#include "dialog_result.hpp"
#include "input_box_style.hpp"
#include "iwin32_window.hpp"
#include <xtd/static>
#include <xtd/string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays input box.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/input_box>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                  | macOS                                    | Gnome                                    |
    /// | ----- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
    /// | Light |  @image html dialog_input_dialog_w.png   |  @image html dialog_input_dialog_m.png   |  @image html dialog_input_dialog_g.png   |
    /// | Dark  |  @image html dialog_input_dialog_wd.png  |  @image html dialog_input_dialog_md.png  |  @image html dialog_input_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of input_box dialog.
    /// @include input_box.cpp
    class forms_export_ input_box final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Displays an input box in front of the specified window. The input box displays a text value.
      /// @param value A xtd::string that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::string& value, const xtd::forms::iwin32_window& owner);
      /// @brief Displays an input box in front of the specified window. The input box displays a input text value with specified invite message text.
      /// @param value A xtd::string that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::string that specifies the invite message text to display.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::string& value, const xtd::forms::iwin32_window& owner, const xtd::string& text);
      /// @brief Displays an input box in front of the specified window. The input box displays a input text value with specified invite message text and caption title.
      /// @param value A xtd::string that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::string that specifies the invite message text to display.
      /// @param caption A xtd::string that specifies the caption title of dialog.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::string& value, const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption);
      /// @brief Displays an input box in front of the specified window. The input box displays a input text value with specified invite message text, caption title and input box style.
      /// @param value A xtd::string that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::string that specifies the invite message text to display.
      /// @param caption A xtd::string that specifies the caption title of dialog.
      /// @param style On of xtd::forms::input_box_style values.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::string& value, const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, xtd::forms::input_box_style style);
      /// @brief Displays an input box in front of the specified window. The input box displays a input text value with specified invite message text, caption title, input box style and character casing.
      /// @param value A xtd::string that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::string that specifies the invite message text to display.
      /// @param caption A xtd::string that specifies the caption title of dialog.
      /// @param style On of xtd::forms::input_box_style values. The default is xtd::forms::input_box_style::normal
      /// @param casing On of xtd::forms::character_casing values. The default is xtd::forms::character_casing::normal
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::string& value, const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, xtd::forms::input_box_style style, xtd::forms::character_casing casing);
      /// @brief Displays an input box in front of the specified window. The input box displays a input text value with specified invite message text, caption title, input box style, character casing and word_wrap.
      /// @param value A xtd::string that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::string that specifies the invite message text to display.
      /// @param caption A xtd::string that specifies the caption title of dialog.
      /// @param style On of xtd::forms::input_box_style values. The default is xtd::forms::input_box_style::normal
      /// @param casing On of xtd::forms::character_casing values. The default is xtd::forms::character_casing::normal
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @param word_wrap `true` if word_wrap; otherwise `false`. The default is `true`.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::string& value, const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, xtd::forms::input_box_style style, xtd::forms::character_casing casing, bool word_wrap);
      
      /// @brief Displays an input box. The input box displays a text value.
      /// @param value A xtd::string that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::string& value);
      /// @brief Displays an input box. The input box displays a input text value with specified invite message text.
      /// @param value A xtd::string that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::string that specifies the invite message text to display.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::string& value, const xtd::string& text);
      /// @brief Displays an input box. The input box displays a input text value with specified invite message text and caption title.
      /// @param value A xtd::string that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::string that specifies the invite message text to display.
      /// @param caption A xtd::string that specifies the caption title of dialog.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::string& value, const xtd::string& text, const xtd::string& caption);
      /// @brief Displays an input box. The input box displays a input text value with specified invite message text, caption title and input box style.
      /// @param value A xtd::string that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::string that specifies the invite message text to display.
      /// @param caption A xtd::string that specifies the caption title of dialog.
      /// @param style On of xtd::forms::input_box_style values.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::string& value, const xtd::string& text, const xtd::string& caption, xtd::forms::input_box_style style);
      /// @brief Displays an input box. The input box displays a input text value with specified invite message text, caption title, input box style and character casing.
      /// @param value A xtd::string that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::string that specifies the invite message text to display.
      /// @param caption A xtd::string that specifies the caption title of dialog.
      /// @param style On of xtd::forms::input_box_style values. The default is xtd::forms::input_box_style::normal
      /// @param casing On of xtd::forms::character_casing values. The default is xtd::forms::character_casing::normal
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::string& value, const xtd::string& text, const xtd::string& caption, xtd::forms::input_box_style style, xtd::forms::character_casing casing);
      /// @brief Displays an input box. The input box displays a input text value with specified invite message text, caption title, input box style, character casing and word_wrap.
      /// @param value A xtd::string that specifies the text to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param text A xtd::string that specifies the invite message text to display.
      /// @param caption A xtd::string that specifies the caption title of dialog.
      /// @param style On of xtd::forms::input_box_style values. The default is xtd::forms::input_box_style::normal
      /// @param casing On of xtd::forms::character_casing values. The default is xtd::forms::character_casing::normal
      /// @param word_wrap `true` if word_wrap; otherwise `false`. The default is `true`.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the value parameter contains the new chosen value.
      static xtd::forms::dialog_result show(xtd::string& value, const xtd::string& text, const xtd::string& caption, xtd::forms::input_box_style style, xtd::forms::character_casing casing, bool word_wrap);
      /// @}
      
    private:
      static xtd::forms::dialog_result show_input_box(xtd::string& value, const xtd::forms::iwin32_window* owner = nullptr, const xtd::string& text = xtd::string::empty_string, const xtd::string& caption = xtd::string::empty_string, xtd::forms::input_box_style style = xtd::forms::input_box_style::normal, xtd::forms::character_casing casing = xtd::forms::character_casing::normal, bool word_wrap = true);
    };
  }
}
