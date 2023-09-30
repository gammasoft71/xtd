#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "wx_brush.h"
#include <xtd/argument_exception>
#include <xtd/as>
#include <wx/pen.h>
#include <wx/image.h>
#include <wx/graphics.h>
#include <cstdint>

namespace xtd {
  namespace drawing {
    namespace native {
      class wx_pen {
      public:
        enum class pen_type {
          none,
          conical_gradient,
          hatch_fill,
          linear_gradient,
          radial_gradient,
          solid_color,
          texture_fill
        };
        
        struct conical_gradiant_pen {
          wx_brush brush;
          float width = 1.0f;
        };
        struct hatch_fill_pen {
          wx_brush brush;
          float width = 1.0f;
        };
        struct linear_gradiant_pen {
          wx_brush brush;
          float width = 1.0f;
        };
        struct radial_gradiant_pen {
          wx_brush brush;
          float width = 1.0f;
        };
        struct solid_color_pen {
          wxColour color;
          float width = 1.0f;
          float dash_offset = 0.0f;
          std::vector<xtd::sbyte> dashes;
        };
        struct texture_fill_pen {
          wx_brush brush;
          float width = 1.0f;
        };
        
        wx_pen() = default;
        
        void create_conical_gradient_pen(const wx_brush& brush, float width) {
          pen_type_ = pen_type::conical_gradient;
          conical_gradiant_pen_.brush = brush;
          conical_gradiant_pen_.width = width;
        }
        
        void create_hatch_fill_pen(const wx_brush& brush, float width) {
          pen_type_ = pen_type::hatch_fill;
          hatch_fill_pen_.brush = brush;
          hatch_fill_pen_.width = width;
        }
        
        void create_linear_gradient_pen(const wx_brush& brush, float width) {
          pen_type_ = pen_type::linear_gradient;
          linear_gradiant_pen_.brush = brush;
          linear_gradiant_pen_.width = width;
        }
        
        void create_radial_gradient_pen(const wx_brush& brush, float width) {
          pen_type_ = pen_type::radial_gradient;
          radial_gradiant_pen_.brush = brush;
          radial_gradiant_pen_.width = width;
        }
        
        void create_solid_color_pen(const wxColour& color, float width, float dash_offset, const std::vector<xtd::sbyte>& dashes) {
          pen_type_ = pen_type::solid_color;
          solid_color_pen_.color = color;
          solid_color_pen_.dash_offset = dash_offset;
          solid_color_pen_.dashes = dashes;
          solid_color_pen_.width = width;
        }
        
        void create_texture_fill_pen(const wx_brush& brush, float width) {
          pen_type_ = pen_type::texture_fill;
          texture_fill_pen_.brush = brush;
          texture_fill_pen_.width = width;
        }
        
        bool is_conical_gradiant_pen() const {return pen_type_ == pen_type::conical_gradient;}
        bool is_hatch_fill_pen() const {return pen_type_ == pen_type::hatch_fill;}
        bool is_linear_gradiant_pen() const {return pen_type_ == pen_type::linear_gradient;}
        bool is_radial_gradiant_pen() const {return pen_type_ == pen_type::radial_gradient;}
        bool is_solid_color_pen() const {return pen_type_ == pen_type::solid_color;}
        bool is_texture_fill_pen() const {return pen_type_ == pen_type::texture_fill;}
        
        const conical_gradiant_pen& get_conical_gradiant_pen() const {return conical_gradiant_pen_;}
        conical_gradiant_pen& get_conical_gradiant_pen() {return conical_gradiant_pen_;}
        
        const hatch_fill_pen& get_hatch_fill_pen() const {return hatch_fill_pen_;}
        hatch_fill_pen& get_hatch_fill_pen() {return hatch_fill_pen_;}
        
        const linear_gradiant_pen& get_linear_gradiant_pen() const {return linear_gradiant_pen_;}
        linear_gradiant_pen& get_linear_gradiant_pen() {return linear_gradiant_pen_;}
        
        const radial_gradiant_pen& get_radial_gradiant_pen() const {return radial_gradiant_pen_;}
        radial_gradiant_pen& get_radial_gradiant_pen() {return radial_gradiant_pen_;}
        
        const solid_color_pen& get_solid_color_pen() const {return solid_color_pen_;}
        solid_color_pen& get_solid_color_pen() {return solid_color_pen_;}
        
        const texture_fill_pen& get_texture_fill_pen() const {return texture_fill_pen_;}
        texture_fill_pen& get_texture_fill_pen() {return texture_fill_pen_;}
        
        wxPenJoin line_join() const {return line_join_;}
        void line_join(wxPenJoin  line_join) {line_join_ = line_join;}
        
        wxPenCap line_cap() const {return line_cap_;}
        void line_cap(wxPenCap  line_cap) {line_cap_ = line_cap;}
        
