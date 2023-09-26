#include "../../../include/xtd/forms/application"
#include "../../../include/xtd/forms/control_paint"
#include "../../../include/xtd/forms/switch_button"

using namespace xtd;
using namespace xtd::forms;

struct switch_button::data {
  std::optional<xtd::drawing::color> checked_back_color;
  std::optional<xtd::drawing::color> slider_color;
  bool rounded = true;
  bool auto_check = true;
  bool show_text = false;
  bool checked = false;
};

switch_button::switch_button() : data_(std::make_shared<data>()) {
  set_style(control_styles::standard_click | control_styles::standard_double_click, false);
}

bool switch_button::auto_check() const noexcept {
  return data_->auto_check;
}

switch_button& switch_button::auto_check(bool auto_check) {
  data_->auto_check = auto_check;
  return *this;
}

xtd::drawing::color switch_button::checked_back_color() const noexcept {
  return data_->checked_back_color.value_or(application::style_sheet().system_colors().accent());
}

switch_button& switch_button::checked_back_color(const xtd::drawing::color& color) {
  if (data_->checked_back_color.has_value() && data_->checked_back_color.value() == color) return *this;
  data_->checked_back_color = color;
  invalidate();
  return *this;
}

switch_button& switch_button::checked_back_color(std::nullptr_t) {
  if (!data_->checked_back_color.has_value()) return *this;
  data_->checked_back_color.reset();
  invalidate();
  return *this;
}

xtd::drawing::color switch_button::slider_color() const noexcept {
  return data_->slider_color.value_or(back_color());
}

switch_button& switch_button::slider_color(const xtd::drawing::color& color) {
  if (data_->slider_color.has_value() && data_->slider_color.value() == color) return *this;
  data_->slider_color = color;
  invalidate();
  return *this;
}

switch_button& switch_button::slider_color(std::nullptr_t) {
  if (!data_->slider_color.has_value()) return *this;
  data_->slider_color.reset();
  invalidate();
  return *this;
}

bool switch_button::rounded() const noexcept {
  return data_->rounded;
}

switch_button& switch_button::rounded(bool value) {
  if (data_->rounded == value) return *this;
  data_->rounded = value;
  invalidate();
  return *this;
}

bool switch_button::checked() const noexcept {
  return data_->checked;
}

switch_button& switch_button::checked(bool checked) {
  if (data_->checked == checked) return *this;
  data_->checked = checked;
  invalidate();
  on_checked_changed(event_args::empty);
  return *this;
}

bool switch_button::show_text() const noexcept {
  return data_->show_text;
}

switch_button& switch_button::show_text(bool value) {
  if (data_->show_text == value) return *this;
  data_->show_text = value;
  invalidate();
  return *this;
}

switch_button switch_button::create(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = switch_button {};
  result.checked(checked);
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}

switch_button switch_button::create(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = switch_button {};
  result.parent(parent);
  result.checked(checked);
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}

drawing::size switch_button::default_size() const noexcept {
  return {50, 25};
}

void switch_button::on_checked_changed(const event_args& e) {
  checked_changed(*this, e);
}

void switch_button::on_mouse_down(const mouse_event_args& e) {
  button_base::on_mouse_down(e);
  if (data_->auto_check) checked(!checked());
}

void switch_button::on_handle_created(const event_args& e) {
  button_base::on_handle_created(e);
  invalidate();
}

