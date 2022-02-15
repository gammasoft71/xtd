#include <cmath>
#include <vector>
#include <xtd/argument_exception.h>
#include <xtd/convert_string.h>
#include <xtd/ustring.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/graphics.h>
#include "../../../../../include/xtd/drawing/native/hdc_wrapper.h"
#include "../../../../../include/xtd/drawing/native/wx_brush.h"
#include "../../../../../include/xtd/drawing/native/wx_pen.h"
#include "../../../../../include/xtd/drawing/native/wxConicalGradient.h"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/app.h>
#include <wx/dcgraph.h>
#include <wx/dcmemory.h>
#include <wx/region.h>

using namespace xtd;
using namespace xtd::drawing::native;

namespace {
  class graphics_context {
  public:
    explicit graphics_context(intptr_t hdc) : hdc_(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc()) {
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
    if (brush.is_conical_gradiant_brush()) return graphics.CreateBrush(wxBrush(brush.get_conical_gradiant_brush().colors.Item(0).GetColour()));
    if (brush.is_linear_gradiant_brush()) return graphics.CreateLinearGradientBrush(static_cast<double>(brush.get_linear_gradiant_brush().point1.x), static_cast<double>(brush.get_linear_gradiant_brush().point1.y), static_cast<double>(brush.get_linear_gradiant_brush().point2.x), static_cast<double>(brush.get_linear_gradiant_brush().point2.y), brush.get_linear_gradiant_brush().colors);
    if (brush.is_radial_gradiant_brush()) return graphics.CreateRadialGradientBrush(static_cast<double>(brush.get_radial_gradiant_brush().focal_point.x), static_cast<double>(brush.get_radial_gradiant_brush().focal_point.y), static_cast<double>(brush.get_radial_gradiant_brush().center_point.x), static_cast<double>(brush.get_radial_gradiant_brush().center_point.y), static_cast<double>(brush.get_radial_gradiant_brush().radius), brush.get_radial_gradiant_brush().colors);
    if (brush.is_solid_brush()) return graphics.CreateBrush(wxBrush(brush.get_solid_brush().color));
    if (brush.is_texture_brush()) return graphics.CreateBrush(wxBrush(brush.get_texture_brush().texture));
    throw xtd::argument_exception("brush not defined"_t, current_stack_frame_);
  }
  
  wxPen to_pen(const wx_pen& pen) {
    if (pen.is_solid_color_pen()) {
      wxPen wxpen(pen.get_solid_color_pen().color, pen.get_solid_color_pen().width);
      wxpen.SetStyle(wxPenStyle::wxPENSTYLE_USER_DASH);
      wxpen.SetCap(wxPenCap::wxCAP_BUTT);
      wxpen.SetDashes(pen.get_solid_color_pen().dashes.size(), pen.get_solid_color_pen().dashes.data());
      return wxpen;
    }
    throw xtd::argument_exception("brush not defined"_t, current_stack_frame_);
  }
  
