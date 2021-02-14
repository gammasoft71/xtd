#pragma once
#include <xtd/static.h>
#include "../drawing_export.h"
#include "color.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief colors for all the standard colors. This class cannot be inherited.
    /// @remarks The color objects returned by this class are immutable, meaning their properties cannot be changed.
    class drawing_export_ colors final static_ {
    public:
      // A system-defined color object.
      static xtd::drawing::color transparent();
      
      // A system-defined color object.
      static xtd::drawing::color alice_blue();
      
      // A system-defined color object.
      static xtd::drawing::color antique_white();
      
      // A system-defined color object.
      static xtd::drawing::color aqua();
      
      // A system-defined color object.
      static xtd::drawing::color aquamarine();
      
      // A system-defined color object.
      static xtd::drawing::color azure();
      
      // A system-defined color object.
      static xtd::drawing::color beige();
      
      // A system-defined color object.
      static xtd::drawing::color bisque();
      
      // A system-defined color object.
      static xtd::drawing::color black();
      
      // A system-defined color object.
      static xtd::drawing::color blanched_almond();
      
      // A system-defined color object.
      static xtd::drawing::color blue();
      
      // A system-defined color object.
      static xtd::drawing::color blue_violet();
      
      // A system-defined color object.
      static xtd::drawing::color brown();
      
      // A system-defined color object.
      static xtd::drawing::color burly_wood();
      
      // A system-defined color object.
      static xtd::drawing::color cadet_blue();
      
      // A system-defined color object.
      static xtd::drawing::color chartreuse();
      
      // A system-defined color object.
      static xtd::drawing::color chocolate();
      
      // A system-defined color object.
      static xtd::drawing::color coral();
      
      // A system-defined color object.
      static xtd::drawing::color cornflower_blue();
      
      // A system-defined color object.
      static xtd::drawing::color cornsilk();
      
      // A system-defined color object.
      static xtd::drawing::color crimson();
      
      // A system-defined color object.
      static xtd::drawing::color cyan();
      
      // A system-defined color object.
      static xtd::drawing::color dark_blue();
      
      // A system-defined color object.
      static xtd::drawing::color dark_cyan();
      
      // A system-defined color object.
      static xtd::drawing::color dark_goldenrod();
      
      // A system-defined color object.
      static xtd::drawing::color dark_gray();
      
      // A system-defined color object.
      static xtd::drawing::color dark_green();
      
      // A system-defined color object.
      static xtd::drawing::color dark_khaki();
      
      // A system-defined color object.
      static xtd::drawing::color dark_magenta();
      
      // A system-defined color object.
      static xtd::drawing::color dark_olive_green();
      
      // A system-defined color object.
      static xtd::drawing::color dark_orange();
      
      // A system-defined color object.
      static xtd::drawing::color dark_orchid();
      
      // A system-defined color object.
      static xtd::drawing::color dark_red();
      
      // A system-defined color object.
      static xtd::drawing::color dark_salmon();
      
      // A system-defined color object.
      static xtd::drawing::color dark_sea_green();
      
      // A system-defined color object.
      static xtd::drawing::color dark_slate_blue();
      
      // A system-defined color object.
      static xtd::drawing::color dark_slate_gray();
      
      // A system-defined color object.
      static xtd::drawing::color dark_turquoise();
      
      // A system-defined color object.
      static xtd::drawing::color dark_violet();
      
      // A system-defined color object.
      static xtd::drawing::color deep_pink();
      
      // A system-defined color object.
      static xtd::drawing::color deep_sky_blue();
      
      // A system-defined color object.
      static xtd::drawing::color dim_gray();
      
      // A system-defined color object.
      static xtd::drawing::color dodger_blue();
      
      // A system-defined color object.
      static xtd::drawing::color firebrick();
      
      // A system-defined color object.
      static xtd::drawing::color floral_white();
      
      // A system-defined color object.
      static xtd::drawing::color forest_green();
      
      // A system-defined color object.
      static xtd::drawing::color fuchsia();
      
      // A system-defined color object.
      static xtd::drawing::color gainsboro();
      
      // A system-defined color object.
      static xtd::drawing::color ghost_white();
      
      // A system-defined color object.
      static xtd::drawing::color gold();
      
      // A system-defined color object.
      static xtd::drawing::color goldenrod();
      
      // A system-defined color object.
      static xtd::drawing::color gray();
      
      // A system-defined color object.
      static xtd::drawing::color green();
      
      // A system-defined color object.
      static xtd::drawing::color green_yellow();
      
      // A system-defined color object.
      static xtd::drawing::color honeydew();
      
      // A system-defined color object.
      static xtd::drawing::color hot_pink();
      
      // A system-defined color object.
      static xtd::drawing::color indian_red();
      
      // A system-defined color object.
      static xtd::drawing::color indigo();
      
      // A system-defined color object.
      static xtd::drawing::color ivory();
      
      // A system-defined color object.
      static xtd::drawing::color khaki();
      
      // A system-defined color object.
      static xtd::drawing::color lavender();
      
      // A system-defined color object.
      static xtd::drawing::color lavender_blush();
      
      // A system-defined color object.
      static xtd::drawing::color lawn_green();
      
      // A system-defined color object.
      static xtd::drawing::color lemon_chiffon();
      
      // A system-defined color object.
      static xtd::drawing::color light_blue();
      
      // A system-defined color object.
      static xtd::drawing::color light_coral();
      
      // A system-defined color object.
      static xtd::drawing::color light_cyan();
      
      // A system-defined color object.
      static xtd::drawing::color light_goldenrod_yellow();
      
      // A system-defined color object.
      static xtd::drawing::color light_gray();
      
      // A system-defined color object.
      static xtd::drawing::color light_green();
      
      // A system-defined color object.
      static xtd::drawing::color light_pink();
      
      // A system-defined color object.
      static xtd::drawing::color light_salmon();
      
      // A system-defined color object.
      static xtd::drawing::color light_sea_green();
      
      // A system-defined color object.
      static xtd::drawing::color light_sky_blue();
      
      // A system-defined color object.
      static xtd::drawing::color light_slate_gray();
      
      // A system-defined color object.
      static xtd::drawing::color light_steel_blue();
      
      // A system-defined color object.
      static xtd::drawing::color light_yellow();
      
      // A system-defined color object.
      static xtd::drawing::color lime();
      
      // A system-defined color object.
      static xtd::drawing::color lime_green();
      
      // A system-defined color object.
      static xtd::drawing::color linen();
      
      // A system-defined color object.
      static xtd::drawing::color magenta();
      
      // A system-defined color object.
      static xtd::drawing::color maroon();
      
      // A system-defined color object.
      static xtd::drawing::color medium_aquamarine();
      
      // A system-defined color object.
      static xtd::drawing::color medium_blue();
      
      // A system-defined color object.
      static xtd::drawing::color medium_orchid();
      
      // A system-defined color object.
      static xtd::drawing::color medium_purple();
      
      // A system-defined color object.
      static xtd::drawing::color medium_sea_green();
      
      // A system-defined color object.
      static xtd::drawing::color medium_slate_blue();
      
      // A system-defined color object.
      static xtd::drawing::color medium_spring_green();
      
      // A system-defined color object.
      static xtd::drawing::color medium_turquoise();
      
      // A system-defined color object.
      static xtd::drawing::color medium_violet_red();
      
      // A system-defined color object.
      static xtd::drawing::color midnight_blue();
      
      // A system-defined color object.
      static xtd::drawing::color mint_cream();
      
      // A system-defined color object.
      static xtd::drawing::color misty_rose();
      
      // A system-defined color object.
      static xtd::drawing::color moccasin();
      
      // A system-defined color object.
      static xtd::drawing::color navajo_white();
      
      // A system-defined color object.
      static xtd::drawing::color navy();
      
      // A system-defined color object.
      static xtd::drawing::color old_lace();
      
      // A system-defined color object.
      static xtd::drawing::color olive();
      
      // A system-defined color object.
      static xtd::drawing::color olive_drab();
      
      // A system-defined color object.
      static xtd::drawing::color orange();
      
      // A system-defined color object.
      static xtd::drawing::color orange_red();
      
      // A system-defined color object.
      static xtd::drawing::color orchid();
      
      // A system-defined color object.
      static xtd::drawing::color pale_goldenrod();
      
      // A system-defined color object.
      static xtd::drawing::color pale_green();
      
      // A system-defined color object.
      static xtd::drawing::color pale_turquoise();
      
      // A system-defined color object.
      static xtd::drawing::color pale_violet_red();
      
      // A system-defined color object.
      static xtd::drawing::color papaya_whip();
      
      // A system-defined color object.
      static xtd::drawing::color peach_puff();
      
      // A system-defined color object.
      static xtd::drawing::color peru();
      
      // A system-defined color object.
      static xtd::drawing::color pink();
      
      // A system-defined color object.
      static xtd::drawing::color plum();
      
      // A system-defined color object.
      static xtd::drawing::color powder_blue();
      
      // A system-defined color object.
      static xtd::drawing::color purple();
      
      // A system-defined color object.
      static xtd::drawing::color rebecca_purple();
      
      // A system-defined color object.
      static xtd::drawing::color red();
      
      // A system-defined color object.
      static xtd::drawing::color rosy_brown();
      
      // A system-defined color object.
      static xtd::drawing::color royal_blue();
      
      // A system-defined color object.
      static xtd::drawing::color saddle_brown();
      
      // A system-defined color object.
      static xtd::drawing::color salmon();
      
      // A system-defined color object.
      static xtd::drawing::color sandy_brown();
      
      // A system-defined color object.
      static xtd::drawing::color sea_green();
      
      // A system-defined color object.
      static xtd::drawing::color sea_shell();
      
      // A system-defined color object.
      static xtd::drawing::color sienna();
      
      // A system-defined color object.
      static xtd::drawing::color silver();
      
      // A system-defined color object.
      static xtd::drawing::color sky_blue();
      
      // A system-defined color object.
      static xtd::drawing::color slate_blue();
      
      // A system-defined color object.
      static xtd::drawing::color slate_gray();
      
      // A system-defined color object.
      static xtd::drawing::color snow();
      
      // A system-defined color object.
      static xtd::drawing::color spring_green();
      
      // A system-defined color object.
      static xtd::drawing::color steel_blue();
      
      // A system-defined color object.
      static xtd::drawing::color tan();
      
      // A system-defined color object.
      static xtd::drawing::color teal();
      
      // A system-defined color object.
      static xtd::drawing::color thistle();
      
      // A system-defined color object.
      static xtd::drawing::color tomato();
      
      // A system-defined color object.
      static xtd::drawing::color turquoise();
      
      // A system-defined color object.
      static xtd::drawing::color violet();
      
      // A system-defined color object.
      static xtd::drawing::color wheat();
      
      // A system-defined color object.
      static xtd::drawing::color white();
      
      // A system-defined color object.
      static xtd::drawing::color white_smoke();
      
      // A system-defined color object.
      static xtd::drawing::color yellow();
      
      // A system-defined color object.
      static xtd::drawing::color yellow_green();
    };
  }
}
