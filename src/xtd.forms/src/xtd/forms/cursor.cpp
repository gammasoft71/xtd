#include "../../../include/xtd/forms/cursor.hpp"
#include "../../../include/xtd/forms/cursors.hpp"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/cursor>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/optional>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
  auto current_cursor = std::optional<cursor> {};
}

struct cursor::data {
  intptr handle = 0;
  bool destroyable = true;
  xtd::drawing::point hot_spot;
  xtd::string name;
  xtd::drawing::size size;
  std::any tag;
};

cursor cursor::none(0, false, "none");

cursor::cursor(intptr handle, bool destroyable, const xtd::string& name) : data_(xtd::new_sptr<data>()) {
  data_->handle = handle;
  data_->destroyable = destroyable;
  data_->name = name;
  data_->hot_spot = native::cursor::hot_spot(data_->handle);
  data_->size = native::cursor::size(data_->handle);
}

cursor::cursor() : data_(xtd::new_sptr<data>()) {
  data_->handle = native::cursor::create();
  data_->hot_spot = native::cursor::hot_spot(data_->handle);
  data_->size = native::cursor::size(data_->handle);
}

cursor::cursor(intptr handle) : cursor(handle, false, string::empty_string) {
}

cursor::cursor(const bitmap& bitmap, const xtd::drawing::point& hot_spot) : data_(xtd::new_sptr<data>()) {
  data_->handle = native::cursor::create(bitmap, hot_spot);
  data_->hot_spot = hot_spot;
  data_->size = native::cursor::size(data_->handle);
}

cursor::~cursor() {
  if (data_.use_count() == 1 && data_->handle && data_->destroyable)
    native::cursor::destroy(data_->handle);
}

void cursor::current(const cursor& cursor) {
  current_cursor = cursor;
  native::cursor::current(cursor.data_->name == "default_cursor" ? 0 : cursor.data_->handle);
}

cursor cursor::current() {
  return current_cursor.value_or(none);
}

intptr cursor::handle() const noexcept {
  return data_->handle;
}

drawing::point cursor::hot_spot() const noexcept {
  return data_->hot_spot;
}

point cursor::position() {
  return native::cursor::position();
}

void cursor::position(const point& position) {
  native::cursor::position(position);
}

drawing::size cursor::size() const noexcept {
  return data_->size;
}

std::any cursor::tag() const noexcept {
  return data_->tag;
}

void cursor::tag(std::any tag) {
  data_->tag = tag;
}

intptr cursor::copy_handle() const {
  return native::cursor::copy(data_->handle);
}

bool cursor::equals(const object& obj) const noexcept {
  return is<cursor>(obj) && equals(static_cast<const cursor&>(obj));
}

bool cursor::equals(const cursor& value) const noexcept {
  if (!string::is_empty(data_->name)) return data_->name == value.data_->name;
  return data_->handle == value.data_->handle;
}

xtd::size cursor::get_hash_code() const noexcept {
  if (!string::is_empty(data_->name)) return hash_code::combine(data_->name);
  return hash_code::combine(data_->handle);
}

string cursor::to_string() const noexcept {
  return string::format("[cursor: {}]", data_->name != "" ? data_->name : get_type().full_name());
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
