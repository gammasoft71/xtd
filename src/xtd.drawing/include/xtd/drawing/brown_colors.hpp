/// @file
/// @brief Contains xtd::drawing::brown_colors factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "color.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Brown colors for all the hmtl brown colors. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ brown_colors final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::brown_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ brown_colors final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_bisque.png
      [[nodiscard]] static auto bisque() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_blanched_almond.png
      [[nodiscard]] static auto blanched_almond() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_brown.png
      [[nodiscard]] static auto brown() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_burly_wood.png
      [[nodiscard]] static auto burly_wood() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_chocolate.png
      [[nodiscard]] static auto chocolate() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_cornsilk.png
      [[nodiscard]] static auto cornsilk() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_goldenrod.png
      [[nodiscard]] static auto dark_goldenrod() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_goldenrod.png
      [[nodiscard]] static auto goldenrod() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_maroon.png
      [[nodiscard]] static auto maroon() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_navajo_white.png
      [[nodiscard]] static auto navajo_white() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_peru.png
      [[nodiscard]] static auto peru() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_rosy_brown.png
      [[nodiscard]] static auto rosy_brown() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_saddle_brown.png
      [[nodiscard]] static auto saddle_brown() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_sandy_brown.png
      [[nodiscard]] static auto sandy_brown() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_sienna.png
      [[nodiscard]] static auto sienna() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_tan.png
      [[nodiscard]] static auto tan() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_wheat.png
      [[nodiscard]] static auto wheat() noexcept -> xtd::drawing::color;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of colors.
      [[nodiscard]] static auto get_colors() noexcept -> const xtd::array<xtd::drawing::color>&;
      
      /// @brief Gets an array of color names.
      [[nodiscard]] static auto get_color_names() noexcept -> const xtd::array<xtd::string>&;
      /// @}
    };
  }
}
