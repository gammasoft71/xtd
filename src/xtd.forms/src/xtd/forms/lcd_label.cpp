#include "dot_matrix_display_digit.hpp"
#include "fourteen_segment_display_digit.hpp"
#include "nine_segment_display_digit.hpp"
#include "seven_segment_display_digit.hpp"
#include "sixteen_segment_display_digit.hpp"
#include "../../../include/xtd/forms/lcd_label.hpp"
#include <xtd/collections/generic/list>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::helpers;

struct lcd_label::data {
  bool show_back_digit = true;
  std::optional<xtd::drawing::color> back_digit_color;
  double back_digit_opacity = 0.95;
  std::optional<int32> digit_spacing;
  xtd::forms::lcd_style lcd_style = xtd::forms::lcd_style::seven_segment_display;
  xtd::forms::segment_style segment_style = xtd::forms::segment_style::standard;
  xtd::forms::dot_matrix_style dot_matrix_style = xtd::forms::dot_matrix_style::standard;
  list<xtd::sptr<idigit>> digits;
  std::optional<int32> thickness;
};

lcd_label::lcd_label() : data_(xtd::new_sptr<data>()) {
  set_auto_size_mode(forms::auto_size_mode::grow_and_shrink);
  set_can_focus(false);
  set_style(control_styles::user_paint | control_styles::supports_transparent_back_color | control_styles::optimized_double_buffer, control::control_appearance() == xtd::forms::control_appearance::standard);
  set_style(control_styles::fixed_height | control_styles::selectable, false);
  set_style(control_styles::resize_redraw, true);
}

xtd::drawing::color lcd_label::back_digit_color() const noexcept {
  return data_->back_digit_color.value_or(fore_color());
}

lcd_label& lcd_label::back_digit_color(const xtd::drawing::color& value) {
  if (data_->back_digit_color.has_value() && data_->back_digit_color.value() == value) return *this;
  data_->back_digit_color = value;
  set_digits_params();
  return *this;
}

double lcd_label::back_digit_opacity() const noexcept {
  return data_->back_digit_opacity;
}

lcd_label& lcd_label::back_digit_opacity(double value) {
  if (value < 0.0 || value > 1.0) throw_helper::throws(exception_case::argument_out_of_range, "value must be between 0.0 and 1.0."_t);
  if (data_->back_digit_opacity == value) return *this;
  data_->back_digit_opacity = value;
  set_digits_params();
  return *this;
}

bool lcd_label::show_back_digit() const noexcept {
  return data_->show_back_digit;
}

lcd_label& lcd_label::show_back_digit(bool value) {
  if (data_->show_back_digit == value) return *this;
  data_->show_back_digit = value;
  set_digits_params();
  return *this;
}

int32 lcd_label::digit_spacing() const noexcept {
  return data_->digit_spacing.value_or(data_->lcd_style == lcd_style::dot_matrix_display ? 0 : thickness());
}

lcd_label& lcd_label::digit_spacing(int32 value) {
  if (value < 0) throw_helper::throws(exception_case::argument_out_of_range, "value must be positive"_t);
  if (data_->digit_spacing == value) return *this;
  data_->digit_spacing = value;
  set_digits_params();
  return *this;
}

forms::lcd_style lcd_label::lcd_style() const noexcept {
  return data_->lcd_style;
}

lcd_label& lcd_label::lcd_style(forms::lcd_style value) {
  if (data_->lcd_style == value) return *this;
  data_->lcd_style = value;
  xtd::string current_text = text();
  text("");
  text(current_text);
  return *this;
}

forms::segment_style lcd_label::segment_style() const noexcept {
  return data_->segment_style;
}

lcd_label& lcd_label::segment_style(forms::segment_style value) {
  if (data_->segment_style == value) return *this;
  data_->segment_style = value;
  for (auto& digit : data_->digits)
    digit->segment_style_digit(value);
  return *this;
}

forms::dot_matrix_style lcd_label::dot_matrix_style() const noexcept {
  return data_->dot_matrix_style;
}

lcd_label& lcd_label::dot_matrix_style(forms::dot_matrix_style value) {
  if (data_->dot_matrix_style == value) return *this;
  data_->dot_matrix_style = value;
  for (auto& digit : data_->digits)
    digit->dot_matrix_style_digit(value);
  return *this;
}

