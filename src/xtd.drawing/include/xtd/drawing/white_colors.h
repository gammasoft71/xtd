/// @file
/// @brief Contains xtd::drawing::white_colors factory.
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
    /// @brief White colors for all the hmtl white colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ white_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::white_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ white_colors final static_ {
    public:
      /// @name Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_alice_blue.png
      static xtd::drawing::color alice_blue();
      
      /// @brief A system-defined color object.
      /// @image html colors_antique_white.png
      static xtd::drawing::color antique_white();
      
      /// @brief A system-defined color object.
      /// @image html colors_azure.png
      static xtd::drawing::color azure();
      
      /// @brief A system-defined color object.
      /// @image html colors_beige.png
      static xtd::drawing::color beige();
      
      /// @brief A system-defined color object.
      /// @image html colors_floral_white.png
      static xtd::drawing::color floral_white();
      
      /// @brief A system-defined color object.
      /// @image html colors_ghost_white.png
      static xtd::drawing::color ghost_white();
      
      /// @brief A system-defined color object.
      /// @image html colors_honeydew.png
      static xtd::drawing::color honeydew();
      
      /// @brief A system-defined color object.
      /// @image html colors_ivory.png
      static xtd::drawing::color ivory();
      
      /// @brief A system-defined color object.
      /// @image html colors_lavender_blush.png
      static xtd::drawing::color lavender_blush();
      
      /// @brief A system-defined color object.
      /// @image html colors_linen.png
      static xtd::drawing::color linen();
      
      /// @brief A system-defined color object.
      /// @image html colors_mint_cream.png
      static xtd::drawing::color mint_cream();
      
      /// @brief A system-defined color object.
      /// @image html colors_misty_rose.png
      static xtd::drawing::color misty_rose();
      
      /// @brief A system-defined color object.
      /// @image html colors_old_lace.png
      static xtd::drawing::color old_lace();
      
      /// @brief A system-defined color object.
      /// @image html colors_sea_shell.png
      static xtd::drawing::color sea_shell();
      
      /// @brief A system-defined color object.
      /// @image html colors_snow.png
      static xtd::drawing::color snow();
      
      /// @brief A system-defined color object.
      /// @image html colors_white.png
      static xtd::drawing::color white();
      
      /// @brief A system-defined color object.
      /// @image html colors_white_smoke.png
      static xtd::drawing::color white_smoke();
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
