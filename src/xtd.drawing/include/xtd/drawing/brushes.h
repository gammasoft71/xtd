#pragma once
#include <xtd/static.h>
#include "solid_brush.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief brushes for all the standard colors. This class cannot be inherited.
    /// @remarks The brushes class contains static read-only properties that return a solid_brush object of the color indicated by the property name. You typically do not have to explicitly dispose of the brush returned by a property in this class, unless it is used to construct a new brush.
    class brushes static_ {
    public:
      // A system-defined brush object.
      static xtd::drawing::solid_brush transparent();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush alice_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush antique_white();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush aqua();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush aquamarine();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush azure();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush beige();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush bisque();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush black();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush blanched_almond();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush blue_violet();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush brown();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush burly_wood();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush cadet_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush chartreuse();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush chocolate();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush coral();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush cornflower_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush cornsilk();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush crimson();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush cyan();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dark_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dark_cyan();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dark_goldenrod();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dark_gray();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dark_green();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dark_khaki();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dark_magenta();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dark_olive_green();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dark_orange();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dark_orchid();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dark_red();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dark_salmon();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dark_sea_green();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dark_slate_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dark_slate_gray();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dark_turquoise();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dark_violet();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush deep_pink();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush deep_sky_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dim_gray();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush dodger_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush firebrick();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush floral_white();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush forest_green();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush fuchsia();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush gainsboro();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush ghost_white();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush gold();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush goldenrod();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush gray();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush green();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush green_yellow();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush honeydew();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush hot_pink();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush indian_red();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush indigo();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush ivory();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush khaki();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush lavender();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush lavender_blush();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush lawn_green();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush lemon_chiffon();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush light_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush light_coral();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush light_cyan();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush light_goldenrod_yellow();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush light_gray();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush light_green();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush light_pink();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush light_salmon();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush light_sea_green();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush light_sky_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush light_slate_gray();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush light_steel_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush light_yellow();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush lime();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush lime_green();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush linen();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush magenta();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush maroon();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush medium_aquamarine();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush medium_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush medium_orchid();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush medium_purple();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush medium_sea_green();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush medium_slate_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush medium_spring_green();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush medium_turquoise();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush medium_violet_red();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush midnight_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush mint_cream();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush misty_rose();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush moccasin();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush navajo_white();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush navy();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush old_lace();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush olive();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush olive_drab();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush orange();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush orange_red();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush orchid();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush pale_goldenrod();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush pale_green();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush pale_turquoise();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush pale_violet_red();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush papaya_whip();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush peach_puff();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush peru();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush pink();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush plum();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush powder_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush purple();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush rebecca_purple();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush red();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush rosy_brown();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush royal_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush saddle_brown();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush salmon();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush sandy_brown();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush sea_green();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush sea_shell();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush sienna();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush silver();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush sky_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush slate_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush slate_gray();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush snow();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush spring_green();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush steel_blue();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush tan();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush teal();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush thistle();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush tomato();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush turquoise();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush violet();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush wheat();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush white();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush white_smoke();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush yellow();
      
      // A system-defined brush object.
      static xtd::drawing::solid_brush yellow_green();
    };
  }
}
