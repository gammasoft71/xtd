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
  static auto to_image_layout(picture_box_size_mode size_mode) -> image_layout {
    switch (size_mode) {
      case picture_box_size_mode::normal: return image_layout::none;
      case picture_box_size_mode::stretch_image: return image_layout::stretch;
      case picture_box_size_mode::auto_size: return image_layout::none;
      case picture_box_size_mode::center_image: return image_layout::center;
      case picture_box_size_mode::zoom: return image_layout::zoom;
    }
    return image_layout::none;
  }
}

struct picture_box::data {
  xtd::forms::border_sides border_sides = forms::border_sides::all;
  std::optional<xtd::forms::border_style> border_style;
  std::optional<xtd::drawing::image> image;
  picture_box_size_mode size_mode = picture_box_size_mode::normal;
};

picture_box::picture_box() : data_(xtd::new_sptr<data>()) {
  set_can_focus(false);
  set_style(control_styles::opaque | control_styles::selectable, false);
  set_style(control_styles::optimized_double_buffer | control_styles::supports_transparent_back_color, true);
}

auto picture_box::border_sides() const noexcept -> xtd::forms::border_sides {
  return data_->border_sides;
}

auto picture_box::border_sides(forms::border_sides value) -> picture_box& {
  if (data_->border_sides == value) return *this;
  data_->border_sides = value;
  refresh();
  return *this;
}

auto picture_box::border_style() const noexcept -> xtd::forms::border_style {
  return data_->border_style.value_or(forms::border_style::none);
}

auto picture_box::border_style(forms::border_style value) -> picture_box& {
  if (this->border_style() == value) return *this;
  data_->border_style = value;
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) post_recreate_handle();
  refresh();
  return *this;
}

auto picture_box::border_style(null_ptr) -> picture_box& {
  if (data_->border_style) return *this;
  data_->border_style.reset();
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) post_recreate_handle();
  refresh();
  return *this;
}

auto picture_box::image() const noexcept -> std::optional<xtd::drawing::image> {
  return data_->image;
}

auto picture_box::image(const xtd::drawing::image& image) -> picture_box& {
  if (data_->image.has_value() && data_->image->handle() == image.handle()) return *this;
  if (image == xtd::drawing::image::empty) return this->image(nullptr);
  data_->image = image;
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) native::picture_box::image(handle(), *data_->image);
  refresh();
  return *this;
}

auto picture_box::image(null_ptr) -> picture_box& {
  if (!data_->image.has_value()) return *this;
  data_->image.reset();
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) native::picture_box::reset(handle());
  refresh();
  return *this;
}

auto picture_box::size_mode() const noexcept -> picture_box_size_mode {
  return data_->size_mode;
}

auto picture_box::size_mode(picture_box_size_mode value) -> picture_box& {
  if (data_->size_mode != value) {
    data_->size_mode = value;
    post_recreate_handle();
  }
  return *this;
}

auto picture_box::create() -> picture_box {
  return picture_box {};
}

auto picture_box::create(const xtd::drawing::point& location) -> picture_box {
  auto result = picture_box {};
  result.location(location);
  return result;
}

auto picture_box::create(const xtd::drawing::point& location, const xtd::drawing::size& size) -> picture_box {
  auto result = picture_box {};
  result.location(location);
  result.size(size);
  return result;
}

