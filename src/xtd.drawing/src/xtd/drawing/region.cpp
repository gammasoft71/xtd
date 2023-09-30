#include "../../../include/xtd/drawing/region.h"
#include "../../../include/xtd/drawing/graphics.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/region>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/as>
#include <xtd/box>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;

struct region::data {
  intptr handle = 0;
};

region::region() : data_(std::make_shared<data>()) {
  data_->handle = native::region::create();
}

region::region(const graphics_path& path) : data_(std::make_shared<data>()) {
  data_->handle = native::region::create_from_graphics_path(path.handle());
}

region::region(const rectangle& rect) : region(rectangle_f(rect)) {
}

region::region(const rectangle_f& rect) : data_(std::make_shared<data>()) {
  data_->handle = native::region::create_from_rect(rect.x(), rect.y(), rect.width(), rect.height());
}

region::~region() {
  if (data_.use_count() == 1 && data_->handle != 0) native::region::destroy(data_->handle);
}

intptr region::handle() const noexcept {
  return data_->handle;
}

void region::complement(const xtd::drawing::drawing_2d::graphics_path& path) noexcept {
  complement(region(path));
}

void region::complement(const xtd::drawing::rectangle& rect) noexcept {
  complement(region(rect));
}

void region::complement(const xtd::drawing::rectangle_f& rect) noexcept {
  complement(region(rect));
}

void region::complement(const xtd::drawing::region& region) noexcept {
  native::region::complement(data_->handle, region.data_->handle);
}

bool region::equals(const region& value) const noexcept {
  return data_ == value.data_;
}

void region::exclude(const xtd::drawing::drawing_2d::graphics_path& path) noexcept {
  exclude(region(path));
}

void region::exclude(const xtd::drawing::rectangle& rect) noexcept {
  exclude(region(rect));
}

void region::exclude(const xtd::drawing::rectangle_f& rect) noexcept {
  exclude(region(rect));
}

void region::exclude(const xtd::drawing::region& region) noexcept {
  native::region::exclude(data_->handle, region.data_->handle);
}

xtd::drawing::region region::from_hrgn(intptr hrgn) {
  auto result = region {};
  result.data_->handle = native::region::from_hrgn(hrgn);
  return result;
}

rectangle_f region::get_bounds() const noexcept {
  auto x = 0.0f, y = 0.0f, width = 0.0f, height = 0.0f;
  native::region::get_bounds(handle(), x, y, width, height);
  return rectangle_f(x, y, width, height);
}

rectangle_f region::get_bounds(const xtd::drawing::graphics& g) const noexcept {
  auto rect = get_bounds();
  rect.x(g.to_page_unit(rect.x()));
  rect.y(g.to_page_unit(rect.y()));
  rect.width(g.to_page_unit(rect.width()));
  rect.height(g.to_page_unit(rect.height()));
  return rect;
}

intptr region::get_hrgn(const xtd::drawing::graphics& g) const noexcept {
  return native::region::get_hrgn(handle(), g.handle());
}

void region::intersect(const xtd::drawing::drawing_2d::graphics_path& path) noexcept {
  intersect(region(path));
}

void region::intersect(const xtd::drawing::rectangle& rect) noexcept {
  intersect(region(rect));
}

void region::intersect(const xtd::drawing::rectangle_f& rect) noexcept {
  intersect(region(rect));
}

void region::intersect(const xtd::drawing::region& region) noexcept {
  native::region::intersect(data_->handle, region.data_->handle);
}

bool region::is_empty() const noexcept {
  return native::region::is_empty(handle());
}

bool region::is_empty(const xtd::drawing::graphics& g) const noexcept {
  return native::region::is_empty(handle(), g.handle());
}

bool region::is_infinite() const noexcept {
  return native::region::is_infinite(handle());
}

bool region::is_infinite(const xtd::drawing::graphics& g) const noexcept {
  return native::region::is_infinite(handle(), g.handle());
}

bool region::is_visible(const xtd::drawing::rectangle_f& rect, const xtd::drawing::graphics& g) const noexcept {
  return is_visible(rect.x(), rect.y(), rect.width(), rect.height(), g);
}

