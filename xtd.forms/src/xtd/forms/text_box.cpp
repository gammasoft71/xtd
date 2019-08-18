#include <xtd/drawing/system_colors.hpp>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/text_box.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/text_box.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

text_box::text_box() {
  this->back_color_ = this->default_back_color();
  this->fore_color_ = this->default_fore_color();
}

text_box& text_box::border_style(forms::border_style border_style) {
  if (this->border_style_ != border_style) {
    this->border_style_ = border_style;
    this->recreate_handle();
  }
  return *this;
}

color text_box::default_back_color() const {
  return native::text_box::default_back_color();
}

color text_box::default_fore_color() const {
  return native::text_box::default_fore_color();
}

control& text_box::text(const string& text) {
  if (this->text_ != text) {
    this->text_ = text;
    native::text_box::text(this->handle_, this->text_);
  }
  return *this;
}

void text_box::create_handle() {
  size_t styles = 0;
  size_t ex_styles = 0;
  
  if (this->border_style_ == forms::border_style::fixed_single) styles |= WS_BORDER;
  else if (this->border_style_ == forms::border_style::fixed_3d) ex_styles |= WS_EX_CLIENTEDGE;

  this->handle_ = native::text_box::create(this->parent_->__get_handle__(), this->default_size(), styles, ex_styles);
  this->control::create_handle();
  native::control::back_color(this->handle_, this->back_color());
  native::text_box::text(this->handle_, this->text_);
}
