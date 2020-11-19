#pragma once
#include "input_dialog.h"
#include "input_box_style.h"
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class input_box final static_ {
    public:
      static xtd::forms::dialog_result show(std::string& value) {return show_input_box(value);}
      static xtd::forms::dialog_result show(std::string& value, const std::string& text) {return show_input_box(value, nullptr, text);}
      static xtd::forms::dialog_result show(std::string& value, const std::string& text, const std::string& caption) {return show_input_box(value, nullptr, text, caption);}
      static xtd::forms::dialog_result show(std::string& value, const std::string& text, const std::string& caption, xtd::forms::input_box_style style) {return show_input_box(value, nullptr, text, caption, style);}
      static xtd::forms::dialog_result show(std::string& value, const std::string& text, const std::string& caption, xtd::forms::input_box_style style, xtd::forms::character_casing casing) {return show_input_box(value, nullptr, text, caption, style, casing);}
      
      static xtd::forms::dialog_result show(std::string& value, const xtd::forms::iwin32_window& owner) {return show_input_box(value, &owner);}
      static xtd::forms::dialog_result show(std::string& value, const xtd::forms::iwin32_window& owner, const std::string& text) {return show_input_box(value, &owner, text);}
      static xtd::forms::dialog_result show(std::string& value, const xtd::forms::iwin32_window& owner, const std::string& text, const std::string& caption) {return show_input_box(value, &owner, text, caption);}
      static xtd::forms::dialog_result show(std::string& value, const xtd::forms::iwin32_window& owner, const std::string& text, const std::string& caption, xtd::forms::input_box_style style) {return show_input_box(value, &owner, text, caption, style);}
      static xtd::forms::dialog_result show(std::string& value, const xtd::forms::iwin32_window& owner, const std::string& text, const std::string& caption, xtd::forms::input_box_style style, xtd::forms::character_casing casing) {return show_input_box(value, &owner, text, caption, style, casing);}
      
    private:
      static xtd::forms::dialog_result show_input_box(std::string& value, const xtd::forms::iwin32_window* owner = nullptr, const std::string& text = "", const std::string& caption = "", xtd::forms::input_box_style style = xtd::forms::input_box_style::normal, xtd::forms::character_casing casing = xtd::forms::character_casing::normal) {
        xtd::forms::input_dialog dialog;
        dialog.value(value);
        dialog.message(text);
        dialog.text(caption);
        dialog.character_casing(casing);
        dialog.multiline(style == xtd::forms::input_box_style::multiline);
        dialog.use_system_password_char(style == xtd::forms::input_box_style::password);
        xtd::forms::dialog_result result = owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
        if (result == xtd::forms::dialog_result::ok) value = dialog.value();
        return result;
      }
    };
  }
}
