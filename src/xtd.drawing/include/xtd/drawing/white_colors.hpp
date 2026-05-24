/// @file
/// @brief Contains xtd::drawing::white_colors factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "color.hpp"
#include <xtd/static>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief White colors for all the hmtl white colors. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ white_colors final static_
    /// ```
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
      [[nodiscard]] static auto alice_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_antique_white.png
      [[nodiscard]] static auto antique_white() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_azure.png
      [[nodiscard]] static auto azure() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_beige.png
      [[nodiscard]] static auto beige() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_floral_white.png
      [[nodiscard]] static auto floral_white() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_ghost_white.png
      [[nodiscard]] static auto ghost_white() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_honeydew.png
      [[nodiscard]] static auto honeydew() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_ivory.png
      [[nodiscard]] static auto ivory() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_lavender_blush.png
      [[nodiscard]] static auto lavender_blush() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_linen.png
      [[nodiscard]] static auto linen() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_mint_cream.png
      [[nodiscard]] static auto mint_cream() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_misty_rose.png
      [[nodiscard]] static auto misty_rose() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_old_lace.png
      [[nodiscard]] static auto old_lace() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_sea_shell.png
      [[nodiscard]] static auto sea_shell() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_snow.png
      [[nodiscard]] static auto snow() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_white.png
      [[nodiscard]] static auto white() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_white_smoke.png
      [[nodiscard]] static auto white_smoke() noexcept -> xtd::drawing::color;
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
