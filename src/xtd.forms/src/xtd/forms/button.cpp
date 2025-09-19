#include "../../../include/xtd/forms/button.hpp"
#include "../../../include/xtd/forms/button_renderer.hpp"
#include "../../../include/xtd/forms/form.hpp"
#include <xtd/drawing/pen>
#include <xtd/drawing/solid_brush>
#include <xtd/drawing/string_format>
#include <xtd/drawing/system_brushes>
#include <xtd/drawing/system_pens>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/button>
#include <xtd/forms/native/button_styles>
#include <xtd/forms/native/control>
#include <xtd/forms/native/window_definitions>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::helpers;

struct button::data {
  bool auto_repeat = false;
  bool auto_repeat_click = false;
  timer auto_repeat_timer;
  int32 auto_repeat_delay = 300;
  int32 auto_repeat_interval = 100;
  forms::dialog_result dialog_result = forms::dialog_result::none;
  xtd::forms::visual_styles::push_button_state state = xtd::forms::visual_styles::push_button_state::normal;
};

button::button() : data_(xtd::new_sptr<data>()) {
  set_style(control_styles::standard_click | control_styles::standard_double_click, false);
  data_->auto_repeat_timer.tick += {*this, &button::on_auto_repeat_timer_tick};
}

button::button(button&& rhs) : button_base(std::move(rhs)), data_ {std::move(rhs.data_)} {
  data_->auto_repeat_timer.tick -= {rhs, &button::on_auto_repeat_timer_tick};
  data_->auto_repeat_timer.tick += {*this, &button::on_auto_repeat_timer_tick};
}

bool button::auto_repeat() const noexcept {
  return data_->auto_repeat;
}

button& button::auto_repeat(bool auto_repeat) {
  if (data_->auto_repeat == auto_repeat) return *this;
  data_->auto_repeat = auto_repeat;
  if (!data_->auto_repeat) data_->auto_repeat_timer.enabled(false);
  return *this;
}

int32 button::auto_repeat_delay() const noexcept {
  return data_->auto_repeat_delay;
}

button& button::auto_repeat_delay(int32 auto_repeat_delay) {
  data_->auto_repeat_delay = auto_repeat_delay;
  return *this;
}

int32 button::auto_repeat_interval() const noexcept {
  return data_->auto_repeat_interval;
}

button& button::auto_repeat_interval(int32 auto_repeat_interval) {
  data_->auto_repeat_interval = auto_repeat_interval;
  return *this;
}

forms::auto_size_mode button::auto_size_mode() const noexcept {
  return get_auto_size_mode();
}

button& button::auto_size_mode(forms::auto_size_mode value) {
  set_auto_size_mode(value);
  return *this;
}

forms::dialog_result button::dialog_result() const noexcept {
  return data_->dialog_result;
}

control& button::dialog_result(forms::dialog_result dialog_result) {
  data_->dialog_result = dialog_result;
  return *this;
}

button button::create() {
  return button {};
}

button button::create(const drawing::point& location) {
  auto result = button {};
  result.location(location);
  return result;
}

button button::create(const drawing::point& location, const drawing::size& size) {
  auto result = button {};
  result.location(location);
  result.size(size);
  return result;
}