bool region::is_visible(float x, float y, float width, float height, const xtd::drawing::graphics& g) const noexcept {
  return native::region::is_visible(handle(), x, y, width, height, g.handle());
}

bool region::is_visible(const xtd::drawing::rectangle& rect, const xtd::drawing::graphics& g) const noexcept {
  return is_visible(as<float>(rect.x()), as<float>(rect.y()), as<float>(rect.width()), as<float>(rect.height()), g);
}

bool region::is_visible(int32 x, int32 y, int32 width, int32 height, const xtd::drawing::graphics& g) const noexcept {
  return is_visible(as<float>(x), as<float>(y), as<float>(width), as<float>(height), g);
}

bool region::is_visible(const xtd::drawing::rectangle_f& rect) const noexcept {
  return is_visible(rect.x(), rect.y(), rect.width(), rect.height());
}

bool region::is_visible(float x, float y, float width, float height) const noexcept {
  return native::region::is_visible(handle(), x, y, width, height);
}

bool region::is_visible(const xtd::drawing::rectangle& rect) const noexcept {
  return is_visible(as<float>(rect.x()), as<float>(rect.y()), as<float>(rect.width()), as<float>(rect.height()));
}

bool region::is_visible(int32 x, int32 y, int32 width, int32 height) const noexcept {
  return is_visible(as<float>(x), as<float>(y), as<float>(width), as<float>(height));
}

bool region::is_visible(xtd::drawing::point_f pt, const xtd::drawing::graphics& g) const noexcept {
  return is_visible(pt.x(), pt.y(), g);
}

bool region::is_visible(float x, float y, const xtd::drawing::graphics& g) const noexcept {
  return native::region::is_visible(handle(), x, y, g.handle());
}

bool region::is_visible(xtd::drawing::point pt, const xtd::drawing::graphics& g) const noexcept {
  return is_visible(as<float>(pt.x()), as<float>(pt.y()), g);
}

bool region::is_visible(int32 x, int32 y, const xtd::drawing::graphics& g) const noexcept {
  return is_visible(as<float>(x), as<float>(y), g);
}

bool region::is_visible(xtd::drawing::point_f pt) const noexcept {
  return is_visible(pt.x(), pt.y());
}

bool region::is_visible(float x, float y) const noexcept {
  return native::region::is_visible(handle(), x, y);
}

bool region::is_visible(xtd::drawing::point pt) const noexcept {
  return is_visible(as<float>(pt.x()), as<float>(pt.y()));
}

bool region::is_visible(int32 x, int32 y) const noexcept {
  return is_visible(as<float>(x), as<float>(y));
}

void region::make_empty() {
  native::region::make_empty(handle());
}

void region::make_infinite() noexcept {
  *this = region();
}

void region::make_union(const xtd::drawing::drawing_2d::graphics_path& path) noexcept {
  make_union(region(path));
}

void region::make_union(const xtd::drawing::rectangle& rect) noexcept {
  make_union(region(rect));
}

void region::make_union(const xtd::drawing::rectangle_f& rect) noexcept {
  make_union(region(rect));
}

void region::make_union(const xtd::drawing::region& region) noexcept {
  native::region::make_union(data_->handle, region.data_->handle);
}

void region::make_xor(const xtd::drawing::drawing_2d::graphics_path& path) noexcept {
  make_xor(region(path));
}

void region::make_xor(const xtd::drawing::rectangle& rect) noexcept {
  make_xor(region(rect));
}

void region::make_xor(const xtd::drawing::rectangle_f& rect) noexcept {
  make_xor(region(rect));
}

void region::make_xor(const xtd::drawing::region& region) noexcept {
  native::region::make_xor(data_->handle, region.data_->handle);
}

void region::release_hrgn(intptr region_handle) {
  native::region::release_hrgn(region_handle);
}

void region::translate(int32 dx, int32 dy) noexcept {
  translate(as<float>(dx), as<float>(dy));
}

void region::translate(float dx, float dy) noexcept {
  native::region::translate(handle(), dx, dy);
}
