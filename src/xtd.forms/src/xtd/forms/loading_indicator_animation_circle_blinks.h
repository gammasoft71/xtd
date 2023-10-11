#pragma once
#include "loading_indicator_animation.h"
#include <xtd/math>

namespace xtd::forms {
  class loading_indicator_animation_circle_blinks : public loading_indicator_animation {
  public:
    void on_paint(xtd::drawing::graphics& graphics,  const xtd::drawing::rectangle& clip_rectangle, const xtd::drawing::color& color, bool enabled) override {
      graphics.translate_transform(clip_rectangle.width() / 2.0f, clip_rectangle.height() / 2.0f);
      auto angle = -360.f / intervals_;
      graphics.rotate_transform(frame_ * angle);
      auto height = static_cast<float>(xtd::math::min(clip_rectangle.width(), clip_rectangle.height())) / radius_factor_;
      auto width = static_cast<float>(xtd::math::min(clip_rectangle.width(), clip_rectangle.height())) / radius_factor_;
      for (auto n = 0; n < intervals_; n++) {
        auto opacity_index = enabled ? n + 1 : 2;
        auto opacity = opacity_index * (255 + 1) / intervals_ - 1;
        graphics.fill_ellipse(xtd::drawing::solid_brush {xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), color)}, -(radius_factor_ / 2.f - 1.f) * width + width / radius_factor_ * 2.f, -(radius_factor_ / 2.f - 1.f) * height + height / radius_factor_ * 2.f, 2.f * width, 2.f * height);
        graphics.rotate_transform(angle);
      }
    }
    
    void on_timer() override {
      if (++frame_ == intervals_) frame_ = 0;
    }
    
  private:
    xtd::int32 intervals_ = 8;
    xtd::int32 radius_factor_ = 10;
    xtd::int32 frame_ = 0;
  };
}
