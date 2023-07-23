/// @file
/// @brief Contains xtd::drawing::red_colors factory.
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
    /// @brief Red colors for all the hmtl red colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ red_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::red_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ red_colors final static_ {
    public:
      /// @name Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_crimson.png
      static xtd::drawing::color crimson();
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_red.png
      static xtd::drawing::color dark_red();
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_salmon.png
      static xtd::drawing::color dark_salmon();
      
      /// @brief A system-defined color object.
      /// @image html colors_firebrick.png
      static xtd::drawing::color firebrick();
      
      /// @brief A system-defined color object.
      /// @image html colors_indian_red.png
      static xtd::drawing::color indian_red();
      
      /// @brief A system-defined color object.
      /// @image html colors_light_coral.png
      static xtd::drawing::color light_coral();
      
      /// @brief A system-defined color object.
      /// @image html colors_light_salmon.png
      static xtd::drawing::color light_salmon();
      
      /// @brief A system-defined color object.
      /// @image html colors_red.png
      static xtd::drawing::color red();
      
      /// @brief A system-defined color object.
      /// @image html colors_salmon.png
      static xtd::drawing::color salmon();
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