int32 lcd_label::thickness() const noexcept {
  return data_->thickness.value_or(data_->digits.size() ? data_->digits[0]->thickness_digit() : 1);
}

lcd_label& lcd_label::thickness(int32 value) {
  if (data_->thickness == value) return *this;
  data_->thickness = value;
  set_digits_params();
  return *this;
}

control& lcd_label::text(const xtd::string& value) {
  if (text() == value) return *this;
  if (is_handle_created()) suspend_layout();
  auto str = convert_string::to_wstring(value);
  if (str.size() < data_->digits.size()) {
    for (auto index = data_->digits.size(); index < str.size(); ++index) {
      dynamic_cast<control*>(data_->digits[index].get())->mouse_down -= {*this, &lcd_label::on_digit_mouse_down};
      dynamic_cast<control*>(data_->digits[index].get())->mouse_move -= {*this, &lcd_label::on_digit_mouse_move};
      dynamic_cast<control*>(data_->digits[index].get())->mouse_up -= {*this, &lcd_label::on_digit_mouse_up};
    }
    data_->digits.erase(data_->digits.begin() + str.size(), data_->digits.end());
  }
  if (str.size() > data_->digits.size())
    for (auto index = data_->digits.size(); index < str.size(); ++index) {
      switch (data_->lcd_style) {
        case lcd_style::seven_segment_display: data_->digits.push_back(xtd::new_sptr<seven_segment_display_digit>()); break;
        case lcd_style::nine_segment_display: data_->digits.push_back(xtd::new_sptr<nine_segment_display_digit>()); break;
        case lcd_style::fourteen_segment_display: data_->digits.push_back(xtd::new_sptr<fourteen_segment_display_digit>()); break;
        case lcd_style::sixteen_segment_display: data_->digits.push_back(xtd::new_sptr<sixteen_segment_display_digit>()); break;
        case lcd_style::dot_matrix_display: data_->digits.push_back(xtd::new_sptr<dot_matrix_display_digit>()); break;
        default: throw_helper::throws(exception_case::argument, "lcd_style invalid"_t);
      }
      dynamic_cast<control*>(data_->digits[data_->digits.size() - 1].get())->parent(*this);
      dynamic_cast<control*>(data_->digits[data_->digits.size() - 1].get())->double_buffered(double_buffered());
      dynamic_cast<control*>(data_->digits[data_->digits.size() - 1].get())->click += {*this, &lcd_label::on_digit_click};
      dynamic_cast<control*>(data_->digits[data_->digits.size() - 1].get())->mouse_down += {*this, &lcd_label::on_digit_mouse_down};
      dynamic_cast<control*>(data_->digits[data_->digits.size() - 1].get())->mouse_move += {*this, &lcd_label::on_digit_mouse_move};
      dynamic_cast<control*>(data_->digits[data_->digits.size() - 1].get())->mouse_up += {*this, &lcd_label::on_digit_mouse_up};
    }
  for (auto index = 0_z; index < str.size(); ++index)
    data_->digits[index]->character(str[index]);
  set_digits_params();
  set_text(value);
  if (is_handle_created()) resume_layout();
  return *this;
}

array<char32> lcd_label::valid_characters() {
  switch (data_->lcd_style) {
    case lcd_style::seven_segment_display: return seven_segment_display_digit {}.valid_characters();
    case lcd_style::nine_segment_display: return nine_segment_display_digit {}.valid_characters();
    case lcd_style::fourteen_segment_display: return fourteen_segment_display_digit {}.valid_characters();
    case lcd_style::sixteen_segment_display: return sixteen_segment_display_digit {}.valid_characters();
    case lcd_style::dot_matrix_display: return dot_matrix_display_digit {}.valid_characters();
    default: throw_helper::throws(exception_case::argument, "lcd_style invalid"_t);
  }
}

lcd_label lcd_label::create() {
  return lcd_label {};
}

lcd_label lcd_label::create(const drawing::point& location) {
  auto result = lcd_label {};
  result.location(location);
  return result;
}

lcd_label lcd_label::create(const drawing::point& location, const drawing::size& size) {
  auto result = lcd_label {};
  result.location(location);
  result.size(size);
  return result;
}

