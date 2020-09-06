#pragma once
#include "../brush.h"
#include "../color.h"
#include "../point.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::.drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      class linear_gradient_brush : public brush {
      public:
        linear_gradient_brush();
        linear_gradient_brush(const xtd::drawing::point& point1, const xtd::drawing::point& point2, const xtd::drawing::color& color1, const xtd::drawing::color& color2) {
          data_->point1_ = point1;
          data_->point2_ = point2;
          data_->color1_ = color1;
          data_->color2_ = color2;
          recreate_handle();
        }
        
        /// @cond
        linear_gradient_brush(const linear_gradient_brush& value);
        linear_gradient_brush& operator=(const linear_gradient_brush& value);
        bool operator==(const linear_gradient_brush& value) const {return data_->point1_ == value.data_->point1_ && data_->point2_ == value.data_->point2_ && data_->color1_ == value.data_->color1_ && data_->color2_ == value.data_->color2_;}
        bool operator!=(const linear_gradient_brush& value) const {return !this->operator==(value);}
        /// @endcond
        
        const xtd::drawing::point& point1() const {return data_->point1_;}
        xtd::drawing::drawing2d::linear_gradient_brush& point1(const xtd::drawing::point& point1);
        
        const xtd::drawing::point& point2() const {return data_->point2_;}
        xtd::drawing::drawing2d::linear_gradient_brush& point2(const xtd::drawing::point& point2);
        
        const xtd::drawing::color& color1() const {return data_->color1_;}
        xtd::drawing::drawing2d::linear_gradient_brush& color1(const xtd::drawing::color& color1);

        const xtd::drawing::color& color2() const {return data_->color2_;}
        xtd::drawing::drawing2d::linear_gradient_brush& color2(const xtd::drawing::color& color2);
      
        private:
        void recreate_handle();
        struct data {
          xtd::drawing::point point1_;
          xtd::drawing::point point2_;
          xtd::drawing::color color1_;
          xtd::drawing::color color2_;
        };
        std::shared_ptr<data> data_ = std::make_shared<data>();
      };
    }
  }
}
