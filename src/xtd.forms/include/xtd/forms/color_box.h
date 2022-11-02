/// @file
/// @brief Contains xtd::forms::color_box control.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "color_dialog.h"
#include "color_box_styles.h"
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays available colors along with controls that enable the user to define custom colors.
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
    ///     <td>@image html dialog_color_dialog_w.png</td>
    ///     <td>@image html dialog_color_dialog2_m.png</td>
    ///     <td>@image html dialog_color_dialog2_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html dialog_color_dialog_wd.png</td>
    ///     <td>@image html dialog_color_dialog2_md.png</td>
    ///     <td>@image html dialog_color_dialog2_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of color_box dialog.
    /// @include color_box.cpp
    class color_box final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Displays a color box in front of the specified window. The color box displays a color.
      /// @param color A xtd::drawing::color that specifies the color to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the color parameter contains the new chosen color.
      static xtd::forms::dialog_result show(xtd::drawing::color& color, const xtd::forms::iwin32_window& owner) {return show_color_box(color, &owner);}
      /// @brief Displays a color box in front of the specified window. The color box displays a color.
      /// @param color A xtd::drawing::color that specifies the color to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param title The file dialog box title. The default value is an empty string ("").
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the color parameter contains the new chosen color.
      static xtd::forms::dialog_result show(xtd::drawing::color& color, const xtd::forms::iwin32_window& owner, const xtd::ustring& title) {return show_color_box(color, &owner, title);}
      /// @brief Displays a color box in front of the specified window. The color box displays a color with styles.
      /// @param color A xtd::drawing::color that specifies the color to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param title The file dialog box title. The default value is an empty string ("").
      /// @param styles A bitwise combination of the color_box_styles values. The default is alpha_color and allow_full_open.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the color parameter contains the new chosen color.
      static xtd::forms::dialog_result show(xtd::drawing::color& color, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, color_box_styles styles) {return show_color_box(color, &owner, title, styles);}
      /// @brief Displays a color box in front of the specified window. The color box displays a color with styles, and custom colors.
      /// @param color A xtd::drawing::color that specifies the color to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param title The file dialog box title. The default value is an empty string ("").
      /// @param styles A bitwise combination of the color_box_styles values. The default is alpha_color and allow_full_open.
      /// @param custom_colors A colors array that contains user custom colors.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the color parameter contains the new chosen color.
      static xtd::forms::dialog_result show(xtd::drawing::color& color, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, color_box_styles styles, const std::vector<xtd::drawing::color>& custom_colors) {return show_color_box(color, &owner, title, styles, custom_colors);}
      
      /// @brief Displays a color box. The color box displays a color.
      /// @param color A xtd::drawing::color that specifies the color to display.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the color parameter contains the new chosen color.
      static xtd::forms::dialog_result show(xtd::drawing::color& color) {return show_color_box(color, nullptr);}
      /// @brief Displays a color box. The color box displays a color.
      /// @param color A xtd::drawing::color that specifies the color to display.
      /// @param title The file dialog box title. The default value is an empty string ("").
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the color parameter contains the new chosen color.
      static xtd::forms::dialog_result show(xtd::drawing::color& color, const xtd::ustring& title) {return show_color_box(color, nullptr, title);}
      /// @brief Displays a color box. The color box displays a color with styles.
      /// @param color A xtd::drawing::color that specifies the color to display.
      /// @param title The file dialog box title. The default value is an empty string ("").
      /// @param styles A bitwise combination of the color_box_styles values. The default is alpha_color and allow_full_open.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the color parameter contains the new chosen color.
      static xtd::forms::dialog_result show(xtd::drawing::color& color, const xtd::ustring& title, color_box_styles styles) {return show_color_box(color, nullptr, title, styles);}
      /// @brief Displays a color box. The color box displays a color with styles, and custom colors.
      /// @param color A xtd::drawing::color that specifies the color to display.
      /// @param title The file dialog box title. The default value is an empty string ("").
      /// @param styles A bitwise combination of the color_box_styles values. The default is alpha_color and allow_full_open.
      /// @param custom_colors A colors array that contains user custom colors.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the color parameter contains the new chosen color.
      static xtd::forms::dialog_result show(xtd::drawing::color& color, const xtd::ustring& title, color_box_styles styles, const std::vector<xtd::drawing::color>& custom_colors) {return show_color_box(color, nullptr, title, styles, custom_colors);}
      /// @}
      
    private:
      static xtd::forms::dialog_result show_color_box(xtd::drawing::color& color, const xtd::forms::iwin32_window* owner = nullptr, const xtd::ustring& title = "", color_box_styles styles = color_box_styles::alpha_color | color_box_styles::allow_full_open, const std::optional<std::vector<xtd::drawing::color>>& custom_colors = std::optional<std::vector<xtd::drawing::color>> {}) {
        xtd::forms::color_dialog dialog;
        dialog.color(color);
        dialog.alpha_color((styles & color_box_styles::alpha_color) == color_box_styles::alpha_color);
        dialog.allow_full_open((styles & color_box_styles::allow_full_open) == color_box_styles::allow_full_open);
        dialog.any_color((styles & color_box_styles::any_color) == color_box_styles::any_color);
        dialog.full_open((styles & color_box_styles::full_open) == color_box_styles::full_open);
        dialog.show_help((styles & color_box_styles::show_help) == color_box_styles::show_help);
        dialog.title(title);
        if (custom_colors.has_value()) dialog.custom_colors(custom_colors.value());
        dialog.solid_color_only((styles & color_box_styles::solid_color_only) == color_box_styles::solid_color_only);
        xtd::forms::dialog_result result = owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
        if (result == xtd::forms::dialog_result::ok) color = dialog.color();
        return result;
      }
    };
  }
}
