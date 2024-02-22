/// @file
/// @brief Contains xtd::drawing::drawing_2d::linear_gradient_brush class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../../drawing_export.h"
#include "../brush.h"
#include "../color.h"
#include "../point.h"
#include "../rectangle.h"
#include "drawing2d.h"
#include "gradient_stop_collection.h"
#include "linear_gradient_mode.h"
#include <array>
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing_2d/ namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing_2d {
      /// @brief Encapsulates a xtd::drawing::brush with a linear gradient. This class cannot be inherited.
      /// @par Namespace
      /// xtd::drawing::drawing_2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing brushes
      /// @image html linear_gradient_brush.png
      /// @par Examples
      /// The following code example demonstrates the use of linear_gradient_brush class.
      /// @include fill_rectangle.cpp
      class drawing_export_ linear_gradient_brush final : public brush, xtd::iequatable<linear_gradient_brush> {
        struct data;
        
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::radial_gradient_brush class with default values.
        /// @remarks Rectanlge is set to {0, 0, 0, 0}  and colors are set with two transparent colors.
        linear_gradient_brush();
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified points and colors.
        /// @param point1 A xtd::drawing::point structure that represents the starting point of the linear gradient.
        /// @param point2 A xtd::drawing::point structure that represents the endpoint of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        linear_gradient_brush(const xtd::drawing::point& point1, const xtd::drawing::point& point2, const xtd::drawing::color& color1, const xtd::drawing::color& color2);
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified points and colors.
        /// @param point1 A xtd::drawing::point_f structure that represents the starting point of the linear gradient.
        /// @param point2 A xtd::drawing::point_f structure that represents the endpoint of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        linear_gradient_brush(const xtd::drawing::point_f& point1, const xtd::drawing::point_f& point2, const xtd::drawing::color& color1, const xtd::drawing::color& color2);
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle, colors, and orientation.
        /// @param rect A xtd::drawing::rectangle structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        /// @param linear_gradient_mode A xtd::drawing::drawing_2d::linear_gradient_mode enumeration element that specifies the orientation of the gradient. The orientation determines the starting and ending points of the gradient. For example, xtd::drawing::drawing_2d::linear_gradient_mode::forward_diagonal specifies that the starting point is the upper-left corner of the rectangle and the ending point is the lower-right corner of the rectangle.
        linear_gradient_brush(const xtd::drawing::rectangle& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, xtd::drawing::drawing_2d::linear_gradient_mode linear_gradient_mode);
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle, colors, and orientation angle.
        /// @param rect A xtd::drawing::rectangle structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        /// @param angle The angle, measured in degrees clockwise from the x-axis, of the gradient's orientation line.
        linear_gradient_brush(const xtd::drawing::rectangle& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float angle);
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle, colors, and orientation.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        /// @param linear_gradient_mode A xtd::drawing::drawing_2d::linear_gradient_mode enumeration element that specifies the orientation of the gradient. The orientation determines the starting and ending points of the gradient. For example, xtd::drawing::drawing_2d::linear_gradient_mode::forward_diagonal specifies that the starting point is the upper-left corner of the rectangle and the ending point is the lower-right corner of the rectangle.
        linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, xtd::drawing::drawing_2d::linear_gradient_mode linear_gradient_mode);
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle, colors, and orientation angle.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        /// @param angle The angle, measured in degrees clockwise from the x-axis, of the gradient's orientation line.
        linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float angle);
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle and colors.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        linear_gradient_brush(const xtd::drawing::rectangle& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2);
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle and colors.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2);
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified points and colors.
        /// @param point1 A xtd::drawing::point structure that represents the starting point of the linear gradient.
        /// @param point2 A xtd::drawing::point structure that represents the endpoint of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        linear_gradient_brush(const xtd::drawing::point& point1, const xtd::drawing::point& point2, const std::vector<xtd::drawing::color>& linear_colors);
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified points and colors.
        /// @param point1 A xtd::drawing::point_f structure that represents the starting point of the linear gradient.
        /// @param point2 A xtd::drawing::point_f structure that represents the endpoint of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        linear_gradient_brush(const xtd::drawing::point_f& point1, const xtd::drawing::point_f& point2, const std::vector<xtd::drawing::color>& linear_colors);
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle, colors, and orientation.
        /// @param rect A xtd::drawing::rectangle structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        /// @param linear_gradient_mode A xtd::drawing::drawing_2d::linear_gradient_mode enumeration element that specifies the orientation of the gradient. The orientation determines the starting and ending points of the gradient. For example, xtd::drawing::drawing_2d::linear_gradient_mode::forward_diagonal specifies that the starting point is the upper-left corner of the rectangle and the ending point is the lower-right corner of the rectangle.
        linear_gradient_brush(const xtd::drawing::rectangle& rect, const std::vector<xtd::drawing::color>& linear_colors, xtd::drawing::drawing_2d::linear_gradient_mode linear_gradient_mode);
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle, colors, and orientation angle.
        /// @param rect A xtd::drawing::rectangle structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        /// @param angle The angle, measured in degrees clockwise from the x-axis, of the gradient's orientation line.
        linear_gradient_brush(const xtd::drawing::rectangle& rect, const std::vector<xtd::drawing::color>& linear_colors, float angle);
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle, colors, and orientation.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        /// @param linear_gradient_mode A xtd::drawing::drawing_2d::linear_gradient_mode enumeration element that specifies the orientation of the gradient. The orientation determines the starting and ending points of the gradient. For example, xtd::drawing::drawing_2d::linear_gradient_mode::forward_diagonal specifies that the starting point is the upper-left corner of the rectangle and the ending point is the lower-right corner of the rectangle.
        linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const std::vector<xtd::drawing::color>& linear_colors, xtd::drawing::drawing_2d::linear_gradient_mode linear_gradient_mode);
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle, colors, and orientation angle.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        /// @param angle The angle, measured in degrees clockwise from the x-axis, of the gradient's orientation line.
        linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const std::vector<xtd::drawing::color>& linear_colors, float angle);
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle and colors.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        linear_gradient_brush(const xtd::drawing::rectangle& rect, const std::vector<xtd::drawing::color>& linear_colors);
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle and colors.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const std::vector<xtd::drawing::color>& linear_colors);
        /// @}
        
        /// @cond
        linear_gradient_brush(const linear_gradient_brush& value);
        linear_gradient_brush& operator =(const linear_gradient_brush& value);
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the angle of the gradient.
        /// @return A float that specifies the angle of the linear gradient.
        float angle() const noexcept;
        /// @brief Sets the angle of the gradient.
        /// @param value A float that specifies the angle of the linear gradient.
        /// @return Current linear_gradient_brush instance.
        linear_gradient_brush& angle(float value) noexcept;
        
        /// @brief Gets the starting and ending colors of the gradient.
        /// @return An array of two xtd::drawing::color structures that represents the starting and ending colors of the linear gradient.
        const xtd::drawing::drawing_2d::gradient_stop_collection& linear_colors() const noexcept;
        /// @brief sets the starting and ending colors of the gradient.
        /// @param value An array of two xtd::drawing::color structures that represents the starting and ending colors of the linear gradient.
        /// @return Current linear_gradient_brush instance.
        xtd::drawing::drawing_2d::linear_gradient_brush& linear_colors(const xtd::drawing::drawing_2d::gradient_stop_collection& value);
        
        /// @brief Gets a rectangular region that defines the starting and ending points of the linear gradient.
        /// @return A xtd::drawing::rectangle_f structure that specifies the starting and ending points of the linear gradient.
        const xtd::drawing::rectangle_f& rectangle() const noexcept;
        /// @brief Sets a rectangular region that defines the starting and ending points of the linear gradient.
        /// @param value A xtd::drawing::rectangle_f structure that specifies the starting and ending points of the linear gradient.
        /// @return Current linear_gradient_brush instance.
        linear_gradient_brush& rectangle(const xtd::drawing::rectangle_f& value) noexcept;
        /// @brief Sets a rectangular region that defines the starting and ending points of the linear gradient.
        /// @param value A xtd::drawing::rectangle_f structure that specifies the starting and ending points of the linear gradient.
        /// @return Current linear_gradient_brush instance.
        linear_gradient_brush& rectangle(const xtd::drawing::rectangle& value) noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{
        using brush::equals;
        bool equals(const linear_gradient_brush& value) const noexcept override;
        /// @}
        
      private:
        static float linear_gradient_mode_to_angle(xtd::drawing::drawing_2d::linear_gradient_mode);
        void recreate_handle();
        
        std::shared_ptr<data> data_;
      };
    }
  }
}

