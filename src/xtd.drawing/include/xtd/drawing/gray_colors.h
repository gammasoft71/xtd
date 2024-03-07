/// @file
/// @brief Contains xtd::drawing::gray_colors factory.
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
    /// @brief Gray and black colors for all the hmtl gray and black colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ gray_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::gray_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ gray_colors final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_black.png
      static xtd::drawing::color black() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_gray.png
      static xtd::drawing::color dark_gray() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_slate_gray.png
      static xtd::drawing::color dark_slate_gray() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dim_gray.png
      static xtd::drawing::color dim_gray() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_gainsboro.png
      static xtd::drawing::color gainsboro() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_gray.png
      static xtd::drawing::color gray() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_gray.png
      static xtd::drawing::color light_gray() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_slate_gray.png
      static xtd::drawing::color light_slate_gray() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_silver.png
      static xtd::drawing::color silver() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_slate_gray.png
      static xtd::drawing::color slate_gray() noexcept;
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
