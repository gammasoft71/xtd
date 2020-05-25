#include <cmath>
#include <xtd/drawing/native/graphics.h>
#include "../../../../../include/xtd/drawing/native/hdc_wrapper.h"
#include <wx/app.h>
#include <wx/dcgraph.h>

using namespace xtd;
using namespace xtd::drawing::native;

namespace {
  class graphics_context {
  public:
    graphics_context(intptr_t hdc) : hdc_(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()) {
      brush_ = hdc_->GetBrush();
      pen_ = hdc_->GetPen();
      back_color_ = hdc_->GetTextBackground();
      fore_color_ = hdc_->GetTextForeground();
      font_ = hdc_->GetFont();
    }
    
    ~graphics_context() {
      hdc_->SetBrush(brush_);
      hdc_->SetPen(pen_);
      hdc_->SetTextBackground(back_color_);
      hdc_->SetTextForeground(fore_color_);
      hdc_->SetFont(font_);
    }
    
  private:
    wxDC* hdc_;
    wxBrush brush_;
    wxColour back_color_;
    wxColour fore_color_;
    wxPen pen_;
    wxFont font_;
  };
}


void graphics::clear(intptr_t hdc, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (hdc == 0) return;
  graphics_context gc(hdc);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBackground(wxBrush(wxColour(r, g, b, a)));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->Clear();
}

void graphics::draw_arc(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  if (!hdc) return;
  graphics_context gc(hdc);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(*reinterpret_cast<wxPen*>(pen));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawEllipticArc(x, y, width, height, start_angle, start_angle + sweep_angle);
}

void graphics::draw_bezier(intptr_t hdc, intptr_t pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t x4, int32_t y4) {
  if (!hdc) return;
  graphics_context gc(hdc);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(*reinterpret_cast<wxPen*>(pen));
  wxPoint points[] = {wxPoint(x1, y1), wxPoint(x2, y2), wxPoint(x3, y3), wxPoint(x4, y4)};
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawSpline(4, points);
}

void graphics::draw_ellipse(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  graphics_context gc(hdc);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(*reinterpret_cast<wxPen*>(pen));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawEllipse(x, y, width, height);
}

void graphics::destroy(intptr_t hdc) {
  if (!hdc) return;
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc);
  delete hdc_wrapper;
}

void graphics::draw_image(intptr_t hdc, intptr_t image, int32_t x, int32_t y) {
  if (!hdc) return;
  graphics_context gc(hdc);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawBitmap(wxBitmap(*reinterpret_cast<wxImage*>(image)), x, y, true);
}

void graphics::draw_line(intptr_t hdc, intptr_t pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
  if (!hdc) return;
  graphics_context gc(hdc);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(*reinterpret_cast<wxPen*>(pen));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawLine(x1, y1, x2, y2);
}

void graphics::draw_rectangle(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  graphics_context gc(hdc);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(*reinterpret_cast<wxPen*>(pen));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawRectangle(x, y, width, height);
}

void graphics::draw_string(intptr_t hdc, const std::string& text, intptr_t font, int32_t x, int32_t y, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (!hdc) return;
  graphics_context gc(hdc);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetFont(*reinterpret_cast<wxFont*>(font));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetTextForeground(wxColour(r, g, b, a));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawText({text.c_str(), wxMBConvUTF8()}, x, y);
}

void graphics::draw_string(intptr_t hdc, const std::string& text, intptr_t font, int32_t x, int32_t y, int32_t w, int32_t h, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (!hdc) return;
  graphics_context gc(hdc);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetClippingRegion(x, y, w, h);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetFont(*reinterpret_cast<wxFont*>(font));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetTextForeground(wxColour(r, g, b, a));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawText({text.c_str(), wxMBConvUTF8()}, x, y);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DestroyClippingRegion();
}

void graphics::fill_ellipse(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  graphics_context gc(hdc);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(*reinterpret_cast<wxBrush*>(brush));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(*wxTRANSPARENT_PEN);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawEllipse(x, y, width, height);
}

void graphics::fill_pie(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  if (!hdc) return;
  graphics_context gc(hdc);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(*reinterpret_cast<wxBrush*>(brush));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(*wxTRANSPARENT_PEN);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawEllipticArc(x, y, width, height, start_angle, start_angle + sweep_angle);
}

void graphics::fill_rectangle(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  graphics_context gc(hdc);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(*reinterpret_cast<wxBrush*>(brush));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(*wxTRANSPARENT_PEN);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawRectangle(x, y, width, height);
}

void graphics::measure_string(intptr_t hdc, const std::string &text, intptr_t font, int32_t &width, int32_t &height) {
  if (!hdc) return;
  graphics_context gc(hdc);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetFont(*reinterpret_cast<wxFont*>(font));
  wxSize size = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetMultiLineTextExtent({text.c_str(), wxMBConvUTF8()});
  wxFontMetrics metrics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetFontMetrics();
  width = size.GetWidth();
  height = size.GetHeight();
#if defined(__WXOSX__) || defined(__WXGTK__)
  if (reinterpret_cast<wxFont*>(font)->GetStyle() > wxFontStyle::wxFONTSTYLE_NORMAL) width += std::ceil(metrics.averageWidth / 2.3f);
#endif
}

