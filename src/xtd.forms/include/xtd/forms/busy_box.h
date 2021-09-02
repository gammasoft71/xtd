/// @file
/// @brief Contains xtd::forms::busy_box dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "busy_dialog.h"
#include <xtd/literals.h>
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a dialog box that displays busy box.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrate the use of busy_box dialog.
    /// @include busy_box.cpp
    /// @par Windows
    /// @image html busy_box_w.png
    /// <br>
    /// @image html busy_box_wd.png
    /// @par macOS
    /// @image html busy_box_m.png
    /// <br>
    /// @image html busy_box_md.png
    /// @par Gnome
    /// @image html busy_box_g.png
    /// <br>
    /// @image html busy_box_gd.png
    class forms_export_ busy_box final static_ {
    public:
      /// @brief Hides a busy box in front.
      static void hide() {
        delete dialog_;
        dialog_ = nullptr;
      }
      
      /// @brief Displays a busy box in front of the specified window. The busy box displays a message, title bar caption, button, and icon.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      static void show(const iwin32_window& owner) {show_busy_dialog(&owner);}
      /// @brief Displays a busy box in front of the specified window. The busy box displays a message, title bar caption, button, and icon.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      static void show(const iwin32_window& owner, const xtd::ustring& text) {show_busy_dialog(&owner, text);}
      /// @brief Displays a busy box in front of the specified window. The busy box displays a message, title bar caption, button, and icon.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      static void show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption) {show_busy_dialog(&owner, text, caption);}
      /// @brief Displays a busy box in front of the specified window. The busy box displays a message, title bar caption, button, and icon.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      static void show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon) {show_busy_dialog(&owner, text, caption, icon);}
      /// @brief Displays a busy box in front of the specified window. The busy box displays a message, title bar caption, button, and icon.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param back_color A color that represents the background color of the busy box.
      static void show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color) {show_busy_dialog(&owner, text, caption, icon, back_color);}
      /// @brief Displays a busy box in front of the specified window. The busy box displays a message, title bar caption, button, and icon.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param back_color A color that represents the background color of the busy box.
      /// @param fore_color A color that represents the background color of the busy box.
      static void show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color) {show_busy_dialog(&owner, text, caption, icon, back_color, fore_color);}
      /// @brief Displays a busy box in front of the specified window. The busy box displays a message, title bar caption, button, and icon.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param back_color A color that represents the background color of the busy box.
      /// @param fore_color A color that represents the background color of the busy box.
      /// @param opacity A float that represents the topacity of the busy box. (0: full opacity and 1.0 no full opacity)
      static void show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color, float opacity) {show_busy_dialog(&owner, text, caption, icon, back_color, fore_color, opacity);}

      /// @brief Displays a busy box.
      static void show() {show_busy_dialog(nullptr);}
      /// @brief Displays a busy box. The busy box displays a message, title bar caption, button, and icon.
      /// @param text A string that specifies the text to display.
      static void show(const xtd::ustring& text) {show_busy_dialog(nullptr, text);}
      /// @brief Displays a busy box. The busy box displays a message, title bar caption, button, and icon.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      static void show(const xtd::ustring& text, const xtd::ustring& caption) {show_busy_dialog(nullptr, text, caption);}
      /// @brief Displays a busy box. The busy box displays a message, title bar caption, button, and icon.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      static void show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon) {show_busy_dialog(nullptr, text, caption, icon);}
      /// @brief Displays a busy box. The busy box displays a message, title bar caption, button, and icon.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param back_color A color that represents the background color of the busy box.
      static void show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color) {show_busy_dialog(nullptr, text, caption, icon, back_color);}
      /// @brief Displays a busy box. The busy box displays a message, title bar caption, button, and icon.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param back_color A color that represents the background color of the busy box.
      /// @param fore_color A color that represents the background color of the busy box.
      static void show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color) {show_busy_dialog(nullptr, text, caption, icon, back_color, fore_color);}
      /// @brief Displays a busy box. The busy box displays a message, title bar caption, button, and icon.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param back_color A color that represents the background color of the busy box.
      /// @param fore_color A color that represents the background color of the busy box.
      /// @param opacity A float that represents the topacity of the busy box. (0: full opacity and 1.0 no opacity)
      static void show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color, float opacity) {show_busy_dialog(nullptr, text, caption, icon, back_color, fore_color, opacity);}
      
    private:
      static busy_dialog* dialog_;
      static void show_busy_dialog(const iwin32_window* owner, const xtd::ustring& text = "Please wait..."_t, const xtd::ustring& caption = "", const xtd::drawing::icon& icon = xtd::drawing::icon::empty, const xtd::drawing::color& back_color = xtd::forms::theme_colors::current_theme().control(), const xtd::drawing::color& fore_color = xtd::forms::theme_colors::current_theme().control_text(), float opacity = 0.0) {
        if (dialog_) return;
        dialog_ = new busy_dialog();
        dialog_->description(text);
        dialog_->text(caption);
        dialog_->icon(icon);
        dialog_->back_color(back_color);
        dialog_->fore_color(fore_color);
        dialog_->opacity(opacity);
        owner ? dialog_->show(*owner) : dialog_->show();
      }
    };
  }
}