button button::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = button {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

button button::create(const xtd::string& text) {
  auto result = button {};
  result.text(text);
  return result;
}

button button::create(const xtd::string& text, const drawing::point& location) {
  auto result = button {};
  result.text(text);
  result.location(location);
  return result;
}

button button::create(const xtd::string& text, const drawing::point& location, const drawing::size& size) {
  auto result = button {};
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

button button::create(const xtd::string& text, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = button {};
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

button button::create(const control& parent) {
  auto result = button {};
  result.parent(parent);
  return result;
}

button button::create(const control& parent, const drawing::point& location) {
  auto result = button {};
  result.parent(parent);
  result.location(location);
  return result;
}

button button::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = button {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

button button::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = button {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

button button::create(const control& parent, const xtd::string& text) {
  auto result = button {};
  result.parent(parent);
  result.text(text);
  return result;
}

button button::create(const control& parent, const xtd::string& text, const drawing::point& location) {
  auto result = button {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  return result;
}

button button::create(const control& parent, const xtd::string& text, const drawing::point& location, const drawing::size& size) {
  auto result = button {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

button button::create(const control& parent, const xtd::string& text, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = button {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

void button::notify_default(bool value) {
  is_default(value);
  if (enabled()) data_->state = is_default() ? xtd::forms::visual_styles::push_button_state::default_state : xtd::forms::visual_styles::push_button_state::normal;
  if (flat_style() != xtd::forms::flat_style::system) invalidate();
  else {
    if (is_handle_created() && value) native::button::set_default_button(handle());
    else post_recreate_handle();
  }
}

void button::perform_click() {
  on_click(event_args::empty);
}

forms::create_params button::create_params() const noexcept {
  auto create_params = button_base::create_params();
  create_params.class_name("button");
  create_params.style(create_params.style() | BS_PUSHBUTTON | BS_MULTILINE | BS_CENTER | BS_VCENTER);
  return create_params;
}

xtd::forms::visual_styles::push_button_state button::state() const noexcept {
  return data_->state;
}

xtd::uptr<xtd::object> button::clone() const {
  auto result = xtd::new_uptr<button>(*this);
  if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).chars().c_str());
  return result;
}

drawing::size button::measure_control() const noexcept {
  auto size = button_base::measure_control();
  if (size.height < default_size().height) size.height = default_size().height;
  return size;
}

void button::on_click(const event_args& e) {
  if (enabled() && (!data_->auto_repeat || data_->auto_repeat_click)) button_base::on_click(e);
  if (data_->dialog_result != forms::dialog_result::none &&  top_level_control().has_value() && static_cast<form&>(top_level_control().value().get()).modal()) {
    static_cast<form&>(top_level_control().value().get()).dialog_result(dialog_result());
    static_cast<form&>(top_level_control().value().get()).close();
  }
}

void button::on_image_changed(const xtd::event_args& e) {
  button_base::on_image_changed(e);
}

void button::on_handle_created(const event_args& e) {
  button_base::on_handle_created(e);
  if (flat_style() == xtd::forms::flat_style::system) {
    if (image() != drawing::image::empty || (image_list().images().count() && image_index() > -1)) {
      native::button::image(handle(), image() != drawing::image::empty ? image() : image_list().images()[image_index()]);
      native::button::image_align(handle(), static_cast<uint32_t>(image_align()));
      if (image_align() != content_alignment::middle_center) native::control::text(handle(), text());
      native::control::location(handle(), location());
      native::control::size(handle(), size());
    }
    if (is_default() && flat_style() == xtd::forms::flat_style::system) native::button::set_default_button(handle());
  }
}

void button::on_enabled_changed(const event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system) data_->state = enabled() ? (is_default() ? xtd::forms::visual_styles::push_button_state::default_state : xtd::forms::visual_styles::push_button_state::normal) : xtd::forms::visual_styles::push_button_state::disabled;
  button_base::on_enabled_changed(e);
}

void button::on_mouse_down(const mouse_event_args& e) {
  data_->auto_repeat_timer.enabled(false);
  if (data_->auto_repeat && e.button() == mouse_buttons::left) {
    auto_repeat_perform_click();
    data_->auto_repeat_timer.interval_milliseconds(data_->auto_repeat_delay);
    data_->auto_repeat_timer.enabled(data_->auto_repeat);
  }
  if (flat_style() != xtd::forms::flat_style::system && enabled()) data_->state = xtd::forms::visual_styles::push_button_state::pressed;
  button_base::on_mouse_down(e);
}

void button::on_mouse_enter(const event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system && enabled()) data_->state = (mouse_buttons() & mouse_buttons::left) == mouse_buttons::left ? xtd::forms::visual_styles::push_button_state::pressed : xtd::forms::visual_styles::push_button_state::hot;
  button_base::on_mouse_enter(e);
}

void button::on_mouse_leave(const event_args& e) {
  data_->auto_repeat_timer.enabled(false);
  if (flat_style() != xtd::forms::flat_style::system && enabled()) data_->state = is_default() ? xtd::forms::visual_styles::push_button_state::default_state : xtd::forms::visual_styles::push_button_state::normal;
  button_base::on_mouse_leave(e);
}

void button::on_mouse_up(const mouse_event_args& e) {
  data_->auto_repeat_timer.enabled(false);
  if (e.button() == mouse_buttons::left && flat_style() != xtd::forms::flat_style::system && enabled() && data_->state == xtd::forms::visual_styles::push_button_state::pressed) data_->state = xtd::forms::visual_styles::push_button_state::hot;
  button_base::on_mouse_up(e);
}

void button::on_paint(paint_event_args& e) {
  auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  if (flat_style() == xtd::forms::flat_style::standard) button_renderer::draw_button(style, e.graphics(), e.clip_rectangle(), state(), is_default(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font() != default_font() ? std::optional<drawing::font> {font()} : std::nullopt, image(), image_align());
  if (flat_style() == xtd::forms::flat_style::flat) button_renderer::draw_flat_button(style, e.graphics(), e.clip_rectangle(), state(), is_default(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, flat_appearance(), text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font() != default_font() ? std::optional<drawing::font> {font()} : std::nullopt, image(), image_align());
  if (flat_style() == xtd::forms::flat_style::popup) button_renderer::draw_popup_button(style, e.graphics(), e.clip_rectangle(), state(), is_default(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, flat_appearance(), text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font() != default_font() ? std::optional<drawing::font> {font()} : std::nullopt, image(), image_align());
  button_base::on_paint(e);
}

void button::auto_repeat_perform_click() {
  data_->auto_repeat_click = true;
  perform_click();
  data_->auto_repeat_click = false;
}

void button::on_auto_repeat_timer_tick(object& sender, const event_args& e) {
  data_->auto_repeat_timer.enabled(false);
  if (enabled()) {
    auto_repeat_perform_click();
    data_->auto_repeat_timer.interval_milliseconds(data_->auto_repeat_interval);
    data_->auto_repeat_timer.enabled(data_->auto_repeat);
  }
}
