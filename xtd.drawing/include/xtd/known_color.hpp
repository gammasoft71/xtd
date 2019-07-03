#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies the known system colors.
    /// @see xtd::drawing::color
    enum class known_color {
      /// @brief The system-defined color of the active window's border.
      ActiveBorder = 1,
      /// @brief The system-defined color of the background of the active window's title bar.
      ActiveCaption,
      /// @brief The system-defined color of the text in the active window's title bar.
      ActiveCaptionText,
      /// @brief The system-defined color of the application workspace. The application workspace is the area in a multiple-document view that is not being occupied by documents.
      AppWorkspace,
      /// @brief The system-defined face color of a 3-D element.
      Control,
      /// @brief The system-defined shadow color of a 3-D element. The shadow color is applied to parts of a 3-D element that face away from the light source.
      ControlDark,
      /// @brief The system-defined color that is the dark shadow color of a 3-D element. The dark shadow color is applied to the parts of a 3-D element that are the darkest color.
      ControlDarkDark,
      /// @brief The system-defined color that is the light color of a 3-D element. The light color is applied to parts of a 3-D element that face the light source.
      ControlLight,
      /// @brief The system-defined highlight color of a 3-D element. The highlight color is applied to the parts of a 3-D element that are the lightest color.
      ControlLightLight,
      /// @brief The system-defined color of text in a 3-D element.
      ControlText,
      /// @brief The system-defined color of the desktop.
      Desktop,
      /// @brief The system-defined color of dimmed text. Items in a list that are disabled are displayed in dimmed text.
      GrayText,
      /// @brief The system-defined color of the background of selected items. This includes selected menu items as well as selected text.
      Highlight,
      /// @brief The system-defined color of the text of selected items.
      HighlightText,
      /// @brief The system-defined color used to designate a hot-tracked item. Single-clicking a hot-tracked item executes the item.
      HotTrack,
      /// @brief The system-defined color of an inactive window's border.
      InactiveBorder,
      /// @brief The system-defined color of the background of an inactive window's title bar.
      InactiveCaption,
      /// @brief The system-defined color of the text in an inactive window's title bar.
      InactiveCaptionText,
      /// @brief The system-defined color of the background of a ToolTip.
      Info,
      /// @brief The system-defined color of the text of a ToolTip.
      InfoText,
      /// @brief The system-defined color of a menu's background.
      Menu,
      /// @brief The system-defined color of a menu's text.
      MenuText,
      /// @brief The system-defined color of the background of a scroll bar.
      ScrollBar,
      /// @brief The system-defined color of the background in the client area of a window.
      Window,
      /// @brief The system-defined color of a window frame.
      WindowFrame,
      /// @brief The system-defined color of the text in the client area of a window.
      WindowText,
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
      dark_seaGreen,
      /// @brief A system-defined color.
      dark_slateBlue,
      /// @brief A system-defined color.
      dark_slateGray,
      /// @brief A system-defined color.
      dark_turquoise,
      /// @brief A system-defined color.
      dark_violet,
      /// @brief A system-defined color.
      deep_pink,
      /// @brief A system-defined color.
      DeepSkyBlue,
      /// @brief A system-defined color.
      DimGray,
      /// @brief A system-defined color.
      DodgerBlue,
      /// @brief A system-defined color.
      Firebrick,
      /// @brief A system-defined color.
      FloralWhite,
      /// @brief A system-defined color.
      ForestGreen,
      /// @brief A system-defined color.
      Fuchsia,
      /// @brief A system-defined color.
      Gainsboro,
      /// @brief A system-defined color.
      GhostWhite,
      /// @brief A system-defined color.
      Gold,
      /// @brief A system-defined color.
      Goldenrod,
      /// @brief A system-defined color.
      Gray,
      /// @brief A system-defined color.
      Green,
      /// @brief A system-defined color.
      GreenYellow,
      /// @brief A system-defined color.
      Honeydew,
      /// @brief A system-defined color.
      HotPink,
      /// @brief A system-defined color.
      IndianRed,
      /// @brief A system-defined color.
      Indigo,
      /// @brief A system-defined color.
      Ivory,
      /// @brief A system-defined color.
      Khaki,
      /// @brief A system-defined color.
      Lavender,
      /// @brief A system-defined color.
      LavenderBlush,
      /// @brief A system-defined color.
      LawnGreen,
      /// @brief A system-defined color.
      LemonChiffon,
      /// @brief A system-defined color.
      LightBlue,
      /// @brief A system-defined color.
      LightCoral,
      /// @brief A system-defined color.
      LightCyan,
      /// @brief A system-defined color.
      LightGoldenrodYellow,
      /// @brief A system-defined color.
      LightGray,
      /// @brief A system-defined color.
      LightGreen,
      /// @brief A system-defined color.
      LightPink,
      /// @brief A system-defined color.
      LightSalmon,
      /// @brief A system-defined color.
      LightSeaGreen,
      /// @brief A system-defined color.
      LightSkyBlue,
      /// @brief A system-defined color.
      LightSlateGray,
      /// @brief A system-defined color.
      LightSteelBlue,
      /// @brief A system-defined color.
      LightYellow,
      /// @brief A system-defined color.
      Lime,
      /// @brief A system-defined color.
      LimeGreen,
      /// @brief A system-defined color.
      Linen,
      /// @brief A system-defined color.
      Magenta,
      /// @brief A system-defined color.
      Maroon,
      /// @brief A system-defined color.
      MediumAquamarine,
      /// @brief A system-defined color.
      MediumBlue,
      /// @brief A system-defined color.
      MediumOrchid,
      /// @brief A system-defined color.
      MediumPurple,
      /// @brief A system-defined color.
      MediumSeaGreen,
      /// @brief A system-defined color.
      MediumSlateBlue,
      /// @brief A system-defined color.
      MediumSpringGreen,
      /// @brief A system-defined color.
      MediumTurquoise,
      /// @brief A system-defined color.
      MediumVioletRed,
      /// @brief A system-defined color.
      MidnightBlue,
      /// @brief A system-defined color.
      MintCream,
      /// @brief A system-defined color.
      MistyRose,
      /// @brief A system-defined color.
      Moccasin,
      /// @brief A system-defined color.
      NavajoWhite,
      /// @brief A system-defined color.
      Navy,
      /// @brief A system-defined color.
      OldLace,
      /// @brief A system-defined color.
      Olive,
      /// @brief A system-defined color.
      OliveDrab,
      /// @brief A system-defined color.
      Orange,
      /// @brief A system-defined color.
      OrangeRed,
      /// @brief A system-defined color.
      Orchid,
      /// @brief A system-defined color.
      PaleGoldenrod,
      /// @brief A system-defined color.
      PaleGreen,
      /// @brief A system-defined color.
      PaleTurquoise,
      /// @brief A system-defined color.
      PaleVioletRed,
      /// @brief A system-defined color.
      PapayaWhip,
      /// @brief A system-defined color.
      PeachPuff,
      /// @brief A system-defined color.
      Peru,
      /// @brief A system-defined color.
      Pink,
      /// @brief A system-defined color.
      Plum,
      /// @brief A system-defined color.
      PowderBlue,
      /// @brief A system-defined color.
      Purple,
      /// @brief A system-defined color.
      Red,
      /// @brief A system-defined color.
      RosyBrown,
      /// @brief A system-defined color.
      RoyalBlue,
      /// @brief A system-defined color.
      SaddleBrown,
      /// @brief A system-defined color.
      Salmon,
      /// @brief A system-defined color.
      SandyBrown,
      /// @brief A system-defined color.
      SeaGreen,
      /// @brief A system-defined color.
      SeaShell,
      /// @brief A system-defined color.
      Sienna,
      /// @brief A system-defined color.
      Silver,
      /// @brief A system-defined color.
      SkyBlue,
      /// @brief A system-defined color.
      SlateBlue,
      /// @brief A system-defined color.
      SlateGray,
      /// @brief A system-defined color.
      Snow,
      /// @brief A system-defined color.
      SpringGreen,
      /// @brief A system-defined color.
      SteelBlue,
      /// @brief A system-defined color.
      Tan,
      /// @brief A system-defined color.
      Teal,
      /// @brief A system-defined color.
      Thistle,
      /// @brief A system-defined color.
      Tomato,
      /// @brief A system-defined color.
      Turquoise,
      /// @brief A system-defined color.
      Violet,
      /// @brief A system-defined color.
      Wheat,
      /// @brief A system-defined color.
      White,
      /// @brief A system-defined color.
      WhiteSmoke,
      /// @brief A system-defined color.
      Yellow,
      /// @brief A system-defined color.
      YellowGreen,
      /// @brief The system-defined face color of a 3-D element.
      ButtonFace,
      /// @brief The system-defined color that is the highlight color of a 3-D element. This color is applied to parts of a 3-D element that face the light source.
      ButtonHighlight,
      /// @brief The system-defined color that is the shadow color of a 3-D element. This color is applied to parts of a 3-D element that face away from the light source.
      ButtonShadow,
      /// @brief The system-defined color of the lightest color in the color gradient of an active window's title bar.
      GradientActiveCaption,
      /// @brief The system-defined color of the lightest color in the color gradient of an inactive window's title bar.
      GradientInactiveCaption,
      /// @brief The system-defined color of the background of a menu bar.
      MenuBar,
      /// @brief The system-defined color used to highlight menu items when the menu appears as a flat menu.
      MenuHighlight
    };
  }
}
