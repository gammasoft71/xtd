#pragma once
#include "loading_indicator_animation.h"
#include <xtd/math>

namespace xtd::forms {
  class loading_indicator_animation_bar : public loading_indicator_animation {
  public:
    void on_paint(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& clip_rectangle, const xtd::drawing::color& color, bool enabled) override {
      auto h = clip_rectangle.height() / 6;
      auto w = static_cast<xtd::int32>(clip_rectangle.width() / 1.3);
      auto p = clip_rectangle.width() * 2 / intervals_;
      auto x = -clip_rectangle.width();
      auto y = (clip_rectangle.height() - h) / 2;
      
      auto graphics_path = xtd::drawing::drawing_2d::graphics_path {};
      graphics_path.add_rounded_rectangle(0, y, clip_rectangle.width(), h, h / 2);
      auto region = xtd::drawing::region {graphics_path};
      graphics.clip(region);
      graphics.clear(xtd::drawing::color::from_argb(static_cast<xtd::byte>(32), color));
      graphics.fill_rounded_rectangle(xtd::drawing::solid_brush {xtd::drawing::color::from_argb(static_cast<xtd::byte>(255), color)}, x + (frame_ * p), y, w, h, h / 2);
      graphics.reset_clip();
    }
    
    void on_timer() override {
      if (++frame_ == intervals_) frame_ = 0;
    }
    
  private:
    xtd::int32 intervals_ = 8;
    xtd::int32 frame_ = 0;
  };
}
