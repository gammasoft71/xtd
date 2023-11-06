#pragma once
#include "loading_indicator_animation.h"
#include <xtd/math>

namespace xtd::forms {
  class loading_indicator_animation_five_lines : public loading_indicator_animation {
  public:
    void on_paint(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& clip_rectangle, const xtd::drawing::color& color, bool enabled) override {
      auto line_width = clip_rectangle.width() / radius_factor_;
      auto gap = (clip_rectangle.width() - 4 - (5 * line_width)) / 4;
      auto line_height = clip_rectangle.height() - 4;
      auto x1 = clip_rectangle.left() + 2;
      auto x2 = x1 + line_width + gap;
      auto x3 = x2 + line_width + gap;
      auto x4 = x3 + line_width + gap;
      auto x5 = x4 + line_width + gap;
      auto y = clip_rectangle.top() + 2;
      auto opacity = enabled ? 255 : 64;
      auto wave1 = enabled ? std::vector {4, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} : std::vector {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      auto wave2 = enabled ? std::vector {0, 0, 0, 4, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0} : std::vector {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      auto wave3 = enabled ? std::vector {0, 0, 0, 0, 0, 0, 4, 2, 4, 0, 0, 0, 0, 0, 0} : std::vector {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      auto wave4 = enabled ? std::vector {0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 4, 0, 0, 0} : std::vector {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      auto wave5 = enabled ? std::vector {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 4} : std::vector {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

      graphics.fill_rounded_rectangle(xtd::drawing::solid_brush {xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), color)}, x1, y + (wave1[frame_] ? line_height / wave1[frame_] / 2 : 0), line_width, (wave1[frame_] ? line_height - line_height / wave1[frame_] : line_height), line_width / 2);
      graphics.fill_rounded_rectangle(xtd::drawing::solid_brush {xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), color)}, x2, y + (wave2[frame_] ? line_height / wave2[frame_] / 2 : 0), line_width, (wave2[frame_] ? line_height - line_height / wave2[frame_] : line_height), line_width / 2);
      graphics.fill_rounded_rectangle(xtd::drawing::solid_brush {xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), color)}, x3, y + (wave3[frame_] ? line_height / wave3[frame_] / 2 : 0), line_width, (wave3[frame_] ? line_height - line_height / wave3[frame_] : line_height), line_width / 2);
      graphics.fill_rounded_rectangle(xtd::drawing::solid_brush {xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), color)}, x4, y + (wave4[frame_] ? line_height / wave4[frame_] / 2 : 0), line_width, (wave4[frame_] ? line_height - line_height / wave4[frame_] : line_height), line_width / 2);
      graphics.fill_rounded_rectangle(xtd::drawing::solid_brush {xtd::drawing::color::from_argb(static_cast<xtd::byte>(opacity), color)}, x5, y + (wave5[frame_] ? line_height / wave5[frame_] / 2 : 0), line_width, (wave5[frame_] ? line_height - line_height / wave5[frame_] : line_height), line_width / 2);
    }
    
    void on_timer() override {
      if (++frame_ == intervals_) frame_ = 0;
    }
    
  private:
    xtd::int32 intervals_ = 15;
    xtd::int32 radius_factor_ = 10;
    xtd::int32 frame_ = 0;
  };
}
