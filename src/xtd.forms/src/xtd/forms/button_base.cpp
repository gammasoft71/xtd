#include "../../../include/xtd/forms/button_base.h"
#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/button_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms;

button_base::button_base() {
  set_auto_size_mode(forms::auto_size_mode::grow_only);
  set_style(control_styles::user_mouse | control_styles::user_paint, control_appearance() == forms::control_appearance::standard);
}

control& button_base::control_appearance(forms::control_appearance value) {
  control::control_appearance(value);
  if (value == forms::control_appearance::system && data_->flat_style != xtd::forms::flat_style::system)
    flat_style(xtd::forms::flat_style::system);
  else if (value == forms::control_appearance::standard && data_->flat_style == xtd::forms::flat_style::system)
    flat_style(xtd::forms::flat_style::standard);
  return *this;
}

button_base& button_base::flat_appearance(const xtd::forms::flat_button_appearance& value) {
  if (data_->flat_appearance != value) {
    data_->flat_appearance = value;
    recreate_handle();
  }
  return *this;
}

button_base& button_base::flat_style(xtd::forms::flat_style value) {
  if (data_->flat_style != value) {
    data_->flat_style = value;
    control_appearance(data_->flat_style == xtd::forms::flat_style::system ? forms::control_appearance::system : forms::control_appearance::standard);
    recreate_handle();
  }
  return *this;
}

button_base& button_base::image(const drawing::image& value) {
  if (data_->image != value) {
    data_->image = value;
    data_->image_list = forms::image_list();
    data_->image_index = -1;
    if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
    on_image_changed(xtd::event_args::empty);
  }
  return *this;
}

button_base& button_base::image_align(content_alignment value) {
  if (data_->image_align != value) {
    data_->image_align = value;
    if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  }
  return *this;
}

button_base& button_base::image_index(int32_t value) {
  if (data_->image_index != value) {
    if (value < -1 || static_cast<size_t>(value) >= data_->image_list.images().size()) throw argument_out_of_range_exception(current_stack_frame_);
    data_->image_index = value;
    if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
    if (value != -1) data_->image = xtd::drawing::image::empty;
  }
  return *this;
}

button_base& button_base::image_list(const forms::image_list& value) {
  if (data_->image_list != value) {
    data_->image_list = value;
    data_->image = drawing::image::empty;
    post_recreate_handle();
  }
  return *this;
}

button_base& button_base::text_align(content_alignment text_align) {
  if (data_->text_align != text_align) {
    data_->text_align = text_align;
    if (data_->flat_style == xtd::forms::flat_style::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

forms::create_params button_base::create_params() const {
  forms::create_params create_params = control::create_params();
  
  if (data_->flat_style != xtd::forms::flat_style::system) create_params.style(create_params.style() | BS_OWNERDRAW);
  
  switch (data_->text_align) {
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
  return control::measure_text() + drawing::size(13, 0);
}

text_format_flags button_base::to_text_format_flags(content_alignment text_align) {
  text_format_flags flags = text_format_flags::default_format;
  
  switch (text_align) {
    case content_alignment::top_left: flags |= text_format_flags::top | text_format_flags::left; break;
    case content_alignment::top_center: flags |= text_format_flags::top | text_format_flags::horizontal_center; break;
    case content_alignment::top_right: flags |= text_format_flags::top | text_format_flags::right; break;
    case content_alignment::middle_left: flags |= text_format_flags::vertical_center | text_format_flags::left; break;
    case content_alignment::middle_center: flags |= text_format_flags::vertical_center | text_format_flags::horizontal_center; break;
    case content_alignment::middle_right: flags |= text_format_flags::vertical_center | text_format_flags::right; break;
    case content_alignment::bottom_left: flags |= text_format_flags::bottom | text_format_flags::left; break;
    case content_alignment::bottom_center: flags |= text_format_flags::bottom | text_format_flags::horizontal_center; break;
    case content_alignment::bottom_right: flags |= text_format_flags::bottom | text_format_flags::right; break;
    default: break;
  }
  
  return flags;
}

xtd::drawing::rectangle button_base::compute_image_bounds(const xtd::drawing::rectangle& rectangle) {
  xtd::drawing::rectangle image_bounds = {(width() - data_->image.width()) / 2, (height() - data_->image.height()) / 2, data_->image.width(), data_->image.height()};
  auto image_margin = 4;
  switch (data_->image_align) {
    case content_alignment::top_left: image_bounds = {rectangle.x() + image_margin, rectangle.y() + image_margin, data_->image.width(), data_->image.height()}; break;
    case content_alignment::top_center: image_bounds = {(rectangle.width() - data_->image.width()) / 2, rectangle.y() + image_margin, data_->image.width(), data_->image.height()}; break;
    case content_alignment::top_right: image_bounds = {rectangle.width() - data_->image.width() - image_margin, rectangle.y() + image_margin, data_->image.width(), data_->image.height()}; break;
    case content_alignment::middle_left: image_bounds = {rectangle.x() + image_margin, (rectangle.height() - data_->image.height()) / 2, data_->image.width(), data_->image.height()}; break;
    case content_alignment::middle_center: image_bounds = {(rectangle.width() - data_->image.width()) / 2, (rectangle.height() - data_->image.height()) / 2, data_->image.width(), data_->image.height()}; break;
    case content_alignment::middle_right: image_bounds = {rectangle.width() - data_->image.width() - image_margin, (rectangle.height() - data_->image.height()) / 2, data_->image.width(), data_->image.height()}; break;
    case content_alignment::bottom_left: image_bounds = {rectangle.x() + image_margin, rectangle.height() - data_->image.height() - image_margin, data_->image.width(), data_->image.height()}; break;
    case content_alignment::bottom_center: image_bounds = {(rectangle.width() - data_->image.width()) / 2, rectangle.height() - data_->image.height() - image_margin, data_->image.width(), data_->image.height()}; break;
    case content_alignment::bottom_right: image_bounds = {rectangle.width() - data_->image.width() - image_margin, rectangle.height() - data_->image.height() - image_margin, data_->image.width(), data_->image.height()}; break;
    default: break;
  }
  return image_bounds;
}
