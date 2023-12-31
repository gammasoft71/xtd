/// @file
/// @brief Contains xtd::forms::find_box control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "find_dialog.h"
#include <xtd/static>
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays a find dialog. This class cannot be inherited.
    /// @par Header
    /// @code #include <xtd/forms/file_box> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                 | macOS                                   | Gnome                                   |
    /// | ----- | --------------------------------------- | --------------------------------------- | --------------------------------------- |
    /// | Light |  @image html dialog_find_dialog_w.png   |  @image html dialog_find_dialog_m.png   |  @image html dialog_find_dialog_g.png   |
    /// | Dark  |  @image html dialog_find_dialog_wd.png  |  @image html dialog_find_dialog_md.png  |  @image html dialog_find_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of xtd::forms::find_box dialog.
    /// @include find_box.cpp
    class forms_export_ find_box final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Displays a find dialog box.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the find dialog box.
      /// @param find_next The callback called when the user click the find button.
      template<typename find_next_callback_t>
      static void show(const iwin32_window& owner, find_next_callback_t find_next) {show_find_box(owner, xtd::forms::find_event_handler(find_next));}
      /// @brief Displays a find dialog box.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the find dialog box.
      /// @param find_string The string to find.
      /// @param find_next The callback called when the user click the find button.
      template<typename find_next_callback_t>
      static void show(const iwin32_window& owner, const xtd::ustring& find_string, find_next_callback_t find_next) {show_find_box(owner, xtd::forms::find_event_handler(find_next), find_string);}
      /// @brief Displays a find dialog box.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the find dialog box.
      /// @param find_string The string to find.
      /// @param title The find dialog title.
      /// @param find_next The callback called when the user click the find button.
      template<typename find_next_callback_t>
      static void show(const iwin32_window& owner, const xtd::ustring& find_string, const xtd::ustring& title, find_next_callback_t find_next) {show_find_box(owner, xtd::forms::find_event_handler(find_next), find_string, title);}
      /// @brief Displays a find dialog box.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the find dialog box.
      /// @param find_string The string to find.
      /// @param title The find dialog title.
      /// @param match_case true if match case option selected; otherwise false.
      /// @param find_next The callback called when the user click the find button.
      template<typename find_next_callback_t>
      static void show(const iwin32_window& owner, const xtd::ustring& find_string, const xtd::ustring& title, bool match_case, find_next_callback_t find_next) {show_find_box(owner, xtd::forms::find_event_handler(find_next), find_string, title, match_case);}
      /// @brief Displays a find dialog box.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the find dialog box.
      /// @param find_string The string to find.
      /// @param title The find dialog title.
      /// @param match_case true if match case option selected; otherwise false.
      /// @param search_direction One of xtd::forms::search_direction values.
      /// @param find_next The callback called when the user click the find button.
      template<typename find_next_callback_t>
      static void show(const iwin32_window& owner, const xtd::ustring& find_string, const xtd::ustring& title, bool match_case, xtd::forms::search_direction search_direction, find_next_callback_t find_next) {show_find_box(owner, xtd::forms::find_event_handler(find_next), find_string, title, match_case, search_direction);}
      /// @brief Displays a find dialog box.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the find dialog box.
      /// @param find_string The string to find.
      /// @param title The find dialog title.
      /// @param match_case true if match case option selected; otherwise false.
      /// @param search_direction One of xtd::forms::search_direction values.
      /// @param whole_word true if whole word option selected; otherwise false.
      /// @param find_next The callback called when the user click the find button.
      template<typename find_next_callback_t>
      static void show(const iwin32_window& owner, const xtd::ustring& find_string, const xtd::ustring& title, bool match_case, xtd::forms::search_direction search_direction, bool whole_word, find_next_callback_t find_next) {show_find_box(owner, xtd::forms::find_event_handler(find_next), find_string, title, match_case, search_direction, whole_word);}
      /// @}
      
    private:
      static void show_find_box(const iwin32_window& owner, xtd::forms::find_event_handler find_next, const xtd::ustring& find_string = "", const xtd::ustring& title = "", bool match_case = false, xtd::forms::search_direction search_direction = xtd::forms::search_direction::down, bool whole_word = false);
      
      static std::unique_ptr<xtd::forms::find_dialog> dialog_;
    };
  }
}
