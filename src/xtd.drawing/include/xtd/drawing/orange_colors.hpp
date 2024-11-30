/// @file
/// @brief Contains xtd::drawing::orange_colors factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "color.hpp"
#include <xtd/static>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Orange colors for all the hmtl orange colors. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ orange_colors final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::orange_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ orange_colors final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_coral.png
      static xtd::drawing::color coral() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_orange_red.png
      static xtd::drawing::color orange_red() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_tomato.png
      static xtd::drawing::color tomato() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_orange.png
      static xtd::drawing::color dark_orange() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_orange.png
      static xtd::drawing::color orange() noexcept;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of colors.
      static const std::vector<xtd::drawing::color>& get_colors() noexcept;
      
      /// @brief Gets an array of color names.
      static const std::vector<xtd::string>& get_color_names() noexcept;
      /// @}
    };
  }
}
