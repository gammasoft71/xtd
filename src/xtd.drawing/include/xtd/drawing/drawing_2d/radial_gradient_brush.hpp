/// @file
/// @brief Contains xtd::drawing::drawing_2d::radial_gradient_brush class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../../drawing_export.hpp"
#include "../brush.hpp"
#include "../point.hpp"
#include "../rectangle.hpp"
#include "gradient_stop_collection.hpp"
#include <array>
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing_2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing_2d {
      /// @brief Encapsulates a xtd::drawing::brush with a radial gradient. This class cannot be inherited.
      /// @par Namespace
      /// xtd::drawing::drawing_2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing brushes
      /// @image html radial_gradient_brush.png
      /// @par Examples
      /// The following code example demonstrates the use of radial_gradient_brush class.
      /// @include fill_rectangle.cpp
      class drawing_export_ radial_gradient_brush final : public brush {
        struct data;
        
      public:
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::radial_gradient_brush class with default values.
        /// @remarks Center and focal points are set to {0, 0} and colors are set with two transparent colors.
        radial_gradient_brush();
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::radial_gradient_brush class with the specified center point and colors.
        /// @param center A xtd::drawing::point structure that represents the center point of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        radial_gradient_brush(const xtd::drawing::point& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2);
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::radial_gradient_brush class with the specified center point and colors.
        /// @param center A xtd::drawing::point structure that represents the center point of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        radial_gradient_brush(const xtd::drawing::point_f& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2);
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::radial_gradient_brush class with the specified center point ,colors and radius.
        /// @param center A xtd::drawing::point structure that represents the center point of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        /// @param radius A float hat represents the radius of the radial gradient.
        radial_gradient_brush(const xtd::drawing::point& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float radius);
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::radial_gradient_brush class with the specified center point, colors and radiuus.
        /// @param center A xtd::drawing::point structure that represents the center point of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        /// @param radius A float hat represents the radius of the radial gradient.
        radial_gradient_brush(const xtd::drawing::point_f& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float radius);
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::radial_gradient_brush class with the specified center point and colors.
        /// @param center A xtd::drawing::point structure that represents the center point of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        radial_gradient_brush(const xtd::drawing::point& center, const xtd::array<xtd::drawing::color>& radial_colors);
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::radial_gradient_brush class with the specified center point and colors.
        /// @param center A xtd::drawing::point structure that represents the center point of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        radial_gradient_brush(const xtd::drawing::point_f& center, const xtd::array<xtd::drawing::color>& radial_colors);
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::radial_gradient_brush class with the specified center poin, colors and radius.
        /// @param center A xtd::drawing::point structure that represents the center point of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        /// @param radius A float hat represents the radius of the radial gradient.
        radial_gradient_brush(const xtd::drawing::point& center, const xtd::array<xtd::drawing::color>& radial_colors, float radius);
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::radial_gradient_brush class with the specified center point, colors and radius.
        /// @param center A xtd::drawing::point structure that represents the center point of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        /// @param radius A float hat represents the radius of the radial gradient.
        radial_gradient_brush(const xtd::drawing::point_f& center, const xtd::array<xtd::drawing::color>& radial_colors, float radius);
        /// @}
        
        /// @cond
        radial_gradient_brush(const radial_gradient_brush& value);
        radial_gradient_brush& operator =(const radial_gradient_brush& value);
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the center point of the radial gradient.
        /// @return A xtd::drawing::point_f structure that specifies the center point of the radial  gradient.
        [[nodiscard]] auto center_point() const noexcept -> xtd::drawing::point_f;
        /// @brief Gets the center point of the radial gradient.
        /// @param value A xtd::drawing::point_f structure that specifies the center point of the radial  gradient.
        /// @return This current instance.
        auto center_point(const xtd::drawing::point_f& value) noexcept -> radial_gradient_brush&;
        /// @brief Sets the center point of the radial gradient.
        /// @param value A xtd::drawing::point_f structure that specifies the center point of the radial  gradient.
        /// @return This current instance.
        auto center_point(const xtd::drawing::point& value) noexcept -> radial_gradient_brush&;
        
        /// @brief Gets the focal point of the radial gradient.
        /// @return A xtd::drawing::point_f structure that specifies the focal point of the radial  gradient.
        [[nodiscard]] auto focal_point() const noexcept -> xtd::drawing::point_f;
        /// @brief Sets the focal point of the radial gradient.
        /// @param value A xtd::drawing::point_f structure that specifies the focal point of the radial  gradient.
        /// @return This current instance.
        auto focal_point(const xtd::drawing::point_f& value) noexcept -> radial_gradient_brush&;
        /// @brief Sets the focal point of the radial gradient.
        /// @param value A xtd::drawing::point_f structure that specifies the focal point of the radial  gradient.
        /// @return This current instance.
        auto focal_point(const xtd::drawing::point& value) noexcept -> radial_gradient_brush&;
        
        /// @brief Gets the starting and ending colors of the gradient.
        /// @return An array of two xtd::drawing::color structures that represents the starting and ending colors of the gradient.
        [[nodiscard]] auto radial_colors() const noexcept -> const xtd::drawing::drawing_2d::gradient_stop_collection&;
        /// @brief sets the starting and ending colors of the gradient.
        /// @param radial_colors An array of two xtd::drawing::color structures that represents the starting and ending colors of the gradient.
        /// @return Current radial_gradient_brush instance.
        auto radial_colors(const xtd::drawing::drawing_2d::gradient_stop_collection& radial_colors) -> radial_gradient_brush&;
        
        /// @brief Gets the angle of the gradient.
        /// @return A float that specifies the angle of the linear gradient.
        [[nodiscard]] auto radius() const noexcept -> float;
        /// @brief Sets the radius of the gradient.
        /// @param value A float that specifies the radius of the radial gradient.
        /// @return Current linear_gradient_brush instance.
        auto radius(float value) noexcept -> radial_gradient_brush&;
        /// @}
        
      private:
        auto recreate_handle() -> void;
        
        xtd::sptr<data> data_;
      };
    }
  }
}

