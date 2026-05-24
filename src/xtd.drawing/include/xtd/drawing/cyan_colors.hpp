/// @file
/// @brief Contains xtd::drawing::cyan_colors factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "color.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Cyan colors for all the hmtl cyan colors. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ cyan_colors final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::cyan_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ cyan_colors final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_aqua.png
      [[nodiscard]] static auto aqua() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_aquamarine.png
      [[nodiscard]] static auto aquamarine() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_cadet_blue.png
      [[nodiscard]] static auto cadet_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_cyan.png
      [[nodiscard]] static auto cyan() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_cyan.png
      [[nodiscard]] static auto dark_cyan() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_turquoise.png
      [[nodiscard]] static auto dark_turquoise() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_cyan.png
      [[nodiscard]] static auto light_cyan() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_sea_green.png
      [[nodiscard]] static auto light_sea_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_turquoise.png
      [[nodiscard]] static auto medium_turquoise() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_turquoise.png
      [[nodiscard]] static auto pale_turquoise() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_teal.png
      [[nodiscard]] static auto teal() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_turquoise.png
      [[nodiscard]] static auto turquoise() noexcept -> xtd::drawing::color;
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
