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
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto transparent(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto alice_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto antique_white(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto aqua(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto aquamarine(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto azure(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto beige(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto bisque(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto black(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto blanched_almond(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto blue_violet(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto brown(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto burly_wood(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto cadet_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto chartreuse(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto chocolate(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto coral(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto cornflower_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto cornsilk(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto crimson(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto cyan(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dark_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dark_cyan(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dark_goldenrod(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dark_gray(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dark_green(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dark_khaki(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dark_magenta(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dark_olive_green(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dark_orange(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dark_orchid(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dark_red(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dark_salmon(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dark_sea_green(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dark_slate_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dark_slate_gray(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dark_turquoise(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dark_violet(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto deep_pink(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto deep_sky_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dim_gray(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto dodger_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto firebrick(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto floral_white(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto forest_green(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto fuchsia(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto gainsboro(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto ghost_white(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto gold(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto goldenrod(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto gray(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto green(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto green_yellow(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto honeydew(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto hot_pink(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto indian_red(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto indigo(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto ivory(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto khaki(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto lavender(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto lavender_blush(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto lawn_green(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto lemon_chiffon(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto light_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto light_coral(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto light_cyan(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto light_goldenrod_yellow(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto light_gray(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto light_green(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto light_pink(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto light_salmon(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto light_sea_green(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto light_sky_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto light_slate_gray(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto light_steel_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto light_yellow(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto lime(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto lime_green(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto linen(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto magenta(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto maroon(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto medium_aquamarine(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto medium_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto medium_orchid(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto medium_purple(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto medium_sea_green(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto medium_slate_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto medium_spring_green(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto medium_turquoise(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto medium_violet_red(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto midnight_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto mint_cream(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto misty_rose(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto moccasin(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto navajo_white(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto navy(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto old_lace(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto olive(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto olive_drab(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto orange(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto orange_red(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto orchid(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto pale_goldenrod(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto pale_green(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto pale_turquoise(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto pale_violet_red(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto papaya_whip(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto peach_puff(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto peru(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto pink(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto plum(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto powder_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto purple(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto rebecca_purple(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto red(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto rosy_brown(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto royal_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto saddle_brown(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto salmon(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto sandy_brown(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto sea_green(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto sea_shell(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto sienna(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto silver(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto sky_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto slate_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto slate_gray(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto snow(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto spring_green(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto steel_blue(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto tan(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto teal(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto thistle(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto tomato(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto turquoise(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto violet(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto wheat(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto white(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto white_smoke(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto yellow(float width = 1) -> xtd::drawing::pen;
      
      /// @brief A system-defined pen object with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto yellow_green(float width = 1) -> xtd::drawing::pen;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of pens with specified width.
      /// @param width The pen width. By default is  1.
      [[nodiscard]] static auto get_pens(float width = 1) -> const xtd::array<xtd::drawing::pen>&;
      /// @}
    };
  }
}