  wxGraphicsPen to_graphics_pen(wxGraphicsContext& graphics, const wx_pen& pen) {
    if (pen.is_solid_color_pen()) {
      wxGraphicsPenInfo pen_info;
      pen_info.Cap(wxPenCap::wxCAP_BUTT);
      pen_info.Colour(pen.get_solid_color_pen().color);
      pen_info.Style(wxPenStyle::wxPENSTYLE_USER_DASH);
      pen_info.Dashes(pen.get_solid_color_pen().dashes.size(), pen.get_solid_color_pen().dashes.data());
      pen_info.Width(pen.get_solid_color_pen().width);
      return graphics.CreatePen(pen_info);
    }
    if (pen.is_hatch_fill_pen()) {
      wxGraphicsPenInfo pen_info;
      pen_info.Cap(wxPenCap::wxCAP_BUTT);
      pen_info.Colour({0, 0, 0, 0});
      pen_info.Stipple(wxBitmap(pen.get_hatch_fill_pen().brush.get_texture_brush().texture));
      pen_info.Width(pen.get_hatch_fill_pen().width);
      return graphics.CreatePen(pen_info);
    }
    if (pen.is_linear_gradiant_pen()) {
      wxGraphicsPenInfo pen_info;
      pen_info.Cap(wxPenCap::wxCAP_BUTT);
      pen_info.Colour({0, 0, 0, 0});
      pen_info.LinearGradient(pen.get_linear_gradiant_pen().brush.get_linear_gradiant_brush().point1.x, pen.get_linear_gradiant_pen().brush.get_linear_gradiant_brush().point1.y, pen.get_linear_gradiant_pen().brush.get_linear_gradiant_brush().point2.x, pen.get_linear_gradiant_pen().brush.get_linear_gradiant_brush().point2.y, pen.get_linear_gradiant_pen().brush.get_linear_gradiant_brush().colors);
      pen_info.Width(pen.get_linear_gradiant_pen().width);
      return graphics.CreatePen(pen_info);
    }
    if (pen.is_radial_gradiant_pen()) {
      wxGraphicsPenInfo pen_info;
      pen_info.Cap(wxPenCap::wxCAP_BUTT);
      pen_info.Colour({0, 0, 0, 0});
      pen_info.RadialGradient(pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().focal_point.x, pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().focal_point.y, pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().center_point.x, pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().center_point.y, pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().radius, pen.get_radial_gradiant_pen().brush.get_radial_gradiant_brush().colors);
      pen_info.Width(pen.get_radial_gradiant_pen().width);
      return graphics.CreatePen(pen_info);
    }
    if (pen.is_texture_fill_pen()) {
      wxGraphicsPenInfo pen_info;
      pen_info.Cap(wxPenCap::wxCAP_BUTT);
      pen_info.Colour({0, 0, 0, 0});
      pen_info.Stipple(wxBitmap(pen.get_texture_fill_pen().brush.get_texture_brush().texture));
      pen_info.Width(pen.get_texture_fill_pen().width);
      return graphics.CreatePen(pen_info);
    }
    if (pen.is_conical_gradiant_pen()) {
      wxGraphicsPenInfo pen_info;
      pen_info.Cap(wxPenCap::wxCAP_BUTT);
      pen_info.Colour(pen.get_conical_gradiant_pen().brush.get_conical_gradiant_brush().colors.Item(0).GetColour());
      pen_info.Width(pen.get_conical_gradiant_pen().width);
      return graphics.CreatePen(pen_info);
    }

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

void graphics::draw_arc(intptr_t hdc, intptr_t pen, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  if (!hdc) return;
  graphics_context gc(hdc);
  wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc();
  dc.SetBrush(*wxTRANSPARENT_BRUSH);
  dc.SetPen(to_pen(*reinterpret_cast<wx_pen*>(pen)));
  dc.DrawEllipticArc(x, y, width, height, 360 - start_angle - sweep_angle, 360 - start_angle);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_bezier(intptr_t hdc, intptr_t pen, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
  if (!hdc) return;
  graphics_context gc(hdc);
  wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc();
  dc.SetBrush(*wxTRANSPARENT_BRUSH);
  dc.SetPen(to_pen(*reinterpret_cast<wx_pen*>(pen)));
  std::vector<wxPoint> points {wxPoint(x1, y1), wxPoint(x2, y2), wxPoint(x3, y3), wxPoint(x4, y4)};
  dc.DrawSpline(4, points.data());
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_ellipse(intptr_t hdc, intptr_t pen, float x, float y, float width, float height) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  graphics.SetPen(to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawEllipse(x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_image(intptr_t hdc, intptr_t image, float x, float y) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  wxBitmap bitmap = wxBitmap(*reinterpret_cast<wxImage*>(image));
  graphics.DrawBitmap(bitmap, x, y, bitmap.GetWidth(), bitmap.GetHeight());
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_image_disabled(intptr_t hdc, intptr_t image, float x, float y, float brightness) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  wxBitmap bitmap = wxBitmap(*reinterpret_cast<wxImage*>(image)).ConvertToDisabled(static_cast<uint8_t>(255 * brightness));
  graphics.DrawBitmap(bitmap, x, y, bitmap.GetWidth(), bitmap.GetHeight());
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_line(intptr_t hdc, intptr_t pen, float x1, float y1, float x2, float y2) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  graphics.SetPen(to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.StrokeLine(x1, y1, x2, y2);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_path(intptr_t hdc, intptr_t pen, intptr_t graphics_path) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  graphics.SetPen(to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawPath(*reinterpret_cast<wxGraphicsPath*>(graphics_path));
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_rectangle(intptr_t hdc, intptr_t pen, float x, float y, float width, float height) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  graphics.SetPen(to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawRectangle(x, y, width, height);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_rounded_rectangle(intptr_t hdc, intptr_t pen, float x, float y, float width, float height, float radius) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  graphics.SetPen(to_graphics_pen(graphics, *reinterpret_cast<wx_pen*>(pen)));
  graphics.DrawRoundedRectangle(x, y, width, height, radius);
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::draw_string(intptr_t hdc, const ustring& text, intptr_t font, float x, float y, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (!hdc) return;
  // Workaround : with wxWidgets version <= 3.1.4 wxGraphicsContext::DrawText doesn't work with unicode on Windows.
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

void graphics::draw_string(intptr_t hdc, const ustring& text, intptr_t font, float x, float y, float w, float h, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (!hdc) return;
  // Workaround : with wxWidgets version <= 3.1.4 wxGraphicsContext::DrawText doesn't work with unicode on Windows.
  if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") {
    wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc();
    dc.SetClippingRegion({static_cast<int32_t>(x), static_cast<int32_t>(y)}, {static_cast<int32_t>(w), static_cast<int32_t>(h)});
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

void graphics::fill_ellipse(intptr_t hdc, intptr_t brush, float x, float y, float width, float height) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
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
    graphics.SetBrush(to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.DrawEllipse(static_cast<double>(x), static_cast<double>(y), static_cast<double>(width), static_cast<double>(height));
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::fill_path(intptr_t hdc, intptr_t brush, intptr_t graphics_path) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
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
    graphics.SetBrush(to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.FillPath(*reinterpret_cast<wxGraphicsPath*>(graphics_path));
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::fill_pie(intptr_t hdc, intptr_t brush, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  if (!hdc) return;
  graphics_context gc(hdc);
  wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc();
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
    dc.SetBrush(to_brush(*reinterpret_cast<wx_brush*>(brush)));
    dc.SetPen(wxNullPen);
    dc.DrawEllipticArc(x, y, width, height, 360 - start_angle - sweep_angle, 360 - start_angle);
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::fill_rectangle(intptr_t hdc, intptr_t brush, float x, float y, float width, float height) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush()) {
    graphics.DrawBitmap(wxConicalGradient::CreateBitmap(wxSize(width, height), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().colors, reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().center_point - wxPoint(x, y), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().angle), x, y, width, height);
  } else {
    graphics.SetPen(wxNullPen);
    graphics.SetBrush(to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.DrawRectangle(static_cast<double>(x), static_cast<double>(y), static_cast<double>(width), static_cast<double>(height));
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::fill_region(intptr_t hdc, intptr_t brush, intptr_t region) {
  if (!hdc) return;
  int32_t x, y, width, height;
  wxRegion* wx_region = reinterpret_cast<wxRegion*>(region);
  wx_region->GetBox(x, y, width, height);
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  graphics.Clip(*wx_region);
  if (reinterpret_cast<wx_brush*>(brush)->is_conical_gradiant_brush()) {
    graphics.DrawBitmap(wxConicalGradient::CreateBitmap(wxSize(width, height), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().colors, reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().center_point - wxPoint(x, y), reinterpret_cast<wx_brush*>(brush)->get_conical_gradiant_brush().angle), x, y, width, height);
  } else {
    graphics.SetPen(wxNullPen);
    graphics.SetBrush(to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.DrawRectangle(static_cast<double>(x), static_cast<double>(y), static_cast<double>(width), static_cast<double>(height));
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}

void graphics::fill_rounded_rectangle(intptr_t hdc, intptr_t brush, float x, float y, float width, float height, float radius) {
  if (!hdc) return;
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
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
    graphics.SetBrush(to_graphics_brush(graphics, *reinterpret_cast<wx_brush*>(brush)));
    graphics.DrawRoundedRectangle(static_cast<double>(x), static_cast<double>(y), static_cast<double>(width), static_cast<double>(height), static_cast<double>(radius));
  }
  reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->apply_update();
}


intptr_t graphics::from_image(intptr_t image) {
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper;
  if (image == 0) hdc_wrapper->create<wxScreenDC>();
  else hdc_wrapper->create_memory_hdc(new wxBitmap(*reinterpret_cast<wxImage*>(image)), reinterpret_cast<wxImage*>(image));
  return reinterpret_cast<intptr_t>(hdc_wrapper);
}

void graphics::measure_string(intptr_t hdc, const ustring& text, intptr_t font, float& width, float& height) {
  if (!hdc) return;
  width = 0;
  height = 0;
  auto strings = text.split({ '\n' });
  for (auto string : strings) {
    double line_width = 0, line_height = 0;
    // Workaround : with wxWidgets version <= 3.1.4 wxGraphicsContext::GetTextExtent doesn't work with unicode on Windows.
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
    width = std::max(width, static_cast<float>(line_width));
    height += static_cast<float>(line_height);
    
    // Workaround : with wxWidgets version <= 3.1.4 width size text is too small on macOS and linux.
    if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() != "Windows" && reinterpret_cast<wxFont*>(font)->GetStyle() > wxFontStyle::wxFONTSTYLE_NORMAL) width += std::ceil(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->hdc().GetFontMetrics().averageWidth / 2.3f);
  }
}

void graphics::rotate_transform(intptr_t hdc, float angle) {
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  graphics.Rotate(angle);
}

void graphics::translate_clip(intptr_t hdc, float dx, float dy) {
  wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(hdc)->graphics();
  graphics.Translate(dx, dy);
}