        static wxPen to_pen(const wx_pen& pen) {
          if (pen.is_solid_color_pen()) {
            wxPen wxpen(pen.get_solid_color_pen().color);
            if (pen.get_solid_color_pen().dashes.size() == 0)
              wxpen.SetStyle(wxPenStyle::wxPENSTYLE_SOLID);
            else {
              wxpen.SetStyle(wxPenStyle::wxPENSTYLE_USER_DASH);
              wxpen.SetDashes(as<int32>(pen.get_solid_color_pen().dashes.size()), pen.get_solid_color_pen().dashes.data());
            }
            wxpen.SetWidth(pen.get_solid_color_pen().width);
            wxpen.SetCap(pen.line_cap());
            wxpen.SetJoin(pen.line_join());
            return wxpen;
          }
          throw xtd::argument_exception("brush not defined"_t, csf_);
        }
        
        static wxGraphicsPen to_graphics_pen(wxGraphicsContext& graphics, const wx_pen& pen) {
          if (pen.is_solid_color_pen()) {
            wxGraphicsPenInfo pen_info;
            pen_info.Colour(pen.get_solid_color_pen().color);
            if (pen.get_solid_color_pen().dashes.size() == 0)
              pen_info.Style(wxPenStyle::wxPENSTYLE_SOLID);
            else {
              pen_info.Style(wxPenStyle::wxPENSTYLE_USER_DASH);
              pen_info.Dashes(as<int32>(pen.get_solid_color_pen().dashes.size()), pen.get_solid_color_pen().dashes.data());
            }
            pen_info.Width(pen.get_solid_color_pen().width);
            pen_info.Cap(pen.line_cap());
            pen_info.Join(pen.line_join());
            return graphics.CreatePen(pen_info);
          }
          if (pen.is_hatch_fill_pen()) {
            wxGraphicsPenInfo pen_info;
            pen_info.Colour({0, 0, 0, 0});
            pen_info.Stipple(wxBitmap(pen.get_hatch_fill_pen().brush.get_texture_brush().texture));
            pen_info.Width(pen.get_hatch_fill_pen().width);
            pen_info.Cap(pen.line_cap());
            pen_info.Join(pen.line_join());
            return graphics.CreatePen(pen_info);
          }
          if (pen.is_linear_gradiant_pen()) {
            wxGraphicsPenInfo pen_info;
            pen_info.Colour({0, 0, 0, 0});
            pen_info.LinearGradient(pen.get_linear_gradiant_pen().brush.get_linear_gradiant_brush().point1.x, pen.get_linear_gradiant_pen().brush.get_linear_gradiant_brush().point1.y, pen.get_linear_gradiant_pen().brush.get_linear_gradiant_brush().point2.x, pen.get_linear_gradiant_pen().brush.get_linear_gradiant_brush().point2.y, pen.get_linear_gradiant_pen().brush.get_linear_gradiant_brush().colors);
            pen_info.Width(pen.get_linear_gradiant_pen().width);
            pen_info.Cap(pen.line_cap());
            pen_info.Join(pen.line_join());
            return graphics.CreatePen(pen_info);
          }
          if (pen.is_radial_gradiant_pen()) {
            wxGraphicsPenInfo pen_info;
            pen_info.Colour({0, 0, 0, 0});
            pen_info.RadialGradient(pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().focal_point.x, pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().focal_point.y, pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().center_point.x, pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().center_point.y, pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().radius, pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().colors);
            pen_info.Width(pen.get_radial_gradiant_pen().width);
            pen_info.Cap(pen.line_cap());
            pen_info.Join(pen.line_join());
            return graphics.CreatePen(pen_info);
          }
          if (pen.is_texture_fill_pen()) {
            wxGraphicsPenInfo pen_info;
            pen_info.Colour({0, 0, 0, 0});
            pen_info.Stipple(wxBitmap(pen.get_texture_fill_pen().brush.get_texture_brush().texture));
            pen_info.Width(pen.get_texture_fill_pen().width);
            pen_info.Cap(pen.line_cap());
            pen_info.Join(pen.line_join());
            return graphics.CreatePen(pen_info);
          }
          if (pen.is_conical_gradiant_pen()) {
            wxGraphicsPenInfo pen_info;
            pen_info.Colour(pen.get_conical_gradiant_pen().brush.get_conical_gradiant_brush().colors.Item(0).GetColour());
            pen_info.Width(pen.get_conical_gradiant_pen().width);
            pen_info.Cap(pen.line_cap());
            pen_info.Join(pen.line_join());
            return graphics.CreatePen(pen_info);
          }
          
          throw xtd::argument_exception("brush not defined"_t, csf_);
        }
        
      private:
        pen_type pen_type_ = pen_type::none;
        conical_gradiant_pen conical_gradiant_pen_;
        hatch_fill_pen hatch_fill_pen_;
        linear_gradiant_pen linear_gradiant_pen_;
        radial_gradiant_pen radial_gradiant_pen_;
        solid_color_pen solid_color_pen_;
        texture_fill_pen texture_fill_pen_;
        wxPenCap line_cap_ = wxCAP_BUTT;
        wxPenJoin line_join_ = wxJOIN_MITER;
      };
    }
  }
}

