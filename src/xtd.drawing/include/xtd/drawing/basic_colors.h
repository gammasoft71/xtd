/// @file
/// @brief Contains xtd::drawing::basic_colors factory.
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
    /// @brief Basic colors for all the hmtl basic colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ basic_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::basic_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ basic_colors final static_ {
    public:
      /// @name Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_aqua.png
      static xtd::drawing::color aqua();
      
      /// @brief A system-defined color object.
      /// @image html colors_black.png
      static xtd::drawing::color black();
      
      /// @brief A system-defined color object.
      /// @image html colors_blue.png
      static xtd::drawing::color blue();
      
      /// @brief A system-defined color object.
      /// @image html colors_fuchsia.png
      static xtd::drawing::color fuchsia();
      
      /// @brief A system-defined color object.
      /// @image html colors_gray.png
      static xtd::drawing::color gray();
      
      /// @brief A system-defined color object.
      /// @image html colors_green.png
      static xtd::drawing::color green();
      
      /// @brief A system-defined color object.
      /// @image html colors_lime.png
      static xtd::drawing::color lime();
      
      /// @brief A system-defined color object.
      /// @image html colors_maroon.png
      static xtd::drawing::color maroon();
      
      /// @brief A system-defined color object.
      /// @image html colors_navy.png
      static xtd::drawing::color navy();
      
      /// @brief A system-defined color object.
      /// @image html colors_olive.png
      static xtd::drawing::color olive();
      
      /// @brief A system-defined color object.
      /// @image html colors_purple.png
      static xtd::drawing::color purple();
      
      /// @brief A system-defined color object.
      /// @image html colors_red.png
      static xtd::drawing::color red();
      
      /// @brief A system-defined color object.
      /// @image html colors_silver.png
      static xtd::drawing::color silver();
      
      /// @brief A system-defined color object.
      /// @image html colors_teal.png
      static xtd::drawing::color teal();
      
      /// @brief A system-defined color object.
      /// @image html colors_white.png
      static xtd::drawing::color white();
      
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
