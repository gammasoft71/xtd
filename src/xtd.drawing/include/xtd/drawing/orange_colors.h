/// @file
/// @brief Contains xtd::drawing::orange_colors factory.
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
    /// @brief Orange colors for all the hmtl orange colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ orange_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::orange_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ orange_colors final static_ {
    public:
      /// @name Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_coral.png
      static xtd::drawing::color coral();
      
      /// @brief A system-defined color object.
      /// @image html colors_orange_red.png
      static xtd::drawing::color orange_red();
      
      /// @brief A system-defined color object.
      /// @image html colors_tomato.png
      static xtd::drawing::color tomato();
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_orange.png
      static xtd::drawing::color dark_orange();
      
      /// @brief A system-defined color object.
      /// @image html colors_orange.png
      static xtd::drawing::color orange();
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
