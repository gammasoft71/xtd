/// @file
/// @brief Contains xtd::drawing::purple_colors factory.
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
    /// @brief Purple, violet and magenta colors for all the hmtl purple, violet and magenta colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ purple_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::purple_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ purple_colors final static_ {
    public:
      /// @name Static properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_blue_violet.png
      static xtd::drawing::color blue_violet() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_magenta.png
      static xtd::drawing::color dark_magenta() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_orchid.png
      static xtd::drawing::color dark_orchid() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_slate_blue.png
      static xtd::drawing::color dark_slate_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_violet.png
      static xtd::drawing::color dark_violet() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_fuchsia.png
      static xtd::drawing::color fuchsia() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_indigo.png
      static xtd::drawing::color indigo() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_lavender.png
      static xtd::drawing::color lavender() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_magenta.png
      static xtd::drawing::color magenta() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_orchid.png
      static xtd::drawing::color medium_orchid() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_purple.png
      static xtd::drawing::color medium_purple() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_slate_blue.png
      static xtd::drawing::color medium_slate_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_orchid.png
      static xtd::drawing::color orchid() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_plum.png
      static xtd::drawing::color plum() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_purple.png
      static xtd::drawing::color purple() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_rebecca_purple.png
      static xtd::drawing::color rebecca_purple() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_slate_blue.png
      static xtd::drawing::color slate_blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_thistle.png
      static xtd::drawing::color thistle() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_violet.png
      static xtd::drawing::color violet() noexcept;
      /// @}
      
      /// @name Static methods
      
      /// @{
      /// @brief Gets an array of colors.
      static const std::vector<xtd::drawing::color>& get_colors() noexcept;
      
      /// @brief Gets an array of color names.
      static const std::vector<xtd::ustring>& get_color_names() noexcept;
      /// @}
    };
  }
}
