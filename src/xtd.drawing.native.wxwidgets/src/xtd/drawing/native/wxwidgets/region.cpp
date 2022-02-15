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

using namespace std;
using namespace xtd::drawing::native;

intptr_t region::create(float x, float y, float width, float height) {
  toolkit::initialize(); // Must be first
  return reinterpret_cast<intptr_t>(new wxRegion(as<int32_t>(x), as<int32_t>(y), as<int32_t>(width), as<int32_t>(height)));
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

void region::intersect(intptr_t handle, intptr_t region) {
  auto& region1 = *reinterpret_cast<wxRegion*>(handle);
  auto& region2 = *reinterpret_cast<wxRegion*>(region);
  region1.Intersect(region2);
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
