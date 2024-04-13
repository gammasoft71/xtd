#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/button_base.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/button_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::forms;

struct button_base::data {
  bool auto_ellipsis = false;
  xtd::forms::flat_button_appearance flat_appearance;
  xtd::forms::flat_style flat_style = xtd::forms::flat_style::standard;
  xtd::drawing::image image = xtd::drawing::image::empty;
  xtd::forms::image_list image_list = xtd::forms::image_list::empty;
  int32 image_index = -1;
  content_alignment image_align = content_alignment::middle_center;
  bool is_default = false;
  content_alignment text_align = content_alignment::middle_center;
};


button_base::button_base() noexcept : data_(std::make_shared<data>()) {
  if (application::system_controls()) data_->flat_style = xtd::forms::flat_style::system;
  set_auto_size_mode(forms::auto_size_mode::grow_only);
  set_style(control_styles::user_mouse | control_styles::user_paint, control_appearance() == forms::control_appearance::standard);
}

bool button_base::auto_ellipsis() const noexcept {
  return data_->auto_ellipsis;
}

button_base& button_base::auto_ellipsis(bool auto_ellipsis) {
  data_->auto_ellipsis = auto_ellipsis;
  return *this;
}

bool button_base::auto_size() const noexcept {
  return control::auto_size();
}

control& button_base::auto_size(bool auto_size) {
  control::auto_size(auto_size);
  if (get_state(state::auto_size))
    data_->auto_ellipsis = false;
  return *this;
}

control& button_base::control_appearance(forms::control_appearance value) {
  control::control_appearance(value);
  if (value == forms::control_appearance::system && data_->flat_style != xtd::forms::flat_style::system)
    flat_style(xtd::forms::flat_style::system);
  else if (value == forms::control_appearance::standard && data_->flat_style == xtd::forms::flat_style::system)
    flat_style(xtd::forms::flat_style::standard);
  return *this;
}

const xtd::forms::flat_button_appearance& button_base::flat_appearance() const noexcept {
  return data_->flat_appearance;
}

button_base& button_base::flat_appearance(const xtd::forms::flat_button_appearance& value) {
  if (data_->flat_appearance == value) return *this;
  data_->flat_appearance = value;
  recreate_handle();
  return *this;
}

xtd::forms::flat_style button_base::flat_style() const noexcept {
  return data_->flat_style;
}

button_base& button_base::flat_style(xtd::forms::flat_style value) {
  if (data_->flat_style == value) return *this;
  data_->flat_style = value;
  control_appearance(data_->flat_style == xtd::forms::flat_style::system ? forms::control_appearance::system : forms::control_appearance::standard);
  recreate_handle();
  return *this;
}

const drawing::image& button_base::image() const noexcept {
  return data_->image;
}

button_base& button_base::image(const drawing::image& value) {
  if (data_->image == value) return *this;
  data_->image = value;
  data_->image_list = forms::image_list();
  data_->image_index = -1;
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  on_image_changed(xtd::event_args::empty);
  return *this;
}

content_alignment button_base::image_align() const noexcept {
  return data_->image_align;
}

button_base& button_base::image_align(content_alignment value) {
  if (data_->image_align == value) return *this;
  data_->image_align = value;
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  return *this;
}

int32 button_base::image_index() const noexcept {
  return data_->image_index;
}

button_base& button_base::image_index(int32 value) {
  if (data_->image_index == value) return *this;
  if (value < -1 || static_cast<size_t>(value) >= data_->image_list.images().size()) throw argument_out_of_range_exception {csf_};
  data_->image_index = value;
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  if (value != -1) data_->image = xtd::drawing::image::empty;
  return *this;
}

const forms::image_list& button_base::image_list() const noexcept {
  return data_->image_list;
}

forms::image_list& button_base::image_list() noexcept {
  return data_->image_list;
}

button_base& button_base::image_list(const forms::image_list& value) {
  if (data_->image_list == value) return *this;
  data_->image_list = value;
  data_->image = drawing::image::empty;
  post_recreate_handle();
  return *this;
}

bool button_base::is_default() const noexcept {
  return data_->is_default;
}

button_base& button_base::is_default(bool value) {
  data_->is_default = value;
  return *this;
}

content_alignment button_base::text_align() const noexcept {
  return data_->text_align;
}

button_base& button_base::text_align(content_alignment text_align) {
  if (data_->text_align == text_align) return *this;
  data_->text_align = text_align;
  if (data_->flat_style == xtd::forms::flat_style::system) post_recreate_handle();
  else invalidate();
  return *this;
}

forms::create_params button_base::create_params() const noexcept {
  auto create_params = control::create_params();
  
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

drawing::size button_base::measure_control() const noexcept {
  auto size = control::measure_text() + drawing::size(13, 0);
  if (image().height() > 0 && image().width() > 0) size += image().size() + drawing::size(0, 13);
  return size;
}

void button_base::on_back_color_changed(const event_args& e) {
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  control::on_back_color_changed(e);
}

void button_base::on_enabled_changed(const event_args& e) {
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  control::on_enabled_changed(e);
}

void button_base::on_font_changed(const xtd::event_args& e) {
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  control::on_font_changed(e);
}

void button_base::on_fore_color_changed(const event_args& e) {
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  control::on_fore_color_changed(e);
}

void button_base::on_image_changed(const xtd::event_args& e) {
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  if (can_raise_events()) image_changed(*this, e);
}

void button_base::on_mouse_down(const mouse_event_args& e) {
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  control::on_mouse_down(e);
}

void button_base::on_mouse_enter(const event_args& e) {
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  control::on_mouse_enter(e);
}

void button_base::on_mouse_leave(const event_args& e) {
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  control::on_mouse_leave(e);
}

void button_base::on_mouse_up(const mouse_event_args& e) {
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  control::on_mouse_up(e);
}

void button_base::on_parent_back_color_changed(const event_args& e) {
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  control::on_parent_back_color_changed(e);
}

void button_base::on_parent_fore_color_changed(const event_args& e) {
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  control::on_parent_fore_color_changed(e);
}

void button_base::on_resize(const xtd::event_args& e) {
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  control::on_resize(e);
}

void button_base::on_text_changed(const xtd::event_args& e) {
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
  control::on_text_changed(e);
}

xtd::drawing::rectangle button_base::compute_image_bounds() {return compute_image_bounds({0, 0, width(), height()});}

xtd::drawing::rectangle button_base::compute_image_bounds(const xtd::drawing::rectangle& rectangle) {
  auto image_bounds = xtd::drawing::rectangle {(width() - data_->image.width()) / 2, (height() - data_->image.height()) / 2, data_->image.width(), data_->image.height()};
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

text_format_flags button_base::to_text_format_flags(content_alignment text_align) {
  auto flags = text_format_flags::default_format;
  
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
