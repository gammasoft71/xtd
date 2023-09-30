#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/pen>
#include <xtd/drawing/native/line_caps>
#include <xtd/drawing/native/line_joins>
#include <xtd/drawing/native/toolkit>
#include "../../../../../include/xtd/drawing/native/wx_pen.h"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/colour.h>
#include <wx/pen.h>
#include <map>
#include <vector>

using namespace std;
using namespace xtd;
using namespace xtd::drawing::native;

intptr pen::create() {
  toolkit::initialize(); // Must be first
  return reinterpret_cast<intptr>(new wx_pen());
}

void pen::solid_color(intptr pen, xtd::byte a, xtd::byte r, xtd::byte g, xtd::byte b, float width, float dash_offset, vector<float> dashes) {
  vector<xtd::sbyte> wx_dashes;
  for (auto dash : dashes)
    wx_dashes.push_back(static_cast<xtd::sbyte>(dash));
  reinterpret_cast<wx_pen*>(pen)->create_solid_color_pen({r, g, b, a}, width, dash_offset, wx_dashes);
}

void pen::hatch_fill(intptr pen, intptr brush, float width) {
  reinterpret_cast<wx_pen*>(pen)->create_hatch_fill_pen(*reinterpret_cast<wx_brush*>(brush), width);
}

void pen::conical_gradient(intptr pen, intptr brush, float width) {
  reinterpret_cast<wx_pen*>(pen)->create_conical_gradient_pen(*reinterpret_cast<wx_brush*>(brush), width);
}

void pen::end_cap(intptr pen, int32 line_cap) {
  switch (line_cap) {
    case LC_FLAT: reinterpret_cast<wx_pen*>(pen)->line_cap(wxPenCap::wxCAP_BUTT); break;
    case LC_SQUARE: reinterpret_cast<wx_pen*>(pen)->line_cap(wxPenCap::wxCAP_PROJECTING); break;
    case LC_ROUND: reinterpret_cast<wx_pen*>(pen)->line_cap(wxPenCap::wxCAP_ROUND); break;
    default: reinterpret_cast<wx_pen*>(pen)->line_cap(wxPenCap::wxCAP_BUTT); break;
  }
}

void pen::linear_gradient(intptr pen, intptr brush, float width) {
  reinterpret_cast<wx_pen*>(pen)->create_linear_gradient_pen(*reinterpret_cast<wx_brush*>(brush), width);
}

void pen::line_join(intptr pen, int32 line_join) {
  switch (line_join) {
    case LJ_MITER: reinterpret_cast<wx_pen*>(pen)->line_join(wxPenJoin::wxJOIN_MITER); break;
    case LJ_BEVEL: reinterpret_cast<wx_pen*>(pen)->line_join(wxPenJoin::wxJOIN_BEVEL); break;
    case LJ_ROUND: reinterpret_cast<wx_pen*>(pen)->line_join(wxPenJoin::wxJOIN_ROUND); break;
    case LJ_MITER_CLIPPED: reinterpret_cast<wx_pen*>(pen)->line_join(wxPenJoin::wxJOIN_MITER); break;
    default: reinterpret_cast<wx_pen*>(pen)->line_join(wxPenJoin::wxJOIN_MITER); break;
  }
}

void pen::miter_limit(intptr pen, float miter_limit) {
  // WxWidgets has no mitter limit...
}

void pen::radial_gradient(intptr pen, intptr brush, float width) {
  reinterpret_cast<wx_pen*>(pen)->create_radial_gradient_pen(*reinterpret_cast<wx_brush*>(brush), width);
}

void pen::start_cap(intptr pen, int32 line_cap) {
  switch (line_cap) {
    case LC_FLAT: reinterpret_cast<wx_pen*>(pen)->line_cap(wxPenCap::wxCAP_BUTT); break;
    case LC_SQUARE: reinterpret_cast<wx_pen*>(pen)->line_cap(wxPenCap::wxCAP_PROJECTING); break;
    case LC_ROUND: reinterpret_cast<wx_pen*>(pen)->line_cap(wxPenCap::wxCAP_ROUND); break;
    default: reinterpret_cast<wx_pen*>(pen)->line_cap(wxPenCap::wxCAP_BUTT); break;
  }
}

void pen::texture_fill(intptr pen, intptr brush, float width) {
  reinterpret_cast<wx_pen*>(pen)->create_texture_fill_pen(*reinterpret_cast<wx_brush*>(brush), width);
}

void pen::destroy(intptr pen) {
  delete reinterpret_cast<wx_pen*>(pen);
}

/*
intptr pen::create() {
  toolkit::initialize(); // Must be first
  auto pen = new wx_pen();
  pen->SetQuality(wxPenQuality::wxPEN_QUALITY_HIGH);
  pen->SetCap(wxPenCap::wxCAP_BUTT);
  return reinterpret_cast<intptr>(pen);
}

void pen::color(intptr pen, xtd::byte a, xtd::byte r, xtd::byte g, xtd::byte b) {
  toolkit::initialize(); // Must be first
  reinterpret_cast<wxPen*>(pen)->SetColour(wxColour(r, g, b, a));
}

void pen::image(intptr pen, intptr image) {
  toolkit::initialize(); // Must be first
  reinterpret_cast<wx_pen*>(pen)->SetStyle(wxPenStyle::wxPENSTYLE_STIPPLE);
  reinterpret_cast<wx_pen*>(pen)->SetStipple(*reinterpret_cast<wxImage*>(image));
}

void pen::dash_pattern(intptr pen, std::vector<float> dash_pattern) {
  toolkit::initialize(); // Must be first
  reinterpret_cast<wx_pen*>(pen)->dashes.clear();
  for (auto dash : dash_pattern)
    reinterpret_cast<wx_pen*>(pen)->dashes.push_back(static_cast<wxDash>(dash));
  reinterpret_cast<wxPen*>(pen)->SetDashes(reinterpret_cast<wx_pen*>(pen)->dashes.size(), reinterpret_cast<wx_pen*>(pen)->dashes.data());
}

void pen::dash_style(intptr pen, uint32 dash_style) {
  toolkit::initialize(); // Must be first
  reinterpret_cast<wx_pen*>(pen)->SetStyle(wxPENSTYLE_USER_DASH);
  switch (dash_style) {
    case 0: reinterpret_cast<wx_pen*>(pen)->dashes = {1}; break;
    case 1: reinterpret_cast<wx_pen*>(pen)->dashes = {3, 2}; break;
    case 2: reinterpret_cast<wx_pen*>(pen)->dashes = {1, 1}; break;
    case 3: reinterpret_cast<wx_pen*>(pen)->dashes = {3, 1, 1, 1}; break;
    case 4: reinterpret_cast<wx_pen*>(pen)->dashes = {3, 1, 1, 1, 1, 1}; break;
    default: break;
  }
  reinterpret_cast<wxPen*>(pen)->SetDashes(reinterpret_cast<wx_pen*>(pen)->dashes.size(), reinterpret_cast<wx_pen*>(pen)->dashes.data());
}

void pen::width(intptr pen, float width) {
  toolkit::initialize(); // Must be first
  reinterpret_cast<wxPen*>(pen)->SetWidth(static_cast<int32>(width));
}

void pen::destroy(intptr pen) {
  delete reinterpret_cast<wx_pen*>(pen);
}
*/
