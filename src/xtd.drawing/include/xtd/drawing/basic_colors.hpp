/// @file
/// @brief Contains xtd::drawing::basic_colors factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "color.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Basic colors for all the hmtl basic colors. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ basic_colors final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::basic_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ basic_colors final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_aqua.png
      [[nodiscard]] static auto aqua() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_black.png
      [[nodiscard]] static auto black() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_blue.png
      [[nodiscard]] static auto blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_fuchsia.png
      [[nodiscard]] static auto fuchsia() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_gray.png
      [[nodiscard]] static auto gray() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_green.png
      [[nodiscard]] static auto green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_lime.png
      [[nodiscard]] static auto lime() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_maroon.png
      [[nodiscard]] static auto maroon() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_navy.png
      [[nodiscard]] static auto navy() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_olive.png
      [[nodiscard]] static auto olive() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_purple.png
      [[nodiscard]] static auto purple() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_red.png
      [[nodiscard]] static auto red() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_silver.png
      [[nodiscard]] static auto silver() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_teal.png
      [[nodiscard]] static auto teal() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_white.png
      [[nodiscard]] static auto white() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_yellow.png
      [[nodiscard]] static auto yellow() noexcept -> xtd::drawing::color;
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
