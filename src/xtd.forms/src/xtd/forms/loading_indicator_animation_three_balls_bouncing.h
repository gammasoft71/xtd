#pragma once
#include "loading_indicator_animation.h"
#include <xtd/math>

namespace xtd::forms {
  class loading_indicator_animation_three_balls_bouncing : public loading_indicator_animation {
  public:
    void on_paint(xtd::drawing::graphics& graphics,  const xtd::drawing::rectangle& clip_rectangle, const xtd::drawing::color& color, bool enabled) override {
      auto dot_height = xtd::math::min(clip_rectangle.height(), clip_rectangle.width()) / 4;
      auto dot_width = dot_height;
      auto x1 = clip_rectangle.left() + 2;
      auto x2 = clip_rectangle.left() + clip_rectangle.width() / 2 - dot_width / 2;
      auto x3 = clip_rectangle.right() - dot_width - 2;
      auto y1 = clip_rectangle.top() + clip_rectangle.height() / 2 - dot_height / 2;
      auto y2 = clip_rectangle.top() + clip_rectangle.height() / 2 - dot_height / 2;
      auto y3 = clip_rectangle.top() + clip_rectangle.height() / 2 - dot_height / 2;
      auto height1 = dot_height;
      auto width1 = dot_width;
      auto height2 = dot_height;
      auto width2 = dot_width;
      auto height3 = dot_height;
      auto width3 = dot_width;
      auto opacity = enabled ? 255 : 128;
      auto wave1 = std::vector { 0,  2,  4,  2,  0, -2, -4, -2};
      auto wave2 = std::vector {-4, -2,  0,  2,  4,  2,  0, -2};
      auto wave3 = std::vector { 0, -2, -4, -2,  0,  2,  4,  2};

      graphics.fill_ellipse(xtd::drawing::solid_brush {xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), color)}, x1, y1 - wave1[frame_ % 8], width1, height1);
      graphics.fill_ellipse(xtd::drawing::solid_brush {xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), color)}, x2, y2 - wave2[frame_ % 8], width2, height2);
      graphics.fill_ellipse(xtd::drawing::solid_brush {xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), color)}, x3, y3 - wave3[frame_ % 8], width3, height3);
    }
    
    void on_timer() override {
      if (++frame_ == intervals_) frame_ = 0;
    }
    
  private:
    xtd::int32 intervals_ = 8;
    xtd::int32 frame_ = 0;
  };
}
