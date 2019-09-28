#include "../../../include/xtd/forms/button_base.hpp"
#include <xtd/forms/native/window_button.hpp>

using namespace xtd;
using namespace xtd::forms;

button_base::button_base() {
  this->auto_size_mode_ = forms::auto_size_mode::grow_only;
  this->size_ = this->default_size();
}

button_base& button_base::text_align(content_alignment text_align) {
  if (this->text_align_ != text_align)
    this->text_align_ = text_align;
    this->recreate_handle();
  return *this;
}

forms::create_params button_base::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("button");
  
  switch (this->text_align_) {
    case content_alignment::top_left: create_params.style(create_params.style() | BS_TOP | BS_LEFT); break;
    case content_alignment::top_center: create_params.style(create_params.style() | BS_TOP | BS_CENTER); break;
    case content_alignment::top_right: create_params.style(create_params.style() | BS_TOP | BS_RIGHT); break;
    case content_alignment::middle_left: create_params.style(create_params.style() | BS_VCENTER | BS_LEFT); break;
    case content_alignment::middle_center: create_params.style(create_params.style() | BS_VCENTER | BS_CENTER); break;
    case content_alignment::middle_right: create_params.style(create_params.style() | BS_VCENTER | BS_RIGHT); break;
    case content_alignment::bottom_left: create_params.style(create_params.style() | BS_BOTTOM | BS_LEFT); break;
    case content_alignment::bottom_center: create_params.style(create_params.style() | BS_BOTTOM | BS_CENTER); break;
    case content_alignment::bottom_right: create_params.style(create_params.style() | BS_BOTTOM | BS_RIGHT); break;
    default: break;
  }

  return create_params;
}

drawing::size button_base::measure_control() const {
  return this->control::measure_text() + drawing::size(13, 0);
}