void switch_button::on_paint(paint_event_args& e) {
  auto button_back_color = data_->checked ? checked_back_color() : application::style_sheet().system_colors().gray_text();
  auto text_color = data_->checked ? fore_color() : drawing::color::average(button_back_color, fore_color(), .33);
  auto sld_color = this->slider_color();
  auto text = data_->checked ? "ON" : "OFF";
  
  if (!enabled()) {
    button_back_color = drawing::color::average(back_color(), button_back_color, .33);
    text_color = drawing::color::average(button_back_color, text_color, .33);
    sld_color = drawing::color::average(button_back_color, sld_color, .33);
  }
  
  if (data_->rounded) {
    auto height = static_cast<float>(e.clip_rectangle().height() - e.clip_rectangle().height() % 2);
    auto slider_location = data_->checked ? drawing::point_f {e.clip_rectangle().width() - height + 2.0f, 2.0f} : drawing::point_f {2.0f, 2.0f};
    
    auto string_size = e.graphics().measure_string(text, font());
    auto string_location = data_->checked ? drawing::point_f {slider_location.x() - string_size.width() - 2, (height - string_size.height()) / 2} : drawing::point_f {slider_location.x() + static_cast<float>(height - 4) + 2, (height - string_size.height()) / 2};
    
    e.graphics().fill_rounded_rectangle(drawing::solid_brush {button_back_color}, .0f, .0f, static_cast<float>(e.clip_rectangle().width()), static_cast<float>(height), static_cast<float>(height) / 2);
    e.graphics().fill_ellipse(drawing::solid_brush {sld_color}, slider_location.x(), slider_location.y(), static_cast<float>(height - 4), static_cast<float>(height - 4));
    if (data_->show_text) e.graphics().draw_string(text, font(), drawing::solid_brush(text_color), string_location);
  } else {
    auto slider_size = drawing::size_f {static_cast<float>((e.clip_rectangle().width() - 6) / 2), static_cast<float>(e.clip_rectangle().height() - 6)};
    auto slider_location = data_->checked ? drawing::point_f {width() / 2.0f, 3.0f} : drawing::point_f {3.0f, 3.0f};
    
    drawing::size_f string_size = e.graphics().measure_string(text, font());
    drawing::point_f string_location(data_->checked ? drawing::point_f((width() / 2 - string_size.width()) / 2, (height() - string_size.height()) / 2) : drawing::point_f(width() / 2 + (width() / 2 - string_size.width()) / 2, (height() - string_size.height()) / 2));
    
    e.graphics().clear(button_back_color);
    if (data_->show_text) e.graphics().draw_string(text, font(), drawing::solid_brush(text_color), string_location);
    e.graphics().draw_line(drawing::pen(control_paint::dark(button_back_color), 2), e.clip_rectangle().left(), e.clip_rectangle().top(), e.clip_rectangle().right(), e.clip_rectangle().top());
    e.graphics().draw_line(drawing::pen(control_paint::dark(button_back_color), 2), e.clip_rectangle().left(), e.clip_rectangle().top(), e.clip_rectangle().left(), e.clip_rectangle().bottom());
    e.graphics().draw_line(drawing::pen(control_paint::light(button_back_color), 2), e.clip_rectangle().left(), e.clip_rectangle().bottom(), e.clip_rectangle().right(), e.clip_rectangle().bottom());
    e.graphics().draw_line(drawing::pen(control_paint::light(button_back_color), 2), e.clip_rectangle().right(), e.clip_rectangle().top() + 2, e.clip_rectangle().right(), e.clip_rectangle().bottom());
    
    e.graphics().fill_rectangle(drawing::solid_brush {sld_color}, {slider_location, slider_size});
    e.graphics().draw_line(drawing::pen(control_paint::light(sld_color)), slider_location.x(), slider_location.y(), slider_location.x() + slider_size.width(), slider_location.y());
    e.graphics().draw_line(drawing::pen(control_paint::light(sld_color)), slider_location.x(), slider_location.y(), slider_location.x(), slider_location.y() + slider_size.height() - 2);
    e.graphics().draw_line(drawing::pen(control_paint::dark(sld_color)), slider_location.x(), slider_location.y() + slider_size.height() - 1, slider_location.x() + slider_size.width(), slider_location.y() + slider_size.height() - 1);
    e.graphics().draw_line(drawing::pen(control_paint::dark(sld_color)), slider_location.x() + slider_size.width(), slider_location.y(), slider_location.x() + slider_size.width(), slider_location.y() + slider_size.height() - 1);
  }
  button_base::on_paint(e);
}

void switch_button::on_resize(const event_args& e) {
  button_base::on_resize(e);
  invalidate();
}
