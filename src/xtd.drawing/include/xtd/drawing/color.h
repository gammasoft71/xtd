/// @file
/// @brief Contains xtd::drawing::color class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "known_color.h"
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/ustring>
#include <cstdint>
#include <ostream>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class image;
    /// @endcond
    
    /// @brief Represents an ARGB (alpha, red, green, blue) color.
    /// @code
    /// class drawing_export_ color : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::color
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    /// @remarks Named colors are represented by using the properties of the xtd::drawing::color structure. For more information about these colors, <a href="https://developer.mozilla.org/en-US/docs/Web/CSS/color_value">see Colors by Name</a>.
    /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). Each of the four components is a number from 0 through 255, with 0 representing no intensity and 255 representing full intensity. The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. To determine the alpha, red, green, or blue component of a color, use the xtd::drawing::color::a, xtd::drawing::color::r, xtd::drawing::color::g, or xtd::drawing::color::b property, respectively. You can create a custom color by using one of the xtd::drawing::color::from_argb methods
    /// @par Examples
    /// The following code example demonstrates the xtd::drawing::color::a, xtd::drawing::color::r, xtd::drawing::color::g, and B properties of a xtd::drawing::color, and the Implicit(size to size_f) member.<br>
    /// This example is designed to be used with a Windows Form (xtd::forms). Paste the code into the form and call the show_properties_of_slate_blue method from the form's  xtd::forms::control::paint event-handling method, passing e as xtd::forms::paint_event_args.
    /// @code
    /// void show_properties_of_slate_blue(xtd::forms::paint_event_args& e) {
    ///   color slate_blue = xtd::drawing::color::from_name("slate blue");
    ///   xtd::byte a = slate_blue.a();
    ///   xtd::byte r = slate_blue.r();
    ///   xtd::byte g = slate_blue.g();
    ///   xtd::byte b = slate_blue.b();
    ///   string text = xtd::ustring::format("Slate blue has these ARGB values: alpha:{0}, red:{1}, green:{2}, blue:{3}", a, r, g, b);
    ///   e.graphics().draw_string(text, xtd::drawing::font(font(), xtd::drawing::font_style::italic), xtd::drawing::solid_brush(slate_blue), xtd::drawing::rectangle_f(xtd::drawing::point_f(0.0f, 0.0f), size()));
    /// }
    /// @endcode
    class drawing_export_ color : public xtd::object, public xtd::iequatable<color> {
    public:
      /// @name Public Fields
      
      /// @{
      /// @brief Represents a color that is null.
      static const xtd::drawing::color empty;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0x00FFFFFF. This field is constant.
      /// @remarks The value is 0x00FFFFFF unlike the value defined by css, which is 0x00000000.
      static const xtd::drawing::color transparent;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFF0F8FF. This field is constant.
      static const xtd::drawing::color alice_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFAEBD7. This field is constant.
      static const xtd::drawing::color antique_white;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FFFF. This field is constant.
      static const xtd::drawing::color aqua;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF7FFFD4. This field is constant.
      static const xtd::drawing::color aquamarine;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFF0FFFF. This field is constant.
      static const xtd::drawing::color azure;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFF5F5DC. This field is constant.
      static const xtd::drawing::color beige;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFE4C4. This field is constant.
      static const xtd::drawing::color bisque;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
      static const xtd::drawing::color black;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFEBCD. This field is constant.
      static const xtd::drawing::color blanched_almond;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF0000FF. This field is constant.
      static const xtd::drawing::color blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF8A2BE2. This field is constant.
      static const xtd::drawing::color blue_violet;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFA52A2A. This field is constant.
      static const xtd::drawing::color brown;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFDEB887. This field is constant.
      static const xtd::drawing::color burly_wood;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF5F9EA0. This field is constant.
      static const xtd::drawing::color cadet_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF7FFF00. This field is constant.
      static const xtd::drawing::color chartreuse;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFD2691E. This field is constant.
      static const xtd::drawing::color chocolate;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF7F50. This field is constant.
      static const xtd::drawing::color coral;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF6495ED. This field is constant.
      static const xtd::drawing::color cornflower_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFF8DC. This field is constant.
      static const xtd::drawing::color cornsilk;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFDC143C. This field is constant.
      static const xtd::drawing::color crimson;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FFFF. This field is constant.
      static const xtd::drawing::color cyan;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF00008B. This field is constant.
      static const xtd::drawing::color dark_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF008B8B. This field is constant.
      static const xtd::drawing::color dark_cyan;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFB8860B. This field is constant.
      static const xtd::drawing::color dark_goldenrod;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFA9A9A9. This field is constant.
      static const xtd::drawing::color dark_gray;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF006400. This field is constant.
      static const xtd::drawing::color dark_green;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFBDB76B. This field is constant.
      static const xtd::drawing::color dark_khaki;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF8B008B. This field is constant.
      static const xtd::drawing::color dark_magenta;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF556B2F. This field is constant.
      static const xtd::drawing::color dark_olive_green;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF8C00. This field is constant.
      static const xtd::drawing::color dark_orange;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF9932CC. This field is constant.
      static const xtd::drawing::color dark_orchid;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF8B0000. This field is constant.
      static const xtd::drawing::color dark_red;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFE9967A. This field is constant.
      static const xtd::drawing::color dark_salmon;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF8FBC8B. This field is constant.
      static const xtd::drawing::color dark_sea_green;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF483D8B. This field is constant.
      static const xtd::drawing::color dark_slate_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF2F4F4F. This field is constant.
      static const xtd::drawing::color dark_slate_gray;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF00CED1. This field is constant.
      static const xtd::drawing::color dark_turquoise;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF9400D3. This field is constant.
      static const xtd::drawing::color dark_violet;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF1493. This field is constant.
      static const xtd::drawing::color deep_pink;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF00BFFF. This field is constant.
      static const xtd::drawing::color deep_sky_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF696969. This field is constant.
      static const xtd::drawing::color dim_gray;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF1E90FF. This field is constant.
      static const xtd::drawing::color dodger_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFB22222. This field is constant.
      static const xtd::drawing::color firebrick;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFAF0. This field is constant.
      static const xtd::drawing::color floral_white;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF228B22. This field is constant.
      static const xtd::drawing::color forest_green;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF00FF. This field is constant.
      static const xtd::drawing::color fuchsia;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFDCDCDC. This field is constant.
      static const xtd::drawing::color gainsboro;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFF8F8FF. This field is constant.
      static const xtd::drawing::color ghost_white;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFD700. This field is constant.
      static const xtd::drawing::color gold;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFDAA520. This field is constant.
      static const xtd::drawing::color goldenrod;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF808080. This field is constant.
      static const xtd::drawing::color gray;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF008000. This field is constant.
      static const xtd::drawing::color green;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFADFF2F. This field is constant.
      static const xtd::drawing::color green_yellow;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFF0FFF0. This field is constant.
      static const xtd::drawing::color honeydew;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF69B4. This field is constant.
      static const xtd::drawing::color hot_pink;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFCD5C5C. This field is constant.
      static const xtd::drawing::color indian_red;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF4B0082. This field is constant.
      static const xtd::drawing::color indigo;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFF0. This field is constant.
      static const xtd::drawing::color ivory;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFF0E68C. This field is constant.
      static const xtd::drawing::color khaki;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFE6E6FA. This field is constant.
      static const xtd::drawing::color lavender;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFF0F5. This field is constant.
      static const xtd::drawing::color lavender_blush;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF7CFC00. This field is constant.
      static const xtd::drawing::color lawn_green;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFACD. This field is constant.
      static const xtd::drawing::color lemon_chiffon;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFADD8E6. This field is constant.
      static const xtd::drawing::color light_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFF08080. This field is constant.
      static const xtd::drawing::color light_coral;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFE0FFFF. This field is constant.
      static const xtd::drawing::color light_cyan;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFAFAD2. This field is constant.
      static const xtd::drawing::color light_goldenrod_yellow;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFD3D3D3. This field is constant.
      static const xtd::drawing::color light_gray;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF90EE90. This field is constant.
      static const xtd::drawing::color light_green;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFB6C1. This field is constant.
      static const xtd::drawing::color light_pink;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFA07A. This field is constant.
      static const xtd::drawing::color light_salmon;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF20B2AA. This field is constant.
      static const xtd::drawing::color light_sea_green;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF87CEFA. This field is constant.
      static const xtd::drawing::color light_sky_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF778899. This field is constant.
      static const xtd::drawing::color light_slate_gray;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFB0C4DE. This field is constant.
      static const xtd::drawing::color light_steel_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFE0. This field is constant.
      static const xtd::drawing::color light_yellow;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FF00. This field is constant.
      static const xtd::drawing::color lime;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF32CD32. This field is constant.
      static const xtd::drawing::color lime_green;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFAF0E6. This field is constant.
      static const xtd::drawing::color linen;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF00FF. This field is constant.
      static const xtd::drawing::color magenta;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF800000. This field is constant.
      static const xtd::drawing::color maroon;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF66CDAA. This field is constant.
      static const xtd::drawing::color medium_aquamarine;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF0000CD. This field is constant.
      static const xtd::drawing::color medium_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFBA55D3. This field is constant.
      static const xtd::drawing::color medium_orchid;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF9370DB. This field is constant.
      static const xtd::drawing::color medium_purple;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF3CB371. This field is constant.
      static const xtd::drawing::color medium_sea_green;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF7B68EE. This field is constant.
      static const xtd::drawing::color medium_slate_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FA9A. This field is constant.
      static const xtd::drawing::color medium_spring_green;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF48D1CC. This field is constant.
      static const xtd::drawing::color medium_turquoise;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFC71585. This field is constant.
      static const xtd::drawing::color medium_violet_red;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF191970. This field is constant.
      static const xtd::drawing::color midnight_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFF5FFFA. This field is constant.
      static const xtd::drawing::color mint_cream;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFE4E1. This field is constant.
      static const xtd::drawing::color misty_rose;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFE4B5. This field is constant.
      static const xtd::drawing::color moccasin;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFDEAD. This field is constant.
      static const xtd::drawing::color navajo_white;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF000080. This field is constant.
      static const xtd::drawing::color navy;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFDF5E6. This field is constant.
      static const xtd::drawing::color old_lace;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF808000. This field is constant.
      static const xtd::drawing::color olive;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF6B8E23. This field is constant.
      static const xtd::drawing::color olive_drab;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFA500. This field is constant.
      static const xtd::drawing::color orange;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF4500. This field is constant.
      static const xtd::drawing::color orange_red;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFDA70D6. This field is constant.
      static const xtd::drawing::color orchid;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFEEE8AA. This field is constant.
      static const xtd::drawing::color pale_goldenrod;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF98FB98. This field is constant.
      static const xtd::drawing::color pale_green;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFAFEEEE. This field is constant.
      static const xtd::drawing::color pale_turquoise;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFDB7093. This field is constant.
      static const xtd::drawing::color pale_violet_red;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFEFD5. This field is constant.
      static const xtd::drawing::color papaya_whip;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFDAB9. This field is constant.
      static const xtd::drawing::color peach_puff;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFCD853F. This field is constant.
      static const xtd::drawing::color peru;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFC0CB. This field is constant.
      static const xtd::drawing::color pink;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFDDA0DD. This field is constant.
      static const xtd::drawing::color plum;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFB0E0E6. This field is constant.
      static const xtd::drawing::color powder_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF800080. This field is constant.
      static const xtd::drawing::color purple;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF663399. This field is constant.
      static const xtd::drawing::color rebecca_purple;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF0000. This field is constant.
      static const xtd::drawing::color red;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFBC8F8F. This field is constant.
      static const xtd::drawing::color rosy_brown;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF4169E1. This field is constant.
      static const xtd::drawing::color royal_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF8B4513. This field is constant.
      static const xtd::drawing::color saddle_brown;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFA8072. This field is constant.
      static const xtd::drawing::color salmon;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFF4A460. This field is constant.
      static const xtd::drawing::color sandy_brown;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF2E8B57. This field is constant.
      static const xtd::drawing::color sea_green;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFF5EE. This field is constant.
      static const xtd::drawing::color sea_shell;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFA0522D. This field is constant.
      static const xtd::drawing::color sienna;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFC0C0C0. This field is constant.
      static const xtd::drawing::color silver;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF87CEEB. This field is constant.
      static const xtd::drawing::color sky_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF6A5ACD. This field is constant.
      static const xtd::drawing::color slate_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF708090. This field is constant.
      static const xtd::drawing::color slate_gray;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFAFA. This field is constant.
      static const xtd::drawing::color snow;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FF7F. This field is constant.
      static const xtd::drawing::color spring_green;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF4682B4. This field is constant.
      static const xtd::drawing::color steel_blue;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFD2B48C. This field is constant.
      static const xtd::drawing::color tan;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF008080. This field is constant.
      static const xtd::drawing::color teal;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFD8BFD8. This field is constant.
      static const xtd::drawing::color thistle;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF6347. This field is constant.
      static const xtd::drawing::color tomato;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF40E0D0. This field is constant.
      static const xtd::drawing::color turquoise;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFEE82EE. This field is constant.
      static const xtd::drawing::color violet;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFF5DEB3. This field is constant.
      static const xtd::drawing::color wheat;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
      static const xtd::drawing::color white;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFF5F5F5. This field is constant.
      static const xtd::drawing::color white_smoke;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFF00. This field is constant.
      static const xtd::drawing::color yellow;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF9ACD32. This field is constant.
      static const xtd::drawing::color yellow_green;
      
      /// @brief Represent the lightness threshold.
      /// @remarks If color::get_lightness() less than lightness_threshold is dark color; otherwise is light color.
      static constexpr double lightness_threshold = 0.5;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new instance of xtd::drawing::color class.
      color() = default;
      /// @}
      
      /// @cond
      color(const color& color) = default;
      color& operator =(const color& color) = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the alpha component value of this xtd::drawing::color class.
      /// @return byte The alpha component value of this xtd::drawing::color.
      /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. Likewise, an xtd::drawing::color::a value of 255 represents an opaque color. An xtd::drawing::color::a value from 1 through 254 represents a semitransparent color. The color becomes more opaque as xtd::drawing::color::a approaches 255.
      /// @par Examples
      /// The following code example demonstrates the xtd::drawing::color::a, xtd::drawing::color::r, xtd::drawing::color::g, and xtd::drawing::color::b properties of a xtd::drawing::color, and the Implicit(size to size_f) member.<br>
      /// This example is designed to be used with a Windows Form (xtd::forms). Paste the code into the form and call the show_properties_of_slate_blue method from the form's  xtd::forms::control::paint event-handling method, passing e as xtd::forms::paint_event_args.
      /// @code
      /// void show_properties_of_slate_blue(xtd::forms::paint_event_args& e) {
      ///   color slate_blue = xtd::drawing::color::from_name("slate blue");
      ///   byte g = slate_blue.g();
      ///   byte b = slate_blue.b();
      ///   byte r = slate_blue.r();
      ///   byte a = slate_blue.a();
      ///   string text = xtd::string::ustring::format("Slate blue has these ARGB values: alpha:{0}, red:{1}, green: {2}, blue {3}", a, r, g, b);
      ///   e.graphics().draw_string(text, xtd::drawing::font(font(), xtd::drawing::font_style::italic), xtd::drawing::solid_brush(slate_blue), xtd::drawing::rectangle_f(xtd::drawing::point_f(0.0f, 0.0f), size()));
      /// }
      /// @endcode
      xtd::byte a() const noexcept;
      
      /// @brief Gets the blue component value of this xtd::drawing::color class.
      /// @return byte The blue component value of this xtd::drawing::color.
      /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. Likewise, an xtd::drawing::color::a value of 255 represents an opaque color. An xtd::drawing::color::a value from 1 through 254 represents a semitransparent color. The color becomes more opaque as xtd::drawing::color::a approaches 255.
      /// @par Examples
      /// The following code example demonstrates the xtd::drawing::color::a, xtd::drawing::color::r, xtd::drawing::color::g, and xtd::drawing::color::b properties of a xtd::drawing::color, and the Implicit(size to size_f) member.<br>
      /// This example is designed to be used with a Windows Form (xtd::forms). Paste the code into the form and call the show_properties_of_slate_blue method from the form's  xtd::forms::control::paint event-handling method, passing e as xtd::forms::paint_event_args.
      /// @code
      /// void show_properties_of_slate_blue(xtd::forms::paint_event_args& e) {
      ///   color slate_blue = xtd::drawing::color::from_name("slate blue");
      ///   byte g = slate_blue.g();
      ///   byte b = slate_blue.b();
      ///   byte r = slate_blue.r();
      ///   byte a = slate_blue.a();
      ///   string text = xtd::ustring::format("Slate blue has these ARGB values: alpha:{0}, red:{1}, green: {2}, blue {3}", a, r, g, b);
      ///   e.graphics().draw_string(text, xtd::drawing::font(font(), xtd::drawing::font_style::italic), xtd::drawing::solid_brush(slate_blue), xtd::drawing::rectangle_f(xtd::drawing::point_f(0.0f, 0.0f), size()));
      /// }
      /// @endcode
      xtd::byte b() const noexcept;
      
      /// @brief Gets the green component value of this xtd::drawing::color class.
      /// @return byte The green component value of this xtd::drawing::color.
      /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. Likewise, an xtd::drawing::color::a value of 255 represents an opaque color. An xtd::drawing::color::a value from 1 through 254 represents a semitransparent color. The color becomes more opaque as xtd::drawing::color::a approaches 255.
      /// @par Examples
      /// The following code example demonstrates the xtd::drawing::color::a, xtd::drawing::color::r, xtd::drawing::color::g, and xtd::drawing::color::b properties of a xtd::drawing::color, and the Implicit(size to size_f) member.<br>
      /// This example is designed to be used with a Windows Form (xtd::forms). Paste the code into the form and call the show_properties_of_slate_blue method from the form's  xtd::forms::control::paint event-handling method, passing e as xtd::forms::paint_event_args.
      /// @code
      /// void show_properties_of_slate_blue(xtd::forms::paint_event_args& e) {
      ///   color slate_blue = xtd::drawing::color::from_name("slate blue");
      ///   byte g = slate_blue.g();
      ///   byte b = slate_blue.b();
      ///   byte r = slate_blue.r();
      ///   byte a = slate_blue.a();
      ///   string text = xtd::ustring::format("Slate blue has these ARGB values: alpha:{0}, red:{1}, green: {2}, blue {3}", a, r, g, b);
      ///   e.graphics().draw_string(text, xtd::drawing::font(font(), xtd::drawing::font_style::italic), xtd::drawing::solid_brush(slate_blue), xtd::drawing::rectangle_f(xtd::drawing::point_f(0.0f, 0.0f), size()));
      /// }
      /// @endcode
      xtd::byte g() const noexcept;
      
      /// @brief Gets the native handle of this xtd::drawing::color class.
      /// @remarks For internal use only, needed for system_colors.
      intptr handle() const noexcept;
      
      /// @brief Gets a value indicating wheter this xtd::drawing::color structure is dark color.
      /// @remarks return true if dark color; otherwise false.
      bool is_dark() const noexcept;
      
      /// @brief Specifies whether this xtd::drawing::color class is uninitialized.
      /// @return bool Returns true if this color is uninitialized; otherwise, false.
      bool is_empty() const noexcept;
      
      /// @brief Gets a value indicating whether this xtd::drawing::color structure is a predefined color. Predefined colors are represented by the elements of the xtd::drawing::known_color enumeration.
      /// @return bool Returns true if this xtd::drawing::color was created from a predefined color by using either the from_name method or the from_known_color method; otherwise, false.
      /// @remarks This property does not do a comparison of the ARGB values. Therefore, when the is_known_color property is applied to a xtd::drawing::color structure that is created by using the xtd::drawing::color::from_argb method, is_known_color returns false, even if the ARGB value matches the ARGB value of a predefined color.
      bool is_known_color() const noexcept;
      
      /// @brief Gets a value indicating wheter this xtd::drawing::color structure is light color.
      /// @remarks return true if light color; otherwise false.
      bool is_light() const noexcept;
      
      /// @brief Gets a value indicating whether this xtd::drawing::color structure is a named color or a member of the xtd::drawing::known_color enumeration.
      /// @return bool Returns true if this xtd::drawing::color was created by using either the xtd::drawing::color::from_name method or the xtd::drawing::color::from_known_color method; otherwise, false.
      bool is_named_color() const noexcept;
      
      /// @brief Gets a value indicating whether this xtd::drawing::color structure is a system color. A system color is a color that is used in a Windows display element. System colors are represented by elements of the xtd::drawing::known_color enumeration.
      /// @return bool Returns true if this xtd::drawing::color was created from a system color by using either the xtd::drawing::color::from_name method or the xtd::drawing::color::from_known_color method; otherwise, false.
      bool is_system_color() const noexcept;
      
      /// @brief Gets the name of this xtd::drawing::color.
      /// @return string The name of this xtd::drawing::color.
      xtd::ustring name() const noexcept;
      
      /// @brief Gets the red component value of this xtd::drawing::color class.
      /// @return byte The red component value of this xtd::drawing::color.
      /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. Likewise, an xtd::drawing::color::a value of 255 represents an opaque color. An xtd::drawing::color::a value from 1 through 254 represents a semitransparent color. The color becomes more opaque as xtd::drawing::color::a approaches 255.
      /// @par Examples
      /// The following code example demonstrates the xtd::drawing::color::a, xtd::drawing::color::r, xtd::drawing::color::g, and xtd::drawing::color::b properties of a xtd::drawing::color, and the Implicit(size to size_f) member.<br>
      /// This example is designed to be used with a Windows Form (xtd::forms). Paste the code into the form and call the show_properties_of_slate_blue method from the form's  xtd::forms::control::paint event-handling method, passing e as xtd::forms::paint_event_args.
      /// @code
      /// void show_properties_of_slate_blue(xtd::forms::paint_event_args& e) {
      ///   color slate_blue = xtd::drawing::color::from_name("slate blue");
      ///   byte g = slate_blue.g();
      ///   byte b = slate_blue.b();
      ///   byte r = slate_blue.r();
      ///   byte a = slate_blue.a();
      ///   string text = xtd::ustring::format("Slate blue has these ARGB values: alpha:{0}, red:{1}, green: {2}, blue {3}", a, r, g, b);
      ///   e.graphics().draw_string(text, xtd::drawing::font(font(), xtd::drawing::font_style::italic), xtd::drawing::solid_brush(slate_blue), xtd::drawing::rectangle_f(xtd::drawing::point_f(0.0f, 0.0f), size()));
      /// }
      /// @endcode
      xtd::byte r() const noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      bool equals(const color& value) const noexcept override;

      /// @brief Gets the hue-saturation-brightness (HSB) brightness value for this xtd::drawing::color structure.
      /// @return The brightness of this xtd::drawing::color. The lightness ranges from 0.0 through 1.0, where 0.0 represents black and 1.0 represents white.
      /// @par Examples
      /// The following code example is designed for use with Windows Forms, and it requires xtd::forms::paint_event_args, which is a parameter of the xtd::forms::control::paint event handler. The code performs the following actions:
      /// * Creates an instance of a xtd::drawing::color structure, redShade, to be used for comparisons.
      /// * Iterates through the xtd::drawing::known_color enumeration elements to find all known colors that have the same lightness as redShade. The iterations are terminated when 15 matches are found or the value of the loop counter is greater than the last xtd::drawing::known_color element.
      /// * During each iteration, saves the xtd::drawing::known_color element—if it matches the criteria—in an array.
      /// * Uses a brush to paint rectangles.
      /// The first rectangle is painted the color represented by redShade. Each of the other rectangles is painted a xtd::drawing::known_color that matches the hue of the redShade.
      /// @code
      /// void known_color_brightness_example2(paint_event_args& e) {
      ///   graphics g = e.graphics();
      ///
      ///   // xtd::drawing::color structures. One is a variable used for temporary storage. The other is a constant used for comparisons.
      ///   xtd::drawing::color some_color = xtd::drawing::color::from_argb(0);
      ///   xtd::drawing::color red_shade = xtd::drawing::color::from_argb(255, 200, 0, 100);
      ///
      ///   // Array to store xtd::drawing::known_color values that match the hue of the redShade color.
      ///   std::vector<xtd::drawing::known_color> color_matches(15);
      ///
      ///   // Number of matches found.
      ///   int count = 0;
      ///
      ///   // Iterate through the xtd::drawing::known_color enums until 15 matches are found.
      ///   for (xtd::drawing::known_color enum_value = 0; enum_value <= xtd::drawing::known_color::yellow_green && count < 15; enum_value = known_color(int(enum_value) + 1)) {
      ///     some_color = xtd::drawing::color::from_known_color(enum_value);
      ///     if (some_color.get_brightness() == red_shade.get_brightness())
      ///       color_matches[count++] = enum_value;
      ///   }
      ///
      ///   // Display the redShade color and its argb value.
      ///   solid_brush  my_brush1(red_shade);
      ///   font my_font("Arial", 12);
      ///   int x = 20;
      ///   int y = 20;
      ///   some_color = red_shade;
      ///   g.fill_rectangle(my_brush1, x, y, 100, 30);
      ///   g.draw_string(some_color.to_string(), my_font, brushes::black, x + 120, y);
      ///
      ///   // Iterate through the matches that were found and display each color that corresponds with the enum value in the array. also display the name of the xtd::drawing::known_color.
      ///   for (int i = 0; i < count; i++) {
      ///     y += 40;
      ///     some_color = xtd::drawing::color::from_known_color(color_matches[i]);
      ///     my_brush1.xtd::drawing::color = some_color;
      ///     g.fill_rectangle(my_brush1, x, y, 100, 30);
      ///     g.draw_string(some_color.to_string(), my_font, brushes::black, x + 120, y);
      ///   }
      /// }
      /// @endcode
      float get_brightness() const noexcept;
      
      /// @brief Gets the hue-saturation-brightness (HSB) hue value, in degrees, for this xtd::drawing::color structure.
      /// @return The hue, in degrees, of this xtd::drawing::color. The hue is measured in degrees, ranging from 0.0 through 360.0, in HSL color space.
      /// @par Examples
      /// The following code example is designed for use with Windows Forms, and it requires xtd::forms::paint_event_args, which is a parameter of the xtd::forms::control::paint event handler. The code performs the following actions:
      /// * Creates an instance of a xtd::drawing::color structure, redShade, to be used for comparisons.
      /// * Iterates through the xtd::drawing::known_color enumeration elements to find all known colors that have the same lightness as redShade. The iterations are terminated when 15 matches are found or the value of the loop counter is greater than the last xtd::drawing::known_color element.
      /// * During each iteration, saves the xtd::drawing::known_color element—if it matches the criteria—in an array.
      /// * Uses a brush to paint rectangles.
      /// The first rectangle is painted the color represented by redShade. Each of the other rectangles is painted a xtd::drawing::known_color that matches the hue of the redShade.
      /// @code
      /// void known_color_brightness_example2(paint_event_args& e) {
      ///   graphics g = e.graphics();
      ///
      ///   // xtd::drawing::color structures. One is a variable used for temporary storage. The other is a constant used for comparisons.
      ///   xtd::drawing::color some_color = xtd::drawing::color::from_argb(0);
      ///   xtd::drawing::color red_shade = xtd::drawing::color::from_argb(255, 200, 0, 100);
      ///
      ///   // Array to store xtd::drawing::known_color values that match the hue of the redShade color.
      ///   std::vector<xtd::drawing::known_color> color_matches(15);
      ///
      ///   // Number of matches found.
      ///   int count = 0;
      ///
      ///   // Iterate through the xtd::drawing::known_color enums until 15 matches are found.
      ///   for (xtd::drawing::known_color enum_value = 0; enum_value <= xtd::drawing::known_color::yellow_green && count < 15; enum_value = known_color(int(enum_value) + 1)) {
      ///     some_color = xtd::drawing::color::from_known_color(enum_value);
      ///     if (some_color.get_brightness() == red_shade.get_brightness())
      ///       color_matches[count++] = enum_value;
      ///   }
      ///
      ///   // Display the redShade color and its argb value.
      ///   solid_brush  my_brush1(red_shade);
      ///   font my_font("Arial", 12);
      ///   int x = 20;
      ///   int y = 20;
      ///   some_color = red_shade;
      ///   g.fill_rectangle(my_brush1, x, y, 100, 30);
      ///   g.draw_string(some_color.to_string(), my_font, brushes::black, x + 120, y);
      ///
      ///   // Iterate through the matches that were found and display each color that corresponds with the enum value in the array. also display the name of the xtd::drawing::known_color.
      ///   for (int i = 0; i < count; i++) {
      ///     y += 40;
      ///     some_color = xtd::drawing::color::from_known_color(color_matches[i]);
      ///     my_brush1.xtd::drawing::color = some_color;
      ///     g.fill_rectangle(my_brush1, x, y, 100, 30);
      ///     g.draw_string(some_color.to_string(), my_font, brushes::black, x + 120, y);
      ///   }
      /// }
      /// @endcode
      float get_hue() const noexcept;
      
      /// @brief Gets the hue-saturation-lightness (HSL) lightness value for this xtd::drawing::color structure.
      /// @return The lightness of this xtd::drawing::color. The lightness ranges from 0.0 through 1.0, where 0.0 represents black and 1.0 represents white.
      float get_lightness() const noexcept;
      
      /// @brief Gets the hue-saturation-brightness (HSB) saturation value for this xtd::drawing::color structure.
      /// @return The saturation of this xtd::drawing::color. The saturation ranges from 0.0 through 1.0, where 0.0 is grayscale and 1.0 is the most saturated.
      /// @par Examples
      /// The following code example is designed for use with Windows Forms, and it requires xtd::forms::paint_event_args, which is a parameter of the xtd::forms::control::paint event handler. The code performs the following actions:
      /// * Creates an instance of a xtd::drawing::color structure, redShade, to be used for comparisons.
      /// * Iterates through the xtd::drawing::known_color enumeration elements to find all known colors that have the same lightness as redShade. The iterations are terminated when 15 matches are found or the value of the loop counter is greater than the last xtd::drawing::known_color element.
      /// * During each iteration, saves the xtd::drawing::known_color element—if it matches the criteria—in an array.
      /// * Uses a brush to paint rectangles.
      /// The first rectangle is painted the color represented by redShade. Each of the other rectangles is painted a xtd::drawing::known_color that matches the hue of the redShade.
      /// @code
      /// void known_color_brightness_example2(paint_event_args& e) {
      ///   graphics g = e.graphics();
      ///
      ///   // xtd::drawing::color structures. One is a variable used for temporary storage. The other is a constant used for comparisons.
      ///   xtd::drawing::color some_color = xtd::drawing::color::from_argb(0);
      ///   xtd::drawing::color red_shade = xtd::drawing::color::from_argb(255, 200, 0, 100);
      ///
      ///   // Array to store xtd::drawing::known_color values that match the hue of the redShade color.
      ///   std::vector<xtd::drawing::known_color> color_matches(15);
      ///
      ///   // Number of matches found.
      ///   int count = 0;
      ///
      ///   // Iterate through the xtd::drawing::known_color enums until 15 matches are found.
      ///   for (xtd::drawing::known_color enum_value = 0; enum_value <= xtd::drawing::known_color::yellow_green && count < 15; enum_value = known_color(int(enum_value) + 1)) {
      ///     some_color = xtd::drawing::color::from_known_color(enum_value);
      ///     if (some_color.get_brightness() == red_shade.get_brightness())
      ///       color_matches[count++] = enum_value;
      ///   }
      ///
      ///   // Display the redShade color and its argb value.
      ///   solid_brush  my_brush1(red_shade);
      ///   font my_font("Arial", 12);
      ///   int x = 20;
      ///   int y = 20;
      ///   some_color = red_shade;
      ///   g.fill_rectangle(my_brush1, x, y, 100, 30);
      ///   g.draw_string(some_color.to_string(), my_font, brushes::black, x + 120, y);
      ///
      ///   // Iterate through the matches that were found and display each color that corresponds with the enum value in the array. also display the name of the xtd::drawing::known_color.
      ///   for (int i = 0; i < count; i++) {
      ///     y += 40;
      ///     some_color = xtd::drawing::color::from_known_color(color_matches[i]);
      ///     my_brush1.xtd::drawing::color = some_color;
      ///     g.fill_rectangle(my_brush1, x, y, 100, 30);
      ///     g.draw_string(some_color.to_string(), my_font, brushes::black, x + 120, y);
      ///   }
      /// }
      /// @endcode
      float get_saturation() const noexcept;
      
      /// @brief Gets the Y'UV color model `U` (chroma) value for this xtd::drawing::color structure.
      /// @return The Y'UV `U` value of this xtd::drawing::color. The y ranges from -0.5 through0.5. When `U` and `V` are both 0, the color is neutral (gray). Positive `U` values represent the red-green axis, and positive `V` values represent the blue-yellow axis
      float get_u() const noexcept;
      
      /// @brief Gets the Y'UV color model `V` (chroma) value for this xtd::drawing::color structure.
      /// @return The Y'UV `V` value of this xtd::drawing::color. The y ranges from -0.5 through0.5. When `U` and `V` are both 0, the color is neutral (gray). Positive `U` values represent the red-green axis, and positive `V` values represent the blue-yellow axis
      float get_v() const noexcept;
      
      /// @brief Gets the Y'UV color model `Y` (luma) value for this xtd::drawing::color structure.
      /// @return The Y'UV `Y` value of this xtd::drawing::color. The y ranges from 0.0 through 1.0, where 0.0 represents black and 1.0 represents white.
      float get_y() const noexcept;
      
      /// @brief Gets the 32-bit ARGB value of this xtd::drawing::color class.
      /// @return The 32-bit ARGB value of this xtd::drawing::color.
      /// @remarks The byte-ordering of the 32-bit ARGB value is AARRGGBB. The most significant byte (MSB), represented by AA, is the alpha component value. The second, third, and fourth bytes, represented by RR, GG, and BB, respectively, are the color components red, green, and blue, respectively.
      /// @par Examples
      /// The following code example is designed for use with Windows Forms, and it requires xtd::forms::paint_event_args e, which is a parameter of the xtd::forms::control::paint event handler. The code performs the following actions:
      /// * Iterates through the xtd::drawing::known_color enumeration elements to find all known colors that have a non-zero green component and a zero-value red component, and that are not system colors.
      /// * During each iteration, saves the xtd::drawing::known_color element - if it matches the criteria - in an array.
      /// * Uses a brush to paint rectangles.
      /// Each of the rectangles is painted a xtd::drawing::known_color that matches the criteria stated in the first bullet. The name of the xtd::drawing::known_color and its component values are also displayed.
      /// This example displays certain known colors, the names of the colors, and their four component values. The xtd::drawing::color::to_argb method is used as a preliminary step to display the component values.
      /// @code
      /// void to_argb_to_string_example1(paint_event_args& e) {
      ///   graphics g = e.graphics();
      ///   ///
      ///   // Color structure used for temporary storage.
      ///   color some_color = color::from_argb(0);
      ///   ///
      ///   // Vector to store known_color values that match the criteria.
      ///   std::vector<known_color> color_matches;
      ///   ///
      ///   // Iterate through the KnownColor enums to find all corresponding colors
      ///   // that have a nonzero green component and zero-value red component and
      ///   // that are not system colors.
      ///   for (int enum_value = 0; enum_value <= static_cast<int>(known_color::yellow_green); ++enum_value) {
      ///     some_color = color::from_known_color(static_cast<known_color>(enum_value));
      ///     if (some_color.g() != 0 && some_color.r() == 0 && !some_color.is_system_color())
      ///       color_matches.emplace_back(static_cast<known_color>(enum_value));
      ///   }
      ///   solid_brush my_brush1 {some_color};
      ///   font my_font {"Arial", 9};
      ///   int x = 40;
      ///   int y = 40;
      ///   ///
      ///   // Iterate through the matches that were found and display each color that
      ///   // corresponds with the enum value in the array. also display the name of
      ///   // the known_color and the ARGB components.
      ///   for (size_t i = 0; i < color_matches.size(); ++i) {
      ///     // Display the color.
      ///     some_color = color::from_known_color(color_matches[i]);
      ///     my_brush1.color(some_color);
      ///     g.fill_rectangle(my_brush1, x, y, 50, 30);
      ///     ///
      ///     // Display known_color name and the four component values. To display the
      ///     // component values:  Use the to_argb method to get the 32-bit ARGB value
      ///     // of some_color, which was created from a known_color. Then create a
      ///     // color structure from the 32-bit ARGB value and set some_color equal to
      ///     // this new color structure. Then use the to_string method to convert it to
      ///     // a string.
      ///     g.draw_string(some_color.to_string(), my_font, brushes::black(), x + 55, y);
      ///     some_color = color::from_argb(some_color.to_argb());
      ///     g.draw_string(some_color.to_string(), my_font, brushes::black(), x + 55, y + 15);
      ///     y += 40;
      ///   }
      /// }
      /// @endcode
      uint32 to_argb() const noexcept;
      
      /// @brief Gets the xtd::drawing::known_color value of this xtd::drawing::color class.
      /// @return xtd::drawing::known_color An element of the xtd::drawing::known_color enumeration, if the xtd::drawing::color is created from a predefined color by using either the xtd::drawing::color::from_name method or the xtd::drawing::color::from_known_color method; otherwise, 0.
      /// @remarks A predefined color is also called a known color and is represented by an element of the xtd::drawing::known_color enumeration. When the xtd::drawing::color::to_known_color method is applied to a xtd::drawing::color structure that is created by using the FromArgb method, xtd::drawing::color::to_known_color returns 0, even if the ARGB value matches the ARGB value of a predefined color. xtd::drawing::color::to_known_color also returns 0 when it is applied to a xtd::drawing::color structure that is created by using the xtd::drawing::color::from_name method with a string name that is not valid.
      xtd::drawing::known_color to_known_color() const noexcept;
      
      /// @brief Creates a human-readable string that represents this color class.
      /// @return string A string that represents this Size.
      /// @par Examples
      /// The following code example is designed for use with Windows Forms, and it requires xtd::forms::paint_event_args, which is a parameter of the xtd::forms::control::paint event handler. The code performs the following actions:
      /// * Creates an instance of a xtd::drawing::color structure, redShade, to be used for comparisons.
      /// * Iterates through the xtd::drawing::known_color enumeration elements to find all known colors that have the same lightness as redShade. The iterations are terminated when 15 matches are found or the value of the loop counter is greater than the last xtd::drawing::known_color element.
      /// * During each iteration, saves the xtd::drawing::known_color element—if it matches the criteria—in an array.
      /// * Uses a brush to paint rectangles.
      /// The first rectangle is painted the color represented by redShade. Each of the other rectangles is painted a xtd::drawing::known_color that matches the hue of the redShade.
      /// @code
      /// void known_color_brightness_example2(paint_event_args& e) {
      ///   graphics g = e.graphics();
      ///
      ///   // xtd::drawing::color structures. One is a variable used for temporary storage. The other is a constant used for comparisons.
      ///   xtd::drawing::color some_color = xtd::drawing::color::from_argb(0);
      ///   xtd::drawing::color red_shade = xtd::drawing::color::from_argb(255, 200, 0, 100);
      ///
      ///   // Array to store xtd::drawing::known_color values that match the hue of the redShade color.
      ///   std::vector<xtd::drawing::known_color> color_matches(15);
      ///
      ///   // Number of matches found.
      ///   int count = 0;
      ///
      ///   // Iterate through the xtd::drawing::known_color enums until 15 matches are found.
      ///   for (xtd::drawing::known_color enum_value = 0; enum_value <= xtd::drawing::known_color::yellow_green && count < 15; enum_value = known_color(int(enum_value) + 1)) {
      ///     some_color = xtd::drawing::color::from_known_color(enum_value);
      ///     if (some_color.get_brightness() == red_shade.get_brightness())
      ///       color_matches[count++] = enum_value;
      ///   }
      ///
      ///   // Display the redShade color and its argb value.
      ///   solid_brush  my_brush1(red_shade);
      ///   font my_font("Arial", 12);
      ///   int x = 20;
      ///   int y = 20;
      ///   some_color = red_shade;
      ///   g.fill_rectangle(my_brush1, x, y, 100, 30);
      ///   g.draw_string(some_color.to_string(), my_font, brushes::black, x + 120, y);
      ///
      ///   // Iterate through the matches that were found and display each color that corresponds with the enum value in the array. also display the name of the xtd::drawing::known_color.
      ///   for (int i = 0; i < count; i++) {
      ///     y += 40;
      ///     some_color = xtd::drawing::color::from_known_color(color_matches[i]);
      ///     my_brush1.xtd::drawing::color = some_color;
      ///     g.fill_rectangle(my_brush1, x, y, 100, 30);
      ///     g.draw_string(some_color.to_string(), my_font, brushes::black, x + 120, y);
      ///   }
      /// }
      /// @endcode
      xtd::ustring to_string() const noexcept override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Returns the weighted average color between the two given colors.
      /// @param color1 The first color.
      /// @param color2 The second color.
      /// @param weight The weighting factor
      /// @return The average color.
      /// @remarks The alpha of color1 is conserved.
      /// @remarks The red, green and blue values are averages using the following formula:
      /// @code
      /// color = color1 * (1 - weight) + color2 * weight;
      /// @endcode
      /// @remarks Thus, a weight value of `1.0` will return the second color, while a value of `0.0` will return the first color.
      /// @deprecated Replaced by xtd::drawing::color_converter::average - Will be removed in version 0.4.0
      [[deprecated("Replaced by xtd::drawing::color_converter::average - Will be removed in version 0.4.0")]]
      static color average(const color& color1, const color& color2, double weight) noexcept;
      /// @brief Returns the weighted average color between the two given colors.
      /// @param color1 The first color.
      /// @param color2 The second color.
      /// @param weight The weighting factor
      /// @param average_alpha if true alpha was compute to; otherwise the alpha result is the alpha of color1
      /// @return The average color.
      /// @remarks The alpha, red, green and blue values are averages using the following formula:
      /// @code
      /// color = color1 * (1 - weight) + color2 * weight;
      /// @endcode
      /// @remarks Thus, a weight value of 1.0 will return the first color, while a value of 0.0 will return the second color.
      /// @deprecated Replaced by xtd::drawing::color_converter::average - Will be removed in version 0.4.0
      [[deprecated("Replaced by xtd::drawing::color_converter::average - Will be removed in version 0.4.0")]]
      static color average(const color& color1, const color& color2, double weight, bool average_alpha) noexcept;
      
      /// @brief Creates a new darker color of the specified color with 33% factor.
      /// @param color The color to dark.
      /// @return The new color.
      /// @deprecated Replaced by xtd::drawing::color_converter::dark - Will be removed in version 0.4.0
      [[deprecated("Replaced by xtd::drawing::color_converter::dark - Will be removed in version 0.4.0")]]
      static color dark(const color& color) noexcept;
      /// @brief Creates a new darker color of the specified color with specified percent factor.
      /// @param color The color to dark.
      /// @param percent The darker factor in % (from 0.0 to 1.0).
      /// @return The new color.
      /// @remarks Thus, a percent value of `1.0` will return the xtd::drawing::color::black, while a value of `0.0` will return the color.
      static color dark(const color& color, double percent) noexcept;
      
      /// @brief Creates a xtd::drawing::color class from a 32-bit ARGB value.
      /// @param argb A value specifying the 32-bit ARGB value
      /// @return The xtd::drawing::color structure that this method creates.
      /// @remarks The byte-ordering of the 32-bit ARGB value is AARRGGBB. The most significant byte (MSB), represented by AA, is the alpha component value. The second, third, and fourth bytes, represented by RR, GG, and BB, respectively, are the color components red, green, and blue, respectively.
      /// @par Examples
      /// The following code example is designed for use with Windows Forms, and it requires xtd::forms::paint_event_args e, which is a parameter of the xtd::forms::control::paint event handler. The code performs the following actions:
      /// * Creates three brushes, each a different color. Each xtd::drawing::color structure that is used to create a brush is created from four component values (alpha, red, green, blue).
      /// * Uses an imaginary triangle to position three circles.
      /// * Paints three overlapping circles, each centered on one vertex of the triangle, using a different brush for each circle.
      /// @code
      /// void from_argb1(paint_event_args& e) {
      ///   graphics g = e.graphics();
      ///
      ///   // Transparent red, green, and blue brushes.
      ///   solid_brush trns_red_brush(color::from_argb(0x78FF0000));
      ///   solid_brush trns_green_brush(color::from_argb(0x7800FF00));
      ///   solid_brush trns_blue_brush(color::from_argb(0x780000FF));
      ///
      ///   // Base and height of the triangle that is used to position the circles. Each vertex of the triangle is at the center of one of the 3 circles. The base is equal to the diameter of the circles.
      ///   float tri_base = 100;
      ///   float tri_height = std::sqrt(3 * (tri_base * tri_base) / 4);
      ///
      ///   // Coordinates of first circle's bounding rectangle.
      ///   float x1 = 40;
      ///   float y1 = 40;
      ///
      ///   // Fill 3 over-lapping circles. Each circle is a different color.
      ///   g.fill_ellipse(trns_red_brush, x1, y1, 2 * tri_height, 2 * tri_height);
      ///   g.fill_ellipse(trns_green_brush, x1 + tri_base / 2, y1 + tri_height, 2 * tri_height, 2 * tri_height);
      ///   g.fill_ellipse(trns_blue_brush, x1 + tri_base, y1, 2 * tri_height, 2 * tri_height);
      /// }
      /// @endcode
      static xtd::drawing::color from_argb(uint32 argb) noexcept;
      
      /// @brief Creates a xtd::drawing::color class from the specified xtd::drawing::color structure, but with the new specified alpha value. Although this method allows a 32-bit value to be passed for the alpha value, the value is limited to 8 bits.
      /// @param alpha The alpha value for the new xtd::drawing::color. Valid values are 0 through 255.
      /// @param base_color The xtd::drawing::color from which to create the new xtd::drawing::color.
      /// @return xtd::drawing::color The xtd::drawing::color structure that this method creates.
      /// @par Examples
      /// The following code example is designed for use with Windows Forms, and it requires xtd::forms::paint_event_args e, which is a parameter of the xtd::forms::control::paint event handler. The code performs the following actions:
      /// * Creates xtd::drawing::color structures from the three color component values (red, green, blue). Three xtd::drawing::color structures are created, one for each primary color.
      /// * Iterates through a range of alpha values, changing the alpha value of a color.
      /// * During each iteration, sets the color of a brush to the modified color and paints a rectangle to show the color.
      /// * Repeats steps 2 and 3 for each primary color.
      /// The alpha value is never fully opaque and the rectangles overlap so you get color-combination effects.
      /// @code
      /// void from_argb2(paint_event_aArgs& e) {
      ///   graphics g = e.graphics();
      ///
      ///   // Opaque colors (alpha value defaults to 255 -- max value).
      ///   color red = color::from_argb(255, 0, 0);
      ///   color green = color::from_argb(0, 255, 0);
      ///   color blue = color::from_argb(0, 0, 255);
      ///
      ///   // Solid brush initialized to red.
      ///   solid_brush my_brush(red);
      ///   int alpha;
      ///
      ///   // x coordinate of first red rectangle
      ///   int x = 50;
      ///
      ///   // y coordinate of first red rectangle
      ///   int y = 50;
      ///
      ///   // Fill rectangles with red, varying the alpha value from 25 to 250.
      ///   for (alpha = 25; alpha <= 250; alpha += 25) {
      ///     my_brush.color(color::from_argb(alpha, red));
      ///     g.fill_rectangle(my_brush, x, y, 50, 100);
      ///     g.fill_rectangle(my_brush, x, y + 250, 50, 50);
      ///     x += 50;
      ///   }
      ///   // x coordinate of first green rectangle.
      ///   x = 50;
      ///
      ///   // y coordinate of first green rectangle.
      ///   y += 50;
      ///
      ///   // Fill rectangles with green, varying the alpha value from 25 to 250.
      ///   for (alpha = 25; alpha <= 250; alpha += 25) {
      ///     my_brush.color(color::from_argb(alpha, green));
      ///     g.fill_rectangle(my_brush, x, y, 50, 150);
      ///     x += 50;
      ///   }
      ///   // x coordinate of first blue rectangle.
      ///   x = 50;
      ///
      ///   // y coordinate of first blue rectangle.
      ///   y += 100;
      ///
      ///   // Fill rectangles with blue, varying the alpha value from 25 to 250.
      ///   for (alpha = 25; alpha <= 250; alpha += 25) {
      ///     my_brush.color(color::from_argb(alpha, blue));
      ///     g.fill_rectangle(my_brush, x, y, 50, 150);
      ///     x += 50;
      ///   }
      /// }
      /// @endcode
      static xtd::drawing::color from_argb(xtd::byte alpha, const xtd::drawing::color& base_color) noexcept;
      
      /// @brief Creates a xtd::drawing::color class from the four ARGB component (alpha, red, green, and blue) values. Although this method allows a 32-bit value to be passed for each component, the value of each component is limited to 8 bits.
      /// @param alpha The alpha value for the new xtd::drawing::color. Valid values are 0 through 255.
      /// @param red The red component. Valid values are 0 through 255.
      /// @param green The green component. Valid values are 0 through 255.
      /// @param blue The blue component. Valid values are 0 through 255.
      /// @return xtd::drawing::color The xtd::drawing::color structure that this method creates.
      /// @par Examples
      /// The following code example is designed for use with Windows Forms, and it requires xtd::forms::paint_event_args e, which is a parameter of the xtd::forms::control::paint event handler. The code performs the following actions:
      /// * Creates three brushes, each a different color. Each xtd::drawing::color structure that is used to create a brush is created from four component values (alpha, red, green, blue).
      /// * Uses an imaginary triangle to position three circles.
      /// * Paints three overlapping circles, each centered on one vertex of the triangle, using a different brush for each circle.
      /// @code
      /// void from_argb1(paint_event_args& e) {
      ///   graphics g = e.graphics();
      ///
      ///   // Transparent red, green, and blue brushes.
      ///   solid_brush trns_red_brush(color::from_argb(120, 255, 0, 0));
      ///   solid_brush trns_green_brush(color::from_argb(120, 0, 255, 0));
      ///   solid_brush trns_blue_brush(color::from_argb(120, 0, 0, 255));
      ///
      ///   // Base and height of the triangle that is used to position the circles. Each vertex of the triangle is at the center of one of the 3 circles. The base is equal to the diameter of the circles.
      ///   float tri_base = 100;
      ///   float tri_height = std::sqrt(3 * (tri_base * tri_base) / 4);
      ///
      ///   // Coordinates of first circle's bounding rectangle.
      ///   float x1 = 40;
      ///   float y1 = 40;
      ///
      ///   // Fill 3 over-lapping circles. Each circle is a different color.
      ///   g.fill_ellipse(trns_red_brush, x1, y1, 2 * tri_height, 2 * tri_height);
      ///   g.fill_ellipse(trns_green_brush, x1 + tri_base / 2, y1 + tri_height, 2 * tri_height, 2 * tri_height);
      ///   g.fill_ellipse(trns_blue_brush, x1 + tri_base, y1, 2 * tri_height, 2 * tri_height);
      /// }
      /// @endcode
      static xtd::drawing::color from_argb(xtd::byte alpha, xtd::byte red, xtd::byte green, xtd::byte blue) noexcept;
      
      /// @brief Creates a xtd::drawing::color structure from the specified 8-bit color values (red, green, and blue). The alpha value is implicitly 255 (fully opaque). Although this method allows a 32-bit value to be passed for each color component, the value of each component is limited to 8 bits.
      /// @param red The red component. Valid values are 0 through 255.
      /// @param green The green component. Valid values are 0 through 255.
      /// @param blue The blue component. Valid values are 0 through 255.
      /// @return xtd::drawing::color The xtd::drawing::color structure that this method creates.
      /// @par Examples
      /// The following code example is designed for use with Windows Forms, and it requires xtd::forms::paint_event_args e, which is a parameter of the xtd::forms::control::paint event handler. The code performs the following actions:
      /// * Creates xtd::drawing::color structures from the three color component values (red, green, blue). Three xtd::drawing::color structures are created, one for each primary color.
      /// * Iterates through a range of alpha values, changing the alpha value of a color.
      /// * During each iteration, sets the color of a brush to the modified color and paints a rectangle to show the color.
      /// * Repeats steps 2 and 3 for each primary color.
      /// The alpha value is never fully opaque and the rectangles overlap so you get color-combination effects.
      /// @code
      /// void from_argb2(paint_event_aArgs& e) {
      ///   graphics g = e.graphics();
      ///
      ///   // Opaque colors (alpha value defaults to 255 -- max value).
      ///   color red = color::from_argb(255, 0, 0);
      ///   color green = color::from_argb(0, 255, 0);
      ///   color blue = color::from_argb(0, 0, 255);
      ///
      ///   // Solid brush initialized to red.
      ///   solid_brush my_brush(red);
      ///   int alpha;
      ///
      ///   // x coordinate of first red rectangle
      ///   int x = 50;
      ///
      ///   // y coordinate of first red rectangle
      ///   int y = 50;
      ///
      ///   // Fill rectangles with red, varying the alpha value from 25 to 250.
      ///   for (alpha = 25; alpha <= 250; alpha += 25) {
      ///     my_brush.color(color::from_argb(alpha, red));
      ///     g.fill_rectangle(my_brush, x, y, 50, 100);
      ///     g.fill_rectangle(my_brush, x, y + 250, 50, 50);
      ///     x += 50;
      ///   }
      ///   // x coordinate of first green rectangle.
      ///   x = 50;
      ///
      ///   // y coordinate of first green rectangle.
      ///   y += 50;
      ///
      ///   // Fill rectangles with green, varying the alpha value from 25 to 250.
      ///   for (alpha = 25; alpha <= 250; alpha += 25) {
      ///     my_brush.color(color::from_argb(alpha, green));
      ///     g.fill_rectangle(my_brush, x, y, 50, 150);
      ///     x += 50;
      ///   }
      ///   // x coordinate of first blue rectangle.
      ///   x = 50;
      ///
      ///   // y coordinate of first blue rectangle.
      ///   y += 100;
      ///
      ///   // Fill rectangles with blue, varying the alpha value from 25 to 250.
      ///   for (alpha = 25; alpha <= 250; alpha += 25) {
      ///     my_brush.color(color::from_argb(alpha, blue));
      ///     g.fill_rectangle(my_brush, x, y, 50, 150);
      ///     x += 50;
      ///   }
      /// }
      /// @endcode
      static xtd::drawing::color from_argb(xtd::byte red, xtd::byte green, xtd::byte blue) noexcept;
      
      /// @brief Creates a xtd::drawing::color class from native handle.
      /// @param handle the handle for the new xtd::drawing::color.
      /// @return xtd::drawing::color The xtd::drawing::color structure that this method creates.
      /// @remarks For internal use only.
      static xtd::drawing::color from_handle(intptr handle) noexcept;
      
      /// @brief Creates a xtd::drawing::color class from the three HSV component (hue, saturation, and brightness) values.
      /// @param hue The xtd::drawing::color saturation. The saturation ranges from 0.0 through 1.0, where 0.0 is grayscale and 1.0 is the most saturated.
      /// @param saturation The xtd::drawing::color saturation. The saturation ranges from 0.0 through 1.0, where 0.0 is grayscale and 1.0 is the most saturated.
      /// @param brightness The xtd::drawing::color lightness. The brightness ranges from 0.0 through 1.0, where 0.0 represents black and 1.0 represents white.
      /// @return xtd::drawing::color The xtd::drawing::color structure that this method creates.
      static xtd::drawing::color from_hsb(float hue, float saturation, float brightness) noexcept;
      
      /// @brief Creates a xtd::drawing::color class from the three HSL component (hue, saturation, and lightness) values.
      /// @param hue The xtd::drawing::color saturation. The saturation ranges from 0.0 through 1.0, where 0.0 is grayscale and 1.0 is the most saturated.
      /// @param saturation The xtd::drawing::color saturation. The saturation ranges from 0.0 through 1.0, where 0.0 is grayscale and 1.0 is the most saturated.
      /// @param lightness The xtd::drawing::color lightness. The lightness ranges from 0.0 through 1.0, where 0.0 represents black and 1.0 represents white.
      /// @return xtd::drawing::color The xtd::drawing::color structure that this method creates.
      static xtd::drawing::color from_hsl(float hue, float saturation, float lightness) noexcept;
      
      /// @brief Creates a xtd::drawing::color class from the four ARGB component (alpha, red, green, and blue) values. Although this method allows a 32-bit value to be passed for each component, the value of each component is limited to 8 bits.
      /// @param alpha The alpha value for the new xtd::drawing::color. Valid values are 0 through 255.
      /// @param red The red component. Valid values are 0 through 255.
      /// @param green The green component. Valid values are 0 through 255.
      /// @param blue The blue component. Valid values are 0 through 255.
      /// @return xtd::drawing::color The xtd::drawing::color structure that this method creates.
      /// @exception std::invalid_argument color is not a known_color.
      /// @par Examples
      /// The following code example is designed for use with Windows Forms, and it requires xtd::forms::paint_event_args, which is a parameter of the xtd::forms::control::paint event handler. The code performs the following actions:
      /// * Creates an instance of a xtd::drawing::color structure, redShade, to be used for comparisons.
      /// * Iterates through the xtd::drawing::known_color enumeration elements to find all known colors that have the same lightness as redShade. The iterations are terminated when 15 matches are found or the value of the loop counter is greater than the last xtd::drawing::known_color element.
      /// * During each iteration, saves the xtd::drawing::known_color element—if it matches the criteria—in an array.
      /// * Uses a brush to paint rectangles.
      /// The first rectangle is painted the color represented by redShade. Each of the other rectangles is painted a xtd::drawing::known_color that matches the hue of the redShade.
      /// @code
      /// void known_color_brightness_example2(paint_event_args& e) {
      ///   graphics g = e.graphics();
      ///
      ///   // xtd::drawing::color structures. One is a variable used for temporary storage. The other is a constant used for comparisons.
      ///   xtd::drawing::color some_color = xtd::drawing::color::from_argb(0);
      ///   xtd::drawing::color red_shade = xtd::drawing::color::from_argb(255, 200, 0, 100);
      ///
      ///   // Array to store xtd::drawing::known_color values that match the hue of the redShade color.
      ///   std::vector<xtd::drawing::known_color> color_matches(15);
      ///
      ///   // Number of matches found.
      ///   int count = 0;
      ///
      ///   // Iterate through the xtd::drawing::known_color enums until 15 matches are found.
      ///   for (xtd::drawing::known_color enum_value = 0; enum_value <= xtd::drawing::known_color::yellow_green && count < 15; enum_value = known_color(int(enum_value) + 1)) {
      ///     some_color = xtd::drawing::color::from_known_color(enum_value);
      ///     if (some_color.get_brightness() == red_shade.get_brightness())
      ///       color_matches[count++] = enum_value;
      ///   }
      ///
      ///   // Display the redShade color and its argb value.
      ///   solid_brush  my_brush1(red_shade);
      ///   font my_font("Arial", 12);
      ///   int x = 20;
      ///   int y = 20;
      ///   some_color = red_shade;
      ///   g.fill_rectangle(my_brush1, x, y, 100, 30);
      ///   g.draw_string(some_color.to_string(), my_font, brushes::black, x + 120, y);
      ///
      ///   // Iterate through the matches that were found and display each color that corresponds with the enum value in the array. also display the name of the xtd::drawing::known_color.
      ///   for (int i = 0; i < count; i++) {
      ///     y += 40;
      ///     some_color = xtd::drawing::color::from_known_color(color_matches[i]);
      ///     my_brush1.xtd::drawing::color = some_color;
      ///     g.fill_rectangle(my_brush1, x, y, 100, 30);
      ///     g.draw_string(some_color.to_string(), my_font, brushes::black, x + 120, y);
      ///   }
      /// }
      /// @endcode
      static xtd::drawing::color from_known_color(xtd::drawing::known_color color);
      
      /// @brief Creates a xtd::drawing::color class from the specified name of a predefined color.
      /// @param name A string that is the name of a predefined color. Valid names are the same as the names of the elements of the xtd::drawing::known_color enumeration.
      /// @return xtd::drawing::color The xtd::drawing::color structure that this method creates.
      /// @remarks A predefined color is also called a known color and is represented by an element of the xtd::drawing::known_color enumeration. If the name parameter is not the valid name of a predefined color, the xtd::drawing::color::from_name method creates a xtd::drawing::color structure that has an ARGB value of 0 (that is, all ARGB components are 0).
      /// @par Examples
      /// The following code example demonstrates the xtd::drawing::color::a, xtd::drawing::color::r, xtd::drawing::color::g, and xtd::drawing::color::b properties of a xtd::drawing::color, and the Implicit(size to size_f) member.<br>
      /// This example is designed to be used with a Windows Form (xtd::forms). Paste the code into the form and call the show_properties_of_slate_blue method from the form's  xtd::forms::control::paint event-handling method, passing e as xtd::forms::paint_event_args.
      /// @code
      /// void show_properties_of_slate_blue(xtd::forms::paint_event_args& e) {
      ///   color slate_blue = xtd::drawing::color::from_name("slate blue");
      ///   byte g = slate_blue.g();
      ///   byte b = slate_blue.b();
      ///   byte r = slate_blue.r();
      ///   byte a = slate_blue.a();
      ///   string text = xtd::ustring::format("Slate blue has these ARGB values: alpha:{0}, red:{1}, green: {2}, blue {3}", a, r, g, b);
      ///   e.graphics().draw_string(text, xtd::drawing::font(font(), xtd::drawing::font_style::italic), xtd::drawing::solid_brush(slate_blue), xtd::drawing::rectangle_f(xtd::drawing::point_f(0.0f, 0.0f), size()));
      /// }
      /// @endcode
      static xtd::drawing::color from_name(const xtd::ustring& name) noexcept;
      
      /// @brief Creates a xtd::drawing::color class from the three YUV components (luma and choma) values.
      /// @param y The Y'UV `Y` value of this xtd::drawing::color. The y ranges from 0.0 through 1.0, where 0.0 represents black and 1.0 represents white.
      /// @param u The Y'UV `U` value of this xtd::drawing::color. The y ranges from -0.5 through0.5. When `U` and `V` are both 0, the color is neutral (gray). Positive `U` values represent the red-green axis, and positive `V` values represent the blue-yellow axis
      /// @param v The Y'UV `V` value of this xtd::drawing::color. The y ranges from -0.5 through0.5. When `U` and `V` are both 0, the color is neutral (gray). Positive `U` values represent the red-green axis, and positive `V` values represent the blue-yellow axis
      /// @return xtd::drawing::color The xtd::drawing::color structure that this method creates.
      static xtd::drawing::color from_yuv(float y, float u, float v) noexcept;

      /// @brief Creates a new lighter color of the specified color with 33% factor.
      /// @param color The color to light.
      /// @return The new color.
      /// @deprecated Replaced by xtd::drawing::color_converter::light - Will be removed in version 0.4.0
      [[deprecated("Replaced by xtd::drawing::color_converter::light - Will be removed in version 0.4.0")]]
      static color light(const color& color) noexcept;
      /// @brief Creates a new lighter color of the specified color with specified percent factor.
      /// @param color The color to light.
      /// @param percent The lighter factor in % (from 0.0 to 1.0).
      /// @return The new color.
      /// @remarks Thus, a percent value of `1.0` will return the xtd::drawing::color::black, while a value of `0.0` will return the color.
      /// @deprecated Replaced by xtd::drawing::color_converter::light - Will be removed in version 0.4.0
      [[deprecated("Replaced by xtd::drawing::color_converter::light - Will be removed in version 0.4.0")]]
      static color light(const color& color, double percent) noexcept;
      
      /// @brief Creates a xtd::drawing::color class from the specified name.
      /// @param name A string that is the name of a predefined color. Valid names are the same as the names of the elements of the xtd::drawing::known_color enumeration or hexadecimal value that represents argb value, or four decimal values separated by a comma representing respectively a, r, g, b, values.
      /// @return xtd::drawing::color The xtd::drawing::color structure that this method creates.
      static xtd::drawing::color parse(const xtd::ustring& color) noexcept;
      /// @}
      
    private:
      static constexpr xtd::drawing::known_color start_know_system_colors_range = static_cast<xtd::drawing::known_color>(0xFF01);
      explicit color(uint32 argb);
      explicit color(intptr handle);
      color(const color& color, const xtd::drawing::known_color& know_color);
      
      uint32 argb_ = 0;
      bool empty_ = true;
      intptr handle_ = 0;
      xtd::drawing::known_color known_color_ = static_cast<xtd::drawing::known_color>(0);
      xtd::ustring name_;
    };
  }
  
  /// @brief Creates a xtd::drawing::color class from the specified name.
  /// @param name A string that is the name of a predefined color. Valid names are the same as the names of the elements of the xtd::drawing::known_color enumeration or hexadecimal value that represents argb value, or four decimal values separated by a comma representing respectively a, r, g, b, values.
  /// @return xtd::drawing::color The xtd::drawing::color structure that this method creates.
  /// @ingroup format_parse
  template<>
  inline drawing::color parse<drawing::color>(const std::string& str) {
    return drawing::color::parse(str);
  }
}