lcd_label lcd_label::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = lcd_label {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

lcd_label lcd_label::create(const xtd::string& text) {
  auto result = lcd_label {};
  result.text(text);
  return result;
}

lcd_label lcd_label::create(const xtd::string& text, const drawing::point& location) {
  auto result = lcd_label {};
  result.text(text);
  result.location(location);
  return result;
}

lcd_label lcd_label::create(const xtd::string& text, const drawing::point& location, const drawing::size& size) {
  auto result = lcd_label {};
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

lcd_label lcd_label::create(const xtd::string& text, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = lcd_label {};
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

lcd_label lcd_label::create(const control& parent) {
  auto result = lcd_label {};
  result.parent(parent);
  return result;
}

lcd_label lcd_label::create(const control& parent, const drawing::point& location) {
  auto result = lcd_label {};
  result.parent(parent);
  result.location(location);
  return result;
}

lcd_label lcd_label::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = lcd_label {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

lcd_label lcd_label::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = lcd_label {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

lcd_label lcd_label::create(const control& parent, const xtd::string& text) {
  auto result = lcd_label {};
  result.parent(parent);
  result.text(text);
  return result;
}

lcd_label lcd_label::create(const control& parent, const xtd::string& text, const drawing::point& location) {
  auto result = lcd_label {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  return result;
}

lcd_label lcd_label::create(const control& parent, const xtd::string& text, const drawing::point& location, const drawing::size& size) {
  auto result = lcd_label {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

lcd_label lcd_label::create(const control& parent, const xtd::string& text, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = lcd_label {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

drawing::size lcd_label::default_size() const noexcept {
  return {100, 25};
}

xtd::uptr<xtd::object> lcd_label::clone() const {
  auto result = xtd::new_uptr<lcd_label>(*this);
  if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).c_str());
  return result;
}

drawing::size lcd_label::measure_control() const noexcept {
  if (data_->digits.size() == 0) return {0, size().height};
  return drawing::size((dynamic_cast<control*>(data_->digits[0].get())->width() - 2 + digit_spacing()) * static_cast<int32>(data_->digits.size()) - digit_spacing() + 2, size().height);
}

void lcd_label::on_back_color_changed(const event_args& e) {
  control::on_back_color_changed(e);
  invalidate();
}

void lcd_label::on_fore_color_changed(const event_args& e) {
  control::on_fore_color_changed(e);
  invalidate();
}

void lcd_label::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  set_digits_params();
}

void lcd_label::on_size_changed(const event_args& e) {
  set_digits_params();
  control::on_size_changed(e);
}

void lcd_label::on_resize(const event_args& e) {
  set_digits_params();
  control::on_resize(e);
}

void lcd_label::on_digit_click(object& sender, const event_args& e) {
  on_click(e);
}

void lcd_label::on_digit_mouse_down(object& sender, const mouse_event_args& e) {
  on_mouse_down(mouse_event_args(e.button(), e.clicks(), e.location() + drawing::size(as<control>(sender).location()), e.delta()));
}

void lcd_label::on_digit_mouse_move(object& sender, const mouse_event_args& e) {
  on_mouse_move(mouse_event_args(e.button(), e.clicks(), e.location() + drawing::size(as<control>(sender).location()), e.delta()));
}

void lcd_label::on_digit_mouse_up(object& sender, const mouse_event_args& e) {
  on_mouse_up(mouse_event_args(e.button(), e.clicks(), e.location() + drawing::size(as<control>(sender).location()), e.delta()));
}

void lcd_label::set_digits_params() {
  auto offset_left = 0;
  for (auto& digit : data_->digits) {
    dynamic_cast<control*>(digit.get())->height(size().height);
    dynamic_cast<control*>(digit.get())->left(offset_left);
    digit->back_digit_color(back_digit_color());
    digit->back_digit_opacity(data_->back_digit_opacity);
    digit->show_back_digit(data_->show_back_digit);
    digit->segment_style_digit(data_->segment_style);
    digit->dot_matrix_style_digit(data_->dot_matrix_style);
    if (data_->thickness.has_value()) digit->thickness_digit(thickness());
    offset_left += dynamic_cast<control*>(digit.get())->width() - 2 + digit_spacing();
  }
}
