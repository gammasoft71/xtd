/// @file
/// @brief Contains xtd::drawing::colors factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "color.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief colors for all the standard colors. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ colors final static_
    /// ```
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
      [[nodiscard]] static auto alice_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_antique_white.png
      [[nodiscard]] static auto antique_white() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_aqua.png
      [[nodiscard]] static auto aqua() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_aquamarine.png
      [[nodiscard]] static auto aquamarine() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_azure.png
      [[nodiscard]] static auto azure() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_beige.png
      [[nodiscard]] static auto beige() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_bisque.png
      [[nodiscard]] static auto bisque() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_black.png
      [[nodiscard]] static auto black() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_blanched_almond.png
      [[nodiscard]] static auto blanched_almond() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_blue.png
      [[nodiscard]] static auto blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_blue_violet.png
      [[nodiscard]] static auto blue_violet() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_brown.png
      [[nodiscard]] static auto brown() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_burly_wood.png
      [[nodiscard]] static auto burly_wood() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_cadet_blue.png
      [[nodiscard]] static auto cadet_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_chartreuse.png
      [[nodiscard]] static auto chartreuse() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_chocolate.png
      [[nodiscard]] static auto chocolate() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_coral.png
      [[nodiscard]] static auto coral() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_cornflower_blue.png
      [[nodiscard]] static auto cornflower_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_cornsilk.png
      [[nodiscard]] static auto cornsilk() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_crimson.png
      [[nodiscard]] static auto crimson() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_cyan.png
      [[nodiscard]] static auto cyan() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_blue.png
      [[nodiscard]] static auto dark_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_cyan.png
      [[nodiscard]] static auto dark_cyan() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_goldenrod.png
      [[nodiscard]] static auto dark_goldenrod() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_gray.png
      [[nodiscard]] static auto dark_gray() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_green.png
      [[nodiscard]] static auto dark_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_khaki.png
      [[nodiscard]] static auto dark_khaki() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_magenta.png
      [[nodiscard]] static auto dark_magenta() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_olive_green.png
      [[nodiscard]] static auto dark_olive_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_orange.png
      [[nodiscard]] static auto dark_orange() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_orchid.png
      [[nodiscard]] static auto dark_orchid() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_red.png
      [[nodiscard]] static auto dark_red() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_salmon.png
      [[nodiscard]] static auto dark_salmon() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_sea_green.png
      [[nodiscard]] static auto dark_sea_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_slate_blue.png
      [[nodiscard]] static auto dark_slate_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_slate_gray.png
      [[nodiscard]] static auto dark_slate_gray() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_turquoise.png
      [[nodiscard]] static auto dark_turquoise() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_violet.png
      [[nodiscard]] static auto dark_violet() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_deep_pink.png
      [[nodiscard]] static auto deep_pink() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_deep_sky_blue.png
      [[nodiscard]] static auto deep_sky_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dim_gray.png
      [[nodiscard]] static auto dim_gray() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dodger_blue.png
      [[nodiscard]] static auto dodger_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_firebrick.png
      [[nodiscard]] static auto firebrick() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_floral_white.png
      [[nodiscard]] static auto floral_white() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_forest_green.png
      [[nodiscard]] static auto forest_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_fuchsia.png
      [[nodiscard]] static auto fuchsia() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_gainsboro.png
      [[nodiscard]] static auto gainsboro() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_ghost_white.png
      [[nodiscard]] static auto ghost_white() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_gold.png
      [[nodiscard]] static auto gold() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_goldenrod.png
      [[nodiscard]] static auto goldenrod() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_gray.png
      [[nodiscard]] static auto gray() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_green.png
      [[nodiscard]] static auto green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_green_yellow.png
      [[nodiscard]] static auto green_yellow() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_honeydew.png
      [[nodiscard]] static auto honeydew() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_hot_pink.png
      [[nodiscard]] static auto hot_pink() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_indian_red.png
      [[nodiscard]] static auto indian_red() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_indigo.png
      [[nodiscard]] static auto indigo() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_ivory.png
      [[nodiscard]] static auto ivory() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_khaki.png
      [[nodiscard]] static auto khaki() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_lavender.png
      [[nodiscard]] static auto lavender() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_lavender_blush.png
      [[nodiscard]] static auto lavender_blush() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_lawn_green.png
      [[nodiscard]] static auto lawn_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_lemon_chiffon.png
      [[nodiscard]] static auto lemon_chiffon() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_blue.png
      [[nodiscard]] static auto light_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_coral.png
      [[nodiscard]] static auto light_coral() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_cyan.png
      [[nodiscard]] static auto light_cyan() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_goldenrod_yellow.png
      [[nodiscard]] static auto light_goldenrod_yellow() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_gray.png
      [[nodiscard]] static auto light_gray() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_green.png
      [[nodiscard]] static auto light_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_pink.png
      [[nodiscard]] static auto light_pink() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_salmon.png
      [[nodiscard]] static auto light_salmon() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_sea_green.png
      [[nodiscard]] static auto light_sea_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_sky_blue.png
      [[nodiscard]] static auto light_sky_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_slate_gray.png
      [[nodiscard]] static auto light_slate_gray() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_steel_blue.png
      [[nodiscard]] static auto light_steel_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_yellow.png
      [[nodiscard]] static auto light_yellow() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_lime.png
      [[nodiscard]] static auto lime() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_lime_green.png
      [[nodiscard]] static auto lime_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_linen.png
      [[nodiscard]] static auto linen() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_magenta.png
      [[nodiscard]] static auto magenta() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_maroon.png
      [[nodiscard]] static auto maroon() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_aquamarine.png
      [[nodiscard]] static auto medium_aquamarine() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_blue.png
      [[nodiscard]] static auto medium_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_orchid.png
      [[nodiscard]] static auto medium_orchid() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_purple.png
      [[nodiscard]] static auto medium_purple() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_sea_green.png
      [[nodiscard]] static auto medium_sea_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_slate_blue.png
      [[nodiscard]] static auto medium_slate_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_spring_green.png
      [[nodiscard]] static auto medium_spring_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_turquoise.png
      [[nodiscard]] static auto medium_turquoise() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_turquoise.png
      [[nodiscard]] static auto medium_violet_red() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_midnight_blue.png
      [[nodiscard]] static auto midnight_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_mint_cream.png
      [[nodiscard]] static auto mint_cream() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_misty_rose.png
      [[nodiscard]] static auto misty_rose() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_moccasin.png
      [[nodiscard]] static auto moccasin() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_navajo_white.png
      [[nodiscard]] static auto navajo_white() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_navy.png
      [[nodiscard]] static auto navy() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_old_lace.png
      [[nodiscard]] static auto old_lace() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_olive.png
      [[nodiscard]] static auto olive() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_olive_drab.png
      [[nodiscard]] static auto olive_drab() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_orange.png
      [[nodiscard]] static auto orange() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_orange_red.png
      [[nodiscard]] static auto orange_red() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_orchid.png
      [[nodiscard]] static auto orchid() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_goldenrod.png
      [[nodiscard]] static auto pale_goldenrod() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_green.png
      [[nodiscard]] static auto pale_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_turquoise.png
      [[nodiscard]] static auto pale_turquoise() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_violet_red.png
      [[nodiscard]] static auto pale_violet_red() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_papaya_whip.png
      [[nodiscard]] static auto papaya_whip() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_peach_puff.png
      [[nodiscard]] static auto peach_puff() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_peru.png
      [[nodiscard]] static auto peru() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_pink.png
      [[nodiscard]] static auto pink() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_plum.png
      [[nodiscard]] static auto plum() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_powder_blue.png
      [[nodiscard]] static auto powder_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_purple.png
      [[nodiscard]] static auto purple() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_rebecca_purple.png
      [[nodiscard]] static auto rebecca_purple() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_red.png
      [[nodiscard]] static auto red() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_rosy_brown.png
      [[nodiscard]] static auto rosy_brown() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_royal_blue.png
      [[nodiscard]] static auto royal_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_saddle_brown.png
      [[nodiscard]] static auto saddle_brown() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_salmon.png
      [[nodiscard]] static auto salmon() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_sandy_brown.png
      [[nodiscard]] static auto sandy_brown() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_sea_green.png
      [[nodiscard]] static auto sea_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_sea_shell.png
      [[nodiscard]] static auto sea_shell() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_sienna.png
      [[nodiscard]] static auto sienna() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_silver.png
      [[nodiscard]] static auto silver() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_sky_blue.png
      [[nodiscard]] static auto sky_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_slate_blue.png
      [[nodiscard]] static auto slate_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_slate_gray.png
      [[nodiscard]] static auto slate_gray() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_snow.png
      [[nodiscard]] static auto snow() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_spring_green.png
      [[nodiscard]] static auto spring_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_steel_blue.png
      [[nodiscard]] static auto steel_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_tan.png
      [[nodiscard]] static auto tan() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_teal.png
      [[nodiscard]] static auto teal() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_thistle.png
      [[nodiscard]] static auto thistle() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_tomato.png
      [[nodiscard]] static auto tomato() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_transparent.png
      [[nodiscard]] static auto transparent() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_turquoise.png
      [[nodiscard]] static auto turquoise() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_violet.png
      [[nodiscard]] static auto violet() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_wheat.png
      [[nodiscard]] static auto wheat() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_white.png
      [[nodiscard]] static auto white() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_white_smoke.png
      [[nodiscard]] static auto white_smoke() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_yellow.png
      [[nodiscard]] static auto yellow() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_yellow_green.png
      [[nodiscard]] static auto yellow_green() noexcept -> xtd::drawing::color;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of colors.
      [[nodiscard]] static auto get_colors() noexcept -> const xtd::array<xtd::drawing::color>&;
      
      /// @brief Gets an array of color names.
      [[nodiscard]] static auto get_color_names() noexcept -> const xtd::array<xtd::string>&;
      /// @}
    };
  }
}