auto picture_box::create(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> picture_box {
  auto result = picture_box {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

auto picture_box::create(const xtd::drawing::image& image) -> picture_box {
  auto result = picture_box {};
  result.image(image);
  return result;
}

auto picture_box::create(const xtd::drawing::image& image, const xtd::drawing::point& location) -> picture_box {
  auto result = picture_box {};
  result.image(image);
  result.location(location);
  return result;
}

auto picture_box::create(const xtd::drawing::image& image, const xtd::drawing::point& location, const xtd::drawing::size& size) -> picture_box {
  auto result = picture_box {};
  result.image(image);
  result.location(location);
  result.size(size);
  return result;
}

auto picture_box::create(const xtd::drawing::image& image, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> picture_box {
  auto result = picture_box {};
  result.image(image);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

auto picture_box::create(const xtd::drawing::image& image, picture_box_size_mode size_mode) -> picture_box {
  auto result = picture_box {};
  result.image(image);
  result.size_mode(size_mode);
  return result;
}

auto picture_box::create(const xtd::drawing::image& image, picture_box_size_mode size_mode, const xtd::drawing::point& location) -> picture_box {
  auto result = picture_box {};
  result.image(image);
  result.size_mode(size_mode);
  result.location(location);
  return result;
}

auto picture_box::create(const xtd::drawing::image& image, picture_box_size_mode size_mode, const xtd::drawing::point& location, const xtd::drawing::size& size) -> picture_box {
  auto result = picture_box {};
  result.image(image);
  result.size_mode(size_mode);
  result.location(location);
  result.size(size);
  return result;
}

auto picture_box::create(const xtd::drawing::image& image, picture_box_size_mode size_mode, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> picture_box {
  auto result = picture_box {};
  result.image(image);
  result.size_mode(size_mode);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

auto picture_box::create(const control& parent) -> picture_box {
  auto result = picture_box {};
  result.parent(parent);
  return result;
}

auto picture_box::create(const control& parent, const xtd::drawing::point& location) -> picture_box {
  auto result = picture_box {};
  result.parent(parent);
  result.location(location);
  return result;
}

auto picture_box::create(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> picture_box {
  auto result = picture_box {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

auto picture_box::create(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> picture_box {
  auto result = picture_box {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

auto picture_box::create(const control& parent, const xtd::drawing::image& image) -> picture_box {
  auto result = picture_box {};
  result.parent(parent);
  result.image(image);
  return result;
}

auto picture_box::create(const control& parent, const xtd::drawing::image& image, const xtd::drawing::point& location) -> picture_box {
  auto result = picture_box {};
  result.parent(parent);
  result.image(image);
  result.location(location);
  return result;
}

auto picture_box::create(const control& parent, const xtd::drawing::image& image, const xtd::drawing::point& location, const xtd::drawing::size& size) -> picture_box {
  auto result = picture_box {};
  result.parent(parent);
  result.image(image);
  result.location(location);
  result.size(size);
  return result;
}

auto picture_box::create(const control& parent, const xtd::drawing::image& image, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> picture_box {
  auto result = picture_box {};
  result.parent(parent);
  result.image(image);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

auto picture_box::create(const control& parent, const xtd::drawing::image& image, picture_box_size_mode size_mode) -> picture_box {
  auto result = picture_box {};
  result.parent(parent);
  result.image(image);
  result.size_mode(size_mode);
  return result;
}

auto picture_box::create(const control& parent, const xtd::drawing::image& image, picture_box_size_mode size_mode, const xtd::drawing::point& location) -> picture_box {
  auto result = picture_box {};
  result.parent(parent);
  result.image(image);
  result.size_mode(size_mode);
  result.location(location);
  return result;
}

auto picture_box::create(const control& parent, const xtd::drawing::image& image, picture_box_size_mode size_mode, const xtd::drawing::point& location, const xtd::drawing::size& size) -> picture_box {
  auto result = picture_box {};
  result.parent(parent);
  result.image(image);
  result.size_mode(size_mode);
  result.location(location);
  result.size(size);
  return result;
}

auto picture_box::create(const control& parent, const xtd::drawing::image& image, picture_box_size_mode size_mode, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> picture_box {
  auto result = picture_box {};
  result.parent(parent);
  result.image(image);
  result.size_mode(size_mode);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

auto picture_box::create_params() const noexcept -> xtd::forms::create_params {
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

auto picture_box::measure_control() const noexcept -> xtd::drawing::size {
  auto size = data_->image.has_value() ? data_->image->size() : xtd::drawing::size(0, 0);
  /// @todo add location
  return size;
}

auto picture_box::on_handle_created(const event_args& e) -> void {
  control::on_handle_created(e);
  if (data_->image.has_value() && *data_->image != xtd::drawing::image::empty && control_appearance() == forms::control_appearance::system)
    native::picture_box::image(handle(), *data_->image);
}

auto picture_box::on_paint(paint_event_args& e) -> void {
  control::on_paint(e);
  if (control_appearance() != forms::control_appearance::standard) return;
  if (image().has_value()) control_paint::draw_image(e.graphics(), image().value(), e.clip_rectangle(), to_image_layout(size_mode()));
  control_paint::draw_border_from_back_color(*this, e.graphics(), border_style(), border_sides(), back_color(), e.clip_rectangle());
}
