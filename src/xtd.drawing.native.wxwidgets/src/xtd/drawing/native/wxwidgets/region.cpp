#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/region>
#include <xtd/drawing/native/toolkit>
#include "../../../../../include/xtd/drawing/native/hdc_wrapper.h"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/as>
#include <xtd/int32_object>
#include <xtd/single_object>
#include <wx/colour.h>
#include <wx/region.h>
#include <map>
#include <vector>

using namespace std;
using namespace xtd;
using namespace xtd::drawing::native;

namespace {
  static const wxColour mask_color = wxColour(255, 0, 255);
  static wxBitmap create_graphics_path_bitmap(wxGraphicsPath& path) noexcept {
    double x = .0f, y = .0f, width = .0f, height = .0f;
    path.GetBox(&x, &y, &width, &height);
    wxBitmap bitmap(static_cast<int32>(x + width), static_cast<int32>(y + height));
    auto graphics = wxGraphicsContext::Create(wxMemoryDC(bitmap));
    graphics->SetPen(graphics->CreatePen(wxNullPen));
    graphics->SetBrush(graphics->CreateBrush(wxBrush((mask_color))));
    graphics->DrawRectangle(0, 0, x + width, y + height);
    graphics->SetBrush(graphics->CreateBrush(wxBrush((wxColour(0, 0, 0)))));
    graphics->FillPath(path);
    return bitmap;
  }
}

intptr region::create() {
  toolkit::initialize(); // Must be first
  // Workaround for infinite region on linux
  #if defined(__WXGTK__)
  const auto max_value = 0xFFFFF;
  #else
  const auto max_value = int32_object::max_value;
  #endif
  return reinterpret_cast<intptr>(new wxRegion(-max_value / 2, -max_value / 2, max_value, max_value));
}

intptr region::create_from_rect(float x, float y, float width, float height) {
  toolkit::initialize(); // Must be first
  return reinterpret_cast<intptr>(new wxRegion(as<int32>(x), as<int32>(y), as<int32>(width), as<int32>(height)));
}

intptr region::create_from_graphics_path(intptr path) {
  auto wx_path = reinterpret_cast<wxGraphicsPath*>(path);
  wxBitmap bitmap = create_graphics_path_bitmap(*wx_path);
  return reinterpret_cast<intptr>(new wxRegion(bitmap, mask_color));
}

void region::destroy(intptr handle) {
  delete reinterpret_cast<wxRegion*>(handle);
}

void region::complement(intptr handle, intptr region) {
  auto& region1 = *reinterpret_cast<wxRegion*>(handle);
  auto& region2 = *reinterpret_cast<wxRegion*>(region);
  region2.Subtract(region1);
  region1 = region2;
}

void region::exclude(intptr handle, intptr region) {
  auto& region1 = *reinterpret_cast<wxRegion*>(handle);
  auto& region2 = *reinterpret_cast<wxRegion*>(region);
  region1.Subtract(region2);
}

intptr region::from_hrgn(intptr hrgn) {
  #if defined(__WXOSX__) || defined(__WXMSW__)
  return reinterpret_cast<intptr>(new wxRegion(reinterpret_cast<WXHRGN>(hrgn)));
  #else
  return hrgn;
  #endif
}

void region::get_bounds(intptr handle, float& x, float& y, float& width, float& height) {
  auto wx_region = reinterpret_cast<wxRegion*>(handle);
  x = as<int32>(wx_region->GetBox().x);
  y = as<int32>(wx_region->GetBox().y);
  width = as<int32>(wx_region->GetBox().width);
  height = as<int32>(wx_region->GetBox().height);
}

intptr region::get_hrgn(intptr handle, intptr grpahics) {
  #if defined(__WXOSX__)
  return reinterpret_cast<intptr>(reinterpret_cast<wxRegion*>(handle)->GetWXHRGN());
  #elif defined(__WXMSW__)
  return reinterpret_cast<intptr>(reinterpret_cast<wxRegion*>(handle)->GetHRGN());
  #else
  return reinterpret_cast<intptr>(handle);
  #endif
}

void region::intersect(intptr handle, intptr region) {
  auto& region1 = *reinterpret_cast<wxRegion*>(handle);
  auto& region2 = *reinterpret_cast<wxRegion*>(region);
  region1.Intersect(region2);
}

bool region::is_empty(intptr handle) {
  return reinterpret_cast<wxRegion*>(handle)->IsEmpty();
}

bool region::is_empty(intptr handle, intptr grpahics) {
  return reinterpret_cast<wxRegion*>(handle)->IsEmpty();
}

bool region::is_infinite(intptr handle) {
  auto bounds = reinterpret_cast<wxRegion*>(handle)->GetBox();
  return bounds.x == as<int32>(single_object::min_value) && bounds.y == as<int32>(single_object::min_value) && bounds.width == as<int32>(single_object::max_value) && bounds.height == as<int32>(single_object::max_value);
}

bool region::is_infinite(intptr handle, intptr grpahics) {
  auto bounds = reinterpret_cast<wxRegion*>(handle)->GetBox();
  return bounds.x == as<int32>(single_object::min_value) && bounds.y == as<int32>(single_object::min_value) && bounds.width == as<int32>(single_object::max_value) && bounds.height == as<int32>(single_object::max_value);
}

bool region::is_visible(intptr handle, float x, float y) {
  return reinterpret_cast<wxRegion*>(handle)->Contains(as<int32>(x), as<int32>(y)) == wxInRegion;
}

bool region::is_visible(intptr handle, float x, float y, intptr grpahics) {
  return reinterpret_cast<wxRegion*>(handle)->Contains(as<int32>(x), as<int32>(y)) == wxInRegion;
}

bool region::is_visible(intptr handle, float x, float y, float width, float height) {
  return reinterpret_cast<wxRegion*>(handle)->Contains(as<int32>(x), as<int32>(y), as<int32>(width), as<int32>(height)) != wxOutRegion;
}

bool region::is_visible(intptr handle, float x, float y, float width, float height, intptr grpahics) {
  return reinterpret_cast<wxRegion*>(handle)->Contains(as<int32>(x), as<int32>(y), as<int32>(width), as<int32>(height)) != wxOutRegion;
}

void region::make_empty(intptr handle) {
  reinterpret_cast<wxRegion*>(handle)->Clear();
}

void region::make_union(intptr handle, intptr region) {
  auto& region1 = *reinterpret_cast<wxRegion*>(handle);
  auto& region2 = *reinterpret_cast<wxRegion*>(region);
  region1.Union(region2);
}

void region::make_xor(intptr handle, intptr region) {
  auto& region1 = *reinterpret_cast<wxRegion*>(handle);
  auto& region2 = *reinterpret_cast<wxRegion*>(region);
  region1.Xor(region2);
}

void region::release_hrgn(intptr region_handle) {
  // Does not exists in WxWidgets...
}

void region::translate(intptr handle, float dx, float dy) {
  reinterpret_cast<wxRegion*>(handle)->Offset(as<int32>(dx), as<int32>(dy));
}
