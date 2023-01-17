#define _USE_MATH_DEFINES
#include <cmath>
#include <xtd/drawing/solid_brush.h>
#include <xtd/drawing/string_format.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/loading_indicator.h>
#include <xtd/forms/native/loading_indicator_styles.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/loading_indicator.h"

using namespace xtd;
using namespace xtd::forms;

struct loading_indicator::data {
  bool is_running = false;
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

bool loading_indicator::is_running() const noexcept {
  return data_->is_running;
}

forms::create_params loading_indicator::create_params() const noexcept {
  forms::create_params create_params = control::create_params();
  create_params.class_name("loadingindicator");
  if (data_->loading_indicator_style != xtd::forms::loading_indicator_style::system) create_params.style(create_params.style() | LI_OWNERDRAW);
  return create_params;
}

drawing::size loading_indicator::measure_control() const noexcept {
  return control::measure_text();
}

void loading_indicator::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  if (data_->is_running) start();
}

void loading_indicator::on_paint(paint_event_args& e) {
  if (data_->loading_indicator_style != xtd::forms::loading_indicator_style::system) {
    e.graphics().translate_transform(e.clip_rectangle().width() / 2.0f, e.clip_rectangle().height() / 2.0f);
    const float angle = -360.f / data_->intervals;
    e.graphics().rotate_transform(data_->frame * angle);
    const float height = static_cast<float>(std::min(e.clip_rectangle().width(), e.clip_rectangle().height())) / data_->radius_factor;
    const float width = static_cast<float>(std::min(e.clip_rectangle().width(), e.clip_rectangle().height())) / data_->radius_factor;
    for (int32 n = 0; n < data_->intervals; n++) {
      const int32 opacity_index = enabled() ? n + 1 : 2;
      const int32 opacity = opacity_index * (255 + 1) / data_->intervals - 1;
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
  loading_indicator item;
  if (location != drawing::point {-1, -1}) item.location(location);
  if (size != drawing::size {-1, -1}) item.size(size);
  item.name(name);
  return item;
}

loading_indicator loading_indicator::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  loading_indicator item;
  item.parent(parent);
  if (location != drawing::point {-1, -1}) item.location(location);
  if (size != drawing::size {-1, -1}) item.size(size);
  item.name(name);
  return item;
}

void loading_indicator::start() {
  data_->is_running = true;
  if (data_->loading_indicator_style != xtd::forms::loading_indicator_style::system)
    data_->timer.start();
  else if (is_handle_created())
    native::loading_indicator::start(handle());
}

void loading_indicator::stop() {
  data_->is_running = false;
  if (data_->loading_indicator_style != xtd::forms::loading_indicator_style::system)
    data_->timer.stop();
  else if (is_handle_created())
    native::loading_indicator::stop(handle());
}
