#include <xtd/forms/native/cursor.h>
#include "../../../include/xtd/forms/cursor.h"
#include "../../../include/xtd/forms/cursors.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
  std::optional<cursor> current_cursor;
}

cursor cursor::none(0, false, "none");

cursor::cursor(intptr_t handle, bool destroyable, const std::string& name) {
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

cursor::cursor(const bitmap& bitmap, const xtd::drawing::point& hot_spot) {
  data_->handle_ = native::cursor::create(bitmap.handle(), hot_spot);
  data_->hot_spot_ = hot_spot;
  data_->size_ = native::cursor::size(data_->handle_);
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

point cursor::position() {
  return native::cursor::position();
}

void cursor::position(const point& position) {
  native::cursor::position(position);
}

intptr_t cursor::copy_handle() const {
  return native::cursor::copy(data_->handle_);
}

void cursor::hide() {
  native::cursor::hide();
}

void cursor::show() {
  native::cursor::show();
}

std::string cursor::to_string() const {
  return strings::format("[cursor: {}]", data_->name_ != "" ? data_->name_ : strings::full_class_name(*this));
}
