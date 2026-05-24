/// @file
/// @brief Contains xtd::drawing::orange_colors factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "color.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Orange colors for all the hmtl orange colors. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ orange_colors final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::orange_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ orange_colors final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_coral.png
      [[nodiscard]] static auto coral() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_orange_red.png
      [[nodiscard]] static auto orange_red() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_tomato.png
      [[nodiscard]] static auto tomato() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_orange.png
      [[nodiscard]] static auto dark_orange() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_orange.png
      [[nodiscard]] static auto orange() noexcept -> xtd::drawing::color;
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
