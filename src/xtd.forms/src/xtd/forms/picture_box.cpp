#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/picture_box.h>
#include <xtd/forms/native/window_styles.h>
#include <xtd/forms/native/static_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/picture_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

picture_box::picture_box() {
  size_ = default_size();
}

picture_box& picture_box::border_style(forms::border_style border_style) {
  if (border_style_ != border_style) {
    border_style_ = border_style;
    recreate_handle();
  }
  return *this;
}

picture_box& picture_box::image(const drawing::image& image) {
  if (!image_.has_value() || image_.value().handle() != image.handle()) {
    if (image != drawing::image::empty) {
      image_ = image;
      native::picture_box::image(handle(), image_.value());
    } else {
      image_.reset();
      native::picture_box::reset(handle());
    }
  }
  return *this;
}

picture_box& picture_box::image(nullptr_t) {
  if (image_.has_value()) {
    image_.reset();
    native::picture_box::reset(handle());
  }
  return *this;
}

picture_box& picture_box::size_mode(picture_box_size_mode size_mode) {
  if (size_mode_ != size_mode) {
    size_mode_ = size_mode;
    recreate_handle();
  }
  return *this;
}

forms::create_params picture_box::create_params() const {
  forms::create_params create_params = control::create_params();
  
  create_params.class_name("picturebox");
  create_params.style(create_params.style() | SS_BITMAP);
  
  if (border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  
  switch (size_mode_) {
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
  /// @todo add location
  return size;
}

void picture_box::on_handle_created(const event_args &e) {
  control::on_handle_created(e);
  if (image_.has_value() && image_.value() != drawing::image::empty)
    native::picture_box::image(handle(), image_.value());
}

