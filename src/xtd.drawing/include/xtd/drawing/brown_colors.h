/// @file
/// @brief Contains xtd::drawing::brown_colors factory.
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
    /// @brief Brown colors for all the hmtl brown colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ brown_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::brown_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ brown_colors final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_bisque.png
      static xtd::drawing::color bisque() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_blanched_almond.png
      static xtd::drawing::color blanched_almond() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_brown.png
      static xtd::drawing::color brown() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_burly_wood.png
      static xtd::drawing::color burly_wood() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_chocolate.png
      static xtd::drawing::color chocolate() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_cornsilk.png
      static xtd::drawing::color cornsilk() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_goldenrod.png
      static xtd::drawing::color dark_goldenrod() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_goldenrod.png
      static xtd::drawing::color goldenrod() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_maroon.png
      static xtd::drawing::color maroon() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_navajo_white.png
      static xtd::drawing::color navajo_white() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_peru.png
      static xtd::drawing::color peru() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_rosy_brown.png
      static xtd::drawing::color rosy_brown() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_saddle_brown.png
      static xtd::drawing::color saddle_brown() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_sandy_brown.png
      static xtd::drawing::color sandy_brown() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_sienna.png
      static xtd::drawing::color sienna() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_tan.png
      static xtd::drawing::color tan() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_wheat.png
      static xtd::drawing::color wheat() noexcept;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of colors.
      static const std::vector<xtd::drawing::color>& get_colors() noexcept;
      
      /// @brief Gets an array of color names.
      static const std::vector<xtd::ustring>& get_color_names() noexcept;
      /// @}
    };
  }
}
