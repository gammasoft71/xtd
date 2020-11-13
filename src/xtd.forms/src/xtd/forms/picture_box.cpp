#include <xtd/forms/native/control.h>
#include <xtd/forms/native/picture_box.h>
#include <xtd/forms/native/window_styles.h>
#include <xtd/forms/native/static_styles.h>
#include "../../../include/xtd/forms/picture_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

picture_box::picture_box() {
  this->size_ = this->default_size();
}

picture_box& picture_box::border_style(forms::border_style border_style) {
  if (this->border_style_ != border_style) {
    this->border_style_ = border_style;
    this->recreate_handle();
  }
  return *this;
}

picture_box& picture_box::image(const drawing::image& image) {
  if (!this->image_.has_value() || this->image_.value().handle() != image.handle()) {
    if (image != drawing::image::empty) {
      this->image_ = image;
      native::picture_box::image(this->handle(), this->image_.value());
    } else {
      this->image_.reset();
      native::picture_box::clear(this->handle());
    }
  }
  return *this;
}

picture_box& picture_box::image(nullptr_t) {
  if (this->image_.has_value()) {
    this->image_.reset();
    native::picture_box::clear(this->handle());
  }
  return *this;
}

picture_box& picture_box::size_mode(picture_box_size_mode size_mode) {
  if (this->size_mode_ != size_mode) {
    this->size_mode_ = size_mode;
    this->recreate_handle();
  }
  return *this;
}

forms::create_params picture_box::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("picturebox");
  create_params.style(create_params.style() | SS_BITMAP);
  
  if (this->border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (this->border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  
  switch (this->size_mode_) {
    case picture_box_size_mode::normal: create_params.style(create_params.style() | SS_BITMAP_NORMAL); break;
    case picture_box_size_mode::stretch_image: create_params.style(create_params.style() | SS_BITMAP_STRETCH); break;
    case picture_box_size_mode::auto_size: create_params.style(create_params.style() | SS_BITMAP_AUTOSIZE); break;
    case picture_box_size_mode::center_image: create_params.style(create_params.style() | SS_BITMAP_CENTER); break;
    case picture_box_size_mode::zoom: create_params.style(create_params.style() | SS_BITMAP_ZOOM); break;
  }
  
  return create_params;
}

drawing::size picture_box::measure_control() const {
  drawing::size size;
  size = image_.has_value() ? image_.value().size() : drawing::size(0, 0);
  /// @todo add locatoin
  return size;
}

void picture_box::on_handle_created(const event_args &e) {
  this->control::on_handle_created(e);
  if (this->image_.has_value() && this->image_.value() != drawing::image::empty)
    native::picture_box::image(this->handle(), this->image_.value());
}

