#pragma once
#include <xtd/static.h>
#include "pen.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief pens for all the standard colors. This class cannot be inherited.
    /// @remarks The pen objects returned by this class are immutable, meaning their properties cannot be changed.
    class pens static_ {
    public:
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen transparent();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen alice_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen antique_white();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen aqua();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen aquamarine();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen azure();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen beige();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen bisque();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen black();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen blanched_almond();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen blue_violet();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen brown();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen burly_wood();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen cadet_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen chartreuse();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen chocolate();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen coral();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen cornflower_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen cornsilk();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen crimson();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen cyan();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dark_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dark_cyan();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dark_goldenrod();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dark_gray();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dark_green();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dark_khaki();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dark_magenta();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dark_olive_green();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dark_orange();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dark_orchid();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dark_red();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dark_salmon();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dark_sea_green();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dark_slate_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dark_slate_gray();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dark_turquoise();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dark_violet();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen deep_pink();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen deep_sky_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dim_gray();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen dodger_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen firebrick();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen floral_white();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen forest_green();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen fuchsia();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen gainsboro();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen ghost_white();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen gold();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen goldenrod();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen gray();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen green();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen green_yellow();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen honeydew();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen hot_pink();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen indian_red();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen indigo();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen ivory();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen khaki();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen lavender();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen lavender_blush();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen lawn_green();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen lemon_chiffon();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen light_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen light_coral();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen light_cyan();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen light_goldenrod_yellow();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen light_gray();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen light_green();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen light_pink();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen light_salmon();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen light_sea_green();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen light_sky_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen light_slate_gray();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen light_steel_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen light_yellow();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen lime();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen lime_green();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen linen();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen magenta();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen maroon();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen medium_aquamarine();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen medium_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen medium_orchid();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen medium_purple();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen medium_sea_green();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen medium_slate_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen medium_spring_green();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen medium_turquoise();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen medium_violet_red();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen midnight_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen mint_cream();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen misty_rose();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen moccasin();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen navajo_white();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen navy();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen old_lace();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen olive();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen olive_drab();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen orange();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen orange_red();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen orchid();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen pale_goldenrod();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen pale_green();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen pale_turquoise();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen pale_violet_red();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen papaya_whip();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen peach_puff();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen peru();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen pink();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen plum();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen powder_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen purple();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen rebecca_purple();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen red();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen rosy_brown();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen royal_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen saddle_brown();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen salmon();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen sandy_brown();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen sea_green();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen sea_shell();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen sienna();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen silver();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen sky_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen slate_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen slate_gray();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen snow();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen spring_green();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen steel_blue();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen tan();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen teal();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen thistle();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen tomato();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen turquoise();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen violet();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen wheat();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen white();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen white_smoke();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen yellow();
      
      // A system-defined pen object with a width of 1.
      static xtd::drawing::pen yellow_green();
    };
  }
}
