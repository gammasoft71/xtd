/// @file
/// @brief Contains xtd::drawing::gray_colors factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "color.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Gray and black colors for all the hmtl gray and black colors. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ gray_colors final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::gray_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ gray_colors final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_black.png
      [[nodiscard]] static auto black() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_gray.png
      [[nodiscard]] static auto dark_gray() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_slate_gray.png
      [[nodiscard]] static auto dark_slate_gray() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dim_gray.png
      [[nodiscard]] static auto dim_gray() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_gainsboro.png
      [[nodiscard]] static auto gainsboro() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_gray.png
      [[nodiscard]] static auto gray() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_gray.png
      [[nodiscard]] static auto light_gray() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_slate_gray.png
      [[nodiscard]] static auto light_slate_gray() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_silver.png
      [[nodiscard]] static auto silver() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_slate_gray.png
      [[nodiscard]] static auto slate_gray() noexcept -> xtd::drawing::color;
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
