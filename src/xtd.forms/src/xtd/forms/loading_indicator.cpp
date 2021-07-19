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

namespace {
  static float degrees_to_radians(float degrees) {
    return static_cast<float>(M_PI / 180 * degrees);
  }
}

loading_indicator::loading_indicator() {
  can_focus_ = false;
  size_ = default_size();
  timer_.interval_milliseconds(interval_);
  timer_.tick += {*this, &loading_indicator::on_timer_tick};
}

loading_indicator& loading_indicator::loading_indicator_style(xtd::forms::loading_indicator_style loading_indicator_style) {
  if (loading_indicator_style_ != loading_indicator_style) {
    loading_indicator_style_ = loading_indicator_style;
    recreate_handle();
  }
  return *this;
}

forms::create_params loading_indicator::create_params() const {
  forms::create_params create_params = control::create_params();
  create_params.class_name("loadingindicator");
  if (loading_indicator_style_ != xtd::forms::loading_indicator_style::system) create_params.style(create_params.style() | LI_OWNERDRAW);
  return create_params;
}

drawing::size loading_indicator::measure_control() const {
  return control::measure_text();
}

void loading_indicator::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  if (is_running_) start();
}

void loading_indicator::on_paint(paint_event_args& e) {
  if (loading_indicator_style_ != xtd::forms::loading_indicator_style::system) {
    e.graphics().translate_clip(e.clip_rectangle().width() / 2, e.clip_rectangle().height() / 2);
    const float angle = degrees_to_radians(360.f / intervals_);
    e.graphics().rotate_transform(frame_ * angle);
    const float height = static_cast<float>(std::min(e.clip_rectangle().width(), e.clip_rectangle().height())) / radius_factor_;
    const float width = static_cast<float>(std::min(e.clip_rectangle().width(), e.clip_rectangle().height())) / radius_factor_;
    for (int n = 0; n < intervals_; n++) {
      const int opacity_index = enabled() ? n + 1 : 2;
      const int opacity = opacity_index*(255 + 1)/intervals_ - 1;
      e.graphics().fill_ellipse(xtd::drawing::solid_brush(xtd::drawing::color::from_argb(static_cast<uint8_t>(opacity), fore_color())), -(radius_factor_ / 2.f - 1.f) * width + width / radius_factor_ * 2.f, -(radius_factor_ / 2.f - 1.f) * height + height / radius_factor_ * 2.f, 2.f * width, 2.f *height);
      e.graphics().rotate_transform(angle);
    }
  }
  control::on_paint(e);
}

void loading_indicator::on_timer_tick(object& timer, const xtd::event_args& e) {
  if (++frame_ == intervals_) frame_ = 0;
  invalidate();
}


void loading_indicator::start() {
  is_running_ = true;
  if (loading_indicator_style_ != xtd::forms::loading_indicator_style::system)
    timer_.start();
  else
    native::loading_indicator::start(handle_);
}

void loading_indicator::stop() {
  is_running_ = false;
  if (loading_indicator_style_ != xtd::forms::loading_indicator_style::system)
    timer_.stop();
  else
    native::loading_indicator::stop(handle_);
}
