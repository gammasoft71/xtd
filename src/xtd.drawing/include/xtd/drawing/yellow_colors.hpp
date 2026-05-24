/// @file
/// @brief Contains xtd::drawing::yellow_colors factory.
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
    /// @brief Yellow colors for all the hmtl yellow colors. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ yellow_colors final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::yellow_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ yellow_colors final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_dark_khaki.png
      [[nodiscard]] static auto dark_khaki() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_gold.png
      [[nodiscard]] static auto gold() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_khaki.png
      [[nodiscard]] static auto khaki() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_lemon_chiffon.png
      [[nodiscard]] static auto lemon_chiffon() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_goldenrod_yellow.png
      [[nodiscard]] static auto light_goldenrod_yellow() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_yellow.png
      [[nodiscard]] static auto light_yellow() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_moccasin.png
      [[nodiscard]] static auto moccasin() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_goldenrod.png
      [[nodiscard]] static auto pale_goldenrod() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_papaya_whip.png
      [[nodiscard]] static auto papaya_whip() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_peach_puff.png
      [[nodiscard]] static auto peach_puff() noexcept -> xtd::drawing::color;
      
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
