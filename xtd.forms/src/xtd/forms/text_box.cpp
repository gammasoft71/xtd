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
  this->size_ = this->default_size();
}

text_box& text_box::border_style(forms::border_style border_style) {
  if (this->border_style_ != border_style) {
    this->border_style_ = border_style;
    this->recreate_handle();
  }
  return *this;
}

control& text_box::text(const string& text) {
  if (this->text_ != text) {
    this->text_ = text;
    native::text_box::text(this->handle_, this->text_);
  }
  return *this;
}

forms::create_params text_box::create_params() const {
  forms::create_params create_params = this->text_box_base::create_params();
  
  create_params.class_name("textbox");
  
  if (this->border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (this->border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  
  return create_params;
}

drawing::size text_box::measure_control() const {
  return drawing::size(this->client_size_.width(), static_cast<int32_t>(this->font().get_height()) + 2 + (this->border_style_ == border_style::none ? 0 : 4));
}
