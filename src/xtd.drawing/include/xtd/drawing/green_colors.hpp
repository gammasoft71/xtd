/// @file
/// @brief Contains xtd::drawing::green_colors factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "color.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Green colors for all the hmtl green colors. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ green_colors final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::green_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ green_colors final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_chartreuse.png
      [[nodiscard]] static auto chartreuse() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_green.png
      [[nodiscard]] static auto dark_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_olive_green.png
      [[nodiscard]] static auto dark_olive_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_sea_green.png
      [[nodiscard]] static auto dark_sea_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_green.png
      [[nodiscard]] static auto green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_green_yellow.png
      [[nodiscard]] static auto green_yellow() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_forest_green.png
      [[nodiscard]] static auto forest_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_lawn_green.png
      [[nodiscard]] static auto lawn_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_green.png
      [[nodiscard]] static auto light_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_lime.png
      [[nodiscard]] static auto lime() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_lime_green.png
      [[nodiscard]] static auto lime_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_aquamarine.png
      [[nodiscard]] static auto medium_aquamarine() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_sea_green.png
      [[nodiscard]] static auto medium_sea_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_spring_green.png
      [[nodiscard]] static auto medium_spring_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_olive.png
      [[nodiscard]] static auto olive() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_olive_drab.png
      [[nodiscard]] static auto olive_drab() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_green.png
      [[nodiscard]] static auto pale_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_sea_green.png
      [[nodiscard]] static auto sea_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_spring_green.png
      [[nodiscard]] static auto spring_green() noexcept -> xtd::drawing::color;
      
      /// @brief A system-defined color object.
      /// @image html colors_yellow_green.png
      [[nodiscard]] static auto yellow_green() noexcept -> xtd::drawing::color;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of colors.
      [[nodiscard]] static auto get_colors() noexcept -> const xtd::array<xtd::drawing::color>&;
      
      /// @brief Gets an array of color_names.
      [[nodiscard]] static auto get_color_names() noexcept -> const xtd::array<xtd::string>&;
      /// @}
    };
  }
}
