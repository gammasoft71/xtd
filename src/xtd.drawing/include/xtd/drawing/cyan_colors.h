/// @file
/// @brief Contains xtd::drawing::cyan_colors factory.
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
    /// @brief Cyan colors for all the hmtl cyan colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ cyan_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::cyan_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ cyan_colors final static_ {
    public:
      /// @name Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_aqua.png
      static xtd::drawing::color aqua() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_aquamarine.png
      static xtd::drawing::color aquamarine() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_cadet_blue.png
      static xtd::drawing::color cadet_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_cyan.png
      static xtd::drawing::color cyan() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_cyan.png
      static xtd::drawing::color dark_cyan() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_turquoise.png
      static xtd::drawing::color dark_turquoise() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_cyan.png
      static xtd::drawing::color light_cyan() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_sea_green.png
      static xtd::drawing::color light_sea_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_turquoise.png
      static xtd::drawing::color medium_turquoise() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_turquoise.png
      static xtd::drawing::color pale_turquoise() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_teal.png
      static xtd::drawing::color teal() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_turquoise.png
      static xtd::drawing::color turquoise() noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Gets an array of colors.
      static const std::vector<xtd::drawing::color>& get_colors() noexcept;
      
      /// @brief Gets an array of color names.
      static const std::vector<xtd::ustring>& get_color_names() noexcept;
      /// @}
    };
  }
}
