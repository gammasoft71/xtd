#include <xtd/forms/native/control.h>
#include <xtd/forms/native/label.h>
#include <xtd/forms/native/static_styles.h>
#include <xtd/forms/native/window_styles.h>
#include "../../../include/xtd/forms/label.h"

using namespace xtd;
using namespace xtd::forms;

label::label() {
  this->can_focus_ = false;
  this->size_ = this->default_size();
}

label& label::border_style(forms::border_style border_style) {
  if (this->border_style_ != border_style) {
    this->border_style_ = border_style;
    this->recreate_handle();
  }
  return *this;
}

label& label::text_align(content_alignment text_align) {
  if (this->text_align_ != text_align)
    this->text_align_ = text_align;
    this->recreate_handle();
  return *this;
}

forms::create_params label::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("label");
  create_params.style(create_params.style() | SS_LEFT);

  if (this->border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (this->border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  
  switch (this->text_align_) {
    case content_alignment::top_left: create_params.style(create_params.style() | SS_TOP | SS_LEFT); break;
    case content_alignment::top_center: create_params.style(create_params.style() | SS_TOP  | SS_CENTER); break;
    case content_alignment::top_right: create_params.style(create_params.style() | SS_TOP  | SS_RIGHT); break;
    case content_alignment::middle_left: create_params.style(create_params.style() | SS_VCENTER  | SS_LEFT); break;
    case content_alignment::middle_center: create_params.style(create_params.style() | SS_VCENTER | SS_CENTER); break;
    case content_alignment::middle_right: create_params.style(create_params.style() | SS_VCENTER | SS_RIGHT); break;
    case content_alignment::bottom_left: create_params.style(create_params.style() | SS_BOTTOM | SS_LEFT); break;
    case content_alignment::bottom_center: create_params.style(create_params.style() | SS_BOTTOM | SS_CENTER); break;
    case content_alignment::bottom_right: create_params.style(create_params.style() | SS_BOTTOM | SS_RIGHT); break;
    default: break;
  }

  return create_params;
}

drawing::size label::measure_control() const {
  return this->control::measure_text() + drawing::size(this->border_style_ == border_style::none ? 0 : 4, this->border_style_ == border_style::none ? 0 : 4);
}
