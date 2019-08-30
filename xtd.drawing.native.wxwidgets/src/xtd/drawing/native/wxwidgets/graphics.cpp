#include <cmath>
#include <xtd/drawing/native/graphics.hpp>
#include <wx/app.h>
#include <wx/dc.h>
#include <wx/dcgraph.h>

using namespace xtd::drawing::native;

void graphics::clear(intptr_t hdc, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (hdc == 0) return;
  wxBrush default_brush = reinterpret_cast<wxDC*>(hdc)->GetBackground();
  reinterpret_cast<wxDC*>(hdc)->SetBackground(wxBrush(wxColour(r, g, b, a)));
  reinterpret_cast<wxDC*>(hdc)->Clear();
  reinterpret_cast<wxDC*>(hdc)->SetBackground(default_brush);
}

void graphics::draw_arc(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  if (!hdc) return;
  wxBrush current_brush = reinterpret_cast<wxDC*>(hdc)->GetBrush();
  wxPen current_pen = reinterpret_cast<wxDC*>(hdc)->GetPen();
  reinterpret_cast<wxDC*>(hdc)->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<wxDC*>(hdc)->SetPen(*reinterpret_cast<wxPen*>(pen));
  reinterpret_cast<wxDC*>(hdc)->DrawEllipticArc(x, y, width, height, start_angle, start_angle + sweep_angle);
  reinterpret_cast<wxDC*>(hdc)->SetBrush(current_brush);
  reinterpret_cast<wxDC*>(hdc)->SetPen(current_pen);
}

void graphics::draw_bezier(intptr_t hdc, intptr_t pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t x4, int32_t y4) {
  if (!hdc) return;
  wxBrush current_brush = reinterpret_cast<wxDC*>(hdc)->GetBrush();
  wxPen current_pen = reinterpret_cast<wxDC*>(hdc)->GetPen();
  reinterpret_cast<wxDC*>(hdc)->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<wxDC*>(hdc)->SetPen(*reinterpret_cast<wxPen*>(pen));
  wxPoint points[] = {wxPoint(x1, y1), wxPoint(x2, y2), wxPoint(x3, y3), wxPoint(x4, y4)};
  reinterpret_cast<wxDC*>(hdc)->DrawSpline(4, points);
  reinterpret_cast<wxDC*>(hdc)->SetBrush(current_brush);
  reinterpret_cast<wxDC*>(hdc)->SetPen(current_pen);
}

void graphics::draw_ellipse(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  wxBrush current_brush = reinterpret_cast<wxDC*>(hdc)->GetBrush();
  wxPen default_pen = reinterpret_cast<wxDC*>(hdc)->GetPen();
  reinterpret_cast<wxDC*>(hdc)->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<wxDC*>(hdc)->SetPen(*reinterpret_cast<wxPen*>(pen));
  reinterpret_cast<wxDC*>(hdc)->DrawEllipse(x, y, width, height);
  reinterpret_cast<wxDC*>(hdc)->SetBrush(current_brush);
  reinterpret_cast<wxDC*>(hdc)->SetPen(default_pen);
}

void graphics::destroy(intptr_t hdc) {
  if (hdc == 0 || !wxTheApp->IsMainLoopRunning()) return;
  delete reinterpret_cast<wxDC*>(hdc);
}

void graphics::draw_line(intptr_t hdc, intptr_t pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
  if (!hdc) return;
  wxBrush current_brush = reinterpret_cast<wxDC*>(hdc)->GetBrush();
  wxPen current_pen = reinterpret_cast<wxDC*>(hdc)->GetPen();
  reinterpret_cast<wxDC*>(hdc)->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<wxDC*>(hdc)->SetPen(*reinterpret_cast<wxPen*>(pen));
  reinterpret_cast<wxDC*>(hdc)->DrawLine(x1, y1, x2, y2);
  reinterpret_cast<wxDC*>(hdc)->SetBrush(current_brush);
  reinterpret_cast<wxDC*>(hdc)->SetPen(current_pen);
}

void graphics::draw_rectangle(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  wxBrush current_brush = reinterpret_cast<wxDC*>(hdc)->GetBrush();
  wxPen current_pen = reinterpret_cast<wxDC*>(hdc)->GetPen();
  reinterpret_cast<wxDC*>(hdc)->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<wxDC*>(hdc)->SetPen(*reinterpret_cast<wxPen*>(pen));
  reinterpret_cast<wxDC*>(hdc)->DrawRectangle(x, y, width, height);
  reinterpret_cast<wxDC*>(hdc)->SetBrush(current_brush);
  reinterpret_cast<wxDC*>(hdc)->SetPen(current_pen);
}

