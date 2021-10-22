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
#include "linear_gradient_mode.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::.drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief Encapsulates a xtd::drawing::brush with a linear gradient. This class cannot be inherited.
      /// @par Namespace
      /// xtd::drawing::drawing2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing drawing
      /// @par Examples
      /// The following code example demonstrate the use of linear_gradient_brush class.
      /// @include fill_rectangle.cpp
       class drawing_export_ linear_gradient_brush final : public brush {
      public:
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified points and colors.
        /// @param point1 A xtd::drawing::point structure that represents the starting point of the linear gradient.
        /// @param point2 A xtd::drawing::point structure that represents the endpoint of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        linear_gradient_brush(const xtd::drawing::point& point1, const xtd::drawing::point& point2, const xtd::drawing::color& color1, const xtd::drawing::color& color2) {
          data_->point1_ = point1;
          data_->point2_ = point2;
          data_->linear_colors_ = {color1, color2};
          recreate_handle();
        }
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified points and colors.
        /// @param point1 A xtd::drawing::point_f structure that represents the starting point of the linear gradient.
        /// @param point2 A xtd::drawing::point_f structure that represents the endpoint of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        linear_gradient_brush(const xtd::drawing::point_f& point1, const xtd::drawing::point_f& point2, const xtd::drawing::color& color1, const xtd::drawing::color& color2) {
          data_->point1_ = point1;
          data_->point2_ = point2;
          data_->linear_colors_ = {color1, color2};
          recreate_handle();
        }
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle and colors.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2) : linear_gradient_brush(rect, color1, color2, xtd::drawing::drawing2d::linear_gradient_mode::horizontal) {}
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle, colors, and orientation.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        /// @param linear_gradient_mode A xtd::drawing::drawing2d::linear_gradient_mode enumeration element that specifies the orientation of the gradient. The orientation determines the starting and ending points of the gradient. For example, xtd::drawing::drawing2d::linear_gradient_mode::forward_diagonal specifies that the starting point is the upper-left corner of the rectangle and the ending point is the lower-right corner of the rectangle.
        linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, xtd::drawing::drawing2d::linear_gradient_mode linear_gradient_mode) {
          data_->point1_ = rect.location();
          data_->point2_ = xtd::drawing::point_f(rect.right(), rect.bottom());
          if (linear_gradient_mode == xtd::drawing::drawing2d::linear_gradient_mode::horizontal) data_->point2_.y(.0);
          if (linear_gradient_mode == xtd::drawing::drawing2d::linear_gradient_mode::vertical) data_->point2_.x(.0);
          if (linear_gradient_mode == xtd::drawing::drawing2d::linear_gradient_mode::backward_diagonal) {
            auto x = data_->point1_.x();
            data_->point1_.x(data_->point2_.x());
            data_->point2_.x(x);
          }
          data_->linear_colors_ = {color1, color2};
          recreate_handle();
        }
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle and colors.
        /// @param rect A xtd::drawing::rectangle_f structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        linear_gradient_brush(const xtd::drawing::rectangle& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2) : linear_gradient_brush(rect, color1, color2, xtd::drawing::drawing2d::linear_gradient_mode::horizontal) {}
        /// @brief Initializes a new instance of the linear_gradient_brush class with the specified rectangle, colors, and orientation.
        /// @param rect A xtd::drawing::rectangle structure that specifies the bounds of the linear gradient.
        /// @param color1 A xtd::drawing::color structure that represents the starting color of the linear gradient.
        /// @param color2 A xtd::drawing::color structure that represents the ending color of the linear gradient.
        /// @param linear_gradient_mode A xtd::drawing::drawing2d::linear_gradient_mode enumeration element that specifies the orientation of the gradient. The orientation determines the starting and ending points of the gradient. For example, xtd::drawing::drawing2d::linear_gradient_mode::forward_diagonal specifies that the starting point is the upper-left corner of the rectangle and the ending point is the lower-right corner of the rectangle.
        linear_gradient_brush(const xtd::drawing::rectangle& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, xtd::drawing::drawing2d::linear_gradient_mode linear_gradient_mode) {
          data_->point1_ = rect.location();
          data_->point2_ = xtd::drawing::point(rect.right(), rect.bottom());
          if (linear_gradient_mode == xtd::drawing::drawing2d::linear_gradient_mode::horizontal) data_->point2_.y(data_->point1_.y());
          if (linear_gradient_mode == xtd::drawing::drawing2d::linear_gradient_mode::vertical) data_->point2_.x(data_->point1_.x());
          if (linear_gradient_mode == xtd::drawing::drawing2d::linear_gradient_mode::backward_diagonal) {
            auto x = data_->point1_.x();
            data_->point1_.x(data_->point2_.x());
            data_->point2_.x(x);
          }
          data_->linear_colors_ = {color1, color2};
          recreate_handle();
        }

        /// @cond
        linear_gradient_brush(const linear_gradient_brush& value);
        linear_gradient_brush& operator=(const linear_gradient_brush& value);
        bool operator==(const linear_gradient_brush& value) const {return data_->point1_ == value.data_->point1_ && data_->point2_ == value.data_->point2_ && data_->linear_colors_[0] == value.data_->linear_colors_[0] && data_->linear_colors_[1] == value.data_->linear_colors_[1];}
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
        xtd::drawing::rectangle_f rectangle() const;
      
      private:
        linear_gradient_brush();
        void recreate_handle();
        struct data {
          xtd::drawing::point_f point1_;
          xtd::drawing::point_f point2_;
          std::array<xtd::drawing::color, 2> linear_colors_;
        };
        std::shared_ptr<data> data_ = std::make_shared<data>();
      };
    }
  }
}
