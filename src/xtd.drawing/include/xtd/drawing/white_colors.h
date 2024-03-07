/// @file
/// @brief Contains xtd::drawing::white_colors factory.
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
    /// @ingroup xtd_drawing colors
    class drawing_export_ white_colors final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_alice_blue.png
      static xtd::drawing::color alice_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_antique_white.png
      static xtd::drawing::color antique_white() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_azure.png
      static xtd::drawing::color azure() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_beige.png
      static xtd::drawing::color beige() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_floral_white.png
      static xtd::drawing::color floral_white() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_ghost_white.png
      static xtd::drawing::color ghost_white() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_honeydew.png
      static xtd::drawing::color honeydew() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_ivory.png
      static xtd::drawing::color ivory() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_lavender_blush.png
      static xtd::drawing::color lavender_blush() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_linen.png
      static xtd::drawing::color linen() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_mint_cream.png
      static xtd::drawing::color mint_cream() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_misty_rose.png
      static xtd::drawing::color misty_rose() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_old_lace.png
      static xtd::drawing::color old_lace() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_sea_shell.png
      static xtd::drawing::color sea_shell() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_snow.png
      static xtd::drawing::color snow() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_white.png
      static xtd::drawing::color white() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_white_smoke.png
      static xtd::drawing::color white_smoke() noexcept;
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
