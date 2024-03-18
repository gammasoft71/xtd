#define __XTD_DRAWING_NATIVE_LIBRARY__
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
#include "../../../../../include/xtd/drawing/native/hdc_wrapper.h"
#include "../../../../../include/xtd/drawing/native/wx_brush.h"
#include "../../../../../include/xtd/drawing/native/wx_pen.h"
#include "../../../../../include/xtd/drawing/native/wxConicalGradient.h"
#include "../../../../../include/xtd/drawing/native/wxDrawString.h"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/as>
#include <xtd/convert_string>
#include <xtd/math>
#include <xtd/ustring>
#include <wx/app.h>
#include <wx/dcgraph.h>
#include <wx/dcmemory.h>
#include <wx/dcscreen.h>
#include <wx/region.h>
#include <cmath>
#include <vector>

using namespace xtd;
using namespace xtd::drawing::native;

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
}

void graphics::copy_from_graphics(intptr handle, intptr handle_source, int32 source_x, int32 source_y, int32 destination_x, int32 destination_y, int32 block_region_width, int32 block_region_height, int32 copy_pixel_operation) {
  if (!handle) return;
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
  if (!handle) return;
  // Not defined in wxWidgets
}

void graphics::compositing_quality(intptr handle, int32 compositing_quality) {
  if (!handle) return;
  // Not defined in wxWidgets
}

void graphics::copy_from_screen(intptr handle, int32 source_x, int32 source_y, int32 destination_x, int32 destination_y, int32 block_region_width, int32 block_region_height, int32 copy_pixel_operation) {
  if (!handle) return;
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
}

void graphics::destroy(intptr handle) {
  if (!handle) return;
  graphics_state.erase(handle);
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle);
  delete hdc_wrapper;
}

