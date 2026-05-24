/// @file
/// @brief Contains xtd::drawing::purple_colors factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "color.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Purple, violet and magenta colors for all the hmtl purple, violet and magenta colors. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ purple_colors final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::purple_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ purple_colors final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_blue_violet.png
      [[nodiscard]] static auto blue_violet() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_magenta.png
      [[nodiscard]] static auto dark_magenta() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_orchid.png
      [[nodiscard]] static auto dark_orchid() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_slate_blue.png
      [[nodiscard]] static auto dark_slate_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_violet.png
      [[nodiscard]] static auto dark_violet() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_fuchsia.png
      [[nodiscard]] static auto fuchsia() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_indigo.png
      [[nodiscard]] static auto indigo() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_lavender.png
      [[nodiscard]] static auto lavender() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_magenta.png
      [[nodiscard]] static auto magenta() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_orchid.png
      [[nodiscard]] static auto medium_orchid() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_purple.png
      [[nodiscard]] static auto medium_purple() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_slate_blue.png
      [[nodiscard]] static auto medium_slate_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_orchid.png
      [[nodiscard]] static auto orchid() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_plum.png
      [[nodiscard]] static auto plum() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_purple.png
      [[nodiscard]] static auto purple() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_rebecca_purple.png
      [[nodiscard]] static auto rebecca_purple() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_slate_blue.png
      [[nodiscard]] static auto slate_blue() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_thistle.png
      [[nodiscard]] static auto thistle() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_violet.png
      [[nodiscard]] static auto violet() noexcept -> xtd::drawing::color;
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
