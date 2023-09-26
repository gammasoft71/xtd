#include "../../../include/xtd/forms/loading_indicator"
#include <xtd/drawing/solid_brush>
#include <xtd/drawing/string_format>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/loading_indicator>
#include <xtd/forms/native/loading_indicator_styles>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/math>

using namespace xtd;
using namespace xtd::forms;

struct loading_indicator::data {
  bool running = false;
  xtd::forms::loading_indicator_style loading_indicator_style = xtd::forms::loading_indicator_style::standard;
  xtd::forms::timer timer;
  int32 intervals = 8;
  int32 radius_factor = 10;
  int32 frame = 0;
  int32 interval = 150;
};

loading_indicator::loading_indicator() : data_(std::make_shared<data>()) {
  if (control_appearance() == forms::control_appearance::system) data_->loading_indicator_style = loading_indicator_style::system;
  set_can_focus(false);
  data_->timer.interval_milliseconds(data_->interval);
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

forms::create_params loading_indicator::create_params() const noexcept {
  auto create_params = control::create_params();
  create_params.class_name("loadingindicator");
  if (data_->loading_indicator_style != xtd::forms::loading_indicator_style::system) create_params.style(create_params.style() | LI_OWNERDRAW);
  return create_params;
}

drawing::size loading_indicator::measure_control() const noexcept {
  return control::measure_text();
}

void loading_indicator::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  if (data_->loading_indicator_style == xtd::forms::loading_indicator_style::system) {
    if (data_->running) native::loading_indicator::start(handle());
    else native::loading_indicator::stop(handle());
  }
}

void loading_indicator::on_paint(paint_event_args& e) {
  if (data_->loading_indicator_style != xtd::forms::loading_indicator_style::system) {
    e.graphics().translate_transform(e.clip_rectangle().width() / 2.0f, e.clip_rectangle().height() / 2.0f);
    auto angle = -360.f / data_->intervals;
    e.graphics().rotate_transform(data_->frame * angle);
    auto height = static_cast<float>(math::min(e.clip_rectangle().width(), e.clip_rectangle().height())) / data_->radius_factor;
    auto width = static_cast<float>(math::min(e.clip_rectangle().width(), e.clip_rectangle().height())) / data_->radius_factor;
    for (auto n = 0; n < data_->intervals; n++) {
      auto opacity_index = enabled() ? n + 1 : 2;
      auto opacity = opacity_index * (255 + 1) / data_->intervals - 1;
      e.graphics().fill_ellipse(xtd::drawing::solid_brush(xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), fore_color())), -(data_->radius_factor / 2.f - 1.f) * width + width / data_->radius_factor * 2.f, -(data_->radius_factor / 2.f - 1.f) * height + height / data_->radius_factor * 2.f, 2.f * width, 2.f * height);
      e.graphics().rotate_transform(angle);
    }
  }
  control::on_paint(e);
}

void loading_indicator::on_timer_tick(object& timer, const xtd::event_args& e) {
  if (++data_->frame == data_->intervals) data_->frame = 0;
  if (control_appearance() == forms::control_appearance::standard) invalidate();
}

loading_indicator loading_indicator::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = loading_indicator {};
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}

loading_indicator loading_indicator::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = loading_indicator {};
  result.parent(parent);
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}

void loading_indicator::start() {
  running(true);
}

void loading_indicator::stop() {
  running(false);
}
