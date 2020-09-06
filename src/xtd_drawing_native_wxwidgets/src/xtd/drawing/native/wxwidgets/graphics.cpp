#include <cmath>
#include <vector>
#include <xtd/xtd.strings>
#include <xtd/drawing/native/graphics.h>
#include "../../../../../include/xtd/drawing/native/hdc_wrapper.h"
#include "../../../../../include/xtd/drawing/native/wx_brush.h"
#include <wx/app.h>
#include <wx/dcgraph.h>

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
    throw std::invalid_argument("brush not defined");
  }
}


void graphics::clear(intptr_t hdc, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (hdc == 0) return;
  wxGraphicsContext& graphics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  auto path = graphics.CreatePath();
  double width = 0.0, heigth = 0.0;
  graphics.GetSize(&width, &heigth);
  path.AddRectangle(0, 0, width, heigth);
  graphics.SetBrush(wxBrush({r, g, b, a}));
  graphics.FillPath(path);
}

void graphics::destroy(intptr_t hdc) {
  if (!hdc) return;
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc);
  delete hdc_wrapper;
}

void graphics::draw_arc(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  if (!hdc) return;
  graphics_context gc(hdc);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc().SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc().SetPen(*reinterpret_cast<wxPen*>(pen));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc().DrawEllipticArc(x, y, width, height, start_angle, start_angle + sweep_angle);
}

void graphics::draw_bezier(intptr_t hdc, intptr_t pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t x4, int32_t y4) {
  if (!hdc) return;
  graphics_context gc(hdc);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc().SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc().SetPen(*reinterpret_cast<wxPen*>(pen));
  std::vector<wxPoint> points {wxPoint(x1, y1), wxPoint(x2, y2), wxPoint(x3, y3), wxPoint(x4, y4)};
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc().DrawSpline(4, points.data());
}

void graphics::draw_ellipse(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  wxGraphicsContext& graphics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  auto path = graphics.CreatePath();
  path.AddEllipse(x, y, width, height);
  graphics.SetPen(*reinterpret_cast<wxPen*>(pen));
  graphics.DrawPath(path);
}

void graphics::draw_image(intptr_t hdc, intptr_t image, int32_t x, int32_t y) {
  if (!hdc) return;
  wxBitmap bitmap = wxBitmap(*reinterpret_cast<wxImage*>(image));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics().DrawBitmap(bitmap, x, y, bitmap.GetWidth(),bitmap.GetHeight());
}

void graphics::draw_image_disabled(intptr_t hdc, intptr_t image, int32_t x, int32_t y, float brightness) {
  if (!hdc) return;
  wxBitmap bitmap = wxBitmap(*reinterpret_cast<wxImage*>(image)).ConvertToDisabled(static_cast<uint8_t>(255 * brightness));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics().DrawBitmap(bitmap, x, y, bitmap.GetWidth(),bitmap.GetHeight());
}

void graphics::draw_line(intptr_t hdc, intptr_t pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
  if (!hdc) return;
  wxGraphicsContext& graphics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  auto path = graphics.CreatePath();
  path.MoveToPoint(x1, y1);
  path.AddLineToPoint(x2, y2);
  graphics.SetPen(*reinterpret_cast<wxPen*>(pen));
  graphics.DrawPath(path);
}

void graphics::draw_rectangle(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  wxGraphicsContext& graphics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  auto path = graphics.CreatePath();
  path.AddRectangle(x, y, width, height);
  graphics.SetPen(*reinterpret_cast<wxPen*>(pen));
  graphics.DrawPath(path);
}

void graphics::draw_rounded_rectangle(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius) {
  if (!hdc) return;
  wxGraphicsContext& graphics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  auto path = graphics.CreatePath();
  path.AddRoundedRectangle(x, y, width, height, radius);
  graphics.SetPen(*reinterpret_cast<wxPen*>(pen));
  graphics.DrawPath(path);
}

void graphics::draw_string(intptr_t hdc, const std::string& text, intptr_t font, int32_t x, int32_t y, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (!hdc) return;
  wxGraphicsContext& graphics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  graphics.SetFont(*reinterpret_cast<wxFont*>(font), {r, g, b, a});
  graphics.DrawText({text.c_str(), wxMBConvUTF8()}, x, y);
}

void graphics::draw_string(intptr_t hdc, const std::string& text, intptr_t font, int32_t x, int32_t y, int32_t w, int32_t h, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (!hdc) return;
  wxGraphicsContext& graphics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  graphics.Clip(x, y, w, h);
  graphics.SetFont(*reinterpret_cast<wxFont*>(font), {r, g, b, a});
  graphics.DrawText({text.c_str(), wxMBConvUTF8()}, x, y);
  graphics.ResetClip();
}

void graphics::fill_ellipse(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  wxGraphicsContext& graphics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  auto path = graphics.CreatePath();
  path.AddEllipse(x, y, width, height);
  graphics.SetBrush(to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
  graphics.FillPath(path);
}

void graphics::fill_pie(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  if (!hdc) return;
  graphics_context gc(hdc);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc().SetBrush(wxBrush(reinterpret_cast<wx_brush*>(brush)->get_solid_brush().color));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc().SetPen(*wxTRANSPARENT_PEN);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc().DrawEllipticArc(x, y, width, height, start_angle, start_angle + sweep_angle);
}

void graphics::fill_rectangle(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  wxGraphicsContext& graphics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  auto path = graphics.CreatePath();
  path.AddRectangle(x, y, width, height);
  graphics.SetBrush(to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
  graphics.FillPath(path);
}

void graphics::fill_rounded_rectangle(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius) {
  if (!hdc) return;
  wxGraphicsContext& graphics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  auto path = graphics.CreatePath();
  path.AddRoundedRectangle(x, y, width, height, radius);
  graphics.SetBrush(to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
  graphics.FillPath(path);
}

void graphics::measure_string(intptr_t hdc, const std::string &text, intptr_t font, int32_t &width, int32_t &height) {
  if (!hdc) return;
  wxGraphicsContext& graphics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  graphics.SetFont(*reinterpret_cast<wxFont*>(font), {0, 0, 0});
  width = 0;
  height = 0;
  auto strings = xtd::strings::split(text, {'\n'});
  for (auto string : strings) {
    double w, h;
    graphics.GetTextExtent({string.c_str(), wxMBConvUTF8()}, &w, &h);
    width = std::max(width, static_cast<int32_t>(w));
    height += h;
  }

  /*
  // Workaround : with wxWidgets version <= 3.1.4 hight size text is too small on macOS.
  if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh") height += 1;
  // Workaround : with wxWidgets version <= 3.1.4 width size text is too small on macOS and linux.
  if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() != "Windows" && reinterpret_cast<wxFont*>(font)->GetStyle() > wxFontStyle::wxFONTSTYLE_NORMAL) width += std::ceil(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc().GetFontMetrics().averageWidth / 2.3f);
   */
}

