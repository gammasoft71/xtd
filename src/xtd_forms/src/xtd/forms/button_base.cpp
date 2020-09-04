#include "../../../include/xtd/forms/button_base.h"
#include <xtd/forms/native/button_styles.h>

using namespace xtd;
using namespace xtd::forms;

button_base::button_base() {
  this->auto_size_mode_ = forms::auto_size_mode::grow_only;
  this->size_ = this->default_size();
}

button_base& button_base::flat_style(xtd::forms::flat_style flat_style) {
  if (flat_style_ != flat_style) {
    flat_style_ = flat_style;
    recreate_handle();
  }
  return *this;
}

button_base& button_base::image(const drawing::image& value) {
  if (this->image_ != value) {
    this->image_ = value;
    this->image_list_ = forms::image_list();
    this->image_index_ = -1;
    on_image_changed(xtd::event_args::empty);
  }
  return *this;
}

button_base& button_base::image_align(content_alignment value) {
  if (this->image_align_ != value) {
    this->image_align_ = value;
    if (flat_style_ == xtd::forms::flat_style::system) this->recreate_handle();
    else invalidate();
  }
  return *this;
}

button_base& button_base::image_index(int32_t value) {
 if (this->image_index_ != value) {
   if (value < -1 || value >= image_list_.images().size()) throw std::invalid_argument("Index out of range");
   this->image_index_ = value;
   this->recreate_handle();
 }
  return *this;
}

button_base& button_base::image_list(const forms::image_list& value) {
  if (this->image_list_ != value) {
    this->image_list_ = value;
    this->image_ = drawing::image::empty;
    this->recreate_handle();
  }
  return *this;
}

button_base& button_base::text_align(content_alignment text_align) {
  if (this->text_align_ != text_align) {
    this->text_align_ = text_align;
    if (flat_style_ == xtd::forms::flat_style::system) this->recreate_handle();
    else invalidate();
  }
  return *this;
}

forms::create_params button_base::create_params() const {
  forms::create_params create_params = this->control::create_params();

  if (flat_style_ != xtd::forms::flat_style::system) create_params.style(create_params.style() | BS_OWNERDRAW);

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
