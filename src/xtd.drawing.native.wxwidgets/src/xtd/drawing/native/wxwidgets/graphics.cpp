#include <wx/app.h>
#include <wx/dcgraph.h>
#include <wx/dcmemory.h>
#include <wx/dcscreen.h>
#include <wx/region.h>
#undef interface
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include "../../../../../include/xtd/drawing/native/hdc_wrapper.hpp"
#include "../../../../../include/xtd/drawing/native/wx_brush.hpp"
#include "../../../../../include/xtd/drawing/native/wx_pen.hpp"
#include "../../../../../include/xtd/drawing/native/wxConicalGradient.hpp"
#include "../../../../../include/xtd/drawing/native/wxDrawString.hpp"
#include <xtd/drawing/native/graphics>
#include <xtd/drawing/native/compositing_modes>
#include <xtd/drawing/native/compositing_qualities>
#include <xtd/drawing/native/copy_pixel_operations>
#include <xtd/drawing/native/flush_intentions>
#include <xtd/drawing/native/path_fill_modes>
#include <xtd/drawing/native/interpolation_modes>
#include <xtd/drawing/native/hot_key_prefixes>
#include <xtd/drawing/native/pixel_offset_modes>
#include <xtd/drawing/native/smoothing_modes>
#include <xtd/drawing/native/string_alignments>
#include <xtd/drawing/native/string_trimmings>
#include <xtd/drawing/native/text_rendering>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/as>
#include <xtd/convert_string>
#include <xtd/math>
#include <xtd/string>
#include <cmath>
#include <vector>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::drawing::native;
using namespace xtd::helpers;

namespace {
  std::map<intptr, int32> graphics_state;
  class graphics_context {
  public:
    explicit graphics_context(intptr handle) : hdc_(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc()) {
      brush_ = hdc_.GetBrush();
      pen_ = hdc_.GetPen();
      back_color_ = hdc_.GetTextBackground();
      fore_color_ = hdc_.GetTextForeground();
      font_ = hdc_.GetFont();
    }
    
    ~graphics_context() {
      hdc_.SetBrush(brush_);
      hdc_.SetPen(pen_);
      hdc_.SetTextBackground(back_color_);
      hdc_.SetTextForeground(fore_color_);
      hdc_.SetFont(font_);
    }
    
  private:
    wxDC& hdc_;
    wxBrush brush_;
    wxColour back_color_;
    wxColour fore_color_;
    wxPen pen_;
    wxFont font_;
  };
  
  wxAlignment to_wx_align(int32 alignment, int32 line_alignment) {
    int32 result = wxAlignment::wxALIGN_NOT;
    if (alignment == SA_NEAR) result += wxAlignment::wxALIGN_LEFT;
    else if (alignment == SA_CENTER) result += wxAlignment::wxALIGN_CENTER_HORIZONTAL;
    else if (alignment == SA_FAR) result += wxAlignment::wxALIGN_RIGHT;
    if (line_alignment == SA_NEAR) result += wxAlignment::wxALIGN_TOP;
    else if (line_alignment == SA_CENTER) result += wxAlignment::wxALIGN_CENTER_VERTICAL;
    else if (line_alignment == SA_FAR) result += wxAlignment::wxALIGN_BOTTOM;
    return static_cast<wxAlignment>(result);
  }
  
  wxBitmap render_brush_to_bitmap_with_mask(const wxSize& size, const wx_brush* brush, const std::function<void(wxMemoryDC&)>& draw_mask) {
    if (!brush->is_gradient_brush()) return wxBitmap {size};
    
    auto gradient_bitmap = wxBitmap {size};
    if (brush->is_conical_gradiant_brush()) gradient_bitmap = wxConicalGradient::CreateBitmap(size, brush->get_conical_gradiant_brush().colors, brush->get_conical_gradiant_brush().center_point, brush->get_conical_gradiant_brush().angle);
    else {
      auto dc = wxMemoryDC(gradient_bitmap);
      auto graphics = wxGraphicsContext::Create(dc);
      graphics->SetPen(wxNullPen);
      graphics->SetBrush(wx_brush::to_graphics_brush(*graphics, *brush));
      graphics->DrawRectangle(.0, .0, static_cast<double>(size.GetWidth()), static_cast<double>(size.GetHeight()));
    }
    
    auto gradient_image = gradient_bitmap.ConvertToImage();
    
    auto mask_bitmap = wxBitmap {size};
    {
      auto mask_dc = wxMemoryDC {mask_bitmap};
      mask_dc.SetBrush(*wxWHITE_BRUSH);
      mask_dc.Clear();
      mask_dc.SetBrush(*wxBLACK_BRUSH);
      mask_dc.SetPen(*wxTRANSPARENT_PEN);
      draw_mask(mask_dc); // ex: ellipse, pie, polygon...
    }
    
    gradient_image.SetMaskFromImage(mask_bitmap.ConvertToImage(), 255, 255, 255);
    
    return wxBitmap(gradient_image);
  }
  
  wxPoint2DDouble eval_cubic(const wxPoint2DDouble& P0, const wxPoint2DDouble& P1, const wxPoint2DDouble& P2, const wxPoint2DDouble& P3, double t) {
    // Horner form: ((a*t + b)*t + c)*t + d where a,b,c,d are vector coeffs
    double ax = -P0.m_x + 3.0 * P1.m_x - 3.0 * P2.m_x + P3.m_x;
    double bx =  3.0 * P0.m_x - 6.0 * P1.m_x + 3.0 * P2.m_x;
    double cx = -3.0 * P0.m_x + 3.0 * P1.m_x;
    double dx =  P0.m_x;
    double x = ((ax * t + bx) * t + cx) * t + dx;
    
    double ay = -P0.m_y + 3.0 * P1.m_y - 3.0 * P2.m_y + P3.m_y;
    double by =  3.0 * P0.m_y - 6.0 * P1.m_y + 3.0 * P2.m_y;
    double cy = -3.0 * P0.m_y + 3.0 * P1.m_y;
    double dy =  P0.m_y;
    double y = ((ay * t + by) * t + cy) * t + dy;
    
    return wxPoint2DDouble(x, y);
  }
  
