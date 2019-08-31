#include <cmath>
#include <xtd/drawing/native/graphics.hpp>
#include "hdc_wrapper.hpp"
#include <wx/app.h>
#include <wx/dcgraph.h>

using namespace xtd::drawing::native;

void graphics::clear(intptr_t hdc, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (hdc == 0) return;
  wxBrush default_brush = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetBackground();
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBackground(wxBrush(wxColour(r, g, b, a)));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->Clear();
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBackground(default_brush);
}

void graphics::draw_arc(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  if (!hdc) return;
  wxBrush current_brush = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetBrush();
  wxPen current_pen = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetPen();
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(*reinterpret_cast<wxPen*>(pen));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawEllipticArc(x, y, width, height, start_angle, start_angle + sweep_angle);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(current_brush);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(current_pen);
}

void graphics::draw_bezier(intptr_t hdc, intptr_t pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t x4, int32_t y4) {
  if (!hdc) return;
  wxBrush current_brush = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetBrush();
  wxPen current_pen = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetPen();
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(*reinterpret_cast<wxPen*>(pen));
  wxPoint points[] = {wxPoint(x1, y1), wxPoint(x2, y2), wxPoint(x3, y3), wxPoint(x4, y4)};
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawSpline(4, points);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(current_brush);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(current_pen);
}

void graphics::draw_ellipse(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  wxBrush current_brush = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetBrush();
  wxPen default_pen = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetPen();
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(*reinterpret_cast<wxPen*>(pen));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawEllipse(x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(current_brush);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(default_pen);
}

void graphics::destroy(intptr_t hdc) {
  if (hdc == 0 || !wxTheApp->IsMainLoopRunning()) return;
  
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc);
  delete hdc_wrapper;
}

void graphics::draw_line(intptr_t hdc, intptr_t pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
  if (!hdc) return;
  wxBrush current_brush = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetBrush();
  wxPen current_pen = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetPen();
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(*reinterpret_cast<wxPen*>(pen));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawLine(x1, y1, x2, y2);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(current_brush);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(current_pen);
}

void graphics::draw_rectangle(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  wxBrush current_brush = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetBrush();
  wxPen current_pen = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetPen();
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(*reinterpret_cast<wxPen*>(pen));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawRectangle(x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(current_brush);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(current_pen);
}

void graphics::draw_string(intptr_t hdc, const std::string& text, intptr_t font, int32_t x, int32_t y, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (!hdc) return;
  wxFont current_font = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetFont();
  wxColour current_back_color = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetTextBackground();
  wxColour current_fore_color = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetTextForeground();
  
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetFont(*reinterpret_cast<wxFont*>(font));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetTextForeground(wxColour(r, g, b, a));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawText(text, x, y);
  
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetFont(current_font);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetTextForeground(current_back_color);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetTextForeground(current_fore_color);
}

void graphics::draw_string(intptr_t hdc, const std::string& text, intptr_t font, int32_t x, int32_t y, int32_t w, int32_t h, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (!hdc) return;
  wxFont current_font = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetFont();
  wxColour current_back_color = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetTextBackground();
  wxColour current_fore_color = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetTextForeground();
  
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetClippingRegion(x, y, w, h);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetFont(*reinterpret_cast<wxFont*>(font));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetTextForeground(wxColour(r, g, b, a));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawText(text, x, y);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DestroyClippingRegion();
  
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetFont(current_font);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetTextForeground(current_back_color);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetTextForeground(current_fore_color);
}

void graphics::fill_ellipse(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  wxBrush current_brush = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetBrush();
  wxPen current_pen = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetPen();
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(*reinterpret_cast<wxBrush*>(brush));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(*wxTRANSPARENT_PEN);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawEllipse(x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(current_brush);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(current_pen);
}

void graphics::fill_pie(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  if (!hdc) return;
  wxBrush current_brush = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetBrush();
  wxPen current_pen = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetPen();
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(*reinterpret_cast<wxBrush*>(brush));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(*wxTRANSPARENT_PEN);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawEllipticArc(x, y, width, height, start_angle, start_angle + sweep_angle);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(current_brush);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(current_pen);
}

void graphics::fill_rectangle(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  wxBrush current_brush = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetBrush();
  wxPen current_pen = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetPen();
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(*reinterpret_cast<wxBrush*>(brush));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(*wxTRANSPARENT_PEN);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->DrawRectangle(x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetBrush(current_brush);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetPen(current_pen);
}

void graphics::measure_string(intptr_t hdc, const std::string &text, intptr_t font, int32_t &width, int32_t &height) {
  if (!hdc) return;
  wxFont current_font = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetFont();
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetFont(*reinterpret_cast<wxFont*>(font));
  wxSize size = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetTextExtent(text);
  wxFontMetrics metrics = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->GetFontMetrics();
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()->SetFont(current_font);
  width = size.GetWidth();
  height = size.GetHeight();
#if defined(__WXOSX__)
  if (reinterpret_cast<wxFont*>(font)->GetStyle() > wxFontStyle::wxFONTSTYLE_NORMAL) width += std::ceil(metrics.averageWidth / 2.3f);
#endif
}

