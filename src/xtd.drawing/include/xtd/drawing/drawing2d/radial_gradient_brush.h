/// @file
/// @brief Contains xtd::drawing::drawing2d::radial_gradient_brush class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <array>
#include <utility>
#include "../../drawing_export.h"
#include "../brush.h"
#include "../color.h"
#include "../point.h"
#include "../rectangle.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::.drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief Encapsulates a xtd::drawing::brush with a radial gradient. This class cannot be inherited.
      /// @par Namespace
      /// xtd::drawing::drawing2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing drawing
      /// @par Examples
      /// The following code example demonstrate the use of radial_gradient_brush class.
      /// @include fill_rectangle.cpp
      class drawing_export_ radial_gradient_brush final : public brush {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the radial_gradient_brush class with the specified points and colors.
        /// @param point1 A xtd::drawing::point structure that represents the starting point of the radial gradient.
        /// @param point2 A xtd::drawing::point structure that represents the endpoint of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        radial_gradient_brush(const xtd::drawing::point& point1, const xtd::drawing::point& point2, const xtd::drawing::color& color1, const xtd::drawing::color& color2);
        /// @brief Initializes a new instance of the radial_gradient_brush class with the specified points and colors.
        /// @param point1 A xtd::drawing::point_f structure that represents the starting point of the radial gradient.
        /// @param point2 A xtd::drawing::point_f structure that represents the endpoint of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        radial_gradient_brush(const xtd::drawing::point_f& point1, const xtd::drawing::point_f& point2, const xtd::drawing::color& color1, const xtd::drawing::color& color2);
        /// @brief Initializes a new instance of the radial_gradient_brush class with the specified rectangle, colors, and orientation radius.
        /// @param rect A xtd::drawing::rectangle structure that specifies the bounds of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        /// @param radius The radius, measured in degrees clockwise from the x-axis, of the gradient's orientation line.
        radial_gradient_brush(const xtd::drawing::rectangle& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float radius);
        /// @brief Initializes a new instance of the radial_gradient_brush class with the specified rectangle, colors, and orientation radius.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        /// @param radius The radius, measured in degrees clockwise from the x-axis, of the gradient's orientation line.
        radial_gradient_brush(const xtd::drawing::rectangle_f& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float radius);
        /// @brief Initializes a new instance of the radial_gradient_brush class with the specified rectangle and colors.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        radial_gradient_brush(const xtd::drawing::rectangle& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2);
        /// @brief Initializes a new instance of the radial_gradient_brush class with the specified rectangle and colors.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        radial_gradient_brush(const xtd::drawing::rectangle_f& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2);
        /// @brief Initializes a new instance of the radial_gradient_brush class with the specified points and colors.
        /// @param point1 A xtd::drawing::point structure that represents the starting point of the radial gradient.
        /// @param point2 A xtd::drawing::point structure that represents the endpoint of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        radial_gradient_brush(const xtd::drawing::point& point1, const xtd::drawing::point& point2, const std::vector<xtd::drawing::color>& radial_colors);
        /// @brief Initializes a new instance of the radial_gradient_brush class with the specified points and colors.
        /// @param point1 A xtd::drawing::point_f structure that represents the starting point of the radial gradient.
        /// @param point2 A xtd::drawing::point_f structure that represents the endpoint of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        radial_gradient_brush(const xtd::drawing::point_f& point1, const xtd::drawing::point_f& point2, const std::vector<xtd::drawing::color>& radial_colors);
        /// @brief Initializes a new instance of the radial_gradient_brush class with the specified rectangle, colors, and orientation radius.
        /// @param rect A xtd::drawing::rectangle structure that specifies the bounds of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        /// @param radius The radius, measured in degrees clockwise from the x-axis, of the gradient's orientation line.
        radial_gradient_brush(const xtd::drawing::rectangle& rect, const std::vector<xtd::drawing::color>& radial_colors, float radius);
        /// @brief Initializes a new instance of the radial_gradient_brush class with the specified rectangle, colors, and orientation radius.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        /// @param radius The radius, measured in degrees clockwise from the x-axis, of the gradient's orientation line.
        radial_gradient_brush(const xtd::drawing::rectangle_f& rect, const std::vector<xtd::drawing::color>& radial_colors, float radius);
        /// @brief Initializes a new instance of the radial_gradient_brush class with the specified rectangle and colors.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        radial_gradient_brush(const xtd::drawing::rectangle& rect, const std::vector<xtd::drawing::color>& radial_colors);
        /// @brief Initializes a new instance of the radial_gradient_brush class with the specified rectangle and colors.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the radial gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the radial gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the radial gradient.
        radial_gradient_brush(const xtd::drawing::rectangle_f& rect, const std::vector<xtd::drawing::color>& radial_colors);
        /// @}
        
        /// @cond
        radial_gradient_brush(const radial_gradient_brush& value);
        radial_gradient_brush& operator=(const radial_gradient_brush& value);
        bool operator==(const radial_gradient_brush& value) const {return data_ == value.data_;}
        bool operator!=(const radial_gradient_brush& value) const {return !operator==(value);}
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the starting and ending colors of the gradient.
        /// @return An array of two xtd::drawing::color structures that represents the starting and ending colors of the gradient.
        const std::vector<xtd::drawing::color>& radial_colors() const noexcept;
        /// @brief sets the starting and ending colors of the gradient.
        /// @param radial_colors An array of two xtd::drawing::color structures that represents the starting and ending colors of the gradient.
        /// @return Current radial_gradient_brush instance.
        xtd::drawing::drawing2d::radial_gradient_brush& radial_colors(const std::vector<xtd::drawing::color>& radial_colors);
        
        /// @brief Gets a rectangular region that defines the starting and ending points of the gradient.
        /// @return A xtd::drawing::rectangle_f structure that specifies the starting and ending points of the gradient.
        xtd::drawing::rectangle_f rectangle() const noexcept;
        /// @}
        
      private:
        radial_gradient_brush();
        void recreate_handle();
        struct data {
          xtd::drawing::rectangle_f rect;
          float radius = 0;
          std::vector<xtd::drawing::color> radial_colors;
        };
        std::shared_ptr<data> data_ = std::make_shared<data>();
      };
    }
  }
}