void graphics::draw_string(intptr_t hdc, const std::string& text, intptr_t font, int32_t x, int32_t y, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (!hdc) return;
  wxFont current_font = reinterpret_cast<wxDC*>(hdc)->GetFont();
  wxColour current_back_color = reinterpret_cast<wxDC*>(hdc)->GetTextBackground();
  wxColour current_fore_color = reinterpret_cast<wxDC*>(hdc)->GetTextForeground();
  
  reinterpret_cast<wxDC*>(hdc)->SetFont(*reinterpret_cast<wxFont*>(font));
  reinterpret_cast<wxDC*>(hdc)->SetTextForeground(wxColour(r, g, b, a));
  reinterpret_cast<wxDC*>(hdc)->DrawText(text, x, y);
  
  reinterpret_cast<wxDC*>(hdc)->SetFont(current_font);
  reinterpret_cast<wxDC*>(hdc)->SetTextForeground(current_back_color);
  reinterpret_cast<wxDC*>(hdc)->SetTextForeground(current_fore_color);
}

void graphics::draw_string(intptr_t hdc, const std::string& text, intptr_t font, int32_t x, int32_t y, int32_t w, int32_t h, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (!hdc) return;
  wxFont current_font = reinterpret_cast<wxDC*>(hdc)->GetFont();
  wxColour current_back_color = reinterpret_cast<wxDC*>(hdc)->GetTextBackground();
  wxColour current_fore_color = reinterpret_cast<wxDC*>(hdc)->GetTextForeground();
  
  reinterpret_cast<wxDC*>(hdc)->SetClippingRegion(x, y, w, h);
  reinterpret_cast<wxDC*>(hdc)->SetFont(*reinterpret_cast<wxFont*>(font));
  reinterpret_cast<wxDC*>(hdc)->SetTextForeground(wxColour(r, g, b, a));
  reinterpret_cast<wxDC*>(hdc)->DrawText(text, x, y);
  reinterpret_cast<wxDC*>(hdc)->DestroyClippingRegion();
  
  reinterpret_cast<wxDC*>(hdc)->SetFont(current_font);
  reinterpret_cast<wxDC*>(hdc)->SetTextForeground(current_back_color);
  reinterpret_cast<wxDC*>(hdc)->SetTextForeground(current_fore_color);
}

void graphics::fill_ellipse(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  wxBrush current_brush = reinterpret_cast<wxDC*>(hdc)->GetBrush();
  wxPen current_pen = reinterpret_cast<wxDC*>(hdc)->GetPen();
  reinterpret_cast<wxDC*>(hdc)->SetBrush(*reinterpret_cast<wxBrush*>(brush));
  reinterpret_cast<wxDC*>(hdc)->SetPen(*wxTRANSPARENT_PEN);
  reinterpret_cast<wxDC*>(hdc)->DrawEllipse(x, y, width, height);
  reinterpret_cast<wxDC*>(hdc)->SetBrush(current_brush);
  reinterpret_cast<wxDC*>(hdc)->SetPen(current_pen);
}

void graphics::fill_pie(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  if (!hdc) return;
  wxBrush current_brush = reinterpret_cast<wxDC*>(hdc)->GetBrush();
  wxPen current_pen = reinterpret_cast<wxDC*>(hdc)->GetPen();
  reinterpret_cast<wxDC*>(hdc)->SetBrush(*reinterpret_cast<wxBrush*>(brush));
  reinterpret_cast<wxDC*>(hdc)->SetPen(*wxTRANSPARENT_PEN);
  reinterpret_cast<wxDC*>(hdc)->DrawEllipticArc(x, y, width, height, start_angle, start_angle + sweep_angle);
  reinterpret_cast<wxDC*>(hdc)->SetBrush(current_brush);
  reinterpret_cast<wxDC*>(hdc)->SetPen(current_pen);
}

void graphics::fill_rectangle(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  wxBrush current_brush = reinterpret_cast<wxDC*>(hdc)->GetBrush();
  wxPen current_pen = reinterpret_cast<wxDC*>(hdc)->GetPen();
  reinterpret_cast<wxDC*>(hdc)->SetBrush(*reinterpret_cast<wxBrush*>(brush));
  reinterpret_cast<wxDC*>(hdc)->SetPen(*wxTRANSPARENT_PEN);
  reinterpret_cast<wxDC*>(hdc)->DrawRectangle(x, y, width, height);
  reinterpret_cast<wxDC*>(hdc)->SetBrush(current_brush);
  reinterpret_cast<wxDC*>(hdc)->SetPen(current_pen);
}

void graphics::measure_string(intptr_t hdc, const std::string &text, intptr_t font, int32_t &width, int32_t &height) {
  if (!hdc) return;
  wxFont current_font = reinterpret_cast<wxDC*>(hdc)->GetFont();
  reinterpret_cast<wxDC*>(hdc)->SetFont(*reinterpret_cast<wxFont*>(font));
  wxSize size = reinterpret_cast<wxDC*>(hdc)->GetTextExtent(text);
  wxFontMetrics metrics = reinterpret_cast<wxDC*>(hdc)->GetFontMetrics();
  reinterpret_cast<wxDC*>(hdc)->SetFont(current_font);
  width = size.GetWidth();
  height = size.GetHeight();
#if defined(__WXOSX__)
  if (reinterpret_cast<wxFont*>(font)->GetStyle() > wxFontStyle::wxFONTSTYLE_NORMAL) width += std::ceil(metrics.averageWidth / 2.3f);
#endif
}

