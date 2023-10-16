#pragma once
#include "loading_indicator_animation.h"
#include <xtd/math>

namespace xtd::forms {
  class loading_indicator_animation_three_balls_rotation : public loading_indicator_animation {
  public:
    void on_paint(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& clip_rectangle, const xtd::drawing::color& color, bool enabled) override {
      auto dot_size = xtd::math::min(clip_rectangle.height(), clip_rectangle.width()) / radius_factor_ * 2 + 2;
      auto x1 = clip_rectangle.left() + 2;
      auto x2 = clip_rectangle.left() + clip_rectangle.width() / 2 - dot_size / 2;
      auto x3 = clip_rectangle.right() - dot_size - 2;
      auto y = clip_rectangle.top() + clip_rectangle.height() / 2 - dot_size / 2;
      auto opacity = enabled ? 255 : 64;
      auto offset1 = enabled ? std::vector<xtd::drawing::size> {{0, 0}, {0, 0}, {0, 0}, {x2 / 2 - x1, -y / 2}, {x2 - x1, -y}, {x3, -y / 2}} : std::vector<xtd::drawing::size> {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
      auto offset2 = enabled ? std::vector<xtd::drawing::size> {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}} : std::vector<xtd::drawing::size> {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
      auto offset3 = enabled ? std::vector<xtd::drawing::size> {{0, 0}, {0, 0}, {0, 0}, {-x2 / 2 + x1, y / 2}, {-x2 + x1, y}, {-x3, y / 2}} : std::vector<xtd::drawing::size> {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};

      graphics.fill_ellipse(xtd::drawing::solid_brush {xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), color)}, x1 + offset1[frame_].width(), y + offset1[frame_].height(), dot_size, dot_size);
      graphics.fill_ellipse(xtd::drawing::solid_brush {xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), color)}, x2 + offset2[frame_].width(), y + offset2[frame_].height(), dot_size, dot_size);
      graphics.fill_ellipse(xtd::drawing::solid_brush {xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), color)}, x3 + offset3[frame_].width(), y + offset3[frame_].height(), dot_size, dot_size);
    }
    
    void on_timer() override {
      if (++frame_ == intervals_) frame_ = 0;
    }
    
  private:
    xtd::int32 intervals_ = 6;
    xtd::int32 radius_factor_ = 10;
    xtd::int32 frame_ = 0;
  };
}
