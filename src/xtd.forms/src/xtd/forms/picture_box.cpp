#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/picture_box.h>
#include <xtd/forms/native/window_styles.h>
#include <xtd/forms/native/static_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/picture_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace {
  static xtd::forms::image_layout to_image_layout(picture_box_size_mode size_mode) {
    switch (size_mode) {
      case picture_box_size_mode::normal: return xtd::forms::image_layout::none;
      case picture_box_size_mode::stretch_image: return xtd::forms::image_layout::stretch;
      case picture_box_size_mode::auto_size: return xtd::forms::image_layout::none;
      case picture_box_size_mode::center_image: return xtd::forms::image_layout::center;
      case picture_box_size_mode::zoom: return xtd::forms::image_layout::zoom;
    }
    return xtd::forms::image_layout::none;
  }
}

picture_box::picture_box() {
  set_can_focus(false);
  set_style(control_styles::opaque | control_styles::selectable, false);
  set_style(control_styles::optimized_double_buffer|control_styles::supports_transparent_back_color, true);
}

picture_box& picture_box::border_sides(forms::border_sides border_sides) {
  if (border_sides_ != border_sides) {
    border_sides_ = border_sides;
    if (control_appearance() == forms::control_appearance::standard) invalidate();
  }
  return *this;
}

picture_box& picture_box::border_style(forms::border_style border_style) {
  if (border_style_ != border_style) {
    border_style_ = border_style;
    if (is_handle_created() && control_appearance() == forms::control_appearance::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

picture_box& picture_box::image(const drawing::image& image) {
  if (!image_.has_value() || image_.value().handle() != image.handle()) {
    if (image == drawing::image::empty)
      this->image(nullptr);
    else {
      image_ = image;
      if (is_handle_created() && control_appearance() == forms::control_appearance::system) native::picture_box::image(handle(), image_.value());
      else invalidate();
    }
  }
  return *this;
}

picture_box& picture_box::image(std::nullptr_t) {
  if (image_.has_value()) {
    image_.reset();
    if (is_handle_created() && control_appearance() == forms::control_appearance::system) native::picture_box::reset(handle());
    else invalidate();
  }
  return *this;
}

picture_box& picture_box::size_mode(picture_box_size_mode size_mode) {
  if (size_mode_ != size_mode) {
    size_mode_ = size_mode;
    post_recreate_handle();
  }
  return *this;
}

forms::create_params picture_box::create_params() const noexcept {
  forms::create_params create_params = control::create_params();
  
  create_params.class_name("picturebox");
  create_params.style(create_params.style() | SS_BITMAP);
  
  if (control_appearance() == forms::control_appearance::system) {
    if (border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
    else if (border_style_ != forms::border_style::none) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
    
    switch (size_mode_) {
      case picture_box_size_mode::normal: create_params.style(create_params.style() | SS_BITMAP_NORMAL); break;
      case picture_box_size_mode::stretch_image: create_params.style(create_params.style() | SS_BITMAP_STRETCH); break;
      case picture_box_size_mode::auto_size: create_params.style(create_params.style() | SS_BITMAP_AUTOSIZE); break;
      case picture_box_size_mode::center_image: create_params.style(create_params.style() | SS_BITMAP_CENTER); break;
      case picture_box_size_mode::zoom: create_params.style(create_params.style() | SS_BITMAP_ZOOM); break;
    }
  }
  
  return create_params;
}

drawing::size picture_box::measure_control() const noexcept {
  drawing::size size;
  size = image_.has_value() ? image_.value().size() : drawing::size(0, 0);
  /// @todo add location
  return size;
}

void picture_box::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  if (image_.has_value() && image_.value() != drawing::image::empty && control_appearance() == forms::control_appearance::system)
    native::picture_box::image(handle(), image_.value());
}

void picture_box::on_paint(paint_event_args& e) {
  control::on_paint(e);
  if (control_appearance() == forms::control_appearance::standard) {
    if (image().has_value())
      control_paint::draw_image(e.graphics(), image().value(), e.clip_rectangle(), to_image_layout(size_mode()));
    control_paint::draw_border_from_back_color(*this, e.graphics(), border_style(), border_sides(), back_color(), e.clip_rectangle());
  }
}
