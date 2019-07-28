#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies the known system colors.
    /// @see xtd::drawing::color
    enum class known_color {
      /// @brief The system-defined color of the active window's border.
      active_border = 1,
      /// @brief The system-defined color of the background of the active window's title bar.
      active_caption,
      /// @brief The system-defined color of the text in the active window's title bar.
      active_caption_text,
      /// @brief The system-defined color of the application workspace. The application workspace is the area in a multiple-document view that is not being occupied by documents.
      app_workspace,
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
      /// @brief The system-defined color of a menu's text.
      menu_text,
      /// @brief The system-defined color of the background of a scroll bar.
      scroll_bar,
      /// @brief The system-defined color of the background in the client area of a window.
      window,
      /// @brief The system-defined color of a window frame.
      window_frame,
      /// @brief The system-defined color of the text in the client area of a window.
      window_text,
      /// @brief A system-defined color.
      transparent,
      /// @brief A system-defined color.
      alice_blue,
      /// @brief A system-defined color.
      antique_white,
      /// @brief A system-defined color.
      aqua,
      /// @brief A system-defined color.
      aquamarine,
      /// @brief A system-defined color.
      azure,
      /// @brief A system-defined color.
      beige,
      /// @brief A system-defined color.
      bisque,
      /// @brief A system-defined color.
      black,
      /// @brief A system-defined color.
      blanched_almond,
      /// @brief A system-defined color.
      blue,
      /// @brief A system-defined color.
      blue_violet,
      /// @brief A system-defined color.
      brown,
      /// @brief A system-defined color.
      burly_wood,
      /// @brief A system-defined color.
      cadet_blue,
      /// @brief A system-defined color.
      chartreuse,
      /// @brief A system-defined color.
      chocolate,
      /// @brief A system-defined color.
      coral,
      /// @brief A system-defined color.
      cornflower_blue,
      /// @brief A system-defined color.
      cornsilk,
      /// @brief A system-defined color.
      crimson,
      /// @brief A system-defined color.
      cyan,
      /// @brief A system-defined color.
      dark_blue,
      /// @brief A system-defined color.
      dark_cyan,
      /// @brief A system-defined color.
      dark_goldenrod,
      /// @brief A system-defined color.
      dark_gray,
      /// @brief A system-defined color.
      dark_green,
      /// @brief A system-defined color.
      dark_khaki,
      /// @brief A system-defined color.
      dark_magenta,
      /// @brief A system-defined color.
      dark_oliveGreen,
      /// @brief A system-defined color.
      dark_orange,
      /// @brief A system-defined color.
      dark_orchid,
      /// @brief A system-defined color.
      dark_red,
      /// @brief A system-defined color.
      dark_salmon,
      /// @brief A system-defined color.
      dark_sea_green,
      /// @brief A system-defined color.
      dark_slate_blue,
      /// @brief A system-defined color.
      dark_slate_gray,
      /// @brief A system-defined color.
      dark_turquoise,
      /// @brief A system-defined color.
      dark_violet,
      /// @brief A system-defined color.
      deep_pink,
      /// @brief A system-defined color.
      deep_sky_blue,
      /// @brief A system-defined color.
      dim_gray,
      /// @brief A system-defined color.
      dodger_blue,
      /// @brief A system-defined color.
      firebrick,
      /// @brief A system-defined color.
      floral_white,
      /// @brief A system-defined color.
      forest_green,
      /// @brief A system-defined color.
      fuchsia,
      /// @brief A system-defined color.
      gainsboro,
      /// @brief A system-defined color.
      ghost_white,
      /// @brief A system-defined color.
      gold,
      /// @brief A system-defined color.
      goldenrod,
      /// @brief A system-defined color.
      gray,
      /// @brief A system-defined color.
      green,
      /// @brief A system-defined color.
      green_yellow,
      /// @brief A system-defined color.
      honeydew,
      /// @brief A system-defined color.
      hot_pink,
      /// @brief A system-defined color.
      indian_red,
      /// @brief A system-defined color.
      indigo,
      /// @brief A system-defined color.
      ivory,
      /// @brief A system-defined color.
      khaki,
      /// @brief A system-defined color.
      lavender,
      /// @brief A system-defined color.
      lavender_blush,
      /// @brief A system-defined color.
      lawn_green,
      /// @brief A system-defined color.
      lemon_chiffon,
      /// @brief A system-defined color.
      light_blue,
      /// @brief A system-defined color.
      light_coral,
      /// @brief A system-defined color.
      light_cyan,
      /// @brief A system-defined color.
      light_goldenrod_yellow,
      /// @brief A system-defined color.
      light_gray,
      /// @brief A system-defined color.
      light_green,
      /// @brief A system-defined color.
      light_pink,
      /// @brief A system-defined color.
      light_salmon,
      /// @brief A system-defined color.
      light_sea_green,
      /// @brief A system-defined color.
      light_sky_blue,
      /// @brief A system-defined color.
      light_slate_gray,
      /// @brief A system-defined color.
      light_steel_blue,
      /// @brief A system-defined color.
      light_yellow,
      /// @brief A system-defined color.
      lime,
      /// @brief A system-defined color.
      lime_green,
      /// @brief A system-defined color.
      linen,
      /// @brief A system-defined color.
      magenta,
      /// @brief A system-defined color.
      maroon,
      /// @brief A system-defined color.
      medium_aquamarine,
      /// @brief A system-defined color.
      medium_blue,
      /// @brief A system-defined color.
      medium_orchid,
      /// @brief A system-defined color.
      medium_purple,
      /// @brief A system-defined color.
      medium_sea_green,
      /// @brief A system-defined color.
      medium_slate_blue,
      /// @brief A system-defined color.
      medium_spring_green,
      /// @brief A system-defined color.
      medium_turquoise,
      /// @brief A system-defined color.
      medium_violet_red,
      /// @brief A system-defined color.
      midnight_blue,
      /// @brief A system-defined color.
      mint_cream,
      /// @brief A system-defined color.
      misty_rose,
      /// @brief A system-defined color.
      moccasin,
      /// @brief A system-defined color.
      navajo_white,
      /// @brief A system-defined color.
      navy,
      /// @brief A system-defined color.
      old_lace,
      /// @brief A system-defined color.
      olive,
      /// @brief A system-defined color.
      olive_drab,
      /// @brief A system-defined color.
      orange,
      /// @brief A system-defined color.
      orange_red,
      /// @brief A system-defined color.
      orchid,
      /// @brief A system-defined color.
      pale_goldenrod,
      /// @brief A system-defined color.
      pale_green,
      /// @brief A system-defined color.
      pale_turquoise,
      /// @brief A system-defined color.
      pale_violet_red,
      /// @brief A system-defined color.
      papaya_whip,
      /// @brief A system-defined color.
      peach_puff,
      /// @brief A system-defined color.
      peru,
      /// @brief A system-defined color.
      pink,
      /// @brief A system-defined color.
      plum,
      /// @brief A system-defined color.
      powder_blue,
      /// @brief A system-defined color.
      purple,
      /// @brief A system-defined color.
      red,
      /// @brief A system-defined color.
      rosy_brown,
      /// @brief A system-defined color.
      royal_blue,
      /// @brief A system-defined color.
      saddle_brown,
      /// @brief A system-defined color.
      salmon,
      /// @brief A system-defined color.
      sandy_brown,
      /// @brief A system-defined color.
      sea_green,
      /// @brief A system-defined color.
      sea_shell,
      /// @brief A system-defined color.
      sienna,
      /// @brief A system-defined color.
      silver,
      /// @brief A system-defined color.
      sky_blue,
      /// @brief A system-defined color.
      slate_blue,
      /// @brief A system-defined color.
      slate_gray,
      /// @brief A system-defined color.
      snow,
      /// @brief A system-defined color.
      spring_green,
      /// @brief A system-defined color.
      steel_blue,
      /// @brief A system-defined color.
      tan,
      /// @brief A system-defined color.
      teal,
      /// @brief A system-defined color.
      thistle,
      /// @brief A system-defined color.
      tomato,
      /// @brief A system-defined color.
      turquoise,
      /// @brief A system-defined color.
      violet,
      /// @brief A system-defined color.
      wheat,
      /// @brief A system-defined color.
      white,
      /// @brief A system-defined color.
      white_smoke,
      /// @brief A system-defined color.
      yellow,
      /// @brief A system-defined color.
      yellow_green,
      /// @brief The system-defined face color of a 3-D element.
      button_face,
      /// @brief The system-defined color that is the highlight color of a 3-D element. This color is applied to parts of a 3-D element that face the light source.
      button_highlight,
      /// @brief The system-defined color that is the shadow color of a 3-D element. This color is applied to parts of a 3-D element that face away from the light source.
      button_shadow,
      /// @brief The system-defined color of the lightest color in the color gradient of an active window's title bar.
      gradient_active_caption,
      /// @brief The system-defined color of the lightest color in the color gradient of an inactive window's title bar.
      gradient_inactive_caption,
      /// @brief The system-defined color of the background of a menu bar.
      menu_bar,
      /// @brief The system-defined color used to highlight menu items when the menu appears as a flat menu.
      menu_highlight
    };
    
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, known_color value) {return os << to_string(value, {
      {known_color::active_border, "active_border"},
      {known_color::active_caption, "active_caption"},
      {known_color::active_caption_text, "active_caption_text"},
      {known_color::app_workspace, "app_workspace"},
      {known_color::control, "control"},
      {known_color::control_dark, "control_dark"},
    });}
    inline std::wostream& operator<<(std::wostream& os, known_color value) {return os << to_string(value, {
      {known_color::active_border, L"active_border"},
      {known_color::active_caption, L"active_caption"},
      {known_color::active_caption_text, L"active_caption_text"},
      {known_color::app_workspace, L"app_workspace"},
      {known_color::control, L"control"},
      {known_color::control_dark, L"control_dark"},
    });}
    /// @endcond
  }
}
