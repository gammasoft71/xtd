/// @file
/// @brief Contains xtd::forms::color_box control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include "color_box_styles.h"
#include "dialog_result.h"
#include "iwin32_window.h"
#include <xtd/drawing/color>
#include <xtd/static>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays available colors along with controls that enable the user to define custom colors.
    /// @par Header
    /// @code #include <xtd/forms/color_box> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                  | macOS                                    | Gnome                                    |
    /// | ----- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
    /// | Light |  @image html dialog_color_dialog_w.png   |  @image html dialog_color_dialog_m.png   |  @image html dialog_color_dialog_g.png   |
    /// | Dark  |  @image html dialog_color_dialog_wd.png  |  @image html dialog_color_dialog_md.png  |  @image html dialog_color_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of color_box dialog.
    /// @include color_box.cpp
    class forms_export_ color_box final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Displays a color box in front of the specified window. The color box displays a color.
      /// @param color A xtd::drawing::color that specifies the color to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the color parameter contains the new chosen color.
      static xtd::forms::dialog_result show(xtd::drawing::color& color, const xtd::forms::iwin32_window& owner);
      /// @brief Displays a color box in front of the specified window. The color box displays a color.
      /// @param color A xtd::drawing::color that specifies the color to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param title The file dialog box title. The default value is an empty string ("").
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the color parameter contains the new chosen color.
      static xtd::forms::dialog_result show(xtd::drawing::color& color, const xtd::forms::iwin32_window& owner, const xtd::ustring& title);
      /// @brief Displays a color box in front of the specified window. The color box displays a color with styles.
      /// @param color A xtd::drawing::color that specifies the color to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param title The file dialog box title. The default value is an empty string ("").
      /// @param styles A bitwise combination of the color_box_styles values. The default is alpha_color and allow_full_open.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the color parameter contains the new chosen color.
      static xtd::forms::dialog_result show(xtd::drawing::color& color, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, color_box_styles styles);
      /// @brief Displays a color box in front of the specified window. The color box displays a color with styles, and custom colors.
      /// @param color A xtd::drawing::color that specifies the color to display.
      /// @param owner A iwin32_window that represents the owner window of the color box.
      /// @param title The file dialog box title. The default value is an empty string ("").
      /// @param styles A bitwise combination of the color_box_styles values. The default is alpha_color and allow_full_open.
      /// @param custom_colors A colors array that contains user custom colors.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the color parameter contains the new chosen color.
      static xtd::forms::dialog_result show(xtd::drawing::color& color, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, color_box_styles styles, const std::vector<xtd::drawing::color>& custom_colors);
      
      /// @brief Displays a color box. The color box displays a color.
      /// @param color A xtd::drawing::color that specifies the color to display.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the color parameter contains the new chosen color.
      static xtd::forms::dialog_result show(xtd::drawing::color& color);
      /// @brief Displays a color box. The color box displays a color.
      /// @param color A xtd::drawing::color that specifies the color to display.
      /// @param title The file dialog box title. The default value is an empty string ("").
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the color parameter contains the new chosen color.
      static xtd::forms::dialog_result show(xtd::drawing::color& color, const xtd::ustring& title);
      /// @brief Displays a color box. The color box displays a color with styles.
      /// @param color A xtd::drawing::color that specifies the color to display.
      /// @param title The file dialog box title. The default value is an empty string ("").
      /// @param styles A bitwise combination of the color_box_styles values. The default is alpha_color and allow_full_open.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the color parameter contains the new chosen color.
      static xtd::forms::dialog_result show(xtd::drawing::color& color, const xtd::ustring& title, color_box_styles styles);
      /// @brief Displays a color box. The color box displays a color with styles, and custom colors.
      /// @param color A xtd::drawing::color that specifies the color to display.
      /// @param title The file dialog box title. The default value is an empty string ("").
      /// @param styles A bitwise combination of the color_box_styles values. The default is alpha_color and allow_full_open.
      /// @param custom_colors A colors array that contains user custom colors.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the color parameter contains the new chosen color.
      static xtd::forms::dialog_result show(xtd::drawing::color& color, const xtd::ustring& title, color_box_styles styles, const std::vector<xtd::drawing::color>& custom_colors);
      /// @}
      
    private:
      static xtd::forms::dialog_result show_color_box(xtd::drawing::color& color, const xtd::forms::iwin32_window* owner = nullptr, const xtd::ustring& title = xtd::ustring::empty_string, color_box_styles styles = color_box_styles::alpha_color | color_box_styles::allow_full_open, const std::optional<std::vector<xtd::drawing::color>>& custom_colors = std::optional<std::vector<xtd::drawing::color>> {});
    };
  }
}