  // Expand bbox to include cubic bezier segment P0..P3 (including internal extrema)
  void expand_bbox_for_cubic(const wxPoint2DDouble& P0, const wxPoint2DDouble& P1, const wxPoint2DDouble& P2, const wxPoint2DDouble& P3, double& minx, double& miny, double& maxx, double& maxy) {
    // include control points / endpoints
    auto include_point = [&](const wxPoint2DDouble & p) {
      minx = std::min(minx, p.m_x);
      miny = std::min(miny, p.m_y);
      maxx = std::max(maxx, p.m_x);
      maxy = std::max(maxy, p.m_y);
    };
    include_point(P0); include_point(P1); include_point(P2); include_point(P3);
    
    // derivative coefficients: B'(t) = 3a t^2 + 2b t + c
    auto ax = -P0.m_x + 3.0 * P1.m_x - 3.0 * P2.m_x + P3.m_x;
    auto bx =  3.0 * P0.m_x - 6.0 * P1.m_x + 3.0 * P2.m_x;
    auto cx = -3.0 * P0.m_x + 3.0 * P1.m_x;
    auto ay = -P0.m_y + 3.0 * P1.m_y - 3.0 * P2.m_y + P3.m_y;
    auto by =  3.0 * P0.m_y - 6.0 * P1.m_y + 3.0 * P2.m_y;
    auto cy = -3.0 * P0.m_y + 3.0 * P1.m_y;
    
    // Solve 3a t^2 + 2b t + c = 0  (for x and y separately)
    auto solve_quadratic_and_add = [&](double A, double B, double C) {
      const auto EPS = 1e-12;
      if (std::abs(A) < EPS) {
        if (std::abs(B) < EPS) return; // constant -> no root
        auto t = -C / B;
        if (t > 0.0 && t < 1.0) {
          // later we'll evaluate full curve at t
          wxPoint2DDouble p = eval_cubic(P0, P1, P2, P3, t);
          include_point(p);
        }
        return;
      }
      auto disc = B * B - 4.0 * A * C;
      if (disc < 0.0) return;
      auto s = std::sqrt(disc);
      auto t1 = (-B + s) / (2.0 * A);
      auto t2 = (-B - s) / (2.0 * A);
      if (t1 > 0.0 && t1 < 1.0) include_point(eval_cubic(P0, P1, P2, P3, t1));
      if (t2 > 0.0 && t2 < 1.0) include_point(eval_cubic(P0, P1, P2, P3, t2));
    };
    
    // For x: A = 3*ax, B = 2*bx, C = cx
    solve_quadratic_and_add(3.0 * ax, 2.0 * bx, cx);
    // For y:
    solve_quadratic_and_add(3.0 * ay, 2.0 * by, cy);
  }
}

