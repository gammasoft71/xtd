/// @file
/// @brief Contains xtd::forms::font_box control.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export"
#include "font_box_options"
#include "dialog_result"
#include "iwin32_window"
#include <xtd/drawing/color>
#include <xtd/drawing/font>
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays a dialog to the user to choose a font from among those installed on the local computer.
    /// @par Header
    /// @code #include <xtd/forms/font_box> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                 | macOS                                   | Gnome                                   |
    /// | ----- | --------------------------------------- | --------------------------------------- | --------------------------------------- |
    /// | Light |  @image html dialog_font_dialog_w.png   |  @image html dialog_font_dialog_m.png   |  @image html dialog_font_dialog_g.png   |
    /// | Dark  |  @image html dialog_font_dialog_wd.png  |  @image html dialog_font_dialog_md.png  |  @image html dialog_font_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of xtd::forms::font_box dialog.
    /// @include font_box.cpp
    class forms_export_ font_box final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Displays a font dialog box.
      /// @param font An output xtd::drawing::font that will store the selected font.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output font parameter will contain the selected font, otherwise it will be ignored.
      static dialog_result show(xtd::drawing::font& font);
      
      /// @brief Displays a font dialog box.
      /// @param font An output xtd::drawing::font that will store the selected font.
      /// @param options A bitwise combination of enum xtd::forms::font_box_options to specify additional options to the font dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output font parameter will contain the selected font, otherwise it will be ignored.
      static dialog_result show(xtd::drawing::font& font, const font_box_options options);
      
      /// @brief Displays a font dialog box in front of a specified window.
      /// @param font An output xtd::drawing::font that will store the selected font.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the font dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output font parameter will contain the selected font, otherwise it will be ignored.
      static dialog_result show(xtd::drawing::font& font, const iwin32_window& owner);
      
      /// @brief Displays a font dialog box in front of a specified window.
      /// @param font An output xtd::drawing::font that will store the selected font.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the font dialog box.
      /// @param options A bitwise combination of enum xtd::forms::font_box_options to specify additional options to the font dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output font parameter will contain the selected font, otherwise it will be ignored.
      static dialog_result show(xtd::drawing::font& font, const iwin32_window& owner, const font_box_options options);
      
      /// @brief Displays a font dialog box.
      /// @param font An output xtd::drawing::font that will store the selected font.
      /// @param color An output xtd::drawing::color that will store the selected font color.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output parameters font and color will contain the selected font and color, otherwise they will be ignored.
      static dialog_result show(xtd::drawing::font& font, xtd::drawing::color& color);
      
      /// @brief Displays a font dialog box.
      /// @param font An output xtd::drawing::font that will store the selected font.
      /// @param color An output xtd::drawing::color that will store the selected font color.
      /// @param options A bitwise combination of enum xtd::forms::font_box_options to specify additional options to the font dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output parameters font and color will contain the selected font and color, otherwise they will be ignored.
      static dialog_result show(xtd::drawing::font& font, xtd::drawing::color& color, const font_box_options options);
      
      /// @brief Displays a font dialog box in front of a specified window.
      /// @param font An output xtd::drawing::font that will store the selected font.
      /// @param color An output xtd::drawing::color that will store the selected font color.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the font dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output parameters font and color will contain the selected font and color, otherwise they will be ignored.
      static dialog_result show(xtd::drawing::font& font, xtd::drawing::color& color, const iwin32_window& owner);
      
      /// @brief Displays a font dialog box in front of a specified window.
      /// @param font An output xtd::drawing::font that will store the selected font.
      /// @param color An output xtd::drawing::color that will store the selected font color.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the font dialog box.
      /// @param options A bitwise combination of enum xtd::forms::font_box_options to specify additional options to the font dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output parameters font and color will contain the selected font and color, otherwise they will be ignored.
      static dialog_result show(xtd::drawing::font& font, xtd::drawing::color& color, const iwin32_window& owner, const font_box_options options);
      /// @}
      
    private:
      static dialog_result show_font_box(xtd::drawing::font& font, xtd::drawing::color* color = nullptr, const iwin32_window* owner = nullptr, font_box_options options = font_box_options::none);
    };
  }
}
