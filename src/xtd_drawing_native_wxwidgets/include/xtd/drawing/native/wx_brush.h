#pragma once

#include <cstdint>
#include <wx/brush.h>
#include <wx/graphics.h>

namespace xtd {
  namespace drawing {
    namespace native {
      class wx_brush {
      public:
        enum class brush_type {
          none,
          solid,
          linear_gradient
        };
        
        struct solid_brush {
          wxColour color;
        };
        struct linear_gradiant_brush {
          wxPoint point1;
          wxPoint point2;
          wxColour color1;
          wxColour color2;
          //const wxGraphicsMatrix* graphics_matrix;
        };

        wx_brush() = default;

        void create_solid_brush(const wxColour& color) {
          brush_type_ = brush_type::solid;
          solid_brush_.color = color;
        }
        
        void create_linear_gradiant_brush(const wxPoint& point1, const wxPoint& point2, const wxColour& color1, const wxColour& color2) {
          brush_type_ = brush_type::linear_gradient;
          linear_gradiant_brush_.point1 = point1;
          linear_gradiant_brush_.point2 = point2;
          linear_gradiant_brush_.color1 = color1;
          linear_gradiant_brush_.color2 = color2;
        }
        
        bool is_solid_brush() const {return brush_type_ == brush_type::solid;}
        bool is_linear_gradiant_brush() const {return brush_type_ == brush_type::linear_gradient;}

        const solid_brush& get_solid_brush() const {return solid_brush_;}
        solid_brush& get_solid_brush() {return solid_brush_;}
        
        const linear_gradiant_brush& get_linear_gradiant_brush() const {return linear_gradiant_brush_;}
        linear_gradiant_brush& get_linear_gradiant_brush() {return linear_gradiant_brush_;}

      private:
        brush_type brush_type_ = brush_type::none;
        solid_brush solid_brush_;
        linear_gradiant_brush linear_gradiant_brush_;
      };
    }
  }
}

