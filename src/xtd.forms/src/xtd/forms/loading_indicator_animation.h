#pragma once
#include <xtd/drawing/color>
#include <xtd/drawing/graphics>
#include <xtd/drawing/rectangle>
#include <xtd/abstract>

namespace xtd::forms {
  class loading_indicator_animation abstract_ {
  public:
    virtual void on_paint(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& clip_rectangle, const xtd::drawing::color& color, bool enabled) = 0;
    virtual void on_timer() = 0;
  };
}
