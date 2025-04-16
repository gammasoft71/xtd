/// @file
/// @brief Contains xtd::drawing::red_colors factory.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "color.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Red colors for all the hmtl red colors. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ red_colors final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::red_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ red_colors final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_crimson.png
      static xtd::drawing::color crimson() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_red.png
      static xtd::drawing::color dark_red() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_salmon.png
      static xtd::drawing::color dark_salmon() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_firebrick.png
      static xtd::drawing::color firebrick() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_indian_red.png
      static xtd::drawing::color indian_red() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_coral.png
      static xtd::drawing::color light_coral() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_salmon.png
      static xtd::drawing::color light_salmon() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_red.png
      static xtd::drawing::color red() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_salmon.png
      static xtd::drawing::color salmon() noexcept;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of colors.
      static const xtd::array<xtd::drawing::color>& get_colors() noexcept;
      
      /// @brief Gets an array of color names.
      static const xtd::array<xtd::string>& get_color_names() noexcept;
      /// @}
    };
  }
}
