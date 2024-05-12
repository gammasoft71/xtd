/// @file
/// @brief Contains xtd::forms::replace_box control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "replace_dialog.h"
#include <xtd/static>
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays a replace dialog. This class cannot be inherited.
    /// @par Header
    /// @code #include <xtd/forms/replace_box> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                    | macOS                                      | Gnome                                      |
    /// | ----- | ------------------------------------------ | ------------------------------------------ | ------------------------------------------ |
    /// | Light |  @image html dialog_replace_dialog_w.png   |  @image html dialog_replace_dialog_m.png   |  @image html dialog_replace_dialog_g.png   |
    /// | Dark  |  @image html dialog_replace_dialog_wd.png  |  @image html dialog_replace_dialog_md.png  |  @image html dialog_replace_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of xtd::forms::replace_box dialog.
    /// @include replace_box.cpp
    class forms_export_ replace_box final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Displays a replace dialog box.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the replace dialog box.
      /// @param find_next The callback called when the user click the find button.
      /// @param replace The callback called when the user click the replace button.
      /// @param replace_all The callback called when the user click the replace all button.
      template<typename find_next_callback_t, typename replace_callback_t, typename replace_all_callback_t>
      static void show(const iwin32_window& owner, find_next_callback_t find_next, replace_callback_t replace, replace_all_callback_t replace_all) {show_replace_box(owner, xtd::forms::find_event_handler(find_next), xtd::forms::replace_event_handler(replace), xtd::forms::replace_event_handler(replace_all));}
      
      /// @brief Displays a replace dialog box.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the replace dialog box.
      /// @param find_string The string to find.
      /// @param find_next The callback called when the user click the find button.
      /// @param replace The callback called when the user click the replace button.
      /// @param replace_all The callback called when the user click the replace all button.
      template<typename find_next_callback_t, typename replace_callback_t, typename replace_all_callback_t>
      static void show(const iwin32_window& owner, const xtd::ustring& find_string, find_next_callback_t find_next, replace_callback_t replace, replace_all_callback_t replace_all) {show_replace_box(owner, xtd::forms::find_event_handler(find_next), xtd::forms::replace_event_handler(replace), xtd::forms::replace_event_handler(replace_all), find_string);}
      
      /// @brief Displays a replace dialog box.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the replace dialog box.
      /// @param find_string The string to find.
      /// @param replace_string The replaced string.
      /// @param find_next The callback called when the user click the find button.
      /// @param replace The callback called when the user click the replace button.
      /// @param replace_all The callback called when the user click the replace all button.
      template<typename find_next_callback_t, typename replace_callback_t, typename replace_all_callback_t>
      static void show(const iwin32_window& owner, const xtd::ustring& find_string, const xtd::ustring& replace_string, find_next_callback_t find_next, replace_callback_t replace, replace_all_callback_t replace_all) {show_replace_box(owner, xtd::forms::find_event_handler(find_next), xtd::forms::replace_event_handler(replace), xtd::forms::replace_event_handler(replace_all), find_string, replace_string);}
      
      /// @brief Displays a replace dialog box.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the replace dialog box.
      /// @param find_string The string to find.
      /// @param replace_string The replaced string.
      /// @param title The find dialog title.
      /// @param find_next The callback called when the user click the find button.
      /// @param replace The callback called when the user click the replace button.
      /// @param replace_all The callback called when the user click the replace all button.
      template<typename find_next_callback_t, typename replace_callback_t, typename replace_all_callback_t>
      static void show(const iwin32_window& owner, const xtd::ustring& find_string, const xtd::ustring& replace_string, const xtd::ustring& title, find_next_callback_t find_next, replace_callback_t replace, replace_all_callback_t replace_all) {show_replace_box(owner, xtd::forms::find_event_handler(find_next), xtd::forms::replace_event_handler(replace), xtd::forms::replace_event_handler(replace_all), find_string, replace_string, title);}
      
      /// @brief Displays a replace dialog box.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the replace dialog box.
      /// @param find_string The string to find.
      /// @param replace_string The replaced string.
      /// @param title The find dialog title.
      /// @param match_case true if match case option selected; otherwise false.
      /// @param find_next The callback called when the user click the find button.
      /// @param replace The callback called when the user click the replace button.
      /// @param replace_all The callback called when the user click the replace all button.
      template<typename find_next_callback_t, typename replace_callback_t, typename replace_all_callback_t>
      static void show(const iwin32_window& owner, const xtd::ustring& find_string, const xtd::ustring& replace_string, const xtd::ustring& title, bool match_case, find_next_callback_t find_next, replace_callback_t replace, replace_all_callback_t replace_all) {show_replace_box(owner, xtd::forms::find_event_handler(find_next), xtd::forms::replace_event_handler(replace), xtd::forms::replace_event_handler(replace_all), find_string, replace_string, title, match_case);}
      
      /// @brief Displays a replace dialog box.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the replace dialog box.
      /// @param find_string The string to find.
      /// @param replace_string The replaced string.
      /// @param title The find dialog title.
      /// @param match_case true if match case option selected; otherwise false.
      /// @param whole_word true if whole word option selected; otherwise false.
      /// @param find_next The callback called when the user click the find button.
      /// @param replace The callback called when the user click the replace button.
      /// @param replace_all The callback called when the user click the replace all button.
      template<typename find_next_callback_t, typename replace_callback_t, typename replace_all_callback_t>
      static void show(const iwin32_window& owner, const xtd::ustring& find_string, const xtd::ustring& replace_string, const xtd::ustring& title, bool match_case, bool whole_word, find_next_callback_t find_next, replace_callback_t replace, replace_all_callback_t replace_all) {show_replace_box(owner, xtd::forms::find_event_handler(find_next), xtd::forms::replace_event_handler(replace), xtd::forms::replace_event_handler(replace_all), find_string, replace_string, title, match_case, whole_word);}
      /// @}
      
    private:
      static void show_replace_box(const iwin32_window& owner, xtd::forms::find_event_handler find_next, xtd::forms::replace_event_handler replace, xtd::forms::replace_event_handler replace_all, const xtd::ustring& find_string = xtd::ustring::empty_string, const xtd::ustring& replace_string = xtd::ustring::empty_string, const xtd::ustring& title = xtd::ustring::empty_string, bool match_case = false, bool whole_word = false);
      
      static std::unique_ptr<xtd::forms::replace_dialog> dialog_;
    };
  }
}
