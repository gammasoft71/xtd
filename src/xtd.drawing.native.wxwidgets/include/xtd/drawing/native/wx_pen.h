#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <wx/pen.h>
#include <wx/image.h>
#include <wx/graphics.h>

namespace xtd {
  namespace drawing {
    namespace native {
      class wx_pen {
      public:
        enum class pen_type {
          none,
          solid,
          linear_gradient,
          texture
        };
        
        struct solid_pen {
          wxColour color;
        };
        struct linear_gradiant_pen {
          wxPoint point1;
          wxPoint point2;
          wxColour color1;
          wxColour color2;
          //const wxGraphicsMatrix* graphics_matrix;
        };
        struct texture_pen {
          wxImage texture;
        };
        
        wx_pen() = default;
        
        void create_solid_pen(const wxColour& color) {
          pen_type_ = pen_type::solid;
          solid_pen_.color = color;
        }
        
        void create_linear_gradiant_pen(const wxPoint& point1, const wxPoint& point2, const wxColour& color1, const wxColour& color2) {
          pen_type_ = pen_type::linear_gradient;
          linear_gradiant_pen_.point1 = point1;
          linear_gradiant_pen_.point2 = point2;
          linear_gradiant_pen_.color1 = color1;
          linear_gradiant_pen_.color2 = color2;
        }
        
        void create_texture_pen(const wxImage& texture) {
          pen_type_ = pen_type::texture;
          texture_pen_.texture = texture;
        }
        
        bool is_solid_pen() const {return pen_type_ == pen_type::solid;}
        bool is_linear_gradiant_pen() const {return pen_type_ == pen_type::linear_gradient;}
        bool is_texture_pen() const {return pen_type_ == pen_type::texture;}
        
        const solid_pen& get_solid_pen() const {return solid_pen_;}
        solid_pen& get_solid_pen() {return solid_pen_;}
        
        const linear_gradiant_pen& get_linear_gradiant_pen() const {return linear_gradiant_pen_;}
        linear_gradiant_pen& get_linear_gradiant_pen() {return linear_gradiant_pen_;}
        
        const texture_pen& get_texture_pen() const {return texture_pen_;}
        texture_pen& get_texture_pen() {return texture_pen_;}
        
      private:
        pen_type pen_type_ = pen_type::none;
        solid_pen solid_pen_;
        linear_gradiant_pen linear_gradiant_pen_;
        texture_pen texture_pen_;
      };
    }
  }
}

