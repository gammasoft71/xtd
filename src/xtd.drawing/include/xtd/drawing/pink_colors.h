/// @file
/// @brief Contains xtd::drawing::pink_colors factory.
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
    /// @brief Pink colors for all the hmtl pink colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ pink_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::pink_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing colors
    class drawing_export_ pink_colors final static_ {
    public:
      /// @name Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_deep_pink.png
      static xtd::drawing::color deep_pink() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_hot_pink.png
      static xtd::drawing::color hot_pink() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_pink.png
      static xtd::drawing::color light_pink() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_violet_red.png
      static xtd::drawing::color medium_violet_red() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_violet_red.png
      static xtd::drawing::color pale_violet_red() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_pink.png
      static xtd::drawing::color pink() noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Gets an array of colors.
      static const std::vector<xtd::drawing::color>& get_colors() noexcept;
      
      /// @brief Gets an array of color names.
      static const std::vector<xtd::ustring>& get_color_names() noexcept;
      /// @}
    };
  }
}
