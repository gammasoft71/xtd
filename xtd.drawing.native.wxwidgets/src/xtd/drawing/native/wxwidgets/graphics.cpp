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
  wxBrush current_brush = reinterpret_cast<wxDC*>(hdc)->GetBrush();
  wxPen current_pen = reinterpret_cast<wxDC*>(hdc)->GetPen();
  reinterpret_cast<wxDC*>(hdc)->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<wxDC*>(hdc)->SetPen(*reinterpret_cast<wxPen*>(pen));
  reinterpret_cast<wxDC*>(hdc)->DrawEllipticArc(x, y, width, height, start_angle, start_angle + sweep_angle);
  reinterpret_cast<wxDC*>(hdc)->SetBrush(current_brush);
  reinterpret_cast<wxDC*>(hdc)->SetPen(current_pen);
}

void graphics::draw_bezier(intptr_t hdc, intptr_t pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t x4, int32_t y4) {
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
  wxBrush current_brush = reinterpret_cast<wxDC*>(hdc)->GetBrush();
  wxPen current_pen = reinterpret_cast<wxDC*>(hdc)->GetPen();
  reinterpret_cast<wxDC*>(hdc)->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<wxDC*>(hdc)->SetPen(*reinterpret_cast<wxPen*>(pen));
  reinterpret_cast<wxDC*>(hdc)->DrawLine(x1, y1, x2, y2);
  reinterpret_cast<wxDC*>(hdc)->SetBrush(current_brush);
  reinterpret_cast<wxDC*>(hdc)->SetPen(current_pen);
}

void graphics::draw_rectangle(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  wxBrush current_brush = reinterpret_cast<wxDC*>(hdc)->GetBrush();
  wxPen current_pen = reinterpret_cast<wxDC*>(hdc)->GetPen();
  reinterpret_cast<wxDC*>(hdc)->SetBrush(*wxTRANSPARENT_BRUSH);
  reinterpret_cast<wxDC*>(hdc)->SetPen(*reinterpret_cast<wxPen*>(pen));
  reinterpret_cast<wxDC*>(hdc)->DrawRectangle(x, y, width, height);
  reinterpret_cast<wxDC*>(hdc)->SetBrush(current_brush);
  reinterpret_cast<wxDC*>(hdc)->SetPen(current_pen);
}

void graphics::fill_ellipse(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  wxBrush current_brush = reinterpret_cast<wxDC*>(hdc)->GetBrush();
  wxPen current_pen = reinterpret_cast<wxDC*>(hdc)->GetPen();
  reinterpret_cast<wxDC*>(hdc)->SetBrush(*reinterpret_cast<wxBrush*>(brush));
  reinterpret_cast<wxDC*>(hdc)->SetPen(*wxTRANSPARENT_PEN);
  reinterpret_cast<wxDC*>(hdc)->DrawEllipse(x, y, width, height);
  reinterpret_cast<wxDC*>(hdc)->SetBrush(current_brush);
  reinterpret_cast<wxDC*>(hdc)->SetPen(current_pen);
}

void graphics::fill_pie(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  wxBrush current_brush = reinterpret_cast<wxDC*>(hdc)->GetBrush();
  wxPen current_pen = reinterpret_cast<wxDC*>(hdc)->GetPen();
  reinterpret_cast<wxDC*>(hdc)->SetBrush(*reinterpret_cast<wxBrush*>(brush));
  reinterpret_cast<wxDC*>(hdc)->SetPen(*wxTRANSPARENT_PEN);
  reinterpret_cast<wxDC*>(hdc)->DrawEllipticArc(x, y, width, height, start_angle, start_angle + sweep_angle);
  reinterpret_cast<wxDC*>(hdc)->SetBrush(current_brush);
  reinterpret_cast<wxDC*>(hdc)->SetPen(current_pen);
}

void graphics::fill_rectangle(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  wxBrush current_brush = reinterpret_cast<wxDC*>(hdc)->GetBrush();
  wxPen current_pen = reinterpret_cast<wxDC*>(hdc)->GetPen();
  reinterpret_cast<wxDC*>(hdc)->SetBrush(*reinterpret_cast<wxBrush*>(brush));
  reinterpret_cast<wxDC*>(hdc)->SetPen(*wxTRANSPARENT_PEN);
  reinterpret_cast<wxDC*>(hdc)->DrawRectangle(x, y, width, height);
  reinterpret_cast<wxDC*>(hdc)->SetBrush(current_brush);
  reinterpret_cast<wxDC*>(hdc)->SetPen(current_pen);
}
