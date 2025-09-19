#include "../../../include/xtd/forms/control_paint.hpp"
#include "../../../include/xtd/forms/picture_box.hpp"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/picture_box>
#include <xtd/forms/native/window_styles>
#include <xtd/forms/native/static_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/optional>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::helpers;

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

struct picture_box::data {
  forms::border_sides border_sides = forms::border_sides::all;
  std::optional<forms::border_style> border_style;
  std::optional<drawing::image> image;
  picture_box_size_mode size_mode = picture_box_size_mode::normal;
};

picture_box::picture_box() : data_(xtd::new_sptr<data>()) {
  set_can_focus(false);
  set_style(control_styles::opaque | control_styles::selectable, false);
  set_style(control_styles::optimized_double_buffer | control_styles::supports_transparent_back_color, true);
}

forms::border_sides picture_box::border_sides() const noexcept {
  return data_->border_sides;
}

picture_box& picture_box::border_sides(forms::border_sides border_sides) {
  if (data_->border_sides == border_sides) return *this;
  data_->border_sides = border_sides;
  refresh();
  return *this;
}

forms::border_style picture_box::border_style() const noexcept {
  return data_->border_style.value_or(forms::border_style::none);
}

picture_box& picture_box::border_style(forms::border_style border_style) {
  if (this->border_style() == border_style) return *this;
  data_->border_style = border_style;
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) post_recreate_handle();
  refresh();
  return *this;
}

picture_box& picture_box::border_style(std::nullptr_t) {
  if (data_->border_style) return *this;
  data_->border_style.reset();
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) post_recreate_handle();
  refresh();
  return *this;
}

std::optional<drawing::image> picture_box::image() const noexcept {
  return data_->image;
}

picture_box& picture_box::image(const drawing::image& image) {
  if (data_->image.has_value() && data_->image.value().handle() == image.handle()) return *this;
  if (image == drawing::image::empty) return this->image(nullptr);
  data_->image = image;
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) native::picture_box::image(handle(), data_->image.value());
  refresh();
  return *this;
}

picture_box& picture_box::image(std::nullptr_t) {
  if (!data_->image.has_value()) return *this;
  data_->image.reset();
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) native::picture_box::reset(handle());
  refresh();
  return *this;
}

picture_box_size_mode picture_box::size_mode() const noexcept {
  return data_->size_mode;
}

picture_box& picture_box::size_mode(picture_box_size_mode size_mode) {
  if (data_->size_mode != size_mode) {
    data_->size_mode = size_mode;
    post_recreate_handle();
  }
  return *this;
}

picture_box picture_box::create() {
  return picture_box {};
}

picture_box picture_box::create(const drawing::point& location) {
  auto result = picture_box {};
  result.location(location);
  return result;
}

picture_box picture_box::create(const drawing::point& location, const drawing::size& size) {
  auto result = picture_box {};
  result.location(location);
  result.size(size);
  return result;
}

picture_box picture_box::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = picture_box {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

picture_box picture_box::create(const xtd::drawing::image& image) {
  auto result = picture_box {};
  result.image(image);
  return result;
}

picture_box picture_box::create(const xtd::drawing::image& image, const drawing::point& location) {
  auto result = picture_box {};
  result.image(image);
  result.location(location);
  return result;
}

picture_box picture_box::create(const xtd::drawing::image& image, const drawing::point& location, const drawing::size& size) {
  auto result = picture_box {};
  result.image(image);
  result.location(location);
  result.size(size);
  return result;
}

picture_box picture_box::create(const xtd::drawing::image& image, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = picture_box {};
  result.image(image);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

picture_box picture_box::create(const control& parent) {
  auto result = picture_box {};
  result.parent(parent);
  return result;
}

picture_box picture_box::create(const control& parent, const drawing::point& location) {
  auto result = picture_box {};
  result.parent(parent);
  result.location(location);
  return result;
}

picture_box picture_box::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = picture_box {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

picture_box picture_box::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = picture_box {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

picture_box picture_box::create(const control& parent, const xtd::drawing::image& image) {
  auto result = picture_box {};
  result.parent(parent);
  result.image(image);
  return result;
}

picture_box picture_box::create(const control& parent, const xtd::drawing::image& image, const drawing::point& location) {
  auto result = picture_box {};
  result.parent(parent);
  result.image(image);
  result.location(location);
  return result;
}

picture_box picture_box::create(const control& parent, const xtd::drawing::image& image, const drawing::point& location, const drawing::size& size) {
  auto result = picture_box {};
  result.parent(parent);
  result.image(image);
  result.location(location);
  result.size(size);
  return result;
}

picture_box picture_box::create(const control& parent, const xtd::drawing::image& image, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = picture_box {};
  result.parent(parent);
  result.image(image);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

forms::create_params picture_box::create_params() const noexcept {
  auto create_params = control::create_params();
  
  create_params.class_name("picturebox");
  create_params.style(create_params.style() | SS_BITMAP);
  
  if (control_appearance() == forms::control_appearance::system) {
    if (border_style() == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
    else if (border_style() != forms::border_style::none) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  }
  
  if (control_appearance() != forms::control_appearance::system) create_params.style(create_params.style() | SS_OWNERDRAW);
  
  switch (data_->size_mode) {
    case picture_box_size_mode::normal: create_params.style(create_params.style() | SS_BITMAP_NORMAL); break;
    case picture_box_size_mode::stretch_image: create_params.style(create_params.style() | SS_BITMAP_STRETCH); break;
    case picture_box_size_mode::auto_size: create_params.style(create_params.style() | SS_BITMAP_AUTOSIZE); break;
    case picture_box_size_mode::center_image: create_params.style(create_params.style() | SS_BITMAP_CENTER); break;
    case picture_box_size_mode::zoom: create_params.style(create_params.style() | SS_BITMAP_ZOOM); break;
  }
  
  return create_params;
}

xtd::uptr<xtd::object> picture_box::clone() const {
  auto result = xtd::new_uptr<picture_box>(*this);
  if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).chars().c_str());
  return result;
}

drawing::size picture_box::measure_control() const noexcept {
  auto size = data_->image.has_value() ? data_->image.value().size() : drawing::size(0, 0);
  /// @todo add location
  return size;
}

void picture_box::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  if (data_->image.has_value() && data_->image.value() != drawing::image::empty && control_appearance() == forms::control_appearance::system)
    native::picture_box::image(handle(), data_->image.value());
}

void picture_box::on_paint(paint_event_args& e) {
  control::on_paint(e);
  if (control_appearance() != forms::control_appearance::standard) return;
  if (image().has_value()) control_paint::draw_image(e.graphics(), image().value(), e.clip_rectangle(), to_image_layout(size_mode()));
  control_paint::draw_border_from_back_color(*this, e.graphics(), border_style(), border_sides(), back_color(), e.clip_rectangle());
}
