#include "../../../include/xtd/forms/loading_indicator.hpp"
#include "loading_indicator_animation_bar.hpp"
#include "loading_indicator_animation_circle_bars.hpp"
#include "loading_indicator_animation_circle_blinks.hpp"
#include "loading_indicator_animation_five_lines.hpp"
#include "loading_indicator_animation_five_lines_center.hpp"
#include "loading_indicator_animation_five_lines_chronological.hpp"
#include "loading_indicator_animation_five_lines_pulse.hpp"
#include "loading_indicator_animation_five_lines_wave.hpp"
#include "loading_indicator_animation_pulse.hpp"
#include "loading_indicator_animation_pulse_outline.hpp"
#include "loading_indicator_animation_standard.hpp"
#include "loading_indicator_animation_system.hpp"
#include "loading_indicator_animation_three_balls.hpp"
#include "loading_indicator_animation_three_balls_bouncing.hpp"
#include "loading_indicator_animation_three_balls_rotation.hpp"
#include <xtd/drawing/solid_brush>
#include <xtd/drawing/string_format>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/loading_indicator>
#include <xtd/forms/native/loading_indicator_styles>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::helpers;

struct loading_indicator::data {
  bool running = false;
  int32 interval = 150;
  xtd::forms::loading_indicator_style loading_indicator_style = xtd::forms::loading_indicator_style::standard;
  xtd::forms::timer timer;
  xtd::sptr<xtd::forms::loading_indicator_animation> loading_indicator_animation;
};

loading_indicator::loading_indicator() : data_(xtd::new_sptr<data>()) {
  if (control_appearance() == forms::control_appearance::system) data_->loading_indicator_style = loading_indicator_style::system;
  set_can_focus(false);
  data_->timer.interval_milliseconds(data_->interval);
  data_->timer.tick += {*this, &loading_indicator::on_timer_tick};
}

loading_indicator::loading_indicator(loading_indicator&& rhs) : control(std::move(rhs)), data_ {std::move(rhs.data_)} {
  data_->timer.tick -= {rhs, &loading_indicator::on_timer_tick};
  data_->timer.tick += {*this, &loading_indicator::on_timer_tick};
}

control& loading_indicator::control_appearance(forms::control_appearance value) {
  control::control_appearance(value);
  if (value == forms::control_appearance::system && data_->loading_indicator_style != loading_indicator_style::system)
    loading_indicator_style(loading_indicator_style::system);
  else if (value == forms::control_appearance::standard && data_->loading_indicator_style == loading_indicator_style::system)
    loading_indicator_style(loading_indicator_style::standard);
  return *this;
}

xtd::forms::loading_indicator_style loading_indicator::loading_indicator_style() const noexcept {
  return data_->loading_indicator_style;
}

loading_indicator& loading_indicator::loading_indicator_style(xtd::forms::loading_indicator_style loading_indicator_style) {
  if (data_->loading_indicator_style != loading_indicator_style) {
    data_->loading_indicator_style = loading_indicator_style;
    control_appearance(data_->loading_indicator_style == loading_indicator_style::system ? forms::control_appearance::system : forms::control_appearance::standard);
    recreate_handle();
  }
  return *this;
}

bool loading_indicator::running() const noexcept {
  return data_->running;
}

loading_indicator& loading_indicator::running(bool value) {
  if (data_->running == value) return *this;
  data_->running = value;
  if (data_->loading_indicator_style != xtd::forms::loading_indicator_style::system)
    data_->timer.enabled(data_->running);
  else if (is_handle_created()) {
    if (data_->running) native::loading_indicator::start(handle());
    else native::loading_indicator::stop(handle());
  }
  return *this;
}

loading_indicator loading_indicator::create() {
  return loading_indicator {};
}

loading_indicator loading_indicator::create(const drawing::point& location) {
  auto result = loading_indicator {};
  result.location(location);
  return result;
}

loading_indicator loading_indicator::create(const drawing::point& location, const drawing::size& size) {
  auto result = loading_indicator {};
  result.location(location);
  result.size(size);
  return result;
}

