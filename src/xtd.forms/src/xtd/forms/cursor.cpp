#include <optional>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/cursor.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/cursor.h"
#include "../../../include/xtd/forms/cursors.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
  std::optional<cursor> current_cursor;
}

cursor cursor::none(0, false, "none");

cursor::cursor(intptr_t handle, bool destroyable, const xtd::ustring& name) {
  data_->handle_ = handle;
  data_->destroyable_ = destroyable;
  data_->name_ = name;
  data_->hot_spot_ = native::cursor::hot_spot(data_->handle_);
  data_->size_ = native::cursor::size(data_->handle_);
}

cursor::cursor() {
  data_->handle_ = native::cursor::create();
  data_->hot_spot_ = native::cursor::hot_spot(data_->handle_);
  data_->size_ = native::cursor::size(data_->handle_);
}

cursor::cursor(intptr_t handle) : cursor(handle, false, "") {
}

cursor::cursor(const bitmap& bitmap, const xtd::drawing::point& hot_spot) {
  data_->handle_ = native::cursor::create(bitmap, hot_spot);
  data_->hot_spot_ = hot_spot;
  data_->size_ = native::cursor::size(data_->handle_);
}

cursor::cursor(const cursor& value) {
  *data_ = *value.data_;
}

cursor& cursor::operator =(const cursor& value) {
  *data_ = *value.data_;
  return *this;
}

cursor::~cursor() {
  if (data_.use_count() == 1 && data_->handle_ && data_->destroyable_)
    native::cursor::destroy(data_->handle_);
}

void cursor::current(const cursor& cursor) {
  current_cursor = cursor;
  native::cursor::current(cursor.data_->name_ == "default_cursor" ? 0 : cursor.data_->handle_);
}

cursor cursor::current() {
  return current_cursor.value_or(none);
}

intptr_t cursor::handle() const noexcept {
  return data_->handle_;
}

drawing::point cursor::hot_spot() const noexcept {
  return data_->hot_spot_;
}

point cursor::position() {
  return native::cursor::position();
}

void cursor::position(const point& position) {
  native::cursor::position(position);
}

drawing::size cursor::size() const noexcept {
  return data_->size_;
}

std::any cursor::tag() const noexcept {
  return data_->tag_;
}

void cursor::tag(std::any tag) {
  data_->tag_ = tag;
}

intptr_t cursor::copy_handle() const {
  return native::cursor::copy(data_->handle_);
}

cursor cursor::from_bitmap(const xtd::drawing::bitmap& bitmap, const xtd::drawing::point& hot_spot) {
  return cursor(bitmap, hot_spot);
}

cursor cursor::from_bitmap(const xtd::drawing::bitmap& bitmap) {
  return from_bitmap(bitmap, {});
}

void cursor::hide() {
  native::cursor::hide();
}

void cursor::show() {
  native::cursor::show();
}

ustring cursor::to_string() const noexcept {
  return ustring::format("[cursor: {}]", data_->name_ != "" ? data_->name_ : ustring::full_class_name(*this));
}

bool cursor::operator ==(const cursor& value) const noexcept {
  return data_ == value.data_ || (!data_->name_.empty() && data_->name_ == value.data_->name_);
}

bool cursor::operator !=(const cursor& value) const noexcept {
  return !operator ==(value);
}
