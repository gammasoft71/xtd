#include "../../../include/xtd/drawing/region.h"
#include <xtd/box.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/region.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;

region::region() : region(rectangle_f(single_object::min_value, single_object::min_value, single_object::max_value, single_object::max_value)) {
}

region::region(const graphics_path& path) {
  data_->bounds = path.get_bounds();
  data_->handle = native::region::create_from_graphics_path(path.handle());
}

region::region(const rectangle& rect) : region(rectangle_f(rect)) {
}

region::region(const rectangle_f& rect) {
  data_->bounds = rect;
  data_->handle = native::region::create_from_rect(data_->bounds.x(), data_->bounds.y(), data_->bounds.width(), data_->bounds.height());
}

region::~region() {
  if (data_.use_count() == 1 && data_->handle != 0) native::region::destroy(data_->handle);
}

bool region::operator==(const region& value) const {
  return data_ == value.data_;
}

bool region::operator!=(const region& value) const {
  return !operator==(value);
}

intptr_t region::handle() const {
  return data_->handle;
}

void region::complement(const xtd::drawing::drawing2d::graphics_path& path) {
  complement(region(path));
}

void region::complement(const xtd::drawing::rectangle& rect) {
  complement(region(rect));
}

void region::complement(const xtd::drawing::rectangle_f& rect) {
  complement(region(rect));
}

void region::complement(const xtd::drawing::region& region) {
  native::region::complement(data_->handle, region.data_->handle);
}

void region::exclude(const xtd::drawing::drawing2d::graphics_path& path) {
  exclude(region(path));
}

void region::exclude(const xtd::drawing::rectangle& rect) {
  exclude(region(rect));
}

void region::exclude(const xtd::drawing::rectangle_f& rect) {
  exclude(region(rect));
}

void region::exclude(const xtd::drawing::region& region) {
  native::region::exclude(data_->handle, region.data_->handle);
}

void region::intersect(const xtd::drawing::drawing2d::graphics_path& path) {
  intersect(region(path));
}

void region::intersect(const xtd::drawing::rectangle& rect) {
  intersect(region(rect));
}

void region::intersect(const xtd::drawing::rectangle_f& rect) {
  intersect(region(rect));
}

void region::intersect(const xtd::drawing::region& region) {
  native::region::intersect(data_->handle, region.data_->handle);
}

rectangle_f region::get_bounds() const {
  return data_->bounds;
}

void region::make_union(const xtd::drawing::drawing2d::graphics_path& path) {
  make_union(region(path));
}

void region::make_union(const xtd::drawing::rectangle& rect) {
  make_union(region(rect));
}

void region::make_union(const xtd::drawing::rectangle_f& rect) {
  make_union(region(rect));
}

void region::make_union(const xtd::drawing::region& region) {
  native::region::make_union(data_->handle, region.data_->handle);
}

void region::make_xor(const xtd::drawing::drawing2d::graphics_path& path) {
  make_xor(region(path));
}

void region::make_xor(const xtd::drawing::rectangle& rect) {
  make_xor(region(rect));
}

void region::make_xor(const xtd::drawing::rectangle_f& rect) {
  make_xor(region(rect));
}

void region::make_xor(const xtd::drawing::region& region) {
  native::region::make_xor(data_->handle, region.data_->handle);
}
