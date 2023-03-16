/// @file
/// @brief Contains xtd::forms::busy_box dialog.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "busy_dialog.h"
#include <xtd/literals.h>
#include <xtd/static.h>
#include <xtd/forms/application.h>

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
    /// @par Appearance
    /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
    ///   <tr>
    ///     <th style="width:100px"></th>
    ///     <th><b>Windows</b></th>
    ///     <th><b>macOS</b></th>
    ///     <th><b>Gnome</b></th>
    ///   </tr>
    ///   <tr>
    ///     <th>Light</th>
    ///     <td>@image html dialog_busy_dialog2_w.png</td>
    ///     <td>@image html dialog_busy_dialog2_m.png</td>
    ///     <td>@image html dialog_busy_dialog2_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html dialog_busy_dialog2_wd.png</td>
    ///     <td>@image html dialog_busy_dialog2_md.png</td>
    ///     <td>@image html dialog_busy_dialog2_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of busy_box dialog.
    /// @include busy_box.cpp
    class forms_export_ busy_box final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Hides a busy box in front.
      static void hide();
      
      /// @brief Displays a busy box in front of the specified window. The busy box displays a message, title bar caption, button, and icon.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      static void show(const iwin32_window& owner);
      /// @brief Displays a busy box in front of the specified window. The busy box displays a message, title bar caption, button, and icon.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      static void show(const iwin32_window& owner, const xtd::ustring& text);
      /// @brief Displays a busy box in front of the specified window. The busy box displays a message, title bar caption, button, and icon.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      static void show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption);
      /// @brief Displays a busy box in front of the specified window. The busy box displays a message, title bar caption, button, and icon.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      static void show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon);
      /// @brief Displays a busy box in front of the specified window. The busy box displays a message, title bar caption, button, and icon.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param back_color A color that represents the background color of the busy box.
      static void show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color);
      /// @brief Displays a busy box in front of the specified window. The busy box displays a message, title bar caption, button, and icon.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param back_color A color that represents the background color of the busy box.
      /// @param fore_color A color that represents the background color of the busy box.
      static void show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color);
      /// @brief Displays a busy box in front of the specified window. The busy box displays a message, title bar caption, button, and icon.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param back_color A color that represents the background color of the busy box.
      /// @param fore_color A color that represents the background color of the busy box.
      /// @param opacity A float that represents the opacity of the busy box. (0: full opacity and 1.0 no full opacity)
      static void show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color, float opacity);
      
      /// @brief Displays a busy box.
      static void show();
      /// @brief Displays a busy box. The busy box displays a message, title bar caption, button, and icon.
      /// @param text A string that specifies the text to display.
      static void show(const xtd::ustring& text);
      /// @brief Displays a busy box. The busy box displays a message, title bar caption, button, and icon.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      static void show(const xtd::ustring& text, const xtd::ustring& caption);
      /// @brief Displays a busy box. The busy box displays a message, title bar caption, button, and icon.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      static void show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon);
      /// @brief Displays a busy box. The busy box displays a message, title bar caption, button, and icon.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param back_color A color that represents the background color of the busy box.
      static void show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color);
      /// @brief Displays a busy box. The busy box displays a message, title bar caption, button, and icon.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param back_color A color that represents the background color of the busy box.
      /// @param fore_color A color that represents the background color of the busy box.
      static void show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color);
      /// @brief Displays a busy box. The busy box displays a message, title bar caption, button, and icon.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param back_color A color that represents the background color of the busy box.
      /// @param fore_color A color that represents the background color of the busy box.
      /// @param opacity A float that represents the opacity of the busy box. (0: full opacity and 1.0 no opacity). The lower the value, the more transparent.
      static void show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color, float opacity);
      /// @}
      
    private:
      static void show_busy_dialog(const iwin32_window* owner, const xtd::ustring& text = "Please wait..."_t, const xtd::ustring& caption = "", const xtd::drawing::icon& icon = xtd::drawing::icon::empty, const xtd::drawing::color& back_color = application::style_sheet().system_colors().control(), const xtd::drawing::color& fore_color = application::style_sheet().system_colors().control_text(), float opacity = 1.0f);
      
      static std::unique_ptr<busy_dialog> dialog_;
    };
  }
}
