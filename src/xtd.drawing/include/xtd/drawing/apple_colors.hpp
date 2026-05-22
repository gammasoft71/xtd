/// @file
/// @brief Contains xtd::drawing::apple_colors factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "gray_colors.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Apple colors for all the Apple colors. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ apple_colors final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::apple_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ apple_colors final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html apple_colors_black.png
      [[nodiscard]] static auto black() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_blue.png
      [[nodiscard]] static auto blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_brown.png
      [[nodiscard]] static auto brown() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_cyan.png
      [[nodiscard]] static auto cyan() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_green.png
      [[nodiscard]] static auto green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_magenta.png
      [[nodiscard]] static auto magenta() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_orange.png
      [[nodiscard]] static auto orange() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_purple.png
      [[nodiscard]] static auto purple() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_red.png
      [[nodiscard]] static auto red() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_yellow.png
      [[nodiscard]] static auto yellow() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html apple_colors_white.png
      [[nodiscard]] static auto white() noexcept -> xtd::drawing::color;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of colors.
      [[nodiscard]] static auto get_colors() noexcept -> const xtd::array<xtd::drawing::color>&;
      
      
      [[nodiscard]] static auto get_color_names() noexcept -> const xtd::array<xtd::string>&;
      /// @}
    };
  }
}
