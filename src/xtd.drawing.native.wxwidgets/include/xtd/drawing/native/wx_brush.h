#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/argument_exception>
#include <wx/brush.h>
#include <wx/image.h>
#include <wx/graphics.h>
#include <cstdint>

namespace xtd {
  namespace drawing {
    namespace native {
      class wx_brush {
      public:
        enum class brush_type {
          none,
          solid,
          linear_gradient,
          radial_gradient,
          conical_gradient,
          texture
        };
        
        struct conical_gradiant_brush {
          wxPoint center_point;
          float angle = .0f;
          wxGraphicsGradientStops colors;
          //const wxGraphicsMatrix* graphics_matrix;
        };
        struct linear_gradiant_brush {
          wxPoint point1;
          wxPoint point2;
          wxGraphicsGradientStops colors;
          //const wxGraphicsMatrix* graphics_matrix;
        };
        struct radial_gradiant_brush {
          wxPoint center_point;
          wxPoint focal_point;
          float radius = .0f;
          wxGraphicsGradientStops colors;
          //const wxGraphicsMatrix* graphics_matrix;
        };
        struct solid_brush {
          wxColour color;
        };
        struct texture_brush {
          wxImage texture;
        };
        
        wx_brush() = default;
        
        void create_conical_gradiant_brush(const wxPoint& center_point, const wxGraphicsGradientStops& colors, float angle) {
          brush_type_ = brush_type::conical_gradient;
          conical_gradiant_brush_.center_point = center_point;
          conical_gradiant_brush_.angle = angle;
          conical_gradiant_brush_.colors = colors;
        }
        
        void create_linear_gradiant_brush(const wxPoint& point1, const wxPoint& point2, const wxGraphicsGradientStops& colors) {
          brush_type_ = brush_type::linear_gradient;
          linear_gradiant_brush_.point1 = point1;
          linear_gradiant_brush_.point2 = point2;
          linear_gradiant_brush_.colors = colors;
        }
        
        void create_radial_gradiant_brush(const wxPoint& center_point, const wxPoint& focal_point, const wxGraphicsGradientStops& colors, float radius) {
          brush_type_ = brush_type::radial_gradient;
          radial_gradiant_brush_.center_point = center_point;
          radial_gradiant_brush_.focal_point = focal_point;
          radial_gradiant_brush_.radius = radius;
          radial_gradiant_brush_.colors = colors;
        }
        
        void create_solid_brush(const wxColour& color) {
          brush_type_ = brush_type::solid;
          solid_brush_.color = color;
        }
        
        void create_texture_brush(const wxImage& texture) {
          brush_type_ = brush_type::texture;
          texture_brush_.texture = texture;
        }
        
        bool is_conical_gradiant_brush() const {return brush_type_ == brush_type::conical_gradient;}
        bool is_linear_gradiant_brush() const {return brush_type_ == brush_type::linear_gradient;}
        bool is_radial_gradiant_brush() const {return brush_type_ == brush_type::radial_gradient;}
        bool is_solid_brush() const {return brush_type_ == brush_type::solid;}
        bool is_texture_brush() const {return brush_type_ == brush_type::texture;}
        
        const conical_gradiant_brush& get_conical_gradiant_brush() const {return conical_gradiant_brush_;}
        conical_gradiant_brush& get_conical_gradiant_brush() {return conical_gradiant_brush_;}
        
        const linear_gradiant_brush& get_linear_gradiant_brush() const {return linear_gradiant_brush_;}
        linear_gradiant_brush& get_linear_gradiant_brush() {return linear_gradiant_brush_;}
        
        const radial_gradiant_brush& get_radial_gradiant_brush() const {return radial_gradiant_brush_;}
        radial_gradiant_brush& get_radial_gradiant_brush() {return radial_gradiant_brush_;}
        
        const solid_brush& get_solid_brush() const {return solid_brush_;}
        solid_brush& get_solid_brush() {return solid_brush_;}
        
        const texture_brush& get_texture_brush() const {return texture_brush_;}
        texture_brush& get_texture_brush() {return texture_brush_;}
        
        
        static wxBrush to_brush(const wx_brush& brush) {
          if (brush.is_solid_brush()) return wxBrush(brush.get_solid_brush().color);
          if (brush.is_texture_brush()) return wxBrush(brush.get_texture_brush().texture);
          throw xtd::argument_exception("brush not defined"_t, csf_);
        }
        
        static wxGraphicsBrush to_graphics_brush(wxGraphicsContext& graphics, const wx_brush& brush) {
          if (brush.is_conical_gradiant_brush()) return graphics.CreateBrush(wxBrush(brush.get_conical_gradiant_brush().colors.Item(0).GetColour()));
          if (brush.is_linear_gradiant_brush()) return graphics.CreateLinearGradientBrush(static_cast<double>(brush.get_linear_gradiant_brush().point1.x), static_cast<double>(brush.get_linear_gradiant_brush().point1.y), static_cast<double>(brush.get_linear_gradiant_brush().point2.x), static_cast<double>(brush.get_linear_gradiant_brush().point2.y), brush.get_linear_gradiant_brush().colors);
          if (brush.is_radial_gradiant_brush()) return graphics.CreateRadialGradientBrush(static_cast<double>(brush.get_radial_gradiant_brush().focal_point.x), static_cast<double>(brush.get_radial_gradiant_brush().focal_point.y), static_cast<double>(brush.get_radial_gradiant_brush().center_point.x), static_cast<double>(brush.get_radial_gradiant_brush().center_point.y), static_cast<double>(brush.get_radial_gradiant_brush().radius), brush.get_radial_gradiant_brush().colors);
          if (brush.is_solid_brush()) return graphics.CreateBrush(wxBrush(brush.get_solid_brush().color));
          if (brush.is_texture_brush()) return graphics.CreateBrush(wxBrush(brush.get_texture_brush().texture));
          throw xtd::argument_exception("brush not defined"_t, csf_);
        }
        
      private:
        brush_type brush_type_ = brush_type::none;
        conical_gradiant_brush conical_gradiant_brush_;
        linear_gradiant_brush linear_gradiant_brush_;
        radial_gradiant_brush radial_gradiant_brush_;
        solid_brush solid_brush_;
        texture_brush texture_brush_;
      };
    }
  }
}

