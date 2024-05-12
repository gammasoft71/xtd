#include "../../../include/xtd/forms/cursor.h"
#include "../../../include/xtd/forms/cursors.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/cursor>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/optional>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
  auto current_cursor = optional<cursor> {};
}

struct cursor::data {
  intptr handle_ = 0;
  bool destroyable_ = true;
  xtd::drawing::point hot_spot_;
  xtd::ustring name_;
  xtd::drawing::size size_;
  any tag_;
};

cursor cursor::none(0, false, "none");

cursor::cursor(intptr handle, bool destroyable, const xtd::ustring& name) : data_(make_shared<data>()) {
  data_->handle_ = handle;
  data_->destroyable_ = destroyable;
  data_->name_ = name;
  data_->hot_spot_ = native::cursor::hot_spot(data_->handle_);
  data_->size_ = native::cursor::size(data_->handle_);
}

cursor::cursor() : data_(make_shared<data>()) {
  data_->handle_ = native::cursor::create();
  data_->hot_spot_ = native::cursor::hot_spot(data_->handle_);
  data_->size_ = native::cursor::size(data_->handle_);
}

cursor::cursor(intptr handle) : cursor(handle, false, ustring::empty_string) {
}

cursor::cursor(const bitmap& bitmap, const xtd::drawing::point& hot_spot) : data_(make_shared<data>()) {
  data_->handle_ = native::cursor::create(bitmap, hot_spot);
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

intptr cursor::handle() const noexcept {
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

any cursor::tag() const noexcept {
  return data_->tag_;
}

void cursor::tag(any tag) {
  data_->tag_ = tag;
}

intptr cursor::copy_handle() const {
  return native::cursor::copy(data_->handle_);
}

bool cursor::equals(const cursor& value) const noexcept {
  return data_ == value.data_ || (!data_->name_.empty() && data_->name_ == value.data_->name_);
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
  return ustring::format("[cursor: {}]", data_->name_ != "" ? data_->name_ : get_type().full_name());
}
