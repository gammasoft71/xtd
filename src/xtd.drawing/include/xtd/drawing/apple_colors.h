/// @file
/// @brief Contains xtd::drawing::apple_colors factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "gray_colors.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Apple colors for all the Apple colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ apple_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::apple_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing colors
    class drawing_export_ apple_colors final static_ {
    public:
      /// @name Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html apple_colors_black.png
      static xtd::drawing::color black() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_blue.png
      static xtd::drawing::color blue() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_brown.png
      static xtd::drawing::color brown() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_cyan.png
      static xtd::drawing::color cyan() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_green.png
      static xtd::drawing::color green() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_magenta.png
      static xtd::drawing::color magenta() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_orange.png
      static xtd::drawing::color orange() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_purple.png
      static xtd::drawing::color purple() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_red.png
      static xtd::drawing::color red() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_yellow.png
      static xtd::drawing::color yellow() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_white.png
      static xtd::drawing::color white() noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Gets an array of colors.
      static const std::vector<xtd::drawing::color>& get_colors() noexcept;
      
      
      static const std::vector<xtd::ustring>& get_color_names() noexcept;
      /// @}
    };
  }
}
