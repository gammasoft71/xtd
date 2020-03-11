#include <xtd/forms/native/cursor.h>
#include "../../../include/xtd/forms/cursor.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

cursor::cursor(intptr_t handle, bool destroyable, const std::string& name) {
  this->data_->handle_ = handle;
  this->data_->destroyable_ = destroyable;
  this->data_->name_ = name;
  this->data_->hot_spot_ = native::cursor::hot_spot(this->data_->handle_);
  this->data_->size_ = native::cursor::size(this->data_->handle_);
}

cursor::cursor() {
  this->data_->handle_ = native::cursor::create();
  this->data_->hot_spot_ = native::cursor::hot_spot(this->data_->handle_);
  this->data_->size_ = native::cursor::size(this->data_->handle_);
}

cursor::~cursor() {
  if (this->data_.use_count() == 1 && this->data_->handle_ && this->data_->destroyable_)
    native::cursor::destroy(this->data_->handle_);
}

point cursor::position() {
  return native::cursor::position();
}

void cursor::position(const point& position) {
  native::cursor::position(position);
}

intptr_t cursor::copy_handle() const {
  return native::cursor::copy(this->data_->handle_);
}

void cursor::hide() {
  native::cursor::hide();
}

void cursor::show() {
  native::cursor::show();
}

std::string cursor::to_string() const {
  return strings::format("[cursor: {}]", this->data_->name_ != "" ? this->data_->name_ : strings::full_class_name(*this));
}
