#pragma once
#include "loading_indicator_animation.h"

namespace xtd::forms {
  class loading_indicator_animation_system : public loading_indicator_animation {
  public:
    void on_paint(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& clip_rectangle, const xtd::drawing::color& color, bool enabled) override {
    }
    
    void on_timer() override {
    }
  };
}
