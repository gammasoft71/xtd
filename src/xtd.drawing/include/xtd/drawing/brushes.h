/// @file
/// @brief Contains xtd::drawing::brushes factory.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/static.h>
#include "../drawing_export.h"
#include "solid_brush.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief brushes for all the standard colors. This class cannot be inherited.
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks The brushes class contains static read-only properties that return a solid_brush object of the color indicated by the property name. You typically do not have to explicitly dispose of the brush returned by a property in this class, unless it is used to construct a new brush.
    class drawing_export_ brushes final static_ {
    public:
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush transparent();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush alice_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush antique_white();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush aqua();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush aquamarine();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush azure();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush beige();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush bisque();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush black();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush blanched_almond();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush blue_violet();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush brown();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush burly_wood();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush cadet_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush chartreuse();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush chocolate();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush coral();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush cornflower_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush cornsilk();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush crimson();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush cyan();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dark_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dark_cyan();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dark_goldenrod();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dark_gray();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dark_green();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dark_khaki();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dark_magenta();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dark_olive_green();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dark_orange();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dark_orchid();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dark_red();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dark_salmon();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dark_sea_green();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dark_slate_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dark_slate_gray();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dark_turquoise();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dark_violet();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush deep_pink();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush deep_sky_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dim_gray();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush dodger_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush firebrick();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush floral_white();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush forest_green();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush fuchsia();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush gainsboro();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush ghost_white();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush gold();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush goldenrod();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush gray();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush green();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush green_yellow();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush honeydew();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush hot_pink();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush indian_red();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush indigo();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush ivory();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush khaki();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush lavender();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush lavender_blush();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush lawn_green();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush lemon_chiffon();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush light_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush light_coral();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush light_cyan();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush light_goldenrod_yellow();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush light_gray();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush light_green();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush light_pink();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush light_salmon();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush light_sea_green();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush light_sky_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush light_slate_gray();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush light_steel_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush light_yellow();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush lime();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush lime_green();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush linen();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush magenta();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush maroon();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush medium_aquamarine();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush medium_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush medium_orchid();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush medium_purple();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush medium_sea_green();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush medium_slate_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush medium_spring_green();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush medium_turquoise();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush medium_violet_red();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush midnight_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush mint_cream();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush misty_rose();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush moccasin();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush navajo_white();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush navy();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush old_lace();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush olive();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush olive_drab();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush orange();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush orange_red();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush orchid();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush pale_goldenrod();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush pale_green();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush pale_turquoise();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush pale_violet_red();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush papaya_whip();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush peach_puff();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush peru();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush pink();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush plum();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush powder_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush purple();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush rebecca_purple();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush red();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush rosy_brown();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush royal_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush saddle_brown();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush salmon();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush sandy_brown();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush sea_green();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush sea_shell();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush sienna();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush silver();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush sky_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush slate_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush slate_gray();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush snow();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush spring_green();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush steel_blue();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush tan();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush teal();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush thistle();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush tomato();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush turquoise();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush violet();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush wheat();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush white();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush white_smoke();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush yellow();
      
      /// @brief A system-defined brush object.
      static xtd::drawing::solid_brush yellow_green();
    };
  }
}
