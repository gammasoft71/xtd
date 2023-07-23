/// @file
/// @brief Contains xtd::drawing::yellow_colors factory.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <vector>
#include <xtd/static.h>
#include "../drawing_export.h"
#include "color.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d/, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Yellow colors for all the hmtl yellow colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ yellow_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::yellow_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ yellow_colors final static_ {
    public:
      /// @name Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_dark_khaki.png
      static xtd::drawing::color dark_khaki();
      
      /// @brief A system-defined color object.
      /// @image html colors_gold.png
      static xtd::drawing::color gold();
      
      /// @brief A system-defined color object.
      /// @image html colors_khaki.png
      static xtd::drawing::color khaki();
      
      /// @brief A system-defined color object.
      /// @image html colors_lemon_chiffon.png
      static xtd::drawing::color lemon_chiffon();
      
      /// @brief A system-defined color object.
      /// @image html colors_light_goldenrod_yellow.png
      static xtd::drawing::color light_goldenrod_yellow();
      
      /// @brief A system-defined color object.
      /// @image html colors_light_yellow.png
      static xtd::drawing::color light_yellow();
      
      /// @brief A system-defined color object.
      /// @image html colors_moccasin.png
      static xtd::drawing::color moccasin();
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_goldenrod.png
      static xtd::drawing::color pale_goldenrod();
      
      /// @brief A system-defined color object.
      /// @image html colors_papaya_whip.png
      static xtd::drawing::color papaya_whip();
      
      /// @brief A system-defined color object.
      /// @image html colors_peach_puff.png
      static xtd::drawing::color peach_puff();
      
      /// @brief A system-defined color object.
      /// @image html colors_yellow.png
      static xtd::drawing::color yellow();
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Gets an array of colors.
      static const std::vector<xtd::drawing::color>& get_colors();
      
      /// @brief Gets an array of color names.
      static const std::vector<xtd::ustring>& get_color_names();
      /// @}
    };
  }
}
