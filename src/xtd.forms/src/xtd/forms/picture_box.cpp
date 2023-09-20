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

struct picture_box::data {
  forms::border_sides border_sides = forms::border_sides::all;
  forms::border_style border_style = forms::border_style::none;
  std::optional<drawing::image> image;
  picture_box_size_mode size_mode = picture_box_size_mode::normal;
};

picture_box::picture_box() : data_(std::make_shared<data>()) {
  set_can_focus(false);
  set_style(control_styles::opaque | control_styles::selectable, false);
  set_style(control_styles::optimized_double_buffer | control_styles::supports_transparent_back_color, true);
}

forms::border_sides picture_box::border_sides() const noexcept {
  return data_->border_sides;
}

picture_box& picture_box::border_sides(forms::border_sides border_sides) {
  if (data_->border_sides != border_sides) {
    data_->border_sides = border_sides;
    if (control_appearance() == forms::control_appearance::standard) invalidate();
  }
  return *this;
}

forms::border_style picture_box::border_style() const noexcept {
  return data_->border_style;
}

picture_box& picture_box::border_style(forms::border_style border_style) {
  if (data_->border_style != border_style) {
    data_->border_style = border_style;
    if (is_handle_created() && control_appearance() == forms::control_appearance::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

std::optional<drawing::image> picture_box::image() const noexcept {
  return data_->image;
}

picture_box& picture_box::image(const drawing::image& image) {
  if (!data_->image.has_value() || data_->image.value().handle() != image.handle()) {
    if (image == drawing::image::empty)
      this->image(nullptr);
    else {
      data_->image = image;
      if (is_handle_created() && control_appearance() == forms::control_appearance::system) native::picture_box::image(handle(), data_->image.value());
      else invalidate();
    }
  }
  return *this;
}

picture_box& picture_box::image(std::nullptr_t) {
  if (data_->image.has_value()) {
    data_->image.reset();
    if (is_handle_created() && control_appearance() == forms::control_appearance::system) native::picture_box::reset(handle());
    else invalidate();
  }
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

picture_box picture_box::create(const xtd::drawing::image& image, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = picture_box {};
  result.image(image);
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}

picture_box picture_box::create(const control& parent, const xtd::drawing::image& image, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = picture_box {};
  result.parent(parent);
  result.image(image);
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}

forms::create_params picture_box::create_params() const noexcept {
  auto create_params = control::create_params();
  
  create_params.class_name("picturebox");
  create_params.style(create_params.style() | SS_BITMAP);
  
  if (control_appearance() == forms::control_appearance::system) {
    if (data_->border_style == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
    else if (data_->border_style != forms::border_style::none) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
    
    switch (data_->size_mode) {
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
  if (control_appearance() == forms::control_appearance::standard) {
    if (image().has_value())
      control_paint::draw_image(e.graphics(), image().value(), e.clip_rectangle(), to_image_layout(size_mode()));
    control_paint::draw_border_from_back_color(*this, e.graphics(), border_style(), border_sides(), back_color(), e.clip_rectangle());
  }
}
