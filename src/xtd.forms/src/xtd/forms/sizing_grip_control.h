#pragma once
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/panel.h"
#include "../../../include/xtd/forms/status_bar.h"

class xtd::forms::status_bar::sizing_grip_control : public xtd::forms::panel {
public:
  sizing_grip_control() {
    set_can_focus(false);
    cursor(xtd::forms::cursors::size_nwse());
  }
   
protected:
  void on_paint(paint_event_args& e) override {
    /// @todo Replace following code by drawing style_sheet sizing grip image.
    auto sizing_grip_color = back_color().is_dark() ? xtd::drawing::color::light(back_color()) : xtd::drawing::color::dark(back_color());
    std::vector<xtd::drawing::rectangle> rectangles = {{e.clip_rectangle().right() - 4, e.clip_rectangle().bottom() - 10, 2, 2}, {e.clip_rectangle().right() - 7, e.clip_rectangle().bottom() - 7, 2, 2}, {e.clip_rectangle().right() - 4, e.clip_rectangle().bottom() - 7, 2, 2}, {e.clip_rectangle().right() - 10, e.clip_rectangle().bottom() - 4, 2, 2}, {e.clip_rectangle().right() - 7, e.clip_rectangle().bottom() - 4, 2, 2}, {e.clip_rectangle().right() - 4, e.clip_rectangle().bottom() - 4, 2, 2}};
    e.graphics().fill_rectangles(xtd::drawing::solid_brush(sizing_grip_color), rectangles);
    control::on_paint(e);
  }
  
private:
  friend status_bar;
};
