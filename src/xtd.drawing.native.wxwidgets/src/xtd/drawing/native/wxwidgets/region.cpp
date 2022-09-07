#include <map>
#include <vector>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/region.h>
#include <xtd/drawing/native/toolkit.h>
#include "../../../../../include/xtd/drawing/native/hdc_wrapper.h"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/colour.h>
#include <wx/region.h>
#include <xtd/as.h>
#include <xtd/box.h>

using namespace std;
using namespace xtd::drawing::native;

namespace {
  static const wxColour mask_color = wxColour(255, 0, 255);
  static wxBitmap create_graphics_path_bitmap(wxGraphicsPath& path) noexcept {
    double x = .0f, y = .0f, width = .0f, height = .0f;
    path.GetBox(&x, &y, &width, &height);
    wxBitmap bitmap(static_cast<int32_t>(x + width), static_cast<int32_t>(y + height));
    auto graphics = wxGraphicsContext::Create(wxMemoryDC(bitmap));
    graphics->SetPen(graphics->CreatePen(wxNullPen));
    graphics->SetBrush(graphics->CreateBrush(wxBrush((mask_color))));
    graphics->DrawRectangle(0, 0, x + width, y + height);
    graphics->SetBrush(graphics->CreateBrush(wxBrush((wxColour(0, 0, 0)))));
    graphics->FillPath(path);
    return bitmap;
  }
}

intptr_t region::create_from_rect(float x, float y, float width, float height) {
  toolkit::initialize(); // Must be first
  return reinterpret_cast<intptr_t>(new wxRegion(as<int32_t>(x), as<int32_t>(y), as<int32_t>(width), as<int32_t>(height)));
}

intptr_t region::create_from_graphics_path(intptr_t path) {
  auto wx_path = reinterpret_cast<wxGraphicsPath*>(path);
  wxBitmap bitmap = create_graphics_path_bitmap(*wx_path);
  return reinterpret_cast<intptr_t>(new wxRegion(bitmap, mask_color));
}

void region::destroy(intptr_t handle) {
  delete reinterpret_cast<wxRegion*>(handle);
}

void region::complement(intptr_t handle, intptr_t region) {
  auto& region1 = *reinterpret_cast<wxRegion*>(handle);
  auto& region2 = *reinterpret_cast<wxRegion*>(region);
  region2.Subtract(region1);
  region1 = region2;
}

void region::exclude(intptr_t handle, intptr_t region) {
  auto& region1 = *reinterpret_cast<wxRegion*>(handle);
  auto& region2 = *reinterpret_cast<wxRegion*>(region);
  region1.Subtract(region2);
}

intptr_t region::from_hrgn(intptr_t hrgn) {
  #if defined(__APPLE__) || defined(WIN32)
  return reinterpret_cast<intptr_t>(new wxRegion(reinterpret_cast<WXHRGN>(hrgn)));
  #else
  return hrgn;
  #endif
}

void region::get_bounds(intptr_t handle, float& x, float& y, float& width, float& height) {
  auto wx_region = reinterpret_cast<wxRegion*>(handle);
  x = as<int32_t>(wx_region->GetBox().x);
  y = as<int32_t>(wx_region->GetBox().y);
  width = as<int32_t>(wx_region->GetBox().width);
  height = as<int32_t>(wx_region->GetBox().height);
}

intptr_t region::get_hrgn(intptr_t handle, intptr_t grpahics) {
  #if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(reinterpret_cast<wxRegion*>(handle)->GetWXHRGN());
  #elif defined(WIN32)
  return reinterpret_cast<intptr_t>(reinterpret_cast<wxRegion*>(handle)->GetHRGN());
  #else
  return reinterpret_cast<intptr_t>(handle);
  #endif
}

void region::intersect(intptr_t handle, intptr_t region) {
  auto& region1 = *reinterpret_cast<wxRegion*>(handle);
  auto& region2 = *reinterpret_cast<wxRegion*>(region);
  region1.Intersect(region2);
}

bool region::is_empty(intptr_t handle) {
  return reinterpret_cast<wxRegion*>(handle)->IsEmpty();
}

bool region::is_empty(intptr_t handle, intptr_t grpahics) {
  return reinterpret_cast<wxRegion*>(handle)->IsEmpty();
}

bool region::is_infinite(intptr_t handle) {
  auto bounds = reinterpret_cast<wxRegion*>(handle)->GetBox();
  return bounds.x == as<int32_t>(single_object::min_value) && bounds.y == as<int32_t>(single_object::min_value) && bounds.width == as<int32_t>(single_object::max_value) && bounds.height == as<int32_t>(single_object::max_value);
}

bool region::is_infinite(intptr_t handle, intptr_t grpahics) {
  auto bounds = reinterpret_cast<wxRegion*>(handle)->GetBox();
  return bounds.x == as<int32_t>(single_object::min_value) && bounds.y == as<int32_t>(single_object::min_value) && bounds.width == as<int32_t>(single_object::max_value) && bounds.height == as<int32_t>(single_object::max_value);
}

bool region::is_visible(intptr_t handle, float x, float y) {
  return reinterpret_cast<wxRegion*>(handle)->Contains(as<int32_t>(x), as<int32_t>(y)) == wxInRegion;
}

bool region::is_visible(intptr_t handle, float x, float y, intptr_t grpahics) {
  return reinterpret_cast<wxRegion*>(handle)->Contains(as<int32_t>(x), as<int32_t>(y)) == wxInRegion;
}

bool region::is_visible(intptr_t handle, float x, float y, float width, float height) {
  return reinterpret_cast<wxRegion*>(handle)->Contains(as<int32_t>(x), as<int32_t>(y), as<int32_t>(width), as<int32_t>(height)) != wxOutRegion;
}

bool region::is_visible(intptr_t handle, float x, float y, float width, float height, intptr_t grpahics) {
  return reinterpret_cast<wxRegion*>(handle)->Contains(as<int32_t>(x), as<int32_t>(y), as<int32_t>(width), as<int32_t>(height)) != wxOutRegion;
}

void region::make_empty(intptr_t handle) {
  reinterpret_cast<wxRegion*>(handle)->Clear();
}

void region::make_union(intptr_t handle, intptr_t region) {
  auto& region1 = *reinterpret_cast<wxRegion*>(handle);
  auto& region2 = *reinterpret_cast<wxRegion*>(region);
  region1.Union(region2);
}

void region::make_xor(intptr_t handle, intptr_t region) {
  auto& region1 = *reinterpret_cast<wxRegion*>(handle);
  auto& region2 = *reinterpret_cast<wxRegion*>(region);
  region1.Xor(region2);
}

void region::release_hrgn(intptr_t region_handle) {
  // Does not exists in WxWidgets...
}

void region::translate(intptr_t handle, float dx, float dy) {
  reinterpret_cast<wxRegion*>(handle)->Offset(as<int32_t>(dx), as<int32_t>(dy));
}