loading_indicator loading_indicator::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = loading_indicator {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

loading_indicator loading_indicator::create(const control& parent) {
  auto result = loading_indicator {};
  result.parent(parent);
  return result;
}

loading_indicator loading_indicator::create(const control& parent, const drawing::point& location) {
  auto result = loading_indicator {};
  result.parent(parent);
  result.location(location);
  return result;
}

loading_indicator loading_indicator::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = loading_indicator {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

loading_indicator loading_indicator::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = loading_indicator {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

forms::create_params loading_indicator::create_params() const noexcept {
  auto create_params = control::create_params();
  create_params.class_name("loadingindicator");
  if (data_->loading_indicator_style != xtd::forms::loading_indicator_style::system) create_params.style(create_params.style() | LI_OWNERDRAW);
  return create_params;
}

xtd::uptr<xtd::object> loading_indicator::clone() const {
  auto result = xtd::new_uptr<loading_indicator>(*this);
  if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).c_str());
  return result;
}

drawing::size loading_indicator::measure_control() const noexcept {
  return control::measure_text();
}

void loading_indicator::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  switch (data_->loading_indicator_style) {
    case loading_indicator_style::bar: data_->loading_indicator_animation = xtd::new_sptr<loading_indicator_animation_bar>(); break;
    case loading_indicator_style::circle_bars: data_->loading_indicator_animation = xtd::new_sptr<loading_indicator_animation_circle_bars>(); break;
    case loading_indicator_style::circle_blinks: data_->loading_indicator_animation = xtd::new_sptr<loading_indicator_animation_circle_blinks>(); break;
    case loading_indicator_style::five_lines: data_->loading_indicator_animation = xtd::new_sptr<loading_indicator_animation_five_lines>(); break;
    case loading_indicator_style::five_lines_center: data_->loading_indicator_animation = xtd::new_sptr<loading_indicator_animation_five_lines_center>(); break;
    case loading_indicator_style::five_lines_chronological: data_->loading_indicator_animation = xtd::new_sptr<loading_indicator_animation_five_lines_chronological>(); break;
    case loading_indicator_style::five_lines_pulse: data_->loading_indicator_animation = xtd::new_sptr<loading_indicator_animation_five_lines_pulse>(); break;
    case loading_indicator_style::five_lines_wave: data_->loading_indicator_animation = xtd::new_sptr<loading_indicator_animation_five_lines_wave>(); break;
    case loading_indicator_style::pulse: data_->loading_indicator_animation = xtd::new_sptr<loading_indicator_animation_pulse>(); break;
    case loading_indicator_style::pulse_outline: data_->loading_indicator_animation = xtd::new_sptr<loading_indicator_animation_pulse_outline>(); break;
    case loading_indicator_style::standard: data_->loading_indicator_animation = xtd::new_sptr<loading_indicator_animation_standard>(); break;
    case loading_indicator_style::system: data_->loading_indicator_animation = xtd::new_sptr<loading_indicator_animation_system>(); break;
    case loading_indicator_style::three_balls: data_->loading_indicator_animation = xtd::new_sptr<loading_indicator_animation_three_balls>(); break;
    case loading_indicator_style::three_balls_bouncing: data_->loading_indicator_animation = xtd::new_sptr<loading_indicator_animation_three_balls_bouncing>(); break;
    case loading_indicator_style::three_balls_rotation: data_->loading_indicator_animation = xtd::new_sptr<loading_indicator_animation_three_balls_rotation>(); break;
    default: data_->loading_indicator_animation = xtd::new_sptr<loading_indicator_animation_system>(); break;
  }
  if (data_->loading_indicator_style == xtd::forms::loading_indicator_style::system) {
    if (data_->running) native::loading_indicator::start(handle());
    else native::loading_indicator::stop(handle());
  }
}

void loading_indicator::on_paint(paint_event_args& e) {
  if (data_->loading_indicator_style != xtd::forms::loading_indicator_style::system) data_->loading_indicator_animation->on_paint(e.graphics(), e.clip_rectangle(), fore_color(), enabled());
  control::on_paint(e);
}

void loading_indicator::on_timer_tick(object& timer, const xtd::event_args& e) {
  if (data_->loading_indicator_style != xtd::forms::loading_indicator_style::system) data_->loading_indicator_animation->on_timer();
  if (control_appearance() == forms::control_appearance::standard) invalidate();
}

void loading_indicator::start() {
  running(true);
}

void loading_indicator::stop() {
  running(false);
}
