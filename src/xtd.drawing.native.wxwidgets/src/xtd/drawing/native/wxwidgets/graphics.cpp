#include <cmath>
#include <vector>
#include <xtd/argument_exception.h>
#include <xtd/convert_string.h>
#include <xtd/ustring.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/graphics.h>
#include "../../../../../include/xtd/drawing/native/hdc_wrapper.h"
#include "../../../../../include/xtd/drawing/native/wx_brush.h"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/app.h>
#include <wx/dcgraph.h>
#include <wx/dcmemory.h>

using namespace xtd;
using namespace xtd::drawing::native;

namespace {
  class graphics_context {
  public:
    graphics_context(intptr_t hdc) : hdc_(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()) {
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

  wxBrush to_brush(const wx_brush& brush) {
    if (brush.is_solid_brush()) return wxBrush(brush.get_solid_brush().color);
    if (brush.is_texture_brush()) return wxBrush(brush.get_texture_brush().texture);
    throw xtd::argument_exception("brush not defined"_t, current_stack_frame_);
  }

  wxGraphicsBrush to_graphics_brush(wxGraphicsContext& graphics, const wx_brush& brush) {
    if (brush.is_solid_brush()) return graphics.CreateBrush(wxBrush(brush.get_solid_brush().color));
    if (brush.is_linear_gradiant_brush()) {
      auto point1 = brush.get_linear_gradiant_brush().point1;
      auto point2 = brush.get_linear_gradiant_brush().point2;
      auto color1 = brush.get_linear_gradiant_brush().color1;
      auto color2 = brush.get_linear_gradiant_brush().color2;
      wxGraphicsBrush b = graphics.CreateLinearGradientBrush(static_cast<double>(point1.x), static_cast<double>(point1.y), static_cast<double>(point2.x), static_cast<double>(point2.y), color1, color2);;
      return b;
    }
    if (brush.is_texture_brush()) return graphics.CreateBrush(wxBrush(brush.get_texture_brush().texture));
    throw xtd::argument_exception("brush not defined"_t, current_stack_frame_);
  }
}


void graphics::clear(intptr_t hdc, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (hdc == 0) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  auto path = graphics.CreatePath();
  double width = 0.0, height = 0.0;
  graphics.GetSize(&width, &height);
  path.AddRectangle(0, 0, width, height);
  graphics.SetBrush(wxBrush({r, g, b, a}));
  graphics.FillPath(path);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::destroy(intptr_t hdc) {
  if (!hdc) return;
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc);
  delete hdc_wrapper;
}

void graphics::draw_arc(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  if (!hdc) return;
  graphics_context gc(hdc);
  wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc();
  dc.SetBrush(*wxTRANSPARENT_BRUSH);
  dc.SetPen(*reinterpret_cast<wxPen*>(pen));
  dc.DrawEllipticArc(x, y, width, height, start_angle, start_angle + sweep_angle);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_bezier(intptr_t hdc, intptr_t pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t x4, int32_t y4) {
  if (!hdc) return;
  graphics_context gc(hdc);
  wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc();
  dc.SetBrush(*wxTRANSPARENT_BRUSH);
  dc.SetPen(*reinterpret_cast<wxPen*>(pen));
  std::vector<wxPoint> points {wxPoint(x1, y1), wxPoint(x2, y2), wxPoint(x3, y3), wxPoint(x4, y4)};
  dc.DrawSpline(4, points.data());
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_ellipse(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  auto path = graphics.CreatePath();
  path.AddEllipse(x, y, width, height);
  graphics.SetPen(*reinterpret_cast<wxPen*>(pen));
  graphics.DrawPath(path);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_image(intptr_t hdc, intptr_t image, int32_t x, int32_t y) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  wxBitmap bitmap = wxBitmap(*reinterpret_cast<wxImage*>(image));
  graphics.DrawBitmap(bitmap, x, y, bitmap.GetWidth(),bitmap.GetHeight());
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_image_disabled(intptr_t hdc, intptr_t image, int32_t x, int32_t y, float brightness) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  wxBitmap bitmap = wxBitmap(*reinterpret_cast<wxImage*>(image)).ConvertToDisabled(static_cast<uint8_t>(255 * brightness));
  graphics.DrawBitmap(bitmap, x, y, bitmap.GetWidth(),bitmap.GetHeight());
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_line(intptr_t hdc, intptr_t pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  auto path = graphics.CreatePath();
  path.MoveToPoint(x1, y1);
  path.AddLineToPoint(x2, y2);
  graphics.SetPen(*reinterpret_cast<wxPen*>(pen));
  graphics.DrawPath(path);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_rectangle(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  auto path = graphics.CreatePath();
  path.AddRectangle(x, y, width, height);
  graphics.SetPen(*reinterpret_cast<wxPen*>(pen));
  graphics.DrawPath(path);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_rounded_rectangle(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  auto path = graphics.CreatePath();
  path.AddRoundedRectangle(x, y, width, height, radius);
  graphics.SetPen(*reinterpret_cast<wxPen*>(pen));
  graphics.DrawPath(path);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_string(intptr_t hdc, const ustring& text, intptr_t font, int32_t x, int32_t y, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (!hdc) return;
  // Workaround : with wxWidgets version <= 3.1.4 wxGraphicsContext::DrawText doesn't work witth unicode on Windows.
  if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") {
    wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc();
    dc.SetFont(*reinterpret_cast<wxFont*>(font));
    dc.SetTextForeground({ r, g, b, a });
    dc.DrawText(wxString(convert_string::to_wstring(text)), x, y);
  } else {
    wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
    graphics.SetFont(*reinterpret_cast<wxFont*>(font), { r, g, b, a });
    graphics.DrawText(wxString(convert_string::to_wstring(text)), x, y);
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_string(intptr_t hdc, const ustring& text, intptr_t font, int32_t x, int32_t y, int32_t w, int32_t h, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (!hdc) return;
  // Workaround : with wxWidgets version <= 3.1.4 wxGraphicsContext::DrawText doesn't work witth unicode on Windows.
  if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") {
    wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc();
    dc.SetClippingRegion({ x, y }, { w, h });
    dc.SetFont(*reinterpret_cast<wxFont*>(font));
    dc.SetTextForeground({ r, g, b, a });
    dc.DrawText(wxString(convert_string::to_wstring(text)), x, y);
    dc.DestroyClippingRegion();
  } else {
    wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
    graphics.Clip(x, y, w, h);
    graphics.SetFont(*reinterpret_cast<wxFont*>(font), { r, g, b, a });
    graphics.DrawText(wxString(convert_string::to_wstring(text)), x, y);
    graphics.ResetClip();
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::fill_ellipse(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  auto path = graphics.CreatePath();
  path.AddEllipse(x, y, width, height);
  graphics.SetBrush(to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
  graphics.FillPath(path);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::fill_pie(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  if (!hdc) return;
  graphics_context gc(hdc);
  wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc();
  dc.SetBrush(to_brush(*reinterpret_cast<wx_brush*>(brush)));
  dc.SetPen(*wxTRANSPARENT_PEN);
  dc.DrawEllipticArc(x, y, width, height, start_angle, start_angle + sweep_angle);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::fill_rectangle(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  auto path = graphics.CreatePath();
  path.AddRectangle(x, y, width, height);
  graphics.SetBrush(to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
  graphics.FillPath(path);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::fill_rounded_rectangle(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  auto path = graphics.CreatePath();
  path.AddRoundedRectangle(x, y, width, height, radius);
  graphics.SetBrush(to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
  graphics.FillPath(path);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}


intptr_t graphics::from_image(intptr_t image) {
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper;
  if (image == 0) hdc_wrapper->create<wxScreenDC>();
  else hdc_wrapper->create_memory_hdc(new wxBitmap(*reinterpret_cast<wxImage*>(image)), reinterpret_cast<wxImage*>(image));
  return reinterpret_cast<intptr_t>(hdc_wrapper);
}

void graphics::measure_string(intptr_t hdc, const ustring &text, intptr_t font, int32_t &width, int32_t &height) {
  if (!hdc) return;
  width = 0;
  height = 0;
  auto strings = text.split({ '\n' });
  for (auto string : strings) {
    double line_width = 0, line_height = 0;
    // Workaround : with wxWidgets version <= 3.1.4 wxGraphicsContext::GetTextExtent doesn't work witth unicode on Windows.
    if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") {
      reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc().SetFont(*reinterpret_cast<wxFont*>(font));
      wxSize line_size = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc().GetTextExtent(wxString(convert_string::to_wstring(string)));
      line_width = line_size.GetWidth();
      line_height = line_size.GetHeight();
    } else {
      wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
      graphics.SetFont(*reinterpret_cast<wxFont*>(font), { 0, 0, 0 });
      graphics.GetTextExtent(wxString(convert_string::to_wstring(string)), &line_width, &line_height);
    }
    width = std::max(width, static_cast<int32_t>(line_width));
    height += static_cast<int32_t>(line_height);

    // Workaround : with wxWidgets version <= 3.1.4 width size text is too small on macOS and linux.
    if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() != "Windows" && reinterpret_cast<wxFont*>(font)->GetStyle() > wxFontStyle::wxFONTSTYLE_NORMAL) width += std::ceil(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc().GetFontMetrics().averageWidth / 2.3f);
  }
}

void graphics::rotate_transform(intptr_t hdc, float angle) {
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  graphics.Rotate(angle);
}

void graphics::translate_clip(intptr_t hdc, int32_t dx, int32_t dy) {
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  graphics.Translate(dx, dy);
}
