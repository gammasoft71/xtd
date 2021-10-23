/// @file
/// @brief Contains xtd::forms::font_box control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/static.h>
#include "font_dialog.h"
#include "font_box_options.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays a dialog to the user to choose a font from among those installed on the local computer.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrate the use of xtd::forms::font_box dialog.
    /// @include font_box.cpp
    class font_box final static_ {
    public:
      /// @brief Displays a font dialog box.
      /// @param font An output xtd::drawing::font that will store the selected font.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the output font parameter will contain the selected font, otherwise it will be ignored.
      static dialog_result show(xtd::drawing::font& font) { return show_font_box(font); }

      /// @brief Displays a font dialog box.
      /// @param font An output xtd::drawing::font that will store the selected font.
      /// @param options A bitwise combination of enum xtd::forms::font_box_options to specify additional options to the font dialog box.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the output font parameter will contain the selected font, otherwise it will be ignored.
      static dialog_result show(xtd::drawing::font& font, const font_box_options options) { return show_font_box(font, nullptr, nullptr, options); }
   
      /// @brief Displays a font dialog box in front of a specified window.
      /// @param font An output xtd::drawing::font that will store the selected font.
      /// @param owner An iwin32_window that represents the owner window of the font dialog box.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the output font parameter will contain the selected font, otherwise it will be ignored.
      static dialog_result show(xtd::drawing::font& font, const iwin32_window& owner) { return show_font_box(font, nullptr, &owner); }

      /// @brief Displays a font dialog box in front of a specified window.
      /// @param font An output xtd::drawing::font that will store the selected font.
      /// @param owner An iwin32_window that represents the owner window of the font dialog box.
      /// @param options A bitwise combination of enum xtd::forms::font_box_options to specify additional options to the font dialog box.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the output font parameter will contain the selected font, otherwise it will be ignored.
      static dialog_result show(xtd::drawing::font& font, const iwin32_window& owner,  const font_box_options options) { return show_font_box(font, nullptr, &owner, options); }

      /// @brief Displays a font dialog box.
      /// @param font An output xtd::drawing::font that will store the selected font.
      /// @param color An output xtd::drawing::color that will store the selected font color.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the output parameters font and color will contain the selected font and color, otherwise they will be ignored.
      static dialog_result show(xtd::drawing::font& font, xtd::drawing::color& color) { return show_font_box(font, &color); }

      /// @brief Displays a font dialog box.
      /// @param font An output xtd::drawing::font that will store the selected font.
      /// @param color An output xtd::drawing::color that will store the selected font color.
      /// @param options A bitwise combination of enum xtd::forms::font_box_options to specify additional options to the font dialog box.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the output parameters font and color will contain the selected font and color, otherwise they will be ignored.
      static dialog_result show(xtd::drawing::font& font, xtd::drawing::color& color, const font_box_options options) { return show_font_box(font, &color, nullptr, options); }

      /// @brief Displays a font dialog box in front of a specified window.
      /// @param font An output xtd::drawing::font that will store the selected font.
      /// @param color An output xtd::drawing::color that will store the selected font color.
      /// @param owner An iwin32_window that represents the owner window of the font dialog box.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the output parameters font and color will contain the selected font and color, otherwise they will be ignored.
      static dialog_result show(xtd::drawing::font& font, xtd::drawing::color& color, const iwin32_window& owner) { return show_font_box(font, &color, &owner); }

      /// @brief Displays a font dialog box in front of a specified window.
      /// @param font An output xtd::drawing::font that will store the selected font.
      /// @param color An output xtd::drawing::color that will store the selected font color.
      /// @param owner An iwin32_window that represents the owner window of the font dialog box.
      /// @param options A bitwise combination of enum xtd::forms::font_box_options to specify additional options to the font dialog box.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks If dialog_result is ok, the output parameters font and color will contain the selected font and color, otherwise they will be ignored.
      static dialog_result show(xtd::drawing::font& font, xtd::drawing::color& color, const iwin32_window& owner, const font_box_options options) { return show_font_box(font, &color, &owner, options); }

    private:
      static dialog_result show_font_box(xtd::drawing::font& font, xtd::drawing::color* color = nullptr, const iwin32_window* owner = nullptr, font_box_options options = font_box_options::none) {
        font_dialog dialog{};
        if (color) {
          options |= font_box_options::show_color;
          dialog.color(*color);
        }
        dialog.allow_simulation(options & font_box_options::allow_simulations)
              .allow_vector_fonts(options & font_box_options::allow_vector_fonts)
              .allow_vertical_fonts(options & font_box_options::allow_simulations)
              .allow_script_change(options & font_box_options::allow_script_change)
              .fixed_pitch_only(options & font_box_options::fixed_pitch_only)
              .font(font)
              .script_only(options & font_box_options::scripts_only)
              .show_apply(options & font_box_options::show_apply)
              .show_color(options & font_box_options::show_color)
              .show_effect(options & font_box_options::show_effects)
              .show_help(options & font_box_options::show_help);
        auto res = owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
        if (res == dialog_result::ok) {
          font = dialog.font();
          if (color) *color = dialog.color();
        }
        return res;
      }
    };
  }
}
