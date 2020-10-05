#include <xtd/drawing/system_colors.h>
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/text_box.h>
#include <xtd/forms/native/text_box_styles.h>
#include <xtd/forms/native/window_styles.h>
#include "../../../include/xtd/forms/text_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

text_box::text_box() {
  //this->back_color_ = this->default_back_color();
  //this->fore_color_ = this->default_fore_color();
  this->size_ = this->default_size();
}

text_box& text_box::border_style(forms::border_style border_style) {
  if (this->border_style_ != border_style) {
    this->border_style_ = border_style;
    this->recreate_handle();
  }
  return *this;
}

text_box& text_box::multiline(bool value) {
  if (this->multiline_ != value) {
    this->multiline_ = value;
    recreate_handle();
  }
  return *this;
}

text_box& text_box::use_system_password_char(bool value) {
  if (use_system_password_char_ != value) {
    use_system_password_char_ = value;
    recreate_handle();
  }
  return *this;
}

control& text_box::text(const std::string& text) {
  if (this->text_ != text) {
    this->text_ = text;
    native::text_box::text(handle(), this->text_.c_str());
    on_text_changed(event_args::empty);
  }
  return *this;
}

forms::create_params text_box::create_params() const {
  forms::create_params create_params = this->text_box_base::create_params();
  
  create_params.class_name("textbox");
  
  if (this->border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (this->border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);

  if (accepts_return_) create_params.style(create_params.style() | ES_WANTRETURN);
  if (accepts_tab_) create_params.style(create_params.style() | ES_WANTTAB);
  if (multiline_) create_params.style(create_params.style() | ES_MULTILINE);
  if (use_system_password_char_) create_params.style(create_params.style() | ES_PASSWORD);
  if (read_only_) create_params.style(create_params.style() | ES_READONLY);
  if (!word_wrap_) create_params.style(create_params.style() | ES_AUTOHSCROLL);

  return create_params;
}

drawing::size text_box::measure_control() const {
  return drawing::size(this->client_size_.width(), static_cast<int32_t>(this->font().get_height()) + 2 + (this->border_style_ == border_style::none ? 0 : 4));
}

void text_box::append_text(const std::string& value) {
  native::text_box::append(handle_, value);
}

void text_box::select(size_t start, size_t length) {
  text_box_base::select(start, length);  
  native::text_box::select(handle_, selection_start_, selection_length_);
}
