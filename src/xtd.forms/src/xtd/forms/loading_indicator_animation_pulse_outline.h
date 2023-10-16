#pragma once
#include "loading_indicator_animation.h"
#include <xtd/math>

namespace xtd::forms {
  class loading_indicator_animation_pulse_outline : public loading_indicator_animation {
  public:
    void on_paint(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& clip_rectangle, const xtd::drawing::color& color, bool enabled) override {
      auto elipse_size = xtd::math::min(clip_rectangle.width(), clip_rectangle.height()) - 2;
      auto ellipse_size1 = enabled ? std::vector {xtd::as<xtd::int32>(elipse_size * .0), xtd::as<xtd::int32>(elipse_size * .1), xtd::as<xtd::int32>(elipse_size * .2), xtd::as<xtd::int32>(elipse_size * .3), xtd::as<xtd::int32>(elipse_size * .4), xtd::as<xtd::int32>(elipse_size * .5), xtd::as<xtd::int32>(elipse_size * .6), xtd::as<xtd::int32>(elipse_size * .7), xtd::as<xtd::int32>(elipse_size * .8), xtd::as<xtd::int32>(elipse_size * .9), elipse_size} : std::vector {elipse_size, elipse_size, elipse_size, elipse_size, elipse_size, elipse_size, elipse_size, elipse_size, elipse_size, elipse_size, elipse_size};
      auto ellipse_size2 = enabled ? std::vector {xtd::as<xtd::int32>(elipse_size * .4), xtd::as<xtd::int32>(elipse_size * .5), xtd::as<xtd::int32>(elipse_size * .6), xtd::as<xtd::int32>(elipse_size * .7), xtd::as<xtd::int32>(elipse_size * .8), xtd::as<xtd::int32>(elipse_size * .9), elipse_size, xtd::as<xtd::int32>(elipse_size * .0), xtd::as<xtd::int32>(elipse_size * .1), xtd::as<xtd::int32>(elipse_size * .2), xtd::as<xtd::int32>(elipse_size * .3)} : std::vector {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      auto opacity = enabled ? 255 : 64;

      graphics.draw_ellipse(xtd::drawing::pen {xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), color), 1}, clip_rectangle.left() + clip_rectangle.width() / 2 - ellipse_size1[frame_] / 2, clip_rectangle.left() + clip_rectangle.width() / 2 - ellipse_size1[frame_] / 2, ellipse_size1[frame_], ellipse_size1[frame_]);
      graphics.draw_ellipse(xtd::drawing::pen {xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), color), 1}, clip_rectangle.left() + clip_rectangle.width() / 2 - ellipse_size2[frame_] / 2, clip_rectangle.left() + clip_rectangle.width() / 2 - ellipse_size2[frame_] / 2, ellipse_size2[frame_], ellipse_size2[frame_]);
    }
    
    void on_timer() override {
      if (++frame_ == intervals_) frame_ = 0;
    }
    
  private:
    xtd::int32 intervals_ = 11;
    xtd::int32 frame_ = 0;
  };
}
