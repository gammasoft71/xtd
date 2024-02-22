/// @file
/// @brief Contains xtd::drawing::green_colors factory.
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
    /// @brief Green colors for all the hmtl green colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ green_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::green_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ green_colors final static_ {
    public:
      /// @name Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_chartreuse.png
      static xtd::drawing::color chartreuse() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_green.png
      static xtd::drawing::color dark_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_olive_green.png
      static xtd::drawing::color dark_olive_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_sea_green.png
      static xtd::drawing::color dark_sea_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_green.png
      static xtd::drawing::color green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_green_yellow.png
      static xtd::drawing::color green_yellow() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_forest_green.png
      static xtd::drawing::color forest_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_lawn_green.png
      static xtd::drawing::color lawn_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_green.png
      static xtd::drawing::color light_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_lime.png
      static xtd::drawing::color lime() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_lime_green.png
      static xtd::drawing::color lime_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_aquamarine.png
      static xtd::drawing::color medium_aquamarine() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_sea_green.png
      static xtd::drawing::color medium_sea_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_spring_green.png
      static xtd::drawing::color medium_spring_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_olive.png
      static xtd::drawing::color olive() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_olive_drab.png
      static xtd::drawing::color olive_drab() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_green.png
      static xtd::drawing::color pale_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_sea_green.png
      static xtd::drawing::color sea_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_spring_green.png
      static xtd::drawing::color spring_green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_yellow_green.png
      static xtd::drawing::color yellow_green() noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Gets an array of colors.
      static const std::vector<xtd::drawing::color>& get_colors() noexcept;
      
      /// @brief Gets an array of color_names.
      static const std::vector<xtd::ustring>& get_color_names() noexcept;
      /// @}
    };
  }
}
