/// @file
/// @brief Contains xtd::forms::known_themed_color enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the known system colors.
    /// @par Header
    /// @code #include <xtd/forms/known_themed_color> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @see xtd::drawing::color
    enum class known_themed_color {
      /// @brief The system-defined color of the accent color (macos specific. On other platform is same as menu_highlight).
      accent = 1,
      /// @brief The system-defined color of the accent text color (macos specific. On other platform is same as highlight_text).
      accent_text,
      /// @brief The system-defined color of the active window's border.
      active_border,
      /// @brief The system-defined color of the background of the active window's title bar.
      active_caption,
      /// @brief The system-defined color of the text in the active window's title bar.
      active_caption_text,
      /// @brief The system-defined color of the application workspace. The application workspace is the area in a multiple-document view that is not being occupied by documents.
      app_workspace,
      /// @brief The system-defined face color of a 3-D element.
      button_face,
      /// @brief The system-defined color that is the highlight color of a 3-D element. This color is applied to parts of a 3-D element that face the light source.
      button_highlight,
      /// @brief The system-defined color that is the shadow color of a 3-D element. This color is applied to parts of a 3-D element that face away from the light source.
      button_shadow,
      /// @brief The system-defined face color of a 3-D element.
      control,
      /// @brief The system-defined shadow color of a 3-D element. The shadow color is applied to parts of a 3-D element that face away from the light source.
      control_dark,
      /// @brief The system-defined color that is the dark shadow color of a 3-D element. The dark shadow color is applied to the parts of a 3-D element that are the darkest color.
      control_dark_dark,
      /// @brief The system-defined color that is the light color of a 3-D element. The light color is applied to parts of a 3-D element that face the light source.
      control_light,
      /// @brief The system-defined highlight color of a 3-D element. The highlight color is applied to the parts of a 3-D element that are the lightest color.
      control_light_light,
      /// @brief The system-defined color of text in a 3-D element.
      control_text,
      /// @brief The system-defined color of the desktop.
      desktop,
      /// @brief The system-defined color of the lightest color in the color gradient of an active window's title bar.
      gradient_active_caption,
      /// @brief The system-defined color of the lightest color in the color gradient of an inactive window's title bar.
      gradient_inactive_caption,
      /// @brief The system-defined color of dimmed text. Items in a list that are disabled are displayed in dimmed text.
      gray_text,
      /// @brief The system-defined color of the background of selected items. This includes selected menu items as well as selected text.
      highlight,
      /// @brief The system-defined color of the text of selected items.
      highlight_text,
      /// @brief The system-defined color used to designate a hot-tracked item. Single-clicking a hot-tracked item executes the item.
      hot_track,
      /// @brief The system-defined color of an inactive window's border.
      inactive_border,
      /// @brief The system-defined color of the background of an inactive window's title bar.
      inactive_caption,
      /// @brief The system-defined color of the text in an inactive window's title bar.
      inactive_caption_text,
      /// @brief The system-defined color of the background of a ToolTip.
      info,
      /// @brief The system-defined color of the text of a ToolTip.
      info_text,
      /// @brief The system-defined color of a menu's background.
      menu,
      /// @brief The system-defined color of the background of a menu bar.
      menu_bar,
      /// @brief The system-defined color used to highlight menu items when the menu appears as a flat menu.
      menu_highlight,
      /// @brief The system-defined color of a menu's text.
      menu_text,
      /// @brief The system-defined color of the background of a scroll bar.
      scroll_bar,
      /// @brief The system-defined color of the accent color (macos specific. On other platform is same as window).
      text_box,
      /// @brief The system-defined color of the accent text color (macos specific. On other platform is same as window_text).
      text_box_text,
      /// @brief The system-defined color of the background in the client area of a window.
      window,
      /// @brief The system-defined color of a window frame.
      window_frame,
      /// @brief The system-defined color of the text in the client area of a window.
      window_text,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::known_themed_color> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::known_themed_color> {{xtd::forms::known_themed_color::active_border, "active_border"}, {xtd::forms::known_themed_color::active_caption, "active_caption"}, {xtd::forms::known_themed_color::active_caption_text, "active_caption_text"}, {xtd::forms::known_themed_color::app_workspace, "app_workspace"}, {xtd::forms::known_themed_color::control, "control"}, {xtd::forms::known_themed_color::control_dark, "control_dark"}, {xtd::forms::known_themed_color::control_dark_dark, "control_dark_dark"}, {xtd::forms::known_themed_color::control_light, "control_light"}, {xtd::forms::known_themed_color::control_light_light, "control_light_light"}, {xtd::forms::known_themed_color::control_text, "control_text"}, {xtd::forms::known_themed_color::desktop, "desktop"}, {xtd::forms::known_themed_color::gray_text, "gray_text"}, {xtd::forms::known_themed_color::highlight, "highlight"}, {xtd::forms::known_themed_color::highlight_text, "highlight_text"}, {xtd::forms::known_themed_color::hot_track, "hot_track"}, {xtd::forms::known_themed_color::inactive_border, "inactive_border"}, {xtd::forms::known_themed_color::inactive_caption, "inactive_caption"}, {xtd::forms::known_themed_color::inactive_caption_text, "inactive_caption_text"}, {xtd::forms::known_themed_color::info, "info"}, {xtd::forms::known_themed_color::info_text, "info_text"}, {xtd::forms::known_themed_color::menu, "menu"}, {xtd::forms::known_themed_color::menu_text, "menu_text"}, {xtd::forms::known_themed_color::scroll_bar, "scroll_bar"}, {xtd::forms::known_themed_color::window, "window"}, {xtd::forms::known_themed_color::window_frame, "window_frame"}, {xtd::forms::known_themed_color::window_text, "window_text"}, {xtd::forms::known_themed_color::button_face, "button_face"}, {xtd::forms::known_themed_color::button_highlight, "button_highlight"}, {xtd::forms::known_themed_color::button_shadow, "button_shadow"}, {xtd::forms::known_themed_color::gradient_active_caption, "gradient_active_caption"}, {xtd::forms::known_themed_color::gradient_inactive_caption, "gradient_inactive_caption"}, {xtd::forms::known_themed_color::menu_bar, "menu_bar"}, {xtd::forms::known_themed_color::menu_highlight, "menu_highlight"}, {xtd::forms::known_themed_color::accent, "accent"}, {xtd::forms::known_themed_color::accent_text, "accent_text"}, {xtd::forms::known_themed_color::text_box, "text_box"}, {xtd::forms::known_themed_color::text_box_text, "text_box_text"}};}
};
/// @endcond
