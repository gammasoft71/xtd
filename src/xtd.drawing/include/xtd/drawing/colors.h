/// @file
/// @brief Contains xtd::drawing::colors factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "color.h"
#include <xtd/static>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief colors for all the standard colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    /// @remarks The color objects returned by this class are immutable, meaning their properties cannot be changed.
    class drawing_export_ colors final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_alice_blue.png
      static xtd::drawing::color alice_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_antique_white.png
      static xtd::drawing::color antique_white() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_aqua.png
      static xtd::drawing::color aqua() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_aquamarine.png
      static xtd::drawing::color aquamarine() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_azure.png
      static xtd::drawing::color azure() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_beige.png
      static xtd::drawing::color beige() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_bisque.png
      static xtd::drawing::color bisque() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_black.png
      static xtd::drawing::color black() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_blanched_almond.png
      static xtd::drawing::color blanched_almond() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_blue.png
      static xtd::drawing::color blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_blue_violet.png
      static xtd::drawing::color blue_violet() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_brown.png
      static xtd::drawing::color brown() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_burly_wood.png
      static xtd::drawing::color burly_wood() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_cadet_blue.png
      static xtd::drawing::color cadet_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_chartreuse.png
      static xtd::drawing::color chartreuse() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_chocolate.png
      static xtd::drawing::color chocolate() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_coral.png
      static xtd::drawing::color coral() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_cornflower_blue.png
      static xtd::drawing::color cornflower_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_cornsilk.png
      static xtd::drawing::color cornsilk() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_crimson.png
      static xtd::drawing::color crimson() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_cyan.png
      static xtd::drawing::color cyan() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_blue.png
      static xtd::drawing::color dark_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_cyan.png
      static xtd::drawing::color dark_cyan() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_goldenrod.png
      static xtd::drawing::color dark_goldenrod() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_gray.png
      static xtd::drawing::color dark_gray() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_green.png
      static xtd::drawing::color dark_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_khaki.png
      static xtd::drawing::color dark_khaki() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_magenta.png
      static xtd::drawing::color dark_magenta() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_olive_green.png
      static xtd::drawing::color dark_olive_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_orange.png
      static xtd::drawing::color dark_orange() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_orchid.png
      static xtd::drawing::color dark_orchid() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_red.png
      static xtd::drawing::color dark_red() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_salmon.png
      static xtd::drawing::color dark_salmon() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_sea_green.png
      static xtd::drawing::color dark_sea_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_slate_blue.png
      static xtd::drawing::color dark_slate_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_slate_gray.png
      static xtd::drawing::color dark_slate_gray() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_turquoise.png
      static xtd::drawing::color dark_turquoise() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_violet.png
      static xtd::drawing::color dark_violet() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_deep_pink.png
      static xtd::drawing::color deep_pink() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_deep_sky_blue.png
      static xtd::drawing::color deep_sky_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dim_gray.png
      static xtd::drawing::color dim_gray() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dodger_blue.png
      static xtd::drawing::color dodger_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_firebrick.png
      static xtd::drawing::color firebrick() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_floral_white.png
      static xtd::drawing::color floral_white() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_forest_green.png
      static xtd::drawing::color forest_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_fuchsia.png
      static xtd::drawing::color fuchsia() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_gainsboro.png
      static xtd::drawing::color gainsboro() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_ghost_white.png
      static xtd::drawing::color ghost_white() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_gold.png
      static xtd::drawing::color gold() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_goldenrod.png
      static xtd::drawing::color goldenrod() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_gray.png
      static xtd::drawing::color gray() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_green.png
      static xtd::drawing::color green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_green_yellow.png
      static xtd::drawing::color green_yellow() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_honeydew.png
      static xtd::drawing::color honeydew() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_hot_pink.png
      static xtd::drawing::color hot_pink() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_indian_red.png
      static xtd::drawing::color indian_red() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_indigo.png
      static xtd::drawing::color indigo() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_ivory.png
      static xtd::drawing::color ivory() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_khaki.png
      static xtd::drawing::color khaki() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_lavender.png
      static xtd::drawing::color lavender() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_lavender_blush.png
      static xtd::drawing::color lavender_blush() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_lawn_green.png
      static xtd::drawing::color lawn_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_lemon_chiffon.png
      static xtd::drawing::color lemon_chiffon() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_blue.png
      static xtd::drawing::color light_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_coral.png
      static xtd::drawing::color light_coral() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_cyan.png
      static xtd::drawing::color light_cyan() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_goldenrod_yellow.png
      static xtd::drawing::color light_goldenrod_yellow() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_gray.png
      static xtd::drawing::color light_gray() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_green.png
      static xtd::drawing::color light_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_pink.png
      static xtd::drawing::color light_pink() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_salmon.png
      static xtd::drawing::color light_salmon() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_sea_green.png
      static xtd::drawing::color light_sea_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_sky_blue.png
      static xtd::drawing::color light_sky_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_slate_gray.png
      static xtd::drawing::color light_slate_gray() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_steel_blue.png
      static xtd::drawing::color light_steel_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_yellow.png
      static xtd::drawing::color light_yellow() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_lime.png
      static xtd::drawing::color lime() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_lime_green.png
      static xtd::drawing::color lime_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_linen.png
      static xtd::drawing::color linen() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_magenta.png
      static xtd::drawing::color magenta() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_maroon.png
      static xtd::drawing::color maroon() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_aquamarine.png
      static xtd::drawing::color medium_aquamarine() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_blue.png
      static xtd::drawing::color medium_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_orchid.png
      static xtd::drawing::color medium_orchid() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_purple.png
      static xtd::drawing::color medium_purple() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_sea_green.png
      static xtd::drawing::color medium_sea_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_slate_blue.png
      static xtd::drawing::color medium_slate_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_spring_green.png
      static xtd::drawing::color medium_spring_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_turquoise.png
      static xtd::drawing::color medium_turquoise() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_turquoise.png
      static xtd::drawing::color medium_violet_red() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_midnight_blue.png
      static xtd::drawing::color midnight_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_mint_cream.png
      static xtd::drawing::color mint_cream() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_misty_rose.png
      static xtd::drawing::color misty_rose() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_moccasin.png
      static xtd::drawing::color moccasin() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_navajo_white.png
      static xtd::drawing::color navajo_white() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_navy.png
      static xtd::drawing::color navy() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_old_lace.png
      static xtd::drawing::color old_lace() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_olive.png
      static xtd::drawing::color olive() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_olive_drab.png
      static xtd::drawing::color olive_drab() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_orange.png
      static xtd::drawing::color orange() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_orange_red.png
      static xtd::drawing::color orange_red() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_orchid.png
      static xtd::drawing::color orchid() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_goldenrod.png
      static xtd::drawing::color pale_goldenrod() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_green.png
      static xtd::drawing::color pale_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_turquoise.png
      static xtd::drawing::color pale_turquoise() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_violet_red.png
      static xtd::drawing::color pale_violet_red() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_papaya_whip.png
      static xtd::drawing::color papaya_whip() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_peach_puff.png
      static xtd::drawing::color peach_puff() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_peru.png
      static xtd::drawing::color peru() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_pink.png
      static xtd::drawing::color pink() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_plum.png
      static xtd::drawing::color plum() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_powder_blue.png
      static xtd::drawing::color powder_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_purple.png
      static xtd::drawing::color purple() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_rebecca_purple.png
      static xtd::drawing::color rebecca_purple() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_red.png
      static xtd::drawing::color red() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_rosy_brown.png
      static xtd::drawing::color rosy_brown() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_royal_blue.png
      static xtd::drawing::color royal_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_saddle_brown.png
      static xtd::drawing::color saddle_brown() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_salmon.png
      static xtd::drawing::color salmon() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_sandy_brown.png
      static xtd::drawing::color sandy_brown() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_sea_green.png
      static xtd::drawing::color sea_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_sea_shell.png
      static xtd::drawing::color sea_shell() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_sienna.png
      static xtd::drawing::color sienna() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_silver.png
      static xtd::drawing::color silver() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_sky_blue.png
      static xtd::drawing::color sky_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_slate_blue.png
      static xtd::drawing::color slate_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_slate_gray.png
      static xtd::drawing::color slate_gray() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_snow.png
      static xtd::drawing::color snow() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_spring_green.png
      static xtd::drawing::color spring_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_steel_blue.png
      static xtd::drawing::color steel_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_tan.png
      static xtd::drawing::color tan() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_teal.png
      static xtd::drawing::color teal() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_thistle.png
      static xtd::drawing::color thistle() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_tomato.png
      static xtd::drawing::color tomato() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_transparent.png
      static xtd::drawing::color transparent() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_turquoise.png
      static xtd::drawing::color turquoise() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_violet.png
      static xtd::drawing::color violet() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_wheat.png
      static xtd::drawing::color wheat() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_white.png
      static xtd::drawing::color white() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_white_smoke.png
      static xtd::drawing::color white_smoke() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_yellow.png
      static xtd::drawing::color yellow() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_yellow_green.png
      static xtd::drawing::color yellow_green() noexcept;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of colors.
      static const std::vector<xtd::drawing::color>& get_colors() noexcept;
      
      /// @brief Gets an array of color names.
      static const std::vector<xtd::ustring>& get_color_names() noexcept;
      /// @}
    };
  }
}
