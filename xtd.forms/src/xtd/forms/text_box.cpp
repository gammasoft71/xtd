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
  this->control::data_->back_color_ = this->default_back_color();
  this->control::data_->fore_color_ = this->default_fore_color();
  this->control::data_->size_ = this->default_size();
}

text_box& text_box::border_style(forms::border_style border_style) {
  if (this->data_->border_style_ != border_style) {
    this->data_->border_style_ = border_style;
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
  if (this->control::data_->text_ != text) {
    this->control::data_->text_ = text;
    native::text_box::text(this->control::data_->handle_, this->control::data_->text_);
  }
  return *this;
}

forms::create_params text_box::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("EDIT");
  
  if (this->data_->border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (this->data_->border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  
  return create_params;
}
