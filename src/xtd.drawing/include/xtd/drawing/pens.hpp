/// @file
/// @brief Contains xtd::drawing::pens factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "pen.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief pens for all the standard colors. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ pens final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::pens
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing pens
    /// @remarks The pen objects returned by this class are immutable, meaning their properties cannot be changed.
    class drawing_export_ pens final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto transparent() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto alice_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto antique_white() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto aqua() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto aquamarine() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto azure() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto beige() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto bisque() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto black() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto blanched_almond() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto blue_violet() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto brown() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto burly_wood() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto cadet_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto chartreuse() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto chocolate() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto coral() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto cornflower_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto cornsilk() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto crimson() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto cyan() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dark_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dark_cyan() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dark_goldenrod() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dark_gray() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dark_green() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dark_khaki() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dark_magenta() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dark_olive_green() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dark_orange() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dark_orchid() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dark_red() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dark_salmon() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dark_sea_green() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dark_slate_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dark_slate_gray() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dark_turquoise() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dark_violet() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto deep_pink() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto deep_sky_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dim_gray() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto dodger_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto firebrick() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto floral_white() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto forest_green() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto fuchsia() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto gainsboro() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto ghost_white() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto gold() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto goldenrod() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto gray() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto green() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto green_yellow() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto honeydew() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto hot_pink() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto indian_red() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto indigo() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto ivory() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto khaki() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto lavender() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto lavender_blush() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto lawn_green() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto lemon_chiffon() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto light_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto light_coral() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto light_cyan() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto light_goldenrod_yellow() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto light_gray() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto light_green() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto light_pink() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto light_salmon() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto light_sea_green() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto light_sky_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto light_slate_gray() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto light_steel_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto light_yellow() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto lime() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto lime_green() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto linen() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto magenta() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto maroon() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto medium_aquamarine() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto medium_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto medium_orchid() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto medium_purple() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto medium_sea_green() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto medium_slate_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto medium_spring_green() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto medium_turquoise() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto medium_violet_red() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto midnight_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto mint_cream() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto misty_rose() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto moccasin() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto navajo_white() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto navy() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto old_lace() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto olive() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto olive_drab() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto orange() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto orange_red() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto orchid() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto pale_goldenrod() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto pale_green() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto pale_turquoise() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto pale_violet_red() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto papaya_whip() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto peach_puff() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto peru() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto pink() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto plum() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto powder_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto purple() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto rebecca_purple() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto red() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto rosy_brown() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto royal_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto saddle_brown() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto salmon() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto sandy_brown() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto sea_green() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto sea_shell() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto sienna() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto silver() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto sky_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto slate_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto slate_gray() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto snow() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto spring_green() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto steel_blue() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto tan() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto teal() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto thistle() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto tomato() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto turquoise() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto violet() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto wheat() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto white() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto white_smoke() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto yellow() -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with a width of 1.
      [[nodiscard]] static auto yellow_green() -> xtd::drawing::pen;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of pens.
      [[nodiscard]] static auto get_pens() -> const xtd::array<xtd::drawing::pen>&;
      /// @}
    };
  }
}
