/// @file
/// @brief Contains xtd::drawing::known_color enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "xtd/ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies the known system colors.
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing
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
      dark_olive_green,
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
      rebecca_purple,
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
      menu_highlight,
      /// @brief The system-defined color of the accent color (macos specific. On other platform is same as menu_highlight).
      accent,
      /// @brief The system-defined color of the accent text color (macos specific. On other platform is same as highlight_text).
      accent_text,
      /// @brief The system-defined color of the accent color (macos specific. On other platform is same as window).
      text_box,
      /// @brief The system-defined color of the accent text color (macos specific. On other platform is same as window_text).
      text_box_text,
    };
    
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, known_color value) {return os << to_string(value, {{known_color::active_border, "active_border"}, {known_color::active_caption, "active_caption"}, {known_color::active_caption_text, "active_caption_text"}, {known_color::app_workspace, "app_workspace"}, {known_color::control, "control"}, {known_color::control_dark, "control_dark"}, {known_color::control_dark_dark, "control_dark_dark"}, {known_color::control_light, "control_light"}, {known_color::control_light_light, "control_light_light"}, {known_color::control_text, "control_text"}, {known_color::desktop, "desktop"}, {known_color::gray_text, "gray_text"}, {known_color::highlight, "highlight"}, {known_color::highlight_text, "highlight_text"}, {known_color::hot_track, "hot_track"}, {known_color::inactive_border, "inactive_border"}, {known_color::inactive_caption, "inactive_caption"}, {known_color::inactive_caption_text, "inactive_caption_text"}, {known_color::info, "info"}, {known_color::info_text, "info_text"}, {known_color::menu, "menu"}, {known_color::menu_text, "menu_text"}, {known_color::scroll_bar, "scroll_bar"}, {known_color::window, "window"}, {known_color::window_frame, "window_frame"}, {known_color::window_text, "window_text"}, {known_color::transparent, "transparent"}, {known_color::alice_blue, "alice_blue"}, {known_color::antique_white, "antique_white"}, {known_color::aqua, "aqua"}, {known_color::aquamarine, "aquamarine"}, {known_color::azure, "azure"}, {known_color::beige, "beige"}, {known_color::bisque, "bisque"}, {known_color::black, "black"}, {known_color::blanched_almond, "blanched_almond"}, {known_color::blue, "blue"}, {known_color::blue_violet, "blue_violet"}, {known_color::brown, "brown"}, {known_color::burly_wood, "burly_wood"}, {known_color::cadet_blue, "cadet_blue"}, {known_color::chartreuse, "chartreuse"}, {known_color::chocolate, "chocolate"}, {known_color::coral, "coral"}, {known_color::cornflower_blue, "cornflower_blue"}, {known_color::cornsilk, "cornsilk"}, {known_color::crimson, "crimson"}, {known_color::cyan, "cyan"}, {known_color::dark_blue, "dark_blue"}, {known_color::dark_cyan, "dark_cyan"}, {known_color::dark_goldenrod, "dark_goldenrod"}, {known_color::dark_gray, "dark_gray"}, {known_color::dark_green, "dark_green"}, {known_color::dark_khaki, "dark_khaki"}, {known_color::dark_magenta, "dark_magenta"}, {known_color::dark_olive_green, "dark_olive_green"}, {known_color::dark_orange, "dark_orange"}, {known_color::dark_orchid, "dark_orchid"}, {known_color::dark_red, "dark_red"}, {known_color::dark_salmon, "dark_salmon"}, {known_color::dark_sea_green, "dark_sea_green"}, {known_color::dark_slate_blue, "dark_slate_blue"}, {known_color::dark_slate_gray, "dark_slate_gray"}, {known_color::dark_turquoise, "dark_turquoise"}, {known_color::dark_violet, "dark_violet"}, {known_color::deep_pink, "deep_pink"}, {known_color::deep_sky_blue, "deep_sky_blue"}, {known_color::dim_gray, "dim_gray"}, {known_color::dodger_blue, "dodger_blue"}, {known_color::firebrick, "firebrick"}, {known_color::floral_white, "floral_white"}, {known_color::forest_green, "forest_green"}, {known_color::fuchsia, "fuchsia"}, {known_color::gainsboro, "gainsboro"}, {known_color::ghost_white, "ghost_white"}, {known_color::gold, "gold"}, {known_color::goldenrod, "goldenrod"}, {known_color::gray, "gray"}, {known_color::green, "green"}, {known_color::green_yellow, "green_yellow"}, {known_color::honeydew, "honeydew"}, {known_color::hot_pink, "hot_pink"}, {known_color::indian_red, "indian_red"}, {known_color::indigo, "indigo"}, {known_color::ivory, "ivory"}, {known_color::khaki, "khaki"}, {known_color::lavender, "lavender"}, {known_color::lavender_blush, "lavender_blush"}, {known_color::lawn_green, "lawn_green"}, {known_color::lemon_chiffon, "lemon_chiffon"}, {known_color::light_blue, "light_blue"}, {known_color::light_coral, "light_coral"}, {known_color::light_cyan, "light_cyan"}, {known_color::light_goldenrod_yellow, "light_goldenrod_yellow"}, {known_color::light_gray, "light_gray"}, {known_color::light_green, "light_green"}, {known_color::light_pink, "light_pink"}, {known_color::light_salmon, "light_salmon"}, {known_color::light_sea_green, "light_sea_green"}, {known_color::light_sky_blue, "light_sky_blue"}, {known_color::light_slate_gray, "light_slate_gray"}, {known_color::light_steel_blue, "light_steel_blue"}, {known_color::light_yellow, "light_yellow"}, {known_color::lime, "lime"}, {known_color::lime_green, "lime_green"}, {known_color::linen, "linen"}, {known_color::magenta, "magenta"}, {known_color::maroon, "maroon"}, {known_color::medium_aquamarine, "medium_aquamarine"}, {known_color::medium_blue, "medium_blue"}, {known_color::medium_orchid, "medium_orchid"}, {known_color::medium_purple, "medium_purple"}, {known_color::medium_sea_green, "medium_sea_green"}, {known_color::medium_slate_blue, "medium_slate_blue"}, {known_color::medium_spring_green, "medium_spring_green"}, {known_color::medium_turquoise, "medium_turquoise"}, {known_color::medium_violet_red, "medium_violet_red"}, {known_color::midnight_blue, "midnight_blue"}, {known_color::mint_cream, "mint_cream"}, {known_color::misty_rose, "misty_rose"}, {known_color::moccasin, "moccasin"}, {known_color::navajo_white, "navajo_white"}, {known_color::navy, "navy"}, {known_color::old_lace, "old_lace"}, {known_color::olive, "olive"}, {known_color::olive_drab, "olive_drab"}, {known_color::orange, "orange"}, {known_color::orange_red, "orange_red"}, {known_color::orchid, "orchid"}, {known_color::pale_goldenrod, "pale_goldenrod"}, {known_color::pale_green, "pale_green"}, {known_color::pale_turquoise, "pale_turquoise"}, {known_color::pale_violet_red, "pale_violet_red"}, {known_color::papaya_whip, "papaya_whip"}, {known_color::peach_puff, "peach_puff"}, {known_color::peru, "peru"}, {known_color::pink, "pink"}, {known_color::plum, "plum"}, {known_color::powder_blue, "powder_blue"}, {known_color::purple, "purple"}, {known_color::rebecca_purple, "rebecca_purple"}, {known_color::red, "red"}, {known_color::rosy_brown, "rosy_brown"}, {known_color::royal_blue, "royal_blue"}, {known_color::saddle_brown, "saddle_brown"}, {known_color::salmon, "salmon"}, {known_color::sandy_brown, "sandy_brown"}, {known_color::sea_green, "sea_green"}, {known_color::sea_shell, "sea_shell"}, {known_color::sienna, "sienna"}, {known_color::silver, "silver"}, {known_color::sky_blue, "sky_blue"}, {known_color::slate_blue, "slate_blue"}, {known_color::slate_gray, "slate_gray"}, {known_color::snow, "snow"}, {known_color::spring_green, "spring_green"}, {known_color::steel_blue, "steel_blue"}, {known_color::tan, "tan"}, {known_color::teal, "teal"}, {known_color::thistle, "thistle"}, {known_color::tomato, "tomato"}, {known_color::turquoise, "turquoise"}, {known_color::violet, "violet"}, {known_color::wheat, "wheat"}, {known_color::white, "white"}, {known_color::white_smoke, "white_smoke"}, {known_color::yellow, "yellow"}, {known_color::yellow_green, "yellow_green"}, {known_color::button_face, "button_face"}, {known_color::button_highlight, "button_highlight"}, {known_color::button_shadow, "button_shadow"}, {known_color::gradient_active_caption, "gradient_active_caption"}, {known_color::gradient_inactive_caption, "gradient_inactive_caption"}, {known_color::menu_bar, "menu_bar"}, {known_color::menu_highlight, "menu_highlight"}, {known_color::accent, "accent"}, {known_color::accent_text, "accent_text"}, {known_color::text_box, "text_box"}, {known_color::text_box_text, "text_box_text"}});}
    inline std::wostream& operator<<(std::wostream& os, known_color value) {return os << to_string(value, {{known_color::active_border, L"active_border"}, {known_color::active_caption, L"active_caption"}, {known_color::active_caption_text, L"active_caption_text"}, {known_color::app_workspace, L"app_workspace"}, {known_color::control, L"control"}, {known_color::control_dark, L"control_dark"}, {known_color::control_dark_dark, L"control_dark_dark"}, {known_color::control_light, L"control_light"}, {known_color::control_light_light, L"control_light_light"}, {known_color::control_text, L"control_text"}, {known_color::desktop, L"desktop"}, {known_color::gray_text, L"gray_text"}, {known_color::highlight, L"highlight"}, {known_color::highlight_text, L"highlight_text"}, {known_color::hot_track, L"hot_track"}, {known_color::inactive_border, L"inactive_border"}, {known_color::inactive_caption, L"inactive_caption"}, {known_color::inactive_caption_text, L"inactive_caption_text"}, {known_color::info, L"info"}, {known_color::info_text, L"info_text"}, {known_color::menu, L"menu"}, {known_color::menu_text, L"menu_text"}, {known_color::scroll_bar, L"scroll_bar"}, {known_color::window, L"window"}, {known_color::window_frame, L"window_frame"}, {known_color::window_text, L"window_text"}, {known_color::transparent, L"transparent"}, {known_color::alice_blue, L"alice_blue"}, {known_color::antique_white, L"antique_white"}, {known_color::aqua, L"aqua"}, {known_color::aquamarine, L"aquamarine"}, {known_color::azure, L"azure"}, {known_color::beige, L"beige"}, {known_color::bisque, L"bisque"}, {known_color::black, L"black"}, {known_color::blanched_almond, L"blanched_almond"}, {known_color::blue, L"blue"}, {known_color::blue_violet, L"blue_violet"}, {known_color::brown, L"brown"}, {known_color::burly_wood, L"burly_wood"}, {known_color::cadet_blue, L"cadet_blue"}, {known_color::chartreuse, L"chartreuse"}, {known_color::chocolate, L"chocolate"}, {known_color::coral, L"coral"}, {known_color::cornflower_blue, L"cornflower_blue"}, {known_color::cornsilk, L"cornsilk"}, {known_color::crimson, L"crimson"}, {known_color::cyan, L"cyan"}, {known_color::dark_blue, L"dark_blue"}, {known_color::dark_cyan, L"dark_cyan"}, {known_color::dark_goldenrod, L"dark_goldenrod"}, {known_color::dark_gray, L"dark_gray"}, {known_color::dark_green, L"dark_green"}, {known_color::dark_khaki, L"dark_khaki"}, {known_color::dark_magenta, L"dark_magenta"}, {known_color::dark_olive_green, L"dark_oliveGreen"}, {known_color::dark_orange, L"dark_orange"}, {known_color::dark_orchid, L"dark_orchid"}, {known_color::dark_red, L"dark_red"}, {known_color::dark_salmon, L"dark_salmon"}, {known_color::dark_sea_green, L"dark_sea_green"}, {known_color::dark_slate_blue, L"dark_slate_blue"}, {known_color::dark_slate_gray, L"dark_slate_gray"}, {known_color::dark_turquoise, L"dark_turquoise"}, {known_color::dark_violet, L"dark_violet"}, {known_color::deep_pink, L"deep_pink"}, {known_color::deep_sky_blue, L"deep_sky_blue"}, {known_color::dim_gray, L"dim_gray"}, {known_color::dodger_blue, L"dodger_blue"}, {known_color::firebrick, L"firebrick"}, {known_color::floral_white, L"floral_white"}, {known_color::forest_green, L"forest_green"}, {known_color::fuchsia, L"fuchsia"}, {known_color::gainsboro, L"gainsboro"}, {known_color::ghost_white, L"ghost_white"}, {known_color::gold, L"gold"}, {known_color::goldenrod, L"goldenrod"}, {known_color::gray, L"gray"}, {known_color::green, L"green"}, {known_color::green_yellow, L"green_yellow"}, {known_color::honeydew, L"honeydew"}, {known_color::hot_pink, L"hot_pink"}, {known_color::indian_red, L"indian_red"}, {known_color::indigo, L"indigo"}, {known_color::ivory, L"ivory"}, {known_color::khaki, L"khaki"}, {known_color::lavender, L"lavender"}, {known_color::lavender_blush, L"lavender_blush"}, {known_color::lawn_green, L"lawn_green"}, {known_color::lemon_chiffon, L"lemon_chiffon"}, {known_color::light_blue, L"light_blue"}, {known_color::light_coral, L"light_coral"}, {known_color::light_cyan, L"light_cyan"}, {known_color::light_goldenrod_yellow, L"light_goldenrod_yellow"}, {known_color::light_gray, L"light_gray"}, {known_color::light_green, L"light_green"}, {known_color::light_pink, L"light_pink"}, {known_color::light_salmon, L"light_salmon"}, {known_color::light_sea_green, L"light_sea_green"}, {known_color::light_sky_blue, L"light_sky_blue"}, {known_color::light_slate_gray, L"light_slate_gray"}, {known_color::light_steel_blue, L"light_steel_blue"}, {known_color::light_yellow, L"light_yellow"}, {known_color::lime, L"lime"}, {known_color::lime_green, L"lime_green"}, {known_color::linen, L"linen"}, {known_color::magenta, L"magenta"}, {known_color::maroon, L"maroon"}, {known_color::medium_aquamarine, L"medium_aquamarine"}, {known_color::medium_blue, L"medium_blue"}, {known_color::medium_purple, L"medium_purple"}, {known_color::medium_sea_green, L"medium_sea_green"}, {known_color::medium_slate_blue, L"medium_slate_blue"}, {known_color::medium_spring_green, L"medium_spring_green"}, {known_color::medium_turquoise, L"medium_turquoise"}, {known_color::medium_violet_red, L"medium_violet_red"}, {known_color::midnight_blue, L"midnight_blue"}, {known_color::mint_cream, L"mint_cream"}, {known_color::moccasin, L"moccasin"}, {known_color::navajo_white, L"navajo_white"}, {known_color::navy, L"navy"}, {known_color::old_lace, L"old_lace"}, {known_color::olive, L"olive"}, {known_color::olive_drab, L"olive_drab"}, {known_color::orange, L"orange"}, {known_color::orange_red, L"orange_red"}, {known_color::orchid, L"orchid"}, {known_color::pale_goldenrod, L"pale_goldenrod"}, {known_color::pale_green, L"pale_green"}, {known_color::pale_turquoise, L"pale_turquoise"}, {known_color::pale_violet_red, L"pale_violet_red"}, {known_color::papaya_whip, L"papaya_whip"}, {known_color::peach_puff, L"peach_puff"}, {known_color::peru, L"peru"}, {known_color::pink, L"pink"}, {known_color::plum, L"plum"}, {known_color::powder_blue, L"powder_blue"}, {known_color::rebecca_purple, L"rebecca_purple"}, {known_color::purple, L"purple"}, {known_color::red, L"red"}, {known_color::rosy_brown, L"rosy_brown"}, {known_color::royal_blue, L"royal_blue"}, {known_color::saddle_brown, L"saddle_brown"}, {known_color::salmon, L"salmon"}, {known_color::sandy_brown, L"sandy_brown"}, {known_color::sea_green, L"sea_green"}, {known_color::sea_shell, L"sea_shell"}, {known_color::sienna, L"sienna"}, {known_color::silver, L"silver"}, {known_color::sky_blue, L"sky_blue"}, {known_color::slate_blue, L"slate_blue"}, {known_color::slate_gray, L"slate_gray"}, {known_color::snow, L"snow"}, {known_color::spring_green, L"spring_green"}, {known_color::steel_blue, L"steel_blue"}, {known_color::tan, L"tan"}, {known_color::teal, L"teal"}, {known_color::thistle, L"thistle"}, {known_color::tomato, L"tomato"}, {known_color::turquoise, L"turquoise"}, {known_color::violet, L"violet"}, {known_color::wheat, L"wheat"}, {known_color::white, L"white"}, {known_color::white_smoke, L"white_smoke"}, {known_color::yellow, L"yellow"}, {known_color::yellow_green, L"yellow_green"}, {known_color::button_face, L"button_face"}, {known_color::button_highlight, L"button_highlight"}, {known_color::button_shadow, L"button_shadow"}, {known_color::gradient_active_caption, L"gradient_active_caption"}, {known_color::gradient_inactive_caption, L"gradient_inactive_caption"}, {known_color::menu_bar, L"menu_bar"}, {known_color::menu_highlight, L"menu_highlight"}, {known_color::accent, L"accent"}, {known_color::accent_text, L"accent_text"}, {known_color::text_box, L"text_box"}, {known_color::text_box_text, L"text_box_text"}});}
    /// @endcond
  }
}
