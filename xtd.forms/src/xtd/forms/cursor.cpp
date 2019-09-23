#include <xtd/forms/native/cursor.hpp>
#include "../../../include/xtd/forms/cursor.hpp"

using namespace xtd::drawing;
using namespace xtd::forms;

bool cursor::visible_ = true;

cursor::cursor(intptr_t handle, bool destroyable) {
  this->data_->handle_ = handle;
  this->data_->destroyable_ = destroyable;
  this->data_->hot_spot_ = native::cursor::hot_spot(this->data_->handle_);
}

cursor::cursor() {
  this->data_->handle_ = native::cursor::create();
  this->data_->hot_spot_ = native::cursor::hot_spot(this->data_->handle_);
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

void cursor::visible(bool visible) {
  if (visible_ != visible) {
    visible_ = visible;
    if (visible_)
      native::cursor::show();
    else
    native::cursor::hide();
  }
}
