#include "../../../include/xtd/drawing/icon.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/icon.h>
#include <xtd/drawing/native/image_formats.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <iostream>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

icon icon::empty;

struct icon::data {
  intptr handle = 0;
  xtd::drawing::size size;
};

icon::icon(const ustring& filename) : data_(make_shared<data>()) {
  data_->handle = native::icon::create(filename);
  data_->size = {native::icon::get_width(handle()), native::icon::get_height(handle())};
}

icon::icon(const xtd::ustring& filename, const xtd::drawing::size& size) : icon(filename, size.width(), size.height()) {
}

icon::icon(const xtd::ustring& filename, int32 width, int32 height) : data_(make_shared<data>()) {
  data_->handle = native::icon::create(filename, width, height);
  data_->size = {width, height};
}

icon::icon(istream& stream) : data_(make_shared<data>()) {
  data_->handle = native::icon::create(stream);
  data_->size = {native::icon::get_width(handle()), native::icon::get_height(handle())};
}

icon::icon(istream& stream, const xtd::drawing::size& size) : icon(stream, size.width(), size.height()) {
}

icon::icon(istream& stream, int32 width, int32 height) : data_(make_shared<data>()) {
  data_->handle = native::icon::create(stream, width, height);
  data_->size = {native::icon::get_width(handle()), native::icon::get_height(handle())};
}

icon::icon(const char* const* bits) : data_(make_shared<data>()) {
  data_->handle = native::icon::create(bits);
  data_->size = {native::icon::get_width(handle()), native::icon::get_height(handle())};
}

icon::icon(const char* const* bits, const xtd::drawing::size& size) : icon(bits, size.width(), size.height()) {
}

icon::icon(const char* const* bits, int32 width, int32 height) : data_(make_shared<data>()) {
  data_->handle = native::icon::create(bits, width, height);
  data_->size = {native::icon::get_width(handle()), native::icon::get_height(handle())};
}

icon::icon(const icon& original, const xtd::drawing::size& size) : icon(original, size.width(), size.height()) {
}

icon::icon(const icon& original, int32 width, int32 height) : data_(make_shared<data>()) {
  data_->handle = native::icon::create(original.data_->handle, width, height);
  data_->size = {native::icon::get_width(handle()), native::icon::get_height(handle())};
}

icon::icon(const drawing::bitmap& bitmap) : data_(make_shared<data>()) {
  if (bitmap == drawing::bitmap::empty) return;
  data_->handle = native::icon::create(bitmap.handle());
  data_->size = {native::icon::get_width(handle()), native::icon::get_height(handle())};
}

icon::icon() : data_(make_shared<data>()) {
}

icon::~icon() {
  if (data_.use_count() == 1 && data_->handle)
    native::icon::destroy(data_->handle);
}

intptr icon::handle() const noexcept {
  return data_->handle;
}

int32 icon::height() const noexcept {
  return data_->size.height();
}

const xtd::drawing::size& icon::size() const noexcept {
  return data_->size;
}

int32 icon::width() const noexcept {
  return data_->size.width();
}

bool icon::equals(const icon& icon) const noexcept {
  return data_->handle == icon.data_->handle;
}

icon icon::from_handle(intptr handle) {
  auto icon = drawing::icon {};
  icon.data_->handle = native::icon::from_handle(handle);
  icon.data_->size = {native::icon::get_width(icon.data_->handle), native::icon::get_height(icon.data_->handle)};
  return icon;
}

icon icon::from_bitmap(const bitmap& bitmap) {
  return icon(bitmap);
}

void icon::save(const ustring& filename) const {
  native::icon::save(data_->handle, filename);
}

void icon::save(ostream& stream) const {
  native::icon::save(data_->handle, stream, IFM_ICO);
}

bitmap icon::to_bitmap() const {
  return image::from_hbitmap(native::icon::to_image(data_->handle));
}

xtd::ustring icon::to_string() const noexcept {
  return get_type().full_name();
}