void graphics::copy_from_graphics(intptr handle, intptr handle_source, int32 source_x, int32 source_y, int32 destination_x, int32 destination_y, int32 block_region_width, int32 block_region_height, int32 copy_pixel_operation) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxRasterOperationMode raster_operation_mode = wxRasterOperationMode::wxCOPY;
  switch (copy_pixel_operation) {
    case CPO_BLACKNESS: raster_operation_mode = wxRasterOperationMode::wxCLEAR; break;
    case CPO_CAPTURE_BLT: raster_operation_mode = wxRasterOperationMode::wxCOPY; break;
    case CPO_DESTINATION_INVERT: raster_operation_mode = wxRasterOperationMode::wxINVERT; break;
    case CPO_MERGE_COPY: raster_operation_mode = wxRasterOperationMode::wxAND; break;
    case CPO_MERGE_PAINT: raster_operation_mode = wxRasterOperationMode::wxOR_INVERT; break;
    case CPO_NO_MIRROR_BITMAP: raster_operation_mode = wxRasterOperationMode::wxINVERT; break;
    case CPO_NOT_SOURCE_COPY: raster_operation_mode = wxRasterOperationMode::wxSRC_INVERT; break;
    case CPO_NOT_SOURCE_ERASE: raster_operation_mode = wxRasterOperationMode::wxOR_INVERT; break;
    case CPO_PAT_COPY:  break;
    case CPO_PAT_INVERT:  break;
    case CPO_PAT_PAINT:  break;
    case CPO_SOURCE_AND: raster_operation_mode = wxRasterOperationMode::wxAND; break;
    case CPO_SOURCE_COPY: raster_operation_mode = wxRasterOperationMode::wxCOPY; break;
    case CPO_SOURCE_ERASE: raster_operation_mode = wxRasterOperationMode::wxAND_INVERT; break;
    case CPO_SOURCE_INVERT: raster_operation_mode = wxRasterOperationMode::wxXOR; break;
    case CPO_SOURCE_PAINT: raster_operation_mode = wxRasterOperationMode::wxOR; break;
    case CPO_WHITENESS: raster_operation_mode = wxRasterOperationMode::wxSET; break;
    default: raster_operation_mode = wxRasterOperationMode::wxCOPY; break;
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc().Blit(destination_x, destination_y, block_region_width, block_region_height, &reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle_source)->hdc(), source_x, source_y, raster_operation_mode);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::clear(intptr handle, xtd::byte a, xtd::byte r, xtd::byte g, xtd::byte b) {
  if (handle == 0) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  auto path = graphics.CreatePath();
  double width = 0.0, height = 0.0;
  graphics.GetSize(&width, &height);
  path.AddRectangle(0, 0, width, height);
  graphics.SetBrush(wxBrush({r, g, b, a}));
  graphics.FillPath(path);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::clip(intptr handle, intptr region) {
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc().SetClippingRegion(reinterpret_cast<wxRegion*>(region)->GetBox());
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->Clip(*reinterpret_cast<wxRegion*>(region));
}

void graphics::compositing_mode(intptr handle, int32 compositing_mode) {
  if (!handle) throw_helper::throws(exception_case::argument);
  // Not defined in wxWidgets
}

void graphics::compositing_quality(intptr handle, int32 compositing_quality) {
  if (!handle) throw_helper::throws(exception_case::argument);
  // Not defined in wxWidgets
}

void graphics::copy_from_screen(intptr handle, int32 source_x, int32 source_y, int32 destination_x, int32 destination_y, int32 block_region_width, int32 block_region_height, int32 copy_pixel_operation) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxScreenDC screen_dc;
  wxRasterOperationMode raster_operation_mode = wxRasterOperationMode::wxCOPY;
  switch (copy_pixel_operation) {
    case CPO_BLACKNESS: raster_operation_mode = wxRasterOperationMode::wxCLEAR; break;
    case CPO_CAPTURE_BLT: raster_operation_mode = wxRasterOperationMode::wxCOPY; break;
    case CPO_DESTINATION_INVERT: raster_operation_mode = wxRasterOperationMode::wxINVERT; break;
    case CPO_MERGE_COPY: raster_operation_mode = wxRasterOperationMode::wxAND; break;
    case CPO_MERGE_PAINT: raster_operation_mode = wxRasterOperationMode::wxOR_INVERT; break;
    case CPO_NO_MIRROR_BITMAP: raster_operation_mode = wxRasterOperationMode::wxINVERT; break;
    case CPO_NOT_SOURCE_COPY: raster_operation_mode = wxRasterOperationMode::wxSRC_INVERT; break;
    case CPO_NOT_SOURCE_ERASE: raster_operation_mode = wxRasterOperationMode::wxOR_INVERT; break;
    case CPO_PAT_COPY:  break;
    case CPO_PAT_INVERT:  break;
    case CPO_PAT_PAINT:  break;
    case CPO_SOURCE_AND: raster_operation_mode = wxRasterOperationMode::wxAND; break;
    case CPO_SOURCE_COPY: raster_operation_mode = wxRasterOperationMode::wxCOPY; break;
    case CPO_SOURCE_ERASE: raster_operation_mode = wxRasterOperationMode::wxAND_INVERT; break;
    case CPO_SOURCE_INVERT: raster_operation_mode = wxRasterOperationMode::wxXOR; break;
    case CPO_SOURCE_PAINT: raster_operation_mode = wxRasterOperationMode::wxOR; break;
    case CPO_WHITENESS: raster_operation_mode = wxRasterOperationMode::wxSET; break;
    default: raster_operation_mode = wxRasterOperationMode::wxCOPY; break;
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc().Blit(destination_x, destination_y, block_region_width, block_region_height, &screen_dc, source_x, source_y, raster_operation_mode);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::destroy(intptr handle) {
  if (!handle) throw_helper::throws(exception_case::argument);
  graphics_state.erase(handle);
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle);
  delete hdc_wrapper;
}

void graphics::draw_arc(intptr handle, intptr pen, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  if (!handle) throw_helper::throws(exception_case::argument);
  graphics_context gc(handle);
  wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
  dc.SetBrush(*wxTRANSPARENT_BRUSH);
  dc.SetPen(wx_pen::to_pen(*reinterpret_cast<wx_pen*>(pen)));
  dc.DrawEllipticArc(x, y, width, height, 360 - start_angle - sweep_angle, 360 - start_angle);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_bezier(intptr handle, intptr pen, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
  if (!handle) throw_helper::throws(exception_case::argument);
  auto path = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->CreatePath();
  path.MoveToPoint(x1, y1);
  path.AddCurveToPoint(x2, y2, x3, y3, x4, y4);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawPath(path);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_beziers(intptr handle, intptr pen, const array<key_value_pair<float, float>>& points) {
  if (!handle) throw_helper::throws(exception_case::argument);
  auto path = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->CreatePath();
  path.MoveToPoint(points[0].first, points[0].second);
  for (auto index = 1_z; index < points.length(); index += 3) {
    path.AddCurveToPoint(points[index].first, points[index].second, points[index + 1].first, points[index + 1].second, points[index + 2].first, points[index + 2].second);
    path.MoveToPoint(points[index + 2].first, points[index + 2].second);
  }
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawPath(path);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_closed_curve(intptr handle, intptr pen, const array<key_value_pair<float, float>> points, float tension) {
  if (!handle) throw_helper::throws(exception_case::argument);
  graphics_context gc(handle);
  wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
  dc.SetBrush(*wxTRANSPARENT_BRUSH);
  dc.SetPen(wx_pen::to_pen(*reinterpret_cast<wx_pen*>(pen)));
  std::vector<wxPoint> wx_points;
  for (auto [x, y] : points)
    wx_points.push_back(wxPoint(as<int32>(x), as<int32>(y)));
  wx_points.push_back(wx_points[0]);
  dc.DrawSpline(as<int32>(wx_points.size()), wx_points.data());
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_curve(intptr handle, intptr pen, const array<key_value_pair<float, float>> points, float tension) {
  if (!handle) throw_helper::throws(exception_case::argument);
  graphics_context gc(handle);
  wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
  dc.SetBrush(*wxTRANSPARENT_BRUSH);
  dc.SetPen(wx_pen::to_pen(*reinterpret_cast<wx_pen*>(pen)));
  std::vector<wxPoint> wx_points;
  for (auto [x, y] : points)
    wx_points.push_back(wxPoint(as<int32>(x), as<int32>(y)));
  dc.DrawSpline(as<int32>(wx_points.size()), wx_points.data());
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_ellipse(intptr handle, intptr pen, float x, float y, float width, float height) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawEllipse(x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_image(intptr handle, intptr image, float x, float y, float width, float height) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  wxBitmap bitmap = wxBitmap(*reinterpret_cast<wxImage*>(image));
  graphics.DrawBitmap(bitmap, x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_image(intptr handle, intptr image, float dest_x, float dest_y, float dest_width, float dest_height, float src_x, float src_y, float src_width, float src_height) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  auto new_image = *reinterpret_cast<wxImage*>(image);
  if (src_x + src_width <= new_image.GetWidth()) new_image = new_image.GetSubImage({static_cast<int>(src_x), 0, static_cast<int>(src_width), new_image.GetHeight()});
  if (src_y + src_height <= new_image.GetHeight()) new_image = new_image.GetSubImage({0, static_cast<int>(src_y), new_image.GetWidth(), static_cast<int>(src_height)});
  if (src_width > new_image.GetWidth() || src_height > new_image.GetHeight()) new_image = new_image.Resize({static_cast<int>(src_width), static_cast<int>(src_height)}, {});
  wxBitmap bitmap = wxBitmap(new_image);
  graphics.DrawBitmap(bitmap, dest_x, dest_y, dest_width, dest_height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_image_disabled(intptr handle, intptr image, float x, float y, float width, float height, float brightness) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  wxBitmap bitmap = wxBitmap(*reinterpret_cast<wxImage*>(image)).ConvertToDisabled(static_cast<xtd::byte>(255 * brightness));
  graphics.DrawBitmap(bitmap, x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_line(intptr handle, intptr pen, float x1, float y1, float x2, float y2) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.StrokeLine(x1, y1, x2, y2);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_lines(intptr handle, intptr pen, const array<key_value_pair<float, float>>& points) {
  if (!handle) throw_helper::throws(exception_case::argument);
  
  auto start_line = points[0];
  for (auto it = points.begin() + 1; it != points.end(); ++it) {
    draw_line(handle, pen, start_line.first, start_line.second, it->first, it->second);
    start_line = *it;
  }
  /*
  std::vector<wxPoint2DDouble> wx_points;
  for (auto [x, y] : points)
    wx_points.push_back(wxPoint(as<double>(x), as<double>(y)));
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawLines(wx_points.size(), wx_points.data());
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
   */
}

void graphics::draw_path(intptr handle, intptr pen, intptr graphics_path) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawPath(*reinterpret_cast<wxGraphicsPath*>(graphics_path));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_pie(intptr handle, intptr pen, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  if (!handle) throw_helper::throws(exception_case::argument);
  graphics_context gc(handle);
  wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
  dc.SetBrush(*wxTRANSPARENT_BRUSH);
  dc.SetPen(wx_pen::to_pen(*reinterpret_cast<wx_pen*>(pen)));
  dc.DrawEllipticArc(x, y, width, height, 360 - start_angle - sweep_angle, 360 - start_angle);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_polygon(intptr handle, intptr pen, const array<key_value_pair<float, float>>& points) {
  if (!handle) throw_helper::throws(exception_case::argument);
  std::vector<wxPoint2DDouble> wx_points;
  for (auto [x, y] : points)
    wx_points.push_back(wxPoint(as<double>(x), as<double>(y)));
  wx_points.push_back(wx_points[0]);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawLines(wx_points.size(), wx_points.data());
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_rectangle(intptr handle, intptr pen, float x, float y, float width, float height) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawRectangle(x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_rectangles(intptr handle, intptr pen, const array<std::tuple<float, float, float, float>>& rects) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  for (auto [x, y, width, height] : rects)
    graphics.DrawRectangle(x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_rotated_string(intptr handle, const xtd::string& text, intptr font, intptr brush, float x, float y, float angle) {
  wxDrawString::DrawString(handle, convert_string::to_wstring(text).chars().c_str(), *reinterpret_cast<wxFont*>(font), *reinterpret_cast<wx_brush*>(brush), x, y, angle, wxAlignment::wxALIGN_NOT, HKP_NONE, ST_NONE);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_rounded_rectangle(intptr handle, intptr pen, float x, float y, float width, float height, float radius) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawRoundedRectangle(x, y, width, height, radius);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_string(intptr handle, const xtd::string& text, intptr font, intptr brush, float x, float y, int32 alignment, int32 line_alignment, int32 hot_key_prefix, int32 trimming) {
  wxDrawString::DrawString(handle, convert_string::to_wstring(text).chars().c_str(), *reinterpret_cast<wxFont*>(font), *reinterpret_cast<wx_brush*>(brush), x, y, 0.0f, to_wx_align(alignment, line_alignment), hot_key_prefix, trimming);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_string(intptr handle, const xtd::string& text, intptr font, intptr brush, float x, float y, float width, float height, int32 alignment, int32 line_alignment, int32 hot_key_prefix, int32 trimming, int32 string_formats) {
  wxDrawString::DrawString(handle, convert_string::to_wstring(text).chars().c_str(), *reinterpret_cast<wxFont*>(font), *reinterpret_cast<wx_brush*>(brush), x, y, width, height, 0.0f, to_wx_align(alignment, line_alignment), hot_key_prefix, trimming, string_formats);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_closed_curve(intptr handle, intptr brush, const array<key_value_pair<float, float>> points, uint32 fill_mode, float tension) {
  if (!handle) throw_helper::throws(exception_case::argument);
  
  graphics_context gc(handle);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  
  auto pts = std::vector<wxPoint2DDouble> {};
  for (auto [x, y] : points)
    pts.emplace_back(x, y);
    
  if (pts.size() < 2) return;
  
  pts.push_back(pts[0]);
  pts.push_back(pts[1]);
  
  auto s = tension == 0 ? 0.5 : static_cast<double>(tension);
  
  auto minx = std::numeric_limits<double>::infinity();
  auto miny = std::numeric_limits<double>::infinity();
  auto maxx = -std::numeric_limits<double>::infinity();
  auto maxy = -std::numeric_limits<double>::infinity();
  
  for (auto i = 1_z; i + 2 < pts.size(); ++i) {
    wxPoint2DDouble p0 = pts[i - 1];
    wxPoint2DDouble p1 = pts[i];
    wxPoint2DDouble p2 = pts[i + 1];
    wxPoint2DDouble p3 = pts[i + 2];
    
    wxPoint2DDouble c1(p1.m_x + (p2.m_x - p0.m_x) * (s / 3.0), p1.m_y + (p2.m_y - p0.m_y) * (s / 3.0));
    wxPoint2DDouble c2(p2.m_x - (p3.m_x - p1.m_x) * (s / 3.0), p2.m_y - (p3.m_y - p1.m_y) * (s / 3.0));
    expand_bbox_for_cubic(p0, c1, c2, p2, minx, miny, maxx, maxy);
  }
  
  const auto PADDING = 2;
  auto bx = static_cast<int>(std::floor(minx)) - PADDING;
  auto by = static_cast<int>(std::floor(miny)) - PADDING;
  auto bwidth  = std::max(1, static_cast<int>(std::ceil(maxx)) - bx + PADDING);
  auto bheight = std::max(1, static_cast<int>(std::ceil(maxy)) - by + PADDING);
  
  auto path = graphics.CreatePath();
  path.MoveToPoint(pts[0]);
  for (auto i = 1_z; i + 2 < pts.size(); ++i) {
    auto p0 = pts[i - 1];
    auto p1 = pts[i];
    auto p2 = pts[i + 1];
    auto p3 = pts[i + 2];
    
    auto c1 = wxPoint2DDouble(p1.m_x + (p2.m_x - p0.m_x) * (s / 3.0), p1.m_y + (p2.m_y - p0.m_y) * (s / 3.0));
    auto c2 = wxPoint2DDouble(p2.m_x - (p3.m_x - p1.m_x) * (s / 3.0), p2.m_y - (p3.m_y - p1.m_y) * (s / 3.0));
    path.AddCurveToPoint(c1, c2, p2);
  }
  path.CloseSubpath();
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush()) {
    auto gradient_bitmap = wxConicalGradient::CreateBitmap(wxSize(bwidth, bheight), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().colors, reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().center_point - wxPoint(bx, by), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().angle);
    
    auto mask_bitmap = wxBitmap(bwidth, bheight, 32);
    {
      auto mask_dc = wxMemoryDC(mask_bitmap);
      mask_dc.SetBackground(*wxBLACK_BRUSH);
      mask_dc.Clear();
      
      auto mask_gc = wxGraphicsContext::Create(mask_dc);
      if (mask_gc) {
        auto mask_path = path; // copie du path existant
        auto m = mask_gc->CreateMatrix();
        m.Translate(-bx, -by);
        mask_path.Transform(m);
        
        mask_gc->SetBrush(*wxWHITE_BRUSH);
        mask_gc->SetPen(*wxTRANSPARENT_PEN);
        mask_gc->FillPath(mask_path);
        
        delete mask_gc;
      }
    }
    
    gradient_bitmap.SetMask(new wxMask(mask_bitmap, *wxBLACK));
    graphics.DrawBitmap(gradient_bitmap, bx, by, bwidth, bheight);
  } else {
    graphics.SetBrush(wx_brush::to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.FillPath(path, fill_mode == 0 ? wxODDEVEN_RULE : wxWINDING_RULE);
  }
  
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_ellipse(intptr handle, intptr brush, float x, float y, float width, float height) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush()) {
    auto& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
    wxBitmap bitmap = render_brush_to_bitmap_with_mask(wxSize(width, height), reinterpret_cast<wx_brush*>(brush), [&](wxMemoryDC & mask_dc) {mask_dc.DrawEllipse(0, 0, width, height);});
    dc.DrawBitmap(bitmap, x, y, true);
  } else {
    graphics.SetPen(wxNullPen);
    graphics.SetBrush(wx_brush::to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.DrawEllipse(static_cast<double>(x), static_cast<double>(y), static_cast<double>(width), static_cast<double>(height));
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_path(intptr handle, intptr brush, intptr graphics_path, int32 mode) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush()) {
    double x, y, width, height;
    reinterpret_cast<wxGraphicsPath*>(graphics_path)->GetBox(&x, &y, &width, &height);
    wxBitmap conical_gradient_bitmap = wxConicalGradient::CreateBitmap(wxSize(x + width, y + height), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().colors, reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().center_point, reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().angle);
    wxImage conical_gradient_image = conical_gradient_bitmap.ConvertToImage();
    wxBitmap conical_gradient_bitmap_mask(x + width, y + height);
    auto conical_gradient_mask_graphics = wxGraphicsContext::Create(wxMemoryDC(conical_gradient_bitmap_mask));
    conical_gradient_mask_graphics->SetBrush(conical_gradient_mask_graphics->CreateBrush(wxBrush(wxColour(255, 255, 255))));
    conical_gradient_mask_graphics->FillPath(*reinterpret_cast<wxGraphicsPath*>(graphics_path));
    conical_gradient_image.SetMaskFromImage(conical_gradient_bitmap_mask.ConvertToImage(), 0, 0, 0);
    conical_gradient_bitmap = conical_gradient_image;
    graphics.DrawBitmap(conical_gradient_bitmap, 0, 0, x + width, y + height);
  } else {
    graphics.SetPen(wxNullPen);
    graphics.SetBrush(wx_brush::to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.FillPath(*reinterpret_cast<wxGraphicsPath*>(graphics_path), mode == PFM_ALTERNATE ? wxODDEVEN_RULE : wxWINDING_RULE);
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_pie(intptr handle, intptr brush, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  if (!handle) throw_helper::throws(exception_case::argument);
  
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush()) {
    auto& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
    wxBitmap bitmap = render_brush_to_bitmap_with_mask(wxSize(width, height), reinterpret_cast<wx_brush*>(brush), [&](wxMemoryDC & mask_dc) {mask_dc.DrawEllipticArc(0, 0, width, height, 360 - start_angle - sweep_angle, 360 - start_angle);});
    dc.DrawBitmap(bitmap, x, y, true);
  } else {
    auto& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
    wxGraphicsPath path = graphics.CreatePath();
    
    path.MoveToPoint(0, 0);
    path.AddArc(0, 0, 1.0, wxDegToRad(start_angle), wxDegToRad(start_angle + sweep_angle), true);
    path.CloseSubpath();
    
    wxGraphicsMatrix m = graphics.CreateMatrix();
    m.Translate(x + width / 2.0, y + height / 2.0);
    m.Scale(width / 2.0, height / 2.0);
    path.Transform(m);
    
    graphics.SetPen(*wxTRANSPARENT_PEN);
    graphics.SetBrush(wx_brush::to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.FillPath(path);
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_polygon(intptr handle, intptr brush, const array<key_value_pair<float, float>>& points, int32 fill_mode) {
  if (!handle) throw_helper::throws(exception_case::argument);
  
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush()) {
    float min_x = std::numeric_limits<float>::max();
    float min_y = std::numeric_limits<float>::max();
    float max_x = std::numeric_limits<float>::lowest();
    float max_y = std::numeric_limits<float>::lowest();
    for (auto [x, y] : points) {
      min_x = std::min(min_x, x);
      min_y = std::min(min_y, y);
      max_x = std::max(max_x, x);
      max_y = std::max(max_y, y);
    }
    auto width  = static_cast<int>(max_x - min_x);
    auto height = static_cast<int>(max_y - min_y);
    
    auto& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
    
    auto bitmap = render_brush_to_bitmap_with_mask(wxSize(width, height), reinterpret_cast<wx_brush*>(brush), [&](wxMemoryDC & mask_dc) {
      auto wx_points = std::vector<wxPoint> {};
      wx_points.reserve(points.size());
      for (auto [x, y] : points)
        wx_points.emplace_back(static_cast<int>(x - min_x), static_cast<int>(y - min_y));
      mask_dc.DrawPolygon(static_cast<int>(wx_points.size()), wx_points.data());
    });
    dc.DrawBitmap(bitmap, static_cast<int>(min_x), static_cast<int>(min_y), true);
  } else {
    std::vector<wxPoint2DDouble> wx_points;
    for (auto [x, y] : points)
      wx_points.push_back(wxPoint(as<double>(x), as<double>(y)));
    wx_points.push_back(wx_points[0]);
    wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
    graphics.SetBrush(wx_brush::to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.SetPen(wxNullPen);
    graphics.DrawLines(wx_points.size(), wx_points.data());
  }
  
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_rectangle(intptr handle, intptr brush, float x, float y, float width, float height) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush())
    graphics.DrawBitmap(wxConicalGradient::CreateBitmap(wxSize(width, height), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().colors, reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().center_point - wxPoint(x, y), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().angle), x, y, width, height);
  else {
    graphics.SetPen(wxNullPen);
    graphics.SetBrush(wx_brush::to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.DrawRectangle(static_cast<double>(x), static_cast<double>(y), static_cast<double>(width), static_cast<double>(height));
  }
  
  // Workaround : with wxWidgets version <= 3.1.5 Radial gradient does not fill rectangle with end color on Windows.
  #if defined(__WXMSW__)
  if (reinterpret_cast<wx_brush*>(brush)->is_radial_gradiant_brush()) {
    auto wx_radial_brush = reinterpret_cast<wx_brush*>(brush)->get_radial_gradiant_brush();
    wxImage image(width, height);
    image.InitAlpha();
    for (int32 y_ia = 0; y_ia < height; y_ia++)
      for (int32 x_ia = 0; x_ia < width; x_ia++)
        image.SetAlpha(x_ia, y_ia, 0);
    wxBitmap radial_gradient_bitmap(image);
    auto radial_gradient_graphics = wxGraphicsContext::Create(wxMemoryDC(radial_gradient_bitmap));
    radial_gradient_graphics->SetPen(wxNullPen);
    radial_gradient_graphics->SetBrush(wxBrush(reinterpret_cast<wx_brush*>(brush)->get_radial_gradiant_brush().colors.Item(reinterpret_cast<wx_brush*>(brush)->get_radial_gradiant_brush().colors.GetCount() - 1).GetColour()));
    radial_gradient_graphics->DrawRectangle(0, 0, static_cast<double>(width), static_cast<double>(height));
    wxImage radial_gradient_image = radial_gradient_bitmap.ConvertToImage();
    wxBitmap radial_gradient_bitmap_mask(width, height);
    auto radial_gradient_mask_graphics = wxGraphicsContext::Create(wxMemoryDC(radial_gradient_bitmap_mask));
    radial_gradient_mask_graphics->SetPen(wxNullPen);
    radial_gradient_mask_graphics->SetBrush(radial_gradient_mask_graphics->CreateBrush(wxBrush(wxColour(255, 255, 255))));
    radial_gradient_mask_graphics->DrawRectangle(0, 0, width, height);
    radial_gradient_mask_graphics->SetBrush(radial_gradient_mask_graphics->CreateRadialGradientBrush(wx_radial_brush.focal_point.x - x, wx_radial_brush.focal_point.y - y, wx_radial_brush.center_point.x - x, wx_radial_brush.center_point.y - y, wx_radial_brush.radius, wxColour(0, 0, 0), wxColour(0, 0, 0)));
    radial_gradient_mask_graphics->DrawRectangle(0, 0, static_cast<double>(width), static_cast<double>(height));
    radial_gradient_image.SetMaskFromImage(radial_gradient_bitmap_mask.ConvertToImage(), 0, 0, 0);
    
    radial_gradient_bitmap = radial_gradient_image;
    graphics.DrawBitmap(radial_gradient_bitmap, x, y, width, height);
  }
  #endif
  
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_rectangles(intptr handle, intptr brush, const array<std::tuple<float, float, float, float>>& rects) {
  if (!handle) throw_helper::throws(exception_case::argument);
  for (auto [x, y, width, height] : rects)
    fill_rectangle(handle, brush, x, y, width, height);
}

void graphics::fill_region(intptr handle, intptr brush, intptr region) {
  if (!handle) throw_helper::throws(exception_case::argument);
  int32 x, y, width, height;
  wxRegion* wx_region = reinterpret_cast<wxRegion*>(region);
  wx_region->GetBox(x, y, width, height);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.Clip(*wx_region);
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush())
    graphics.DrawBitmap(wxConicalGradient::CreateBitmap(wxSize(width, height), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().colors, reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().center_point - wxPoint(x, y), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().angle), x, y, width, height);
  else {
    graphics.SetPen(wxNullPen);
    graphics.SetBrush(wx_brush::to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.DrawRectangle(static_cast<double>(x), static_cast<double>(y), static_cast<double>(width), static_cast<double>(height));
  }
  graphics.ResetClip();
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_rounded_rectangle(intptr handle, intptr brush, float x, float y, float width, float height, float radius) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush()) {
    wxBitmap conical_gradient_bitmap = wxConicalGradient::CreateBitmap(wxSize(width, height), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().colors, reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().center_point - wxPoint(x, y), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().angle);
    wxImage conical_gradient_image = conical_gradient_bitmap.ConvertToImage();
    wxBitmap conical_gradient_bitmap_mask(width, height);
    auto conical_gradient_mask_graphics = wxGraphicsContext::Create(wxMemoryDC(conical_gradient_bitmap_mask));
    conical_gradient_mask_graphics->SetBrush(conical_gradient_mask_graphics->CreateBrush(wxBrush(wxColour(255, 255, 255))));
    conical_gradient_mask_graphics->DrawRoundedRectangle(0, 0, width, height, radius);
    conical_gradient_image.SetMaskFromImage(conical_gradient_bitmap_mask.ConvertToImage(), 0, 0, 0);
    conical_gradient_bitmap = conical_gradient_image;
    graphics.DrawBitmap(conical_gradient_bitmap, x, y, width, height);
  } else {
    graphics.SetPen(wxNullPen);
    graphics.SetBrush(wx_brush::to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.DrawRoundedRectangle(static_cast<double>(x), static_cast<double>(y), static_cast<double>(width), static_cast<double>(height), static_cast<double>(radius));
  }
  
  // Workaround : with wxWidgets version <= 3.1.5 Radial gradient does not fill rounded rectangle with end color on Windows.
  #if defined(__WXMSW__)
  if (reinterpret_cast<wx_brush*>(brush)->is_radial_gradiant_brush()) {
    auto wx_radial_brush = reinterpret_cast<wx_brush*>(brush)->get_radial_gradiant_brush();
    wxImage image(width, height);
    image.InitAlpha();
    for (int32 y_ia = 0; y_ia < height; y_ia++)
      for (int32 x_ia = 0; x_ia < width; x_ia++)
        image.SetAlpha(x_ia, y_ia, 0);
    wxBitmap radial_gradient_bitmap(image);
    auto radial_gradient_graphics = wxGraphicsContext::Create(wxMemoryDC(radial_gradient_bitmap));
    radial_gradient_graphics->SetPen(wxNullPen);
    radial_gradient_graphics->SetBrush(wxBrush(reinterpret_cast<wx_brush*>(brush)->get_radial_gradiant_brush().colors.Item(reinterpret_cast<wx_brush*>(brush)->get_radial_gradiant_brush().colors.GetCount() - 1).GetColour()));
    radial_gradient_graphics->DrawRoundedRectangle(0, 0, static_cast<double>(width), static_cast<double>(height), static_cast<double>(radius));
    wxImage radial_gradient_image = radial_gradient_bitmap.ConvertToImage();
    wxBitmap radial_gradient_bitmap_mask(width, height);
    auto radial_gradient_mask_graphics = wxGraphicsContext::Create(wxMemoryDC(radial_gradient_bitmap_mask));
    radial_gradient_mask_graphics->SetPen(wxNullPen);
    radial_gradient_mask_graphics->SetBrush(radial_gradient_mask_graphics->CreateBrush(wxBrush(wxColour(255, 255, 255))));
    radial_gradient_mask_graphics->DrawRoundedRectangle(0, 0, width, height, radius);
    radial_gradient_mask_graphics->SetBrush(radial_gradient_mask_graphics->CreateRadialGradientBrush(wx_radial_brush.focal_point.x - x, wx_radial_brush.focal_point.y - y, wx_radial_brush.center_point.x - x, wx_radial_brush.center_point.y - y, wx_radial_brush.radius, wxColour(0, 0, 0), wxColour(0, 0, 0)));
    radial_gradient_mask_graphics->DrawRoundedRectangle(0, 0, static_cast<double>(width), static_cast<double>(height), static_cast<double>(radius));
    radial_gradient_image.SetMaskFromImage(radial_gradient_bitmap_mask.ConvertToImage(), 0, 0, 0);
    radial_gradient_bitmap = radial_gradient_image;
    graphics.DrawBitmap(radial_gradient_bitmap, x, y, width, height);
  }
  #endif
  
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::flush(intptr handle, int32 intention) {
  if (!handle) throw_helper::throws(exception_case::argument);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->Flush();
}

intptr graphics::from_hdc(intptr hdc) {
  return 0;
}

intptr graphics::from_hdc(intptr hdc, intptr hdevice) {
  return 0;
}

intptr graphics::from_hwnd(intptr hwnd) {
  /// @todo Use this method instead hdc_wrapper::create...
  return 0;
}

intptr graphics::from_image(intptr image) {
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper;
  if (image == 0) hdc_wrapper->create<wxScreenDC>();
  else hdc_wrapper->create_memory_hdc(image);
  return reinterpret_cast<intptr>(hdc_wrapper);
}

float graphics::get_dpi_x(intptr handle) {
  if (!handle) return 0.0f;
  double dpi_x = 0.0, dpi_y = 0.0;
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->GetDPI(&dpi_x, &dpi_y);
  return static_cast<float>(dpi_x);
}

float graphics::get_dpi_y(intptr handle) {
  if (!handle) return 0.0f;
  double dpi_x = 0.0, dpi_y = 0.0;
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->GetDPI(&dpi_x, &dpi_y);
  return static_cast<float>(dpi_y);
}

intptr graphics::get_hdc(intptr handle) {
  if (!handle) return 0;
  return reinterpret_cast<intptr>(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc().GetHandle());
}

void graphics::get_nearest_color(intptr handle, xtd::byte original_a, xtd::byte original_r, xtd::byte original_g, xtd::byte original_b, xtd::byte& nearest_a, xtd::byte& nearest_r, xtd::byte& nearest_g, xtd::byte& nearest_b) {
  // Not defined in wxWidgets
  nearest_a = original_a;
  nearest_r = original_r;
  nearest_g = original_g;
  nearest_b = original_b;
}

void graphics::interpolation_mode(intptr handle, int32 interpolation_mode) {
  if (!handle) throw_helper::throws(exception_case::argument);
  auto graphics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  switch (interpolation_mode) {
    case IM_INVALID: break;
    case IM_DEFAULT: graphics->SetInterpolationQuality(wxInterpolationQuality::wxINTERPOLATION_DEFAULT); break;
    case IM_LOW: graphics->SetInterpolationQuality(wxInterpolationQuality::wxINTERPOLATION_FAST); break;
    case IM_HIGHT: graphics->SetInterpolationQuality(wxInterpolationQuality::wxINTERPOLATION_GOOD); break;
    case IM_BICUBIC: graphics->SetInterpolationQuality(wxInterpolationQuality::wxINTERPOLATION_GOOD); break;
    case IM_NEAREST_NEIGHBOOR: graphics->SetInterpolationQuality(wxInterpolationQuality::wxINTERPOLATION_GOOD); break;
    case IM_HIGH_QUALITY_BILINEAR: graphics->SetInterpolationQuality(wxInterpolationQuality::wxINTERPOLATION_BEST); break;
    case IM_HIGH_QUALITY_BICUBIC: graphics->SetInterpolationQuality(wxInterpolationQuality::wxINTERPOLATION_BEST); break;
    default: graphics->SetInterpolationQuality(wxInterpolationQuality::wxINTERPOLATION_DEFAULT); break;
  }
}

/*
void graphics::measure_string(intptr handle, const string& text, intptr font, float& width, float& height, float max_width, float max_height, int32 alignment, int32 line_alignment, int32 hot_key_prefix, int32 trimming, size_t characters_fitted, size_t lines_filled, bool measure_trailing_spaces) {
  if (!handle) throw_helper::throws(exception_case::argument);
  width = 0;
  height = 0;
  size_t line_index = 0_z;
  auto strings = text.split({ '\n' });
  for (auto string : strings) {
    wxString text_to_draw = wxDrawString::FormatString(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc(), convert_string::to_wstring(string), max_width, hot_key_prefix, trimming);
    if (++line_index > lines_filled) break;
    double line_width = 0, line_height = 0;
    reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc().SetFont(*reinterpret_cast<wxFont*>(font));
    wxSize line_size = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc().GetTextExtent(measure_trailing_spaces ? text_to_draw : text_to_draw.Trim());
    line_width = line_size.GetWidth();
    line_height = line_size.GetHeight();
    width = std::max(width, static_cast<float>(line_width));
    height += static_cast<float>(line_height);

    // Workaround : with wxWidgets version <= 3.1.5 width size text is too small on macOS and linux.
    #if !defined(__WXMSW__)
    if (reinterpret_cast<wxFont*>(font)->GetStyle() > wxFontStyle::wxFONTSTYLE_NORMAL) width += std::ceil(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc().GetFontMetrics().averageWidth / 2.3f);
    #endif
  }
}
*/

void graphics::measure_string(intptr handle, const string& text, intptr font, float& width, float& height, float max_width, float max_height, int32 alignment, int32 line_alignment, int32 hot_key_prefix, int32 trimming, size_t characters_fitted, size_t lines_filled, bool measure_trailing_spaces) {
  if (!handle) throw_helper::throws(exception_case::argument);
  width = 0.0f;
  height = 0.0f;
  size_t line_index = 0_z;
  auto strings = text.split('\n');
  wxString formated_text;
  for (auto string : strings) {
    wxString line_string = wxDrawString::FormatString(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc(), convert_string::to_wstring(string).chars().c_str(), max_width, hot_key_prefix, trimming);
    if (++line_index > lines_filled) break;
    formated_text += line_string + wxString("\n");
  }
  if (formated_text.size()) formated_text.Remove(formated_text.size() - 1);
  wxDrawString::MeasureString(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc(), formated_text, *reinterpret_cast<wxFont*>(font), width, height, measure_trailing_spaces);
}

void graphics::pixel_offset_mode(intptr handle, int32 pixel_offset_mode) {
  if (!handle) throw_helper::throws(exception_case::argument);
  auto graphics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  switch (pixel_offset_mode) {
    case PO_INVALID: break;
    case PO_DEFAULT: graphics->DisableOffset(); break;
    case PO_HIGH_SPEED: graphics->DisableOffset(); break;
    case PO_HIGHT_QUALITY: graphics->EnableOffset(); break;
    case PO_NONE: graphics->DisableOffset(); break;
    case PO_HALF: graphics->ShouldOffset(); break;
    default: graphics->DisableOffset(); break;
  }
}

void graphics::release_hdc(intptr handle, intptr hdc) {
  // Not defined in wxWidgets
}

void graphics::reset_transform(intptr handle) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetTransform(graphics.CreateMatrix());
}

void graphics::restore(intptr handle, intptr& gstate) {
  if (!handle) throw_helper::throws(exception_case::argument);
  if (gstate == 0 || gstate != graphics_state[handle]) throw_helper::throws(exception_case::argument);
  --graphics_state[handle];
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->PopState();
  gstate = 0;
}

void graphics::rotate_transform(intptr handle, float angle, int32 order) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.Rotate(math::degrees_to_radians(-angle));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

intptr graphics::save(intptr handle) {
  if (!handle) return 0;
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->PushState();
  return as<intptr>(++graphics_state[handle]);
}

void graphics::scale_transform(intptr handle, float sx, float sy, int32 order) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.Scale(sx, sy);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::smoothing_mode(intptr handle, int32 smoothing_mode) {
  if (!handle) throw_helper::throws(exception_case::argument);
  auto graphics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  switch (smoothing_mode) {
    case SM_INVALID: break;
    case SM_DEFAULT: graphics->SetAntialiasMode(wxAntialiasMode::wxANTIALIAS_NONE); break;
    case SM_HIGH_SPEED: graphics->SetAntialiasMode(wxAntialiasMode::wxANTIALIAS_NONE); break;
    case SM_HIGHT_QUALITY: graphics->SetAntialiasMode(wxAntialiasMode::wxANTIALIAS_DEFAULT); break;
    case SM_NONE: graphics->SetAntialiasMode(wxAntialiasMode::wxANTIALIAS_NONE); break;
    case SM_ANTI_ALIAS: graphics->SetAntialiasMode(wxAntialiasMode::wxANTIALIAS_DEFAULT); break;
    default: graphics->SetAntialiasMode(wxAntialiasMode::wxANTIALIAS_NONE); break;
  }
}

void graphics::text_contrast(intptr handle, int32 text_contrast) {
  if (!handle) throw_helper::throws(exception_case::argument);
  // Not defined in wxWidgets
}

void graphics::text_rendering_hint(intptr handle, int32 text_rendering_hint) {
  if (!handle) throw_helper::throws(exception_case::argument);
  // Not defined in wxWidgets
}

intptr graphics::transform(intptr handle) {
  return reinterpret_cast<intptr>(new wxGraphicsMatrix(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->GetTransform()));
}

void graphics::transform(intptr handle, intptr matrix) {
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->SetTransform(*reinterpret_cast<wxGraphicsMatrix*>(matrix));
}

void graphics::translate_transform(intptr handle, float dx, float dy, int32 order) {
  if (!handle) throw_helper::throws(exception_case::argument);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.Translate(dx, dy);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

xtd::string graphics::trim_string(intptr handle, const xtd::string& text, intptr font, float width, int32 trimming) {
  return convert_string::to_string(wxDrawString::TrimString(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc(), convert_string::to_wstring(text).chars().c_str(), *reinterpret_cast<wxFont*>(font), width, trimming).c_str().AsWChar());
}

void graphics::visible_clip_bounds(intptr handle, float& x, float& y, float& width, float& height) {
  double wx_x = 0.0, wx_y = 0.0, wx_width = 0.0, wx_height = 0.0;
  if (handle) reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->GetClipBox(&wx_x, &wx_y, &wx_width, &wx_height);
  x = as<float>(wx_x);
  y = as<float>(wx_y);
  width = as<float>(wx_width);
  height = as<float>(wx_height);
}
