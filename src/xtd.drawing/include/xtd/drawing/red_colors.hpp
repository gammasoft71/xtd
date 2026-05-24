/// @file
/// @brief Contains xtd::drawing::red_colors factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "color.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Red colors for all the hmtl red colors. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ red_colors final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::red_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ red_colors final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_crimson.png
      [[nodiscard]] static auto crimson() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_red.png
      [[nodiscard]] static auto dark_red() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_salmon.png
      [[nodiscard]] static auto dark_salmon() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_firebrick.png
      [[nodiscard]] static auto firebrick() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_indian_red.png
      [[nodiscard]] static auto indian_red() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_coral.png
      [[nodiscard]] static auto light_coral() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_salmon.png
      [[nodiscard]] static auto light_salmon() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_red.png
      [[nodiscard]] static auto red() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_salmon.png
      [[nodiscard]] static auto salmon() noexcept -> xtd::drawing::color;
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
