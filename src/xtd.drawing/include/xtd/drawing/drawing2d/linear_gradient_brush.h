/// @file
/// @brief Contains xtd::drawing::drawing2d::linear_gradient_brush class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <array>
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
      /// @brief Encapsulates a xtd::drawing::rush with a linear gradient. This class cannot be inherited.
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing drawing
      /// @todo add gradient mode: enum class linear_gradient_mode {horizontal = 0, vertical = 1, forward_diagonal = 2, backward_diagonal = 3};
      class drawing_export_ linear_gradient_brush final : public brush {
      public:
        /// @brief Initializes a new instance of the linear_gradient_brush class.
        linear_gradient_brush();
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified points and colors.
        /// @param point1 A xtd::drawing::point structure that represents the starting point of the linear gradient.
        /// @param point2 A xtd::drawing::point structure that represents the endpoint of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        linear_gradient_brush(const xtd::drawing::point& point1, const xtd::drawing::point& point2, const xtd::drawing::color& color1, const xtd::drawing::color& color2) {
          data_->rect_ = xtd::drawing::rectangle_f(static_cast<float>(point1.x()), static_cast<float>(point1.y()), static_cast<float>(point2.x() - point1.x()), static_cast<float>(point2.y() - point1.y()));
          data_->linear_colors_ = {color1, color2};
          recreate_handle();
        }
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified points and colors.
        /// @param point1 A xtd::drawing::point_f structure that represents the starting point of the linear gradient.
        /// @param point2 A xtd::drawing::point_f structure that represents the endpoint of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        linear_gradient_brush(const xtd::drawing::point_f& point1, const xtd::drawing::point_f& point2, const xtd::drawing::color& color1, const xtd::drawing::color& color2) {
          data_->rect_ = xtd::drawing::rectangle_f(point1.x(), point1.y(), point2.x() - point1.x(), point2.y() - point1.y());
          data_->linear_colors_ = {color1, color2};
          recreate_handle();
        }
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle and colors.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2) {
          data_->rect_ = rect;
          data_->linear_colors_ = {color1, color2};
          recreate_handle();
        }
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle and colors.
        /// @param rect A xtd::drawing::rectangle structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        linear_gradient_brush(const xtd::drawing::rectangle& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2) {
          data_->rect_ = rect;
          data_->linear_colors_ = {color1, color2};
          recreate_handle();
        }

        /// @cond
        linear_gradient_brush(const linear_gradient_brush& value);
        linear_gradient_brush& operator=(const linear_gradient_brush& value);
        bool operator==(const linear_gradient_brush& value) const {return data_->rect_ == value.data_->rect_ && data_->linear_colors_[0] == value.data_->linear_colors_[0] && data_->linear_colors_[1] == value.data_->linear_colors_[1];}
        bool operator!=(const linear_gradient_brush& value) const {return !operator==(value);}
        /// @endcond
        
        /// @brief Gets the starting and ending colors of the gradient.
        /// @return An array of two xtd::drawing::color structures that represents the starting and ending colors of the gradient.
        const std::array<xtd::drawing::color, 2>& linear_colors() const {return data_->linear_colors_;}
        /// @brief Gets the starting and ending colors of the gradient.
        /// @return An array of two xtd::drawing::color structures that represents the starting and ending colors of the gradient.
        std::array<xtd::drawing::color, 2>& linear_colors() {return data_->linear_colors_;}
        /// @brief sets the starting and ending colors of the gradient.
        /// @param linear_colors An array of two xtd::drawing::color structures that represents the starting and ending colors of the gradient.
        /// @return Current linear_gradient_brush instance.
        xtd::drawing::drawing2d::linear_gradient_brush& linear_colors(const std::array<xtd::drawing::color, 2>& linear_colors);

        /// @brief Gets a rectangular region that defines the starting and ending points of the gradient.
        /// @return A xtd::drawing::rectangle_f structure that specifies the starting and ending points of the gradient.
        const xtd::drawing::rectangle_f& rectangle() const {return data_->rect_;}
        /// @brief Sets a rectangular region that defines the starting and ending points of the gradient.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the starting and ending points of the gradient.
        /// @return Current linear_gradient_brush instance.
        xtd::drawing::drawing2d::linear_gradient_brush& rectangle(const xtd::drawing::rectangle_f& rect);
      
        private:
        void recreate_handle();
        struct data {
          xtd::drawing::rectangle_f rect_;
          std::array<xtd::drawing::color, 2> linear_colors_;
        };
        std::shared_ptr<data> data_ = std::make_shared<data>();
      };
    }
  }
}
