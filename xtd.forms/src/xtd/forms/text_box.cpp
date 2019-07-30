#include <xtd/drawing/system_colors.hpp>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/text_box.hpp>
#include "../../../include/xtd/forms/text_box.hpp"

using namespace std;
using namespace xtd::drawing;
using namespace xtd::forms;

text_box::text_box() {
  this->back_color_ = this->default_back_color();
  this->fore_color_ = this->default_fore_color();
}

color text_box::default_back_color() const {
  return native::text_box::default_back_color();
}

color text_box::default_fore_color() const {
  return native::text_box::default_fore_color();
}

void text_box::text(const string& text) {
  if (this->text_ != text) {
    this->text_ = text;
    native::text_box::text(this->handle_, this->text_);
  }
}

void text_box::create_handle() {
  this->handle_ = native::text_box::create(this->parent_->__get_handle__(), this->default_size());
  this->control::create_handle();
  native::control::back_color(this->handle_, this->back_color());
  native::text_box::text(this->handle_, this->text_);
}