void graphics::draw_arc(intptr handle, intptr pen, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  if (!handle) return;
  graphics_context gc(handle);
  wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
  dc.SetBrush(*wxTRANSPARENT_BRUSH);
  dc.SetPen(wx_pen::to_pen(*reinterpret_cast<wx_pen*>(pen)));
  dc.DrawEllipticArc(x, y, width, height, 360 - start_angle - sweep_angle, 360 - start_angle);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_bezier(intptr handle, intptr pen, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
  if (!handle) return;
  auto path = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->CreatePath();
  path.MoveToPoint(x1, y1);
  path.AddCurveToPoint(x2, y2, x3, y3, x4, y4);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawPath(path);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_beziers(intptr handle, intptr pen, const std::vector<std::pair<float, float>>& points) {
  if (!handle) return;
  auto path = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->CreatePath();
  path.MoveToPoint(points[0].first, points[0].second);
  for (auto index  = 1_z; index < points.size(); index += 3) {
    path.AddCurveToPoint(points[index].first, points[index].second, points[index + 1].first, points[index + 1].second, points[index + 2].first, points[index + 2].second);
    path.MoveToPoint(points[index + 2].first, points[index + 2].second);
  }
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawPath(path);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_closed_curve(intptr handle, intptr pen, std::vector<std::pair<float, float>> points, float tension) {
  if (!handle) return;
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

void graphics::draw_curve(intptr handle, intptr pen, std::vector<std::pair<float, float>> points, float tension) {
  if (!handle) return;
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
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawEllipse(x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_image(intptr handle, intptr image, float x, float y, float width, float height) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  wxBitmap bitmap = wxBitmap(*reinterpret_cast<wxImage*>(image));
  graphics.DrawBitmap(bitmap, x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_image(intptr handle, intptr image, float dest_x, float dest_y, float dest_width, float dest_height, float src_x, float src_y, float src_width, float src_height) {
  if (!handle) return;
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
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  wxBitmap bitmap = wxBitmap(*reinterpret_cast<wxImage*>(image)).ConvertToDisabled(static_cast<xtd::byte>(255 * brightness));
  graphics.DrawBitmap(bitmap, x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_line(intptr handle, intptr pen, float x1, float y1, float x2, float y2) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.StrokeLine(x1, y1, x2, y2);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_lines(intptr handle, intptr pen, const std::vector<std::pair<float, float>>& points) {
  if (!handle) return;
  
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
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawPath(*reinterpret_cast<wxGraphicsPath*>(graphics_path));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_pie(intptr handle, intptr pen, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  if (!handle) return;
  graphics_context gc(handle);
  wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
  dc.SetBrush(*wxTRANSPARENT_BRUSH);
  dc.SetPen(wx_pen::to_pen(*reinterpret_cast<wx_pen*>(pen)));
  dc.DrawEllipticArc(x, y, width, height, 360 - start_angle - sweep_angle, 360 - start_angle);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_polygon(intptr handle, intptr pen, const std::vector<std::pair<float, float>>& points) {
  if (!handle) return;
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
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawRectangle(x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_rectangles(intptr handle, intptr pen, std::vector<std::tuple<float, float, float, float>>& rects) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  for (auto [x, y, width, height] : rects)
    graphics.DrawRectangle(x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_rotated_string(intptr handle, const xtd::ustring& text, intptr font, intptr brush, float x, float y, float angle) {
  wxDrawString::DrawString(handle, convert_string::to_wstring(text), *reinterpret_cast<wxFont*>(font), *reinterpret_cast<wx_brush*>(brush), x, y, angle, wxAlignment::wxALIGN_NOT, HKP_NONE, ST_NONE);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_rounded_rectangle(intptr handle, intptr pen, float x, float y, float width, float height, float radius) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wxNullBrush);
  graphics.SetPen(wx_pen::to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawRoundedRectangle(x, y, width, height, radius);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_string(intptr handle, const xtd::ustring& text, intptr font, intptr brush, float x, float y, int32 alignment, int32 line_alignment, int32 hot_key_prefix, int32 trimming) {
  wxDrawString::DrawString(handle, convert_string::to_wstring(text), *reinterpret_cast<wxFont*>(font), *reinterpret_cast<wx_brush*>(brush), x, y, 0.0f, to_wx_align(alignment, line_alignment), hot_key_prefix, trimming);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::draw_string(intptr handle, const xtd::ustring& text, intptr font, intptr brush, float x, float y, float width, float height, int32 alignment, int32 line_alignment, int32 hot_key_prefix, int32 trimming, int32 string_formats) {
  wxDrawString::DrawString(handle, convert_string::to_wstring(text), *reinterpret_cast<wxFont*>(font), *reinterpret_cast<wx_brush*>(brush), x, y, width, height, 0.0f, to_wx_align(alignment, line_alignment), hot_key_prefix, trimming, string_formats);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_closed_curve(intptr handle, intptr brush, std::vector<std::pair<float, float>> points, uint32 fill_mode, float tension) {
  /// @todo Using graphics_path when done...
  if (!handle) return;
  graphics_context gc(handle);
  wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
  dc.SetBrush(wx_brush::to_brush(*reinterpret_cast<wx_brush*>(brush)));
  dc.SetPen(*wxTRANSPARENT_PEN);
  std::vector<wxPoint> wx_points;
  for (auto [x, y] : points)
    wx_points.push_back(wxPoint(as<int32>(x), as<int32>(y)));
  dc.DrawSpline(as<int32>(wx_points.size()), wx_points.data());
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_ellipse(intptr handle, intptr brush, float x, float y, float width, float height) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush()) {
    wxBitmap conical_gradient_bitmap = wxConicalGradient::CreateBitmap(wxSize(width, height), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().colors, reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().center_point - wxPoint(x, y), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().angle);
    wxImage conical_gradient_image = conical_gradient_bitmap.ConvertToImage();
    wxBitmap conical_gradient_bitmap_mask(width, height);
    auto conical_gradient_mask_graphics = wxGraphicsContext::Create(wxMemoryDC(conical_gradient_bitmap_mask));
    conical_gradient_mask_graphics->SetBrush(conical_gradient_mask_graphics->CreateBrush(wxBrush(wxColour(255, 255, 255))));
    conical_gradient_mask_graphics->DrawEllipse(0, 0, width, height);
    conical_gradient_image.SetMaskFromImage(conical_gradient_bitmap_mask.ConvertToImage(), 0, 0, 0);
    conical_gradient_bitmap = conical_gradient_image;
    graphics.DrawBitmap(conical_gradient_bitmap, x, y, width, height);
  } else {
    graphics.SetPen(wxNullPen);
    graphics.SetBrush(wx_brush::to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.DrawEllipse(static_cast<double>(x), static_cast<double>(y), static_cast<double>(width), static_cast<double>(height));
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_path(intptr handle, intptr brush, intptr graphics_path, int32 mode) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush()) {
    double x, y, width, height;
    reinterpret_cast<wxGraphicsPath*>(graphics_path)->GetBox(&x, &y, &width, &height);
    wxBitmap conical_gradient_bitmap = wxConicalGradient::CreateBitmap(wxSize(width, height), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().colors, reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().center_point - wxPoint(x, y), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().angle);
    wxImage conical_gradient_image = conical_gradient_bitmap.ConvertToImage();
    wxBitmap conical_gradient_bitmap_mask(x + width, y + height);
    auto conical_gradient_mask_graphics = wxGraphicsContext::Create(wxMemoryDC(conical_gradient_bitmap_mask));
    conical_gradient_mask_graphics->SetBrush(conical_gradient_mask_graphics->CreateBrush(wxBrush(wxColour(255, 255, 255))));
    conical_gradient_mask_graphics->FillPath(*reinterpret_cast<wxGraphicsPath*>(graphics_path));
    conical_gradient_image.SetMaskFromImage(conical_gradient_bitmap_mask.ConvertToImage(), 0, 0, 0);
    conical_gradient_bitmap = conical_gradient_image;
    graphics.DrawBitmap(conical_gradient_bitmap, x, y, width, height);
  } else {
    graphics.SetPen(wxNullPen);
    graphics.SetBrush(wx_brush::to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.FillPath(*reinterpret_cast<wxGraphicsPath*>(graphics_path), mode == PFM_ALTERNATE ? wxODDEVEN_RULE : wxWINDING_RULE);
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_pie(intptr handle, intptr brush, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  if (!handle) return;
  graphics_context gc(handle);
  wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush()) {
    wxBitmap conical_gradient_bitmap = wxConicalGradient::CreateBitmap(wxSize(width, height), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().colors, reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().center_point - wxPoint(x, y), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().angle);
    wxImage conical_gradient_image = conical_gradient_bitmap.ConvertToImage();
    wxBitmap conical_gradient_bitmap_mask(width, height);
    auto conical_gradient_bitmap_mask_dc = wxMemoryDC(conical_gradient_bitmap_mask);
    conical_gradient_bitmap_mask_dc.SetBrush(wxBrush(wxColour(255, 255, 255)));
    conical_gradient_bitmap_mask_dc.DrawEllipticArc(0, y, width, height, 360 - start_angle - sweep_angle, 360 - start_angle);
    conical_gradient_image.SetMaskFromImage(conical_gradient_bitmap_mask.ConvertToImage(), 0, 0, 0);
    conical_gradient_bitmap = conical_gradient_image;
    dc.DrawBitmap(conical_gradient_bitmap, x, y);
  } else {
    dc.SetBrush(wx_brush::to_brush(*reinterpret_cast<wx_brush*>(brush)));
    dc.SetPen(*wxTRANSPARENT_PEN);
    dc.DrawEllipticArc(x, y, width, height, 360 - start_angle - sweep_angle, 360 - start_angle);
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_polygon(intptr handle, intptr brush, const std::vector<std::pair<float, float>>& points, int32 fill_mode) {
  if (!handle) return;
  /// @todo Using graphics_path when done...
  std::vector<wxPoint2DDouble> wx_points;
  for (auto [x, y] : points)
    wx_points.push_back(wxPoint(as<double>(x), as<double>(y)));
  wx_points.push_back(wx_points[0]);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetBrush(wx_brush::to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
  graphics.SetPen(wxNullPen);
  graphics.DrawLines(wx_points.size(), wx_points.data());
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::fill_rectangle(intptr handle, intptr brush, float x, float y, float width, float height) {
  if (!handle) return;
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

void graphics::fill_rectangles(intptr handle, intptr brush, std::vector<std::tuple<float, float, float, float>>& rects) {
  if (!handle) return;
  for (auto [x, y, width, height] : rects)
    fill_rectangle(handle, brush, x, y, width, height);
}

void graphics::fill_region(intptr handle, intptr brush, intptr region) {
  if (!handle) return;
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
  if (!handle) return;
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
  if (!handle) return;
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
  if (!handle) return;
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
void graphics::measure_string(intptr handle, const ustring& text, intptr font, float& width, float& height, float max_width, float max_height, int32 alignment, int32 line_alignment, int32 hot_key_prefix, int32 trimming, size_t characters_fitted, size_t lines_filled, bool measure_trailing_spaces) {
  if (!handle) return;
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

void graphics::measure_string(intptr handle, const ustring& text, intptr font, float& width, float& height, float max_width, float max_height, int32 alignment, int32 line_alignment, int32 hot_key_prefix, int32 trimming, size_t characters_fitted, size_t lines_filled, bool measure_trailing_spaces) {
  if (!handle) return;
  width = 0.0f;
  height = 0.0f;
  size_t line_index = 0_z;
  auto strings = text.split({'\n'});
  wxString formated_text;
  for (auto string : strings) {
    wxString line_string = wxDrawString::FormatString(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc(), convert_string::to_wstring(string), max_width, hot_key_prefix, trimming);
    if (++line_index > lines_filled) break;
    formated_text += line_string + wxString("\n");
  }
  if (formated_text.size()) formated_text.Remove(formated_text.size() - 1);
  wxDrawString::MeasureString(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc(), formated_text, *reinterpret_cast<wxFont*>(font), width, height, measure_trailing_spaces);
}

void graphics::pixel_offset_mode(intptr handle, int32 pixel_offset_mode) {
  if (!handle) return;
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
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.SetTransform(graphics.CreateMatrix());
}

void graphics::restore(intptr handle, intptr& gstate) {
  if (!handle) return;
  if (gstate == 0 || gstate != graphics_state[handle]) throw argument_exception {csf_};
  --graphics_state[handle];
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->PopState();
  gstate = 0;
}

void graphics::rotate_transform(intptr handle, float angle, int32 order) {
  if (!handle) return;
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
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.Scale(sx, sy);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

void graphics::smoothing_mode(intptr handle, int32 smoothing_mode) {
  if (!handle) return;
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
  if (!handle) return;
  // Not defined in wxWidgets
}

void graphics::text_rendering_hint(intptr handle, int32 text_rendering_hint) {
  if (!handle) return;
  // Not defined in wxWidgets
}

intptr graphics::transform(intptr handle) {
  return reinterpret_cast<intptr>(new wxGraphicsMatrix(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->GetTransform()));
}

void graphics::transform(intptr handle, intptr matrix) {
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->SetTransform(*reinterpret_cast<wxGraphicsMatrix*>(matrix));
}

void graphics::translate_transform(intptr handle, float dx, float dy, int32 order) {
  if (!handle) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
  graphics.Translate(dx, dy);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->apply_update();
}

xtd::ustring graphics::trim_string(intptr handle, const xtd::ustring& text, intptr font, float width, int32 trimming) {
  return convert_string::to_string(wxDrawString::TrimString(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc(), convert_string::to_wstring(text), *reinterpret_cast<wxFont*>(font), width, trimming).c_str().AsWChar());
}

void graphics::visible_clip_bounds(intptr handle, float& x, float& y, float& width, float& height) {
  double wx_x = 0.0, wx_y = 0.0, wx_width = 0.0, wx_height = 0.0;
  if (handle) reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics()->GetClipBox(&wx_x, &wx_y, &wx_width, &wx_height);
  x = as<float>(wx_x);
  y = as<float>(wx_y);
  width = as<float>(wx_width);
  height = as<float>(wx_height);
}
