/// @file
/// @brief Contains xtd::drawing::drawing_2d::conical_gradient_brush class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../../drawing_export.h"
#include "../brush.h"
#include "../point.h"
#include "../rectangle.h"
#include "drawing2d.h"
#include "gradient_stop_collection.h"
#include <xtd/iequatable>
#include <array>
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing_2d/ namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing_2d {
      /// @brief Encapsulates a xtd::drawing::brush with a conical gradient. This class cannot be inherited.
      /// @code
      /// class drawing_export_ conical_gradient_brush final : public brush
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::drawing::brush → xtd::drawing::drawing_2d::conical_gradient_brush
      /// @par Namespace
      /// xtd::drawing::drawing_2d/
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing drawing
      /// @image html conical_gradient_brush.png
      /// @par Examples
      /// The following code example demonstrates the use of conical_gradient_brush class.
      /// @include fill_rectangle.cpp
      class drawing_export_ conical_gradient_brush final : public brush, public xtd::iequatable<conical_gradient_brush> {
        struct data;
        
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::conical_gradient_brush class with default values.
        /// @remarks Center and focal points are set to {0, 0} and colors are set with two transparent colors.
        conical_gradient_brush();
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::conical_gradient_brush class with the specified center point and colors.
        /// @param center A xtd::drawing::point structure that represents the center point of the conical gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the conical gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the conical gradient.
        conical_gradient_brush(const xtd::drawing::point& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2);
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::conical_gradient_brush class with the specified center point and colors.
        /// @param center A xtd::drawing::point structure that represents the center point of the conical gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the conical gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the conical gradient.
        conical_gradient_brush(const xtd::drawing::point_f& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2);
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::conical_gradient_brush class with the specified center point ,colors and angle.
        /// @param center A xtd::drawing::point structure that represents the center point of the conical gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the conical gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the conical gradient.
        /// @param angle A float hat represents the angle of the conical gradient.
        conical_gradient_brush(const xtd::drawing::point& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float angle);
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::conical_gradient_brush class with the specified center point, colors and radiuus.
        /// @param center A xtd::drawing::point structure that represents the center point of the conical gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the conical gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the conical gradient.
        /// @param angle A float hat represents the angle of the conical gradient.
        conical_gradient_brush(const xtd::drawing::point_f& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float angle);
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::conical_gradient_brush class with the specified center point and colors.
        /// @param center A xtd::drawing::point structure that represents the center point of the conical gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the conical gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the conical gradient.
        conical_gradient_brush(const xtd::drawing::point& center, const std::vector<xtd::drawing::color>& conical_colors);
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::conical_gradient_brush class with the specified center point and colors.
        /// @param center A xtd::drawing::point structure that represents the center point of the conical gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the conical gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the conical gradient.
        conical_gradient_brush(const xtd::drawing::point_f& center, const std::vector<xtd::drawing::color>& conical_colors);
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::conical_gradient_brush class with the specified center poin, colors and angle.
        /// @param center A xtd::drawing::point structure that represents the center point of the conical gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the conical gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the conical gradient.
        /// @param angle A float hat represents the angle of the conical gradient.
        conical_gradient_brush(const xtd::drawing::point& center, const std::vector<xtd::drawing::color>& conical_colors, float angle);
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::conical_gradient_brush class with the specified center point, colors and angle.
        /// @param center A xtd::drawing::point structure that represents the center point of the conical gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the conical gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the conical gradient.
        /// @param angle A float hat represents the angle of the conical gradient.
        conical_gradient_brush(const xtd::drawing::point_f& center, const std::vector<xtd::drawing::color>& conical_colors, float angle);
        /// @}
        
        /// @cond
        conical_gradient_brush(const conical_gradient_brush& value);
        conical_gradient_brush& operator =(const conical_gradient_brush& value);
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the angle of the gradient.
        /// @return A float that specifies the angle of the conical gradient.
        /// @remarks The angle rotates in the clockwise direction. An angle of O° represents an angle from the center to the left. The angle turns in the clockwise direction. An angle of 90° represents an angle from the center downwards. An angle of 180° represents an angle from the center to the right. And so on.
        float angle() const noexcept;
        /// @brief Sets the angle of the gradient.
        /// @param value A float that specifies the angle of the conicalconical gradient.
        /// @return Current linear_gradient_brush instance.
        /// @remarks The angle rotates in the clockwise direction. An angle of O° represents an angle from the center to the left. The angle turns in the clockwise direction. An angle of 90° represents an angle from the center downwards. An angle of 180° represents an angle from the center to the right. And so on.
        conical_gradient_brush& angle(float value) noexcept;
        
        /// @brief Gets the center point of the conical gradient.
        /// @return A xtd::drawing::point_f structure that specifies the center point of the angle  gradient.
        xtd::drawing::point_f center_point() const noexcept;
        /// @brief Gets the center point of the conical gradient.
        /// @param value A xtd::drawing::point_f structure that specifies the center point of the angle  gradient.
        /// @return This current instance.
        conical_gradient_brush& center_point(const xtd::drawing::point_f& value) noexcept;
        /// @brief Sets the center point of the conical gradient.
        /// @param value A xtd::drawing::point_f structure that specifies the center point of the angle  gradient.
        /// @return This current instance.
        conical_gradient_brush& center_point(const xtd::drawing::point& value) noexcept;
        
        /// @brief Gets the starting and ending colors of the gradient.
        /// @return An array of two xtd::drawing::color structures that represents the starting and ending colors of the gradient.
        const xtd::drawing::drawing_2d::gradient_stop_collection& conical_colors() const noexcept;
        /// @brief sets the starting and ending colors of the gradient.
        /// @param conical_colors An array of two xtd::drawing::color structures that represents the starting and ending colors of the gradient.
        /// @return Current conical_gradient_brush instance.
        xtd::drawing::drawing_2d::conical_gradient_brush& conical_colors(const xtd::drawing::drawing_2d::gradient_stop_collection& conical_colors);
        /// @}
        
        /// @name Methods
        
        /// @{
        using brush::equals;
        bool equals(const conical_gradient_brush& value) const noexcept override;
        /// @}
        
      private:
        void recreate_handle();
        
        std::shared_ptr<data> data_;
      };
    }
  }
}

