/// @file
/// @brief Contains xtd::drawing::blue_colors factory.
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
    /// @brief Blue colors for all the hmtl blue colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ blue_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::blue_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ blue_colors final static_ {
    public:
      /// @name Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_blue.png
      static xtd::drawing::color blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_cornflower_blue.png
      static xtd::drawing::color cornflower_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_blue.png
      static xtd::drawing::color dark_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_deep_sky_blue.png
      static xtd::drawing::color deep_sky_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dodger_blue.png
      static xtd::drawing::color dodger_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_blue.png
      static xtd::drawing::color light_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_sky_blue.png
      static xtd::drawing::color light_sky_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_steel_blue.png
      static xtd::drawing::color light_steel_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_blue.png
      static xtd::drawing::color medium_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_midnight_blue.png
      static xtd::drawing::color midnight_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_navy.png
      static xtd::drawing::color navy() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_powder_blue.png
      static xtd::drawing::color powder_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_royal_blue.png
      static xtd::drawing::color royal_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_sky_blue.png
      static xtd::drawing::color sky_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_steel_blue.png
      static xtd::drawing::color steel_blue() noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Gets an array of colors.
      static const std::vector<xtd::drawing::color>& get_colors() noexcept;
      

      static const std::vector<xtd::ustring>& get_color_names() noexcept;
      /// @}
    };
  }
}
