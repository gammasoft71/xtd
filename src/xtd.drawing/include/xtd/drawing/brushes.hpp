/// @file
/// @brief Contains xtd::drawing::brushes factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "solid_brush.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Brushes for all the standard colors. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ brushes final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::brushes
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing brushes
    /// @remarks The brushes class contains static read-only properties that return a solid_brush object of the color indicated by the property name.
    class drawing_export_ brushes final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto transparent() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto alice_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto antique_white() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto aqua() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto aquamarine() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto azure() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto beige() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto bisque() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto black() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto blanched_almond() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto blue_violet() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto brown() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto burly_wood() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto cadet_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto chartreuse() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto chocolate() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto coral() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto cornflower_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto cornsilk() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto crimson() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto cyan() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dark_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dark_cyan() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dark_goldenrod() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dark_gray() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dark_green() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dark_khaki() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dark_magenta() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dark_olive_green() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dark_orange() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dark_orchid() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dark_red() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dark_salmon() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dark_sea_green() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dark_slate_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dark_slate_gray() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dark_turquoise() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dark_violet() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto deep_pink() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto deep_sky_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dim_gray() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto dodger_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto firebrick() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto floral_white() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto forest_green() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto fuchsia() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto gainsboro() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto ghost_white() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto gold() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto goldenrod() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto gray() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto green() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto green_yellow() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto honeydew() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto hot_pink() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto indian_red() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto indigo() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto ivory() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto khaki() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto lavender() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto lavender_blush() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto lawn_green() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto lemon_chiffon() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto light_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto light_coral() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto light_cyan() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto light_goldenrod_yellow() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto light_gray() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto light_green() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto light_pink() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto light_salmon() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto light_sea_green() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto light_sky_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto light_slate_gray() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto light_steel_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto light_yellow() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto lime() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto lime_green() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto linen() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto magenta() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto maroon() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto medium_aquamarine() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto medium_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto medium_orchid() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto medium_purple() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto medium_sea_green() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto medium_slate_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto medium_spring_green() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto medium_turquoise() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto medium_violet_red() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto midnight_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto mint_cream() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto misty_rose() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto moccasin() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto navajo_white() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto navy() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto old_lace() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto olive() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto olive_drab() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto orange() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto orange_red() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto orchid() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto pale_goldenrod() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto pale_green() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto pale_turquoise() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto pale_violet_red() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto papaya_whip() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto peach_puff() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto peru() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto pink() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto plum() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto powder_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto purple() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto rebecca_purple() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto red() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto rosy_brown() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto royal_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto saddle_brown() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto salmon() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto sandy_brown() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto sea_green() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto sea_shell() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto sienna() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto silver() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto sky_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto slate_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto slate_gray() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto snow() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto spring_green() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto steel_blue() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto tan() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto teal() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto thistle() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto tomato() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto turquoise() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto violet() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto wheat() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto white() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto white_smoke() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto yellow() -> xtd::drawing::solid_brush;
      
      /// @brief A system-defined brush object.
      [[nodiscard]] static auto yellow_green() -> xtd::drawing::solid_brush;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of brushes.
      [[nodiscard]] static auto get_brushes() -> const xtd::array<xtd::drawing::solid_brush>&;
      /// @}
    };
  }
}
