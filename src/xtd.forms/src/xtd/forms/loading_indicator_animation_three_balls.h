#pragma once
#include "loading_indicator_animation.h"
#include <xtd/math>

namespace xtd::forms {
  class loading_indicator_animation_three_balls : public loading_indicator_animation {
  public:
    void on_paint(xtd::drawing::graphics& graphics,  const xtd::drawing::rectangle& clip_rectangle, const xtd::drawing::color& color, bool enabled) override {
      auto dot_size = xtd::math::min(clip_rectangle.height(), clip_rectangle.width()) / radius_factor_ * 2;
      auto x1 = clip_rectangle.left() + 2;
      auto x2 = clip_rectangle.left() + clip_rectangle.width() / 2 - dot_size / 2;
      auto x3 = clip_rectangle.right() - dot_size - 2;
      auto y = clip_rectangle.top() + clip_rectangle.height() / 2 - dot_size / 2;
      auto opacity = enabled ? 255 : 64;
      auto size1 = enabled ? std::vector {4, 4, 2, 2, 0, 0, 2, 2} : std::vector {0, 0, 0, 0, 0, 0, 0, 0};
      auto size2 = enabled ? std::vector {2, 2, 4, 4, 2, 2, 0, 0} : std::vector {0, 0, 0, 0, 0, 0, 0, 0};
      auto size3 = enabled ? std::vector {0, 0, 2, 2, 4, 4, 2, 2} : std::vector {0, 0, 0, 0, 0, 0, 0, 0};

      graphics.fill_ellipse(xtd::drawing::solid_brush {xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), color)}, x1 - size1[frame_] / 2, y - size1[frame_] / 2, dot_size + size1[frame_], dot_size + size1[frame_]);
      graphics.fill_ellipse(xtd::drawing::solid_brush {xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), color)}, x2 - size2[frame_] / 2, y - size2[frame_] / 2, dot_size + size2[frame_], dot_size + size2[frame_]);
      graphics.fill_ellipse(xtd::drawing::solid_brush {xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), color)}, x3 - size3[frame_] / 2, y - size3[frame_] / 2, dot_size + size3[frame_], dot_size + size3[frame_]);
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
